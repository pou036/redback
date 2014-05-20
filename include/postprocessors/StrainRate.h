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

#ifndef STRAINRATE_H
#define STRAINRATE_H

#include "PointValue.h"

//Forward Declarations
class StrainRate;

template<>
InputParameters validParams<StrainRate>();

class StrainRate : public PointValue
{
public:
  StrainRate(const std::string & name, InputParameters parameters);
  virtual ~StrainRate();
  virtual Real variableValue();

protected:
  Real _gr;
  Real _ar;
};



#endif /* STRAINRATE_H */
