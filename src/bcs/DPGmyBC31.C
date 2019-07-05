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
// BC for the term -<\nabla(u-g)*n,\tilde{u}>
#include "DPGmyBC31.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC31);

template <>
InputParameters
validParams<DPGmyBC31>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredParam<FunctionName>("function", "ParsedGradFunction to impose Dirichlet boundary condition.");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<\\nabla(u-g)*n,\\tilde{u}>$");
  return params;
}

DPGmyBC31::DPGmyBC31(const InputParameters & parameters)
  : IntegratedBC(parameters),
  _func(getFunction("function"))
{
}

Real
DPGmyBC31::computeQpResidual()
{
  RealGradient grad_g = _func.gradient(_t, _q_point[_qp]);
  return -_test[_i][_qp] * (_grad_u[_qp] - grad_g) * _normals[_qp];
}


Real
DPGmyBC31::computeQpJacobian()
{
  return -_test[_i][_qp] * _grad_phi[_j][_qp] * _normals[_qp];
}
