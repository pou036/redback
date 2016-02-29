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

#ifndef FUNCTIONTIMESRANDOMIC_H
#define FUNCTIONTIMESRANDOMIC_H

#include "InitialCondition.h"
#include "InputParameters.h"

// System includes
#include <string>

// Forward Declarations
class FunctionTimesRandomIC;
class Function;
namespace libMesh
{
class Point;
}

template <>
InputParameters validParams<FunctionTimesRandomIC>();

/**
 * FunctionTimesRandomIC just returns a Random value.
 */
class FunctionTimesRandomIC : public InitialCondition
{
public:
  /**
   * Constructor
   *
   * @param name The name given to the initial condition in the input file.
   * @param parameters The parameters object holding data for the class to use.
   */
  FunctionTimesRandomIC(const InputParameters & parameters);

protected:
  /**
   * Evaluate the function at the current quadrature point and timestep.
   */
  Real f();
  /**
   * The value of the variable at a point.
   *
   * This must be overridden by derived classes.
   */
  virtual Real value(const Point & p);

  Real _min;
  Real _max;
  Real _range;
  Function & _func;
};

#endif // FUNCTIONTIMESRANDOMIC_H
