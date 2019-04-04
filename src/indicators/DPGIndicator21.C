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
#include "DPGIndicator21.h"

registerMooseObject("MooseApp", DPGIndicator21);

template <>
InputParameters
validParams<DPGIndicator21>()
{
  InputParameters params = validParams<InternalSideIndicator>();
  params.addRequiredCoupledVar("velocity_x", "X component of velocity AuxVariable");
  params.addCoupledVar("velocity_y", 0.0, "Y component of velocity AuxVariable");
  params.addCoupledVar("velocity_z", 0.0, "Z component of velocity AuxVariable");
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPGIndicator21::DPGIndicator21(const InputParameters & parameters)
  : InternalSideIndicator(parameters),
  _is_vel_y_coupled(isCoupled("velocity_y")),
  _is_vel_z_coupled(isCoupled("velocity_z")),
  _vel_x(coupledValue("velocity_x")),
  _vel_y(coupledValue("velocity_y")),
  _vel_z(coupledValue("velocity_z")),
  _kappa(coupledValue("kappa"))
{
}

Real
DPGIndicator21::computeQpIntegral()
{
  Real jump = _u[_qp] - _u_neighbor[_qp];
  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;
  Real vdotn = _vel_x[_qp] * _normals[_qp](0);
  if (_is_vel_y_coupled)
  {
    vdotn += _vel_y[_qp] * _normals[_qp](1);
  }
  if (_is_vel_z_coupled)
  {
    vdotn += _vel_z[_qp] * _normals[_qp](2);
  }

  return (0.5 * fabs(vdotn) + _kappa[_qp]/h_e) * jump * jump;
}
