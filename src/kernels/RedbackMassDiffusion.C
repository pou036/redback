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
  params.addRequiredParam<RealTensorValue>("Lewis_number", "The Tensor form of Lewis number to multiply the Diffusion operator by");
//  params.addRequiredCoupledVar("temperature", "Temperature variable.");
  return params;
}

RedbackMassDiffusion::RedbackMassDiffusion(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters),
//    _T(coupledValue("temperature")),
    _Le(getParam<RealTensorValue>("Lewis_number"))
 //   _volumetric_strain_rate(getMaterialProperty<Real>("volumetric_strain_rate"))
{
}

RedbackMassDiffusion::~RedbackMassDiffusion()
{
}

Real
RedbackMassDiffusion::computeQpResidual()
{
  return (_Le * _grad_u[_qp]) * _grad_test[_i][_qp];// + _test[_i][_qp]* _volumetric_strain_rate[_qp];// + _test[_i][_qp]*_T_dot[_qp];
}

Real
RedbackMassDiffusion::computeQpJacobian()
{
  return (_Le * _grad_phi[_j][_qp]) * _grad_test[_i][_qp];// + _test[_i][_qp] * 0 * _phi[_j][_qp];
}
