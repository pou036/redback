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

#ifndef LNEFLUIDMATERIAL_H
#define LNEFLUIDMATERIAL_H

#include "Material.h"
#include "RankTwoTensor.h"
#include "RankFourTensor.h"

// Forward Declarations
class LneFluidMaterial;

template <>
InputParameters validParams<LneFluidMaterial>();

class LneFluidMaterial : public Material
{
public:
  LneFluidMaterial(const InputParameters & parameters);

protected:
  virtual void stepInitQpProperties();
  virtual void computeQpProperties();
  virtual void computeLneTerms();

  bool _has_sat;
  const VariableValue & _sat;
  bool _has_pore_pres;
  const VariableValue & _pore_pres; 

  RealVectorValue _gravity_param;

  MaterialProperty<RealVectorValue> & _gravity_term;
  MaterialProperty<Real> & _fluid_density;
  MaterialProperty<Real> & _dfluid_density;
  MaterialProperty<Real> & _diffusivity;
  MaterialProperty<Real> & _ddiffusivity;  

  Real _fluid_density_param, _fluid_compressibility_param;

  const VariableGradient & _grad_sat;
  const VariableGradient & _grad_pore_pres;

  Real _T0_param, _P0_param;

};

#endif // LNEFLUIDMATERIAL_H
