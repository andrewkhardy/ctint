// Copyright (c) 2017--present, The Simons Foundation
// This file is part of TRIQS/ctint and is licensed under the terms of GPLv3 or later.
// SPDX-License-Identifier: GPL-3.0-or-later
// See LICENSE in the root of this distribution for details.

#pragma once
#include <triqs/det_manip/det_manip.hpp>

#include <algorithm>
#include <numeric>
#include <vector>

namespace triqs_ctint {

  /**
   * A det_manip that also switches (row, column) pairs of its matrix on and off in batches, with submatrix updates
   * (Gull et al., PRB 83, 075122 (2011), there for the spin flips of CT-AUX).
   *
   * In the internal matrix G (G(m, n) = f(x_m, y_n), mat_inv = G^-1), a pair (row i, column j) is off when row i is the
   * unit row e_j^T. Expanding along that row, det G is (-1)^(i+j) times the determinant without the pair, which is the
   * ratio det_manip's own removal gives (mat_inv(j, i)): switching pairs off and on gives exactly the ratios of
   * try_remove and try_insert as CTINT uses them (CTINT's position parity cancels det_manip's).
   *
   * A batch:
   *  - begin_batch(xc, yc) appends the candidate pairs (xc[p], yc[p]) as off pairs, rows and columns N0 + p, with
   *    G_b = [[A, C], [0, 1]] and G_b^-1 = [[A^-1, W], [0, 1]], W = -A^-1 C, one matrix product;
   *  - try_toggle(pairs) gives det G' / det G for switching those pairs (on <-> off) in the current matrix. With the
   *    accepted changes S so far, the change of row i_e, Delta_e = dir_e (on row - e_(j_e)^T), and
   *    Gamma(e, e') = (Delta_e G_b^-1)_(i_e'), it is the Schur complement det(1 + Gamma_PP - Gamma_PS M_S Gamma_SP),
   *    M_S = (1 + Gamma_SS)^-1, at O(N0 |S|) cost and no pass over A^-1;
   *  - accept_toggle() or reject_toggle();
   *  - end_batch() applies all accepted changes to the inverse with two matrix products,
   *    G_b'^-1 = G_b^-1 - (G_b^-1 E_S) M_S (Delta_S G_b^-1), drops the pairs that are off, and restores the det_manip
   *    state, the user order sorted by x and by y (as CTINT keeps it).
   * Between batches it is a plain det_manip.
   */
  template <typename FunctionType> class submatrix_det : public triqs::det_manip::det_manip<FunctionType> {
    using base = triqs::det_manip::det_manip<FunctionType>;
    using base::det;
    using base::f;
    using base::mat_inv;
    using base::N;
    using base::n_opts;
    using base::n_opts_max_before_check;
    using base::precision_error;
    using base::precision_warning;
    using base::row_num;
    using base::col_num;
    using base::sign;
    using base::x_values;
    using base::y_values;

    public:
    using typename base::matrix_type;
    using typename base::value_type;
    using typename base::x_type;
    using typename base::y_type;
    using base::base;
    using range = nda::range;

    /// A pair of the batch matrix: row i (x_i) and column j (y_j)
    struct pair_t {
      long i, j;
    };

    /// The internal pair of the row of x and the column of y, both in the matrix (between batches or at its start)
    pair_t find_pair(x_type const &x, y_type const &y) const {
      auto pos_x = lower(N, [this](long k) { return this->get_x(k); }, x);
      auto pos_y = lower(N, [this](long k) { return this->get_y(k); }, y);
      TRIQS_ASSERT(pos_x < N and pos_y < N);
      return {row_num[pos_x], col_num[pos_y]};
    }

    /// Start a batch with the candidate pairs (xc[p], yc[p]), off, as rows and columns N0 + p
    void begin_batch(std::vector<x_type> xc_, std::vector<y_type> yc_) {
      TRIQS_ASSERT(xc_.size() == yc_.size());
      xc = std::move(xc_);
      yc = std::move(yc_);
      N0 = N;
      K  = long(xc.size());
      this->reserve(N0 + K + 1);
      W.resize(N0, K);
      R.resize(K, N0 + K);
      r_done.assign(K, false);
      is_on.assign(N0 + K, false);
      for (long i = 0; i < N0; ++i) is_on[i] = true;
      S.clear();
      MS.resize(0, 0);
      ratio_product = 1;
      if (N0 > 0 and K > 0) {
        matrix_type C(N0, K);
        for (long m = 0; m < N0; ++m)
          for (long p = 0; p < K; ++p) C(m, p) = f(x_values[m], yc[p]);
        nda::blas::gemm(-1.0, mat_inv(range(N0), range(N0)), C, 0.0, W);
      }
    }

    /// Number of candidate pairs of the batch, and the pair of candidate p
    long n_candidates() const { return K; }
    pair_t candidate(long p) const { return {N0 + p, N0 + p}; }

    /// Is the pair of row i on in the current batch matrix?
    bool row_is_on(long i) const { return is_on[i]; }

    /// det G' / det G for switching the given pairs (on <-> off); complete with accept_toggle or reject_toggle
    value_type try_toggle(std::vector<pair_t> const &pairs) {
      long m = long(pairs.size()), s = long(S.size());
      trial.clear();
      for (auto const &pr : pairs) {
        entry_t e{pr.i, pr.j, is_on[pr.i] ? -1 : +1};
        if (e.i >= N0) fill_row(e.i - N0);
        trial.push_back(e);
      }
      // d = 1 + Gamma_PP, u = Gamma_PS, v = Gamma_SP
      matrix_type d(m, m), u(m, s), v(s, m);
      for (long a = 0; a < m; ++a) {
        for (long b = 0; b < m; ++b) d(a, b) = (a == b ? 1 : 0) + gamma(trial[a], trial[b].i);
        for (long c = 0; c < s; ++c) {
          u(a, c) = gamma(trial[a], S[c].i);
          v(c, a) = gamma(S[c], trial[a].i);
        }
      }
      if (s > 0) {
        MSv = MS * v; // s x m
        Sc  = d - u * MSv;
      } else {
        MSv.resize(0, m);
        Sc = d;
      }
      u_trial = u;
      return small_det(Sc);
    }

    /// Accept the last try_toggle
    void accept_toggle() {
      long m = long(trial.size()), s = long(S.size());
      matrix_type Sc_inv = nda::linalg::inv(Sc);
      // Bordered inverse: [[MS + MS v Sc^-1 u MS, -MS v Sc^-1], [-Sc^-1 u MS, Sc^-1]]
      matrix_type MS_new(s + m, s + m);
      if (s > 0) {
        matrix_type uMS   = u_trial * MS;   // m x s
        matrix_type top   = MSv * Sc_inv;   // s x m
        MS_new(range(s), range(s))         = MS + top * uMS;
        MS_new(range(s), range(s, s + m))  = -top;
        MS_new(range(s, s + m), range(s))  = -(Sc_inv * uMS);
      }
      MS_new(range(s, s + m), range(s, s + m)) = Sc_inv;
      MS = std::move(MS_new);
      for (auto const &e : trial) {
        S.push_back(e);
        is_on[e.i] = !is_on[e.i];
      }
      ratio_product *= small_det(Sc);
      trial.clear();
    }

    /// Reject the last try_toggle
    void reject_toggle() { trial.clear(); }

    /// Apply the accepted changes, drop the pairs that are off and restore the det_manip state
    void end_batch() {
      long NB = N0 + K, s = long(S.size());
      if (s == 0) { // nothing changed: A^-1 is untouched in mat_inv(0:N0, 0:N0), the candidates were never written
        K = 0;
        return;
      }
      // The batch inverse G_b^-1 = [[A^-1, W], [0, 1]] in mat_inv(0:NB, 0:NB)
      if (K > 0) {
        if (N0 > 0) { // (nda's fill of a strided view with an empty dimension runs off the end: never make one)
          mat_inv(range(N0), range(N0, NB)) = W;
          mat_inv(range(N0, NB), range(N0)) = 0;
        }
        mat_inv(range(N0, NB), range(N0, NB)) = 0;
        for (long p = 0; p < K; ++p) mat_inv(N0 + p, N0 + p) = 1;
      }
      // U = G_b^-1 E_S (columns i_e), V = Delta_S G_b^-1 (rows)
      matrix_type U(NB, s), V(s, NB);
      for (long c = 0; c < s; ++c) U(range(NB), c) = mat_inv(range(NB), S[c].i);
      V() = 0;
      std::vector<long> cand;
      for (long c = 0; c < s; ++c) {
        auto const &e = S[c];
        if (e.i >= N0) cand.push_back(c);
        else
          V(c, e.i) += e.dir; // on row of an existing pair: (G_b G_b^-1)_(i, .) = e_i
        V(c, range(NB)) -= e.dir * mat_inv(e.j, range(NB));
      }
      if (not cand.empty()) { // r G_b^-1 for the candidate rows, one matrix product
        long nc = long(cand.size());
        matrix_type Rc(nc, N0), RG(nc, NB);
        RG() = 0;
        if (N0 > 0) {
          for (long a = 0; a < nc; ++a) Rc(a, range(N0)) = R(S[cand[a]].i - N0, range(N0));
          nda::blas::gemm(1.0, Rc, mat_inv(range(N0), range(NB)), 0.0, RG);
        }
        for (long a = 0; a < nc; ++a) {
          auto const &e = S[cand[a]];
          RG(a, range(N0, NB)) += R(e.i - N0, range(N0, NB));
          V(cand[a], range(NB)) += e.dir * RG(a, range(NB));
        }
      }
      matrix_type UMS = U * MS;
      nda::blas::gemm(-1.0, UMS, V, 1.0, mat_inv(range(NB), range(NB)));

      // The pairs off at the end, each a row with the column of its unit row: drop them, keep the rest in order
      std::vector<long> col_of_row(NB, -1);
      for (long p = 0; p < K; ++p) col_of_row[N0 + p] = N0 + p;
      for (auto const &e : S) col_of_row[e.i] = e.j;
      std::vector<bool> col_off(NB, false);
      for (long i = 0; i < NB; ++i)
        if (not is_on[i]) {
          TRIQS_ASSERT(col_of_row[i] >= 0);
          col_off[col_of_row[i]] = true;
        }
      std::vector<long> rows_on, cols_on;
      for (long i = 0; i < NB; ++i)
        if (is_on[i]) rows_on.push_back(i);
      for (long n = 0; n < NB; ++n)
        if (not col_off[n]) cols_on.push_back(n);
      TRIQS_ASSERT(rows_on.size() == cols_on.size());
      long Nn = long(rows_on.size());

      // det of the compacted matrix: det G_final = eps det G_compact, eps the parities of putting the off rows and
      // their columns last in matching order
      std::vector<long> rperm(rows_on), cperm(cols_on);
      for (long i = 0; i < NB; ++i)
        if (not is_on[i]) {
          rperm.push_back(i);
          cperm.push_back(col_of_row[i]);
        }
      det = det * ratio_product * double(parity(rperm) * parity(cperm));

      // Compact mat_inv(n, m): keep columns-of-G n in cols_on and rows-of-G m in rows_on, in place (new <= old index)
      for (long a = 0; a < Nn; ++a)
        for (long b = 0; b < Nn; ++b) mat_inv(a, b) = mat_inv(cols_on[a], rows_on[b]);
      std::vector<x_type> xn;
      std::vector<y_type> yn;
      for (long i : rows_on) xn.push_back(i < N0 ? x_values[i] : xc[i - N0]);
      for (long n : cols_on) yn.push_back(n < N0 ? y_values[n] : yc[n - N0]);
      x_values = std::move(xn);
      y_values = std::move(yn);
      N        = Nn;

      // User order sorted by x and by y, and its sign
      row_num.resize(N);
      col_num.resize(N);
      std::iota(row_num.begin(), row_num.end(), 0);
      std::iota(col_num.begin(), col_num.end(), 0);
      std::stable_sort(row_num.begin(), row_num.end(), [this](long a, long b) { return x_values[a] < x_values[b]; });
      std::stable_sort(col_num.begin(), col_num.end(), [this](long a, long b) { return y_values[a] < y_values[b]; });
      sign = parity(row_num) * parity(col_num);

      n_opts += s;
      if (n_opts > n_opts_max_before_check) check();
      S.clear();
      K = 0;
    }

    private:
    struct entry_t {
      long i, j; // row, and the column whose unit row it is when off
      int dir;   // +1: switched on, -1: switched off
    };

    long N0 = 0, K = 0;
    std::vector<x_type> xc;
    std::vector<y_type> yc;
    matrix_type W, R;          // W = -A^-1 C (N0 x K); R(p, .) the on row of candidate p (f(xc[p], y), N0 + K)
    std::vector<bool> r_done, is_on;
    std::vector<entry_t> S, trial;
    matrix_type MS, MSv, Sc, u_trial;
    value_type ratio_product = 1;

    template <typename Get, typename T> static long lower(long count, Get const &get, T const &value) {
      long first = 0;
      while (count > 0) {
        long step = count / 2, p = first + step;
        if (get(p) < value) {
          first = p + 1;
          count -= step + 1;
        } else
          count = step;
      }
      return first;
    }

    static int parity(std::vector<long> const &perm) { // parity of a permutation of its sorted values
      std::vector<long> sorted(perm);
      std::sort(sorted.begin(), sorted.end());
      std::vector<long> pos(perm.size());
      for (long k = 0; k < long(perm.size()); ++k) pos[k] = std::lower_bound(sorted.begin(), sorted.end(), perm[k]) - sorted.begin();
      std::vector<bool> seen(perm.size(), false);
      int par = 1;
      for (long k = 0; k < long(perm.size()); ++k) {
        if (seen[k]) continue;
        long len = 0;
        for (long l = k; not seen[l]; l = pos[l]) {
          seen[l] = true;
          ++len;
        }
        if (len % 2 == 0) par = -par;
      }
      return par;
    }

    static value_type small_det(matrix_type const &M) {
      if (M.extent(0) == 1) return M(0, 0);
      if (M.extent(0) == 2) return M(0, 0) * M(1, 1) - M(0, 1) * M(1, 0);
      return nda::linalg::det(M);
    }

    // (G_b^-1)(n, q): n a column of G_b, q a row
    value_type gbinv(long n, long q) const {
      if (n >= N0) return n == q ? 1 : 0;
      return q < N0 ? mat_inv(n, q) : W(n, q - N0);
    }

    // The on row of candidate p, f(xc[p], y) over all N0 + K columns
    void fill_row(long p) {
      if (r_done[p]) return;
      for (long n = 0; n < N0; ++n) R(p, n) = f(xc[p], y_values[n]);
      for (long q = 0; q < K; ++q) R(p, N0 + q) = f(xc[p], yc[q]);
      r_done[p] = true;
    }

    // Gamma(e, q) = (Delta_e G_b^-1)_q = dir (r_e G_b^-1 - e_(j_e)^T G_b^-1)_q, r_e the on row of e
    value_type gamma(entry_t const &e, long q) const {
      value_type rg = 0;
      if (e.i < N0)
        rg = (e.i == q) ? 1 : 0; // the on row of an existing pair is its row of G_b
      else {
        long p = e.i - N0;
        for (long n = 0; n < N0; ++n) rg += R(p, n) * gbinv(n, q);
        if (q >= N0) rg += R(p, q);
      }
      return value_type(e.dir) * (rg - gbinv(e.j, q));
    }

    // det_manip's consistency check of the inverse (its own is private): rebuild G^-1 and compare, then keep the fresh one
    void check() {
      n_opts = 0;
      if (N == 0) return;
      matrix_type res(N, N);
      for (long i = 0; i < N; ++i)
        for (long j = 0; j < N; ++j) res(i, j) = f(x_values[i], y_values[j]);
      res        = nda::linalg::inv(res);
      double r   = nda::max_element(nda::abs(res - mat_inv(range(N), range(N))));
      double r2  = nda::max_element(nda::abs(res + mat_inv(range(N), range(N))));
      if (not(r < precision_error * r2)) TRIQS_RUNTIME_ERROR << "submatrix_det: deviation above critical threshold, N = " << N << ", " << r;
      if (not(r < precision_warning * r2))
        std::cerr << "Warning : submatrix_det deviation above warning threshold, N = " << N << ", max |M^-1 - M^-1_true| = " << r << "\n";
      mat_inv(range(N), range(N)) = res;
    }
  };

} // namespace triqs_ctint
