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

#ifndef RedbackMechMaterialCCanisotropic_UO_DC_H
#define RedbackMechMaterialCCanisotropic_UO_DC_H

#include "RedbackMechMaterialCC_UO_DC.h"

// Forward Declarations
class RedbackMechMaterialCCanisotropic_UO_DC;

template <>
InputParameters validParams<RedbackMechMaterialCCanisotropic_UO_DC>();

class RedbackMechMaterialCCanisotropic_UO_DC : public RedbackMechMaterialCC_UO_DC
{
public:
  RedbackMechMaterialCCanisotropic_UO_DC(const InputParameters & parameters);

protected:
  Real _initial_anisotropy_param; // Initial coefficient alpha of anisotropy
                                  // (Dafalias 2013)

  MaterialProperty<Real> & _anisotropy_coeff; // current coefficient alpha of
                                              // anisotropy (Dafalias 2013)

  virtual void stepInitQpProperties();
  void getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &);
  void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &);
  Real getFlowIncrement(Real, Real, Real, Real, Real);
  void get_py_qy(Real, Real, Real &, Real &, Real);
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real);
};

#endif // RedbackMechMaterialCCanisotropic_UO_DC_H
