/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
// Kernel for the term (\kappa\nabla w,\nabla\tilde{w})

#include "DPG6.h"

registerMooseObject("RedbackApp", DPG6);

template <>
InputParameters
validParams<DPG6>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPG6::DPG6(const InputParameters & parameters):
  Kernel(parameters),
  _kappa(coupledValue("kappa"))
{
}

Real
DPG6::computeQpResidual()
{
  return _kappa[_qp] * _grad_test[_i][_qp] * _grad_u[_qp];
}

Real
DPG6::computeQpJacobian()
{
  return _kappa[_qp] * _grad_test[_i][_qp] * _grad_phi[_j][_qp];
}

