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

#include "RedbackMechDissip.h"


template<>
InputParameters validParams<RedbackMechDissip>()
{
  InputParameters params = validParams<Kernel>();

  //params.addCoupledVar("pressure", 0., "Pressure variable.");
  //params.addRequiredParam<Real>("activation_energy", "Activation energy");
  //params.addParam<Real>("gas_constant", 8.3143, "Universal gas constant");

  return params;
}


RedbackMechDissip::RedbackMechDissip(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  //_pressure(coupledValue("pressure")),
  _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation")),
  _mechanical_dissipation_jac(getMaterialProperty<Real>("mechanical_dissipation_jacobian"))
{

}

RedbackMechDissip::~RedbackMechDissip()
{

}

Real
RedbackMechDissip::computeQpResidual()
{
  //std::cout<<"In RedbackMechDissip.C: heat_capacity="<<_heat_capacity[_qp]<<std::endl;
	return -_test[_i][_qp]*_mechanical_dissipation[_qp];
  
}

Real
RedbackMechDissip::computeQpJacobian()
{
	return -_test[_i][_qp] *_mechanical_dissipation_jac[_qp] * _phi[_j][_qp];
}