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
// Kernel for the term -(w,{\nabla\tilde{\sigma_k})_k)

#include "DPG5.h"

registerMooseObject("RedbackApp", DPG5);

template <>
InputParameters
validParams<DPG5>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled variable");
  params.addRequiredParam<unsigned int>("component",
                                        "An integer corresponding to the direction k"
                                        "the variable this kernel acts in. (0 for x, "
                                        "1 for y, 2 for z)");
  return params;
}

DPG5::DPG5(const InputParameters & parameters):
    Kernel(parameters),
    _component(getParam<unsigned int>("component")),
    _coupled_var(coupledValue("coupled_variable")),
    _k_var(coupled("coupled_variable")),
    _phi_k(_assembly.phi(*getVar("coupled_variable",0)))
{
}

Real
DPG5::computeQpResidual()
{
  return -_grad_test[_i][_qp](_component) * _coupled_var[_qp];
}

Real
DPG5::computeQpJacobian()
{
  return 0;
}

Real
DPG5::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return -_grad_test[_i][_qp](_component) * _phi_k[_j][_qp];
  }
  return 0;
}
