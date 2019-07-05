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
// BC for the term <(k/h)*\tilde{u},u-g>
#include "DPGmyBC25.h"
#include "Assembly.h"
#include "Function.h"

registerMooseObject("MooseApp", DPGmyBC25);

template <>
InputParameters
validParams<DPGmyBC25>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredParam<FunctionName>("function", "Function to impose Dirichlet boundary condition.");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$<(k/h)*\\tilde{u},u-g>$");
  return params;
}

DPGmyBC25::DPGmyBC25(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _func(getFunction("function")),
    _kappa(coupledValue("kappa"))
{
}

Real
DPGmyBC25::computeQpResidual()
{
  Real h = _current_elem->hmax();
  Real g = _func.value(_t, _q_point[_qp]);
  return (_kappa[_qp]/h) * _test[_i][_qp] * (_u[_qp] - g);
}

Real
DPGmyBC25::computeQpJacobian()
{
  Real h = _current_elem->hmax();
  return (_kappa[_qp]/h) * _test[_i][_qp] * _phi[_j][_qp];
}
