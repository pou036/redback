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

#ifndef REDBACKTHERMALPRESSURIZATION_H
#define REDBACKTHERMALPRESSURIZATION_H

#include "Kernel.h"

class RedbackThermalPressurization;

template <>
InputParameters validParams<RedbackThermalPressurization>();

/**
 * Kernel that is calling coupledDot
 */
class RedbackThermalPressurization : public Kernel
{
public:
  RedbackThermalPressurization(const InputParameters & parameters);
  virtual ~RedbackThermalPressurization();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const VariableValue & _temp_dot;
  const VariableValue & _dtemp_dot_dtemp;

  const MaterialProperty<Real> & _pressurization_coefficient;
  unsigned int _temp_var; // variable number of the temperature variable

private:
  Real _time_factor;
};

#endif /* REDBACKTHERMALPRESSURIZATION_H */
