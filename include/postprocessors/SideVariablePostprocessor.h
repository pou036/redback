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

#ifndef SIDEVARIABLEPOSTPROCESSOR_H
#define SIDEVARIABLEPOSTPROCESSOR_H

#include "SidePostprocessor.h"
#include "MooseVariableInterface.h"

// Forward Declarations
class SideVariablePostprocessor;

template <>
InputParameters validParams<SideVariablePostprocessor>();

class SideVariablePostprocessor : public SidePostprocessor, public MooseVariableInterface
{
public:
  SideVariablePostprocessor(const InputParameters & parameters);

  virtual void execute() override;

protected:
  /// This is what derived classes should override to do something on every quadrature point on every element
  virtual void computeQpValue() = 0;

  /// Holds the solution at current quadrature points
  const VariableValue & _u;

  /// Holds the solution gradient at the current quadrature points
  const VariableGradient & _grad_u;

  /// Holds the solution derivative at the current quadrature points
  const VariableValue & _u_dot;

  /// The current quadrature point
  unsigned int _qp;
};

#endif
