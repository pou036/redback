#ifndef REDBACKFLOWLAWSINSERIES_H
#define REDBACKFLOWLAWSINSERIES_H

#include "RedbackFlowLawBase.h"

class RedbackFlowLawsInSeries;


template<>
InputParameters validParams<RedbackFlowLawsInSeries>();

/**
 * Redback user objects class for adding flow laws in series (Maxwell)
 */
class RedbackFlowLawsInSeries : public RedbackFlowLawBase
{
 public:
  RedbackFlowLawsInSeries(const InputParameters & parameters);

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

  virtual std::string activeModelName(unsigned int qp) const {return "Redback_flow_laws_in_series";};

 protected:
  std::vector<const RedbackFlowLawBase *> _flow_laws_uo;
  unsigned int _num_flow_law_uos;
};

/*
 * * @param stress the stress at which to calculate the yield function
   * @param intnl internal parameter
   * @return the yield function

 */
#endif // REDBACKFLOWLAWSINSERIES_H
