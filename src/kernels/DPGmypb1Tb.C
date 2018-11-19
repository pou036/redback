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
// Kernel for the term (\tau_k,\tilde{\sigma}_k)

#include "DPGmypb1Tb.h"

registerMooseObject("RedbackApp", DPGmypb1Tb);

template <>
InputParameters
validParams<DPGmypb1Tb>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled variable");
  return params;
}

DPGmypb1Tb::DPGmypb1Tb(const InputParameters & parameters):
  Kernel(parameters),
  _coupled_var(coupledValue("coupled_variable")),
  _k_var(coupled("coupled_variable")),
  _phi_k(_assembly.phi(*getVar("coupled_variable",0)))
{
}

Real
DPGmypb1Tb::computeQpResidual()
{
  return _coupled_var[_qp] * _test[_i][_qp];
}

Real
DPGmypb1Tb::computeQpJacobian()
{
  return 0;
}

Real
DPGmypb1Tb::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return _phi_k[_j][_qp] * _test[_i][_qp];
  }
  return 0;
}
