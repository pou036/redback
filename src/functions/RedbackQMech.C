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

#include "MooseRandom.h"
#include "RedbackQMech.h"

template <>
InputParameters
validParams<RedbackQMech>()
{
  InputParameters params = validParams<Function>();
  params.addRequiredParam<PostprocessorName>("plastic_strain_rate", "plastic strain rate volumetric or deviatoric");
  params.addRequiredParam<PostprocessorName>("stress", "mean or mises stress");
  params.addRequiredParam<PostprocessorName>("temp", "temperature");
  params.addParam<Real>("R", 8.314, "constant");
  params.addParam<Real>("pe_ref_rate", 1.0, "reference plastic strain rate");
  params.addClassDescription("This function computes QMech deviatoric or volumetric.");
  return params;
}

RedbackQMech::RedbackQMech(const InputParameters & parameters)
  : Function(parameters),
    _plastic_strain_rate(getPostprocessorValue("plastic_strain_rate")),
    _stress(getPostprocessorValue("stress")),
    _temp(getPostprocessorValue("temp")),
    _R(getParam<Real>("R")),
    _pe_ref_rate(getParam<Real>("pe_ref_rate"))
{
}

Real
RedbackQMech::value(Real t, const Point & p)
{
  Real qmech = 0;
  if (_plastic_strain_rate != 0)
  {
    qmech = -log(_plastic_strain_rate / _stress) * _R * _temp;
  }
  return qmech;
}
