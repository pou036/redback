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
  params.addRequiredParam<unsigned int>("component", "An integer corresponding to the direction the variable this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addRequiredCoupledVar("fluid_vel_x", "The x component of fluid velocity");
  params.addRequiredCoupledVar("fluid_vel_y", "The y component of fluid velocity");
  params.addCoupledVar("fluid_vel_z", 0.0, "The z component of fluid velocity");
  params.set<bool>("use_displaced_mesh") = true;
  return params;
}


RedbackNavier::RedbackNavier(const InputParameters & parameters) :
  Kernel(parameters),
  _component(getParam<unsigned int>("component")),
  _div_fluid_vel(getMaterialProperty<Real>("divergence_of_fluid_velocity")),
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
  Real vel_component;
  switch (_component)
  {
  case 0: vel_component = _fluid_vel_x[_qp];
      break;
  case 1: vel_component = _fluid_vel_y[_qp];
      break;
  case 2: vel_component = _fluid_vel_z[_qp];
      break;
  default: mooseError("Wrong RedbackNavier dimension component used (needs to be 0, 1, or 2)");
      break;
  }
  return _time_factor*_test[_i][_qp]*_div_fluid_vel[_qp]*vel_component;
}

Real
RedbackNavier::computeQpJacobian()
{
  return 0;
}
