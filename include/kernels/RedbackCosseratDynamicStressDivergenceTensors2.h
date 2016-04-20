/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef REDBACKCOSSERATDYNAMICSTRESSDIVERGENCETENSORS2_H
#define REDBACKCOSSERATDYNAMICSTRESSDIVERGENCETENSORS2_H

#include "DynamicStressDivergenceTensors.h"

//Forward Declarations
class RedbackCosseratDynamicStressDivergenceTensors2;

template<>
InputParameters validParams<RedbackCosseratDynamicStressDivergenceTensors2>();

class RedbackCosseratDynamicStressDivergenceTensors2 : public DynamicStressDivergenceTensors
{
public:
  RedbackCosseratDynamicStressDivergenceTensors2(const InputParameters & parameters);

protected:
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:
  const unsigned int _wc_x_var;
  const unsigned int _wc_y_var;
  const unsigned int _wc_z_var;
};

#endif //RedbackCosseratDynamicStressDivergenceTensors2_H
