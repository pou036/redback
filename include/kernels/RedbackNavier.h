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

template<>
InputParameters validParams<RedbackNavier>();


class RedbackNavier : public Kernel
{
public:
  RedbackNavier(const InputParameters & parameters);
  virtual ~RedbackNavier();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  const unsigned int _component;

  const MaterialProperty<Real> & _div_fluid_vel;

  VariableValue & _fluid_vel_x;
  VariableValue & _fluid_vel_y;
  VariableValue & _fluid_vel_z;

private:
  Real _time_factor;
};


#endif /* REDBACKNAVIER_H */
