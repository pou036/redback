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

template<>
InputParameters validParams<RedbackRotationBC>()
{
  InputParameters params = validParams<NodalBC>();
  params.addRequiredCoupledVar("grad_ux", "The gradient of this variable will be used to calculate the 1st term of macro-rotation");
  //params.addRequiredCoupledVar("some_var_1", "The gradient of this variable will be used to calculate the 1st term of macro-rotation");
  //params.addRequiredCoupledVar("some_var_2", "The gradient of this variable will be used to calculate the 2nd term of macro-rotation");
  //params.addParam<double>("dir1", 0, "direction of the first derivative");
  //params.addParam<double>("dir2", 0, "direction of the second derivative");
  //params.addRequiredCoupledVar("antisymmetric_strain_xz", "...");
  //params.addRequiredCoupledVar("antisymmetric_strain_yz", "...");
  //params.addParam<Real>("alpha", 1, "factor before the antisymmetric strain");
  return params;
}

RedbackRotationBC::RedbackRotationBC(const InputParameters & parameters) :
    NodalBC(parameters),
    _grad_ux(coupledValue("grad_ux"))
      //_some_var_1(coupledGradient("some_var_1")),
      //_some_var_2(coupledGradient("some_var_2")),
      //_d1(getParam<double>("dir1")),
      //_d2(getParam<double>("dir2"))
    //_v(coupledValue("v")),
    //_v_num(coupled("v")),
    //_grad_v(coupledGradient("v")),
    //_alpha(getParam<Real>("alpha"))
{}

Real
RedbackRotationBC::computeQpResidual()
{
  return _u[_qp];//-0.5*(_grad_ux[_qp])//-0.5*(_some_var_1[_qp](_d1)-_some_var_2[_qp](_d2));// - _antisymmetric_strain_ij[_qp];
}

//Real
//RedbackRotationBC::computeQpOffDiagJacobian(unsigned int jvar)
//{
//  if (jvar == _v_num)
//    return -1.0;
//  else
//    return 0.;
//}
