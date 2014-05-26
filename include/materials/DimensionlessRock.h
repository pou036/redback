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

#ifndef DIMENSIONLESSROCK_H
#define DIMENSIONLESSROCK_H

#include "Material.h"


//Forward Declarations
class DimensionlessRock;

template<>
InputParameters validParams<DimensionlessRock>();

class DimensionlessRock : public Material
{
public:
  DimensionlessRock(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpProperties();
  Real _gr_param, _ar_param, _ar_c_param;
  MaterialProperty<Real> & _gr;
  MaterialProperty<Real> & _ar;
  MaterialProperty<Real> & _ar_c;
};

#endif //DIMENSIONLESSROCK_H
