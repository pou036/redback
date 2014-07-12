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

#include "MechDissip.h"


template<>
InputParameters validParams<MechDissip>()
{
  InputParameters params = validParams<Kernel>();

  params.addCoupledVar("pressure", 0., "Pressure variable.");
  //params.addRequiredParam<Real>("_ref_pe_rate", "Reference plastic strain rate parameter for rate dependent plasticity (Overstress model)");
  //params.addRequiredParam<Real>("_exponent", "Exponent for rate dependent plasticity (Perzyna)");
  params.addRequiredParam<Real>("activation_energy", "Activation energy");
  params.addParam<Real>("gas_constant", 8.3143, "Universal gas constant");

  return params;
}


MechDissip::MechDissip(const std::string & name, InputParameters parameters) :
  Kernel(name, parameters),
  _pressure(coupledValue("pressure")),
  _stress(getMaterialProperty<RankTwoTensor>("stress")),
  _mech_dissipation(getMaterialProperty<Real>("mech_dissipation")),
  //_ref_pe_rate(getParam<Real>("ref_pe_rate")),
  //_exponent(getParam<Real>("exponent")),
  _activation_energy(getParam<Real>("activation_energy")),
  _gas_constant(getParam<Real>("gas_constant"))
{

}

MechDissip::~MechDissip()
{

}

Real
MechDissip::computeQpResidual()
{
  //std::cout<<_mech_dissipation[_qp]<<std::endl;
  return -_test[_i][_qp] * _mech_dissipation[_qp];
  
}

Real
MechDissip::computeQpJacobian()
{
  return -_test[_i][_qp] * _mech_dissipation[_qp] * _activation_energy / (_gas_constant * _u[_qp] * _u[_qp]);
}
