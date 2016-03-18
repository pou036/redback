/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackNavier.h"


template<>
InputParameters validParams<RedbackNavier>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.addRequiredCoupledVar("fluid_vel_x", "The x component of fluid velocity");
  params.addRequiredCoupledVar("fluid_vel_y", "The y component of fluid velocity");
  params.addCoupledVar("fluid_vel_z", 0.0, "The z component of fluid velocity");
  params.set<bool>("use_displaced_mesh") = true;
  return params;
}


RedbackNavier::RedbackNavier(const InputParameters & parameters) :
  Kernel(parameters),
  _fluid_vel_x(coupledValue("fluid_vel_x")),
  _fluid_vel_y(coupledValue("fluid_vel_y")),
  _fluid_vel_z(coupledValue("fluid_vel_z")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackNavier::~RedbackNavier()
{

}

Real
RedbackNavier::computeQpResidual()
{
  return _time_factor*_test[_i][_qp]*_grad_u[_qp]
         *RealVectorValue(_fluid_vel_x[_qp], _fluid_vel_y[_qp], _fluid_vel_z[_qp]);


}

Real
RedbackNavier::computeQpJacobian()
{
  return (RealVectorValue(_u_vel[_qp], _v_vel[_qp], _w_vel[_qp]) * _grad_phi[_j][_qp] +
           _phi[_j][_qp]*_grad_u[_qp](_component)) * _test[_i][_qp];
}
