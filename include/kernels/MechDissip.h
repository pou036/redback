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

#ifndef MECHDISSIP_H
#define MECHDISSIP_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class MechDissip;

template<>
InputParameters validParams<MechDissip>();


class MechDissip : public Kernel
{
public:
  MechDissip(const std::string & name, InputParameters parameters);
  virtual ~MechDissip();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  VariableValue &_pressure;
  MaterialProperty<RankTwoTensor> &_stress; // equivalent stress
  MaterialProperty<Real> & _activation_energy;
  MaterialProperty<Real> & _mech_dissipation;
  MaterialProperty<Real> & _equivalent_stress;
  MaterialProperty<Real> & _heat_capacity;
  //Real _ref_pe_rate;
  //Real _exponent;
  //Real _activation_energy;
  Real _gas_constant;
      
  Real macaulayBracket(Real);
};


#endif /* MECHDISSIP_H */
