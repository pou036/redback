//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef BEZIERUSEROBJECT_H
#define BEZIERUSEROBJECT_H

#include "GeneralUserObject.h"

// Forward declarations
// class GriddedData;

class BezierUserObject;

template <>
InputParameters validParams<BezierUserObject>();

/**
 * Computes the average value of a variable on each block
 */
class BezierUserObject : public GeneralUserObject
{
public:
  BezierUserObject(const InputParameters & parameters);

  /**
   * Given a block ID return the average value for a variable on that block
   *
   * Note that accessor functions on UserObjects like this _must_ be const.
   * That is because the UserObject system returns const references to objects
   * trying to use UserObjects.  This is done for parallel correctness.
   *
   * @return The average value of a variable on that block.
   */
  Real value(const Point & p) const;

  /**
   * Called on every "object" (like every element or node).
   * In this case, it is called at every quadrature point on every element.
   */
  virtual void execute() override {}
  virtual void initialize() override;
  virtual void finalize() override {}

protected:
private:
  std::vector<Real> _points_x;
  std::vector<Real> _points_y;
  Real _initial_value;
  std::vector<std::vector<std::pair<Real, Real>>> _abcd_segments;
  std::vector<PostprocessorName> _ppn;

  std::vector<Real> getTangents(std::vector<Real> x_array, std::vector<Real> y_array);

  std::vector<Real> getParabolaWeigths(Real x1, Real y1, Real x2, Real y2, Real x3, Real y3);

  // std::pair<Real,Real> lerp(std::pair<Real,Real> a, std::pair<Real,Real> b, Real t) const;
};

#endif
