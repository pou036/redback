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

#ifndef DUMMYCNOIDAL_H
#define DUMMYCNOIDAL_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class RedbackMechDissip;

template<>
InputParameters validParams<RedbackMechDissip>();


class DummyCnoidal : public Kernel
{
public:
  DummyCnoidal(const InputParameters & parameters);
  virtual ~DummyCnoidal();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  Real _lambda_param, _mu_param, _tau_param, _alpha_param;
};


#endif /* DUMMYCNOIDAL_H */
