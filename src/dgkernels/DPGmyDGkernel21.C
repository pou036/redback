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
// Kernel for the term <1/h_e * [\kappa u], [\tilde{u}]>

#include "DPGmyDGkernel21.h"

// MOOSE includes
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel21);

template <>
InputParameters
validParams<DPGmyDGkernel21>()
{
  InputParameters params = validParams<DGKernel>();
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  return params;
}

DPGmyDGkernel21::DPGmyDGkernel21(const InputParameters & parameters)
  : DGKernel(parameters),
    _kappa(coupledValue("kappa")),
    _kappa_neighbor(coupledNeighborValue("kappa"))
{
}

Real
DPGmyDGkernel21::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

  switch (type)
  {
    case Moose::Element:
      r += (1/h_e) * (_kappa[_qp]*_u[_qp] - _kappa_neighbor[_qp]*_u_neighbor[_qp]) * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r -= (1/h_e) * (_kappa[_qp]*_u[_qp] - _kappa_neighbor[_qp]*_u_neighbor[_qp]) * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
DPGmyDGkernel21::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;

  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

  switch (type)
  {
    case Moose::ElementElement:
      r += (_kappa[_qp]/h_e) * _phi[_j][_qp] * _test[_i][_qp];
      break;

    case Moose::ElementNeighbor:
      r -= (_kappa_neighbor[_qp]/h_e) * _phi_neighbor[_j][_qp] * _test[_i][_qp];
      break;

    case Moose::NeighborElement:
      r -= (_kappa[_qp]/h_e) *_phi[_j][_qp] * _test_neighbor[_i][_qp];
      break;

    case Moose::NeighborNeighbor:
      r += (_kappa_neighbor[_qp]/h_e) * _phi_neighbor[_j][_qp] * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}
