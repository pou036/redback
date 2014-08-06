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

#include "RedbackChemEndo.h"


template<>
InputParameters validParams<RedbackChemEndo>()
{
  InputParameters params = validParams<Kernel>();

  return params;
}


RedbackChemEndo::RedbackChemEndo(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _chemical_endothermic_energy(getMaterialProperty<Real>("chemical_endothermic_energy")),
  _chemical_endothermic_energy_jac(getMaterialProperty<Real>("chemical_endothermic_energy_jacobian"))
{

}

RedbackChemEndo::~RedbackChemEndo()
{

}

Real
RedbackChemEndo::computeQpResidual()
{
  return _test[_i][_qp]*_chemical_endothermic_energy[_qp];
}

Real
RedbackChemEndo::computeQpJacobian()
{
  return _test[_i][_qp] * _chemical_endothermic_energy_jac[_qp] * _phi[_j][_qp];
}
