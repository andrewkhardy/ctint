// Copyright (c) 2017--present, The Simons Foundation
// This file is part of TRIQS/ctint and is licensed under the terms of GPLv3 or later.
// SPDX-License-Identifier: GPL-3.0-or-later
// See LICENSE in the root of this distribution for details.

#include "./submatrix.hpp"

#include <array>
#include <vector>

namespace triqs_ctint::moves {

  namespace {

    // The two (c, c^dagger) pairs of a vertex, as lazy_det_operation puts them in the blocks: pair 0 in block b1 (= b2),
    // pair 1 in block b3 (= b4)
    struct vertex_pairs {
      int block[2];
      c_t c[2];
      cdag_t cdag[2];
    };

    vertex_pairs pairs_of(vertex_t const &v) {
      auto const &x = v.idx;
      if (x.b1 != x.b2 or x.b3 != x.b4 or x.b1 == x.b3)
        TRIQS_RUNTIME_ERROR << "use_submatrix needs density-density vertices with their two pairs in two different blocks (as U n_up n_dn)";
      return {{x.b1, x.b3},
              {c_t{v.tau2, x.u2, v.vertex_label, 0, v.s}, c_t{v.tau4, x.u4, v.vertex_label, 1, v.s}},
              {cdag_t{v.tau1, x.u1, v.vertex_label, 0, v.s}, cdag_t{v.tau3, x.u3, v.vertex_label, 1, v.s}}};
    }

  } // namespace

  mc_weight_t submatrix::attempt() {
    auto &dets      = qmc_config->dets;
    auto &vertices  = qmc_config->vertex_lst;
    int n_fact      = vertex_factories.size();
    long n_blocks   = dets.size();
    using pair_t    = det_t::pair_t;

    // The kind of every step (insertion or removal, 1/2 each), and a candidate vertex for every insertion
    std::vector<char> is_insert(n_steps);
    std::vector<vertex_t> cand;
    for (auto &b : is_insert) {
      b = rng() < 0.5;
      if (b) cand.push_back(vertex_factories[rng(n_fact)]());
    }

    // The candidates' pairs, appended to their blocks as off pairs
    std::vector<std::vector<c_t>> xc(n_blocks);
    std::vector<std::vector<cdag_t>> yc(n_blocks);
    std::vector<std::array<pair_t, 2>> cand_pair(cand.size());
    for (long k = 0; k < long(cand.size()); ++k) {
      auto vp = pairs_of(cand[k]);
      for (int a : {0, 1}) {
        int b = vp.block[a];
        cand_pair[k][a] = {long(xc[b].size()), 0}; // candidate index in its block, made a pair after begin_batch
        xc[b].push_back(vp.c[a]);
        yc[b].push_back(vp.cdag[a]);
      }
    }

    // The vertices on: the existing ones (their pairs found when first chosen for removal) and accepted candidates
    struct on_t {
      long k;      // index in vertices (existing) or in cand (candidate)
      bool is_cand;
      bool found;  // pairs known
      std::array<int, 2> block;
      std::array<pair_t, 2> pr;
    };
    std::vector<on_t> on;
    on.reserve(vertices.size() + cand.size());
    for (long k = 0; k < long(vertices.size()); ++k) on.push_back({k, false, false, {0, 0}, {}});

    for (long b = 0; b < n_blocks; ++b) dets[b].begin_batch(std::move(xc[b]), std::move(yc[b]));

    mc_weight_t sign = 1;
    long order       = vertices.size();
    long next        = 0; // next candidate
    std::vector<char> removed(vertices.size(), 0);
    std::vector<char> accepted(cand.size(), 0);

    for (int step = 0; step < n_steps; ++step) {
      std::array<int, 2> block;
      std::array<pair_t, 2> pr;
      double proposal_ratio; // weight factor of the move, as in insert.cpp / remove.cpp
      long a = -1;

      if (is_insert[step]) {
        auto const &v = cand[next];
        if (max_order != -1 and order + 1 >= max_order) {
          ++next;
          continue;
        }
        auto vp = pairs_of(v);
        for (int i : {0, 1}) {
          block[i] = vp.block[i];
          pr[i]    = dets[block[i]].candidate(cand_pair[next][i].i);
        }
        proposal_ratio = 1.0 / double(order + 1) * n_fact / v.proposition_proba;
        auto det_ratio = dets[block[0]].try_toggle({pr[0]}) * dets[block[1]].try_toggle({pr[1]});
        auto R         = mc_weight_t{det_ratio} * proposal_ratio * v.amplitude;
        if (rng() < std::min(1.0, double(std::abs(R)))) {
          for (int i : {0, 1}) dets[block[i]].accept_toggle();
          sign *= R / std::abs(R);
          on.push_back({next, true, true, block, pr});
          accepted[next] = 1;
          ++order;
        } else
          for (int i : {0, 1}) dets[block[i]].reject_toggle();
        ++next;
      } else {
        if (order == 0) continue;
        a         = rng(int(on.size()));
        auto &o   = on[a];
        auto const &v = o.is_cand ? cand[o.k] : vertices[o.k];
        if (not o.found) { // an existing vertex: its pairs in the matrices at the start of the batch
          auto vp = pairs_of(v);
          for (int i : {0, 1}) {
            o.block[i] = vp.block[i];
            o.pr[i]    = dets[o.block[i]].find_pair(vp.c[i], vp.cdag[i]);
          }
          o.found = true;
        }
        block          = o.block;
        pr             = o.pr;
        proposal_ratio = double(order) * v.proposition_proba / n_fact;
        auto det_ratio = dets[block[0]].try_toggle({pr[0]}) * dets[block[1]].try_toggle({pr[1]});
        auto R         = mc_weight_t{det_ratio} * proposal_ratio / v.amplitude;
        if (rng() < std::min(1.0, double(std::abs(R)))) {
          for (int i : {0, 1}) dets[block[i]].accept_toggle();
          sign *= R / std::abs(R);
          if (o.is_cand)
            accepted[o.k] = 0;
          else
            removed[o.k] = 1;
          on[a] = on.back();
          on.pop_back();
          --order;
        } else
          for (int i : {0, 1}) dets[block[i]].reject_toggle();
      }
    }

    for (auto &d : dets) d.end_batch();

    // The vertex list: drop the removed vertices, append the accepted candidates
    std::vector<vertex_t> new_list;
    new_list.reserve(order);
    for (long k = 0; k < long(vertices.size()); ++k)
      if (not removed[k]) new_list.push_back(vertices[k]);
    for (long k = 0; k < long(cand.size()); ++k)
      if (accepted[k]) new_list.push_back(cand[k]);
    vertices = std::move(new_list);

    return sign;
  }

} // namespace triqs_ctint::moves
