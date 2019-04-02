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
// BC for the term 0.5*<abs(b.n)*u, \tilde{u}>
#include "DPGmyBC20.h"

registerMooseObject("MooseApp", DPGmyBC20);

template <>
InputParameters
validParams<DPGmyBC20>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$0.5*<|b.n|u,\\tilde{u}>=h$");
  return params;
}

DPGmyBC20::DPGmyBC20(const InputParameters & parameters)
  : IntegratedBC(parameters),
    _is_vel_y_coupled(isCoupled("velocity_y")),
    _is_vel_z_coupled(isCoupled("velocity_z")),
    _vel_x(coupledValue("velocity_x")),
    _vel_y(coupledValue("velocity_y")),
    _vel_z(coupledValue("velocity_z"))
{
}

Real
DPGmyBC20::computeQpResidual()
{
  Real vdotn = _vel_x[_qp] * _normals[_qp](0);
  if (_is_vel_y_coupled)
  {
    vdotn += _vel_y[_qp] * _normals[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    vdotn += _vel_z[_qp] * _normals[_qp](2);
  }
  return 0.5 * fabs(vdotn) * _test[_i][_qp] * _u[_qp];
}

Real
DPGmyBC20::computeQpJacobian()
{
  Real vdotn = _vel_x[_qp] * _normals[_qp](0);
  if (_is_vel_y_coupled)
  {
    vdotn += _vel_y[_qp] * _normals[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    vdotn += _vel_z[_qp] * _normals[_qp](2);
  }
  return 0.5 * fabs(vdotn) * _test[_i][_qp] * _phi[_j][_qp];
}

