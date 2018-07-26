/****************************************************************/
/*   Material implementing Eleni Gerolymatou's yield surface    */
/*   [REF needed]                                               */
/****************************************************************/

#ifndef REDBACKMECHMATERIALLNE_H
#define REDBACKMECHMATERIALLNE_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialLne;

template <>
InputParameters validParams<RedbackMechMaterialLne>();

class RedbackMechMaterialLne : public RedbackMechMaterial
{
public:
  RedbackMechMaterialLne(const InputParameters & parameters);

protected:
  Real _M;     // slope of critical state line (needed? TODO: check with Eleni)
  Real _M_e;   // slope of critical state line in extension
  Real _M_c;   // slope of critical state line in compression
  Real _alpha; // material parameter controlling location (in p') of yield surface maximum
  Real _beta;  // material parameter controlling width of yield surface bell curve
  Real _theta; // Lode angle (using positive cosine)
  Real _p_c;   // isotropic compression strength
  Real _p_t;   // tensile strength

  Real _M_f; // M_f coefficient (function of M, M_e, M_c, theta)

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

#endif // REDBACKMECHMATERIALLNE_H
