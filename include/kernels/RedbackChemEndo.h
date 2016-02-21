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

#ifndef REDBACKCHEMENDO_H
#define REDBACKCHEMENDO_H

#include "Kernel.h"

class RedbackChemEndo;

template <>
InputParameters validParams<RedbackChemEndo>();

class RedbackChemEndo : public Kernel
{
public:
  RedbackChemEndo(const InputParameters & parameters);
  virtual ~RedbackChemEndo();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const MaterialProperty<Real> & _chemical_endothermic_energy;
  const MaterialProperty<Real> & _chemical_endothermic_energy_jac;

private:
  Real _time_factor;
};

#endif /* REDBACKCHEMENDO_H */
