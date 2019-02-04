//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplacianRate.h"
#include "Function.h"

registerMooseObject("RedbackApp", LaplacianRate);

template <>
InputParameters
validParams<LaplacianRate>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("The Laplacian of the rate of the variable");
  // params.addParam<Real>("mu_name","The parameter multiplying the Laplacian rate");
  params.addParam<FunctionName>("mu_function", "1", "A function that describes the coefficient mu");
  return params;
}

LaplacianRate::LaplacianRate(const InputParameters & parameters) : Kernel(parameters),
  _mu_function(getFunction("mu_function")),
 // _mu(getParam<Real>("mu_name")),
  _grad_u_dot(_var.gradSlnDot())
{
}

Real
LaplacianRate::computeQpResidual()
{
  return _mu_function.value(_t, _q_point[_qp]) * _grad_u_dot[_qp] * _grad_test[_i][_qp];
}
Real
LaplacianRate::computeQpJacobian()
{
  return 0;
}
//return _grad_phi[_j][_qp] * _grad_test[_i][_qp];
