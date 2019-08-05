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

#ifndef INTERFACESTRESS_H
#define INTERFACESTRESS_H

#include "InterfaceKernel.h"
#include "RankTwoTensor.h"

// Forward Declarations
class InterfaceStress;

template <>
InputParameters validParams<InterfaceStress>();

/**
 * DG kernel for interfacing diffusion between two variables on adjacent blocks
 */
class InterfaceStress : public InterfaceKernel
{
public:
  InterfaceStress(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  const MaterialProperty<RankTwoTensor> & _stress0;
  const MaterialProperty<RankTwoTensor> & _stress1;
  const unsigned int _component;
};

#endif
