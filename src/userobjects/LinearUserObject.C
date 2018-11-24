//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LinearUserObject.h"
#include "GriddedData.h"

registerMooseObject("RedbackApp", LinearUserObject);

template <>
InputParameters
validParams<LinearUserObject>()
{
  InputParameters params = validParams<GeneralUserObject>();
  params.addParam<std::vector<Real>>("positions", "The positions of the anchor points");
  params.addParam<Real>("initial_value", "The initial value of permeability");
  params.addParam<std::vector<PostprocessorName>>("permeability_values",
                                                  "The name of the postprocessor(s) that holds the "
                                                  "permeability values.");
  params.addClassDescription(
      "Bezier interpolation of permeability from postprocessors value in 1D.");
  return params;
}

LinearUserObject::LinearUserObject(const InputParameters & params)
  : GeneralUserObject(params),
  _positions(getParam<std::vector<Real>>("positions")),
  _fcn(),
  _initial_value(getParam<Real>("initial_value"))
{
  // variation of permeability in Y, 1D
  _dim = 1;
  _axes.clear();
  _axes.push_back(1);
  if (isParamValid("permeability_values"))
    _ppn = params.get<std::vector<PostprocessorName>>("permeability_values");
  _grid.clear();
  _grid.resize(_dim);
  _grid[_dim - 1] = _positions;
}

Real
LinearUserObject::value(Real t, const Point & p) const
{
  // convert the inputs to an input to the sample function using _axes
  std::vector<Real> pt_in_grid(_dim);
  for (unsigned int i = 0; i < _dim; ++i)
  {
    if (_axes[i] < 3)
      pt_in_grid[i] = p(_axes[i]);
    else if (_axes[i] == 3) // the time direction
      pt_in_grid[i] = t;
  }
  return sample(pt_in_grid);
}

void
LinearUserObject::initialize()
{
  _fcn.clear();
  const unsigned int len = _ppn.size();
  for (unsigned int i = 0; i < len; ++i)
    // transfer returns 0 if multiapp isn't solved, should put initial value of permeability instead
    if (getPostprocessorValueByName(_ppn[i]) == 0)
      _fcn.push_back(_initial_value);
    else
      _fcn.push_back(getPostprocessorValueByName(_ppn[i]));
}

Real
LinearUserObject::sample(const std::vector<Real> & pt) const
{
  /*
   * left contains the indices of the point to the 'left', 'down', etc, of pt
   * right contains the indices of the point to the 'right', 'up', etc, of pt
   * Hence, left and right define the vertices of the hypercube containing pt
   */
  std::vector<unsigned int> left(_dim);
  std::vector<unsigned int> right(_dim);
  for (unsigned int i = 0; i < _dim; ++i)
  {
    getNeighborIndices(_grid[i], pt[i], left[i], right[i]);
  }

  /*
   * The following just loops through all the vertices of the
   * hypercube containing pt, evaluating the function at all
   * those vertices, and weighting the contributions to the
   * final result depending on the distance of pt from the vertex
   */
  Real f = 0;
  Real weight;
  std::vector<unsigned int> arg(_dim);
  for (unsigned int i = 0; i < std::pow(2.0, int(_dim));
       ++i) // number of points in hypercube = 2^_dim
  {
    weight = 1;
    for (unsigned int j = 0; j < _dim; ++j)
      if ((i >> j) % 2 ==
          0) // shift i j-bits to the right and see if the result has a 0 as its right-most bit
      {
        arg[j] = left[j];
        if (left[j] != right[j])
          weight *= std::abs(pt[j] - _grid[j][right[j]]);
        else // unusual "end condition" case.  weight by 0.5 because we will encounter this twice
          weight *= 0.5;
      }
      else
      {
        arg[j] = right[j];
        if (left[j] != right[j])
          weight *= std::abs(pt[j] - _grid[j][left[j]]);
        else // unusual "end condition" case.  weight by 0.5 because we will encounter this twice
          weight *= 0.5;
      }
    if (arg.size() != _dim)
      mooseError(
          "Gridded data evaluateFcn called with ", arg.size(), " arguments, but expected ", _dim);
    unsigned int index = arg[0];
    for (unsigned int i = 1; i < _dim; ++i)
      index += arg[i];
    if (index >= _fcn.size())
      mooseError("Gridded data evaluateFcn attempted to access index ",
                 index,
                 " of function, but it contains only ",
                 _fcn.size(),
                 " entries");
    f += _fcn[index] * weight;
  }

  /*
   * finally divide by the volume of the hypercube
   */
  weight = 1;
  for (unsigned int dim = 0; dim < pt.size(); ++dim)
    if (left[dim] != right[dim])
      weight *= _grid[dim][right[dim]] - _grid[dim][left[dim]];
    else // unusual "end condition" case.  weight by 1 to cancel the two 0.5 encountered previously
      weight *= 1;

  return f / weight;
}

void
LinearUserObject::getNeighborIndices(std::vector<Real> in_arr,
                                       Real x,
                                       unsigned int & lower_x,
                                       unsigned int & upper_x) const
{
  int N = in_arr.size();
  if (x <= in_arr[0])
  {
    lower_x = 0;
    upper_x = 0;
  }
  else if (x >= in_arr[N - 1])
  {
    lower_x = N - 1;
    upper_x = N - 1;
  }
  else
  {
    // returns up which points at the first element in inArr that is not less than x
    std::vector<double>::iterator up = std::lower_bound(in_arr.begin(), in_arr.end(), x);

    // std::distance returns std::difference_type, which can be negative in theory, but
    // in this context will always be >=0.  Therefore the explicit cast is just to shut
    // the compiler up.
    upper_x = static_cast<unsigned int>(std::distance(in_arr.begin(), up));
    if (in_arr[upper_x] == x)
      lower_x = upper_x;
    else
      lower_x = upper_x - 1;
  }
}
