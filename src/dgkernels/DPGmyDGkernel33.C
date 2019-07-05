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
// Kernel for the term <1/h_e * [\tilde{u}], [u]>

#include "DPGmyDGkernel33.h"

// MOOSE includes
#include "Assembly.h"
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel33);

template <>
InputParameters
validParams<DPGmyDGkernel33>()
{
  InputParameters params = validParams<DGKernel>();
  return params;
}

DPGmyDGkernel33::DPGmyDGkernel33(const InputParameters & parameters)
  : DGKernel(parameters)
{
}

Real
DPGmyDGkernel33::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

  switch (type)
  {
    case Moose::Element:
      r += (1/h_e) * (_u[_qp] - _u_neighbor[_qp]) * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r -= (1/h_e) * (_u[_qp] - _u_neighbor[_qp]) * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
DPGmyDGkernel33::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;

  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

  switch (type)
  {
    case Moose::ElementElement:
      r += (1/h_e) * _phi[_j][_qp] * _test[_i][_qp];
      break;

    case Moose::ElementNeighbor:
      r -= (1/h_e) * _phi_neighbor[_j][_qp] * _test[_i][_qp];
      break;

    case Moose::NeighborElement:
      r -= (1/h_e) * _phi[_j][_qp] * _test_neighbor[_i][_qp];
      break;

    case Moose::NeighborNeighbor:
      r += (1/h_e) * _phi_neighbor[_j][_qp] * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}
