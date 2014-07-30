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

#include "MechHeat.h"


template<>
InputParameters validParams<MechHeat>()
{
  InputParameters params = validParams<Kernel>();

  params.addCoupledVar("pressure", 0., "Pressure variable.");

  return params;
}


MechHeat::MechHeat(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _pressure(coupledValue("pressure")),
  _gr(getMaterialProperty<Real>("gr")),
  _ar(getMaterialProperty<Real>("ar")),
  _ar_c(getMaterialProperty<Real>("ar_c")),
  _m(getMaterialProperty<Real>("m")),
  _delta(getMaterialProperty<Real>("delta"))
{

}

MechHeat::~MechHeat()
{

}

Real
MechHeat::computeQpResidual()
{
  //return -_test[_i][_qp]*_gr[_qp]*std::pow(1.-_pressure[_qp], _m[_qp])*std::exp( (_ar[_qp]+_ar_c[_qp]*_delta[_qp]*_u[_qp]) / (1 + _delta[_qp]*_u[_qp]) );
  return -_test[_i][_qp]*_gr[_qp] * std::exp( _u[_qp]);
}

Real
MechHeat::computeQpJacobian()
{
  //return -_test[_i][_qp] * _gr[_qp] * std::pow(1.-_pressure[_qp], _m[_qp]) * (_ar[_qp] - _ar_c[_qp])*_delta[_qp] / ( (1+_delta[_qp]*_u[_qp] ) * (1+_delta[_qp]*_u[_qp] ) ) *
  //  std::exp( (_ar[_qp]+_ar_c[_qp]*_delta[_qp]*_u[_qp]) / (1 + _delta[_qp]*_u[_qp]) ) * _phi[_j][_qp];
  return -_test[_i][_qp]*_gr[_qp] * std::exp( _u[_qp]) * _phi[_j][_qp];
}
