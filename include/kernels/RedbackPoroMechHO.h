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

#ifndef REDBACKPOROMECHHO_H
#define REDBACKPOROMECHHO_H

#include "Kernel.h"

class RedbackPoroMechHO;

template <>
InputParameters validParams<RedbackPoroMechHO>();

/**
 * Kernel that is calling coupledDot
 */
class RedbackPoroMechHO : public Kernel
{
public:
  RedbackPoroMechHO(const InputParameters & parameters);
  virtual ~RedbackPoroMechHO();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const MaterialProperty<Real> & _poromech_kernel;
  const MaterialProperty<Real> & _poromech_jac;

  unsigned int _temp_var; // variable number of the temperature variable

private:
  Real _time_factor;
};

#endif /* REDBACKPOROMECHHO_H */