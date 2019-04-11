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
// BC for the term -<\nabla(v-g)*n,\tilde{u}>
#include "DPGmyBC30.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC30);

template <>
InputParameters
validParams<DPGmyBC30>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredParam<FunctionName>("function", "ParsedGradFunction to impose Dirichlet boundary condition.");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<\\nabla(v-g)*n,\\tilde{u}>$");
  return params;
}

DPGmyBC30::DPGmyBC30(const InputParameters & parameters)
  : IntegratedBC(parameters),
  _k_var(coupled("coupled_variable")),
  _grad_coupled_variable(coupledGradient("coupled_variable")),
  _func(getFunction("function")),
  _grad_phi_cvariable(_assembly.gradPhi(*getVar("coupled_variable",0)))
{
}

Real
DPGmyBC30::computeQpResidual()
{
  RealGradient grad_g = _func.gradient(_t, _q_point[_qp]);
  return -_test[_i][_qp] * (_grad_coupled_variable[_qp] - grad_g) * _normals[_qp];
}

Real
DPGmyBC30::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return -_test[_i][_qp] * _grad_phi_cvariable[_j][_qp] * _normals[_qp];
  }
  return 0;
}

