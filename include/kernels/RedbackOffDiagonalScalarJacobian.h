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

#ifndef REDBACKOFFDIAGONALSCALARJACOBIAN_H
#define REDBACKOFFDIAGONALSCALARJACOBIAN_H

#include "Kernel.h"

class RedbackOffDiagonalScalarJacobian;

template <>
InputParameters validParams<RedbackOffDiagonalScalarJacobian>();

class RedbackOffDiagonalScalarJacobian : public Kernel
{
public:
  RedbackOffDiagonalScalarJacobian(const InputParameters & parameters);
  virtual ~RedbackOffDiagonalScalarJacobian();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);
  unsigned int _sc_var;
  const VariableValue & _sc;
  unsigned int _z_var;
  const VariableValue & _z;

};

#endif /* REDBACKOFFDIAGONALSCALARJACOBIAN_H */
