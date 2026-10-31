
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
#include <c2py/serialization/h5.hpp>

using c2py::operator""_a;

// ==================== enums =====================

// ==================== module classes =====================

// --------- class _c2py_cls_5068255a -----------
using _c2py_cls_5068255a                                            = triqs_ctint::constr_params_t;
template <> constexpr bool c2py::is_wrapped<_c2py_cls_5068255a>     = true;
template <> inline constexpr auto c2py::tp_name<_c2py_cls_5068255a> = "triqs_ctint.solver_core.ConstrParamsT";

static int synth_constructor_645bfd34(PyObject *self, PyObject *args, PyObject *kwargs) {
  if (args and PyTuple_Check(args) and (PyTuple_Size(args) > 0)) {
    PyErr_SetString(PyExc_RuntimeError,
                    ("Error in constructing triqs_ctint::constr_params_t.\nNo positional arguments allowed. Use keywords arguments"));
    return -1;
  }
  c2py::pydict_extractor de{kwargs};
  try {
    ((c2py::wrap<_c2py_cls_5068255a> *)self)->_c = new _c2py_cls_5068255a{};
  } catch (std::exception const &e) {
    PyErr_SetString(PyExc_RuntimeError, ("Error in constructing triqs_ctint::constr_params_t from a Python dict.\n   "s + e.what()).c_str());
    return -1;
  }
  auto &self_c = *(((c2py::wrap<_c2py_cls_5068255a> *)self)->_c);
  de("n_tau", self_c.n_tau, true);
  de("dlr_wmax", self_c.dlr_wmax, false);
  de("dlr_eps", self_c.dlr_eps, true);
  de("beta", self_c.beta, false);
  de("gf_struct", self_c.gf_struct, false);
  de("use_D", self_c.use_D, true);
  de("use_Jperp", self_c.use_Jperp, true);
  de("n_tau_dynamical_interactions", self_c.n_tau_dynamical_interactions, true);
  return de.check();
}

template <> constexpr initproc c2py::tp_init<_c2py_cls_5068255a> = synth_constructor_645bfd34;

template <>
const std::string c2py::tp_ctor_doc<_c2py_cls_5068255a> = c2py::replace_tags(
   R"DOC(Synthesized constructor with the following keyword arguments:

Parameters
----------
dlr_wmax : {par_0}

beta : {par_1}

gf_struct : {par_2}

n_tau : {par_3}, default=5001

dlr_eps : {par_4}, default=1e-10

use_D : {par_5}, default=false

use_Jperp : {par_6}, default=false

n_tau_dynamical_interactions : {par_7}, default=this->n_tau

)DOC",
   "par",
   {c2py::python_typename<double>(), c2py::python_typename<double>(), c2py::python_typename<triqs::gfs::gf_struct_t>(), c2py::python_typename<int>(),
    c2py::python_typename<double>(), c2py::python_typename<bool>(), c2py::python_typename<bool>(), c2py::python_typename<int>()});
// block_names
static auto const _c2py_fun_9ca459cc =
   c2py::dispatcher_f_kw_t{c2py::cmethod([](_c2py_cls_5068255a const &self) -> decltype(auto) { return self.block_names(); }, "self")};

// n_blocks
static auto const _c2py_fun_e5f8983b =
   c2py::dispatcher_f_kw_t{c2py::cmethod([](_c2py_cls_5068255a const &self) -> decltype(auto) { return self.n_blocks(); }, "self")};

static const auto _c2py_doc_9ca459cc = _c2py_fun_9ca459cc.doc(R"DOC(
Names of the blocks of the Green's function.
)DOC");
static const auto _c2py_doc_e5f8983b = _c2py_fun_e5f8983b.doc(R"DOC(
Number of blocks of the Green's function.
)DOC");

// ----- Method table ----
// clang-format off
template <> PyMethodDef c2py::tp_methods<_c2py_cls_5068255a>[] = {
   PMDF("block_names", 9ca459cc),
   PMDF("n_blocks", e5f8983b),
   {nullptr, nullptr, 0, nullptr} // Sentinel
};
// clang-format on

constexpr auto _c2py_doc_member_7654a601 = R"DOC(Number of imaginary-time points for the single-particle quantities.)DOC";
constexpr auto _c2py_doc_member_4e8fb5ac = R"DOC(DLR bandwidth cutoff :math:`w_{max} = \Lambda / \beta` for the single-particle quantities.)DOC";
constexpr auto _c2py_doc_member_66cde27d = R"DOC(DLR error tolerance :math:`\epsilon` for the single-particle quantities.)DOC";
constexpr auto _c2py_doc_member_85f92c8c = R"DOC(Inverse temperature :math:`\beta`.)DOC";
constexpr auto _c2py_doc_member_45916571 = R"DOC(Structure of the Green's function (names and sizes of blocks).)DOC";
constexpr auto _c2py_doc_member_1bfd99b2 = R"DOC(Use a dynamic density-density interaction?)DOC";
constexpr auto _c2py_doc_member_3cb4e92d = R"DOC(Use a dynamic spin-spin interaction?)DOC";
constexpr auto _c2py_doc_member_ba20494a = R"DOC(Number of imaginary-time points for :math:`D_0(\tau)` and :math:`J_\perp(\tau)`.)DOC";
static PyObject *prop_get_dict_645bfd34(PyObject *self, void *) {
  auto &self_c = *(((c2py::wrap<_c2py_cls_5068255a> *)self)->_c);
  c2py::pydict dic;
  dic["n_tau"]                        = self_c.n_tau;
  dic["dlr_wmax"]                     = self_c.dlr_wmax;
  dic["dlr_eps"]                      = self_c.dlr_eps;
  dic["beta"]                         = self_c.beta;
  dic["gf_struct"]                    = self_c.gf_struct;
  dic["use_D"]                        = self_c.use_D;
  dic["use_Jperp"]                    = self_c.use_Jperp;
  dic["n_tau_dynamical_interactions"] = self_c.n_tau_dynamical_interactions;
  return dic.new_ref();
}

// ----- Member and property table ----

template <>
constinit PyGetSetDef c2py::tp_getset<_c2py_cls_5068255a>[] = {
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::n_tau, _c2py_cls_5068255a>("n_tau", _c2py_doc_member_7654a601),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::dlr_wmax, _c2py_cls_5068255a>("dlr_wmax", _c2py_doc_member_4e8fb5ac),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::dlr_eps, _c2py_cls_5068255a>("dlr_eps", _c2py_doc_member_66cde27d),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::beta, _c2py_cls_5068255a>("beta", _c2py_doc_member_85f92c8c),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::gf_struct, _c2py_cls_5068255a>("gf_struct", _c2py_doc_member_45916571),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::use_D, _c2py_cls_5068255a>("use_D", _c2py_doc_member_1bfd99b2),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::use_Jperp, _c2py_cls_5068255a>("use_Jperp", _c2py_doc_member_3cb4e92d),
   c2py::getsetdef_from_member<&_c2py_cls_5068255a::n_tau_dynamical_interactions, _c2py_cls_5068255a>("n_tau_dynamical_interactions",
                                                                                                      _c2py_doc_member_ba20494a),
   {"__dict__", (getter)prop_get_dict_645bfd34, nullptr, "", nullptr},
   {nullptr, nullptr, nullptr, nullptr, nullptr}};

template <>
const std::string c2py::tp_doc<_c2py_cls_5068255a> =
   R"DOC(Parameters used for constructing the solver class.)DOC" + std::string{"\n\n----------\n\n"} + c2py::tp_ctor_doc<_c2py_cls_5068255a>;
// --------- class _c2py_cls_81f689d4 -----------
using _c2py_cls_81f689d4                                            = triqs_ctint::solve_params_t;
template <> constexpr bool c2py::is_wrapped<_c2py_cls_81f689d4>     = true;
template <> inline constexpr auto c2py::tp_name<_c2py_cls_81f689d4> = "triqs_ctint.solver_core.SolveParamsT";

static int synth_constructor_7569c250(PyObject *self, PyObject *args, PyObject *kwargs) {
  if (args and PyTuple_Check(args) and (PyTuple_Size(args) > 0)) {
    PyErr_SetString(PyExc_RuntimeError,
                    ("Error in constructing triqs_ctint::solve_params_t.\nNo positional arguments allowed. Use keywords arguments"));
    return -1;
  }
  c2py::pydict_extractor de{kwargs};
  try {
    ((c2py::wrap<_c2py_cls_81f689d4> *)self)->_c = new _c2py_cls_81f689d4{};
  } catch (std::exception const &e) {
    PyErr_SetString(PyExc_RuntimeError, ("Error in constructing triqs_ctint::solve_params_t from a Python dict.\n   "s + e.what()).c_str());
    return -1;
  }
  auto &self_c = *(((c2py::wrap<_c2py_cls_81f689d4> *)self)->_c);
  de("h_int", self_c.h_int, false);
  de("n_s", self_c.n_s, true);
  de("alpha", self_c.alpha, false);
  de("n_cycles", self_c.n_cycles, false);
  de("length_cycle", self_c.length_cycle, true);
  de("n_warmup_cycles", self_c.n_warmup_cycles, true);
  de("random_seed", self_c.random_seed, true);
  de("random_name", self_c.random_name, true);
  de("use_double_insertion", self_c.use_double_insertion, true);
  de("insertion_types", self_c.insertion_types, true);
  de("use_submatrix", self_c.use_submatrix, true);
  de("submatrix_size", self_c.submatrix_size, true);
  de("use_auxiliary_spin_flip", self_c.use_auxiliary_spin_flip, true);
  de("max_time", self_c.max_time, true);
  de("max_order", self_c.max_order, true);
  de("verbosity", self_c.verbosity, true);
  de("rethrow_exception", self_c.rethrow_exception, true);
  de("measure_sign_only", self_c.measure_sign_only, true);
  de("measure_average_sign", self_c.measure_average_sign, true);
  de("measure_average_k", self_c.measure_average_k, true);
  de("measure_auto_corr_time", self_c.measure_auto_corr_time, true);
  de("measure_histogram", self_c.measure_histogram, true);
  de("measure_density", self_c.measure_density, true);
  de("measure_M_tau", self_c.measure_M_tau, true);
  de("measure_M_iw", self_c.measure_M_iw, true);
  de("measure_M4_iw", self_c.measure_M4_iw, true);
  de("measure_M4pp_iw", self_c.measure_M4pp_iw, true);
  de("measure_M4ph_iw", self_c.measure_M4ph_iw, true);
  de("n_iW_M4", self_c.n_iW_M4, true);
  de("n_iw_M4", self_c.n_iw_M4, true);
  de("measure_M3pp_iw", self_c.measure_M3pp_iw, true);
  de("measure_M3ph_iw", self_c.measure_M3ph_iw, true);
  de("n_iw_M3", self_c.n_iw_M3, true);
  de("n_iW_M3", self_c.n_iW_M3, true);
  de("measure_M3pp_tau", self_c.measure_M3pp_tau, true);
  de("measure_M3ph_tau", self_c.measure_M3ph_tau, true);
  de("measure_M3xph_tau", self_c.measure_M3xph_tau, true);
  de("n_tau_M3", self_c.n_tau_M3, true);
  de("measure_chi2pp_tau", self_c.measure_chi2pp_tau, true);
  de("measure_chi2ph_tau", self_c.measure_chi2ph_tau, true);
  de("n_tau_chi2", self_c.n_tau_chi2, true);
  de("n_iw_chi2", self_c.n_iw_chi2, true);
  de("measure_chiAB_tau", self_c.measure_chiAB_tau, true);
  de("chi_A_vec", self_c.chi_A_vec, true);
  de("chi_B_vec", self_c.chi_B_vec, true);
  de("nfft_buf_size", self_c.nfft_buf_size, true);
  de("nfft_tol", self_c.nfft_tol, true);
  de("post_process", self_c.post_process, true);
  de("det_init_size", self_c.det_init_size, true);
  de("det_n_operations_before_check", self_c.det_n_operations_before_check, true);
  de("det_precision_warning", self_c.det_precision_warning, true);
  de("det_precision_error", self_c.det_precision_error, true);
  de("det_singular_threshold", self_c.det_singular_threshold, true);
  return de.check();
}

template <> constexpr initproc c2py::tp_init<_c2py_cls_81f689d4> = synth_constructor_7569c250;

template <>
const std::string c2py::tp_ctor_doc<_c2py_cls_81f689d4> =
   c2py::replace_tags(R"DOC(Synthesized constructor with the following keyword arguments:

Parameters
----------
h_int : {par_0}

alpha : {par_1}

n_cycles : {par_2}

n_s : {par_3}, default=2

length_cycle : {par_4}, default=100

n_warmup_cycles : {par_5}, default=5000

random_seed : {par_6}, default=34788 + 928374 * mpi::communicator().rank()

random_name : {par_7}, default=""

use_double_insertion : {par_8}, default=true

insertion_types : {par_9}, default={}

use_submatrix : {par_10}, default=false

submatrix_size : {par_11}, default=32

use_auxiliary_spin_flip : {par_12}, default=false

max_time : {par_13}, default=-1

max_order : {par_14}, default=-1

verbosity : {par_15}, default== 0 ? 3 : 0

rethrow_exception : {par_16}, default=true

measure_sign_only : {par_17}, default=false

measure_average_sign : {par_18}, default=true

measure_average_k : {par_19}, default=true

measure_auto_corr_time : {par_20}, default=true

measure_histogram : {par_21}, default=false

measure_density : {par_22}, default=true

measure_M_tau : {par_23}, default=true

measure_M_iw : {par_24}, default=false

measure_M4_iw : {par_25}, default=false

measure_M4pp_iw : {par_26}, default=false

measure_M4ph_iw : {par_27}, default=false

n_iW_M4 : {par_28}, default=32

n_iw_M4 : {par_29}, default=32

measure_M3pp_iw : {par_30}, default=false

measure_M3ph_iw : {par_31}, default=false

n_iw_M3 : {par_32}, default=64

n_iW_M3 : {par_33}, default=32

measure_M3pp_tau : {par_34}, default=false

measure_M3ph_tau : {par_35}, default=false

measure_M3xph_tau : {par_36}, default=false

n_tau_M3 : {par_37}, default=201

measure_chi2pp_tau : {par_38}, default=false

measure_chi2ph_tau : {par_39}, default=false

n_tau_chi2 : {par_40}, default=201

n_iw_chi2 : {par_41}, default=32

measure_chiAB_tau : {par_42}, default=false

chi_A_vec : {par_43}, default={}

chi_B_vec : {par_44}, default={}

nfft_buf_size : {par_45}, default=100000

nfft_tol : {par_46}, default=1e-8

post_process : {par_47}, default=true

det_init_size : {par_48}, default=1000

det_n_operations_before_check : {par_49}, default=100

det_precision_warning : {par_50}, default=1.e-8

det_precision_error : {par_51}, default=1.e-5

det_singular_threshold : {par_52}, default=-1

)DOC",
                      "par",
                      {c2py::python_typename<triqs::operators::many_body_operator>(),
                       c2py::python_typename<triqs_ctint::alpha_t>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<std::string>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<std::vector<int>>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<std::vector<triqs::operators::many_body_operator>>(),
                       c2py::python_typename<std::vector<triqs::operators::many_body_operator>>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<double>(),
                       c2py::python_typename<bool>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<int>(),
                       c2py::python_typename<double>(),
                       c2py::python_typename<double>(),
                       c2py::python_typename<double>()});

// ----- Method table ----
// clang-format off
template <> PyMethodDef c2py::tp_methods<_c2py_cls_81f689d4>[] = {
   {nullptr, nullptr, 0, nullptr} // Sentinel
};
// clang-format on

constexpr auto _c2py_doc_member_04295c8e = R"DOC(Interacting part of the local Hamiltonian.)DOC";
constexpr auto _c2py_doc_member_047151a4 = R"DOC(Number of auxiliary spins.)DOC";
constexpr auto _c2py_doc_member_b59f5b04 = R"DOC(The :math:`\alpha` tensor used in the determinantal expansion.)DOC";
constexpr auto _c2py_doc_member_521c5ed4 = R"DOC(Number of QMC cycles.)DOC";
constexpr auto _c2py_doc_member_47be870d = R"DOC(Length of a single QMC cycle.)DOC";
constexpr auto _c2py_doc_member_7fb7e427 = R"DOC(Number of cycles for thermalization.)DOC";
constexpr auto _c2py_doc_member_9f3a10cd = R"DOC(Seed for the random number generator.)DOC";
constexpr auto _c2py_doc_member_12aa171b = R"DOC(Name of the random number generator.)DOC";
constexpr auto _c2py_doc_member_58b6639f = R"DOC(Use double insertion?)DOC";
constexpr auto _c2py_doc_member_df5b539f = R"DOC(Types of insertions to use.)DOC";
constexpr auto _c2py_doc_member_2a3bb3c3 =
   R"DOC(Replace the single insertions and removals by batches of them with submatrix updates of the determinants (for
density-density vertices with their two pairs in two different blocks, as U n_up n_dn). One batch counts as one
move of the cycle; it is proposed with weight 2 / submatrix_size against 1 for each other move.)DOC";
constexpr auto _c2py_doc_member_b8efcf91 = R"DOC(Number of insertion and removal steps in one submatrix batch.)DOC";
constexpr auto _c2py_doc_member_49b77d49 = R"DOC(Use auxiliary spin-flip insertion (requires :math:`n_s = 2`)?)DOC";
constexpr auto _c2py_doc_member_edcf89aa = R"DOC(Maximum runtime in seconds, use -1 to set infinite.)DOC";
constexpr auto _c2py_doc_member_7eebfd75 = R"DOC(Maximum perturbation order accepted during insertion and removal moves (use -1 for unlimited).)DOC";
constexpr auto _c2py_doc_member_de8ec3c9 = R"DOC(Verbosity level.)DOC";
constexpr auto _c2py_doc_member_64ce0fd5 = R"DOC(Catch exceptions on the nodes and rethrow them on rank 0?)DOC";
constexpr auto _c2py_doc_member_4656dd43 = R"DOC(Measure the sign only?)DOC";
constexpr auto _c2py_doc_member_594b226c = R"DOC(Measure the Monte-Carlo sign?)DOC";
constexpr auto _c2py_doc_member_1efec732 = R"DOC(Measure the average perturbation order?)DOC";
constexpr auto _c2py_doc_member_67b59bdf = R"DOC(Measure the auto-correlation time?)DOC";
constexpr auto _c2py_doc_member_7c0e2bb9 = R"DOC(Measure the perturbation-order distribution?)DOC";
constexpr auto _c2py_doc_member_2e5f33c3 = R"DOC(Measure the density by operator insertion?)DOC";
constexpr auto _c2py_doc_member_569c2fc1 = R"DOC(Measure :math:`M(\tau)`?)DOC";
constexpr auto _c2py_doc_member_eda83c41 = R"DOC(Measure :math:`M(i\omega)` using NFFT?)DOC";
constexpr auto _c2py_doc_member_2d274845 = R"DOC(Measure :math:`M^{(4)}(i\omega)` using NFFT?)DOC";
constexpr auto _c2py_doc_member_c0ca9dc5 = R"DOC(Measure :math:`M^{(4)}_{pp}(i\omega)` using NFFT?)DOC";
constexpr auto _c2py_doc_member_6b6fba9d = R"DOC(Measure :math:`M^{(4)}_{ph}(i\omega)` using NFFT?)DOC";
constexpr auto _c2py_doc_member_01881229 = R"DOC(Number of positive bosonic Matsubara frequencies in :math:`M^{(4)}`.)DOC";
constexpr auto _c2py_doc_member_ae1d05c9 = R"DOC(Number of positive fermionic Matsubara frequencies in :math:`M^{(4)}`.)DOC";
constexpr auto _c2py_doc_member_f3008dea = R"DOC(Measure :math:`M^{(3)}_{pp}(i\omega)`?)DOC";
constexpr auto _c2py_doc_member_82f4fcf2 = R"DOC(Measure :math:`M^{(3)}_{ph}(i\omega)`?)DOC";
constexpr auto _c2py_doc_member_af1d075c = R"DOC(Number of positive fermionic Matsubara frequencies in :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_028813bc = R"DOC(Number of positive bosonic Matsubara frequencies in :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_915193fc = R"DOC(Measure :math:`M^{(3)}_{pp}(\tau)`?)DOC";
constexpr auto _c2py_doc_member_6950bf04 = R"DOC(Measure :math:`M^{(3)}_{ph}(\tau)`?)DOC";
constexpr auto _c2py_doc_member_ab89fc02 = R"DOC(Measure :math:`M^{(3)}_{xph}(\tau)`?)DOC";
constexpr auto _c2py_doc_member_45bcc02c = R"DOC(Number of imaginary-time points in :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_e5a437f8 = R"DOC(Measure :math:`\chi^{(2)}_{pp}(\tau)` by insertion?)DOC";
constexpr auto _c2py_doc_member_b68b6df0 = R"DOC(Measure :math:`\chi^{(2)}_{ph}(\tau)` by insertion?)DOC";
constexpr auto _c2py_doc_member_0767a1c4 = R"DOC(Number of imaginary-time points in :math:`\chi^{(2)}`.)DOC";
constexpr auto _c2py_doc_member_1498b1f4 = R"DOC(Number of positive Matsubara frequencies in :math:`\chi^{(2)}`.)DOC";
constexpr auto _c2py_doc_member_0feb28f7 = R"DOC(Measure :math:`\chi_{AB}(\tau)` by insertion?)DOC";
constexpr auto _c2py_doc_member_8962a7ef = R"DOC(List of all operators :math:`A`.)DOC";
constexpr auto _c2py_doc_member_c2b3ca5e = R"DOC(List of all operators :math:`B`.)DOC";
constexpr auto _c2py_doc_member_ac3bbcb0 = R"DOC(Size of the NFFT buffer.)DOC";
constexpr auto _c2py_doc_member_9e2f3b6e = R"DOC(Tolerance for the NFFT transform.)DOC";
constexpr auto _c2py_doc_member_b7b607ac = R"DOC(Perform post-processing?)DOC";
constexpr auto _c2py_doc_member_50142de8 = R"DOC(The maximum size of the determinant matrix before a resize.)DOC";
constexpr auto _c2py_doc_member_5e26bdf4 = R"DOC(Maximum number of operations before testing the accuracy of :math:`\det(M)` and :math:`M^{-1}`.)DOC";
constexpr auto _c2py_doc_member_33eb6d19 = R"DOC(Threshold for determinant precision warnings.)DOC";
constexpr auto _c2py_doc_member_2d4d4d6f = R"DOC(Threshold for determinant precision errors.)DOC";
constexpr auto _c2py_doc_member_eb16d70f =
   R"DOC(Bound for the determinant matrix being singular (if :math:`< 0`, checks for subnormal numbers instead).)DOC";
static PyObject *prop_get_dict_7569c250(PyObject *self, void *) {
  auto &self_c = *(((c2py::wrap<_c2py_cls_81f689d4> *)self)->_c);
  c2py::pydict dic;
  dic["h_int"]                         = self_c.h_int;
  dic["n_s"]                           = self_c.n_s;
  dic["alpha"]                         = self_c.alpha;
  dic["n_cycles"]                      = self_c.n_cycles;
  dic["length_cycle"]                  = self_c.length_cycle;
  dic["n_warmup_cycles"]               = self_c.n_warmup_cycles;
  dic["random_seed"]                   = self_c.random_seed;
  dic["random_name"]                   = self_c.random_name;
  dic["use_double_insertion"]          = self_c.use_double_insertion;
  dic["insertion_types"]               = self_c.insertion_types;
  dic["use_submatrix"]                 = self_c.use_submatrix;
  dic["submatrix_size"]                = self_c.submatrix_size;
  dic["use_auxiliary_spin_flip"]       = self_c.use_auxiliary_spin_flip;
  dic["max_time"]                      = self_c.max_time;
  dic["max_order"]                     = self_c.max_order;
  dic["verbosity"]                     = self_c.verbosity;
  dic["rethrow_exception"]             = self_c.rethrow_exception;
  dic["measure_sign_only"]             = self_c.measure_sign_only;
  dic["measure_average_sign"]          = self_c.measure_average_sign;
  dic["measure_average_k"]             = self_c.measure_average_k;
  dic["measure_auto_corr_time"]        = self_c.measure_auto_corr_time;
  dic["measure_histogram"]             = self_c.measure_histogram;
  dic["measure_density"]               = self_c.measure_density;
  dic["measure_M_tau"]                 = self_c.measure_M_tau;
  dic["measure_M_iw"]                  = self_c.measure_M_iw;
  dic["measure_M4_iw"]                 = self_c.measure_M4_iw;
  dic["measure_M4pp_iw"]               = self_c.measure_M4pp_iw;
  dic["measure_M4ph_iw"]               = self_c.measure_M4ph_iw;
  dic["n_iW_M4"]                       = self_c.n_iW_M4;
  dic["n_iw_M4"]                       = self_c.n_iw_M4;
  dic["measure_M3pp_iw"]               = self_c.measure_M3pp_iw;
  dic["measure_M3ph_iw"]               = self_c.measure_M3ph_iw;
  dic["n_iw_M3"]                       = self_c.n_iw_M3;
  dic["n_iW_M3"]                       = self_c.n_iW_M3;
  dic["measure_M3pp_tau"]              = self_c.measure_M3pp_tau;
  dic["measure_M3ph_tau"]              = self_c.measure_M3ph_tau;
  dic["measure_M3xph_tau"]             = self_c.measure_M3xph_tau;
  dic["n_tau_M3"]                      = self_c.n_tau_M3;
  dic["measure_chi2pp_tau"]            = self_c.measure_chi2pp_tau;
  dic["measure_chi2ph_tau"]            = self_c.measure_chi2ph_tau;
  dic["n_tau_chi2"]                    = self_c.n_tau_chi2;
  dic["n_iw_chi2"]                     = self_c.n_iw_chi2;
  dic["measure_chiAB_tau"]             = self_c.measure_chiAB_tau;
  dic["chi_A_vec"]                     = self_c.chi_A_vec;
  dic["chi_B_vec"]                     = self_c.chi_B_vec;
  dic["nfft_buf_size"]                 = self_c.nfft_buf_size;
  dic["nfft_tol"]                      = self_c.nfft_tol;
  dic["post_process"]                  = self_c.post_process;
  dic["det_init_size"]                 = self_c.det_init_size;
  dic["det_n_operations_before_check"] = self_c.det_n_operations_before_check;
  dic["det_precision_warning"]         = self_c.det_precision_warning;
  dic["det_precision_error"]           = self_c.det_precision_error;
  dic["det_singular_threshold"]        = self_c.det_singular_threshold;
  return dic.new_ref();
}

// ----- Member and property table ----

template <>
constinit PyGetSetDef c2py::tp_getset<_c2py_cls_81f689d4>[] = {
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::h_int, _c2py_cls_81f689d4>("h_int", _c2py_doc_member_04295c8e),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_s, _c2py_cls_81f689d4>("n_s", _c2py_doc_member_047151a4),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::alpha, _c2py_cls_81f689d4>("alpha", _c2py_doc_member_b59f5b04),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_cycles, _c2py_cls_81f689d4>("n_cycles", _c2py_doc_member_521c5ed4),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::length_cycle, _c2py_cls_81f689d4>("length_cycle", _c2py_doc_member_47be870d),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_warmup_cycles, _c2py_cls_81f689d4>("n_warmup_cycles", _c2py_doc_member_7fb7e427),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::random_seed, _c2py_cls_81f689d4>("random_seed", _c2py_doc_member_9f3a10cd),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::random_name, _c2py_cls_81f689d4>("random_name", _c2py_doc_member_12aa171b),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::use_double_insertion, _c2py_cls_81f689d4>("use_double_insertion", _c2py_doc_member_58b6639f),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::insertion_types, _c2py_cls_81f689d4>("insertion_types", _c2py_doc_member_df5b539f),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::use_submatrix, _c2py_cls_81f689d4>("use_submatrix", _c2py_doc_member_2a3bb3c3),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::submatrix_size, _c2py_cls_81f689d4>("submatrix_size", _c2py_doc_member_b8efcf91),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::use_auxiliary_spin_flip, _c2py_cls_81f689d4>("use_auxiliary_spin_flip",
                                                                                                 _c2py_doc_member_49b77d49),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::max_time, _c2py_cls_81f689d4>("max_time", _c2py_doc_member_edcf89aa),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::max_order, _c2py_cls_81f689d4>("max_order", _c2py_doc_member_7eebfd75),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::verbosity, _c2py_cls_81f689d4>("verbosity", _c2py_doc_member_de8ec3c9),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::rethrow_exception, _c2py_cls_81f689d4>("rethrow_exception", _c2py_doc_member_64ce0fd5),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_sign_only, _c2py_cls_81f689d4>("measure_sign_only", _c2py_doc_member_4656dd43),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_average_sign, _c2py_cls_81f689d4>("measure_average_sign", _c2py_doc_member_594b226c),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_average_k, _c2py_cls_81f689d4>("measure_average_k", _c2py_doc_member_1efec732),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_auto_corr_time, _c2py_cls_81f689d4>("measure_auto_corr_time", _c2py_doc_member_67b59bdf),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_histogram, _c2py_cls_81f689d4>("measure_histogram", _c2py_doc_member_7c0e2bb9),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_density, _c2py_cls_81f689d4>("measure_density", _c2py_doc_member_2e5f33c3),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M_tau, _c2py_cls_81f689d4>("measure_M_tau", _c2py_doc_member_569c2fc1),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M_iw, _c2py_cls_81f689d4>("measure_M_iw", _c2py_doc_member_eda83c41),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M4_iw, _c2py_cls_81f689d4>("measure_M4_iw", _c2py_doc_member_2d274845),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M4pp_iw, _c2py_cls_81f689d4>("measure_M4pp_iw", _c2py_doc_member_c0ca9dc5),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M4ph_iw, _c2py_cls_81f689d4>("measure_M4ph_iw", _c2py_doc_member_6b6fba9d),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_iW_M4, _c2py_cls_81f689d4>("n_iW_M4", _c2py_doc_member_01881229),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_iw_M4, _c2py_cls_81f689d4>("n_iw_M4", _c2py_doc_member_ae1d05c9),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M3pp_iw, _c2py_cls_81f689d4>("measure_M3pp_iw", _c2py_doc_member_f3008dea),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M3ph_iw, _c2py_cls_81f689d4>("measure_M3ph_iw", _c2py_doc_member_82f4fcf2),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_iw_M3, _c2py_cls_81f689d4>("n_iw_M3", _c2py_doc_member_af1d075c),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_iW_M3, _c2py_cls_81f689d4>("n_iW_M3", _c2py_doc_member_028813bc),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M3pp_tau, _c2py_cls_81f689d4>("measure_M3pp_tau", _c2py_doc_member_915193fc),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M3ph_tau, _c2py_cls_81f689d4>("measure_M3ph_tau", _c2py_doc_member_6950bf04),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_M3xph_tau, _c2py_cls_81f689d4>("measure_M3xph_tau", _c2py_doc_member_ab89fc02),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_tau_M3, _c2py_cls_81f689d4>("n_tau_M3", _c2py_doc_member_45bcc02c),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_chi2pp_tau, _c2py_cls_81f689d4>("measure_chi2pp_tau", _c2py_doc_member_e5a437f8),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_chi2ph_tau, _c2py_cls_81f689d4>("measure_chi2ph_tau", _c2py_doc_member_b68b6df0),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_tau_chi2, _c2py_cls_81f689d4>("n_tau_chi2", _c2py_doc_member_0767a1c4),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::n_iw_chi2, _c2py_cls_81f689d4>("n_iw_chi2", _c2py_doc_member_1498b1f4),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::measure_chiAB_tau, _c2py_cls_81f689d4>("measure_chiAB_tau", _c2py_doc_member_0feb28f7),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::chi_A_vec, _c2py_cls_81f689d4>("chi_A_vec", _c2py_doc_member_8962a7ef),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::chi_B_vec, _c2py_cls_81f689d4>("chi_B_vec", _c2py_doc_member_c2b3ca5e),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::nfft_buf_size, _c2py_cls_81f689d4>("nfft_buf_size", _c2py_doc_member_ac3bbcb0),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::nfft_tol, _c2py_cls_81f689d4>("nfft_tol", _c2py_doc_member_9e2f3b6e),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::post_process, _c2py_cls_81f689d4>("post_process", _c2py_doc_member_b7b607ac),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::det_init_size, _c2py_cls_81f689d4>("det_init_size", _c2py_doc_member_50142de8),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::det_n_operations_before_check, _c2py_cls_81f689d4>("det_n_operations_before_check",
                                                                                                       _c2py_doc_member_5e26bdf4),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::det_precision_warning, _c2py_cls_81f689d4>("det_precision_warning", _c2py_doc_member_33eb6d19),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::det_precision_error, _c2py_cls_81f689d4>("det_precision_error", _c2py_doc_member_2d4d4d6f),
   c2py::getsetdef_from_member<&_c2py_cls_81f689d4::det_singular_threshold, _c2py_cls_81f689d4>("det_singular_threshold", _c2py_doc_member_eb16d70f),
   {"__dict__", (getter)prop_get_dict_7569c250, nullptr, "", nullptr},
   {nullptr, nullptr, nullptr, nullptr, nullptr}};

template <>
const std::string c2py::tp_doc<_c2py_cls_81f689d4> =
   R"DOC(Parameters passed to the solve method of the solver class.)DOC" + std::string{"\n\n----------\n\n"} + c2py::tp_ctor_doc<_c2py_cls_81f689d4>;
// --------- class _c2py_cls_b7a6df6c -----------
using _c2py_cls_b7a6df6c                                            = triqs_ctint::solver_core;
template <> constexpr bool c2py::is_wrapped<_c2py_cls_b7a6df6c>     = true;
template <> inline constexpr auto c2py::tp_name<_c2py_cls_b7a6df6c> = "triqs_ctint.solver_core.SolverCore";
static const auto _c2py_init_d5f661d1 =
   c2py::dispatcher_c_kw_t{c2py::c_constructor<_c2py_cls_b7a6df6c, const triqs_ctint::constr_params_t &>("constr_params_")};
template <> constexpr initproc c2py::tp_init<_c2py_cls_b7a6df6c> = c2py::pyfkw_constructor<_c2py_init_d5f661d1>;
template <>
const std::string c2py::tp_ctor_doc<_c2py_cls_b7a6df6c> = _c2py_init_d5f661d1.doc(R"DOC(
Construct a CT-INT solver.

Parameters
----------
constr_params_ : {par_0}
   Set of parameters used to construct the solver.
)DOC",
                                                                                  {{c2py::python_typename<const triqs_ctint::constr_params_t &>()}});
// post_process
static auto const _c2py_fun_0d864ad4 =
   c2py::dispatcher_f_kw_t{c2py::cmethod([](_c2py_cls_b7a6df6c &self) -> decltype(auto) { return self.post_process(); }, "self")};

// solve
static auto const _c2py_fun_121b7c6b = c2py::dispatcher_f_kw_t{
   c2py::cmethod([](_c2py_cls_b7a6df6c &self, const triqs_ctint::solve_params_t &solve_params) -> decltype(auto) { return self.solve(solve_params); },
                 "self", "solve_params")};

static const auto _c2py_doc_0d864ad4 = _c2py_fun_0d864ad4.doc(R"DOC(
Retrigger post-processing with the last set of parameters.
)DOC");
static const auto _c2py_doc_121b7c6b = _c2py_fun_121b7c6b.doc(R"DOC(
Solve the impurity problem with a CT-INT calculation.

Parameters
----------
solve_params : {par_0}
   Set of parameters used for the solve.
)DOC",
                                                              {{c2py::python_typename<const triqs_ctint::solve_params_t &>()}});

// ----- Method table ----
// clang-format off
template <> PyMethodDef c2py::tp_methods<_c2py_cls_b7a6df6c>[] = {
   PMDF("post_process", 0d864ad4),
   PMDF("solve", 121b7c6b),
   {"__write_hdf5__", c2py::tpxx_write_h5<_c2py_cls_b7a6df6c>, METH_VARARGS, "  "},
   {"__getstate__", c2py::getstate_h5<_c2py_cls_b7a6df6c>, METH_NOARGS, ""},
   {"__setstate__", c2py::setstate_h5<_c2py_cls_b7a6df6c>, METH_O, ""},
   {nullptr, nullptr, 0, nullptr} // Sentinel
};
// clang-format on

constexpr auto _c2py_doc_member_d903023c = R"DOC(Non-interacting Green's function :math:`G_0(i\omega)` in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_93eb1f44 = R"DOC(Inverse of the non-interacting Green's function :math:`G_0^{-1}(i\omega)`.)DOC";
constexpr auto _c2py_doc_member_72605465 = R"DOC(Dynamic density-density interaction :math:`D_0(i\omega)` in Matsubara frequencies (DLR mesh).)DOC";
constexpr auto _c2py_doc_member_909b18d4 = R"DOC(Dynamic spin-spin interaction :math:`J_\perp(i\omega)` in Matsubara frequencies (DLR mesh).)DOC";
constexpr auto _c2py_doc_member_72f2d715 = R"DOC(The shifted non-interacting Green's function in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_ad902905 = R"DOC(The shifted non-interacting Green's function in imaginary time.)DOC";
constexpr auto _c2py_doc_member_4df17d5a = R"DOC(Parameters used to construct the solver.)DOC";
constexpr auto _c2py_doc_member_9d1a0eeb = R"DOC(Parameters used in the last solve (empty until the solver has been run).)DOC";
constexpr auto _c2py_doc_member_1e9fc171 = R"DOC(Average Monte-Carlo sign.)DOC";
constexpr auto _c2py_doc_member_cc76dda7 = R"DOC(Total number of measurements.)DOC";
constexpr auto _c2py_doc_member_b5de05b1 = R"DOC(Average perturbation order.)DOC";
constexpr auto _c2py_doc_member_01901a8c = R"DOC(Error bar on the average sign.)DOC";
constexpr auto _c2py_doc_member_509d57cc = R"DOC(Error bar on the average perturbation order.)DOC";
constexpr auto _c2py_doc_member_851eded2 = R"DOC(Auto-correlation time.)DOC";
constexpr auto _c2py_doc_member_e1dc0ee4 = R"DOC(Warmup time in seconds.)DOC";
constexpr auto _c2py_doc_member_4e70af8d = R"DOC(Accumulation time in seconds.)DOC";
constexpr auto _c2py_doc_member_c558b41a = R"DOC(Perturbation-order distribution.)DOC";
constexpr auto _c2py_doc_member_622f5a08 = R"DOC(The density (measured by operator insertion).)DOC";
constexpr auto _c2py_doc_member_d685da76 = R"DOC(Building block for the Green's function in imaginary time :math:`M(\tau)`.)DOC";
constexpr auto _c2py_doc_member_0e3ee1a7 = R"DOC(Hartree term of :math:`M(\tau)`.)DOC";
constexpr auto _c2py_doc_member_1a31e713 =
   R"DOC(Same as :math:`M(\tau)`, but measured directly in Matsubara frequencies using NFFT on the DLR grid.)DOC";
constexpr auto _c2py_doc_member_ad37448a =
   R"DOC(Building block :math:`M^{(4)}(i\omega)` for the full vertex, measured in Matsubara frequencies using NFFT.)DOC";
constexpr auto _c2py_doc_member_83c34582 =
   R"DOC(Building block :math:`M^{(4)}_{pp}(i\omega)` (particle-particle channel) for the full vertex, measured using NFFT.)DOC";
constexpr auto _c2py_doc_member_0048e4da =
   R"DOC(Building block :math:`M^{(4)}_{ph}(i\omega)` (particle-hole channel) for the full vertex, measured using NFFT.)DOC";
constexpr auto _c2py_doc_member_cedc36c0 =
   R"DOC(Building block :math:`M^{(3)}_{pp}(i\omega)` (particle-particle channel) for the fermion-boson vertex, measured using NFFT.)DOC";
constexpr auto _c2py_doc_member_203728f8 =
   R"DOC(Building block :math:`M^{(3)}_{ph}(i\omega)` (particle-hole channel) for the fermion-boson vertex, measured using NFFT.)DOC";
constexpr auto _c2py_doc_member_481e24ad =
   R"DOC(Building block :math:`M^{(3)}_{pp}(\tau)` (particle-particle channel) for the fermion-boson vertex in imaginary time.)DOC";
constexpr auto _c2py_doc_member_9e88eeb5 =
   R"DOC(Building block :math:`M^{(3)}_{ph}(\tau)` (particle-hole channel) for the fermion-boson vertex in imaginary time.)DOC";
constexpr auto _c2py_doc_member_63e396e5 =
   R"DOC(Building block :math:`M^{(3)}_{xph}(\tau)` (particle-hole-cross channel) for the fermion-boson vertex in imaginary time.)DOC";
constexpr auto _c2py_doc_member_3bf02f55 = R"DOC(Equal-time peak of :math:`M^{(3)}_{pp}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_44e29b8d = R"DOC(Equal-time peak of :math:`M^{(3)}_{ph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_230d049d = R"DOC(Equal-time peak of :math:`M^{(3)}_{xph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_4363aec5 =
   R"DOC(Correlator :math:`\chi^{(2)}_{pp}(\tau)` (particle-particle channel) in imaginary time, obtained by operator insertion.)DOC";
constexpr auto _c2py_doc_member_4560dadd =
   R"DOC(Correlator :math:`\chi^{(2)}_{ph}(\tau)` (particle-hole channel) in imaginary time, obtained by operator insertion.)DOC";
constexpr auto _c2py_doc_member_5c14cdc8 = R"DOC(Correlation function :math:`\chi_{AB}(\tau)` in imaginary time.)DOC";
constexpr auto _c2py_doc_member_ece03d34 = R"DOC(Fourier transform of :math:`M(\tau)`.)DOC";
constexpr auto _c2py_doc_member_7379739e = R"DOC(Green's function :math:`G(i\omega)` in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_1c38d004 =
   R"DOC(Dynamic self-energy :math:`\Sigma_{dyn}(i\omega)` in Matsubara frequencies (DLR, decays to zero).)DOC";
constexpr auto _c2py_doc_member_1d06a31b = R"DOC(Static (Hartree) part of the self-energy, :math:`\Sigma = \Sigma_{dyn} + \Sigma_{hartree}`.)DOC";
constexpr auto _c2py_doc_member_e049e4dd =
   R"DOC(Building block :math:`M^{(3)}_{pp}(i\omega)` (particle-particle channel) for the fermion-boson vertex in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_35a33505 =
   R"DOC(Building block :math:`M^{(3)}_{ph}(i\omega)` (particle-hole channel) for the fermion-boson vertex in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_5525dd75 =
   R"DOC(Building block :math:`M^{(3)}_{xph}(i\omega)` (particle-hole-cross channel) for the fermion-boson vertex in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_d3fea37f = R"DOC(The two-particle vertex function :math:`F` in purely fermionic notation.)DOC";
constexpr auto _c2py_doc_member_6c8515ef = R"DOC(The two-particle vertex function :math:`F` (particle-particle channel).)DOC";
constexpr auto _c2py_doc_member_61bcc5b7 = R"DOC(The two-particle vertex function :math:`F` (particle-hole channel).)DOC";
constexpr auto _c2py_doc_member_e9f93ca5 = R"DOC(Connected part of the two-particle Green's function :math:`G^{(2)}`.)DOC";
constexpr auto _c2py_doc_member_578665ed =
   R"DOC(Connected part of the two-particle Green's function :math:`G^{(2)}` (particle-particle channel).)DOC";
constexpr auto _c2py_doc_member_e03b74d5 = R"DOC(Connected part of the two-particle Green's function :math:`G^{(2)}` (particle-hole channel).)DOC";
constexpr auto _c2py_doc_member_42b1bd3e = R"DOC(The two-particle Green's function :math:`G^{(2)}`.)DOC";
constexpr auto _c2py_doc_member_fb7abb76 = R"DOC(The two-particle Green's function :math:`G^{(2)}` (particle-particle channel).)DOC";
constexpr auto _c2py_doc_member_26915cee = R"DOC(The two-particle Green's function :math:`G^{(2)}` (particle-hole channel).)DOC";
constexpr auto _c2py_doc_member_9a8bd1d5 =
   R"DOC(Correlator :math:`\chi^{(2)}_{pp}(i\omega)` (particle-particle channel) in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_c5a2734d = R"DOC(Correlator :math:`\chi^{(2)}_{ph}(i\omega)` (particle-hole channel) in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_5acfab88 =
   R"DOC(Connected :math:`\chi^{(2)}` (particle-particle channel) in imaginary time, obtained from :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_f5241a40 =
   R"DOC(Connected :math:`\chi^{(2)}` (particle-hole channel) in imaginary time, obtained from :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_14e278d0 =
   R"DOC(Connected :math:`\chi^{(2)}` (particle-hole-cross channel) in imaginary time, obtained from :math:`M^{(3)}`.)DOC";
constexpr auto _c2py_doc_member_49472dcf =
   R"DOC(Correlator :math:`\chi^{(2)}_{pp}(\tau)` (particle-particle channel), obtained from :math:`M^{(3)}_{pp}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_7eb3bc97 =
   R"DOC(Correlator :math:`\chi^{(2)}_{ph}(\tau)` (particle-hole channel), obtained from :math:`M^{(3)}_{ph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_8ecffaa7 =
   R"DOC(Correlator :math:`\chi^{(2)}_{xph}(\tau)` (particle-hole-cross channel), obtained from :math:`M^{(3)}_{xph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_e395811f =
   R"DOC(Correlator :math:`\chi^{(2)}_{pp}(i\omega)` (particle-particle channel), obtained from :math:`M^{(3)}_{pp}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_14ed1387 =
   R"DOC(Correlator :math:`\chi^{(2)}_{ph}(i\omega)` (particle-hole channel), obtained from :math:`M^{(3)}_{ph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_d6331697 =
   R"DOC(Correlator :math:`\chi^{(2)}_{xph}(i\omega)` (particle-hole-cross channel), obtained from :math:`M^{(3)}_{xph}(\tau)`.)DOC";
constexpr auto _c2py_doc_member_ef41d046 = R"DOC(Correlation function :math:`\chi_{AB}(i\omega)` in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_20298adc =
   R"DOC(Correlator :math:`\chi^{(3)}_{pp}(i\omega)` (particle-particle channel) in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_4377d1c4 = R"DOC(Correlator :math:`\chi^{(3)}_{ph}(i\omega)` (particle-hole channel) in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_8be9a196 =
   R"DOC(Correlator :math:`\chi^{(3)}_{xph}(i\omega)` (particle-hole-cross channel) in Matsubara frequencies.)DOC";
constexpr auto _c2py_doc_member_728406cb =
   R"DOC(Correlator :math:`\chi^{(3)}_{pp}(i\omega)` (particle-particle channel), obtained from the NFFT :math:`M^{(3)}` measurement.)DOC";
constexpr auto _c2py_doc_member_5f4ecf43 =
   R"DOC(Correlator :math:`\chi^{(3)}_{ph}(i\omega)` (particle-hole channel), obtained from the NFFT :math:`M^{(3)}` measurement.)DOC";

// ----- Member and property table ----

template <>
constinit PyGetSetDef c2py::tp_getset<_c2py_cls_b7a6df6c>[] = {
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G0_iw, _c2py_cls_b7a6df6c>("G0_iw", _c2py_doc_member_d903023c),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G0_iw_inv, _c2py_cls_b7a6df6c>("G0_iw_inv", _c2py_doc_member_93eb1f44),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::D0_iw, _c2py_cls_b7a6df6c>("D0_iw", _c2py_doc_member_72605465),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::Jperp_iw, _c2py_cls_b7a6df6c>("Jperp_iw", _c2py_doc_member_909b18d4),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G0_shift_iw, _c2py_cls_b7a6df6c>("G0_shift_iw", _c2py_doc_member_72f2d715),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G0_shift_tau, _c2py_cls_b7a6df6c>("G0_shift_tau", _c2py_doc_member_ad902905),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::constr_params, _c2py_cls_b7a6df6c>("constr_params", _c2py_doc_member_4df17d5a),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::last_solve_params, _c2py_cls_b7a6df6c>("last_solve_params", _c2py_doc_member_9d1a0eeb),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::average_sign, _c2py_cls_b7a6df6c>("average_sign", _c2py_doc_member_1e9fc171),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::nmeasures, _c2py_cls_b7a6df6c>("nmeasures", _c2py_doc_member_cc76dda7),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::average_k, _c2py_cls_b7a6df6c>("average_k", _c2py_doc_member_b5de05b1),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::average_sign_error, _c2py_cls_b7a6df6c>("average_sign_error", _c2py_doc_member_01901a8c),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::average_k_error, _c2py_cls_b7a6df6c>("average_k_error", _c2py_doc_member_509d57cc),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::auto_corr_time, _c2py_cls_b7a6df6c>("auto_corr_time", _c2py_doc_member_851eded2),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::warmup_time, _c2py_cls_b7a6df6c>("warmup_time", _c2py_doc_member_e1dc0ee4),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::accumulation_time, _c2py_cls_b7a6df6c>("accumulation_time", _c2py_doc_member_4e70af8d),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::histogram, _c2py_cls_b7a6df6c>("histogram", _c2py_doc_member_c558b41a),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::density, _c2py_cls_b7a6df6c>("density", _c2py_doc_member_622f5a08),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M_tau, _c2py_cls_b7a6df6c>("M_tau", _c2py_doc_member_d685da76),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M_hartree, _c2py_cls_b7a6df6c>("M_hartree", _c2py_doc_member_0e3ee1a7),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M_iw_nfft, _c2py_cls_b7a6df6c>("M_iw_nfft", _c2py_doc_member_1a31e713),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M4_iw, _c2py_cls_b7a6df6c>("M4_iw", _c2py_doc_member_ad37448a),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M4pp_iw, _c2py_cls_b7a6df6c>("M4pp_iw", _c2py_doc_member_83c34582),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M4ph_iw, _c2py_cls_b7a6df6c>("M4ph_iw", _c2py_doc_member_0048e4da),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3pp_iw_nfft, _c2py_cls_b7a6df6c>("M3pp_iw_nfft", _c2py_doc_member_cedc36c0),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3ph_iw_nfft, _c2py_cls_b7a6df6c>("M3ph_iw_nfft", _c2py_doc_member_203728f8),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3pp_tau, _c2py_cls_b7a6df6c>("M3pp_tau", _c2py_doc_member_481e24ad),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3ph_tau, _c2py_cls_b7a6df6c>("M3ph_tau", _c2py_doc_member_9e88eeb5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3xph_tau, _c2py_cls_b7a6df6c>("M3xph_tau", _c2py_doc_member_63e396e5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3pp_delta, _c2py_cls_b7a6df6c>("M3pp_delta", _c2py_doc_member_3bf02f55),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3ph_delta, _c2py_cls_b7a6df6c>("M3ph_delta", _c2py_doc_member_44e29b8d),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3xph_delta, _c2py_cls_b7a6df6c>("M3xph_delta", _c2py_doc_member_230d049d),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2pp_tau, _c2py_cls_b7a6df6c>("chi2pp_tau", _c2py_doc_member_4363aec5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2ph_tau, _c2py_cls_b7a6df6c>("chi2ph_tau", _c2py_doc_member_4560dadd),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chiAB_tau, _c2py_cls_b7a6df6c>("chiAB_tau", _c2py_doc_member_5c14cdc8),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M_iw, _c2py_cls_b7a6df6c>("M_iw", _c2py_doc_member_ece03d34),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G_iw, _c2py_cls_b7a6df6c>("G_iw", _c2py_doc_member_7379739e),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::Sigma_dyn_iw, _c2py_cls_b7a6df6c>("Sigma_dyn_iw", _c2py_doc_member_1c38d004),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::Sigma_hartree, _c2py_cls_b7a6df6c>("Sigma_hartree", _c2py_doc_member_1d06a31b),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3pp_iw, _c2py_cls_b7a6df6c>("M3pp_iw", _c2py_doc_member_e049e4dd),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3ph_iw, _c2py_cls_b7a6df6c>("M3ph_iw", _c2py_doc_member_35a33505),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::M3xph_iw, _c2py_cls_b7a6df6c>("M3xph_iw", _c2py_doc_member_5525dd75),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::F_iw, _c2py_cls_b7a6df6c>("F_iw", _c2py_doc_member_d3fea37f),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::Fpp_iw, _c2py_cls_b7a6df6c>("Fpp_iw", _c2py_doc_member_6c8515ef),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::Fph_iw, _c2py_cls_b7a6df6c>("Fph_iw", _c2py_doc_member_61bcc5b7),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2_conn_iw, _c2py_cls_b7a6df6c>("G2_conn_iw", _c2py_doc_member_e9f93ca5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2pp_conn_iw, _c2py_cls_b7a6df6c>("G2pp_conn_iw", _c2py_doc_member_578665ed),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2ph_conn_iw, _c2py_cls_b7a6df6c>("G2ph_conn_iw", _c2py_doc_member_e03b74d5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2_iw, _c2py_cls_b7a6df6c>("G2_iw", _c2py_doc_member_42b1bd3e),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2pp_iw, _c2py_cls_b7a6df6c>("G2pp_iw", _c2py_doc_member_fb7abb76),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::G2ph_iw, _c2py_cls_b7a6df6c>("G2ph_iw", _c2py_doc_member_26915cee),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2pp_iw, _c2py_cls_b7a6df6c>("chi2pp_iw", _c2py_doc_member_9a8bd1d5),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2ph_iw, _c2py_cls_b7a6df6c>("chi2ph_iw", _c2py_doc_member_c5a2734d),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2pp_conn_tau_from_M3, _c2py_cls_b7a6df6c>("chi2pp_conn_tau_from_M3",
                                                                                                 _c2py_doc_member_5acfab88),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2ph_conn_tau_from_M3, _c2py_cls_b7a6df6c>("chi2ph_conn_tau_from_M3",
                                                                                                 _c2py_doc_member_f5241a40),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2xph_conn_tau_from_M3, _c2py_cls_b7a6df6c>("chi2xph_conn_tau_from_M3",
                                                                                                  _c2py_doc_member_14e278d0),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2pp_tau_from_M3, _c2py_cls_b7a6df6c>("chi2pp_tau_from_M3", _c2py_doc_member_49472dcf),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2ph_tau_from_M3, _c2py_cls_b7a6df6c>("chi2ph_tau_from_M3", _c2py_doc_member_7eb3bc97),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2xph_tau_from_M3, _c2py_cls_b7a6df6c>("chi2xph_tau_from_M3", _c2py_doc_member_8ecffaa7),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2pp_iw_from_M3, _c2py_cls_b7a6df6c>("chi2pp_iw_from_M3", _c2py_doc_member_e395811f),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2ph_iw_from_M3, _c2py_cls_b7a6df6c>("chi2ph_iw_from_M3", _c2py_doc_member_14ed1387),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi2xph_iw_from_M3, _c2py_cls_b7a6df6c>("chi2xph_iw_from_M3", _c2py_doc_member_d6331697),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chiAB_iw, _c2py_cls_b7a6df6c>("chiAB_iw", _c2py_doc_member_ef41d046),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi3pp_iw, _c2py_cls_b7a6df6c>("chi3pp_iw", _c2py_doc_member_20298adc),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi3ph_iw, _c2py_cls_b7a6df6c>("chi3ph_iw", _c2py_doc_member_4377d1c4),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi3xph_iw, _c2py_cls_b7a6df6c>("chi3xph_iw", _c2py_doc_member_8be9a196),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi3pp_iw_nfft, _c2py_cls_b7a6df6c>("chi3pp_iw_nfft", _c2py_doc_member_728406cb),
   c2py::getsetdef_from_member<&_c2py_cls_b7a6df6c::chi3ph_iw_nfft, _c2py_cls_b7a6df6c>("chi3ph_iw_nfft", _c2py_doc_member_5f4ecf43),

   {nullptr, nullptr, nullptr, nullptr, nullptr}};

template <>
const std::string c2py::tp_doc<_c2py_cls_b7a6df6c> =
   R"DOC(The CT-INT solver.)DOC" + std::string{"\n\n----------\n\n"} + c2py::tp_ctor_doc<_c2py_cls_b7a6df6c>;

// ==================== module functions ====================

//--------------------- module function table  -----------------------------

// clang-format off
static PyMethodDef module_methods[] = {
   {nullptr, nullptr, 0, nullptr}  // Sentinel
};
// clang-format on

//--------------------- module struct & init error definition ------------

//// module doc directly in the code or "" if not present...
/// Or mandatory ?
static struct PyModuleDef module_def = {PyModuleDef_HEAD_INIT,
                                        "solver_core",                           /* name of module */
                                        R"RAWDOC(The TRIQS ctint solver)RAWDOC", /* module documentation, may be NULL */
                                        -1, /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
                                        module_methods,
                                        NULL,
                                        NULL,
                                        NULL,
                                        NULL};

//--------------------- module init function -----------------------------

extern "C" __attribute__((visibility("default"))) PyObject *PyInit_solver_core() {

  if (not c2py::check_python_version("solver_core")) return NULL;

  // import numpy iff 'numpy/arrayobject.h' included
#ifdef Py_ARRAYOBJECT_H
  import_array();
#endif

  PyObject *m;

  if (PyType_Ready(&c2py::wrap_pytype<_c2py_cls_5068255a>) < 0) return NULL;
  if (PyType_Ready(&c2py::wrap_pytype<_c2py_cls_81f689d4>) < 0) return NULL;
  if (PyType_Ready(&c2py::wrap_pytype<_c2py_cls_b7a6df6c>) < 0) return NULL;

  m = PyModule_Create(&module_def);
  if (m == NULL) return NULL;

  if (not c2py::register_internal_types()) return NULL;
#define _add_type(T, N)                                                                                                                              \
  if (not c2py::add_type_object_to_main<T>(N, m)) return NULL
  _add_type(_c2py_cls_5068255a, "ConstrParamsT");
  _add_type(_c2py_cls_81f689d4, "SolveParamsT");
  _add_type(_c2py_cls_b7a6df6c, "SolverCore");
#undef _add_type

  c2py::pyref module = c2py::pyref::module("h5.formats");
  if (not module) return nullptr;
  c2py::pyref register_class = module.attr("register_class");

  register_h5_type<_c2py_cls_b7a6df6c>(register_class);

  return m;
}
#endif
// CLAIR_WRAP_GEN
