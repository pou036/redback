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

 // params.addRequiredCoupledVar("vel_x", "The x velocity");
 // params.addCoupledVar("vel_y", 0.0, "The y velocity");
 // params.addCoupledVar("vel_z", 0.0, "The z velocity");


  params.addRequiredCoupledVar("velocity", "The components of the velocity vector (vel_x, vel_y etc)");

  return params;
}

RedbackConservativeAdvection::RedbackConservativeAdvection(const InputParameters & parameters) :
    Kernel(parameters),
   // _velocity(getParam<RealVectorValue>("velocity"))
	//  _vel_x(coupledValue("vel_x")),
	//  _vel_y(isCoupled("vel_y") ? coupledValue("vel_y") : _zero),
	//  _vel_z(isCoupled("vel_z") ? coupledValue("vel_z") : _zero)
    _nvel(coupledComponents("velocity")),
    _vel(3),
    _grad_vel(3)
{


	for (unsigned int i = 0; i < _nvel; ++i)
	{
		_vel[i] = &coupledValue("velocity", i);
		_grad_vel[i] = &coupledGradient("velocity", i);
	}

	// set unused dimensions to zero
	for (unsigned i = _nvel; i < 3; ++i)
	{
		_vel[i] = &_zero;
		_grad_vel[i] = &_grad_zero;
	}
}

Real RedbackConservativeAdvection::computeQpResidual()
{

	//_velocity(0) = _vel_x[_qp];
	//_velocity(1) = _vel_y[_qp];
	//_velocity(2) = _vel_z[_qp];
	RealVectorValue velocity((*_vel[0])[_qp], (*_vel[1])[_qp], (*_vel[2])[_qp]); //velocity
	Real div_velocity = 0.0;
	for(unsigned int i = 0; i < 3; ++i){
	  div_velocity += (*_grad_vel[i])[_qp](i);  // divergence term
	}

	return -_u[_qp] * ( velocity * _grad_test[_i][_qp]) - (_u[_qp] * div_velocity)*_test[_i][_qp] ;
}

Real RedbackConservativeAdvection::computeQpJacobian()
{

	//_velocity(0) = _vel_x[_qp];
	//_velocity(1) = _vel_y[_qp];
	//_velocity(2) = _vel_z[_qp];

	RealVectorValue velocity((*_vel[0])[_qp], (*_vel[1])[_qp], (*_vel[2])[_qp]);
	Real div_velocity = 0.0;
	for(unsigned int i = 0; i < 3; ++i){
	  div_velocity += (*_grad_vel[i])[_qp](i);  // divergence term
	}

	return -_phi[_j][_qp] *   (velocity * _grad_test[_i][_qp]) - _phi[_j][_qp]  * div_velocity*_test[_i][_qp];
}
