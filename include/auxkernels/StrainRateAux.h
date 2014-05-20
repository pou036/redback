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

#ifndef STRAINRATEAUX_H
#define STRAINRATEAUX_H

#include "AuxKernel.h"


//Forward Declarations
class StrainRateAux;

template<>
InputParameters validParams<StrainRateAux>();

/**
 * Constant auxiliary value
 */
class StrainRateAux : public AuxKernel
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  StrainRateAux(const std::string & name, InputParameters parameters);

  virtual ~StrainRateAux() {}

protected:
  virtual Real computeValue();

  const VariableValue & _temp;

  Real _gr;
  Real _ar;
};

#endif //STRAINRATEAUX_H
