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

#include "SideExtremeValue.h"

#include <algorithm>
#include <limits>

template <>
InputParameters
validParams<SideExtremeValue>()
{
  // Define the min/max enumeration
  MooseEnum type_options("max=0 min=1", "max");

  // Define the parameters
  InputParameters params = validParams<SideVariablePostprocessor>();

  params.addParam<MooseEnum>("value_type",
                             type_options,
                             "Type of extreme value to return. 'max' "
                             "returns the maximum value. 'min' returns "
                             "the minimum value.");

  return params;
}

SideExtremeValue::SideExtremeValue(const InputParameters & parameters) :
    SideVariablePostprocessor(parameters),
    _type((ExtremeType)(int)parameters.get<MooseEnum>("value_type")),
    _value(_type == 0 ? -std::numeric_limits<Real>::max() : std::numeric_limits<Real>::max())
{
}

void
SideExtremeValue::initialize()
{
  switch (_type)
  {
    case MAX:
      _value = -std::numeric_limits<Real>::max(); // start w/ the min
      break;

    case MIN:
      _value = std::numeric_limits<Real>::max(); // start w/ the max
      break;
  }
}

void
SideExtremeValue::computeQpValue()
{
  switch (_type)
  {
    case MAX:
      _value = std::max(_value, _u[ _qp ]);
      break;

    case MIN:
      _value = std::min(_value, _u[ _qp ]);
      break;
  }
}

Real
SideExtremeValue::getValue()
{
  switch (_type)
  {
    case MAX:
      gatherMax(_value);
      break;
    case MIN:
      gatherMin(_value);
      break;
  }

  return _value;
}

void
SideExtremeValue::threadJoin(const UserObject & y)
{
  const SideExtremeValue & pps = static_cast<const SideExtremeValue &>(y);

  switch (_type)
  {
    case MAX:
      _value = std::max(_value, pps._value);
      break;
    case MIN:
      _value = std::min(_value, pps._value);
      break;
  }
}
