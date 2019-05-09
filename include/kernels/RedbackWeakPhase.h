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

#ifndef REDBACKWEAKPHASE_H
#define REDBACKWEAKPHASE_H

#include "Kernel.h"

class RedbackWeakPhase;

template <>
InputParameters validParams<RedbackWeakPhase>();

/**
 * Kernel that is calling coupledDot
 */
class RedbackWeakPhase : public Kernel
{
public:
  RedbackWeakPhase(const InputParameters & parameters);
  virtual ~RedbackWeakPhase();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const MaterialProperty<Real> & _poromech_kernel;
  const MaterialProperty<Real> & _poromech_jac;

  unsigned int _temp_var; // variable number of the temperature variable

private:
  Real _time_factor;
};

#endif /* RedbackWeakPhase_H */
