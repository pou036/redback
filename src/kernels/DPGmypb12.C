/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2018 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Kernel for the term
// (\lambda(1+u)^m e^{-\alpha u} - \mu e^{\beta u}, \tilde{u})

#include "DPGmypb12.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPGmypb12);

template <>
InputParameters
validParams<DPGmypb12>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

DPGmypb12::DPGmypb12(const InputParameters & parameters):
  Kernel(parameters),
  _lambda(getMaterialProperty<Real>("DPG_lambda")),
  _alpha_2(getMaterialProperty<Real>("alpha_2")),
  _m(getMaterialProperty<Real>("DPG_m")),
  _mu(getMaterialProperty<Real>("DPG_mu")),
  _beta(getMaterialProperty<Real>("DPG_beta"))
{
}

Real
DPGmypb12::computeQpResidual()
{
  return _test[_i][_qp]*(
    _lambda[_qp]*std::pow(1+_u[_qp], _m[_qp])*std::exp(-_alpha_2[_qp]*_u[_qp])
    - _mu[_qp]*std::exp(_beta[_qp]*_u[_qp]));
}

Real
DPGmypb12::computeQpJacobian()
{
  return _test[_i][_qp]*(
      _lambda[_qp]*std::pow(1+_u[_qp], _m[_qp]-1)*std::exp(-_alpha_2[_qp]*_u[_qp])
        * (_m[_qp] - _alpha_2[_qp]*(1+_u[_qp]))*_phi[_j][_qp]
      - _mu[_qp]*_beta[_qp]*std::exp(_beta[_qp]*_u[_qp])*_phi[_j][_qp]);
}

