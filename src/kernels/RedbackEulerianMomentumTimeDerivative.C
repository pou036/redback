/*
 * RedbackEulerianMomentumTimeDerivative.C
 *
 *  Created on: Jul 28, 2016
 *      Author: stuartwalsh
 */

#include "RedbackEulerianMomentumTimeDerivative.h"

template<>
InputParameters validParams<RedbackEulerianMomentumTimeDerivative>()
{
  InputParameters params = validParams<TimeDerivative>();
  //params.addRequiredParam<Real>("rho", "density");
  params.addCoupledVar("rho", "density");
  return params;
}


RedbackEulerianMomentumTimeDerivative::RedbackEulerianMomentumTimeDerivative(const InputParameters & parameters) :
  TimeDerivative(parameters),
  _rho(coupledValue("rho"))
{}



Real
RedbackEulerianMomentumTimeDerivative::computeQpResidual()
{
  return _rho[_qp] * TimeDerivative::computeQpResidual();
}



Real
RedbackEulerianMomentumTimeDerivative::computeQpJacobian()
{
  return _rho[_qp] * TimeDerivative::computeQpJacobian();
}



Real RedbackEulerianMomentumTimeDerivative::computeQpOffDiagJacobian(unsigned)
{
  return 0.;
}




