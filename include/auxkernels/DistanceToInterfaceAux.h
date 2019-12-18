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

class DistanceToInterfaceAux;

template <>
InputParameters validParams<DistanceToInterfaceAux>();

class DistanceToInterfaceAux : public VectorAuxKernel
{
public:
  DistanceToInterfaceAux(const InputParameters & parameters);

protected:
  virtual RealVectorValue computeValue() override;

  std::string _stl_name;

  Eigen::MatrixXd _V;
  Eigen::MatrixXi _F;
  Eigen::MatrixXd _N;
};

#endif // DISTANCETOINTERFACEAUX_H
