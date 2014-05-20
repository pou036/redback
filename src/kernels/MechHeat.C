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

#include "MechHeat.h"


template<>
InputParameters validParams<MechHeat>()
{
  InputParameters params = validParams<Kernel>();

  params.addParam<Real>("gr", 1.0, "Gruntfest number.");
  params.addParam<Real>("ar", 1.0, "Arrhenius number.");

  return params;
}


MechHeat::MechHeat(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _gr(getParam<Real>("gr")),
  _ar(getParam<Real>("ar"))
{

}

MechHeat::~MechHeat()
{

}

Real
MechHeat::computeQpResidual()
{
  return -_test[_i][_qp]*_gr*std::exp( (_ar*_u[_qp]) / (1 + _u[_qp]) );
}

Real
MechHeat::computeQpJacobian()
{
  return -_test[_i][_qp] * _gr * ( _ar / ( (1+_u[_qp] ) * (1+_u[_qp] ) ) ) *
    std::exp( (_ar*_u[_qp]) / (1 + _u[_qp]) ) * _phi[_j][_qp];
}
