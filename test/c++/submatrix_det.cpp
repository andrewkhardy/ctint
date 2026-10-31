// Copyright (c) 2017--present, The Simons Foundation
// This file is part of TRIQS/ctint and is licensed under the terms of GPLv3 or later.
// SPDX-License-Identifier: GPL-3.0-or-later
// See LICENSE in the root of this distribution for details.

// submatrix_det against a plain det_manip doing the same insertions and removals one at a time, as CTINT does them
// (at the sorted positions, times the parity of the positions): every ratio of a batch, and after the batch the
// user-ordered inverse, x, y and determinant.

#include <triqs/test_tools/arrays.hpp>
#include <triqs_ctint/submatrix_det.hpp>

#include <cmath>
#include <random>
#include <vector>

double g_beta = 10.0; // the period of fun, set by each test

struct fun {
  // a G0-like kernel of x - y on [0, beta), antiperiodic, plus a narrow peak at x = y that plays the alpha shift's
  // part in CTINT: the pairs (x, y = x + small) dominate their rows, so the matrices are well conditioned
  double operator()(double x, double y) const {
    const double beta = g_beta, eps = 0.3;
    double tau = x - y;
    double s   = 1;
    if (tau < 0) {
      tau += beta;
      s = -1;
    }
    double d = (x - y) / 0.02;
    return 0.3 * (-s * std::exp(-eps * tau) / (1 + std::exp(-eps * beta)) + 0.2 * std::cos(0.7 * tau)) + std::exp(-d * d);
  }
};

using ref_t = triqs::det_manip::det_manip<fun>;
using sub_t = triqs_ctint::submatrix_det<fun>;

template <typename D, typename T, typename Get> long position(D const &d, T const &v, Get get) {
  long p = 0;
  while (p < d.size() and get(d, p) < v) ++p;
  return p;
}
auto gx = [](auto const &d, long k) { return d.get_x(k); };
auto gy = [](auto const &d, long k) { return d.get_y(k); };

// Insert (x, y) in both at the sorted positions
void insert_both(ref_t &ref, sub_t &sub, double x, double y) {
  long px = position(ref, x, gx), py = position(ref, y, gy);
  ref.try_insert(px, py, x, y);
  ref.complete_operation();
  sub.try_insert(px, py, x, y);
  sub.complete_operation();
}

void remove_both(ref_t &ref, sub_t &sub, double x, double y) {
  long px = position(ref, x, gx), py = position(ref, y, gy);
  ref.try_remove(px, py);
  ref.complete_operation();
  sub.try_remove(px, py);
  sub.complete_operation();
}

void expect_same(ref_t &ref, sub_t &sub) {
  ASSERT_EQ(ref.size(), sub.size());
  double scale = 0;
  for (long i = 0; i < ref.size(); ++i)
    for (long j = 0; j < ref.size(); ++j) scale = std::max(scale, std::abs(ref.inverse_matrix(i, j)));
  for (long i = 0; i < ref.size(); ++i) {
    EXPECT_EQ(ref.get_x(i), sub.get_x(i));
    EXPECT_EQ(ref.get_y(i), sub.get_y(i));
    for (long j = 0; j < ref.size(); ++j) EXPECT_NEAR(ref.inverse_matrix(i, j), sub.inverse_matrix(i, j), 1e-10 * scale);
  }
  double dr = ref.determinant(), ds = sub.determinant();
  EXPECT_NEAR(ds / dr, 1.0, 1e-8);
}

// n0 random pairs inserted (then a third of them removed), then n_batches batches of up to max_steps steps
void run(int seed, int n0, int n_batches, int max_steps, double beta, long init_size) {
  g_beta = beta;
  {
    std::mt19937 rng(seed);
    std::uniform_real_distribution<double> U(0, 1);
    ref_t ref(fun{}, init_size);
    sub_t sub(fun{}, init_size);

    // The pairs (x, y) currently in the matrices
    std::vector<std::pair<double, double>> pairs;
    for (int k = 0; k < n0; ++k) {
      double x = beta * U(rng), y = x + 0.01 * (U(rng) - 0.5);
      insert_both(ref, sub, x, y);
      pairs.emplace_back(x, y);
    }
    // A few removals, so that rows and columns of a pair sit at different internal positions
    for (int k = 0; k < n0 / 3; ++k) {
      long a = long(U(rng) * pairs.size());
      remove_both(ref, sub, pairs[a].first, pairs[a].second);
      pairs.erase(pairs.begin() + a);
    }
    expect_same(ref, sub);

    for (int batch = 0; batch < n_batches; ++batch) {
      int n_steps = 1 + int(U(rng) * max_steps);
      std::vector<int> is_insert(n_steps);
      int n_ins = 0;
      for (auto &b : is_insert) n_ins += (b = (U(rng) < 0.5));
      std::vector<double> xc, yc;
      for (int p = 0; p < n_ins; ++p) {
        double x = beta * U(rng);
        xc.push_back(x);
        yc.push_back(x + 0.01 * (U(rng) - 0.5));
      }

      // The pairs on, with their submatrix_det pair
      struct on_t {
        double x, y;
        sub_t::pair_t pr;
      };
      std::vector<on_t> on;
      for (auto [x, y] : pairs) on.push_back({x, y, sub.find_pair(x, y)});
      sub.begin_batch(xc, yc);

      int next = 0;
      for (int step = 0; step < n_steps; ++step) {
        double r_sub, r_ref;
        bool ins = is_insert[step];
        long a   = -1;
        if (ins) {
          double x = xc[next], y = yc[next];
          long px = position(ref, x, gx), py = position(ref, y, gy);
          r_ref = ref.try_insert(px, py, x, y) * ((px + py) % 2 ? -1 : 1);
          r_sub = sub.try_toggle({sub.candidate(next)});
        } else {
          if (on.empty()) continue;
          a        = long(U(rng) * on.size());
          long px  = position(ref, on[a].x, gx), py = position(ref, on[a].y, gy);
          r_ref    = ref.try_remove(px, py) * ((px + py) % 2 ? -1 : 1);
          r_sub    = sub.try_toggle({on[a].pr});
        }
        EXPECT_NEAR(r_sub, r_ref, 1e-9 * (std::abs(r_ref) + 1e-3)) << "seed " << seed << " batch " << batch << " step " << step << (ins ? " insert" : " remove");
        if (U(rng) < 0.6) {
          ref.complete_operation();
          sub.accept_toggle();
          if (ins)
            on.push_back({xc[next], yc[next], sub.candidate(next)});
          else
            on.erase(on.begin() + a);
        } else {
          ref.reject_last_try();
          sub.reject_toggle();
        }
        if (ins) ++next;
      }
      sub.end_batch();
      pairs.clear();
      for (auto const &o : on) pairs.emplace_back(o.x, o.y);
      expect_same(ref, sub);

      // A plain det_manip operation after the batch
      double x = beta * U(rng), y = x + 0.01;
      insert_both(ref, sub, x, y);
      pairs.emplace_back(x, y);
      expect_same(ref, sub);
    }
  }
}

TEST(SubmatrixDet, AgainstDetManip) {
  for (int seed : {1, 2, 3, 4, 5}) run(seed, 5 + 10 * seed, 4, 24, 10.0, 10);
}

// From an empty matrix, as every solve starts
TEST(SubmatrixDet, FromEmpty) {
  for (int seed : {11, 12, 13}) run(seed, 0, 8, 24, 10.0, 1000);
}

// At the orders of the production runs, with the capacity CTINT gives the dets (det_init_size 1000)
TEST(SubmatrixDet, LargeOrder) { run(7, 900, 6, 64, 200.0, 1000); }

MAKE_MAIN;
