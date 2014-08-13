/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackMaterial.h"

template<>
InputParameters validParams<RedbackMaterial>()
{
  InputParameters params = validParams<Material>();

  //params.addParam<Real>("phi0", 0, "initial porosity value.");
  params.addRangeCheckedParam<Real>("phi0","phi0>0 & phi0<1", "initial porosity value.");
  params.addRangeCheckedParam<Real>("gr", "gr>=0", "Gruntfest number.");
  params.addParam<Real>("ref_lewis_nb", "Reference Lewis number.");
  params.addParam<Real>("ar", "Arrhenius number.");
  params.addParam<Real>("delta", 1, "Kamenetskii coefficient.");
  params.addParam<Real>("m", "Exponent for rate dependent plasticity (Perzyna)");
  params.addRequiredParam<bool>("is_mechanics_on", "is mechanics on?");
  params.addCoupledVar("temperature", "Dimensionless temperature");
  params.addCoupledVar("pore_pres", "Dimensionless pore pressure");
  params.addParam<MooseEnum>("density_method", RedbackMaterial::densityMethodEnum() = "linear", "The method to describe density evolution with temperature and pore pressure");
  params.addParam<MooseEnum>("permeability_method", RedbackMaterial::permeabilityMethodEnum() = "KozenyCarman", "The method to describe permeability evolution");

  params.addParam<Real>("ar_F", "Arrhenius number for the forward reaction.");
  params.addParam<Real>("ar_R", "Arrhenius number for the reverse reaction.");
  params.addParam<Real>("da_endo", 0, "Damkoehler number for the endothermic reaction.");
  params.addParam<Real>("da_exo", 0, "Damkoehler number for the exothermic reaction.");
  params.addParam<Real>("mu", 0, "Chemical pressurization coefficient.");
  params.addParam<Real>("Kc", 0, "Equilibtium constant.");
  params.addParam<Real>("eta1", 1, "ratio of concentrations (see documentation).");
  params.addParam<Real>("eta2", 1, "ratio of concentrations (see documentation).");
  params.addRangeCheckedParam<Real>("Aphi","Aphi>=0 & Aphi<=1", "percentage of volume change from chemistry contributing to porosity (see documentation)");

  return params;
}

RedbackMaterial::RedbackMaterial(const std::string & name, InputParameters parameters) :
  Material(name, parameters),
  _has_T(isCoupled("temperature")),
  _T(_has_T ? coupledValue("temperature") : _zero), // TODO: should be NULL (but doesn't compile)
  _has_pore_pres(isCoupled("pore_pres")),
  _pore_pres(_has_pore_pres ? coupledValue("pore_pres") : _zero), // TODO: should be NULL (but doesn't compile)

  _phi0_param(getParam<Real>("phi0")),
  _gr_param(getParam<Real>("gr")),
  _ref_lewis_nb_param(getParam<Real>("ref_lewis_nb")),
  _ar_param(getParam<Real>("ar")),
  _delta_param(getParam<Real>("delta")),
  _m_param(getParam<Real>("m")),
  _ar_F_param(getParam<Real>("ar_F")),
  _ar_R_param(getParam<Real>("ar_R")),
  _da_endo_param(getParam<Real>("da_endo")),
  _da_exo_param(getParam<Real>("da_exo")),
  _mu_param(getParam<Real>("mu")),
  _Kc_param(getParam<Real>("Kc")),
  _eta1_param(getParam<Real>("eta1")),
  _eta2_param(getParam<Real>("eta2")),
  _Aphi_param(getParam<Real>("Aphi")),

  _is_mechanics_on(getParam<bool>("is_mechanics_on")),

  _useless_property_old(declarePropertyOld<Real>("gr")), //TODO: find better way to initiate the values.

  _gr(declareProperty<Real>("gr")),
  _ref_lewis_nb(declareProperty<Real>("ref_lewis_nb")),
  _ar(declareProperty<Real>("ar")),
  _delta(declareProperty<Real>("delta")),
  _m(declareProperty<Real>("m")),

  _porosity(declareProperty<Real>("porosity")),
  _lewis_number(declareProperty<Real>("lewis_number")),

  _mod_gruntfest_number(declareProperty<Real>("mod_gruntfest_number")),
  _mechanical_dissipation(declareProperty<Real>("mechanical_dissipation")),
  _mechanical_dissipation_jac(declareProperty<Real>("mechanical_dissipation_jacobian")),

  _ar_F(declareProperty<Real>("ar_F")),
  _ar_R(declareProperty<Real>("ar_R")),
  _mu(declareProperty<Real>("mu")),

  _chemical_porosity(declareProperty<Real>("chemical_porosity")),
  _solid_ratio(declareProperty<Real>("solid_ratio")),
  _chemical_endothermic_energy(declareProperty<Real>("chemical_endothermic_energy")),
  _chemical_endothermic_energy_jac(declareProperty<Real>("chemical_endothermic_energy_jacobian")),
  _chemical_exothermic_energy(declareProperty<Real>("chemical_exothermic_energy")),
  _chemical_exothermic_energy_jac(declareProperty<Real>("chemical_exothermic_energy_jacobian")),
  _chemical_source_mass(declareProperty<Real>("chemical_source_mass")),
  _chemical_source_mass_jac(declareProperty<Real>("chemical_source_mass_jacobian")),

  _density_method((DensityMethod)(int)getParam<MooseEnum>("density_method")),
  _permeability_method((PermeabilityMethod)(int)getParam<MooseEnum>("permeability_method")),

  _mises_strain(declareProperty<Real>("mises_strain")),
  _mises_strain_rate(declareProperty<Real>("mises_strain_rate"))

{
}

//=================================================================

MooseEnum
RedbackMaterial::densityMethodEnum()
{
  return MooseEnum("linear");
}

MooseEnum
RedbackMaterial::permeabilityMethodEnum()
{
  return MooseEnum("KozenyCarman");
}

void
RedbackMaterial::initQpStatefulProperties()
{

  // Initialise our made up variables...
  _useless_property_old[_qp] = 0; // TODO: find a better way
  _gr[_qp] = _gr_param;
  _ref_lewis_nb[_qp] = _ref_lewis_nb_param;
  _ar[_qp] = _ar_param;
  _delta[_qp] = _delta_param;
  _m[_qp] = _m_param;
  _exponent = _m[_qp];
  _lewis_number[_qp] = _ref_lewis_nb[_qp];
  _porosity[_qp] = _phi0_param;
  _chemical_porosity[_qp]= 0;
   _solid_ratio[_qp] = 0;
  _ar_F[_qp] = _ar_F_param;
  _ar_R[_qp] = _ar_R_param;
  _mu[_qp] = _mu_param;
  _mises_strain[_qp] = 0;
}

void
RedbackMaterial::computeQpProperties()
{
  Material::computeQpProperties();
  //Compute the terms used in Redback Kernels
  computeRedbackTerms();
}

void
RedbackMaterial::computeRedbackTerms()
{
  Real omega_rel, temporary, phi_prime, s_prime;

  //TODO: put flags for all properties depending on activated variables.

  //TODO: do not compute these when mechanics is on (5 fields overwritten)
  _exponential = std::exp(-_ar[_qp])* std::exp(_ar[_qp]*_delta[_qp] *_T[_qp]/(1 + _delta[_qp] *_T[_qp]));
  // Compute modified Gruntfest number
  _mod_gruntfest_number[_qp]=_gr[_qp];
  // Compute Mises strain
  _mises_strain[_qp] = _exponential * _dt;
  // Compute Mises strain rate
  _mises_strain_rate[_qp] = _exponential;

  // Compute Mechanical Dissipation
  _mechanical_dissipation[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) *
      std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) );

  // Compute Mechanical Dissipation Jacobian
  _mechanical_dissipation_jac[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) *
    _ar[_qp]*_delta[_qp] * std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) ) /
    (1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);

  /*
  * The following calculates the volume ratios of a generic reversible reaction of the form:
  * AB_(solid) <-> A_(solid)  + B_(fluid)
  * The chemical porosity is the volume ration of B over the total volume V=V_A + V_B + V_AB
  * and the solid ratio is the volume of product A over the solid volume V_A+V_AB
  */

  // Step 1: calculate the relative rate of reactions
  omega_rel = _eta2_param * _Kc_param * std::exp( (_ar_F[_qp]-_ar_R[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

  // Step 2: calculate the solid ratio
  _solid_ratio[_qp] = omega_rel/(1 + omega_rel);

  // Step 3: calculate the chemical porosity and update the total porosity
  _chemical_porosity[_qp] = _Aphi_param*(1 - _phi0_param)/(1+_eta1_param/_solid_ratio[_qp]);
  _porosity[_qp] =  _phi0_param + _chemical_porosity[_qp];

  // Step 4: calculate the partial derivatives for the jacobian
  temporary = _eta2_param * _Kc_param * (_ar_F[_qp] - _ar_R[_qp]) *_delta[_qp] *
      std::exp( (_ar_F[_qp]-_ar_R[_qp]) / (1 + _delta[_qp]*_T[_qp]) ) / std::pow(1+_delta[_qp]*_T[_qp], 2) ;

  phi_prime = - temporary*_Aphi_param*_eta1_param*(1-_phi0_param) /
      std::pow(_eta1_param * std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) +
          (1 + _eta1_param)*
      std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

  s_prime = - temporary/std::pow(
       std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) +
       std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

  // Compute Endothermic Chemical Energy
  _chemical_endothermic_energy[_qp] = _da_endo_param * (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp]) *
      std::exp( (_ar_F[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

  //std::cout<<"chemical endothermic="<<_chemical_endothermic_energy[_qp] <<std::endl;

  // Compute Endothermic Chemical Energy Jacobian
  _chemical_endothermic_energy_jac[_qp] = _da_endo_param * std::exp( (_ar_F[_qp]) / (1 + _delta[_qp]*_T[_qp]) ) *
      (
       _ar_F[_qp] * _delta[_qp] * (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp])
          / std::pow(1+_delta[_qp]*_T[_qp], 2)
      - (1 - _solid_ratio[_qp]) * phi_prime
      - (1 - _porosity[_qp]) * s_prime
      );

  // Compute Exothermic Chemical Energy
  _chemical_exothermic_energy[_qp] = _da_exo_param * (1 - _porosity[_qp]) * _solid_ratio[_qp] * _chemical_porosity[_qp] *
      std::exp( (_ar_R[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

  // Compute Exothermic Chemical Energy Jacobian
  _chemical_exothermic_energy_jac[_qp] = _da_exo_param * std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp]) ) *
      (
        _solid_ratio[_qp]*(
       _ar_R[_qp] * _delta[_qp] * _chemical_porosity[_qp] *(1 - _porosity[_qp])
          / std::pow(1+_delta[_qp]*_T[_qp], 2)
      + (1 - _porosity[_qp] - _chemical_porosity[_qp]) * phi_prime )
      + _chemical_porosity[_qp]*(1 - _porosity[_qp]) * s_prime
      );

  // Compute Chemical Source/Sink Term for the mass (pore pressure) equation
  _chemical_source_mass[_qp] =  _mu[_qp]* (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp]) *std::exp( (_ar_F[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

  // Compute Jacobian of Chemical Source/Sink Term for the mass (pore pressure) equation. The corresponding variable is pore pressure
  _chemical_source_mass_jac[_qp] = 0;

  // Update Lewis number
  _lewis_number[_qp] = _ref_lewis_nb[_qp]*std::pow((1-_porosity[_qp])/(1-_phi0_param), 2) * std::pow(_phi0_param/_porosity[_qp], 3);
  return;
}


/*	// Compute equivalent stress
	_mises_stress[_qp] = getSigEqv(sig);
	// Compute Mises strain
	_mises_strain[_qp] = flow_incr;
	// Compute Mises strain rate
	_mises_strain_rate[_qp] = flow_incr / _dt;

	// Compute Mechanical Dissipation
	_mechanical_dissipation[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) * getSigEqv(sig) / yield_stress *
		std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent) *
		std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) );
	// Compute Mechanical Dissipation Jacobian
	_mechanical_dissipation_jac[_qp] = _gr[_qp] * std::pow(1 - _pore_pres[_qp], _exponent) * getSigEqv(sig) / yield_stress *
		std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent) *
		_ar[_qp]*_delta[_qp] * std::exp( _ar[_qp]*_delta[_qp] *_T[_qp] / (1 + _delta[_qp] *_T[_qp]) ) /
		(1 + _delta[_qp] * _T[_qp]) / (1 + _delta[_qp] * _T[_qp]);
	// Compute the equivalent Gruntfest number for comparison with SuCCoMBE
	_mod_gruntfest_number[_qp] = _gr[_qp] * getSigEqv(sig) / yield_stress * std::pow( macaulayBracket( getSigEqv(sig) / yield_stress - 1.0 ), _exponent);
*/


