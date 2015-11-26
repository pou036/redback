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

#ifndef REDBACKMECHMATERIALDAMAGEDP_H
#define REDBACKMECHMATERIALDAMAGEDP_H

#include "RedbackMechMaterial.h"
#include "RedbackMechMaterialDP.h"

//Forward Declarations
class RedbackMechMaterialDP;

template<>
InputParameters validParams<RedbackMechMaterialDP>();

class RedbackMechMaterialDamageDP : public RedbackMechMaterialDP
{
public:
  RedbackMechMaterialDamageDP(const InputParameters & parameters);

protected:
  MaterialProperty<Real> & _damage_kernel;
  MaterialProperty<Real> & _damage_kernel_jac;
  Real _energetic_coeff;

  virtual void computeRedbackTerms(RankTwoTensor &, Real, Real);
};

#endif // REDBACKMECHMATERIALDAMAGEDP_H
