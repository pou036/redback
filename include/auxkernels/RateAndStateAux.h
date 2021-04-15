/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef RATEANDSTATEAUX_H
#define RATEANDSTATEAUX_H

#include "AuxKernel.h"

class RateAndStateAux;

template <>
InputParameters validParams<RateAndStateAux>();

class RateAndStateAux : public AuxKernel
{
public:
  RateAndStateAux(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  const PostprocessorValue & _mises;
  const PostprocessorValue & _mises_old;
  Real _activation_mises;
  Real _deactivation_mises;
  Real _creeping_vel;
  Real _vel_0;
  Real _mises_0;
  Real _Ar;
  bool _activation;
  const VariableValue & _u_old;
};

#endif // RATEANDSTATEAUX_H
