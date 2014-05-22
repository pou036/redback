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

#ifndef CUBETERM_H
#define CUBETERM_H

#include "Kernel.h"

class CubeTerm;

template<>
InputParameters validParams<CubeTerm>();


class CubeTerm : public Kernel
{
public:
  CubeTerm(const std::string & name, InputParameters parameters);
  virtual ~CubeTerm();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  Real _lambda;
};


#endif /* CUBETERM_H */
