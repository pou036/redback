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

#ifndef REDBACKMECHDISSIP_H
#define REDBACKMECHDISSIP_H

#include "Kernel.h"
#include "RankTwoTensor.h"

class RedbackMechDissip;

template <>
InputParameters validParams<RedbackMechDissip>();

class RedbackMechDissip : public Kernel
{
public:
  RedbackMechDissip(const InputParameters & parameters);
  virtual ~RedbackMechDissip();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  // const VariableValue & _pressure;
  const MaterialProperty<Real> & _mechanical_dissipation;
  const MaterialProperty<Real> & _mechanical_dissipation_jac;
  
  // d(plastic_heat)/d(total_strain)
  const MaterialProperty<RankTwoTensor> & _dplastic_heat_dstrain;
  const MaterialProperty<RankTwoTensor> & _dplastic_heat_dcurvature;
  
  // number of coupled displacement variables
  unsigned int _ndisp;

  // MOOSE variable number for the displacement variables
  std::vector<unsigned int> _disp_var;
  
    // number of coupled displacement variables
  unsigned int _nwc;

  // MOOSE variable number for the displacement variables
  std::vector<unsigned int> _wc_var;


private:
  Real _time_factor;
};

#endif /* REDBACKMECHDISSIP_H */
