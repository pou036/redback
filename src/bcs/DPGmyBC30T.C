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
// BC for the term -<\nabla\tilde{u}.n,v>
#include "DPGmyBC30T.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC30T);

template <>
InputParameters
validParams<DPGmyBC30T>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$-<\\nabla\\tilde{u}.n,v>$");
  return params;
}

DPGmyBC30T::DPGmyBC30T(const InputParameters & parameters)
  : IntegratedBC(parameters),
  _coupled_variable(coupledValue("coupled_variable")),
  _k_var(coupled("coupled_variable")),
  _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0)))
{
}

Real
DPGmyBC30T::computeQpResidual()
{
  return -_coupled_variable[_qp] * (_grad_test[_i][_qp] * _normals[_qp]);
}

Real
DPGmyBC30T::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return -_phi_coupled_variable[_j][_qp] * (_grad_test[_i][_qp] * _normals[_qp]);
  }
  return 0;
}

