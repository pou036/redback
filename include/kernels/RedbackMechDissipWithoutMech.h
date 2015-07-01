/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKMECHDISSIPWITHOUTMECH_H
#define REDBACKMECHDISSIPWITHOUTMECH_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class RedbackMechDissipWithoutMech;

template<>
InputParameters validParams<RedbackMechDissipWithoutMech>();


class RedbackMechDissipWithoutMech : public Kernel
{
public:
  RedbackMechDissipWithoutMech(const std::string & name, InputParameters parameters);
  virtual ~RedbackMechDissipWithoutMech();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  //VariableValue & _pressure;
  const MaterialProperty<Real> & _mechanical_dissipation_no_mech;
  const MaterialProperty<Real> & _mechanical_dissipation_jac_no_mech;

private:
  Real _time_factor;
};


#endif /* REDBACKMECHDISSIPWITHOUTMECH_H */
