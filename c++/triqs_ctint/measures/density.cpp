// Copyright (c) 2018--present, The Simons Foundation
// This file is part of TRIQS/ctint and is licensed under the terms of GPLv3 or later.
// SPDX-License-Identifier: GPL-3.0-or-later
// See LICENSE in the root of this distribution for details.

#include "./density.hpp"

using namespace triqs::utility;

namespace triqs_ctint::measures {

  density::density(params_t const &params_, qmc_config_t &qmc_config_, container_set *results) : params(params_), qmc_config(qmc_config_) {

    results->density = block_matrix_t{};

    // Init measurement container and capture view
    for (auto &[bl, bl_size] : params.gf_struct) {
      results->density->push_back(zeros<M_tau_scalar_t>(make_shape(bl_size, bl_size)));
      density_.push_back(results->density->back());
    }
  }

  void density::accumulate(mc_weight_t sign) {
    // Accumulate sign
    Z += sign;

    // Calculate density matrix
    for (int bl : range(params.n_blocks())) {

      auto &det     = qmc_config.dets[bl];
      auto &density = density_[bl];
      int bl_size   = density.shape()[0];
      long N        = det.size();

      // density(a, b) is the ratio det.try_insert(0, 0, c_b, cdag_a) would give,
      //   D(b, a) = f(c_b, cdag_a) - sum_{n,l} f(c_b, y_n) M^-1(n, l) f(x_l, cdag_a),
      // for all (a, b) at once, as two matrix products instead of bl_size^2 matrix-vector products
      using value_t = det_t::value_type;
      auto const &f = det.get_function();
      auto const &x = det.get_x_internal_order();
      auto const &y = det.get_y_internal_order();

      std::vector<c_t> c;
      std::vector<cdag_t> cdag;
      for (int a : range(bl_size)) {
        c.push_back(c_t{tau_t::get_zero(), a});
        cdag.push_back(cdag_t{tau_t::get_zero_plus(), a});
      }

      matrix<value_t> D(bl_size, bl_size);
      for (int b : range(bl_size))
        for (int a : range(bl_size)) D(b, a) = f(c[b], cdag[a]);

      if (N > 0) {
        matrix<value_t> X(bl_size, N), Y(N, bl_size), MY(N, bl_size);
        for (int b : range(bl_size))
          for (long n : range(N)) X(b, n) = f(c[b], y[n]);
        for (long l : range(N))
          for (int a : range(bl_size)) Y(l, a) = f(x[l], cdag[a]);
        nda::blas::gemm(1.0, det.inverse_matrix_internal_order(), Y, 0.0, MY);
        nda::blas::gemm(-1.0, X, MY, 1.0, D);
      }

      for (int a : range(bl_size))
        for (int b : range(bl_size)) density(a, b) += sign * D(b, a);
    }
  }

  void density::collect_results(mpi::communicator const &comm) {
    // Collect results and normalize
    Z = mpi::all_reduce(Z, comm);
    for (auto &dens_mat : density_) {
      dens_mat = mpi::all_reduce(dens_mat, comm);
      dens_mat = dens_mat / Z;
    }
  }

} // namespace triqs_ctint::measures
