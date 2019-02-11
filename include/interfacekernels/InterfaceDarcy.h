/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef INTERFACEDARCY_H
#define INTERFACEDARCY_H

#include "InterfaceKernel.h"

// Forward Declarations
class InterfaceDarcy;

template <>
InputParameters validParams<InterfaceDarcy>();

/**
 * DG kernel for interfacing diffusion between two variables on adjacent blocks
 */
class InterfaceDarcy : public InterfaceKernel
{
public:
  InterfaceDarcy(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  const MaterialProperty<Real> & _Le;
  Real _Le_fault;
  const MaterialProperty<RealVectorValue> & _gravity_term;
  Real _thickness;
};

#endif
