//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef LINEARFUNCTIONAUX_H
#define LINEARFUNCTIONAUX_H

#include "AuxKernel.h"
#include "LinearUserObject.h"

/**
 * Function auxiliary value
 */
class LinearFunctionAux : public AuxKernel
{
public:
  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  LinearFunctionAux(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  virtual Real computeValue() override;

  /// Function being used to compute the value of this kernel
  const LinearUserObject & _func;
};

#endif // LINEARFUNCTIONAUX_H
