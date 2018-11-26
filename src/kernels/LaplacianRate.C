//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplacianRate.h"

registerMooseObject("RedbackApp", LaplacianRate);

template <>
InputParameters
validParams<LaplacianRate>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("The Laplacian of the rate of the order parameter");
  params.addParam<MaterialPropertyName>("epsilon_name","The parameter multiplying the Laplacian rate");
  //params.addRequiredParam<Real>("epsilon_name","The parameter multiplying the Laplacian rate");
    params.set<Real>("value") = 0.0;
  return params;
}

LaplacianRate::LaplacianRate(const InputParameters & parameters) : Kernel(parameters),
  _epsilon(getMaterialProperty<Real>("epsilon_name")),
  _grad_u_dot(_var.gradSlnDot())
  //_epsilon(getParam<Real>("epsilon"))
{
}

Real
LaplacianRate::computeQpResidual()
{
  return _epsilon[_qp] * _grad_u_dot[_qp] * _grad_test[_i][_qp];
}
Real
LaplacianRate::computeQpJacobian()
{
  return 0;
}
//return _grad_phi[_j][_qp] * _grad_test[_i][_qp];
