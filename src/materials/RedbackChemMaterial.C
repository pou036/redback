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

#include "RedbackChemMaterial.h"

template<>
InputParameters validParams<RedbackChemMaterial>()
{
  InputParameters params = validParams<RedbackMaterial>();

  params.addRequiredParam<Real>("ar_F", "Arrhenius number for the forward reaction.");
  params.addRequiredParam<Real>("ar_R", "Arrhenius number for the reverse reaction.");
  params.addParam<Real>("da_endo", 0, "Damkoehler number for the endothermic reaction.");
  params.addParam<Real>("da_exo", 0, "Damkoehler number for the exothermic reaction.");
  params.addParam<Real>("mu", 0, "Chemical pressurization coefficient.");
  params.addParam<Real>("Kc", 0, "Equilibtium constant.");
  params.addParam<Real>("eta1", 1, "ratio of concentrations (see documentation).");
  params.addParam<Real>("eta2", 1, "ratio of concentrations (see documentation).");
  params.addRequiredRangeCheckedParam<Real>("Aphi","Aphi>=0 & Aphi<=1", "percentage of volume change from chemistry contributing to porosity (see documentation)");

  return params;
}

RedbackChemMaterial::RedbackChemMaterial(const std::string & name, InputParameters parameters) :
    RedbackMaterial(name, parameters),

    _ar_F_param(getParam<Real>("ar_F")),
    _ar_R_param(getParam<Real>("ar_R")),
    _da_endo_param(getParam<Real>("da_endo")),
    _da_exo_param(getParam<Real>("da_exo")),
    _mu_param(getParam<Real>("mu")),
    _Kc_param(getParam<Real>("Kc")),
    _eta1_param(getParam<Real>("eta1")),
    _eta2_param(getParam<Real>("eta2")),
    _Aphi_param(getParam<Real>("Aphi")),


    _ar_F(declareProperty<Real>("ar_F")),
    _ar_R(declareProperty<Real>("ar_R")),
    _mu(declareProperty<Real>("mu")),

    _chemical_porosity(declareProperty<Real>("_chemical_porosity")),
    _solid_ratio(declareProperty<Real>("solid_ratio")),
    _chemical_endothermic_energy(declareProperty<Real>("chemical_endothermic_energy")),
    _chemical_endothermic_energy_jac(declareProperty<Real>("chemical_endothermic_energy_jacobian")),
	_chemical_exothermic_energy(declareProperty<Real>("chemical_exothermic_energy")),
	_chemical_exothermic_energy_jac(declareProperty<Real>("chemical_exothermic_energy_jacobian"))

  {
}

//=================================================================

void
RedbackChemMaterial::initQpStatefulProperties()
{
	_chemical_porosity[_qp]= 0;
	_solid_ratio[_qp] = 0;
	RedbackMaterial::initQpStatefulProperties();
}

void
RedbackChemMaterial::computeQpStress()
{
    _ar_F[_qp] = _ar_F_param;
    _ar_R[_qp] = _ar_R_param;
	_mu[_qp] = _mu_param;
	RedbackMaterial::computeQpStress();
}

void
RedbackChemMaterial::computeEnergyTerms(RankTwoTensor & sig, Real yield_stress, Real flow_incr)
{
	Real omega_rel, temporary, phi_prime, s_prime;

	if (_is_mechanics_on)
	  {
		RedbackMaterial::computeEnergyTerms(sig, yield_stress, flow_incr);
	  }

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

	// Step 3: calculate the chemical porosity
	_chemical_porosity[_qp] = _Aphi_param*(1 + _porosity[_qp])/(1+_eta1_param/_solid_ratio[_qp]);

	// Step 4: calculate the partial derivatives for the jacobian
	temporary = _eta2_param * _Kc_param * (_ar_F[_qp] - _ar_R[_qp]) *_delta[_qp] *std::exp( (_ar_F[_qp]-_ar_R[_qp]) / (1 + _delta[_qp]*_T[_qp]) )
			 / std::pow(1+_delta[_qp]*_T[_qp], 2) ;

	phi_prime = - temporary*_Aphi_param*_eta1_param*(1-_porosity[_qp]) / std::pow(_eta1_param * std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) + (1 + _eta1_param)* std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

	s_prime = - temporary/std::pow(
			 std::exp( _ar_R[_qp] / (1 + _delta[_qp]*_T[_qp])) + std::exp( _ar_F[_qp] / (1 + _delta[_qp]*_T[_qp]) )* _eta2_param * _Kc_param, 2);

	// Compute Endothermic Chemical Energy
	_chemical_endothermic_energy[_qp] = _da_endo_param * (1 - _porosity[_qp]) * (1 - _solid_ratio[_qp]) *
			std::exp( (_ar_F[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );

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

	// Final Step: Update the total porosity
	_porosity[_qp] =  _porosity[_qp] + _chemical_porosity[_qp];

}
