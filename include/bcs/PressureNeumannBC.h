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

#ifndef PRESSURENEUMANNBC_H
#define PRESSURENEUMANNBC_H

#include "IntegratedBC.h"

class PressureNeumannBC;

template <>
InputParameters validParams<PressureNeumannBC>();

/**
 * Implements a simple constant Neumann BC where grad(u)=value on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class PressureNeumannBC : public IntegratedBC
{
public:
  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  PressureNeumannBC(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  /// Value of grad(u) on the boundary.
  const VariableValue & _var;
  /// The id of the coupled variable
  unsigned int _var_num;

  const unsigned int _component;
};

#endif // PRESSURENEUMANNBC_H
