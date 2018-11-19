/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2018 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Kernel for the term (\nabla w,\tilde{\nabla w})

#include "DPG2.h"

registerMooseObject("RedbackApp", DPG2);

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

