//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef FUNCTIONJUMPDIRICHLETBC_H
#define FUNCTIONJUMPDIRICHLETBC_H

#include "NodalBC.h"

class Function;

/**
 * Defines a boundary condition that forces the value to be a user specified
 * function at the boundary.
 */
class FunctionJumpDirichletBC : public NodalBC
{
public:
  FunctionJumpDirichletBC(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  /**
   * Evaluate the function at the current quadrature point and timestep.
   */
  Real f();

  virtual Real computeQpResidual() override;

  /// The function being used for evaluation
  const Function & _func;
  const VariableValue & _tangent_jump;
  Real _angle;
  const unsigned int _component;
};

#endif // FUNCTIONJUMPDIRICHLETBC_H
