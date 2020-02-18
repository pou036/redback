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

#ifndef TimeDerivativeAux_H
#define TimeDerivativeAux_H

#include "AuxKernel.h"

class TimeDerivativeAux;

template <>
InputParameters validParams<TimeDerivativeAux>();

class TimeDerivativeAux : public AuxKernel
{
public:
  TimeDerivativeAux(const InputParameters & parameters);
  virtual ~TimeDerivativeAux();

protected:
  virtual Real computeValue();
  const VariableValue & _v_dot;
};

#endif
