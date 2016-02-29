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

#ifndef REDBACKMECHDISSIP_H
#define REDBACKMECHDISSIP_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class RedbackMechDissip;

template <>
InputParameters validParams<RedbackMechDissip>();

class RedbackMechDissip : public Kernel
{
public:
  RedbackMechDissip(const InputParameters & parameters);
  virtual ~RedbackMechDissip();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  // const VariableValue & _pressure;
  const MaterialProperty<Real> & _mechanical_dissipation;
  const MaterialProperty<Real> & _mechanical_dissipation_jac;

private:
  Real _time_factor;
};

#endif /* REDBACKMECHDISSIP_H */
