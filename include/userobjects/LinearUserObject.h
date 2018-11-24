//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef LINEARUSEROBJECT_H
#define LINEARUSEROBJECT_H

#include "GeneralUserObject.h"
#include "GriddedData.h"

// Forward declarations
// class GriddedData;

class LinearUserObject;

template <>
InputParameters validParams<LinearUserObject>();

/**
 * Computes the average value of a variable on each block
 */
class LinearUserObject : public GeneralUserObject
{
public:
  LinearUserObject(const InputParameters & parameters);

  /**
   * Given a block ID return the average value for a variable on that block
   *
   * Note that accessor functions on UserObjects like this _must_ be const.
   * That is because the UserObject system returns const references to objects
   * trying to use UserObjects.  This is done for parallel correctness.
   *
   * @return The average value of a variable on that block.
   */
  Real value(Real t, const Point & p) const;

  /**
   * Called on every "object" (like every element or node).
   * In this case, it is called at every quadrature point on every element.
   */
  virtual void execute() override {}
  virtual void initialize() override;
  virtual void finalize() override {}

protected:
private:
  std::vector<Real> _positions;
  std::vector<Real> _fcn;
  Real _initial_value;
  /// dimension of the grid
  unsigned int _dim;

  /**
   * _axes specifies how to embed the grid into the MOOSE coordinate frame
   * if _axes[i] = 0 then the i_th axes of the grid lies along the MOOSE x direction
   * if _axes[i] = 1 then the i_th axes of the grid lies along the MOOSE y direction
   * if _axes[i] = 2 then the i_th axes of the grid lies along the MOOSE z direction
   * if _axes[i] = 3 then the i_th axes of the grid lies along the MOOSE time direction
   */
  std::vector<int> _axes;

  /// the grid
  std::vector<std::vector<Real>> _grid;
  std::vector<PostprocessorName> _ppn;

  /**
   * This does the core work.  Given a point, pt, defined
   * on the grid (not the MOOSE simulation reference frame),
   * interpolate the gridded data to this point
   */
  Real sample(const std::vector<Real> & pt) const;

  /**
   * Operates on monotonically increasing in_arr.
   * Finds lower_x and upper_x which satisfy in_arr[lower_x] < x <= in_arr[upper_x].
   * End conditions: if x<in_arr[0] then lower_x = 0 = upper_x is returned
   *                 if x>in_arr[N-1] then lower_x = N-1 = upper_x is returned (N=size of in_arr)
   *
   * @param in_arr The monotonically increasing vector of real numbers
   * @param x The real value for which we want the neighbor indices
   * @param lower_x Upon return will contain lower_x specified above
   * @param upper_x Upon return will contain upper_x specified above
   */
  void getNeighborIndices(std::vector<Real> in_arr,
                          Real x,
                          unsigned int & lower_x,
                          unsigned int & upper_x) const;
};

#endif
