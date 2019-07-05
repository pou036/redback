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
// Kernel for the term -<\{\nabla u\} . n_e, [\tilde{u}]>

#include "DPGmyDGkernel32.h"

// MOOSE includes
#include "Assembly.h"
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel32);

template <>
InputParameters
validParams<DPGmyDGkernel32>()
{
  InputParameters params = validParams<DGKernel>();
  return params;
}

DPGmyDGkernel32::DPGmyDGkernel32(const InputParameters & parameters)
  : DGKernel(parameters)
{
}

Real
DPGmyDGkernel32::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  switch (type)
  {
    case Moose::Element:
      r -= 0.5 * (_grad_u[_qp] * _normals[_qp]
        + _grad_u_neighbor[_qp] * _normals[_qp])
        * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r += 0.5 * (_grad_u[_qp] * _normals[_qp]
        + _grad_u_neighbor[_qp] * _normals[_qp])
        * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
DPGmyDGkernel32::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;
  switch (type)
  {
    case Moose::ElementElement:
      r -= 0.5 *_grad_phi[_j][_qp] * _normals[_qp]
        * _test[_i][_qp];
      break;

    case Moose::ElementNeighbor:
      r -= 0.5 * _grad_phi_neighbor[_j][_qp] * _normals[_qp]
        * _test[_i][_qp];
      break;

    case Moose::NeighborElement:
      r += 0.5 * _grad_phi[_j][_qp] * _normals[_qp]
        * _test_neighbor[_i][_qp];
      break;

    case Moose::NeighborNeighbor:
      r += 0.5 * _grad_phi_neighbor[_j][_qp] * _normals[_qp]
        * _test_neighbor[_i][_qp];
      break;
  }
  return r;
}

