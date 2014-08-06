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

#ifndef REDBACKCHEMMATERIAL_H
#define REDBACKCHEMMATERIAL_H

#include "RedbackMaterial.h"


//Forward Declarations
class RedbackChemMaterial;

template<>
InputParameters validParams<RedbackChemMaterial>();

class RedbackChemMaterial : public RedbackMaterial
{
public:
  RedbackChemMaterial(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpStress();
  virtual void initQpStatefulProperties();
  virtual void computeEnergyTerms(RankTwoTensor & , Real , Real );

  Real  _ar_c_param, _da_param, _mu_param;
  MaterialProperty<Real> & _ar_c;
  MaterialProperty<Real> & _da;
  MaterialProperty<Real> & _mu;
  
  MaterialProperty<Real> & _chemical_porosity;
  MaterialProperty<Real> & _solid_ratio;
  MaterialProperty<Real> & _chemical_endothermic_energy;
  MaterialProperty<Real> & _chemical_endothermic_energy_jac;
  MaterialProperty<Real> & _chemical_exothermic_energy;
  MaterialProperty<Real> & _chemical_exothermic_energy_jac;
  
};

#endif //REDBACKCHEMMATERIAL_H
