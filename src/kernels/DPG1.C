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
// Kernel for the term (w,\tilde{w})

#include "DPG1.h"

registerMooseObject("RedbackApp", DPG1);

template <>
InputParameters
validParams<DPG1>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

DPG1::DPG1(const InputParameters & parameters):
  Kernel(parameters)
{
}

Real
DPG1::computeQpResidual()
{
  return _test[_i][_qp] * _u[_qp];
}

Real
DPG1::computeQpJacobian()
{
  return _test[_i][_qp] * _phi[_j][_qp];
}

