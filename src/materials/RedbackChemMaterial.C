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

  params.addRequiredParam<Real>("ar_c", "Chemical Arrhenius number.");
  params.addRequiredParam<Real>("da", "Damkoehler number.");
  params.addRequiredParam<Real>("mu", "Chemical pressurization coefficient.");


  return params;
}

RedbackChemMaterial::RedbackChemMaterial(const std::string & name, InputParameters parameters) :
    RedbackMaterial(name, parameters),

    _ar_c_param(getParam<Real>("ar_c")),
    _da_param(getParam<Real>("da")),
    _mu_param(getParam<Real>("mu")),

    _ar_c(declareProperty<Real>("ar_c")),
    _da(declareProperty<Real>("da")),
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
    _ar_c[_qp] = _ar_c_param;
	_da[_qp] = _da_param;
	_mu[_qp] = _mu_param;
	RedbackMaterial::computeQpStress();
}

void
RedbackChemMaterial::computeEnergyTerms(RankTwoTensor & sig, Real yield_stress, Real flow_incr)
{
	RedbackMaterial::computeEnergyTerms(sig, yield_stress, flow_incr);

	// TODO: add porosity and solid ratio variation with _T formulas


	// Compute Endothermic Chemical Energy
	_chemical_endothermic_energy[_qp] = _da[_qp]*std::exp( (_ar_c[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );
	// CCompute Endothermic Chemical Energy Jacobian
	_chemical_endothermic_energy_jac[_qp] = _da[_qp] * ( _delta[_qp]*_ar_c[_qp] / ( (1+_delta[_qp]*_T[_qp] ) * (1+_delta[_qp]*_T[_qp] ) ) ) *
		    std::exp( (_ar_c[_qp]*_delta[_qp]*_T[_qp]) / (1 + _delta[_qp]*_T[_qp]) );
	// Compute Exothermic Chemical Energy
	_chemical_exothermic_energy[_qp] = 7;
	// Compute Exothermic Chemical Energy Jacobian
	_chemical_exothermic_energy_jac[_qp] = 7;
}
