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

#ifndef CHEMENDO_H
#define CHEMENDO_H

#include "Kernel.h"

class ChemEndo;

template<>
InputParameters validParams<ChemEndo>();


class ChemEndo : public Kernel
{
public:
  ChemEndo(const std::string & name, InputParameters parameters);
  virtual ~ChemEndo();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  Real _ar_c;
  Real _da;
  Real _delta;
};


#endif /* CHEMENDO_H */
