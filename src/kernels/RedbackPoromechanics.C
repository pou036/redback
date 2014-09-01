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

#include "RedbackPoromechanics.h"

template<>
InputParameters validParams<RedbackPoromechanics>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

RedbackPoromechanics::RedbackPoromechanics(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters),
    _volumetric_strain_rate(getMaterialProperty<Real>("volumetric_strain_rate")),
    _mixture_compressibility(getMaterialProperty<Real>("mixture_compressibility"))
{
}

RedbackPoromechanics::~RedbackPoromechanics()
{
}

Real
RedbackPoromechanics::computeQpResidual()
{
  return (_volumetric_strain_rate[_qp] / _mixture_compressibility[_qp]) * _test[_i][_qp];
  // TODO: add note in doco to tell users not to turn on term if compress=0
  // TODO: add check compress > 0
  // TODO: this is the small strain formulation. Write it in finite strain... (add second order term)
}

Real
RedbackPoromechanics::computeQpJacobian()
{
  return 0;
}
