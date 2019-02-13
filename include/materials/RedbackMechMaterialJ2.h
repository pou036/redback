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

#ifndef REDBACKMECHMATERIALJ2_H
#define REDBACKMECHMATERIALJ2_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialJ2;

template <>
InputParameters validParams<RedbackMechMaterialJ2>();

class RedbackMechMaterialJ2 : public RedbackMechMaterial
{
public:
  RedbackMechMaterialJ2(const InputParameters & parameters);

protected:
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
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real);
};

#endif // REDBACKMECHMATERIAL_H
