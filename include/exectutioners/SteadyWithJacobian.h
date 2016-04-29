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

#ifndef STEADYWITHJACOBIAN_H
#define STEADYWITHJACOBIAN_H

#include "Executioner.h"
#include "InputParameters.h"

// System includes
#include <string>

class SteadyWithJacobian;
class FEProblem;

template<>
InputParameters validParams<SteadyWithJacobian>();

/**
 * Steady executioners usually only call "solve()" on the NonlinearSystem once.
 */
class SteadyWithJacobian: public Executioner
{
public:

  /**
   * Constructor
   *
   * @param parameters The parameters object holding data for the class to use.
   * @return Whether or not the solve was successful.
   */
  SteadyWithJacobian(const InputParameters & parameters);

  virtual ~SteadyWithJacobian();

  virtual void init();

  /**
   * This will call solve() on the NonlinearSystem.
   */
  virtual void execute();

  virtual void checkIntegrity();

protected:
  FEProblem & _problem;

  int & _time_step;
  Real & _time;
};

#endif //STEADY_H
