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

#include "DummyCnoidal.h"


template<>
InputParameters validParams<DummyCnoidal>()
{
  InputParameters params = validParams<Kernel>();
  params.addParam<Real>("lambda", 1.0, "Lambda parameter");
  params.addParam<Real>("mu", 1.0, "Mu parameter");
  params.addParam<Real>("tau", 1.0, "Tau parameter");
  params.addParam<Real>("alpha", 1.0, "Alpha parameter");
  return params;
}


DummyCnoidal::DummyCnoidal(const InputParameters & parameters) :
  Kernel(parameters),
  _lambda_param(getParam<Real>("lambda")),
  _mu_param(getParam<Real>("mu")),
  _tau_param(getParam<Real>("tau")),
  _alpha_param(getParam<Real>("alpha"))
{

}

DummyCnoidal::~DummyCnoidal()
{

}

Real
DummyCnoidal::computeQpResidual()
{
  //return -(_mu_param*exp(_alpha_param*_u[_qp]) - _lambda_param*std::pow(_tau_param-_u[_qp], 3))*_test[_i][_qp];
  return -(_mu_param*exp(_alpha_param*_u[_qp]) - _lambda_param*exp(-_tau_param*_u[_qp]))*_test[_i][_qp];
}

Real
DummyCnoidal::computeQpJacobian()
{
  //return -(_alpha_param*_mu_param*exp(_alpha_param*_u[_qp]) + 3*_lambda_param*std::pow(_tau_param-_u[_qp], 2))*_test[_i][_qp] * _phi[_j][_qp];
  return -(_alpha_param*_mu_param*exp(_alpha_param*_u[_qp]) - _tau_param*_lambda_param*exp(-_tau_param*_u[_qp]))*_test[_i][_qp] * _phi[_j][_qp];
}
