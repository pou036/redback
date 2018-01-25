#ifndef REDBACKFLOWLAWDIFFUSION_H
#define REDBACKFLOWLAWDIFFUSION_H

#include "RedbackFlowLawBase.h"
#include "RankTwoTensor.h"

class RedbackFlowLawDiffusion;


template<>
InputParameters validParams<RedbackFlowLawDiffusion>();

/**
 * Redback user objects class for diffusion flow law
 */
class RedbackFlowLawDiffusion : public RedbackFlowLawBase
{
 public:
  RedbackFlowLawDiffusion(const InputParameters & parameters);

  /**
   * The value of strain rate given by the flow law, accounting for deviatoric and volumetric parts.
   * @param sig_eqv the Mises stress
   * @param pressure
   * @param q_yield_stress, deviatoric component of yield stress
   * @param p_yield_stress, volumetric component of yield stress
   * @param yield_stress
   * @param qp, quadrature point index
   * @param dt, time step
   * @return the strain rate
   */
  virtual Real value(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress,
                     Real yield_stress, unsigned int qp, Real dt) const;

  /**
   * The value of the derivative of thestrain rate given by the flow law, accounting for deviatoric and volumetric parts.
   * @param sig_eqv the Mises stress
   * @param pressure
   * @param q_yield_stress, deviatoric component of yield stress
   * @param p_yield_stress, volumetric component of yield stress
   * @param yield_stress
   * @param qp, quadrature point index
   * @param dt, time step
   * @return the derivative of strain rate with respect to stress
   */
  virtual Real derivative(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress,
                          const RankTwoTensor & sig, unsigned int qp, Real dt) const;

  virtual std::string activeModelName(unsigned int /*qp*/) const {return "Redback_flow_law_diffusion";};

 protected:
  bool _has_grain_size;
  const VariableValue & _grain_size;
  Real _pre_exponential_factor, _exponent, _grain_size_exponent, _arrhenius;
};

/*
 * * @param stress the stress at which to calculate the yield function
   * @param intnl internal parameter
   * @return the yield function

 */
#endif // REDBACKFLOWLAWDIFFUSION_H
