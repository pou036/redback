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
// BC for the term <-\kappa\nabla v.n,\{\tilde{u}\}>
#include "DPGmyBC22T.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC22T);

template <>
InputParameters
validParams<DPGmyBC22T>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<-\\kappa\\nabla v.n,\\{\\tilde{u}\\}>$");
  return params;
}

DPGmyBC22T::DPGmyBC22T(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _k_var(coupled("coupled_variable")),
    _grad_coupled_variable(coupledGradient("coupled_variable")),
    _grad_phi_cvariable(_assembly.gradPhi(*getVar("coupled_variable",0))),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC22T::computeQpResidual()
{
  return -_kappa[_qp] * _grad_coupled_variable[_qp] * _normals[_qp] * _test[_i][_qp];
}

Real
DPGmyBC22T::computeQpJacobian()
{
  return 0;
}

Real
DPGmyBC22T::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return -_kappa[_qp] * _grad_phi_cvariable[_j][_qp] * _normals[_qp] * _test[_i][_qp];
  }
  return 0;
}

