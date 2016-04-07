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

#include "RedbackPolarStressAux.h"

template <>
InputParameters
validParams<RedbackPolarStressAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

RedbackPolarStressAux::RedbackPolarStressAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _stress(getMaterialProperty<RankTwoTensor>("stress"))
{
}

Real
RedbackPolarStressAux::computeValue()
{
  Real x = (*_current_node)(0);
  Real y = (*_current_node)(1);
  //Real z = (*_current_node)(2);

  Real theta = std::atan(y/x);//*(y <0 ? -1: 1);

  Real sigma_rtheta = -_stress[_qp](0,0) * std::sin(theta) * std::cos(theta) +
                      _stress[_qp](0,1) * (std::cos(theta) * std::cos(theta) - std::sin(theta) * std::sin(theta)) +
                      _stress[_qp](1,1) * std::sin(theta) * std::cos(theta);

  return sigma_rtheta;
}
