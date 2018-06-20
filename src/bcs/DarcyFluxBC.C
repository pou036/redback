//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "DarcyFluxBC.h"

template <>
InputParameters
validParams<DarcyFluxBC>()
{
  InputParameters params = validParams<FluxBC>();
  params.addClassDescription(
      "Computes a boundary residual contribution consistent with the Diffusion Kernel. "
      "Does not impose a boundary condition; instead computes the boundary "
      "contribution corresponding to the current value of grad(u) and accumulates "
      "it in the residual vector.");
  return params;
}

DarcyFluxBC::DarcyFluxBC(const InputParameters & parameters)
  : FluxBC(parameters), _Le(getMaterialProperty<Real>("lewis_number"))
{
}

RealGradient
DarcyFluxBC::computeQpFluxResidual()
{
  return _Le[_qp] * _grad_u[_qp];
}

RealGradient
DarcyFluxBC::computeQpFluxJacobian()
{
  return _Le[_qp] * _grad_phi[_j][_qp];
}
