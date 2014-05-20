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

#include "StrainRatePoint.h"
#include "Function.h"
#include "SubProblem.h"

template<>
InputParameters validParams<StrainRatePoint>()
{
  InputParameters params = validParams<PointValue>();

  params.addParam<Real>("gr", 1.0, "Gruntfest number.");
  params.addParam<Real>("ar", 1.0, "Arrhenius number.");

  return params;
}

StrainRatePoint::StrainRatePoint(const std::string & name, InputParameters parameters) :
    PointValue(name, parameters),
    _gr(getParam<Real>("gr")),
    _ar(getParam<Real>("ar"))
{
}

StrainRatePoint::~StrainRatePoint()
{
}

Real
StrainRatePoint::variableValue()
{
  return _gr * std::exp( ( _ar * _u[0] ) / ( 1 + _u[0] ) );
}
