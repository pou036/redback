//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef MATCHEDVALUEJUMPBC_H
#define MATCHEDVALUEJUMPBC_H

#include "NodalBC.h"

// Forward Declarations
class MatchedValueJumpBC;

template <>
InputParameters validParams<MatchedValueJumpBC>();

/**
 * Implements a simple coupled boundary condition where u=v on the boundary.
 */
class MatchedValueJumpBC : public NodalBC
{
public:
  MatchedValueJumpBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const VariableValue & _v;

  /// The id of the coupled variable
  unsigned int _v_num;

  const PostprocessorValue & _jump;
  Real _angle;
  const unsigned int _component;
};

#endif // MATCHEDVALUEJUMPBC_H
