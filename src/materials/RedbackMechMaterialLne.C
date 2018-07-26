/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Ellipse.h"
#include "RedbackMechMaterialLne.h"
#include <cmath> //used for fabs

template <>
InputParameters
validParams<RedbackMechMaterialLne>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  params.addParam<Real>("slope_yield_surface", 0, "Slope M of critical line");
  params.addParam<Real>("M_e", 1, "slope (>0) of critical state line in extension");
  params.addParam<Real>("M_c", 1, "slope (>0)of critical state line in compression");
  params.addParam<Real>(
      "alpha", 1, "material parameter controlling location (in p') of yield surface maximum");
  params.addParam<Real>(
      "beta", 1, "material parameter controlling width of yield surface bell curve");
  params.addParam<Real>("theta", 0, "Lode angle (using positive cosine)");
  // params.addParam<Real>("p_c", 0, "isotropic compression strength (normalised, positive)"); // no
  // need, using yield_stress
  params.addParam<Real>("p_t", 0, "tensile strength (normalised, negative)"); // user convention:
                                                                              // positive in
                                                                              // compression, but
                                                                              // the code works with
                                                                              // the other
                                                                              // convention
  return params;
}

RedbackMechMaterialLne::RedbackMechMaterialLne(const InputParameters & parameters)
  : RedbackMechMaterial(parameters),
    _M(std::fabs(getParam<Real>("slope_yield_surface"))),
    _M_e(std::fabs(getParam<Real>("M_e"))),
    _M_c(std::fabs(getParam<Real>("M_c"))),
    _alpha(getParam<Real>("alpha")),
    _beta(getParam<Real>("beta")),
    _theta(getParam<Real>("theta")),
    //_p_c(getParam<Real>("p_c")),
    _p_t(-getParam<Real>("p_t")) // keeping our (silly) inconsistency
{
  if (_M == 0)
    mooseError("RedbackMechMaterialLne cannot deal with 0 CSL slope");
  /*if (_p_c <= _p_t)
    mooseError("RedbackMechMaterialLne needs the compression strength "\
      "to be larger than the tensile strength");*/
  // Check loss of concavity: TODO
  Real c = _M_e / _M_c;
  Real gamma = 2 * c / (1 + c - (1 - c) * std::cos(3 * _theta));
  _M_f = _M * gamma;
}

/**
 * Get flow tensor in deviatoric direction, Lne model
 */
void
RedbackMechMaterialLne::getFlowTensor(const RankTwoTensor & sig,
                                      Real q,
                                      Real p,
                                      Real /*q_y*/,
                                      Real /*p_y*/,
                                      Real yield_stress,
                                      RankTwoTensor & flow_tensor)
{
  Real pc = -yield_stress;
  Real h = std::exp(-std::pow((p - _p_t) / (pc - _p_t) - _alpha, 2) / _beta);
  Real A =
      std::pow(_M_f, 2) * h *
      (2 * p - (_p_t + pc) -
       2 * (p - _p_t) * (p - pc) * ((p - _p_t) / (pc - _p_t) - _alpha) / (_beta * (pc - _p_t))) /
      3.;
  flow_tensor = 3.0 * sig.deviatoric();
  flow_tensor.addIa(A);
  // Normalise flow tensor
  flow_tensor /= std::sqrt(3 * std::pow(A, 2) + 6 * std::pow(q, 2));
}

/**
 * Compute the flow incrmement for Lne model
 */
Real
RedbackMechMaterialLne::getFlowIncrement(Real /*sig_eqv*/,
                                         Real /*pressure*/,
                                         Real /*q_yield_stress*/,
                                         Real /*p_yield_stress*/,
                                         Real yield_stress,
                                         Real s)
{
  Real pc = -yield_stress;
  Real sigma_0 = std::fabs(pc - _p_t);
  return _ref_pe_rate * _dt * std::pow(s / sigma_0, _exponent) * _exponential;
}

void
RedbackMechMaterialLne::getJac(const RankTwoTensor & sig,
                               const RankFourTensor & E_ijkl,
                               Real flow_incr,
                               Real sig_eqv,
                               Real pressure,
                               Real p_yield_stress,
                               Real q_yield_stress,
                               Real yield_stress,
                               Real s,
                               RankFourTensor & dresid_dsig)
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, flow_dirn_vol, flow_dirn_dev, fij, flow_dirn, flow_tensor;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dsig, dfi_dsig;
  Real f0, f1, f2, f3, f4, f5, f6;
  Real dfi_dp, dfi_dseqv, dfi_ds, sigma_0;

  Real pc = -yield_stress;
  sig_dev = sig.deviatoric();

  // getDerivativeFlowIncrement(dfi_dp, dfi_dseqv, sig, pressure, sig_eqv, pc, q_yield_stress,
  // p_yield_stress, s);
  getFlowTensor(sig, sig_eqv, pressure, q_yield_stress, p_yield_stress, yield_stress, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the
   *residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow
   *direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative
   *of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */
  f0 = 0.0;
  if (sig_eqv > 1e-10)
    f0 = 3.0 / (2.0 * sig_eqv);

  Real X_1 = 2 * pressure - (_p_t + pc);
  Real X_2 = (pressure - _p_t) * (pressure - pc) / (pc - _p_t);
  Real X_3 = (pressure - _p_t) / (pc - _p_t) - _alpha;
  Real X = (X_1 - 2.0 * X_2 * X_3 / _beta);
  Real h = std::exp(-std::pow(X_3, 2) / _beta);
  Real Mf2hX = std::pow(_M_f, 2) * h * X;
  Real A = Mf2hX / 3.0;
  Real Z = h * (1.0 - (X_1 * X_3 + X_2) / (_beta * (pc - _p_t)));
  Real Y = (2.0 * std::pow(_M_f, 2) / 9.0) * (Z - h * X_3 * X / (_beta * (pc - _p_t)));
  Real norm = std::sqrt(3 * std::pow(A, 2) + 6 * std::pow(sig_eqv, 2));

  // derivative of flow increment with respect to s (overstress)
  sigma_0 = std::fabs(pc - _p_t);
  dfi_ds = _exponent * _ref_pe_rate * _dt * std::pow(s / sigma_0, _exponent - 1) * _exponential /
           sigma_0;

  // derivatives of flow increment with respect to p and q
  dfi_dp = dfi_ds * std::pow(_M_f, 2) * h * X / (2 * s);
  dfi_dseqv = dfi_ds * sig_eqv / s;

  f1 = (Y - 1.0) / norm;
  f2 = 3.0 / norm;
  f3 = Mf2hX / (3.0 * std::pow(norm, 3));
  f4 = 3.0 / std::pow(norm, 3);
  f5 = (2.0 / 3.0) * std::pow(_M_f, 2) * A * Z;
  f6 = 9.0;

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) =
              flow_dirn(i, j) * (f0 * sig_dev(k, l) * dfi_dseqv + dfi_dp * deltaFunc(k, l) / 3.0);

  // This loop calculates the second term (d n_ij / d sigma_kl)
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i, j, k, l) = f1 * deltaFunc(i, j) * deltaFunc(k, l) +
                                 f2 * deltaFunc(i, k) * deltaFunc(j, l) -
                                 (f3 * deltaFunc(i, j) + f4 * sig_dev(i, j)) *
                                     (f5 * deltaFunc(k, l) + f6 * sig_dev(k, l));

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackMechMaterialLne::get_py_qy(
    Real p, Real q, Real & p_y, Real & q_y, Real yield_stress, bool & is_plastic, Real & s)
{
  // Check if outside the ellipse
  Real pc = -yield_stress;
  Real h = std::exp(-std::pow((p - _p_t) / (pc - _p_t) - _alpha, 2) / _beta);
  Real potential = std::pow(q, 2) + std::pow(_M_f, 2) * h * (p - _p_t) * (p - pc);
  is_plastic = (potential > 0);

  // use potential for overstress
  s = std::sqrt(potential);
  // yield point actually irrelevant!
  p_y = 1e99;
  q_y = 1e99;

  // get yield point in any case (even if elastic)
  // Ellipse::getYieldPointLne(_M, _M_e, _M_c, _alpha, _beta, _theta,
  //    -_p_t, pc, p, q, p_y, q_y, s);
}

void RedbackMechMaterialLne::form_damage_kernels(Real /*q_y*/) {}
