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

#ifndef REDBACKMASSDIFFUSION_H
#define REDBACKMASSDIFFUSION_H

#include "Kernel.h"

class RedbackMassDiffusion;

template<>
InputParameters validParams<RedbackMassDiffusion>();


class RedbackMassDiffusion : public Kernel
{
public:
  RedbackMassDiffusion(const std::string & name, InputParameters parameters);
  virtual ~RedbackMassDiffusion();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

//  VariableValue & _T;

  RealTensorValue _Le;
 // MaterialProperty<Real> & _volumetric_strain_rate;
};


#endif /* REDBACKMASSDIFFUSION_H */
