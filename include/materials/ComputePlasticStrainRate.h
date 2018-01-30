/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef COMPUTEPLASTICSTRAINRATE_H
#define COMPUTEPLASTICSTRAINRATE_H

#include "DerivativeMaterialInterface.h"
#include "Material.h"
#include "RankFourTensor.h"
#include "RankTwoTensor.h"

class ComputePlasticStrainRate;

template <>
InputParameters
validParams<ComputePlasticStrainRate>();

/**
 * ComputePlasticStrainRate computes stress * (plastic_strain - plastic_strain_old)
 * and, if currentlyComputingJacobian, then the derivative of this quantity wrt total strain
 */
class ComputePlasticStrainRate : public DerivativeMaterialInterface<Material>
{
public:
  ComputePlasticStrainRate(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  /// optional parameter that allows multiple mechanics materials to be defined
  std::string _base_name;

  /// plastic strain
  const MaterialProperty<RankTwoTensor> & _plastic_strain;

  /// old value of plastic strain
  const MaterialProperty<RankTwoTensor> & _plastic_strain_old;

  MaterialProperty<RankTwoTensor> & _plastic_strain_rate;
};

#endif // COMPUTEPLASTICSTRAINRATE_H
