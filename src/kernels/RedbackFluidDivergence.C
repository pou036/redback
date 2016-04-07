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

#include "RedbackFluidDivergence.h"

template <>
InputParameters
validParams<RedbackFluidDivergence>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.addRequiredCoupledVar("fluid_vel_x", "x-velocity");
  params.addRequiredCoupledVar("fluid_vel_y", "y-velocity");
  params.addCoupledVar("fluid_vel_z", 0, "z-velocity");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackFluidDivergence::RedbackFluidDivergence(const InputParameters & parameters) :
    Kernel(parameters),
    _div_fluid_kernel(getMaterialProperty<Real>("divergence_fluid_velocity_kernel")),
    _time_factor(getParam<Real>("time_factor")),

    // Variable numberings
    _x_vel_var_number(coupled("fluid_vel_x")),
    _y_vel_var_number(coupled("fluid_vel_y")),
    _z_vel_var_number(coupled("fluid_vel_z"))
{
}

RedbackFluidDivergence::~RedbackFluidDivergence()
{
}

Real
RedbackFluidDivergence::computeQpResidual()
{
  return _time_factor * _test[ _i ][ _qp ] * _div_fluid_kernel[ _qp ];
}

Real
RedbackFluidDivergence::computeQpJacobian()
{
  // Derivative with regards to p is zero
  return 0;
}

Real
RedbackFluidDivergence::computeQpOffDiagJacobian(unsigned jvar)
{
  if (jvar == _x_vel_var_number)
    return _grad_phi[ _j ][ _qp ](0) * _test[ _i ][ _qp ];

  else if (jvar == _y_vel_var_number)
    return _grad_phi[ _j ][ _qp ](1) * _test[ _i ][ _qp ];

  else if (jvar == _z_vel_var_number)
    return _grad_phi[ _j ][ _qp ](2) * _test[ _i ][ _qp ];
  else
    return 0;
}
