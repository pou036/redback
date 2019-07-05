/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                   (c) 2019 CSIRO                             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Kernel for the term
// -(\Delta u, \tilde{u})

#include "DPGlaplacian.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPGlaplacian);

template <>
InputParameters
validParams<DPGlaplacian>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

DPGlaplacian::DPGlaplacian(const InputParameters & parameters):
  Kernel(parameters),
  _second_u(second()),
  _second_phi(secondPhi())
{
}

Real
DPGlaplacian::computeQpResidual()
{
  return -_test[_i][_qp]*_second_u[_qp].tr();
}

Real
DPGlaplacian::computeQpJacobian()
{
  return -_test[_i][_qp]*_second_phi[_j][_qp].tr();
}

