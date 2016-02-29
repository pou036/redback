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

#ifndef REDBACKCHEMEXO_H
#define REDBACKCHEMEXO_H

#include "Kernel.h"

class RedbackChemExo;

template <>
InputParameters validParams<RedbackChemExo>();

class RedbackChemExo : public Kernel
{
public:
  RedbackChemExo(const InputParameters & parameters);
  virtual ~RedbackChemExo();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const MaterialProperty<Real> & _chemical_exothermic_energy;
  const MaterialProperty<Real> & _chemical_exothermic_energy_jac;

private:
  Real _time_factor;
};

#endif /* REDBACKCHEMEXO_H */
