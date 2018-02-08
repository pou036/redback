#ifndef REDBACKFLOWLAWBASE_H
#define REDBACKFLOWLAWBASE_H

#include "DiscreteElementUserObject.h"
#include "RankTwoTensor.h"

class RedbackFlowLawBase;


template<>
InputParameters validParams<RedbackFlowLawBase>();

/**
 * Redback user object base class to define flow laws
 */
class RedbackFlowLawBase : public DiscreteElementUserObject
{
 public:
  RedbackFlowLawBase(const InputParameters & parameters);
  virtual Real value(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress,
                     Real yield_stress, unsigned int qp, Real dt) const = 0;
  //Real operator[](unsigned int qp) const{ return value(qp);}
  virtual Real derivative_p(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress,
                            const RankTwoTensor & sig, unsigned int qp, Real dt) const = 0;
  virtual Real derivative_q(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress,
                            const RankTwoTensor & sig, unsigned int qp, Real dt) const = 0;


  virtual std::string activeModelName(unsigned int qp) const = 0;

 protected:
  bool _has_T;
  const VariableValue & _T;
  Real _delta_param;
  Real computeExponentialTemperature(unsigned int qp, Real arrhenius) const;
};

#endif // REDBACKFLOWLAWBASE_H
