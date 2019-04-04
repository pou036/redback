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
#include "DPGIndicator22.h"

registerMooseObject("MooseApp", DPGIndicator22);

template <>
InputParameters
validParams<DPGIndicator22>()
{
  InputParameters params = validParams<ExternalSideIndicator>();
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  return params;
}

DPGIndicator22::DPGIndicator22(const InputParameters & parameters)
  : ExternalSideIndicator(parameters),
  _is_vel_y_coupled(isCoupled("velocity_y")),
  _is_vel_z_coupled(isCoupled("velocity_z")),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z"))
{
}

Real
DPGIndicator22::computeQpIntegral()
{
  // Check whether on selected boundary or not
  // https://stackoverflow.com/questions/1701067/how-to-check-that-an-element-is-in-a-stdset/54197839
  if (_sideset_ids.find(_boundary_id) == _sideset_ids.end())
    return 0;

  // Now, this is a selected boundary, compute proper term to integrate
  Real vdotn = _vel_x[_qp] * _normals[_qp](0);
  if (_is_vel_y_coupled)
  {
    vdotn += _vel_y[_qp] * _normals[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    vdotn += _vel_z[_qp] * _normals[_qp](2);
  }
  return 0.5 * fabs(vdotn) * _u[_qp] * _u[_qp];
}
