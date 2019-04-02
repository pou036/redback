/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*                 (c) 2019 CSIRO                               */
/*               ALL RIGHTS RESERVED                            */
/*                                                              */
/*                Prepared by CSIRO                             */
/*                                                              */
/*        See COPYRIGHT for full restrictions                   */
/****************************************************************/

#ifndef DPGMYBC20_H
#define DPGMYBC20_H

#include "IntegratedBC.h"

class DPGmyBC20;

template <>
InputParameters validParams<DPGmyBC20>();

class DPGmyBC20 : public IntegratedBC
{
public:
  DPGmyBC20(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

private:
  bool _is_vel_y_coupled, _is_vel_z_coupled;
  const VariableValue & _vel_x; // x component of  velocity vector
  const VariableValue & _vel_y; // y component of  velocity vector
  const VariableValue & _vel_z; // z component of  velocity vector

};

#endif // DPGMYBC20_H
