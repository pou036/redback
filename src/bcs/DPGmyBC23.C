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
// BC for the term <(k/h)*\tilde{u},v-g>
#include "DPGmyBC23.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC23);

template <>
InputParameters
validParams<DPGmyBC23>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  params.addRequiredParam<FunctionName>("function", "Function to impose Dirichlet boundary condition.");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<(k/h)*\\tilde{u},v-g>$");
  return params;
}

DPGmyBC23::DPGmyBC23(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _coupled_variable(coupledValue("coupled_variable")),
    _k_var(coupled("coupled_variable")),
    _func(getFunction("function")),
    _phi_coupled_variable(_assembly.phi(*getVar("coupled_variable",0))),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC23::computeQpResidual()
{
  Real h = _current_elem->hmax();
  Real g = _func.value(_t, _q_point[_qp]);
  return (_kappa[_qp]/h) * _test[_i][_qp] * (_coupled_variable[_qp] - g);
}

Real
DPGmyBC23::computeQpJacobian()
{
  return 0;
}

Real
DPGmyBC23::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real h = _current_elem->hmax();
    return (_kappa[_qp]/h) * _test[_i][_qp] * _phi_coupled_variable[_j][_qp];
  }
  return 0;
}

