/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Bezier.h"
#include "RedbackMechMaterialBezier.h"
#include <cmath> //used for fabs

template <>
InputParameters
validParams<RedbackMechMaterialBezier>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  // p_c obtained from yield stress
  params.addParam<Real>("p_t", 0, "tensile strength (normalised, negative in tension, even though the code works with the other convention)");
  params.addParam<Real>("p_M", 0, "p' value of Max point joining 2 Bezier curves (normalised, positive in compression, even though the code works with the other convention)");
  params.addParam<Real>("q_M", 0, "q value of Max point joining 2 Bezier curves (normalised)");
  params.addParam<Real>("p_H", 0, "p' value of centre of homothetic transformation (normalised, positive in compression, even though the code works with the other convention)");
  params.addParam<Real>("q_H", 0, "q value of centre of homothetic transformation (normalised)");
  params.addParam<Real>("coeff_vertical_compression", 1, " multiplying factor (positive less than 1.835924) for vertical tangent at compression cap");
  params.addParam<Real>("coeff_horizontal_compression", 1, "multiplying factor (positive less than 1.835924) for horizontal tangent at Max point on compression side");
  params.addParam<Real>("coeff_vertical_tension", 1, " multiplying factor (positive less than 1.835924) for vertical tangent at tension cap");
  params.addParam<Real>("coeff_horizontal_tension", 1, "multiplying factor (positive less than 1.835924) for horizontal tangent at Max point on tension side");
  return params;
}

RedbackMechMaterialBezier::RedbackMechMaterialBezier(const InputParameters & parameters)
  : RedbackMechMaterial(parameters),
    _p_t(-getParam<Real>("p_t")), // p_t positive in tension
    _p_M(-getParam<Real>("p_M")), // p_M positive in tension
    _q_M(getParam<Real>("q_M")),
    _p_H(-getParam<Real>("p_H")), // p_M positive in tension
    _q_H(getParam<Real>("q_H")),
    _coeff_c_vert(getParam<Real>("coeff_vertical_compression")),
    _coeff_c_hor(getParam<Real>("coeff_horizontal_compression")),
    _coeff_t_vert(getParam<Real>("coeff_vertical_tension")),
    _coeff_t_hor(getParam<Real>("coeff_horizontal_tension"))
{
  std::vector<Real> yield_stress_vector = getParam<std::vector<Real>>("yield_stress");
  Real p_c = -yield_stress_vector[1];
  if (p_c > _p_t)
     mooseError("RedbackMechMaterialBezier: p_t must be smaller than yield stress (p_c)");
  if (_p_M < p_c || _p_M > _p_t)
     mooseError("RedbackMechMaterialBezier: p_M must be between p_c and p_t");
  if (_q_M < 0)
    mooseError("RedbackMechMaterialBezier needs positive q_M");
  if (_q_H != 0)
     mooseError("RedbackMechMaterialBezier: case q_H != 0  not implemented yet");
  if (_p_H < p_c || _p_H > _p_t)
     mooseError("RedbackMechMaterialBezier: case p_H < 0 or p_H > p_t not implemented yet");
  // All coefficients need to be between 0 and 1/magic_number
  Real _magic_nb = 0.5446848561107274; // coefficient to match ellipse, TODO: use static value from Bezier class
  Real inv_magic_nb = 1.0 / _magic_nb;
  if (_coeff_c_vert <= 0 || _coeff_c_vert > inv_magic_nb)
    mooseError("RedbackMechMaterialBezier: coeff_vertical_compression must strictly positive and smaller than ", inv_magic_nb);
  if (_coeff_c_hor <= 0 || _coeff_c_hor > inv_magic_nb)
    mooseError("RedbackMechMaterialBezier: coeff_horizontal_compression must strictly positive and smaller than ", inv_magic_nb);
  if (_coeff_t_vert <= 0 || _coeff_t_vert > inv_magic_nb)
    mooseError("RedbackMechMaterialBezier: coeff_vertical_tension must strictly positive and smaller than ", inv_magic_nb);
  if (_coeff_t_hor <= 0 || _coeff_t_hor > inv_magic_nb)
    mooseError("coeff_horizontal_tension: coeff_vertical_compression must strictly positive and smaller than ", inv_magic_nb);
  _last_p = std::numeric_limits<Real>::infinity();
  _last_q = std::numeric_limits<Real>::infinity();
}

/**
 * Get flow tensor n = d_potential / d_sigma_ij
 */
void
RedbackMechMaterialBezier::getFlowTensor(const RankTwoTensor & sig,
                                         Real q,
                                         Real p,
                                         Real /*q_y*/,
                                         Real /*p_y*/,
                                         Real yield_stress,
                                         RankTwoTensor & flow_tensor)
{
  RankTwoTensor sig_dev;
  Real val;

  // Check first if we have already called Bezier functions
  if (p != _last_p || q != _last_q)
  {
    Real p_c = -yield_stress;
    Bezier::getOverstress(_p_H, _q_H, _p_M, _q_M, _p_t, p_c, _coeff_c_hor,
        _coeff_c_vert, _coeff_t_hor, _coeff_t_vert, p, q, _last_is_plastic,
        _last_s, _last_p_y, _last_q_y, _last_quadrant, _last_t);
    Bezier::getDerivativeOverstress(_p_H, _q_H, _p_M, _q_M, _p_t, p_c,
        _coeff_c_hor, _coeff_c_vert, _coeff_t_hor, _coeff_t_vert, p, q,
        _last_is_plastic, _last_s, _last_p_y, _last_q_y, _last_quadrant,
        _last_t, _last_derivatives);
    _last_p = p;
    _last_q = q;
  }

  if (!_last_is_plastic)
  {
    flow_tensor.zero();
    return;
  }
  // In plasticity, compute proper flow direction tensor
  sig_dev = sig.deviatoric();
  val = 0.;
  if (q > 1e-10)
    val = _last_derivatives[1] * 3. / (2. * q);
  flow_tensor = sig_dev * val;
  flow_tensor.addIa(_last_derivatives[0]/3.);
  // Normalise flow tensor
  flow_tensor /= flow_tensor.L2norm();
}

/**
 * Compute the flow increment for Bezier model
 */
Real
RedbackMechMaterialBezier::getFlowIncrement(Real /*sig_eqv*/,
                                            Real /*pressure*/,
                                            Real /*q_yield_stress*/,
                                            Real /*p_yield_stress*/,
                                            Real /*yield_stress*/,
                                            Real s)
{
  return _ref_pe_rate * _dt * std::pow(s, _exponent) * _exponential;
}

void
RedbackMechMaterialBezier::getJac(const RankTwoTensor & sig,
                               const RankFourTensor & E_ijkl,
                               Real flow_incr,
                               Real sig_eqv,
                               Real pressure,
                               Real p_yield_stress,
                               Real q_yield_stress,
                               Real yield_stress,
                               Real s,
                               RankFourTensor & dresid_dsig)
{
  if (s == 0)
  {
    dresid_dsig = E_ijkl.invSymm();
    return;
  }

  unsigned i, j, k, l;
  RankTwoTensor sig_dev, flow_dirn_vol, flow_dirn_dev, fij, flow_dirn,
    flow_tensor, dfi_dft;
  RankFourTensor dfd_dsig, dfi_dsig;
  Real f0, f1, f2, f3, f4;
  Real dfi_dp, dfi_dseqv, dfi_ds;

  sig_dev = sig.deviatoric();

  getFlowTensor(sig, sig_eqv, pressure, q_yield_stress, p_yield_stress,
    yield_stress, flow_dirn);

  /* The following calculates the tensorial derivative (Jacobian) of the
   * residual with respect to stress, dr_dsig
   * It consists of two terms: The first is
   * dr_dsig = (dfi_dseqv_dev*flow_dirn_dev(k,l)) * flow_dirn_dev(i,j)
   * which is the tensorial product of the flow increment tensor times
   * the flow direction tensor
   *
   * The second is the product of the flow increment tensor times the
   * derivative of the flow direction tensor
   * with respect to the stress tensor. See also REDBACK's documentation
   * */

  // derivative of flow increment with respect to s (overstress)
  dfi_ds = _exponent * _ref_pe_rate * _dt * std::pow(s, _exponent - 1)
    * _exponential;

  // derivatives of flow increment with respect to p and q
  dfi_dp = dfi_ds * _last_derivatives[0];
  dfi_dseqv = dfi_ds * sig_eqv / s * _last_derivatives[1];

  f0 = 0.0;
  if (sig_eqv > 1e-10)
    f0 = 3.0 / (2.0 * sig_eqv);

  // This loop calculates the first term
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfi_dsig(i, j, k, l) =
              flow_dirn(i, j) * (f0 * sig_dev(k, l) * dfi_dseqv + dfi_dp * deltaFunc(k, l) / 3.0);

  f2 = f0 * _last_derivatives[1];
  f1 = _last_derivatives[2]/9 - f2/3.;
  f3 = _last_derivatives[4] * f0/3.;
  f4 = std::pow(f0, 2) * (_last_derivatives[3] - (2*f0/3.) * _last_derivatives[1]);

  // This loop calculates the second term (d n_ij / d sigma_kl)
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      for (k = 0; k < 3; ++k)
        for (l = 0; l < 3; ++l)
          dfd_dsig(i, j, k, l) = f1 * deltaFunc(i, j) * deltaFunc(k, l)
                               + f2 * deltaFunc(i, k) * deltaFunc(j, l)
                               + f3 * deltaFunc(i, j) * sig_dev(k, l)
                               + f3 * sig_dev(i, j) * deltaFunc(k, l)
                               + f4 * sig_dev(i, j) * sig_dev(k, l);

  dresid_dsig = E_ijkl.invSymm() + dfd_dsig * flow_incr + dfi_dsig; // Jacobian
}

void
RedbackMechMaterialBezier::get_py_qy(
    Real p, Real q, Real & p_y, Real & q_y, Real yield_stress,
    bool & is_plastic, Real & s)
{
  Real p_c = -yield_stress;
  Bezier::getOverstress(_p_H, _q_H, _p_M, _q_M, _p_t, p_c, _coeff_c_hor,
    _coeff_c_vert, _coeff_t_hor, _coeff_t_vert, p, q, is_plastic, s,
    p_y, p_y, _quadrant, _t);
  _last_p = p;
  _last_q = q;
  _last_is_plastic = is_plastic;
  _last_s = s;
  _last_p_y = p_y;
  _last_q_y = q_y;
  _last_quadrant = _quadrant;
  _last_t = _t;
  Bezier::getDerivativeOverstress(_p_H, _q_H, _p_M, _q_M, _p_t, p_c,
    _coeff_c_hor, _coeff_c_vert, _coeff_t_hor, _coeff_t_vert, p, q,
    _last_is_plastic, _last_s, _last_p_y, _last_q_y, _last_quadrant,
    _last_t, _last_derivatives);
}

void RedbackMechMaterialBezier::form_damage_kernels(Real /*q_y*/) {}
