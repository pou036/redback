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
  return params;
}

RedbackMassDiffusion::RedbackMassDiffusion(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _Le(getMaterialProperty<Real>("lewis_number"))
{
}

RedbackMassDiffusion::~RedbackMassDiffusion()
{
}

Real
RedbackMassDiffusion::computeQpResidual()
{
  return ((1/_Le[_qp]) * _grad_u[_qp]) * _grad_test[_i][_qp];
}

Real
RedbackMassDiffusion::computeQpJacobian()
{
  return ((1/_Le[_qp])*_grad_phi[_j][_qp]) * _grad_test[_i][_qp];
}
