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

  return params;
}


RedbackChemExo::RedbackChemExo(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _chemical_exothermic_energy(getMaterialProperty<Real>("chemical_exothermic_energy")),
  _chemical_exothermic_energy_jac(getMaterialProperty<Real>("chemical_exothermic_energy_jacobian"))
{

}

RedbackChemExo::~RedbackChemExo()
{

}

Real
RedbackChemExo::computeQpResidual()
{
  return _test[_i][_qp]*_chemical_exothermic_energy[_qp];
}

Real
RedbackChemExo::computeQpJacobian()
{
  return _test[_i][_qp] * _chemical_exothermic_energy_jac[_qp] * _phi[_j][_qp];
}
