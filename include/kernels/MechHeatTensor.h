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

#ifndef MECHHEATTENSOR_H
#define MECHHEATTENSOR_H

#include "RankTwoTensor.h"
#include "Kernel.h"

class MechHeatTensor;

template<>
InputParameters validParams<MechHeatTensor>();


class MechHeatTensor : public Kernel
{
public:
  MechHeatTensor(const std::string & name, InputParameters parameters);
  virtual ~MechHeatTensor();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  VariableValue &_pressure;
  MaterialProperty<Real> & _equivalent_stress;
  MaterialProperty<Real> & _mises_strain_rate;
  //MaterialProperty<RankTwoTensor> &_stress;
  MaterialProperty<Real> & _gr;
  MaterialProperty<Real> & _m;
  MaterialProperty<Real> & _ar;

};


#endif /* MECHHEATTENSOR_H */
