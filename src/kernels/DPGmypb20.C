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
// Kernel for the term (h b.\nabla u, b.\nabla\tilde{u})

#include "DPGmypb20.h"

registerMooseObject("RedbackApp", DPGmypb20);

template <>
InputParameters
validParams<DPGmypb20>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  return params;
}

DPGmypb20::DPGmypb20(const InputParameters & parameters):
  Kernel(parameters),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z"))
{
}

Real
DPGmypb20::computeQpResidual()
{
  RealVectorValue b(_vel_x[_qp], _vel_y[_qp], _vel_z[_qp]);
  Real h = _current_elem->hmax();
  return h * (b * _grad_u[_qp]) * (b * _grad_test[_i][_qp]);
}

Real
DPGmypb20::computeQpJacobian()
{
  RealVectorValue b(_vel_x[_qp], _vel_y[_qp], _vel_z[_qp]);
  Real h = _current_elem->hmax();
  return h * (b * _grad_phi[_j][_qp]) * (b * _grad_test[_i][_qp]);
}

