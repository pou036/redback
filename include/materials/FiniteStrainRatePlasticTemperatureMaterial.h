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
  
  MaterialProperty<Real> & _mech_dissipation;
  
  Real _ref_pe_rate;
  Real _exponent;
  Real _activation_energy;
  Real _gas_constant;
  
  Real _exponential;
  
    
  Real macaulayBracket(Real);

};

#endif //FINITESTRAINRATEPLASTICTEMPERATUREMATERIAL_H
