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

#include "DimensionlessRock.h"

template<>
InputParameters validParams<DimensionlessRock>()
{
  InputParameters params = validParams<Material>();

  params.addRequiredRangeCheckedParam<Real>("gr", "gr>=0", "Gruntfest number.");
  params.addRequiredParam<Real>("ar", "Arrhenius number.");
  params.addRequiredParam<Real>("ar_c", "Chemical Arrhenius number.");
  params.addRequiredParam<Real>("delta", "Kamenetskii coefficient.");
  params.addRequiredParam<Real>("da", "Damkoehler number.");
  params.addRequiredParam<Real>("mu", "Chemical pressurization coefficient.");
  params.addRequiredParam<Real>("m", "Rate sensitivity parameter.");

  return params;
}

DimensionlessRock::DimensionlessRock(const std::string & name, InputParameters parameters) :
    Material(name, parameters),
    _gr_param(getParam<Real>("gr")),
    _ar_param(getParam<Real>("ar")),
    _ar_c_param(getParam<Real>("ar_c")),
    _delta_param(getParam<Real>("delta")),
    _da_param(getParam<Real>("da")),
    _mu_param(getParam<Real>("mu")),
    _m_param(getParam<Real>("m")),

    _gr(declareProperty<Real>("gr")),
    _ar(declareProperty<Real>("ar")),
    _ar_c(declareProperty<Real>("ar_c")),
    _delta(declareProperty<Real>("delta")),
    _da(declareProperty<Real>("da")),
    _mu(declareProperty<Real>("mu")),
    _m(declareProperty<Real>("m"))
{

}

void
DimensionlessRock::computeQpProperties()
{
  _gr[_qp] = _gr_param;
  _ar[_qp] = _ar_param;
  _ar_c[_qp] = _ar_c_param;
  _delta[_qp] = _delta_param;
  _da[_qp] = _da_param;
  _mu[_qp] = _mu_param;
  _m[_qp] = _m_param;
}
