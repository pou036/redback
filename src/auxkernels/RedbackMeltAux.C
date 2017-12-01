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

#include "RedbackMeltAux.h"

template <>
InputParameters
validParams<RedbackMeltAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addCoupledVar("temperature", 0.0, "Temperature variable");
  return params;
}

RedbackMeltAux::RedbackMeltAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _temp(coupledValue("temperature"))
{
}

Real
RedbackMeltAux::computeValue()
{
  Real phi_m; // melt fraction
  phi_m = _temp[_qp]; // TODO: equation missing!
  return phi_m;
}
