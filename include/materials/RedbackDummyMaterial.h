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

#ifndef REDBACKDUMMYMATERIAL_H
#define REDBACKDUMMYMATERIAL_H

#include "Material.h"


//Forward Declarations
class RedbackDummyMaterial;

template<>
InputParameters validParams<RedbackDummyMaterial>();

class RedbackDummyMaterial : public Material
{
public:
  RedbackDummyMaterial(const std::string & name, InputParameters parameters);


protected:
  virtual void computeQpProperties();

  //bool _has_T;
  //VariableValue & _T, & _T_old;
  
  Real _dummy_prop_param;
  
  MaterialProperty<Real> & _dummy_prop;

private:
  MaterialProperty<Real> & _phi0;

};

#endif //REDBACKDUMMYMATERIAL_H
