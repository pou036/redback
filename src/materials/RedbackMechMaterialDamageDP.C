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

void
RedbackMechMaterialDamageDP::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real cohesion)
{
    RedbackMechMaterialDP::computeRedbackTerms(sig, q_y, cohesion);
    Real lambda_dot;

    Real d_yield_dq, denominator; // The derivative of the yield surface with respect to the deviatoric stress q

    denominator = _slope_yield_surface * _mean_stress[_qp] + cohesion* (1 -_damage[_qp]);
    d_yield_dq = 2 * _mises_stress[_qp] / std::pow(denominator,2);
    lambda_dot = _mises_strain_rate[_qp] / d_yield_dq;

    //Based on the damage approach of Einav (2007) and Tengattini et al (2014)
    Real plastic_damage;
    plastic_damage = _energetic_coeff * (1 - _damage[_qp]) * (1 -_damage[_qp]) * 2 * lambda_dot;

    //Declare properties for the damage kernel
    _damage_kernel[_qp] = plastic_damage;
    _damage_kernel_jac[_qp] = 4 * _energetic_coeff * (1 - _damage[_qp]) * lambda_dot
        + _mises_strain_rate[_qp] * cohesion * (1 -_damage[_qp]) / _mises_stress[_qp];

    /*
    //form the damage mechanics contribution in the energy equation
    RankTwoTensor instantaneous_strain_rate;
    if (_dt == 0)
      {
        instantaneous_strain_rate.zero();
      }
      else
      {
        instantaneous_strain_rate = (_plastic_strain[_qp] - _plastic_strain_old[_qp])/_dt;
      }

    Real TaylorQuinney, Gruntfest;
    Real  bulk_modulus, shear_modulus, prefactor, damage_potential, damage_rate;

    bulk_modulus = _youngs_modulus*_poisson_ratio/(1+_poisson_ratio)/(1-2*_poisson_ratio); // First Lame modulus
    shear_modulus = 0.5*_youngs_modulus/(1+_poisson_ratio); // Second Lame modulus (shear)

    Real dmg_coeff = std::pow(((1-_damage[_qp])/_damage[_qp]),2);
    Real Tcr = -_ar[_qp]/std::log(dmg_coeff*_mises_strain_rate[_qp]/_ref_pe_rate);
    Real vartheta0 = 0.95;
    Real vartheta = vartheta0 * (1 - _T[_qp]/Tcr); //The vartheta coefficient of Einav 2007
    prefactor = vartheta0/std::pow((1-vartheta * _damage[_qp]),2);
    damage_potential = prefactor * (_mises_stress[_qp]*_mises_stress[_qp]/(3*shear_modulus) + _mean_stress[_qp]*_mean_stress[_qp]/bulk_modulus);
    damage_rate = (_damage[_qp] - _damage_old[_qp])/_dt;

    TaylorQuinney = 1 - (damage_potential * damage_rate / sig.doubleContraction(instantaneous_strain_rate));

    Gruntfest = TaylorQuinney* _gr[_qp]* std::exp(_ar[_qp]);

    // Compute Mechanical Dissipation. Note that the term of the pore-pressure denotes chemical degradation of the skeleton
    _mechanical_dissipation_mech[_qp] = Gruntfest*sig.doubleContraction(instantaneous_strain_rate);

    // Compute Mechanical Dissipation Jacobian
    _mechanical_dissipation_jac_mech[_qp] = _mechanical_dissipation_mech[_qp] / (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);
*/

}
