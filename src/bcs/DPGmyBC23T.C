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
// BC for the term <(\kappa/h)*v,\tilde{u}>
#include "DPGmyBC23T.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC23T);

template <>
InputParameters
validParams<DPGmyBC23T>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<(\\kappak/h)*v,\\tilde{u}>$");
  return params;
}

DPGmyBC23T::DPGmyBC23T(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _coupled_variable(coupledValue("coupled_variable")),
    _k_var(coupled("coupled_variable")),
    _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0))),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC23T::computeQpResidual()
{
  Real h = _current_elem->hmax();
  return (_kappa[_qp]/h) * _coupled_variable[_qp] * _test[_i][_qp];
}

Real
DPGmyBC23T::computeQpJacobian()
{
  return 0;
}

Real
DPGmyBC23T::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real h = _current_elem->hmax();
    return (_kappa[_qp]/h) * _phi_coupled_variable[_j][_qp] * _test[_i][_qp];
  }
  return 0;
}

