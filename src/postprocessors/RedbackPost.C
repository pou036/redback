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

#include "RedbackPost.h"
#include "Function.h"
#include "SubProblem.h"
#include "DimensionlessRock.h"

template<>
InputParameters validParams<RedbackPost>()
{
  InputParameters params = validParams<PointValue>();

  return params;
}

RedbackPost::RedbackPost(const std::string & name, InputParameters parameters) :
    PointValue(name, parameters),
    _equivalent_stress(getMaterialProperty<Real>("equivalent_stress")),
    _mises_strain(getMaterialProperty<Real>("mises_strain")),
    _mises_strain_rate(getMaterialProperty<Real>("mises_strain_rate")),
    _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation"))
{
}

RedbackPost::~RedbackPost()
{
}

Real
RedbackPost::variableValue()
{
  return _u[0];
}
