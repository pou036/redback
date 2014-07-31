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

  //params.addCoupledVar("pressure", 0., "Pressure variable.");

  return params;
}


MechHeatTensor::MechHeatTensor(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  //_pressure(coupledValue("pressure")),
  //_equivalent_stress(getMaterialProperty<Real>("equivalent_stress")),
  _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation")),
  _mechanical_dissipation_jac(getMaterialProperty<Real>("mechanical_dissipation_jacobian"))
  //_stress(getMaterialProperty<RankTwoTensor>("stress")),
  //_gr(getMaterialProperty<Real>("gr")),
  //_m(getMaterialProperty<Real>("m")),
  //_ar(getMaterialProperty<Real>("ar"))
{

}

MechHeatTensor::~MechHeatTensor()
{

}

Real
MechHeatTensor::computeQpResidual()
{
  //return -_test[_i][_qp]*_gr[_qp]*std::exp(_u[_qp]);
  return -_test[_i][_qp]*_mechanical_dissipation[_qp];
}

Real
MechHeatTensor::computeQpJacobian()
{
  return -_test[_i][_qp] *_mechanical_dissipation_jac[_qp] * _phi[_j][_qp];
  //return -_test[_i][_qp]*_gr[_qp]*std::exp(_u[_qp])*_phi[_j][_qp];
}
