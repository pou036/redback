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
// BC for the term <-\kappa\nabla \tidle{u}.n,u-g}>
#include "DPGmyBC24.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC24);

template <>
InputParameters
validParams<DPGmyBC24>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredParam<FunctionName>("function", "Function to impose Dirichlet boundary condition.");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<-\\kappa\\nabla\\tilde{u}.n,u-g>$");
  return params;
}

DPGmyBC24::DPGmyBC24(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _func(getFunction("function")),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC24::computeQpResidual()
{
  Real g = _func.value(_t, _q_point[_qp]);
  return -_kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp] * (_u[_qp] - g);
}

Real
DPGmyBC24::computeQpJacobian()
{
  return -_kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp] * _phi[_j][_qp];
}


