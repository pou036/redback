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

#ifndef REDBACKDAMAGE_H
#define REDBACKDAMAGE_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class RedbackDamage;

template <>
InputParameters validParams<RedbackDamage>();

class RedbackDamage : public Kernel
{
public:
  RedbackDamage(const InputParameters & parameters);
  virtual ~RedbackDamage();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  // const VariableValue & _pressure;
  const MaterialProperty<Real> & _damage_kernel;
  const MaterialProperty<Real> & _damage_kernel_jac;

private:
  Real _time_factor;
};

#endif /* REDBACKDAMAGE_H */
