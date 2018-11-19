/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
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
