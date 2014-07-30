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

#include "MechHeatTensor.h"


template<>
InputParameters validParams<MechHeatTensor>()
{
  InputParameters params = validParams<Kernel>();

  params.addCoupledVar("pressure", 0., "Pressure variable.");

  return params;
}


MechHeatTensor::MechHeatTensor(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _pressure(coupledValue("pressure")),
  _equivalent_stress(getMaterialProperty<Real>("equivalent_stress")),
  _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation")),
  //_stress(getMaterialProperty<RankTwoTensor>("stress")),
  _gr(getMaterialProperty<Real>("gr")),
  _m(getMaterialProperty<Real>("m")),
  _ar(getMaterialProperty<Real>("ar"))
{

}

MechHeatTensor::~MechHeatTensor()
{

}

Real
MechHeatTensor::computeQpResidual()
{
  //std::cout<<_stress[_qp].secondInvariant()<<std::endl;

  return -_test[_i][_qp]*_mechanical_dissipation[_qp];
  //std::pow(3.*_stress[_qp].secondInvariant(), _m[_qp])
}

Real
MechHeatTensor::computeQpJacobian()
{
  return -_test[_i][_qp] *_mechanical_dissipation[_qp] * ( _ar[_qp] / ( (1+_u[_qp] ) * (1+_u[_qp] ) ) )  * _phi[_j][_qp];
}
