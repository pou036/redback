// Original class author: A.M. Jokisaari,  O. Heinonen

#ifndef FINITESTRAINRATEPLASTICTEMPERATUREMATERIAL_H
#define FINITESTRAINRATEPLASTICTEMPERATUREMATERIAL_H

#include "FiniteStrainPlasticMaterial.h"

class FiniteStrainRatePlasticTemperatureMaterial;

template<>
InputParameters validParams<FiniteStrainRatePlasticTemperatureMaterial>();

class FiniteStrainRatePlasticTemperatureMaterial : public FiniteStrainPlasticMaterial
{
public:
  FiniteStrainRatePlasticTemperatureMaterial(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpStress();
  virtual void initQpStatefulProperties();

  virtual void returnMap(const RankTwoTensor &, const RankTwoTensor &, const RankFourTensor &, RankTwoTensor &, RankTwoTensor &);
  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, RankTwoTensor &);

  VariableValue & _T;

   
  Real _ref_pe_rate;
  Real _exponent;
  Real _activation_energy_prop, _heat_capacity_prop;
  Real _gas_constant;
 
  MaterialProperty<Real> & _activation_energy;
  MaterialProperty<Real> & _mech_dissipation;
  MaterialProperty<Real> & _heat_capacity;
    

  Real _exponential;
  
  Real macaulayBracket(Real);

  
};

#endif //FINITESTRAINRATEPLASTICTEMPERATUREMATERIAL_H
