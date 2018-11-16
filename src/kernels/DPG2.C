// Kernel for the term (\nabla w,\tilde{\nabla w})

#include "DPG2.h"

//registerMooseObject("RedbackApp", DPG2);

template <>
InputParameters
validParams<DPG2>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

DPG2::DPG2(const InputParameters & parameters):
  Kernel(parameters)
{
}

Real
DPG2::computeQpResidual()
{
  return _grad_test[_i][_qp] * _grad_u[_qp];
}

Real
DPG2::computeQpJacobian()
{
  return _grad_test[_i][_qp] * _grad_phi[_j][_qp];
}

