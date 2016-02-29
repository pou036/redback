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

#ifndef RETURNMAPITERDT_H
#define RETURNMAPITERDT_H

#include "TimeStepper.h"
#include "PostprocessorInterface.h"

class ReturnMapIterDT;

template <>
InputParameters validParams<ReturnMapIterDT>();

/**
 * Computes the value of dt based on a value provided by a postprocessor. If
 * this value is above an upper threshold the time step is decreased by a user
 * supplied ratio. If the value is below a lower threshold the time step is
 * increased by 1/ratio.
 **/
class ReturnMapIterDT : public TimeStepper, public PostprocessorInterface
{
public:
  ReturnMapIterDT(const InputParameters & parameters);

protected:
  virtual Real computeInitialDT();
  virtual Real computeDT();

  const PostprocessorValue & _extreme_value;
  bool _has_initial_dt;
  Real _initial_dt;
  Real _max_iter;
  Real _min_iter;
  Real _ratio;
  Real _dt_min;
  Real _dt_max;
};

#endif /* RETURNMAPITERDT_H */
