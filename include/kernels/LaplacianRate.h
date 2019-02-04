//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef LAPLACIANRATE_H
#define LAPLACIANRATE_H

#include "TimeKernel.h"

class LaplacianRate;
class Function;

template <>
InputParameters validParams<LaplacianRate>();


class LaplacianRate : public Kernel
{
public:
  LaplacianRate(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

//private:
// Real _mu;
  Function & _mu_function;

  const VariableGradient & _grad_u_dot;
};

#endif /* DIFFUSION_H */
