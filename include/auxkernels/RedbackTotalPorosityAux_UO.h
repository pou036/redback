#ifndef RedbackTotalPorosityAux_UO_H
#define RedbackTotalPorosityAux_UO_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

#include "RedbackElementParameters.h"

// Forward declarations
class RedbackTotalPorosityAux_UO;

template <>
InputParameters validParams<RedbackTotalPorosityAux_UO>();

class RedbackTotalPorosityAux_UO : public AuxKernel
{
public:
  RedbackTotalPorosityAux_UO(const InputParameters & parameters);
  virtual ~RedbackTotalPorosityAux_UO()
  {
  }

protected:
  virtual Real computeValue();
  bool _is_mechanics_on; //, _is_chemistry_on;
  Real _chemo_mechanical_porosity_coeff;

private:
  const VariableValue & _delta_porosity_mech;
  // MaterialProperty<Real> & _delta_porosity_mech;
  const MaterialProperty<Real> & _delta_porosity_chem;
  //const MaterialProperty<Real> & _initial_porosity;

  const RedbackElementParameters* _common_redback_material_parameters;
  const RedbackMaterialParameterUserObject* _initial_porosity_uo;

  const MaterialProperty<Real> & _mass_removal_rate;
};

#endif // RedbackTotalPorosityAux_UO_H
