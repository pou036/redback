/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKMECHMATERIALCCANISOTROPIC_H
#define REDBACKMECHMATERIALCCANISOTROPIC_H

#include "RedbackMechMaterialCC.h"

// Forward Declarations
class RedbackMechMaterialCCanisotropic;

template <>
InputParameters validParams<RedbackMechMaterialCCanisotropic>();

class RedbackMechMaterialCCanisotropic : public RedbackMechMaterialCC
{
public:
  RedbackMechMaterialCCanisotropic(const InputParameters & parameters);

protected:
  Real _initial_anisotropy_param; // Initial coefficient alpha of anisotropy
                                  // (Dafalias 2013)

  MaterialProperty<Real> & _anisotropy_coeff; // current coefficient alpha of
                                              // anisotropy (Dafalias 2013)

  virtual void stepInitQpProperties() override;
  virtual void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &) override;
  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) override;
  virtual Real getFlowIncrement(Real, Real, Real, Real, Real) override;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real) override;
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real);
};

#endif // REDBACKMECHMATERIALCCANISOTROPIC_H
