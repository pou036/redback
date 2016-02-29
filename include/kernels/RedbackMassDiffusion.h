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

#ifndef REDBACKMASSDIFFUSION_H
#define REDBACKMASSDIFFUSION_H

#include "Kernel.h"

class RedbackMassDiffusion;

template <>
InputParameters validParams<RedbackMassDiffusion>();

class RedbackMassDiffusion : public Kernel
{
public:
  RedbackMassDiffusion(const InputParameters & parameters);
  virtual ~RedbackMassDiffusion();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  //  const VariableValue & _T;

  const MaterialProperty<Real> & _Le;
  const MaterialProperty<RealVectorValue> & _gravity_term;

private:
  Real _time_factor;
};

#endif /* REDBACKMASSDIFFUSION_H */
