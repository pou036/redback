#ifndef REDBACKTOTALPOROSITYAUX_H
#define REDBACKTOTALPOROSITYAUX_H

#include "AuxKernel.h"
#include "RankTwoTensor.h"

//Forward declarations
class RedbackTotalPorosityAux;

template<>
InputParameters validParams<RedbackTotalPorosityAux>();


class RedbackTotalPorosityAux : public AuxKernel
{
public:
  RedbackTotalPorosityAux(const std::string & name, InputParameters parameters);
  virtual ~RedbackTotalPorosityAux() {}

protected:
  virtual Real computeValue();
  bool _is_mechanics_on;//, _is_chemistry_on;

private:
  VariableValue & _delta_porosity_mech;
  //MaterialProperty<Real> & _delta_porosity_mech;
  MaterialProperty<Real> & _delta_porosity_chem;
  MaterialProperty<Real> & _initial_porosity;
};

#endif // REDBACKTOTALPOROSITYAUX_H
