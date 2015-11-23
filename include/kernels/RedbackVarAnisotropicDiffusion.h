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

#ifndef REDBACKVARANISOTROPICDIFFUSION_H
#define REDBACKVARANISOTROPICDIFFUSION_H

#include "Kernel.h"

class RedbackVarAnisotropicDiffusion;

template<>
InputParameters validParams<RedbackVarAnisotropicDiffusion>();


class RedbackVarAnisotropicDiffusion : public Kernel
{
public:
	RedbackVarAnisotropicDiffusion(const InputParameters & parameters);
  virtual ~RedbackVarAnisotropicDiffusion();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

//  RealTensorValue _k;
  const MaterialProperty<RealTensorValue>& _k;
};


#endif /* REDBACKVARANISOTROPICDIFFUSION_H */
