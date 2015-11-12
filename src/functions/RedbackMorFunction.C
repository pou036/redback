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

// Standard includes
#include <math.h>

// MOOSE includes
#include "RedbackMorFunction.h"

template<> InputParameters validParams<RedbackMorFunction>()
{
   InputParameters params = validParams<Function>();
   params.addParam<Real>("mantle_temperature", 1600, "Mantle temperature (Tm in K)");
   params.addParam<Real>("surface_temperature", 300, "Surface temperature (T0 in K)");
   params.addParam<Real>("diffusivity", 0.8e-6, "Diffusivity (c_{th} in m^2/s)");
   params.addParam<Real>("velocity", 6.3694e-10, "Spreading Velocity of the MOR (v, 2cm/yr default)");
   return params;
}

RedbackMorFunction::RedbackMorFunction(const InputParameters & parameters) :
    Function(parameters),
    _mantle_temperature(getParam<Real>("mantle_temperature")),
    _surface_temperature(getParam<Real>("surface_temperature")),
    _diffusivity(getParam<Real>("diffusivity")),
    _velocity(getParam<Real>("velocity"))
{
}

Real
RedbackMorFunction::value(Real, const Point &p)
{
  const Real
      x = p(0),
      y = p(1);
  //    z = p(2);
  Real argument = -y/sqrt(4*_diffusivity*(fabs(x) + 1e-1)/_velocity);
  Real temperature = _mantle_temperature + (_surface_temperature - _mantle_temperature)*erfc(argument);

  return temperature;
}
