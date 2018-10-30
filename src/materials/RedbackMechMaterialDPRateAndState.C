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

#include "RedbackMechMaterialDPRateAndState.h"

template <>
InputParameters
validParams<RedbackMechMaterialDPRateAndState>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  // TODO: deal with sign of _slope_yield_surface properly in DP case
  params.addParam<Real>("slope_yield_surface", 0, "Slope of yield surface (usually negative)");
  params.addParam<Real>("a", 0, "the a coefficient");
  params.addParam<Real>("b", 0, "the b coefficient");
  return params;
}

RedbackMechMaterialDPRateAndState::RedbackMechMaterialDPRateAndState(const InputParameters & parameters)
  : RedbackMechMaterial(parameters),
  _slope_yield_surface(getParam<Real>("slope_yield_surface")),
  _a(getParam<Real>("a")),
  _b(getParam<Real>("b"))
{
}

/**
 * Compute pressure projection of stress on Drucker-Prager yield surface
 */
Real
RedbackMechMaterialDPRateAndState::getPressureProjection(Real pressure, Real sig_eqv, Real cohesion)
{
  // yield pressure, for non-associative, replace mu^2 with mu*dilatency
  // the "fmin" is to handle the apex. Apparently fmin(1/0, x) = x, so it's
  // always true
  // return fmin(-cohesion/_slope_yield_surface, (pressure +
  // _slope_yield_surface*(sig_eqv - cohesion))
  //    / (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));

  if (_slope_yield_surface == 0)
    return pressure;
  else if (_slope_yield_surface < 0)
    return fmin(-cohesion / _slope_yield_surface,
                (pressure + _slope_yield_surface * (sig_eqv - cohesion)) /
                    (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  else
  {
    // _slope_yield_surface > 0, for whatever reason...
    return fmax(-cohesion / _slope_yield_surface,
                (pressure + _slope_yield_surface * (sig_eqv - cohesion)) /
                    (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  }
}

void
RedbackMechMaterialDPRateAndState::getFlowTensor(const RankTwoTensor & sig,
                                     Real q,
                                     Real /*p*/,
                                     Real /*q_y*/,
                                     Real /*p_y*/,
                                     Real /*yield_stress*/,
                                     RankTwoTensor & flow_tensor)
{
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = 3.0 / (2.0 * q);
  flow_tensor = sig_dev * val;
  flow_tensor.addIa(-_slope_yield_surface / 3.0);
  flow_tensor /= std::pow(3.0 / 2.0 + _slope_yield_surface * _slope_yield_surface, 0.5);
}

/**
 * Compute flow increment for Drucker-Prager case
 */
Real
RedbackMechMaterialDPRateAndState::getFlowIncrement(
    Real sig_eqv, Real pressure, Real /*q_yield_stress*/, Real /*p_yield_stress*/, Real /*yield_stress*/)
{
  if (sig_eqv/pressure < _slope_yield_surface)
    return 0.0;
  return _ref_pe_rate * _dt * exp(-_slope_yield_surface/(_a-_b) + sig_eqv/(pressure*(_a-_b)));
}

void
RedbackMechMaterialDPRateAndState::getDerivativeFlowIncrement(Real & dfi_dp,
                                                  Real & dfi_dq,
                                                  const RankTwoTensor & /*sig*/,
                                                  Real pressure,
                                                  Real sig_eqv,
                                                  Real /*yield_stress*/,
                                                  Real /*q_yield_stress*/,
                                                  Real /*p_yield_stress*/)
{
  Real factor = _ref_pe_rate * _dt * exp(-_slope_yield_surface/(_a-_b));
  dfi_dp = - factor * sig_eqv/((_a-_b) * pow(pressure,2)) * exp(sig_eqv/(pressure*(_a-_b)));
  dfi_dq = factor/((_a-_b) * pressure) * exp(sig_eqv/(pressure*(_a-_b)));
}

void
RedbackMechMaterialDPRateAndState::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real yield_stress,
                              RankFourTensor & dresid_dsig)
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, fij, flow_dirn;
  RankTwoTensor dfi_dft;
  RankFourTensor dfd_dft, dfd_dsig, dfi_dsig;
  Real f1, f2, f3, f4;
  Real dfi_dp, dfi_dseqv;

  sig_dev = sig.deviatoric();

  getDerivativeFlowIncrement(
      dfi_dp, dfi_dseqv, sig, pressure, sig_eqv, yield_stress, q_yield_stress, p_yield_stress);
  getFlowTensor(sig, sig_eqv, pressure, q_yield_stress, p_yield_stress, yield_stress, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the
   * residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow
   * direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative
   * of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;
  f4 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv * std::pow(3.0 / 2.0 + _slope_yield_surface * _slope_yield_surface, 0.5));
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0) * std::pow(3.0 / 2.0 + _slope_yield_surface * _slope_yield_surface, 0.5));
    f4 = 3.0 / (2.0 * sig_eqv);
  }

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) =
              flow_dirn(i, j) * (f4 * sig_dev(k, l) * dfi_dseqv + dfi_dp * deltaFunc(k, l) / 3.0);

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i, j, k, l) = f1 * deltaFunc(i, k) * deltaFunc(j, l) -
                                 f2 * deltaFunc(i, j) * deltaFunc(k, l) -
                                 f3 * sig_dev(i, j) * sig_dev(k, l);

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackMechMaterialDPRateAndState::get_py_qy(
    Real p, Real q, Real & p_y, Real & q_y, Real yield_stress, bool & is_plastic)
{
  p_y = getPressureProjection(p /*p*/, q /*q*/, yield_stress /*yield stress*/);
  q_y = yield_stress + _slope_yield_surface * p_y; // yield deviatoric stress
  // Check for plasticity
  is_plastic = (q >= yield_stress + _slope_yield_surface * p);
}
