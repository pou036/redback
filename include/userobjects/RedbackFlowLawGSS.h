#ifndef REDBACKFLOWLAWGSS_H
#define REDBACKFLOWLAWGSS_H

#include "RedbackFlowLaw.h"

class RedbackFlowLawGSS;


template<>
InputParameters validParams<RedbackFlowLawGSS>();

/**
 * Flow law for grain sensitive material
 */
class RedbackFlowLawGSS : public RedbackFlowLaw
{
public:
  RedbackFlowLawGSS(const InputParameters parameters);
  RedbackFlowLawGSS(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  /**
   * Strain rate as a function of stress, temperature, and grain size.
   */
  Real strainRate(Real /*sigma*/, Real /*T*/, Real /*delta*/, Real /*d*/) const;

protected:

  Real _A; // pre-exponential factor
  Real _Ar; // Arrhenius term Q/(RT_ref)
  Real _m; // exponent of (normalised) grain size
  Real _n; // exponent of (normalised) stress
};

#endif // REDBACKFLOWLAWGSS_H
