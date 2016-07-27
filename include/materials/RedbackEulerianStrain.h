/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef RedbackEulerianStrain_H
#define RedbackEulerianStrain_H

#include "ComputeStrainBase.h"

/**
 * RedbackEulerianStrain defines a strain increment and rotation increment, for finite strains.
 */
class RedbackEulerianStrain : public ComputeStrainBase
{
public:
  RedbackEulerianStrain(const InputParameters & parameters);

  virtual void computeProperties();

protected:
  virtual void initQpStatefulProperties();
  virtual void computeQpStrain();

  MaterialProperty<RankTwoTensor> & _strain_rate;
  MaterialProperty<RankTwoTensor> & _strain_increment;
  MaterialProperty<RankTwoTensor> & _mechanical_strain_old;
  MaterialProperty<RankTwoTensor> & _total_strain_old;
  MaterialProperty<RankTwoTensor> & _rotation_increment;

  MaterialProperty<RankTwoTensor> & _deformation_gradient;
  MaterialProperty<RankTwoTensor> & _deformation_gradient_old;

  const MaterialProperty<RankTwoTensor> & _stress_free_strain_increment;

  const Real & _current_elem_volume;
  std::vector<RankTwoTensor> _Fhat;


  unsigned int _neta;
  std::vector<const VariableValue *> _eta;
  std::vector<const VariableGradient *> _grad_eta;
  std::vector<const VariableGradient *> _grad_eta_old;



  /*
  const VariableValue & _eta_x;
  const VariableValue & _eta_y;
  const VariableValue & _eta_z;

  const VariableValue & _grad_eta_x;
  const VariableValue & _grad_eta_y;
  const VariableValue & _grad_eta_z;

  const VariableValue & _grad_eta_x_old;
  const VariableValue & _grad_eta_y_old;
  const VariableValue & _grad_eta_z_old;
  */

private:
 /* const VariableValue & _vel_x;
  const VariableValue & _vel_y;
  const VariableValue & _vel_z;

  RealVectorValue _velocity;*/

};

#endif //RedbackEulerianStrain_H
