#ifndef REDBACKGRAINSIZEAUX_H
#define REDBACKGRAINSIZEAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"
#include "RedbackFlowLawDislocation.h"
#include "RedbackFlowLawPeierlsDislocation.h"

// Forward declarations
class RedbackGrainSizeAux;

template <>
InputParameters validParams<RedbackGrainSizeAux>();

class RedbackGrainSizeAux : public AuxKernel
{
public:
  RedbackGrainSizeAux(const InputParameters & parameters);
  virtual ~RedbackGrainSizeAux()
  {
  }

protected:
  virtual Real computeValue();

private:
  bool _has_T;
  const VariableValue & _T;
  //const VariableValue & _initial_grain_size;
  const RedbackFlowLawDislocation & _flow_law_dis_uo;
  const RedbackFlowLawPeierlsDislocation & _flow_law_peierls_uo;

  const MaterialProperty<Real> & _mises_stress;
  const MaterialProperty<Real> & _mises_strain_rate;
  const MaterialProperty<Real> & _strain_rate_dis;
  const MaterialProperty<Real> & _strain_rate_peirels;

  Real _delta_param;
  Real _ar_growth_param, _growth_exponent_param, _steady_state_constant_param, _pre_exp_factor_growth;
  Real _pre_exp_factor_reduction;
  Real _A_star_ss_param;
};

#endif // REDBACKGRAINSIZEAUX_H
