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
  params.addCoupledVar("damage", 0.0, "damage variable");


  params.addRequiredParam<UserObjectName>("flow_law_dislocation", "Name of the user object implementing the dislocation flow law in use");

  // Steady-State Grain Size
  params.addParam<Real>("pre_exponential_factor_ss", 6107416391.26, "Value of pre-exponential factor for steady-state grain size (A^*_{ss}.");

  // Grain Size Reduction
  params.addParam<Real>("pre_exponential_factor_reduction", 0.032, "Value of pre-exponential factor for reduction rate of grain size (A^*_{red}).");

  // Grain Size Growth
  params.addParam<Real>("Arrhenius_growth", 104.64, "Arrhenius growth (Qg)");
  params.addParam<Real>("growth_exponent", 3.0, "Grain growth constant (p)");
  params.addParam<Real>("pre_exponential_factor_growth", 8.96e-35, "Value of pre-exponential factor for growth rate of grain size (A^*_g).");

  return params;
}

RedbackGrainSizeAux::RedbackGrainSizeAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _has_T(isCoupled("temperature")),
    _T(_has_T ? coupledValue("temperature") : _zero),

    // Damage for stored energy calculation
    _has_D(isCoupled("damage")),
    _damage(coupledValue("damage")),
    _damage_old(coupledValueOld("damage")),


    // From material
    _elastic_strain(getMaterialProperty<RankTwoTensor>("elastic_strain")),

    // From REDBACK
    _youngs_modulus(getMaterialProperty<Real>("youngs_modulus")),
    _poisson_ratio(getMaterialProperty<Real>("poisson_ratio")),



    // For grain size calculation
    _flow_law_dis_uo(getUserObject<RedbackFlowLawDislocation>("flow_law_dislocation")),
    _mises_stress(getMaterialProperty<Real>("mises_stress")),
    _mises_strain_rate(getMaterialProperty<Real>("mises_strain_rate")), // total plastic strain rate
    _strain_rate_dis(getMaterialProperty<Real>("dislocation_strain_rate")), // dislocation strain rate
    _delta_param(getParam<Real>("delta")),
    _ar_growth_param(getParam<Real>("Arrhenius_growth")),
    _growth_exponent_param(getParam<Real>("growth_exponent")),
    _pre_exp_factor_growth(getParam<Real>("pre_exponential_factor_growth")),

    // Provided by User
    _pre_exp_factor_reduction(getParam<Real>("pre_exponential_factor_reduction")),
    _A_star_ss_param(getParam<Real>("pre_exponential_factor_ss"))

{
}

Real
RedbackGrainSizeAux::computeValue()
{
  /* Calculate the stored elastic energy for the time step of interest
   * this is then used in grain size calculation
   */

  // TODO: this section might be irrelivant. Leave but revisit later


  Real bulk_modulus, shear_modulus, vol_elastic_strain, dev_elastic_strain;
  Real Psi0, Psi0_vol, Psi0_dev;
  Real _damage_dissipation, damage_potential, damage_rate;

  bulk_modulus =
  _youngs_modulus[ _qp ] * _poisson_ratio[ _qp ] / (1 + _poisson_ratio[ _qp ]) / (1 - 2 * _poisson_ratio[ _qp ]); // First Lame modulus
  shear_modulus = 0.5 * _youngs_modulus[ _qp ] / (1 + _poisson_ratio[ _qp ]); // Second Lame modulus (shear)

  vol_elastic_strain = _elastic_strain[ _qp ].trace();
  dev_elastic_strain = std::pow(2.0 / 3.0, 0.5) * _elastic_strain[ _qp ].L2norm();

  Psi0_vol = (2 / 3) * bulk_modulus * std::pow(vol_elastic_strain, 2);
  Psi0_dev = (3 / 2) * shear_modulus * std::pow(dev_elastic_strain, 2);
  Psi0 = Psi0_vol + Psi0_dev;

  damage_potential = (1 - _damage[ _qp ]); // fraction of elastic energy left after a time step

  //std::cout << "damage_potential = " << damage_potential << std::endl;

  //damage_rate = (_damage[ _qp ] - _damage_old[ _qp ]) / _dt;

  // _damage_dissipation is equal to (- d Psi / d D * D_dot) which in this code
  // is (damage_potential * damage_rate)
  //_damage_dissipation = damage_potential * damage_rate;


  //std::cout << "damage = " << _damage[ _qp ] << std::endl;




  /* Grain size calculation for the time step of interest */

  Real grain_size = -1.0; //What does this mean?
  if (_has_T)
  {
    Real grain_reduction_rate = 0.;

    if (_strain_rate_dis[_qp] > 0)
    {

      Real beta = _strain_rate_dis[_qp] / _mises_strain_rate[_qp];
      grain_reduction_rate = (((-beta) * (_mises_stress[ _qp ]
        * _mises_strain_rate[ _qp ])) * damage_potential) * std::pow(_u_old[ _qp ],2) * _pre_exp_factor_reduction; // unsure if I need _damage_dissipation or damage_potential

    }

    //std::cout << "beta = " << (-(_mises_stress[ _qp ] * _strain_rate_dis[_qp])) << std::endl;
    //std::cout << "grain_reduction_rate  = " << grain_reduction_rate << std::endl;
    //std::cout << "dd_r_dt  = " << (grain_reduction_rate*_dt) << std::endl;

    Real grain_growth_rate = _pre_exp_factor_growth * 1/_growth_exponent_param * std::pow(_u_old[ _qp ], 1 -_growth_exponent_param)
      * std::exp(_ar_growth_param*_delta_param*_T[_qp]/(1 + _delta_param*_T[_qp]));

    // Debugging
    std::cout << "grain_growth_rate = " << grain_growth_rate << std::endl;

    Real n_dis = _flow_law_dis_uo.getStressExponent();
    Real m_prime = (n_dis + 1)/ (_growth_exponent_param + 1);
    Real ar_dis = _flow_law_dis_uo.getArrhenius();
    Real ar_ss = (_ar_growth_param - ar_dis)/(_growth_exponent_param + 1);
    Real steady_state_grain_size = _A_star_ss_param * (1/damage_potential)
      * std::pow(_mises_stress[ _qp ], -m_prime)* std::exp(ar_ss*_delta_param*_T[_qp]/(1 + _delta_param*_T[_qp]));

    //std::cout << "_u_old[0] = " << _u_old[ 0 ] << std::endl;
    //std::cout << "_u_old[ _qp ] = " << _u_old[ _qp ] << std::endl;
    //std::cout << "(_u_old[ _qp ] + (grain_reduction_rate*_dt)) = " << (_u_old[ _qp ] + (grain_reduction_rate*_dt)) << std::endl;
    //std::cout << "steady_state_grain_size = " << steady_state_grain_size << std::endl;

    if (_u_old[ _qp ] < steady_state_grain_size)
      grain_size = fmin(_u_old[ _qp ] + (grain_growth_rate*_dt), steady_state_grain_size);
    else if (_u_old[ _qp ] > steady_state_grain_size)
      grain_size = fmax(steady_state_grain_size, (_u_old[ _qp ] + (grain_reduction_rate*_dt))); // this is the problem line
    else
      grain_size = steady_state_grain_size;

  }

  //std::cout << "grain_size = " << grain_size << std::endl;

  return grain_size;


}
