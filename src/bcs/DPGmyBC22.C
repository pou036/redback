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
// BC for the term <-\kappa\nabla \tidle{u}.n,v-g}>
#include "DPGmyBC22.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC22);

template <>
InputParameters
validParams<DPGmyBC22>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredParam<FunctionName>("function", "Function to impose Dirichlet boundary condition.");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<-\\kappa\\nabla\\tilde{u}.n,v-g>$");
  return params;
}

DPGmyBC22::DPGmyBC22(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _coupled_variable(coupledValue("coupled_variable")),
    _k_var(coupled("coupled_variable")),
    _func(getFunction("function")),
    _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0))),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC22::computeQpResidual()
{
  Real g = _func.value(_t, _q_point[_qp]);
  return -_kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp] * (_coupled_variable[_qp] - g);
}

Real
DPGmyBC22::computeQpJacobian()
{
  return 0;
}

Real
DPGmyBC22::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return -_kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp] * _phi_coupled_variable[_j][_qp];
  }
  return 0;
}

