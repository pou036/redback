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

#include "RedbackChemPressure.h"


template<>
InputParameters validParams<RedbackChemPressure>()
{
  InputParameters params = validParams<Kernel>();

  params.addRequiredCoupledVar("temp", "Temperature variable.");

  return params;
}


RedbackChemPressure::RedbackChemPressure(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _temp(coupledValue("temp")),
  _ar_c(getMaterialProperty<Real>("ar_c")),
  _mu(getMaterialProperty<Real>("mu")),
  _delta(getMaterialProperty<Real>("delta"))
{

}

RedbackChemPressure::~RedbackChemPressure()
{

}

Real
RedbackChemPressure::computeQpResidual()
{
  return -_test[_i][_qp]*_mu[_qp]*std::exp( (_ar_c[_qp]*_delta[_qp]*_temp[_qp]) / (1 + _delta[_qp]*_temp[_qp]) );
}

Real
RedbackChemPressure::computeQpJacobian()
{
  return 0.;
}
