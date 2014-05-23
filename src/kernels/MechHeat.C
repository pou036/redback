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
  params.addParam<Real>("gr", 1.0, "Gruntfest number.");
  params.addParam<Real>("ar", 1.0, "Arrhenius number.");
  params.addParam<Real>("ar_c", 1.0, "Chemical Arrhenius number.");
  params.addParam<Real>("delta", 1.0, "Kamenetskii parameter.");
  params.addParam<Real>("m", 1.0, "Rate sensitivity coefficient.");

  return params;
}


MechHeat::MechHeat(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _pressure(coupledValue("pressure")),
  _gr(getParam<Real>("gr")),
  _ar(getParam<Real>("ar")),
  _ar_c(getParam<Real>("ar_c")),
  _m(getParam<Real>("m")),
  _delta(getParam<Real>("delta"))
{

}

MechHeat::~MechHeat()
{

}

Real
MechHeat::computeQpResidual()
{
  return -_test[_i][_qp]*_gr*std::pow(1.-_pressure[_qp], _m)*std::exp( (_ar+_ar_c*_delta*_u[_qp]) / (1 + _delta*_u[_qp]) );
}

Real
MechHeat::computeQpJacobian()
{
  return -_test[_i][_qp] * _gr * std::pow(1.-_pressure[_qp], _m) * (_ar- _ar_c)*_delta / ( (1+_delta*_u[_qp] ) * (1+_delta*_u[_qp] ) ) *
    std::exp( (_ar+_ar_c*_delta*_u[_qp]) / (1 + _delta*_u[_qp]) ) * _phi[_j][_qp];
}
