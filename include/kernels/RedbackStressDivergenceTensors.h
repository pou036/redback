#ifndef REDBACKSTRESSDIVERGENCETENSORS_H
#define REDBACKSTRESSDIVERGENCETENSORS_H

#include "Kernel.h"
#include "ElasticityTensorR4.h"
#include "RankTwoTensor.h"

// Forward Declarations
class RedbackStressDivergenceTensors;
class ElasticityTensorR4;
class RankTwoTensor;

template <>
InputParameters validParams<RedbackStressDivergenceTensors>();

/**
 * RedbackStressDivergenceTensors mostly copies from StressDivergence.  There
 * are small changes to use
 * RankFourTensor and RankTwoTensors instead of SymmElasticityTensors and
 * SymmTensors.  This is done
 * to allow for more mathematical transparancy.
 */
class RedbackStressDivergenceTensors : public Kernel
{
public:
  RedbackStressDivergenceTensors(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const VariableValue & _pore_pres;
  RealVectorValue _poromech_stress_row;

  const MaterialProperty<RankTwoTensor> & _stress;
  const MaterialProperty<ElasticityTensorR4> & _Jacobian_mult;
  // MaterialProperty<RankTwoTensor> & _d_stress_dT;

  const unsigned int _component;

  const MaterialProperty<Real> & _biot_coeff;

private:
  const bool _xdisp_coupled;
  const bool _ydisp_coupled;
  const bool _zdisp_coupled;
  const bool _temp_coupled;
  const bool _pore_pres_coupled;

  const unsigned int _xdisp_var;
  const unsigned int _ydisp_var;
  const unsigned int _zdisp_var;
  const unsigned int _temp_var;
  const unsigned int _porepressure_var;

  const MaterialProperty<RealVectorValue> & _gravity_term;
};

#endif // REDBACKSTRESSDIVERGENCETENSORS_H
