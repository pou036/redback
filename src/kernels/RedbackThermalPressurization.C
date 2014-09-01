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

#include "RedbackThermalPressurization.h"

template<>
InputParameters validParams<RedbackThermalPressurization>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("temperature", "Temperature variable."); // TODO: check "required" fields across redback
  return params;
}

RedbackThermalPressurization::RedbackThermalPressurization(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _temp_dot(coupledDot("temperature")),
  _dtemp_dot_dtemp(coupledDotDu("temperature")),
  _pressurization_coefficient(getMaterialProperty<Real>("pressurization_coefficient"))
{
}

RedbackThermalPressurization::~RedbackThermalPressurization()
{
}

Real
RedbackThermalPressurization::computeQpResidual()
{
  return - _pressurization_coefficient[_qp] * _temp_dot[_qp] * _test[_i][_qp];
}

Real
RedbackThermalPressurization::computeQpJacobian()
{
  return - _pressurization_coefficient[_qp] * _dtemp_dot_dtemp[_qp] * _phi[_j][_qp] * _test[_i][_qp];
}
