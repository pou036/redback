/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO                                  */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKFAULTANISOTROPICPERMAUX_H
#define REDBACKFAULTANISOTROPICPERMAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackFaultAnisotropicPermAux;

template <>
InputParameters validParams<RedbackFaultAnisotropicPermAux>();

class RedbackFaultAnisotropicPermAux : public AuxKernel
{
public:
  RedbackFaultAnisotropicPermAux(const InputParameters & parameters);
  virtual ~RedbackFaultAnisotropicPermAux() {}

protected:
  virtual Real computeValue();
  const VariableGradient & _n; // normal vector (non-normalised)
  Real _k_long, _k_tran; // perm values for longitudinal and transversal components
  int _i_row, _i_column; // indices i,j of perm tensor to set
};

#endif // REDBACKFAULTANISOTROPICPERMAUX_H
