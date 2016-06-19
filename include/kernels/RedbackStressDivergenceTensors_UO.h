#ifndef RedbackStressDivergenceTensors_UO_H
#define RedbackStressDivergenceTensors_UO_H

#include "Kernel.h"
#include "RankFourTensor.h"
#include "RankTwoTensor.h"

#include "RedbackElementParameters.h"

// Forward Declarations
class RedbackStressDivergenceTensors_UO;
class RankFourTensor;
class RankTwoTensor;

template <>
InputParameters validParams<RedbackStressDivergenceTensors_UO>();

/**
 * RedbackStressDivergenceTensors_UO mostly copies from StressDivergence.  There
 * are small changes to use
 * RankFourTensor and RankTwoTensors instead of SymmElasticityTensors and
 * SymmTensors.  This is done
 * to allow for more mathematical transparency.
 */
class RedbackStressDivergenceTensors_UO : public Kernel
{
public:
  RedbackStressDivergenceTensors_UO(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const VariableValue & _pore_pres;
  RealVectorValue _poromech_stress_row;

  const MaterialProperty<RankTwoTensor> & _stress;
  const MaterialProperty<RankFourTensor> & _Jacobian_mult;
  // MaterialProperty<RankTwoTensor> & _d_stress_dT;

  const unsigned int _component;

  //const MaterialProperty<Real> & _biot_coeff;

  // the container that holds all of the redback material parameters
  // NB it is "common" in the sense that it is shared by more than one entity
  const RedbackElementParameters* _common_redback_material_parameters;
  const RedbackMaterialParameterUserObject*  _biot_coeff_uo;

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

#endif // RedbackStressDivergenceTensors_UO_H
