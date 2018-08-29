//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "BezierUserObject.h"
#include "GriddedData.h"

template <>
InputParameters
validParams<BezierUserObject>()
{
  InputParameters params = validParams<GeneralUserObject>();
  params.addParam<std::vector<Real> >("positions", "The positions of the App locations (1D)");
  params.addParam<std::vector<PostprocessorName> >("permeability_values",
                                                   "The name of the postprocessor(s) that holds the "
                                                   "permeability values.");
  params.addClassDescription("PiecewiseMultilinear performs interpolation on 1D, 2D, 3D or 4D "
                             "data.  The data_file specifies the axes directions and the function "
                             "values.  If a point lies outside the data range, the appropriate end "
                             "value is used.");
  return params;
}

BezierUserObject::BezierUserObject(const InputParameters & params) :
    GeneralUserObject(params),
  _points_x(getParam<std::vector<Real> >("positions")),
  _points_y()
{
  if (isParamValid("permeability_values"))
    _ppn = params.get<std::vector<PostprocessorName> >("permeability_values");
}

Real
BezierUserObject::value(const Point & p) const
{
  Real x = p(1);
  if (x<=_abcd_segments[0][0].first)
    return _abcd_segments[0][0].second;
  Real k=0;
  //compute ith segment, x in kth*segment
  for (unsigned int i = 0; i < _abcd_segments.size(); ++i)
    if (x==_abcd_segments[i][3].first)
      return _abcd_segments[i][3].second;
    else if (x<_abcd_segments[i][3].first)
    {
      k=i;
      break;
    }
  if (x>_abcd_segments.back()[3].first)
    return _abcd_segments.back()[3].second;

  Real x0 = _abcd_segments[k][0].first;
  Real x1 = _abcd_segments[k][1].first;
  Real x2 = _abcd_segments[k][2].first;
  Real x3 = _abcd_segments[k][3].first;

  Real t_i = 0;
  Real t_i_old = 0;
  Real t_i_older = 0;
  Real tol = 1e-10;
  Real f = x0*pow(1 - t_i,3) + x1*3*t_i*pow(1 - t_i,2) + 3*x2*(1 - t_i)*pow(t_i,2) + x3*pow(t_i,3) - x;
  Real f_prime;
  int iter=0;
  int max_iter=100;
  while (std::abs(f) > tol && iter<max_iter)
  {
    f_prime = 3*(x1-x0)*pow(1-t_i,2)  + 6*(1-t_i)*t_i*(x2-x1) + 3*(x3-x2)*pow(t_i,2);
    t_i_older = t_i_old;
    t_i_old = t_i;
    t_i -= f / f_prime;
    t_i = std::fmax(std::fmin(t_i, 1), 0);
    if (t_i==t_i_older) t_i=0.5*(t_i+t_i_old);
    f = x0*pow(1 - t_i,3) + x1*3*t_i*pow(1 - t_i,2) + 3*x2*(1 - t_i)*pow(t_i,2) + x3*pow(t_i,3) - x;
    iter++;
  }
  if (iter==max_iter)
  {
    std::cout<<"x = "<<x<<", x0 = "<<x0<<", x1 = "<<x1<<", x2 = "<<x2<<", x3 = "<<x3<<std::endl;
    mooseError("Newton-Raphson did not converge.");
  }
  Real y0 = _abcd_segments[k][0].second;
  Real y1 = _abcd_segments[k][1].second;
  Real y2 = _abcd_segments[k][2].second;
  Real y3 = _abcd_segments[k][3].second;
  return y0*pow(1 - t_i,3) + y1*3*t_i*pow(1 - t_i,2) + 3*y2*(1 - t_i)*pow(t_i,2) + y3*pow(t_i,3);

  //
  // //evaluate a point on a bezier-curve. t goes from 0 to 1.0
  // std::pair<Real,Real> ab = lerp(a,b,t); // point between a and b
  // std::pair<Real,Real> bc = lerp(b,c,t); // point between b and c
  // std::pair<Real,Real> cd = lerp(c,d,t); // point between c and d
  // std::pair<Real,Real> abbc = lerp(ab,bc,t); // point between ab and bc
  // std::pair<Real,Real> bccd = lerp(bc,cd,t); // point between bc and cd
  // return lerp(abbc,bccd,t).second; // point on the bezier-curve
}

void
BezierUserObject::initialize()
{
  Real x0 = 0;
  Real weight = 0.25;

  _points_y.clear();
  // prepare result (list of lists of 4 points a,b,c,d)
  _abcd_segments.clear();
  const unsigned int len = _ppn.size();
  for (unsigned int i = 0; i < len; ++i)
    // transfer returns 0 if multiapp isn't solved, should put initial value of permeability instead
    if (getPostprocessorValueByName(_ppn[ i ]) == 0)
      _points_y.push_back(0.1);
    else
      _points_y.push_back(getPostprocessorValueByName(_ppn[ i ]));

  Real nb_segments = len - 1;
  // get tangent points
  std::vector<Real> tangents = getTangents(_points_x, _points_y);

  for (unsigned int k = 0; k < nb_segments; ++k)
  {
    std::pair<Real,Real> a;
    std::pair<Real,Real> b;
    std::pair<Real,Real> c;
    std::pair<Real,Real> d;
    // end points given by user
    a = std::make_pair(_points_x[k], _points_y[k]);
    d = std::make_pair(_points_x[k+1], _points_y[k+1]);
    // other points
    Real segment_length = std::sqrt(std::pow(a.first-d.first, 2) + std::pow(a.second-d.second, 2));
    if (std::abs(a.second-d.second)/std::abs(a.first-d.first) < 1e-1)
    {
      Real delta = weight*segment_length;
      // point b
      b = std::make_pair(a.first + delta, a.second + delta*(a.second-d.second)/(a.first-d.first));
      // point c
      c = std::make_pair(d.first - delta, d.second - delta*(a.second-d.second)/(a.first-d.first));
      std::vector<std::pair<Real,Real>> temp = {a,b,c,d};
      _abcd_segments.push_back(temp);
      continue;
    }
    // point b
    if (std::abs(a.first - x0) < 1e-8)
      b = std::make_pair(a.first + weight*std::abs(a.first-d.first),  a.second);
    else
      b = std::make_pair(a.first + weight*segment_length*std::cos(std::atan(tangents[k])),  a.second + weight*segment_length*std::sin(std::atan(tangents[k])));
    // point c
    if (std::abs(d.first - x0) < 1e-8)
      c = std::make_pair(d.first - weight*std::abs(a.first-d.first),  d.second); //segment_length/10.
    else
      c = std::make_pair(d.first - weight*segment_length*std::cos(std::atan(tangents[k+1])),  d.second - weight*segment_length*std::sin(std::atan(tangents[k+1])));
    std::vector<std::pair<Real,Real>> temp = {a,b,c,d};
    _abcd_segments.push_back(temp);
  }
}

std::vector<Real>
BezierUserObject::getTangents(std::vector<Real> x_array, std::vector<Real> y_array)
{
  std::vector<Real> tangents;
  int nb_segments = x_array.size() - 1;
  for (unsigned int k = 0; k < nb_segments-1; ++k)
  {
    std::vector<Real> coeffs = getParabolaWeigths(x_array[k],y_array[k],
      x_array[k+1],y_array[k+1],
      x_array[k+2],y_array[k+2]);
    Real a = coeffs[0];
    Real b = coeffs[1];
    // Real c = coeffs[2];
    // tangent on first point
    if (k==0)
      tangents.push_back(0);
    //tangent at k+1
    tangents.push_back(2*a*x_array[k+1] + b);
    // tangent on last point
    if (k==nb_segments-2)
      tangents.push_back(0);
  }
  return tangents;
}

std::vector<Real>
BezierUserObject::getParabolaWeigths(Real x1, Real y1, Real x2, Real y2, Real x3, Real y3)
{
  Real a = ((y2-y3)*(x1-x2)-(y1-y2)*(x2-x3))/((x2*x2-x3*x3)*(x1-x2)-(x1*x1-x2*x2)*(x2-x3));
  Real b = (y2-y3-a*(x2*x2-x3*x3)) / (x2-x3);
  // Real c = y1 - b*x1 - a*x1*x1;
  std::vector<Real> result = {a,b}; //,c};
  return result;
}

// std::pair<Real,Real>
// BezierUserObject::lerp(std::pair<Real,Real> a, std::pair<Real,Real> b, Real t) const
// {
//   // Linear interpolation between points a and b at "time" t in [0,1]
//   Real x = a.first + (b.first-a.first)*t;
//   Real y = a.second + (b.second-a.second)*t;
//   return std::make_pair(x, y);
// }
