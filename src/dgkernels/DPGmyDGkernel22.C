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
// Kernel for the term <[\kappa\nabla v . n_e], \{\tilde{u}\}>

#include "DPGmyDGkernel22.h"

// MOOSE includes
#include "MooseVariableFE.h"

#include "libmesh/utility.h"

registerMooseObject("RedbackApp", DPGmyDGkernel22);

template <>
InputParameters
validParams<DPGmyDGkernel22>()
{
  InputParameters params = validParams<DGKernel>();
  params.addRequiredCoupledVar("kappa", "Diffusivity AuxVariable");
  params.addRequiredCoupledVar("coupled_variable", "Coupled scalar variable");
  return params;
}

DPGmyDGkernel22::DPGmyDGkernel22(const InputParameters & parameters)
  : DGKernel(parameters),
    _kappa(coupledValue("kappa")),
    _kappa_neighbor(coupledNeighborValue("kappa")),
    _k_var(coupled("coupled_variable")),
    _grad_coupled_variable(coupledGradient("coupled_variable")),
    _grad_cvar_neighbor(coupledNeighborGradient("coupled_variable")),
    _grad_phi_cvariable(_assembly.gradPhi(*getVar("coupled_variable",0))),
    _grad_phi_cvar_neighbor(_assembly.gradPhiNeighbor(*getVar("coupled_variable",0)))
{
}

Real
DPGmyDGkernel22::computeQpResidual(Moose::DGResidualType type)
{
  Real r = 0;

  switch (type)
  {
    case Moose::Element:
      r += 0.5 * (_kappa[_qp] * _grad_coupled_variable[_qp] * _normals[_qp]
        - _kappa_neighbor[_qp] * _grad_cvar_neighbor[_qp] * _normals[_qp])
        * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      r += 0.5 * (_kappa[_qp] * _grad_coupled_variable[_qp] * _normals[_qp]
        - _kappa_neighbor[_qp] * _grad_cvar_neighbor[_qp] * _normals[_qp])
        * _test_neighbor[_i][_qp];
      break;
  }

  return r;
}

Real
DPGmyDGkernel22::computeQpJacobian(Moose::DGJacobianType /*type*/)
{
  return 0;
}

Real
DPGmyDGkernel22::computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar)
{
  if (jvar == _k_var)
  {
    Real r = 0;

    switch (type)
    {
      case Moose::ElementElement:
        r += 0.5 * _kappa[_qp] * _grad_phi_cvariable[_j][_qp] * _normals[_qp]
          * _test[_i][_qp];
        break;

      case Moose::ElementNeighbor:
        r -= 0.5 * _kappa_neighbor[_qp] * _grad_phi_cvar_neighbor[_j][_qp] * _normals[_qp]
          * _test[_i][_qp];
        break;

      case Moose::NeighborElement:
        r += 0.5 * _kappa[_qp] * _grad_phi_cvariable[_j][_qp] * _normals[_qp]
          * _test_neighbor[_i][_qp];
        break;

      case Moose::NeighborNeighbor:
        r -= 0.5 * _kappa_neighbor[_qp] * _grad_phi_cvar_neighbor[_j][_qp] * _normals[_qp]
          * _test_neighbor[_i][_qp];
        break;
    }
  }
  return 0;
}
