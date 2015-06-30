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

#include "RedbackMechDissip.h"


template<>
InputParameters validParams<RedbackMechDissip>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}


RedbackMechDissip::RedbackMechDissip(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation")),
  _mechanical_dissipation_jac(getMaterialProperty<Real>("mechanical_dissipation_jacobian")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackMechDissip::~RedbackMechDissip()
{

}

Real
RedbackMechDissip::computeQpResidual()
{
  return -_time_factor*_test[_i][_qp]*_mechanical_dissipation[_qp];
}

Real
RedbackMechDissip::computeQpJacobian()
{
  return -_time_factor*_test[_i][_qp] *_mechanical_dissipation_jac[_qp] * _phi[_j][_qp];
}
