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

#ifndef REDBACKTHERMALDIFFUSION_H
#define REDBACKTHERMALDIFFUSION_H

#include "Kernel.h"

class RedbackThermalDiffusion;

template <> InputParameters validParams<RedbackThermalDiffusion>();

class RedbackThermalDiffusion : public Kernel {
public:
  RedbackThermalDiffusion(const InputParameters &parameters);
  virtual ~RedbackThermalDiffusion();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  Real _time_factor;
};

#endif /* REDBACKTHERMALDIFFUSION_H */
