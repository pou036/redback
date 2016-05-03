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

#include "RedbackRotationBC.h"
#include "MooseMesh.h"


template<>
InputParameters validParams<RedbackRotationBC>()
{
  InputParameters params = validParams<NodalBC>();
  params += validParams<MaterialPropertyInterface>();

  params.addRequiredCoupledVar("disp_x", "displacement in x");
  params.addCoupledVar("disp_y", "displacement in y"); // only required in 2D and 3D
  params.addCoupledVar("disp_z", "displacement in z"); // only required in 3D

  params.addRequiredParam<Real>("comp_1", "first component of the macro-rotation tensor");
  params.addRequiredParam<Real>("comp_2", "second component of the macro-rotation tensor");
  params.addRequiredParam<Real>("scalar", "scalar that multiplies the macro-rotation");

  return params;
}

RedbackRotationBC::RedbackRotationBC(const InputParameters & parameters) :
    NodalBC(parameters),
    MaterialPropertyInterface(this),


    // Coupled variables
    _disp_x(coupledValue("disp_x")),
    _disp_y(_mesh.dimension() >= 2 ? coupledValue("disp_y") : _zero),
    _disp_z(_mesh.dimension() == 3 ? coupledValue("disp_z") : _zero),

    // Gradient of Coupled variables
    _grad_ux(coupledGradient("disp_x")),
    _grad_uy(_mesh.dimension() >= 2 ? coupledGradient("disp_y") : _grad_zero),
    _grad_uz(_mesh.dimension() == 3 ? coupledGradient("disp_z") : _grad_zero),

    // Required parameters
    _comp_1(getParam<Real>("comp_1")),
    _comp_2(getParam<Real>("comp_2")),
    _scalar(getParam<Real>("scalar"))
{}

Real
RedbackRotationBC::computeQpResidual()
{
  RealTensorValue grad_tensor_u(_grad_ux[_qp], _grad_uy[_qp], _grad_uz[_qp]);
  RealTensorValue macro_rot;

  macro_rot = (grad_tensor_u - grad_tensor_u.transpose()) / 2.0;

  return _u[_qp] - _scalar * macro_rot(_comp_1,_comp_2);
}
