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

#ifndef CHEMPRESSURE_H
#define CHEMPRESSURE_H

#include "Kernel.h"

class ChemPressure;

template<>
InputParameters validParams<ChemPressure>();


class ChemPressure : public Kernel
{
public:
  ChemPressure(const std::string & name, InputParameters parameters);
  virtual ~ChemPressure();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  VariableValue &_temp;
  Real _ar_c;
  Real _mu;
};


#endif /* CHEMPRESSURE_H */
