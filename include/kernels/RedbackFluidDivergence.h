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

#ifndef REDBACKFLUIDDIVERGENCE_H
#define REDBACKFLUIDDIVERGENCE_H

#include "Kernel.h"

class RedbackFluidDivergence;

template<>
InputParameters validParams<RedbackFluidDivergence>();


class RedbackFluidDivergence : public Kernel
{
public:
  RedbackFluidDivergence(const InputParameters & parameters);
  virtual ~RedbackFluidDivergence();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const MaterialProperty<Real> & _div_fluid_kernel;

private:
  Real _time_factor;
};


#endif /* REDBACKFLUIDDIVERGENCE_H */
