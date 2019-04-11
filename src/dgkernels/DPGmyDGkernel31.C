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
// Kernel for the term <1/h_e * [\tilde{u}], [v]>

#include "DPGmyDGkernel31.h"

// MOOSE includes
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel31);

template <>
InputParameters
validParams<DPGmyDGkernel31>()
{
  InputParameters params = validParams<DGKernel>();
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPGmyDGkernel31::DPGmyDGkernel31(const InputParameters & parameters)
  : DGKernel(parameters),
  _k_var(coupled("coupled_variable")),
  _coupled_variable(coupledValue("coupled_variable")),
  _coupled_neighbor_variable(coupledNeighborValue("coupled_variable")),
  _phi_cvariable(_assembly.phi(*getVar("coupled_variable",0))),
  //_phi_cvar_neighbor(_assembly.phiNeighbor(*getVar("coupled_variable",0)))
  _phi_cvar_neighbor(_assembly.phi(*getVar("coupled_variable",0))) // TODO: use proper neighbor!!!
{
}

Real
DPGmyDGkernel31::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

  switch (type)
  {
    case Moose::Element:
      r += (1/h_e) * (_coupled_variable[_qp] - _coupled_neighbor_variable[_qp]) * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r -= (1/h_e) * (_coupled_variable[_qp] - _coupled_neighbor_variable[_qp]) * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
DPGmyDGkernel31::computeQpJacobian(Moose::DGJacobianType /*type*/)
{
  return 0;
}

Real
DPGmyDGkernel31::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
  Real r = 0;

  if (jvar == _k_var)
  {
    Real h_e = (_current_elem->hmax() + _neighbor_elem->hmax())/2.;

    switch (type)
    {
      case Moose::ElementElement:
        r += (1/h_e) * _phi_cvariable[_j][_qp] * _test[_i][_qp];
        break;

      case Moose::ElementNeighbor:
        r -= (1/h_e) * _phi_cvar_neighbor[_j][_qp] * _test[_i][_qp];
        break;

      case Moose::NeighborElement:
        r -= (1/h_e) * _phi_cvariable[_j][_qp] * _test_neighbor[_i][_qp];
        break;

      case Moose::NeighborNeighbor:
        r += (1/h_e) * _phi_cvar_neighbor[_j][_qp] * _test_neighbor[_i][_qp];
        break;
    }
  }

  return r;
}
