/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO                                  */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

// AuxKernel to compute anistropic permeability component around a fault
// given by its (non-normalised) normal vectors, as well as
// longitudinal and transversal permeability components to assign
#include "RedbackFaultAnisotropicPermAux.h"

registerMooseObject("RedbackApp", RedbackFaultAnisotropicPermAux);

template <>
InputParameters
validParams<RedbackFaultAnisotropicPermAux>()
{
  MooseEnum component("x=0 y=1 z=2");
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("fault_normal_field", "Scalar field from which to infer vector normal to fault in that block");
  params.addParam<Real>("k_long", 1.0, "Permeability, longitudinal component");
  params.addParam<Real>("k_tran", 1.0, "Permeability, transversal component");
  params.addParam<MooseEnum>("row", component, "The permeability tensor component (row) to assign");
  params.addParam<MooseEnum>("column", component, "The permeability tensor component (column) to assign");

  return params;
}

RedbackFaultAnisotropicPermAux::RedbackFaultAnisotropicPermAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    _n(coupledGradient("fault_normal_field")),
    _k_long(getParam<Real>("k_long")),
    _k_tran(getParam<Real>("k_tran")),
    _i_row(getParam<MooseEnum>("row")),
    _i_column(getParam<MooseEnum>("column"))
{
}

Real
RedbackFaultAnisotropicPermAux::computeValue()
{
  RealTensorValue perm_tensor, transfer_matrix;
  // Set first column of transfer matrix as normalised normal vector
  RealVectorValue u(_n[_qp]);//(0), _n[_qp](1), _n[_qp](2));
  u /= u.norm();
  // Second column vector is orthogonal to first one
  RealVectorValue v(0, 0, 0);
  if (_n[_qp](2) == 0) {
    // normal vector in horizontal plane
    if (_n[_qp](1) == 0) {
      v(1) = 1;
      // keep other 2 components zero
    } else {
      v(0) = _n[_qp](1);
      v(1) = -_n[_qp](0);
      // keep third component zero
    }
  } else {
    // normal vector has non-zero vertical component
    // keep first component zero
    v(1) = _n[_qp](2);
    v(2) = -_n[_qp](1);
  }
  v /= v.norm();
  // Third vector as cross product to get orthonormal basis
  transfer_matrix = RealTensorValue(u, v, u.cross(v)).transpose();

  // Define permeability tensor in rotated (fault-aligned) referential
  RealTensorValue k_prime;
  k_prime.zero();
  k_prime(0, 0) = _k_tran;
  k_prime(1, 1) = _k_long;
  k_prime(2, 2) = _k_long;

  // Get perm tensor in original referential
  perm_tensor = transfer_matrix * (k_prime * transfer_matrix.transpose());

  return perm_tensor(_i_row, _i_column);
}
