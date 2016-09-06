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

#include "RedbackGrainSizeAux.h"

template <>
InputParameters
validParams<RedbackGrainSizeAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addParam<Real>("delta", 1, "Kamenetskii coefficient.");
  params.addCoupledVar("temperature", 0.0, "temperature variable");
  params.addRequiredParam<UserObjectName>("flow_law_dislocation", "Name of the user object implementing the dislocation flow law in use");

  // Steady-State Grain Size
  params.addParam<Real>("pre_exponential_factor_ss", 1.0, "Value of pre-exponential factor for steady-state grain size (A^*_{ss}.");

  // Grain Size Reduction
  params.addParam<Real>("lambda", 0.1, "Microstructural energy storage constant (lambda)"); // Assumed from eperimental work that 0.9 converted to heat
  params.addParam<Real>("gamma", 1.0, "Grain boundary energy constant (gamma)"); // Assumed from Covey-Crump (1997)

  // Grain Size Growth
  params.addParam<Real>("Arrhenius_growth", 175.0, "Arrhenius growth (Qg)"); // Assumed from Covey-Crump (1997)
  params.addParam<Real>("growth_exponent", 3.0, "Grain growth constant (p)"); // Assumed from Covey-Crump (1997)
  params.addParam<Real>("growth_constant", 2511.9, "Grain growth constant (Kg)"); // Assumed from Covey-Crump (1997)

  return params;
}

RedbackGrainSizeAux::RedbackGrainSizeAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _has_T(isCoupled("temperature")),
    _T(_has_T ? coupledValue("temperature") : _zero),
    //_initial_grain_size(coupledValue("initial_grain_size")),
    _flow_law_dis_uo(getUserObject<RedbackFlowLawDislocation>("flow_law_dislocation")),
    _mises_stress(getMaterialProperty<Real>("mises_stress")),
    _mises_strain_rate(getMaterialProperty<Real>("mises_strain_rate")), // total plastic strain rate
    _strain_rate_dis(getMaterialProperty<Real>("dislocation_strain_rate")), // dislocation strain rate
    _delta_param(getParam<Real>("delta")),
    _ar_growth_param(getParam<Real>("Arrhenius_growth")),
    _growth_exponent_param(getParam<Real>("growth_exponent")),
    _growth_constant_param(getParam<Real>("growth_constant")),
    _lambda_param(getParam<Real>("lambda")),
    _gamma_param(getParam<Real>("gamma")),
    _A_star_ss_param(getParam<Real>("pre_exponential_factor_ss"))
{
}

Real
RedbackGrainSizeAux::computeValue()
{
  Real grain_size = -1.0;
  if (_has_T)
  {
    Real beta = _strain_rate_dis[_qp] / _mises_strain_rate[_qp];
    // TODO: all temperatures need to be put to full dimensions first. (All formulas are wrong)
    // All expressions need to be checked for normalisation
    Real pi = 3.14159265358979323846;
    Real grain_reduction = beta * _lambda_param/(pi*_gamma_param) * _mises_stress[ _qp ]
      * _mises_strain_rate[ _qp ] * std::pow(_u_old[ _qp ],2) * _dt;
    Real grain_growth = _growth_constant_param * std::pow(_u_old[ _qp ], 1 -_growth_exponent_param)
      * std::exp(- _ar_growth_param/(1 + _T[_qp])) * _dt;

    Real n_dis = _flow_law_dis_uo.getStressExponent();
    Real m_prime = (n_dis + 1)/ (_growth_exponent_param + 1);
    Real _ar_dis = _flow_law_dis_uo.getArrhenius();
    Real _pre_exp_factor_dir = _flow_law_dis_uo.getPreExponentialFactor();
    Real ar_ss = (_ar_growth_param - _ar_dis)/(_growth_exponent_param + 1); // Q_prime
    Real steady_state_grain_size = _A_star_ss_param
      * std::pow(_mises_stress[ _qp ], m_prime)* std::exp(ar_ss*_delta_param*_T[_qp]/(1 + _delta_param*_T[_qp]));

    if (_u_old[ _qp ] < steady_state_grain_size)
      grain_size = fmin(grain_growth, steady_state_grain_size);
    else if (_u_old[ _qp ] > steady_state_grain_size)
      grain_size = fmax(steady_state_grain_size, grain_reduction);
    else
      grain_size = steady_state_grain_size;
  }
  return grain_size;
}
