//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef BEZIERFUNCTIONAUX_H
#define BEZIERFUNCTIONAUX_H

#include "AuxKernel.h"
#include "BezierUserObject.h"

// Forward Declarations
class BezierFunctionAux;

template <>
InputParameters validParams<BezierFunctionAux>();

/**
 * Function auxiliary value
 */
class BezierFunctionAux : public AuxKernel
{
public:
  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  BezierFunctionAux(const InputParameters & parameters);

protected:
  virtual Real computeValue() override;

  /// Function being used to compute the value of this kernel
  const BezierUserObject & _func;
};

#endif // BEZIERFUNCTIONAUX_H
