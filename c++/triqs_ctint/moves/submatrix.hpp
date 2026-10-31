// Copyright (c) 2017--present, The Simons Foundation
// This file is part of TRIQS/ctint and is licensed under the terms of GPLv3 or later.
// SPDX-License-Identifier: GPL-3.0-or-later
// See LICENSE in the root of this distribution for details.

#pragma once
#include "./../qmc_config.hpp"
#include "./../vertex_factories.hpp"
#include <triqs/mc_tools/random_generator.hpp>

namespace triqs_ctint::moves {

  /**
   * A batch of single-vertex insertions and removals with submatrix updates of the determinants (use_submatrix).
   *
   * One attempt makes n_steps Metropolis steps, each an insertion (probability 1/2) of a vertex drawn from the vertex
   * factories or a removal of a uniformly chosen vertex, with the weights of the insert and remove moves. The
   * determinants are updated once, at the end of the batch (submatrix_det). The attempt returns the change of sign
   * (modulus 1), so mc_generic always accepts it. Vertices must be density-density, with their two (c, c^dagger) pairs
   * in two different blocks (as U n_up n_dn).
   */
  struct submatrix {

    /// The Monte-Carlo configuration
    qmc_config_t *qmc_config;

    /// Factory that randomly generates vertices
    std::vector<vertex_factory_t> const &vertex_factories;

    /// The random number generator
    triqs::mc_tools::random_generator &rng;

    /// Number of insertion / removal steps per batch
    int n_steps = 32;

    /// Maximum perturbation order (<0 : unlimited)
    int max_order = -1;

    /// Run a batch, return the change of sign
    mc_weight_t attempt();

    /// The batch is already applied
    mc_weight_t accept() { return 1.0; }

    /// Never called: the attempt has modulus 1
    void reject() {}
  };

} // namespace triqs_ctint::moves
