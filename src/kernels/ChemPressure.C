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

#include "ChemPressure.h"


template<>
InputParameters validParams<ChemPressure>()
{
  InputParameters params = validParams<Kernel>();

  params.addRequiredCoupledVar("temp", "Temperature variable.");

  return params;
}


ChemPressure::ChemPressure(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _temp(coupledValue("temp")),
  _ar_c(getMaterialProperty<Real>("ar_c")),
  _mu(getMaterialProperty<Real>("mu")),
  _delta(getMaterialProperty<Real>("delta"))
{

}

ChemPressure::~ChemPressure()
{

}

Real
ChemPressure::computeQpResidual()
{
  return -_test[_i][_qp]*_mu[_qp]*std::exp( (_ar_c[_qp]*_delta[_qp]*_temp[_qp]) / (1 + _delta[_qp]*_temp[_qp]) );
}

Real
ChemPressure::computeQpJacobian()
{
  return 0.;
}
