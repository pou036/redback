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
#include "DPGIndicator20.h"

registerMooseObject("RedbackApp", DPGIndicator20);

template <>
InputParameters
validParams<DPGIndicator20>()
{
  InputParameters params = validParams<ElementIndicator>();
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPGIndicator20::DPGIndicator20(const InputParameters & parameters)
  : ElementIndicator(parameters),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z")),
  _kappa(coupledValue("kappa"))
{
}

void
DPGIndicator20::computeIndicator()
{
  // volume average over element
  Real sum = 0;
  for (_qp = 0; _qp < _qrule->n_points(); _qp++)
  {
    sum += _JxW[_qp] * _coord[_qp] * computeQpIntegral();
  }
  _field_var.setNodalValue(sum);
}

Real
DPGIndicator20::computeQpIntegral()
{
  Real h = _current_elem->hmax();
  RealVectorValue b(_vel_x[_qp], _vel_y[_qp], _vel_z[_qp]);
  return _u[_qp]*_u[_qp]
    + _kappa[_qp]*_grad_u[_qp]*_grad_u[_qp]
    + h * (b * _grad_u[_qp]) * (b * _grad_u[_qp]);
}
