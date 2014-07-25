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

#include "MechDissip.h"


template<>
InputParameters validParams<MechDissip>()
{
  InputParameters params = validParams<Kernel>();

  params.addCoupledVar("pressure", 0., "Pressure variable.");
  //params.addRequiredParam<Real>("activation_energy", "Activation energy");
  params.addParam<Real>("gas_constant", 8.3143, "Universal gas constant");

  return params;
}


MechDissip::MechDissip(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _pressure(coupledValue("pressure")),
  _stress(getMaterialProperty<RankTwoTensor>("stress")),
  _activation_energy(getMaterialProperty<Real>("activation_energy")),
  _mech_dissipation(getMaterialProperty<Real>("mech_dissipation")),
  _equivalent_stress(getMaterialProperty<Real>("equivalent_stress")),
  _heat_capacity(getMaterialProperty<Real>("heat_capacity")), // rho * Cp
  //_activation_energy(getParam<Real>("activation_energy")),
  _gas_constant(getParam<Real>("gas_constant")) 
{

}

MechDissip::~MechDissip()
{

}

Real
MechDissip::computeQpResidual()
{
  //std::cout<<"In MechDissip.C: heat_capacity="<<_heat_capacity[_qp]<<std::endl;
  return -_test[_i][_qp] * _mech_dissipation[_qp] / _heat_capacity[_qp];
  
}

Real
MechDissip::computeQpJacobian()
{
  return -_test[_i][_qp] * _mech_dissipation[_qp] * _activation_energy[_qp] / (_gas_constant * _heat_capacity[_qp] * _u[_qp] * _u[_qp]);
}
