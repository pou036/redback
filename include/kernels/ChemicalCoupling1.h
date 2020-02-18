//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef ChemicalCoupling1_H
#define ChemicalCoupling1_H

#include "Kernel.h"

class ChemicalCoupling1;

template <>
InputParameters validParams<ChemicalCoupling1>();

class ChemicalCoupling1 : public Kernel
{
public:
  ChemicalCoupling1(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  Real _beta;

  const VariableValue & _c;
};

#endif // ChemicalCoupling1_H
