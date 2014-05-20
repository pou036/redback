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

#include "StrainRateAux.h"

template<>
InputParameters validParams<StrainRateAux>()
{
  InputParameters params = validParams<AuxKernel>();

  params.addRequiredCoupledVar("temp", "The temperature variable.");

  params.addParam<Real>("gr", 1.0, "Gruntfest number.");
  params.addParam<Real>("ar", 1.0, "Arrhenius number.");

  return params;
}

StrainRateAux::StrainRateAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
    _temp(coupledValue("temp")),
    _gr(getParam<Real>("gr")),
    _ar(getParam<Real>("ar"))
{
}


Real
StrainRateAux::computeValue()
{
  return _gr * std::exp( ( _ar * _temp[_qp] ) / ( 1 + _temp[_qp] ) );
}
