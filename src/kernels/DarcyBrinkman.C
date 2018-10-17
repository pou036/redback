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

#include "DarcyBrinkman.h"

template <>
InputParameters
validParams<DarcyBrinkman>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("permeability", 1.0, "the permeability of the solid phase");
  return params;
}

DarcyBrinkman::DarcyBrinkman(const InputParameters & parameters)
  : Kernel(parameters), _perm(coupledValue("permeability")), _mu(getMaterialProperty<Real>("mu"))
{
}

Real
DarcyBrinkman::computeQpResidual()
{
  return _mu[_qp] / _perm[_qp] * _u[_qp] * _test[_i][_qp];
}

Real
DarcyBrinkman::computeQpJacobian()
{
  return _mu[_qp] / _perm[_qp] * _phi[_j][_qp] * _test[_i][_qp];
}
