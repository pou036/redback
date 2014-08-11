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

  Real  _ar_F_param, _ar_R_param, _da_endo_param, _da_exo_param, _mu_param, _Kc_param, _eta1_param, _eta2_param, _Aphi_param;
  MaterialProperty<Real> & _ar_F;
  MaterialProperty<Real> & _ar_R;
  MaterialProperty<Real> & _mu;
  
  MaterialProperty<Real> & _chemical_porosity;
  MaterialProperty<Real> & _solid_ratio;
  MaterialProperty<Real> & _chemical_endothermic_energy;
  MaterialProperty<Real> & _chemical_endothermic_energy_jac;
  MaterialProperty<Real> & _chemical_exothermic_energy;
  MaterialProperty<Real> & _chemical_exothermic_energy_jac;
  MaterialProperty<Real> & _chemical_source_mass;
  MaterialProperty<Real> & _chemical_source_mass_jac;
};

#endif //REDBACKCHEMMATERIAL_H
