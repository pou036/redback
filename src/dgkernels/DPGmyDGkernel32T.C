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
// Kernel for the term -<\{\nabla \tilde{u}\}.n_e, [u]>

#include "DPGmyDGkernel32T.h"

// MOOSE includes
#include "Assembly.h"
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel32T);

template <>
InputParameters
validParams<DPGmyDGkernel32T>()
{
  InputParameters params = validParams<DGKernel>();
  return params;
}

DPGmyDGkernel32T::DPGmyDGkernel32T(const InputParameters & parameters)
  : DGKernel(parameters)
{
}

Real
DPGmyDGkernel32T::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  switch (type)
  {
    case Moose::Element:
      r -= 0.5 * _grad_test[_i][_qp] * _normals[_qp]
        * (_u[_qp] - _u_neighbor[_qp]);
      break;

    case Moose::Neighbor:
      r -= 0.5 * _grad_test_neighbor[_i][_qp] * _normals[_qp]
        * (_u[_qp] - _u_neighbor[_qp]);
      break;
  }

  return r;
}

Real
DPGmyDGkernel32T::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;

  switch (type)
  {
    case Moose::ElementElement:
      r -= 0.5 * _grad_test[_i][_qp] * _normals[_qp]
        * _phi[_j][_qp];
      break;

    case Moose::ElementNeighbor:
      r += 0.5 * _grad_test[_i][_qp] * _normals[_qp]
        * _phi_neighbor[_j][_qp];
      break;

    case Moose::NeighborElement:
      r -= 0.5 * _grad_test_neighbor[_i][_qp] * _normals[_qp]
        * _phi[_j][_qp];
      break;

    case Moose::NeighborNeighbor:
      r += 0.5 * _grad_test_neighbor[_i][_qp] * _normals[_qp]
        * _phi_neighbor[_j][_qp];
      break;
  }

  return r;
}
