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

#ifndef REDBACKMATERIAL_H
#define REDBACKMATERIAL_H

#include "FiniteStrainPlasticMaterial.h"


//Forward Declarations
class RedbackMaterial;

template<>
InputParameters validParams<RedbackMaterial>();

class RedbackMaterial : public FiniteStrainPlasticMaterial
{
public:
  RedbackMaterial(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpStress();
  virtual void initQpStatefulProperties();

  virtual void returnMap(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &);
  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, RankTwoTensor &);
  Real macaulayBracket(Real);

  VariableValue & _T;
  VariableValue & _pore_pres;
  
  Real _gr_param, _ar_param, _ar_c_param, _delta_param, _da_param, _mu_param, _m_param, _exponent;
  MaterialProperty<Real> & _gr;
  MaterialProperty<Real> & _ar;
  MaterialProperty<Real> & _ar_c;
  MaterialProperty<Real> & _delta;
  MaterialProperty<Real> & _da;
  MaterialProperty<Real> & _mu;
  MaterialProperty<Real> & _m;
  
  MaterialProperty<Real> & _equivalent_stress;
  MaterialProperty<Real> & _mises_strain;
  MaterialProperty<Real> & _mises_strain_rate;
  MaterialProperty<Real> & _mod_gruntfest_number;
  MaterialProperty<Real> & _mechanical_dissipation;
  MaterialProperty<Real> & _mechanical_dissipation_jac;
  Real _exponential;
  
};

#endif //REDBACKMATERIAL_H
