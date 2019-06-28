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
// Kernel for the term (\nabla v,\nabla\tilde{u})

#include "DPG7.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPG7);

template <>
InputParameters
validParams<DPG7>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPG7::DPG7(const InputParameters & parameters):
  Kernel(parameters),
  _k_var(coupled("coupled_variable")),
  _grad_coupled_variable(coupledGradient("coupled_variable")),
  _grad_phi_cvariable(_assembly.gradPhi(*getVar("coupled_variable",0)))
{
}

Real
DPG7::computeQpResidual()
{
  return _grad_test[_i][_qp] * _grad_coupled_variable[_qp];
}

Real
DPG7::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return _grad_test[_i][_qp] * _grad_phi_cvariable[_j][_qp];
  }
  return 0;
}
