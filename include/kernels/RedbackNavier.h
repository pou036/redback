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

#ifndef REDBACKNAVIER_H
#define REDBACKNAVIER_H

#include "Kernel.h"

class RedbackNavier;

template <>
InputParameters validParams<RedbackNavier>();

class RedbackNavier : public Kernel
{
public:
  RedbackNavier(const InputParameters & parameters);
  virtual ~RedbackNavier();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const unsigned int _component;

  const VariableValue & _fluid_vel_x;
  const VariableValue & _fluid_vel_y;
  const VariableValue & _fluid_vel_z;

  const unsigned int _vel_fluid_x_var;
  const unsigned int _vel_fluid_y_var;
  const unsigned int _vel_fluid_z_var;

private:
  Real _time_factor;
};

#endif /* REDBACKNAVIER_H */
