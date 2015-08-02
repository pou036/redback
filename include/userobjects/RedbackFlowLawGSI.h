#ifndef REDBACKFLOWLAWGSI_H
#define REDBACKFLOWLAWGSI_H

#include "RedbackFlowLaw.h"

class RedbackFlowLawGSI;


template<>
InputParameters validParams<RedbackFlowLawGSI>();

/**
 * Flow law for grain insensitive material
 */
class RedbackFlowLawGSI : public RedbackFlowLaw
{
public:
  RedbackFlowLawGSI(const InputParameters parameters);
  RedbackFlowLawGSI(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  /**
   * Strain rate (and derivative w.r.t stress) as functions of stress and temperature.
   */
  Real strainRate(Real /*sigma*/, Real /*T*/, Real /*delta*/, Real /*d*/) const;
  Real dStrainRatedSigma(Real /*sigma*/, Real /*T*/, Real /*delta*/, Real /*d*/) const;

protected:

  Real _A; // pre-exponential factor
  Real _Ar; // Arrhenius term Q/(RT_ref)
  Real _n; // exponent of (normalised) stress
};

#endif // REDBACKFLOWLAWGSI_H
