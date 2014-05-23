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

  params.addParam<Real>("ar_c", 1.0, "Arrhenius chemistry.");
  params.addRequiredParam<Real>("da", "Damkoehler number.");
  params.addRequiredParam<Real>("delta", "Kamenetskii coefficient.");

  return params;
}


ChemEndo::ChemEndo(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _ar_c(getParam<Real>("ar_c")),
  _da(getParam<Real>("da")),
  _delta(getParam<Real>("delta"))
{

}

ChemEndo::~ChemEndo()
{

}

Real
ChemEndo::computeQpResidual()
{
  return _test[_i][_qp]*_da*std::exp( (_ar_c*_delta*_u[_qp]) / (1 + _delta*_u[_qp]) );
}

Real
ChemEndo::computeQpJacobian()
{
  return _test[_i][_qp] * _da * ( _delta*_ar_c / ( (1+_delta*_u[_qp] ) * (1+_delta*_u[_qp] ) ) ) *
    std::exp( (_ar_c*_delta*_u[_qp]) / (1 + _delta*_u[_qp]) ) * _phi[_j][_qp];
}
