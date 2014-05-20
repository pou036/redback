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

#ifndef STRAINRATEPOINT_H
#define STRAINRATEPOINT_H

#include "PointValue.h"

//Forward Declarations
class StrainRatePoint;

template<>
InputParameters validParams<StrainRatePoint>();

class StrainRatePoint : public PointValue
{
public:
  StrainRatePoint(const std::string & name, InputParameters parameters);
  virtual ~StrainRatePoint();
  virtual Real variableValue();

protected:
  Real _gr;
  Real _ar;
};



#endif /* STRAINRATEPOINT_H */
