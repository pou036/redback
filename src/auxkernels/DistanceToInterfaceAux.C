/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "DistanceToInterfaceAux.h"
#include <igl/point_mesh_squared_distance.h>

registerMooseObject("RedbackApp", DistanceToInterfaceAux);

template <>
InputParameters
validParams<DistanceToInterfaceAux>()
{
  InputParameters params = validParams<VectorAuxKernel>();
  params.addClassDescription(
      "Compute the minimal distance to the stl interface at every point of the sideset");
  params.addRequiredParam<std::string>("stl_name","name of the stl file (with the extension)");
  return params;
}

DistanceToInterfaceAux::DistanceToInterfaceAux(const InputParameters & parameters)
  : VectorAuxKernel(parameters),
    _stl_name(getParam<std::string>("stl_name"))
{
  igl::readSTL(_stl_name, _V, _F, _N);
}

RealVectorValue
DistanceToInterfaceAux::computeValue()
{
  Eigen::VectorXd sqrD;
  Eigen::VectorXi I;
  Eigen::MatrixXd C;
  Eigen::MatrixXd P = (Eigen::MatrixXd(1,3)<<
       (*_current_node)(0),(*_current_node)(1),(*_current_node)(2)).finished();
  igl::point_mesh_squared_distance(P,_V,_F,sqrD,I,C);
  Eigen::MatrixXd D = C-P;
  // std::cout<<sqrD(0)<<std::endl;
  return RealVectorValue(D(0,0),D(0,1),D(0,2));
}
