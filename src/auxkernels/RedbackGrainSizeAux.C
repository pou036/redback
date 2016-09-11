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
  //params.addParam<Real>("lambda", 0.1, "Microstructural energy storage constant (lambda)"); // Assumed from experimental work that 0.9 converted to heat
  //params.addParam<Real>("gamma", 1.0, "Grain boundary energy constant (gamma)");
  params.addParam<Real>("pre_exponential_factor_reduction", 1.0, "Value of pre-exponential factor for reduction rate of grain size (A^*_{red}).");

  // Grain Size Growth
  params.addParam<Real>("Arrhenius_growth", 175.0, "Arrhenius growth (Qg)");
  params.addParam<Real>("growth_exponent", 3.0, "Grain growth constant (p)");
  params.addParam<Real>("pre_exponential_factor_growth", 1.0, "Value of pre-exponential factor for growth rate of grain size (A^*_g).");

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
    _pre_exp_factor_growth(getParam<Real>("pre_exponential_factor_growth")),
    //_lambda_param(getParam<Real>("lambda")),
    //_gamma_param(getParam<Real>("gamma")),
    _pre_exp_factor_reduction(getParam<Real>("pre_exponential_factor_reduction")),
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
    Real grain_reduction_rate = _pre_exp_factor_reduction * beta * _mises_stress[ _qp ]
      * _mises_strain_rate[ _qp ] * std::pow(_u_old[ _qp ],2);
    Real grain_growth_rate = _pre_exp_factor_growth * 1/_growth_exponent_param * std::pow(_u_old[ _qp ], 1 -_growth_exponent_param)
      * std::exp(_ar_growth_param*_delta_param*_T[_qp]/(1 + _delta_param*_T[_qp]));

    Real n_dis = _flow_law_dis_uo.getStressExponent();
    Real m_prime = (n_dis + 1)/ (_growth_exponent_param + 1);
    Real ar_dis = _flow_law_dis_uo.getArrhenius();
    Real ar_ss = (_ar_growth_param - ar_dis)/(_growth_exponent_param + 1);
    Real steady_state_grain_size = _A_star_ss_param
      * std::pow(_mises_stress[ _qp ], -m_prime)* std::exp(ar_ss*_delta_param*_T[_qp]/(1 + _delta_param*_T[_qp]));

    if (_u_old[ _qp ] < steady_state_grain_size)
      grain_size = fmin(_u_old[ _qp ] + grain_growth_rate*_dt, steady_state_grain_size);
    else if (_u_old[ _qp ] > steady_state_grain_size)
      grain_size = fmax(steady_state_grain_size, _u_old[ _qp ] - grain_reduction_rate*_dt);
    else
      grain_size = steady_state_grain_size;
  }
  return grain_size;
}
