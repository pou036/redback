//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "InterfaceStress.h"
#include "RankTwoScalarTools.h"
#include "RankTwoTensor.h"
#include <cmath>
#include "ElasticityTensorTools.h"

template <>
InputParameters
validParams<InterfaceStress>()
{
  InputParameters params = validParams<InterfaceKernel>();
  params.addParam<std::string>("base_name_master", "Base name for master material");
  params.addParam<std::string>("base_name_slave", "Base name for slave material");
  params.addRequiredRangeCheckedParam<unsigned int>(
      "component",
      "component >= 0 & component <= 2",
      "An integer corresponding to the direction the variable "
      "this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addCoupledVar("other_disp_master", "The other master displacement variable (in 2D)");
  params.addCoupledVar("other_disp_slave", "The other slave displacement variable (in 2D)");
  params.addCoupledVar("pressure_master", 0.0, "Dimensionless pore pressure");
  params.addCoupledVar("pressure_slave", 0.0, "Dimensionless pore pressure");
  params.addClassDescription(
      "Implements an InterfaceKernel to handle the traction continuity (in 2D only!)");
  return params;
}

InterfaceStress::InterfaceStress(const InputParameters & parameters)
  : InterfaceKernel(parameters),
    _base_name0(isParamValid("base_name_master") ? getParam<std::string>("base_name_master") + "_"
                                                 : ""),
    _base_name1(isParamValid("base_name_slave") ? getParam<std::string>("base_name_slave") + "_"
                                                : ""),
    _stress0(getMaterialProperty<RankTwoTensor>(_base_name0 + "stress")),
    _stress1(getNeighborMaterialProperty<RankTwoTensor>(_base_name1 + "stress")),
    _Jacobian_mult0(getMaterialProperty<RankFourTensor>(_base_name0 + "Jacobian_mult")),
    _Jacobian_mult1(getNeighborMaterialProperty<RankFourTensor>(_base_name1 + "Jacobian_mult")),
    _component(getParam<unsigned int>("component")),
    _has_pres0(isCoupled("pressure_master")),
    _pressure0(_has_pres0 ? coupledValue("pressure_master") : _zero),
    _has_pres1(isCoupled("pressure_slave")),
    _pressure1(_has_pres1 ? coupledValue("pressure_slave") : _zero),
    _other_disp_master_num(coupled("other_disp_master")),
    _other_disp_slave_num(coupled("other_disp_slave")),
    _pf_master_num(coupled("pressure_master")),
    _pf_slave_num(coupled("pressure_slave"))
{
  if (!parameters.isParamValid("boundary"))
  {
    mooseError("In order to use the InterfaceStress dgkernel, you must specify a boundary where "
               "it will live.");
  }
}

Real
InterfaceStress::computeQpResidual(Moose::DGResidualType type)
{
  // continuity of each component of traction: (sigma_ij' - p) . n_i
  RankTwoTensor total_stress;
  RealVectorValue traction;

  switch (type)
  {
    case Moose::Element:
    {
      total_stress = _stress1[_qp];
      total_stress.addIa(-_pressure1[_qp]);
      traction = -total_stress * _normals[_qp];
      // the term stress0*normal is already accounted for as natural BC
      // which results in the appropriate traction continuity
      return traction(_component) * _test[_i][_qp];
    }

    case Moose::Neighbor:
    {
      total_stress = _stress0[_qp];
      total_stress.addIa(-_pressure0[_qp]);
      traction = total_stress * _normals[_qp];
      return traction(_component) * _test_neighbor[_i][_qp];
    }

    default:
      mooseError("InterfaceStress type not supported.");
  }
}

Real
InterfaceStress::computeQpJacobian(Moose::DGJacobianType type)
{
  switch (type)
  {
    case Moose::ElementElement:
      return 0;

    case Moose::NeighborNeighbor:
      return 0;

    case Moose::ElementNeighbor:
      return -ElasticityTensorTools::elasticJacobian(_Jacobian_mult1[_qp],
                                                     _component,
                                                     _component,
                                                     _normals[_qp],
                                                     _grad_phi_neighbor[_j][_qp]) *
             _test[_i][_qp];

    case Moose::NeighborElement:
      return ElasticityTensorTools::elasticJacobian(
                 _Jacobian_mult0[_qp], _component, _component, _normals[_qp], _grad_phi[_j][_qp]) *
             _test_neighbor[_i][_qp];
  }
  mooseError("Unsupported type '" + Moose::stringify(type) +
             "' in InterfaceStress::computeQpJacobian");
}

Real
InterfaceStress::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
  switch (type)
  {
    case Moose::ElementElement:
    {
      if (jvar == _other_disp_master_num)
        return 0;
      else if (jvar == _other_disp_slave_num)
        return -ElasticityTensorTools::elasticJacobian(_Jacobian_mult1[_qp],
                                                       _component,
                                                       1 - _component,
                                                       _normals[_qp],
                                                       _grad_phi_neighbor[_j][_qp]) *
               _test[_i][_qp];
      else if (jvar == _pf_master_num)
        return 0;
      else if (jvar == _pf_slave_num)
        return _test[_i][_qp] * _normals[_qp](_component);
      else
        mooseError("Unsupported jvar '" + Moose::stringify(jvar) +
                   "' in InterfaceStress::computeQpOffDiagJacobian, case ElementElement");
    }

    case Moose::NeighborNeighbor:
    {
      if (jvar == _other_disp_master_num)
        return ElasticityTensorTools::elasticJacobian(_Jacobian_mult0[_qp],
                                                      _component,
                                                      1 - _component,
                                                      _normals[_qp],
                                                      _grad_phi[_j][_qp]) *
               _test_neighbor[_i][_qp];
      else if (jvar == _other_disp_slave_num)
        return 0;
      else if (jvar == _pf_master_num)
        return -_test_neighbor[_i][_qp] * _normals[_qp](_component);
      else if (jvar == _pf_slave_num)
        return 0;
      else
        mooseError("Unsupported jvar '" + Moose::stringify(jvar) +
                   "' in InterfaceStress::computeQpOffDiagJacobian, case NeighborNeighbor");
    }

    case Moose::ElementNeighbor:
    {
      if (jvar == _other_disp_master_num)
        return 0;
      else if (jvar == _other_disp_slave_num)
        return -ElasticityTensorTools::elasticJacobian(_Jacobian_mult1[_qp],
                                                       _component,
                                                       1 - _component,
                                                       _normals[_qp],
                                                       _grad_phi_neighbor[_j][_qp]) *
               _test[_i][_qp];
      else if (jvar == _pf_master_num)
        return 0;
      else if (jvar == _pf_slave_num)
        return _test[_i][_qp] * _normals[_qp](_component);
      else
        mooseError("Unsupported jvar '" + Moose::stringify(jvar) +
                   "' in InterfaceStress::computeQpOffDiagJacobian, case ElementNeighbor");
    }

    case Moose::NeighborElement:
    {
      if (jvar == _other_disp_master_num)
        return ElasticityTensorTools::elasticJacobian(_Jacobian_mult0[_qp],
                                                      _component,
                                                      1 - _component,
                                                      _normals[_qp],
                                                      _grad_phi[_j][_qp]) *
               _test_neighbor[_i][_qp];
      else if (jvar == _other_disp_slave_num)
        return 0;
      else if (jvar == _pf_master_num)
        return -_test_neighbor[_i][_qp] * _normals[_qp](_component);
      else if (jvar == _pf_slave_num)
        return 0;
      else
        mooseError("Unsupported jvar '" + Moose::stringify(jvar) +
                   "' in InterfaceStress::computeQpOffDiagJacobian, case NeighborElement");
    }
  }
  mooseError("Unsupported type '" + Moose::stringify(type) +
             "' in InterfaceStress::computeQpOffDiagJacobian");
}
