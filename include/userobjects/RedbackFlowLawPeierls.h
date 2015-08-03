#ifndef REDBACKFLOWLAWPEIERLS_H
#define REDBACKFLOWLAWPEIERLS_H

#include "RedbackFlowLaw.h"

class RedbackFlowLawPeierls;


template<>
InputParameters validParams<RedbackFlowLawPeierls>();

/**
 * Flow law for Peierl material (grain size sensitive dislocation creep)
 */
class RedbackFlowLawPeierls : public RedbackFlowLaw
{
public:
  RedbackFlowLawPeierls(const InputParameters & parameters);
  RedbackFlowLawPeierls(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  /**
   * Strain rate (and derivative w.r.t stress) as functions of stress, temperature, and grain size.
   */
  Real strainRate(Real /*sigma*/, Real /*T*/, Real /*delta*/, Real /*d*/) const;
  Real dStrainRatedSigma(Real /*sigma*/, Real /*T*/, Real /*delta*/, Real /*d*/) const;

protected:

  Real _A; // pre-exponential factor
  Real _Ar; // Arrhenius term Q/(RT_ref)
  Real _m; // exponent of (normalised) grain size
  Real _n; // exponent of (normalised) stress
  Real _Sigma_po; // constant in Peierls stress
  Real _K_p; // constant mutliplying grain size in Peierls stress
  Real _T_m; // reference temperature in Peierls stress
};

#endif // REDBACKFLOWLAWPEIERLS_H
