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
#include "RedbackConservativeAdvection.h"

template<>
InputParameters validParams<RedbackConservativeAdvection>()
{
  InputParameters params = validParams<Kernel>();
 // params.addRequiredParam<RealVectorValue>("velocity", "Velocity vector");

  params.addRequiredCoupledVar("vel_x", "The x velocity");
  params.addCoupledVar("vel_y", 0.0, "The y velocity");
  params.addCoupledVar("vel_z", 0.0, "The z velocity");

  return params;
}

RedbackConservativeAdvection::RedbackConservativeAdvection(const InputParameters & parameters) :
    Kernel(parameters),
   // _velocity(getParam<RealVectorValue>("velocity"))
	  _vel_x(coupledValue("vel_x")),
	  _vel_y(isCoupled("vel_y") ? coupledValue("vel_y") : _zero),
	  _vel_z(isCoupled("vel_z") ? coupledValue("vel_z") : _zero)
{
}

Real RedbackConservativeAdvection::computeQpResidual()
{

	_velocity(0) = _vel_x[_qp];
	_velocity(1) = _vel_y[_qp];
	_velocity(2) = _vel_z[_qp];

	return -_u[_qp] * (_velocity * _grad_test[_i][_qp]);
}

Real RedbackConservativeAdvection::computeQpJacobian()
{

	_velocity(0) = _vel_x[_qp];
	_velocity(1) = _vel_y[_qp];
	_velocity(2) = _vel_z[_qp];

	return -_phi[_j][_qp] * (_velocity * _grad_test[_i][_qp]);
}
