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

#include "RedbackMassDiffusion.h"


template<>
InputParameters validParams<RedbackMassDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackMassDiffusion::RedbackMassDiffusion(const InputParameters & parameters) :
  Kernel(parameters),
  _Le(getMaterialProperty<Real>("lewis_number")),
  _gravity_term(getMaterialProperty<RealVectorValue>("fluid_gravity_term")),
  _time_factor(getParam<Real>("time_factor"))
{
}

RedbackMassDiffusion::~RedbackMassDiffusion()
{
}

Real
RedbackMassDiffusion::computeQpResidual()
{
  return (_time_factor/_Le[_qp]) * (_grad_u[_qp] - _gravity_term[_qp]) * _grad_test[_i][_qp];
}

Real
RedbackMassDiffusion::computeQpJacobian()
{
  return (_time_factor/_Le[_qp])*_grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
