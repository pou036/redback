/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef DISTANCETOINTERFACEAUX_H
#define DISTANCETOINTERFACEAUX_H

#include "AuxKernel.h"
#include <igl/readSTL.h>
#include <igl/AABB.h>

class DistanceToInterfaceAux : public VectorAuxKernel
{
public:
  DistanceToInterfaceAux(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual RealVectorValue computeValue() override;

  std::string _stl_name;

  Eigen::MatrixXd _V;
  Eigen::MatrixXi _F;
  igl::AABB<Eigen::MatrixXd,3> _tree;
  Eigen::MatrixXd _N;
};

#endif // DISTANCETOINTERFACEAUX_H
