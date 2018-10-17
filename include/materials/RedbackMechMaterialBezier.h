/********************************************************************/
/*   Material implementing yield surface defined by Bezier curves   */
/*   [REF needed]                                                   */
/********************************************************************/

#ifndef REDBACKMECHMATERIALBEZIER_H
#define REDBACKMECHMATERIALBEZIER_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialBezier;

template <>
InputParameters validParams<RedbackMechMaterialBezier>();

class RedbackMechMaterialBezier : public RedbackMechMaterial
{
public:
  RedbackMechMaterialBezier(const InputParameters & parameters);

protected:
  Real _p_c;   // isotropic compression strength
  Real _p_t;   // tensile strength
  Real _p_M;   // p' value of Max point joining 2 Bezier curves
  Real _q_M;   // q value of Max point joining 2 Bezier curves
  Real _p_H;   // p' value of centre of homothetic transformation
  Real _q_H;   // q value of centre of homothetic transformation
  Real _coeff_c_vert; // multiplying factor for vertical tangent at p_c
  Real _coeff_c_hor;  // multiplying factor for horizontal tangent at Max point on compression side
  Real _coeff_t_vert; // multiplying factor for vertical tangent at p_t
  Real _coeff_t_hor;  // multiplying factor for horizontal tangent at Max point on tension side

  int _quadrant;
  Real _t;

  Real _last_p, _last_q; // (p,q) last used by Bezier::getOverstress()
  // Corresponding values obtained for (_last_p, _last_q)
  bool _last_is_plastic;
  int _last_quadrant;
  Real _last_s, _last_t, _last_p_y, _last_q_y;
  Real _last_derivatives[2];

  virtual void getJac(const RankTwoTensor &,
                      const RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      RankFourTensor &) override;
  virtual void
  getFlowTensor(const RankTwoTensor &, Real, Real, Real, Real, Real, RankTwoTensor &) override;
  virtual Real getFlowIncrement(Real, Real, Real, Real, Real, Real) override;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real, bool &, Real &) override;
  virtual void form_damage_kernels(Real) override;
};

#endif // REDBACKMECHMATERIALBEZIER_H
