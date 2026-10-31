
// C.f. https://numpy.org/doc/1.21/reference/c-api/array.html#importing-the-api
#define PY_ARRAY_UNIQUE_SYMBOL _cpp2py_ARRAY_API
#ifndef CLAIR_C2PY_WRAP_GEN
#ifdef __clang__
// #pragma clang diagnostic ignored "-W#warnings"
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wcast-function-type"
#pragma GCC diagnostic ignored "-Wcpp"
#endif

#define C2PY_VERSION_MAJOR 1
#define C2PY_VERSION_MINOR 0

#include <c2py/c2py.hpp>
#include <c2py/version_check.hpp>

using c2py::operator""_a;

// ==================== enums =====================

// ==================== module classes =====================

// ==================== module functions ====================

// F_from_G2c
static auto const _c2py_fun_35241b53 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::F_from_G2c(G2_conn_iw, G_iw); },
                                      "G2_conn_iw", "G_iw")};

// Fph_from_G2ph_conn
static auto const _c2py_fun_c7470a29 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2ph_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::Fph_from_G2ph_conn(G2ph_conn_iw, G_iw); },
                                      "G2ph_conn_iw", "G_iw")};

// Fpp_from_G2pp_conn
static auto const _c2py_fun_2e56d769 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2pp_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::Fpp_from_G2pp_conn(G2pp_conn_iw, G_iw); },
                                      "G2pp_conn_iw", "G_iw")};

// G2_conn_from_M4
static auto const _c2py_fun_2dbe60b0 = c2py::dispatcher_f_kw_t{
   c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>, triqs::gfs::tensor_valued<4>,
                                      nda::C_layout, 2>::const_view_type M4_iw,
                 triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw) { return triqs_ctint::G2_conn_from_M4(M4_iw, M_iw, G0_iw); },
              "M4_iw", "M_iw", "G0_iw")};

// G2_from_G2c
static auto const _c2py_fun_f0db3514 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::G2_from_G2c(G2_conn_iw, G_iw); },
                                      "G2_conn_iw", "G_iw")};

// G2ph_conn_from_M4ph
static auto const _c2py_fun_f6dd79b0 = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>, triqs::gfs::tensor_valued<4>,
                           nda::C_layout, 2>::const_view_type M4ph_iw,
      triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw) { return triqs_ctint::G2ph_conn_from_M4ph(M4ph_iw, M_iw, G0_iw); },
   "M4ph_iw", "M_iw", "G0_iw")};

// G2ph_from_G2ph_conn
static auto const _c2py_fun_c9244676 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2ph_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::G2ph_from_G2ph_conn(G2ph_conn_iw, G_iw); },
                                      "G2ph_conn_iw", "G_iw")};

// G2pp_conn_from_M4pp
static auto const _c2py_fun_1451c110 = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>, triqs::gfs::tensor_valued<4>,
                           nda::C_layout, 2>::const_view_type M4pp_iw,
      triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw) { return triqs_ctint::G2pp_conn_from_M4pp(M4pp_iw, M_iw, G0_iw); },
   "M4pp_iw", "M_iw", "G0_iw")};

// G2pp_from_G2pp_conn
static auto const _c2py_fun_ac4d3526 =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2pp_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::G2pp_from_G2pp_conn(G2pp_conn_iw, G_iw); },
                                      "G2pp_conn_iw", "G_iw")};

// chi2_conn_from_M3_PH
static auto const _c2py_fun_b1774cef = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi3_tau_t M3ph_tau, triqs_ctint::chi2_tau_t M3ph_delta, triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw,
      triqs_ctint::g_tau_cv_t M_tau, const triqs_ctint::block_matrix_t &M_hartree,
      triqs_ctint::g_tau_cv_t G0_tau) { return triqs_ctint::chi2_conn_from_M3_PH(M3ph_tau, M3ph_delta, M_iw, G0_iw, M_tau, M_hartree, G0_tau); },
   "M3ph_tau", "M3ph_delta", "M_iw", "G0_iw", "M_tau", "M_hartree", "G0_tau")};

// chi2_conn_from_M3_PP
static auto const _c2py_fun_a9774057 = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi3_tau_t M3pp_tau, triqs_ctint::chi2_tau_t M3pp_delta, triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw,
      triqs_ctint::g_tau_cv_t M_tau, const triqs_ctint::block_matrix_t &M_hartree,
      triqs_ctint::g_tau_cv_t G0_tau) { return triqs_ctint::chi2_conn_from_M3_PP(M3pp_tau, M3pp_delta, M_iw, G0_iw, M_tau, M_hartree, G0_tau); },
   "M3pp_tau", "M3pp_delta", "M_iw", "G0_iw", "M_tau", "M_hartree", "G0_tau")};

// chi2_from_chi2_conn_PH
static auto const _c2py_fun_42522553 = c2py::dispatcher_f_kw_t{
   c2py::cfun([](triqs_ctint::chi2_tau_cv_t chi2_conn_tau, triqs_ctint::g_reg_iw_cv_t G_iw,
                 const triqs_ctint::block_matrix_t &dens_G) { return triqs_ctint::chi2_from_chi2_conn_PH(chi2_conn_tau, G_iw, dens_G); },
              "chi2_conn_tau", "G_iw", "dens_G")};

// chi2_from_chi2_conn_PP
static auto const _c2py_fun_5a524b1b = c2py::dispatcher_f_kw_t{
   c2py::cfun([](triqs_ctint::chi2_tau_cv_t chi2_conn_tau, triqs_ctint::g_reg_iw_cv_t G_iw,
                 const triqs_ctint::block_matrix_t &dens_G) { return triqs_ctint::chi2_from_chi2_conn_PP(chi2_conn_tau, G_iw, dens_G); },
              "chi2_conn_tau", "G_iw", "dens_G")};

// chi3_from_M3_PH
static auto const _c2py_fun_bb34d11d = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi3_iw_cv_t M3_iw, triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw, const triqs_ctint::block_matrix_t &dens_G,
      const triqs_ctint::block_matrix_t &M_hartree) { return triqs_ctint::chi3_from_M3_PH(M3_iw, M_iw, G0_iw, dens_G, M_hartree); },
   "M3_iw", "M_iw", "G0_iw", "dens_G", "M_hartree")};

// chi3_from_M3_PP
static auto const _c2py_fun_c334ddb5 = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi3_iw_cv_t M3_iw, triqs_ctint::g_reg_iw_cv_t M_iw, triqs_ctint::g_reg_iw_cv_t G0_iw, const triqs_ctint::block_matrix_t &dens_G,
      const triqs_ctint::block_matrix_t &M_hartree) { return triqs_ctint::chi3_from_M3_PP(M3_iw, M_iw, G0_iw, dens_G, M_hartree); },
   "M3_iw", "M_iw", "G0_iw", "dens_G", "M_hartree")};

// chiAB_from_chi2_PH
static auto const _c2py_fun_1c896075 = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi2_tau_cv_t chi2ph_tau, const triqs::gfs::gf_struct_t &gf_struct,
      const std::vector<triqs::operators::many_body_operator> &A_op_vec, const std::vector<triqs::operators::many_body_operator> &B_op_vec) {
     return triqs_ctint::chiAB_from_chi2_PH(chi2ph_tau, gf_struct, A_op_vec, B_op_vec);
   },
   "chi2ph_tau", "gf_struct", "A_op_vec", "B_op_vec")};

// chiAB_from_chi2_PP
static auto const _c2py_fun_148953dd = c2py::dispatcher_f_kw_t{c2py::cfun(
   [](triqs_ctint::chi2_tau_cv_t chi2pp_tau, const triqs::gfs::gf_struct_t &gf_struct,
      const std::vector<triqs::operators::many_body_operator> &A_op_vec, const std::vector<triqs::operators::many_body_operator> &B_op_vec) {
     return triqs_ctint::chiAB_from_chi2_PP(chi2pp_tau, gf_struct, A_op_vec, B_op_vec);
   },
   "chi2pp_tau", "gf_struct", "A_op_vec", "B_op_vec")};

// chi_tilde_ph_from_G2ph_conn
static auto const _c2py_fun_0449eafd =
   c2py::dispatcher_f_kw_t{c2py::cfun([](triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                              triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type G2ph_conn_iw,
                                         triqs_ctint::g_reg_iw_cv_t G_iw) { return triqs_ctint::chi_tilde_ph_from_G2ph_conn(G2ph_conn_iw, G_iw); },
                                      "G2ph_conn_iw", "G_iw")};

static const auto _c2py_doc_35241b53 = _c2py_fun_35241b53.doc(
   R"DOC(
Calculate the vertex function :math:`F`.

Amputates the external legs of the connected two-particle Green's function with the
interacting Green's function :math:`G` to obtain the full vertex function :math:`F`.

Parameters
----------
G2_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{conn}(i\omega)`.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The vertex function :math:`F(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_c7470a29 = _c2py_fun_c7470a29.doc(
   R"DOC(
Calculate the vertex function :math:`F` in the particle-hole channel.

Amputates the external legs of the connected two-particle Green's function in the
particle-hole channel with the interacting Green's function :math:`G`.

Parameters
----------
G2ph_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{ph,conn}(i\omega)` in the particle-hole channel.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The vertex function :math:`F_{ph}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_2e56d769 = _c2py_fun_2e56d769.doc(
   R"DOC(
Calculate the vertex function :math:`F` in the particle-particle channel.

Amputates the external legs of the connected two-particle Green's function in the
particle-particle channel with the interacting Green's function :math:`G`.

Parameters
----------
G2pp_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{pp,conn}(i\omega)` in the particle-particle channel.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The vertex function :math:`F_{pp}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_2dbe60b0 = _c2py_fun_2dbe60b0.doc(
   R"DOC(
Calculate the connected part of the two-particle Green's function :math:`G^{(2)}`.

Combines the measured building block :math:`M^{(4)}` with the single-particle building
block :math:`M` and the non-interacting Green's function :math:`G_0` to form the connected
two-particle Green's function.

Parameters
----------
M4_iw : {par_0}
   The building block :math:`M^{(4)}(i\omega)` for the full vertex.
M_iw : {par_1}
   The building block :math:`M(i\omega)`.
G0_iw : {par_2}
   The non-interacting Green's function :math:`G_0(i\omega)`.

Returns
-------
{ret_0}
   The connected two-particle Green's function :math:`G^{(2)}_{conn}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_f0db3514 = _c2py_fun_f0db3514.doc(
   R"DOC(
Calculate the full two-particle Green's function :math:`G^{(2)}`.

Adds the disconnected contribution, built from the interacting Green's function
:math:`G`, to the connected two-particle Green's function.

Parameters
----------
G2_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{conn}(i\omega)`.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The full two-particle Green's function :math:`G^{(2)}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_f6dd79b0 = _c2py_fun_f6dd79b0.doc(
   R"DOC(
Calculate the connected part of :math:`G^{(2)}` in the particle-hole channel.

Combines the measured building block :math:`M^{(4)}_{ph}` with the single-particle
building block :math:`M` and the non-interacting Green's function :math:`G_0` to form the
connected two-particle Green's function in the particle-hole channel.

Parameters
----------
M4ph_iw : {par_0}
   The building block :math:`M^{(4)}_{ph}(i\omega)` in the particle-hole channel.
M_iw : {par_1}
   The building block :math:`M(i\omega)`.
G0_iw : {par_2}
   The non-interacting Green's function :math:`G_0(i\omega)`.

Returns
-------
{ret_0}
   The connected two-particle Green's function :math:`G^{(2)}_{ph,conn}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_c9244676 = _c2py_fun_c9244676.doc(
   R"DOC(
Calculate the full :math:`G^{(2)}` in the particle-hole channel.

Adds the disconnected contribution, built from the interacting Green's function
:math:`G`, to the connected two-particle Green's function in the particle-hole channel.

Parameters
----------
G2ph_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{ph,conn}(i\omega)` in the particle-hole channel.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The full two-particle Green's function :math:`G^{(2)}_{ph}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_1451c110 = _c2py_fun_1451c110.doc(
   R"DOC(
Calculate the connected part of :math:`G^{(2)}` in the particle-particle channel.

Combines the measured building block :math:`M^{(4)}_{pp}` with the single-particle
building block :math:`M` and the non-interacting Green's function :math:`G_0` to form the
connected two-particle Green's function in the particle-particle channel.

Parameters
----------
M4pp_iw : {par_0}
   The building block :math:`M^{(4)}_{pp}(i\omega)` in the particle-particle channel.
M_iw : {par_1}
   The building block :math:`M(i\omega)`.
G0_iw : {par_2}
   The non-interacting Green's function :math:`G_0(i\omega)`.

Returns
-------
{ret_0}
   The connected two-particle Green's function :math:`G^{(2)}_{pp,conn}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_ac4d3526 = _c2py_fun_ac4d3526.doc(
   R"DOC(
Calculate the full :math:`G^{(2)}` in the particle-particle channel.

Adds the disconnected contribution, built from the interacting Green's function
:math:`G`, to the connected two-particle Green's function in the particle-particle channel.

Parameters
----------
G2pp_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{pp,conn}(i\omega)` in the particle-particle channel.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The full two-particle Green's function :math:`G^{(2)}_{pp}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
static const auto _c2py_doc_b1774cef = _c2py_fun_b1774cef.doc(R"DOC(
Calculate the connected two-point correlator :math:`\chi^{(2)}_{conn}` in the particle-hole channel from :math:`M^{(3)}`.

Forms the connected :math:`\chi^{(2)}` in imaginary time from the measured building
block :math:`M^{(3)}(\tau)` and its equal-time peak, together with the single-particle quantities
:math:`M`, :math:`G_0`, and the Hartree term of :math:`M`.

Parameters
----------
M3ph_tau : {par_0}
   The building block :math:`M^{(3)}_{ph}(\tau)` in the particle-hole channel.
M3ph_delta : {par_1}
   The equal-time peak of :math:`M^{(3)}_{ph}(\tau)`.
M_iw : {par_2}
   The building block :math:`M(i\omega)`.
G0_iw : {par_3}
   The non-interacting Green's function :math:`G_0(i\omega)`.
M_tau : {par_4}
   The building block :math:`M(\tau)` in imaginary time.
M_hartree : {par_5}
   The Hartree term of :math:`M`.
G0_tau : {par_6}
   The non-interacting Green's function :math:`G_0(\tau)` in imaginary time.

Returns
-------
{ret_0}
   The connected two-point correlator :math:`\chi^{(2)}_{ph,conn}(\tau)` in the particle-hole channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi3_tau_t>()},
                                                               {c2py::python_typename<triqs_ctint::chi2_tau_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_tau_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()},
                                                               {c2py::python_typename<triqs_ctint::g_tau_cv_t>()}},
                                                              {c2py::python_typename<triqs_ctint::chi2_tau_t>()});
static const auto _c2py_doc_a9774057 = _c2py_fun_a9774057.doc(R"DOC(
Calculate the connected two-point correlator :math:`\chi^{(2)}_{conn}` in the particle-particle channel from :math:`M^{(3)}`.

Forms the connected :math:`\chi^{(2)}` in imaginary time from the measured building
block :math:`M^{(3)}(\tau)` and its equal-time peak, together with the single-particle quantities
:math:`M`, :math:`G_0`, and the Hartree term of :math:`M`.

Parameters
----------
M3pp_tau : {par_0}
   The building block :math:`M^{(3)}_{pp}(\tau)` in the particle-particle channel.
M3pp_delta : {par_1}
   The equal-time peak of :math:`M^{(3)}_{pp}(\tau)`.
M_iw : {par_2}
   The building block :math:`M(i\omega)`.
G0_iw : {par_3}
   The non-interacting Green's function :math:`G_0(i\omega)`.
M_tau : {par_4}
   The building block :math:`M(\tau)` in imaginary time.
M_hartree : {par_5}
   The Hartree term of :math:`M`.
G0_tau : {par_6}
   The non-interacting Green's function :math:`G_0(\tau)` in imaginary time.

Returns
-------
{ret_0}
   The connected two-point correlator :math:`\chi^{(2)}_{pp,conn}(\tau)` in the particle-particle channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi3_tau_t>()},
                                                               {c2py::python_typename<triqs_ctint::chi2_tau_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_tau_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()},
                                                               {c2py::python_typename<triqs_ctint::g_tau_cv_t>()}},
                                                              {c2py::python_typename<triqs_ctint::chi2_tau_t>()});
static const auto _c2py_doc_42522553 = _c2py_fun_42522553.doc(R"DOC(
Calculate the two-point correlator :math:`\chi^{(2)}` in the particle-hole channel.

Adds the disconnected contribution, built from the interacting Green's function
:math:`G` and the density, to the connected :math:`\chi^{(2)}` in imaginary time.

Parameters
----------
chi2_conn_tau : {par_0}
   The connected correlator :math:`\chi^{(2)}_{conn}(\tau)` in imaginary time.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.
dens_G : {par_2}
   The density obtained from the interacting Green's function :math:`G`.

Returns
-------
{ret_0}
   The two-point correlator :math:`\chi^{(2)}_{ph}(\tau)` in the particle-hole channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi2_tau_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()}},
                                                              {c2py::python_typename<triqs_ctint::chi2_tau_t>()});
static const auto _c2py_doc_5a524b1b = _c2py_fun_5a524b1b.doc(R"DOC(
Calculate the two-point correlator :math:`\chi^{(2)}` in the particle-particle channel.

Adds the disconnected contribution, built from the interacting Green's function
:math:`G` and the density, to the connected :math:`\chi^{(2)}` in imaginary time.

Parameters
----------
chi2_conn_tau : {par_0}
   The connected correlator :math:`\chi^{(2)}_{conn}(\tau)` in imaginary time.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.
dens_G : {par_2}
   The density obtained from the interacting Green's function :math:`G`.

Returns
-------
{ret_0}
   The two-point correlator :math:`\chi^{(2)}_{pp}(\tau)` in the particle-particle channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi2_tau_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()}},
                                                              {c2py::python_typename<triqs_ctint::chi2_tau_t>()});
static const auto _c2py_doc_bb34d11d = _c2py_fun_bb34d11d.doc(R"DOC(
Calculate the three-point correlator :math:`\chi^{(3)}` in the particle-hole channel.

Forms :math:`\chi^{(3)}_{ph}` from the measured building block :math:`M^{(3)}`, the
single-particle building block :math:`M`, the non-interacting Green's function :math:`G_0`, the
density obtained from :math:`G`, and the Hartree term of :math:`M`.

Parameters
----------
M3_iw : {par_0}
   The building block :math:`M^{(3)}(i\omega)`.
M_iw : {par_1}
   The building block :math:`M(i\omega)`.
G0_iw : {par_2}
   The non-interacting Green's function :math:`G_0(i\omega)`.
dens_G : {par_3}
   The density obtained from the interacting Green's function :math:`G`.
M_hartree : {par_4}
   The Hartree term of :math:`M`.

Returns
-------
{ret_0}
   The three-point correlator :math:`\chi^{(3)}_{ph}(i\omega)` in the particle-hole channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi3_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()}},
                                                              {c2py::python_typename<triqs_ctint::chi3_iw_t>()});
static const auto _c2py_doc_c334ddb5 = _c2py_fun_c334ddb5.doc(R"DOC(
Calculate the three-point correlator :math:`\chi^{(3)}` in the particle-particle channel.

Forms :math:`\chi^{(3)}_{pp}` from the measured building block :math:`M^{(3)}`, the
single-particle building block :math:`M`, the non-interacting Green's function :math:`G_0`, the
density obtained from :math:`G`, and the Hartree term of :math:`M`.

Parameters
----------
M3_iw : {par_0}
   The building block :math:`M^{(3)}(i\omega)`.
M_iw : {par_1}
   The building block :math:`M(i\omega)`.
G0_iw : {par_2}
   The non-interacting Green's function :math:`G_0(i\omega)`.
dens_G : {par_3}
   The density obtained from the interacting Green's function :math:`G`.
M_hartree : {par_4}
   The Hartree term of :math:`M`.

Returns
-------
{ret_0}
   The three-point correlator :math:`\chi^{(3)}_{pp}(i\omega)` in the particle-particle channel.
)DOC",
                                                              {{c2py::python_typename<triqs_ctint::chi3_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()},
                                                               {c2py::python_typename<const triqs_ctint::block_matrix_t &>()}},
                                                              {c2py::python_typename<triqs_ctint::chi3_iw_t>()});
static const auto _c2py_doc_1c896075 =
   _c2py_fun_1c896075.doc(R"DOC(
Calculate the operator-pair correlation function :math:`\chi_{AB}` in the particle-hole channel.

Contracts the two-point correlator :math:`\chi^{(2)}_{ph}` with the operator pairs
:math:`A` and :math:`B` to form :math:`\chi_{AB}(\tau)`.

Parameters
----------
chi2ph_tau : {par_0}
   The two-point correlator :math:`\chi^{(2)}_{ph}(\tau)` in the particle-hole channel.
gf_struct : {par_1}
   The block structure of the Green's function.
A_op_vec : {par_2}
   The list of operators :math:`A`.
B_op_vec : {par_3}
   The list of operators :math:`B`.

Returns
-------
{ret_0}
   The operator-pair correlation function :math:`\chi_{AB}(\tau)`.
)DOC",
                          {{c2py::python_typename<triqs_ctint::chi2_tau_cv_t>()},
                           {c2py::python_typename<const triqs::gfs::gf_struct_t &>()},
                           {c2py::python_typename<const std::vector<triqs::operators::many_body_operator> &>()},
                           {c2py::python_typename<const std::vector<triqs::operators::many_body_operator> &>()}},
                          {c2py::python_typename<triqs::gfs::gf<triqs::mesh::imtime, triqs::gfs::matrix_valued>>()});
static const auto _c2py_doc_148953dd =
   _c2py_fun_148953dd.doc(R"DOC(
Calculate the operator-pair correlation function :math:`\chi_{AB}` in the particle-particle channel.

Contracts the two-point correlator :math:`\chi^{(2)}_{pp}` with the operator pairs
:math:`A` and :math:`B` to form :math:`\chi_{AB}(\tau)`.

Parameters
----------
chi2pp_tau : {par_0}
   The two-point correlator :math:`\chi^{(2)}_{pp}(\tau)` in the particle-particle channel.
gf_struct : {par_1}
   The block structure of the Green's function.
A_op_vec : {par_2}
   The list of operators :math:`A`.
B_op_vec : {par_3}
   The list of operators :math:`B`.

Returns
-------
{ret_0}
   The operator-pair correlation function :math:`\chi_{AB}(\tau)`.
)DOC",
                          {{c2py::python_typename<triqs_ctint::chi2_tau_cv_t>()},
                           {c2py::python_typename<const triqs::gfs::gf_struct_t &>()},
                           {c2py::python_typename<const std::vector<triqs::operators::many_body_operator> &>()},
                           {c2py::python_typename<const std::vector<triqs::operators::many_body_operator> &>()}},
                          {c2py::python_typename<triqs::gfs::gf<triqs::mesh::imtime, triqs::gfs::matrix_valued>>()});
static const auto _c2py_doc_0449eafd = _c2py_fun_0449eafd.doc(
   R"DOC(
Calculate the generalized particle-hole susceptibility.

Forms the generalized particle-hole susceptibility :math:`\tilde\chi_{ph}` from the
connected two-particle Green's function in the particle-hole channel and the interacting
Green's function :math:`G`.

Parameters
----------
G2ph_conn_iw : {par_0}
   The connected two-particle Green's function :math:`G^{(2)}_{ph,conn}(i\omega)` in the particle-hole channel.
G_iw : {par_1}
   The interacting Green's function :math:`G(i\omega)`.

Returns
-------
{ret_0}
   The generalized particle-hole susceptibility :math:`\tilde\chi_{ph}(i\omega)`.
)DOC",
   {{c2py::python_typename<triqs::gfs::block_gf<triqs::mesh::prod<triqs::mesh::imfreq, triqs::mesh::imfreq, triqs::mesh::imfreq>,
                                                triqs::gfs::tensor_valued<4>, nda::C_layout, 2>::const_view_type>()},
    {c2py::python_typename<triqs_ctint::g_reg_iw_cv_t>()}},
   {c2py::python_typename<triqs_ctint::chi4_iw_t>()});
//--------------------- module function table  -----------------------------

// clang-format off
static PyMethodDef module_methods[] = {
   PMDF("F_from_G2c", 35241b53),
   PMDF("Fph_from_G2ph_conn", c7470a29),
   PMDF("Fpp_from_G2pp_conn", 2e56d769),
   PMDF("G2_conn_from_M4", 2dbe60b0),
   PMDF("G2_from_G2c", f0db3514),
   PMDF("G2ph_conn_from_M4ph", f6dd79b0),
   PMDF("G2ph_from_G2ph_conn", c9244676),
   PMDF("G2pp_conn_from_M4pp", 1451c110),
   PMDF("G2pp_from_G2pp_conn", ac4d3526),
   PMDF("chi2_conn_from_M3_PH", b1774cef),
   PMDF("chi2_conn_from_M3_PP", a9774057),
   PMDF("chi2_from_chi2_conn_PH", 42522553),
   PMDF("chi2_from_chi2_conn_PP", 5a524b1b),
   PMDF("chi3_from_M3_PH", bb34d11d),
   PMDF("chi3_from_M3_PP", c334ddb5),
   PMDF("chiAB_from_chi2_PH", 1c896075),
   PMDF("chiAB_from_chi2_PP", 148953dd),
   PMDF("chi_tilde_ph_from_G2ph_conn", 0449eafd),
   {nullptr, nullptr, 0, nullptr}  // Sentinel
};
// clang-format on

//--------------------- module struct & init error definition ------------

//// module doc directly in the code or "" if not present...
/// Or mandatory ?
static struct PyModuleDef module_def = {PyModuleDef_HEAD_INIT,
                                        "post_process",                          /* name of module */
                                        R"RAWDOC(Postprocess utilities.)RAWDOC", /* module documentation, may be NULL */
                                        -1, /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
                                        module_methods,
                                        NULL,
                                        NULL,
                                        NULL,
                                        NULL};

//--------------------- module init function -----------------------------

extern "C" __attribute__((visibility("default"))) PyObject *PyInit_post_process() {

  if (not c2py::check_python_version("post_process")) return NULL;

  // import numpy iff 'numpy/arrayobject.h' included
#ifdef Py_ARRAYOBJECT_H
  import_array();
#endif

  PyObject *m;

  m = PyModule_Create(&module_def);
  if (m == NULL) return NULL;

  if (not c2py::register_internal_types()) return NULL;
#define _add_type(T, N)                                                                                                                              \
  if (not c2py::add_type_object_to_main<T>(N, m)) return NULL

#undef _add_type

  return m;
}
#endif
// CLAIR_WRAP_GEN
