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

#include "CubeTerm.h"


template<>
InputParameters validParams<CubeTerm>()
{
  InputParameters params = validParams<Kernel>();

  params.addParam<Real>("lambda", 1.0, "Lambda parameter.");

  return params;
}


CubeTerm::CubeTerm(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _lambda(getParam<Real>("lambda"))
{

}

CubeTerm::~CubeTerm()
{

}

Real
CubeTerm::computeQpResidual()
{
  return _test[_i][_qp]*_lambda*_u[_qp]*_u[_qp]*_u[_qp];
}

Real
CubeTerm::computeQpJacobian()
{
  return 3*_test[_i][_qp] * _lambda * _u[_qp]* _u[_qp]  * _phi[_j][_qp];
}
