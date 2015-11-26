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


/*
 * THIS MATERIAL INTRODUCES DAMAGE IN A DRUCKER PRAGER MATERIAL
 */


#include "RedbackMechMaterialDamageDP.h"

template<>
InputParameters validParams<RedbackMechMaterialDamageDP>()
{
  InputParameters params = validParams<RedbackMechMaterialDP>();
  params.addParam< Real >("energies_fraction", 1.0, "The fraction of energies used in damage flow law (e.g. E_D/E_D0)");

  return params;
}

RedbackMechMaterialDamageDP::RedbackMechMaterialDamageDP(const InputParameters & parameters) :
    RedbackMechMaterialDP(parameters),
    _damage_kernel(declareProperty<Real>("damage_kernel")),
    _damage_kernel_jac(declareProperty<Real>("damage_kernel_jacobian")),
    _energetic_coeff(getParam<Real>("energies_fraction"))
{
}

/*
void
RedbackMechMaterialDamageDP::returnMap(const RankTwoTensor & sig_old, const RankTwoTensor & delta_d, const RankFourTensor & E_ijkl, RankTwoTensor & dp, RankTwoTensor & sig, Real & p_y, Real & q_y)
{
  sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); //Plastic rate of deformation tensor in unrotated configuration
}
*/

void
RedbackMechMaterialDamageDP::getFlowTensor(const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor_dev)
{
}

Real
RedbackMechMaterialDamageDP::getFlowIncrement(Real sig_eqv, Real p, Real q_y, Real p_y, Real yield_stress)
{
  return 0;
}

void
RedbackMechMaterialDamageDP::getJac(const RankTwoTensor & sig, const RankFourTensor & E_ijkl, Real flow_incr_dev,
        Real q, Real p, Real p_y, Real q_y, Real yield_stress, RankFourTensor & dresid_dsig)
{
}

void
RedbackMechMaterialDamageDP::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
}

void
RedbackMechMaterialDamageDP::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real cohesion)
{
    RedbackMechMaterial::computeRedbackTerms(sig, q_y, cohesion);
    Real lambda_dot;

    Real d_yield_dq, denominator; // The derivative of the yield surface with respect to the deviatoric stress q

    denominator = _slope_yield_surface * _mean_stress[_qp] + cohesion* (1 -_damage[_qp]);
    d_yield_dq = 2 * _mises_stress[_qp] / std::pow(denominator,2);
    lambda_dot = _mises_strain_rate[_qp] / d_yield_dq;

    //Based on the damage approach of Einav (2007) and Tengattini et al (2014)
    Real plastic_damage;
    plastic_damage = _energetic_coeff * (1 - _damage[_qp]) * (1 -_damage[_qp]) * 2 * lambda_dot;

    /*
    RankTwoTensor test_tensor;
    test_tensor = (sig - _stress_old[_qp]);

    RankTwoTensor elastic_damage; //The elastic damage can be a tensor if needed
    elastic_damage = test_tensor/_dt;
    */

    //Declare properties for the damage kernel
    _damage_kernel[_qp] = plastic_damage;
    _damage_kernel_jac[_qp] = 4 * _energetic_coeff * (1 - _damage[_qp]) * lambda_dot
        + _mises_strain_rate[_qp] * cohesion * (1 -_damage[_qp]) / _mises_stress[_qp];
}
