#ifndef REDBACKTOTALPOROSITYAUX_H
#define REDBACKTOTALPOROSITYAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

// Forward declarations
class RedbackTotalPorosityAux;

template <>
InputParameters validParams<RedbackTotalPorosityAux>();

class RedbackTotalPorosityAux : public AuxKernel
{
public:
  RedbackTotalPorosityAux(const InputParameters & parameters);
  virtual ~RedbackTotalPorosityAux()
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
  const MaterialProperty<Real> & _initial_porosity;

  const MaterialProperty<Real> & _mass_removal_rate;
};

#endif // REDBACKTOTALPOROSITYAUX_H
