/**
 * Utilities to compute overstress for Bezier yield envelope
 */

#ifndef BEZIER_H
#define BEZIER_H

#include "GeneralUserObject.h"

class Bezier
{
public:
  Bezier();

  /**
   * Function to get root of cubic equation a*t^3 + b*t^2 + c*t + d = 0
   * which is between 0 and 1 (for our problem)
   * @param a: coefficient of 3rd order polynomial
   * @param b: coefficient of 2nd order polynomial
   * @param c: coefficient of 1st order polynomial
   * @param d: constant
   */
  static Real getRootOfCubicEquation(Real a, Real b, Real c, Real d);

  /**
   * Function to compute overstress for Bezier yield envelope
   * @param p_H: p' coordinate of centre point of homothetic transformation
   * @param q_H: q coordinate of centre point of homothetic transformation
   * @param p_M: p' coordinate of maximum point (connecting Bezier quadrants)
   * @param q_M: q coordinate of maximum point (connecting Bezier quadrants)
   * @param p_t: tensile strength
   * @param p_c: isotropic compression strength
   * @param alpha_c: coefficient for horizontal tangent on compactant side
   * @param beta_c: coefficient for vertical tangent on compactant side
   * @param alpha_t: coefficient for horizontal tangent on tension (dilatant) side
   * @param beta_t: coefficient for vertical tangent on tension (dilatant) side
   * @param p: p' coordinate of point to project
   * @param q: q coordinate of point to project
   * @param is_plastic: boolean to state if point (p',q) is in plasticity
   * @param s: overstress (if in plasticity)
   * @param p_y: p coordinate of "projection" (yield) point on the ellipse. Only set if is_plastic
   * @param q_y: q coordinate of "projection" (yield) point on the ellipse. Only set if is_plastic
   * @param quadrant: 1 for compactant, 2 for dilatant (if in plasticity), 0 in between. Only set if is_plastic
   * @param t: parametric t of yield point on given quadrant.Only set if is_plastic
   */
   static void getOverstress(Real const p_H,
                             Real const q_H,
                             Real const p_M,
                             Real const q_M,
                             Real const p_t,
                             Real const p_c,
                             Real const alpha_c,
                             Real const beta_c,
                             Real const alpha_t,
                             Real const beta_t,
                             Real const p,
                             Real const q,
                             bool & is_plastic,
                             Real & s,
                             Real & p_y,
                             Real & q_y,
                             int & quadrant,
                             Real & t);

   /**
    * Function to compute derivatives of overstress w.r.t p and q.
    * @param p_H: p' coordinate of centre point of homothetic transformation
    * @param q_H: q coordinate of centre point of homothetic transformation
    * @param p_M: p' coordinate of maximum point (connecting Bezier quadrants)
    * @param q_M: q coordinate of maximum point (connecting Bezier quadrants)
    * @param p_t: tensile strength
    * @param p_c: isotropic compression strength
    * @param alpha_c: coefficient for horizontal tangent on compactant side
    * @param beta_c: coefficient for vertical tangent on compactant side
    * @param alpha_t: coefficient for horizontal tangent on tension (dilatant) side
    * @param beta_t: coefficient for vertical tangent on tension (dilatant) side
    * @param p: p' coordinate of point to project
    * @param q: q coordinate of point to project
    * @param is_plastic: boolean to state if point (p',q) is in plasticity
    * @param s: overstress (if in plasticity)
    * @param p_y: p coordinate of "projection" (yield) point on the ellipse. Only set if is_plastic
    * @param q_y: q coordinate of "projection" (yield) point on the ellipse. Only set if is_plastic
    * @param quadrant: 1 for compactant, 2 for dilatant (if in plasticity), 0 in between. Only set if is_plastic
    * @param t: parametric t of yield point on given quadrant.Only set if is_plastic
    * @param derivatives: array[ds_dp, ds_dq] of derivatives of overstress w.r.t p and q
    */
   static void getDerivativeOverstress(Real const p_H,
                                       Real const q_H,
                                       Real const p_M,
                                       Real const q_M,
                                       Real const p_t,
                                       Real const p_c,
                                       Real const alpha_c,
                                       Real const beta_c,
                                       Real const alpha_t,
                                       Real const beta_t,
                                       Real const p,
                                       Real const q,
                                       bool const is_plastic,
                                       Real const s,
                                       Real const p_y,
                                       Real const q_y,
                                       int const quadrant,
                                       Real const t,
                                       Real derivatives[2]);

  //static constexpr Real _magic_nb = 0.5446848561107274; // coefficient to match ellipse
  //static constexpr Real _inv_magic_nb = 1./_magic_nb;
  //static constexpr std::complex<Real> _i_nb = std::complex<Real>(0, 1); // imaginary number "i"
};
#endif // BEZIER_H

