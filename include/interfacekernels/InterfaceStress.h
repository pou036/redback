//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

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
  virtual Real computeQpOffDiagJacobian(Moose::DGJacobianType type, unsigned int jvar);

  std::string _base_name0;
  std::string _base_name1;
  const MaterialProperty<RankTwoTensor> & _stress0;
  const MaterialProperty<RankTwoTensor> & _stress1;
  const MaterialProperty<RankFourTensor> & _Jacobian_mult0;
  const MaterialProperty<RankFourTensor> & _Jacobian_mult1;
  const unsigned int _component;
  bool _has_pres0;
  const VariableValue & _pressure0;
  bool _has_pres1;
  const VariableValue & _pressure1;
  const unsigned int _other_disp_master_num;
  const unsigned int _other_disp_slave_num;
  const unsigned int _pf_master_num;
  const unsigned int _pf_slave_num;
};

#endif
