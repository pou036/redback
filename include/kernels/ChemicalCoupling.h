//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef ChemicalCoupling_H
#define ChemicalCoupling_H

#include "Kernel.h"

class ChemicalCoupling;

template <>
InputParameters validParams<ChemicalCoupling>();

class ChemicalCoupling : public Kernel
{
public:
  ChemicalCoupling(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  Real _lambda;

  const VariableValue & _c;
};

#endif // ChemicalCoupling_H
