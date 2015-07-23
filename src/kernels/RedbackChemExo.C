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

#include "RedbackChemExo.h"


template<>
InputParameters validParams<RedbackChemExo>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}


RedbackChemExo::RedbackChemExo(const InputParameters & parameters) :
  Kernel(parameters),
  _chemical_exothermic_energy(getMaterialProperty<Real>("chemical_exothermic_energy")),
  _chemical_exothermic_energy_jac(getMaterialProperty<Real>("chemical_exothermic_energy_jacobian")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackChemExo::~RedbackChemExo()
{

}

Real
RedbackChemExo::computeQpResidual()
{
  return -_time_factor*_test[_i][_qp]*_chemical_exothermic_energy[_qp];
}

Real
RedbackChemExo::computeQpJacobian()
{
  return -_time_factor * _test[_i][_qp] * _chemical_exothermic_energy_jac[_qp] * _phi[_j][_qp];
}
