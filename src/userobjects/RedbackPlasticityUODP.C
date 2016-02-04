/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RedbackPlasticityUODP.h"

template<>
InputParameters validParams<RedbackPlasticityUODP>()
{
  InputParameters params = validParams<RedbackPlasticityUOBase>();

//debug
  params.addRequiredParam<Real>("slope_yield_surface", "Slope of yield surface (positive, see documentation)");
  // params.addParam<Real>("slope_yield_surface", 0, "Slope of yield surface (positive, see documentation)");
  params.addClassDescription("User object to store plasticity functions based on DP");
  return params;
}

RedbackPlasticityUODP::RedbackPlasticityUODP(const InputParameters & parameters) :
    RedbackPlasticityUOBase(parameters)
{
}

/**
 * Derivative of getFlowIncrement with respect to equivalent stress, only has deviatoric component in J2 plasiticity
 */
Real
RedbackPlasticityUODP::getDerivativeFlowIncrement(
  const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real q_yield_stress, Real p_yield_stress, Real dt, Real exponent, Real exponential, Real ref_pe_rate) const
{
  Real delta_lambda_p =
    ref_pe_rate * dt * std::pow(macaulayBracket(pressure - p_yield_stress), exponent) * exponential;
  Real delta_lambda_q =
    ref_pe_rate * dt *
    std::pow(macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)), exponent) *
    exponential;
  Real delta_lambda = (std::pow(delta_lambda_p * delta_lambda_p + delta_lambda_q * delta_lambda_q, 0.5));
  Real der_flow_incr_dev =
    ref_pe_rate * dt * exponent *
    std::pow(macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)), exponent - 1.0) *
    exponential / q_yield_stress;
  Real der_flow_incr_vol = ref_pe_rate * dt * exponent *
                           std::pow(macaulayBracket(pressure - p_yield_stress), exponent - 1.0) * exponential;
  return (delta_lambda_q * der_flow_incr_dev + delta_lambda_p * der_flow_incr_vol) / delta_lambda;
}

Real
RedbackPlasticityUODP::getFlowIncrement(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress, Real yield_stress, Real dt, Real exponent, Real exponential, Real ref_pe_rate) const
{
  Real flow_incr_vol =
    ref_pe_rate * dt * std::pow(macaulayBracket(pressure - p_yield_stress), exponent) * exponential;
  // TODO: q_yield_stress can be 0, we should handle that case properly...
  Real flow_incr_dev =
    ref_pe_rate * dt *
    std::pow(macaulayBracket((q_yield_stress > 0 ? 1 : -1) * (sig_eqv / q_yield_stress - 1.0)), exponent) *
    exponential;
  //(q_yield_stress > 0 ? 1:-1) is the sign function
  return std::pow(flow_incr_vol * flow_incr_vol + flow_incr_dev * flow_incr_dev, 0.5);
  // TODO: change the formula to use dist_pq^m
}

void
RedbackPlasticityUODP::getFlowTensor(
  const RankTwoTensor & sig, Real q, Real p, Real yield_stress, RankTwoTensor & flow_tensor) const
{
  RankTwoTensor sig_dev;
  Real val;

  sig_dev = sig.deviatoric();
  val = 0.0;
  if (q > 1e-8)
    val = 3.0 / (2.0 * q);
  flow_tensor = sig_dev * val;
  flow_tensor.addIa(-_slope_yield_surface * (p > 0 ? 1 : -1) / 3.0); //(p > 0 ? 1:-1) is the sign function
  flow_tensor /= std::pow(2.0 / 3.0, 0.5) * flow_tensor.L2norm();
  // flow_tensor /= std::pow(2.0/3.0,0.5)*flow_tensor.L2norm(); // TODO:
  // debugging, returning a tensor of norm sqrt(3/2) to match the J2 case
}




// Jacobian for stress update algorithm
void
RedbackPlasticityUODP::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real yield_stress,
                              RankFourTensor & dresid_dsig,
                              Real dt,
                              Real exponent,
                              Real exponential,
                              Real ref_pe_rate) const
{
  unsigned i, j, k, l;
  RankTwoTensor sig_dev, fij, flow_dirn;
  RankTwoTensor dfi_dft;
  RankFourTensor dft_dsig1, /*dft_dsig2,*/ dfd_dft, dfd_dsig, dfi_dsig;
  Real f1, f2, f3;
  Real dfi_dseqv_dev, dfi_dseqv_vol, dfi_dseqv;

  sig_dev = sig.deviatoric();

  dfi_dseqv = getDerivativeFlowIncrement(sig, pressure, sig_eqv, q_yield_stress, p_yield_stress, dt, exponent, exponential, ref_pe_rate);
  getFlowTensor(sig, sig_eqv, pressure, yield_stress, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the
   * residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times the flow
   * direction tensor
   *
   * The second is the product of the flow increment tensor times the derivative
   * of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) = flow_dirn(i, j) * flow_dirn(k, l) * dfi_dseqv;

  Real flow_tensor_norm = flow_dirn.L2norm();

  // This loop calculates the second term. Read REDBACK's documentation
  // (same as J2 plasticity case)
  f1 = 0.0;
  f2 = 0.0;
  f3 = 0.0;
  if (sig_eqv > 1e-8)
  {
    f1 = 3.0 / (2.0 * sig_eqv);
    f2 = f1 / 3.0;
    f3 = 9.0 / (4.0 * std::pow(sig_eqv, 3.0));
  }
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dft_dsig1(i, j, k, l) = f1 * deltaFunc(i, k) * deltaFunc(j, l) - f2 * deltaFunc(i, j) * deltaFunc(k, l) -
                                  f3 * sig_dev(i, j) * sig_dev(k, l); // d_flow_dirn/d_sig - 2nd part (J2 plasticity)
  // dft_dsig2(i,j,k,l) = flow_tensor(i,j)*flow_tensor(k,l);

  // dfd_dsig = dft_dsig1/flow_tensor_norm - 3.0 * dft_dsig2 /
  // (2*sig_eqv*flow_tensor_norm*flow_tensor_norm*flow_tensor_norm);
  // //d_flow_dirn/d_sig
  // TODO: check if the previous two lines (i.e normalizing the flow vector)
  // should be activated or not. Currently we are using the non-unitary flow
  // vector

  dfd_dsig = dft_dsig1;                                             // d_flow_dirn/d_sig
  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackPlasticityUODP::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress) const
{
  p_y = getPressureProjection(p /*p*/, q /*q*/, yield_stress /*yield stress*/);
  q_y = yield_stress + _slope_yield_surface * p_y; // yield deviatoric stress
}

Real
RedbackPlasticityUODP::getPressureProjection(Real pressure, Real sig_eqv, Real cohesion) const
{
  // yield pressure, for non-associative, replace mu^2 with mu*dilatency
  // the "fmin" is to handle the apex. Apparently fmin(1/0, x) = x, so it's
  // always true
  // return fmin(-cohesion/_slope_yield_surface, (pressure +
  // _slope_yield_surface*(sig_eqv - cohesion))
  //    / (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));

  if (_slope_yield_surface == 0)
    return pressure;
  else if (_slope_yield_surface < 0)
    return fmin(-cohesion / _slope_yield_surface,
                (pressure + _slope_yield_surface * (sig_eqv - cohesion)) /
                  (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  else
  {
    // _slope_yield_surface > 0, for whatever reason...
    return fmax(-cohesion / _slope_yield_surface,
                (pressure + _slope_yield_surface * (sig_eqv - cohesion)) /
                  (1.0 + (_slope_yield_surface) * (_slope_yield_surface)));
  }
}

void
RedbackPlasticityUODP::form_damage_kernels(
  DamageMethod damage_method,
  VariableValue & damage,
  Real cohesion,
  Real damage_coeff,
  MaterialProperty<Real> & damage_kernel,
  MaterialProperty<Real> & damage_kernel_jac,
  MaterialProperty<Real> & mises_stress,
  MaterialProperty<Real> & mises_strain_rate,
  unsigned int qp) const
{
  // update damage evolution law from selected method
  // switch (damage_method)
  // {
  //   case BrittleDamage:
  //     //signatures are not working yet
  //     formBrittleDamage(damage, cohesion, damage_coeff, damage_kernel, damage_kernel_jac, mises_stress, mises_strain_rate, qp);
  //     break;
  //   case CreepDamage:
  //     formCreepDamage(damage, cohesion, damage_coeff, damage_kernel, damage_kernel_jac, mises_stress, mises_strain_rate, qp);
  //     break;
  //   case BreakageMechanics:
  //     mooseError("damage method not implemented yet, use other options");
  //     break;
  //   case DamageHealing:
  //     mooseError("damage method not implemented yet, use other options");
  //     break;
  //   default:
  //     mooseError("damage method not implemented yet, use other options");
  // }
}

//placeholder; currently nonworking
void
RedbackPlasticityUODP::formBrittleDamage(
  VariableValue & damage,
  Real cohesion,
  Real damage_coeff,
  MaterialProperty<Real> & damage_kernel,
  MaterialProperty<Real> & damage_kernel_jac,
  MaterialProperty<Real> & mises_stress,
  MaterialProperty<Real> & mises_strain_rate,
  unsigned int qp) const
{
  Real plastic_damage, healing_damage;
  Real kachanov, exponent_kachanov;

  // Kachanov's original law of Brittle Damage
  exponent_kachanov = 1;
  kachanov = mises_stress[qp] / (1 - damage[qp]);

  plastic_damage = damage_coeff * std::pow(kachanov, exponent_kachanov);
  healing_damage = 0;

  damage_kernel[qp] = plastic_damage + healing_damage;
  damage_kernel_jac[qp] = 0;
}

//placeholder; currently nonworking
void
RedbackPlasticityUODP::formCreepDamage(
  VariableValue & damage,
  Real cohesion,
  Real damage_coeff,
  MaterialProperty<Real> & damage_kernel,
  MaterialProperty<Real> & damage_kernel_jac,
  MaterialProperty<Real> & mises_stress,
  MaterialProperty<Real> & mises_strain_rate,
  unsigned int qp) const
{
  Real plastic_damage, healing_damage;
  Real lambda_dot;
  Real d_yield_dq; // The derivative of the yield surface with respect to the
                   // deviatoric stress q

  // Damage evolution law for creep damage
  // J2 plastic potential with evolving cohesion for the damage evolution law
  // (remember that cohesion is q_y which is updated as q_y * (1-D) in the
  // get_py_qy_damaged function)
  d_yield_dq = 1 / std::pow(cohesion, 2);

  if (d_yield_dq > 0) // ensuring positiveness of the plastic multiplier
  {
    /* the plastic multiplier could be having this form:
     * lambda_dot = _mises_stress[_qp] * _mises_strain_rate[_qp] / d_yield_dq;
     * but cohesion in J2 plasticity is the mises stress at yield, so we are
     * going with a much simpler form: */
    lambda_dot = mises_strain_rate[qp] / d_yield_dq;
  }
  else
    lambda_dot = 0;

  plastic_damage = damage_coeff * lambda_dot;
  healing_damage = 0;
  damage_kernel[qp] = plastic_damage + healing_damage;
  damage_kernel_jac[qp] = 0;
}
