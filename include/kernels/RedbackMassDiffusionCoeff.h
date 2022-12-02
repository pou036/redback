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

#ifndef REDBACKMASSDIFFUSIONCOEFF_H
#define REDBACKMASSDIFFUSIONCOEFF_H

#include "Kernel.h"

class RedbackMassDiffusionCoeff : public Kernel
{
public:
  RedbackMassDiffusionCoeff(const InputParameters & parameters);
  static InputParameters validParams();
  virtual ~RedbackMassDiffusionCoeff();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  //  const VariableValue & _T;

  const VariableValue & _Le;
  const MaterialProperty<RealVectorValue> & _gravity_term;

private:
  Real _time_factor;
};

#endif /* REDBACKMASSDIFFUSIONCOEFF_H */
