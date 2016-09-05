#ifndef REDBACKSANDPRODUCTIONAUX_H
#define REDBACKSANDPRODUCTIONAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"
#include "Function.h"

// Forward declarations
class RedbackSandProductionAux;

template <>
InputParameters validParams<RedbackSandProductionAux>();

class RedbackSandProductionAux : public AuxKernel
{
public:
  RedbackSandProductionAux(const InputParameters & parameters);
  virtual ~RedbackSandProductionAux()
  {
  }

protected:
  virtual Real computeValue();
  Function & _function;

private:
  const VariableValue & _total_porosity;

  Real _lambda_1, _lambda_2;

  const MaterialProperty<Real> & _sand_production_rate;
  const MaterialProperty<Real> & _eqv_plastic_strain;
  const MaterialProperty<Real> & _mean_stress;
};

#endif // REDBACKSANDPRODUCTIONAUX_H_H
