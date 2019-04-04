/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/
#include "DPGErrorFractionMarker.h"

#include "libmesh/error_vector.h"

registerMooseObject("MooseApp", DPGErrorFractionMarker);

template <>
InputParameters
validParams<DPGErrorFractionMarker>()
{
  InputParameters params = validParams<ErrorFractionMarker>();
  params.addParam<IndicatorName>("indicator2",
                                 "The name of a second Indicator that this Marker uses.");
  params.addParam<IndicatorName>("indicator3",
                                 "The name of a third Indicator that this Marker uses.");
  params.addParam<Real>("factor_1", 1.0, "Mutliplication factor of first Indicator.");
  params.addParam<Real>("factor_2", 1.0, "Mutliplication factor of second Indicator.");
  params.addParam<Real>("factor_3", 1.0, "Mutliplication factor of third Indicator.");
  params.addClassDescription("Marks elements for refinement or coarsening based on the fraction of "
                             "the min/max error from the sum of supplied (up to 3) indicators.");
  return params;
}

DPGErrorFractionMarker::DPGErrorFractionMarker(const InputParameters & parameters)
  : ErrorFractionMarker(parameters),
  _is_ev2_supplied(isParamValid("indicator2")),
  _is_ev3_supplied(isParamValid("indicator3")),
  _mult_fact1(getParam<Real>("factor_1")),
  _mult_fact2(getParam<Real>("factor_2")),
  _mult_fact3(getParam<Real>("factor_3")),
  _error_vector2(getErrorVector(parameters.get<IndicatorName>("indicator2"))),
  _error_vector3(getErrorVector(parameters.get<IndicatorName>("indicator3")))
{
}

void
DPGErrorFractionMarker::markerSetup()
{
  if (_clear_extremes)
  {
    _min = std::numeric_limits<Real>::max();
    _max = 0;
  }

  // First find the max and min error
  for (const auto & val : _error_vector)
  {
    _min = std::min(_min, static_cast<Real>(val));
    _max = std::max(_max, static_cast<Real>(val));
  }
  // Account for other 2 indicators
  if (_is_ev2_supplied)
  {
    for (const auto & val : _error_vector2)
    {
      _min = std::min(_min, static_cast<Real>(val));
      _max = std::max(_max, static_cast<Real>(val));
    }
  }
  if (_is_ev3_supplied)
    {
    for (const auto & val : _error_vector3)
    {
      _min = std::min(_min, static_cast<Real>(val));
      _max = std::max(_max, static_cast<Real>(val));
    }
  }

  _delta = _max - _min;
  _refine_cutoff = (1.0 - _refine) * _max;
  _coarsen_cutoff = _coarsen * _delta + _min;
}

Marker::MarkerValue
DPGErrorFractionMarker::computeElementMarker()
{
  Real error = _error_vector[_current_elem->id()];
  if (_is_ev2_supplied)
    error += _error_vector2[_current_elem->id()];
  if (_is_ev3_supplied)
    error += _error_vector3[_current_elem->id()];

  if (error > _refine_cutoff)
    return REFINE;
  else if (error < _coarsen_cutoff)
    return COARSEN;

  return DO_NOTHING;
}
