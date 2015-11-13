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


template<>
InputParameters validParams<RedbackFluidDivergence>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}


RedbackFluidDivergence::RedbackFluidDivergence(const InputParameters & parameters) :
  Kernel(parameters),
  _div_fluid_kernel(getMaterialProperty<Real>("divergence_fluid_velocity_kernel")),
  _time_factor(getParam<Real>("time_factor"))
{

}

RedbackFluidDivergence::~RedbackFluidDivergence()
{

}

Real
RedbackFluidDivergence::computeQpResidual()
{
  return _time_factor*_test[_i][_qp]*_div_fluid_kernel[_qp];
}

Real
RedbackFluidDivergence::computeQpJacobian()
{
  return 0;
}
