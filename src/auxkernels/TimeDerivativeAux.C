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

#include "TimeDerivativeAux.h"

registerMooseObject("RedbackApp", TimeDerivativeAux);

template <>
InputParameters
validParams<TimeDerivativeAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("v", "Coupled variable");
  return params;
}

TimeDerivativeAux::TimeDerivativeAux(const InputParameters & parameters)
  : AuxKernel(parameters), _v_dot(coupledDot("v"))
{
}

TimeDerivativeAux::~TimeDerivativeAux() {}

Real
TimeDerivativeAux::computeValue()
{
  return _v_dot[_qp];
}
