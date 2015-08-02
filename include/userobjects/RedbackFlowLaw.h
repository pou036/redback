#ifndef REDBACKFLOWLAW_H
#define REDBACKFLOWLAW_H

#include "GeneralUserObject.h"

class RedbackFlowLaw;


template<>
InputParameters validParams<RedbackFlowLaw>();

/**
 * Base class for material flow laws as functions of
 * stress, temperature, and grain size.
 * The functions strainRate and dStrainRatedSigma must be
 * over-ridden in derived classes to provide actual values
 */
class RedbackFlowLaw : public GeneralUserObject
{
public:
  RedbackFlowLaw(const InputParameters parameters);
  RedbackFlowLaw(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  void initialize();
  void execute();
  void finalize();

  /**
   * Strain rate as a function of stress, temperature, and grain size.
   * This must be over-ridden in derived classes to provide an actual value
   * @param sigma stress
   * @param T temperature
   * @param delta normalisation parameter for temperature T* = (T-T_ref)/(delta*T_ref)
   * @param d grain size
   */
  virtual Real strainRate(Real sigma, Real T, Real delta, Real d) const = 0;

  /**
   * Derivative of strain rate with respect to stress
   * as a function of stress, temperature, and grain size.
   * This must be over-ridden in derived classes to provide an actual value
   * @param sigma stress
   * @param T temperature
   * @param delta normalisation parameter for temperature T* = (T-T_ref)/(delta*T_ref)
   * @param d grain size
   */
  virtual Real dStrainRatedSigma(Real sigma, Real T, Real delta, Real d) const = 0;

};

#endif // REDBACKFLOWLAW_H
