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
// (- \lambda(1+u)^m e^{-\alpha u} + \mu e^{\beta u}, \tilde{w})

#include "DPGmypb11.h"
#include "Assembly.h"

registerMooseObject("RedbackApp", DPGmypb11);

template <>
InputParameters
validParams<DPGmypb11>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPGmypb11::DPGmypb11(const InputParameters & parameters):
  Kernel(parameters),
  _scalar_var(coupledValue("coupled_variable")),
  _k_var(coupled("coupled_variable")),
  _phi_var(_assembly.phi(*getVar("coupled_variable",0))),
  _lambda(getMaterialProperty<Real>("DPG_lambda")),
  _alpha_2(getMaterialProperty<Real>("alpha_2")),
  _m(getMaterialProperty<Real>("DPG_m")),
  _mu(getMaterialProperty<Real>("DPG_mu")),
  _beta(getMaterialProperty<Real>("DPG_beta"))
{
}

Real
DPGmypb11::computeQpResidual()
{
  return _test[_i][_qp]*(
    _lambda[_qp]*std::pow(1+_scalar_var[_qp], _m[_qp])*std::exp(-_alpha_2[_qp]*_scalar_var[_qp])
    - _mu[_qp]*std::exp(_beta[_qp]*_scalar_var[_qp]));
}

Real
DPGmypb11::computeQpJacobian()
{
  return 0;
}


Real
DPGmypb11::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _k_var)
  {
    return _test[_i][_qp]*(
      _lambda[_qp]*std::pow(1+_scalar_var[_qp], _m[_qp]-1)*std::exp(-_alpha_2[_qp]*_scalar_var[_qp])
        * (_m[_qp] - _alpha_2[_qp]*(1+_scalar_var[_qp]))*_phi_var[_j][_qp]
      - _mu[_qp]*_beta[_qp]*std::exp(_beta[_qp]*_scalar_var[_qp])*_phi_var[_j][_qp]);
  }
  return 0;
}
