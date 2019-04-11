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
// Kernel for the term <[\kappa\nabla \tilde{u} . n_e], \{v\}>

#include "DPGmyDGkernel22T.h"

// MOOSE includes
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel22T);

template <>
InputParameters
validParams<DPGmyDGkernel22T>()
{
  InputParameters params = validParams<DGKernel>();
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPGmyDGkernel22T::DPGmyDGkernel22T(const InputParameters & parameters)
  : DGKernel(parameters),
    _kappa(coupledValue("kappa")),
    _kappa_neighbor(coupledNeighborValue("kappa")),
    _k_var(coupled("coupled_variable")),
    _coupled_variable(coupledValue("coupled_variable")),
    _coupled_neighbor_variable(coupledNeighborValue("coupled_variable")),
    _phi_cvariable(_assembly.phi(*getVar("coupled_variable",0))),
    //_phi_cvar_neighbor(_assembly.phiNeighbor(*getVar("coupled_variable",0)))
    _phi_cvar_neighbor(_assembly.phi(*getVar("coupled_variable",0))) //TODO: should use line above but crashing!
{
}

Real
DPGmyDGkernel22T::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  switch (type)
  {
    case Moose::Element:
      r += 0.5 * _kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp]
        * (_coupled_variable[_qp] + _coupled_neighbor_variable[_qp]);
      break;

    case Moose::Neighbor:
      r -= 0.5 * _kappa_neighbor[_qp] * _grad_test_neighbor[_i][_qp] * _normals[_qp]
        * (_coupled_variable[_qp] + _coupled_neighbor_variable[_qp]);
      break;
  }

  return r;
}

Real
DPGmyDGkernel22T::computeQpJacobian(Moose::DGJacobianType /*type*/)
{
  return 0;
}

Real
DPGmyDGkernel22T::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real r = 0;

    switch (type)
    {
      case Moose::ElementElement:
        r += 0.5 * _kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp]
          * _phi_cvariable[_j][_qp];
        break;

      case Moose::ElementNeighbor:
        r += 0.5 * _kappa[_qp] * _grad_test[_i][_qp] * _normals[_qp]
          * _phi_cvar_neighbor[_j][_qp];
        break;

      case Moose::NeighborElement:
        r -= 0.5 * _kappa_neighbor[_qp] * _grad_test_neighbor[_i][_qp] * _normals[_qp]
          * _phi_cvariable[_j][_qp];
        break;

      case Moose::NeighborNeighbor:
        r -= 0.5 * _kappa_neighbor[_qp] * _grad_test_neighbor[_i][_qp] * _normals[_qp]
          * _phi_cvar_neighbor[_j][_qp];
        break;
    }

    return  r;
  }
  return 0;
}
