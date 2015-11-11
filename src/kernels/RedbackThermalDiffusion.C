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

#include "RedbackThermalDiffusion.h"


template<>
InputParameters validParams<RedbackThermalDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");

  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

RedbackThermalDiffusion::RedbackThermalDiffusion(const InputParameters & parameters) :
  Kernel(parameters),
  _time_factor(getParam<Real>("time_factor"))
{
}

RedbackThermalDiffusion::~RedbackThermalDiffusion()
{
}

Real
RedbackThermalDiffusion::computeQpResidual()
{
  return _time_factor * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
RedbackThermalDiffusion::computeQpJacobian()
{
  return _time_factor*_grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
