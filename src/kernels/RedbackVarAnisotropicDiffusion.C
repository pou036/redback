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

#include "RedbackVarAnisotropicDiffusion.h"


template<>
InputParameters validParams<RedbackVarAnisotropicDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  //params.addRequiredParam<RealTensorValue>("tensor_coeff", "The Tensor to multiply the Diffusion operator by");
  return params;
}


RedbackVarAnisotropicDiffusion::RedbackVarAnisotropicDiffusion(const InputParameters & parameters) :
    Kernel(parameters),
//    _k(getParam<RealTensorValue>("tensor_coeff"))
    _k(getMaterialProperty<RealTensorValue>("tensor_diffusivity"))
{
}

RedbackVarAnisotropicDiffusion::~RedbackVarAnisotropicDiffusion()
{
}

Real
RedbackVarAnisotropicDiffusion::computeQpResidual()
{
/*    Real temp11 = _k[_qp](0,0);
    Real temp22 = _k[_qp](1,1);
    std::cout<<"perm from kernel =" << temp11 <<std::endl;
    std::cout<<"perm from kernel =" << temp22 <<std::endl;
*/
  return (_k[_qp] * _grad_u[_qp]) * _grad_test[_i][_qp];
}

Real
RedbackVarAnisotropicDiffusion::computeQpJacobian()
{
  return (_k[_qp] * _grad_phi[_j][_qp]) * _grad_test[_i][_qp];
}

