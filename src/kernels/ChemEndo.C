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

#include "ChemEndo.h"


template<>
InputParameters validParams<ChemEndo>()
{
  InputParameters params = validParams<Kernel>();

  return params;
}


ChemEndo::ChemEndo(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _ar_c(getMaterialProperty<Real>("ar_c")),
  _da(getMaterialProperty<Real>("da")),
  _delta(getMaterialProperty<Real>("delta"))
{

}

ChemEndo::~ChemEndo()
{

}

Real
ChemEndo::computeQpResidual()
{
  return _test[_i][_qp]*_da[_qp]*std::exp( (_ar_c[_qp]*_delta[_qp]*_u[_qp]) / (1 + _delta[_qp]*_u[_qp]) );
}

Real
ChemEndo::computeQpJacobian()
{
  return _test[_i][_qp] * _da[_qp] * ( _delta[_qp]*_ar_c[_qp] / ( (1+_delta[_qp]*_u[_qp] ) * (1+_delta[_qp]*_u[_qp] ) ) ) *
    std::exp( (_ar_c[_qp]*_delta[_qp]*_u[_qp]) / (1 + _delta[_qp]*_u[_qp]) ) * _phi[_j][_qp];
}
