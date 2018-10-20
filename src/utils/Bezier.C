/**
 * Utilities to compute overstress for Bezier yield envelope
 */

#include <cmath>
#include <complex>
#include "Bezier.h"

Bezier::Bezier() {}

/* Get derivatives of overstress for point R(p,q) w.r.t p and q
 * with all parameters as defined in getOverstress()
 */
void
Bezier::getDerivativeOverstress(Real const p_H,
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
                                Real const /*p_y*/,
                                Real const /*q_y*/,
                                int const quadrant,
                                Real const t,
                                Real derivatives[2])
{
  // Elastic case
  if (!is_plastic)
  {
    derivatives[0] = 0;
    derivatives[1] = 0;
    derivatives[2] = 0;
    derivatives[3] = 0;
    derivatives[4] = 0;
    return;
  }
  // Now, in plasticity
  Real _magic_nb = 0.5446848561107274; // TODO: define once (static)
  Real p_prime_y, q_prime_y, p_second_y, q_second_y, tmp;
  if (quadrant == 1)
  {
    // In contractant regime
    p_prime_y = -3*t*(p_c - p_M)*(2*(1-t) + (3*t - 2)*_magic_nb*alpha_c);
    q_prime_y = 3*(t - 1)*q_M*((3*t-1)*_magic_nb*beta_c - 2*t);
    p_second_y = -6*(p_c - p_M)*(1 - 2*t + (3*t - 1)*_magic_nb*alpha_c);
    q_second_y = 6*q_M*(1 - 2*t + (3*t-2)*_magic_nb*beta_c);
  }
  else if (quadrant == 2)
  {
    // In dilatant regime
    p_prime_y = 3*(1 - t)*(p_M - p_t)*((3*t - 1)*_magic_nb*alpha_t - 2*t);
    q_prime_y = 3*t*q_M*(2*(t - 1) + (2 - 3*t)*_magic_nb*beta_t);
    p_second_y = -6*(p_M - p_t)*(1 - 2*t + (3*t - 2)*_magic_nb*alpha_t);
    q_second_y = -6*q_M*(1 - 2*t + (3*t - 1)*_magic_nb*beta_t);
  }
  else
  {
    if (quadrant != 0)
      mooseError("Wrong quadrant (", quadrant, " is neither 0,1,2) provided to getDerivativeOverstress");
    p_prime_y = -3*(p_M - p_t)*_magic_nb*alpha_t;
    q_prime_y = 0;
    p_second_y = -6*(p_M - p_t)*(1 - 2*_magic_nb*alpha_t);
    q_second_y = -6*q_M*(1 - _magic_nb*beta_t);
  }
  tmp = p_prime_y*(q_H - q) - q_prime_y*(p_H - p);
  derivatives[0] = (1+s)*q_prime_y/tmp;
  derivatives[1] = -(1+s)*p_prime_y/tmp;
  tmp = (p_prime_y*q_second_y - q_prime_y*p_second_y) / std::pow(tmp, 3);
  derivatives[2] = std::pow(q_H - q, 2) * tmp;
  derivatives[3] = std::pow(p_H - p, 2) * tmp;
  derivatives[4] = -(p_H - p) * (q_H - q) * tmp;
}

/* Get overstress for point R(p,q)
 * with all parameters as defined in documentation
 */
void
Bezier::getOverstress(Real const p_H,
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
                      Real & t)
{
  Real test;
  Real _magic_nb = 0.5446848561107274; // coefficient to match ellipse

  // Check on which quadrant the line (HR) intersects
  test = (p_M-p_H)*(q-q_H) - (q_M-q_H)*(p-p_H); // pos=compactant, neg=dilatant
  if (test == 0)
  {
    // Case (HM)//(HR), i.e. intersecting yield envelope where both quadrants join
    Real HM_square = std::pow(p_M-p_H, 2) + std::pow(q_M-q_H, 2);
    Real HR_square = std::pow(p-p_H, 2) + std::pow(q-q_H, 2);
    if (HR_square > HM_square)
    {
      is_plastic = true;
      s = std::sqrt(HR_square)/std::sqrt(HM_square) - 1;
      quadrant = 0;
      t = 0;
      p_y = p_M;
      q_y = q_M;
    }
    else
    {
      is_plastic = false;
      s = 0;
    }
  }
  else if (test > 0)
  {
    // Intersecting in the compactant quadrant
    // First, check easy case of elasticity (R below line (CM))
    test = (p_M-p)*q_M - (q_M-q)*(p_M-p_c);
    if (test < 0)
    {
      // elasticity for sure
      is_plastic = false;
      s = 0;
      return;
    }
    // Now we need to compute the yield point to check if plasticity or not
    // First, get corresponding t
    Real x = p - p_H;
    Real y = q - q_H;
    Real a = 2*x*q_M - (p_c-p_M)*y*(3*_magic_nb*alpha_c-2) - 3*_magic_nb*x*q_M*beta_c;
    Real b = -3*x*q_M + 3*(p_c-p_M)*y*(_magic_nb*alpha_c-1)+6*_magic_nb*x*q_M*beta_c;
    Real c = -3*_magic_nb*x*q_M*beta_c;
    Real d = p*q_H - p_H*q + p_c*y;
    t = getRootOfCubicEquation(a,b,c,d);
    // Get yield point from t
    p_y = std::pow(t, 2)*p_M*(3*_magic_nb*(t-1)*alpha_c - 2*t + 3) - (t-1)*p_c*(3*_magic_nb*std::pow(t, 2)*alpha_c - 2*std::pow(t, 2) + t + 1);
    q_y = t*q_M*(3*_magic_nb*std::pow(t-1, 2)*beta_c + t*(3-2*t));
    // Check plasticity
    Real HY_square = std::pow(p_y-p_H, 2) + std::pow(q_y-q_H, 2);
    Real HR_square = std::pow(p-p_H, 2) + std::pow(q-q_H, 2);
    if (HR_square > HY_square)
    {
      is_plastic = true;
      Real RY = std::sqrt(std::pow(p-p_y, 2) + std::pow(q-q_y, 2));
      s = RY/std::sqrt(HY_square);
      quadrant = 1;
    }
    else
    {
      is_plastic = false;
      s = 0;
    }
  }
  else
  {
    // Intersecting in the dilatant regime
    // First, check easy case of elasticity
    test = (p_t-p_M)*(q-q_M) + q_M*(p-p_M);
    if (test < 0)
    {
      // elasticity for sure
      is_plastic = false;
      s = 0;
      return;
    }
    // Now we need to compute the yield point to check if plasticity or not
    // First, get corresponding t
    Real x = p - p_H;
    Real y = q - q_H;
    Real z = p_M - p_t;
    Real a = -2*x*q_M - z*y*(-2+3*_magic_nb*alpha_t) + 3*_magic_nb*x*q_M*beta_t;
    Real b = 3*(x*q_M + z*y*(-1+2*_magic_nb*alpha_t) - _magic_nb*x*q_M*beta_t);
    Real c = -3*_magic_nb*z*y*alpha_t;
    Real d = p*(q_H-q_M) + p_H*(q_M-q) + p_M*y;
    t = getRootOfCubicEquation(a,b,c,d);
    // Get yield point from t
    p_y = std::pow(1-t, 3)*p_M + 3*t*std::pow(1-t, 2) *(p_M+alpha_t*_magic_nb*(p_t-p_M)) + 3*std::pow(t, 2) *(1-t)*p_t + std::pow(t, 3)*p_t;
    q_y = std::pow(1-t, 3)*q_M + 3*t*std::pow(1-t, 2) *q_M + 3*std::pow(t, 2)*(1-t)*beta_t*_magic_nb*q_M;
    // Check plasticity
    Real HY_square = std::pow(p_y-p_H, 2) + std::pow(q_y-q_H, 2);
    Real HR_square = std::pow(p-p_H, 2) + std::pow(q-q_H, 2);
    if (HR_square > HY_square)
    {
      is_plastic = true;
      Real RY = std::sqrt(std::pow(p-p_y, 2) + std::pow(q-q_y, 2));
      s = RY/std::sqrt(HY_square);
      quadrant = 2;
    }
    else
    {
      is_plastic = false;
      s = 0;
    }
  }
}

/*
 * Get the only time between 0 and 1 of cubic equation
 * defined by a*t^3 + b*t^2 + c*t + d = 0
 */
Real
Bezier::getRootOfCubicEquation(Real a, Real b, Real c, Real d)
{
  Real t;
  // TODO: optimise (a=1), compare with https://www.particleincell.com/2013/cubic-line-intersection/
  Real Delta_0 = std::pow(b, 2) - 3*a*c;
  Real Delta_1 = 2*std::pow(b, 3) - 9*a*b*c + 27*std::pow(a, 2)*d;
  Real Delta_mod = std::pow(Delta_1, 2) - 4*std::pow(Delta_0, 3); // delta/(-27*a^2)
  if (Delta_mod > 0)
  {
    // Single real root
    Real argument = (Delta_1 + std::sqrt(Delta_mod))/2;
    if (argument > 0)
    {
      Real C = std::pow(argument, 1./3);
      t = -1./(3*a) * (b + C + Delta_0/C);
      if (t < 0 || t> 1)
          mooseError("Root of cubic equation is outside [0,1]: ", t);
    }
    else
    {
      t = 1;
    }
  }
  else
  {
    // 3 distinct real roots or multiple roots
    std::complex<Real> _i_nb = std::complex<Real>(0, 1);
    std::complex<Real> C = std::pow((Delta_1 + std::sqrt(-Delta_mod)*_i_nb)/2., 1./3.);
    Real t_0 = real(-1./(3*a) * (b + C + Delta_0/C));
    Real t_1 = real(-1./(3*a) * (b + 0.5*(-1.+std::sqrt(3)*_i_nb)*C + 2*Delta_0/(C*(-1.+std::sqrt(3)*_i_nb))));
    Real t_2 = real(-1./(3*a) * (b + 0.5*(-1.-std::sqrt(3)*_i_nb)*C + 2*Delta_0/(C*(-1.-std::sqrt(3)*_i_nb))));
    // Find the root between 0 and 1
    if (t_0 < 0 || t_0 > 1)
    {
      if (t_1 < 0 || t_1 > 1)
      {
        if (t_2 < 0 || t_2 > 1)
        {
          // Check if one of the roots was just outside (num. error)
          Real tolerance = 1e-14; // tolerance of numerical error
          t = -1;
          Real t_values[] = {t_0, t_1, t_2};
          for (const Real &t_value : t_values)
              if (std::abs(t_value - 0.5) - 0.5 < tolerance)
                  t = fmax(fmin(t_value, 1), 0);
          if (t == -1)
            mooseError("All 3 roots for t outside of range: ", t_0, ", ", t_1, ", ", t_2);
        }
        else
          t = t_2;
      }
      else
        t = t_1;
    }
    else
      t = t_0;
  }
  return t;
}
