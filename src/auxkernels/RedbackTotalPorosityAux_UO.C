/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "RedbackTotalPorosityAux_UO.h"

template <>
InputParameters
validParams<RedbackTotalPorosityAux_UO>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addParam<bool>("is_mechanics_on", false, "is mechanics on?");
  // params.addParam<bool>("is_chemistry_on", false, "is chemistry on?");

  params.addRequiredParam<UserObjectName>("redback_material_parameters","User object holding common redback material parameters");


  params.addCoupledVar("mechanical_porosity", 0.0, "Mechanical porosity (as AuxKernel)");
  return params;
}

RedbackTotalPorosityAux_UO::RedbackTotalPorosityAux_UO(const InputParameters & parameters) :
    AuxKernel(parameters),
    _is_mechanics_on(getParam<bool>("is_mechanics_on")),
    _delta_porosity_mech(_is_mechanics_on ? coupledValue("mechanical_porosity") : _zero),
    _delta_porosity_chem(getMaterialProperty<Real>("chemical_porosity")),
    //_initial_porosity(getMaterialProperty<Real>("initial_porosity")),

    //_has_T(isCoupled("temperature")),
    //_T(_has_T ? coupledValue("temperature") : _zero),

    _mass_removal_rate(_is_mechanics_on ? getMaterialProperty<Real>("mass_removal_rate")
                                        : getZeroMaterialProperty<Real>("mass_removal_rate"))
{

	// common redback material parameters
	UserObjectName rep_uo_name = getParam<UserObjectName>("redback_material_parameters");
	_common_redback_material_parameters = &getUserObjectByName<RedbackElementParameters>( rep_uo_name);

	// extract pointers to active parameters
	_initial_porosity_uo = _common_redback_material_parameters->GetRequiredParameterObject("initial_porosity");

}

Real
RedbackTotalPorosityAux_UO::computeValue()
{
  Real total_porosity;
  // Moose::out << "RedbackTotalPorosityAux_UO::computeValue() at _qp" << _qp <<
  // "\n";
  total_porosity = (*_initial_porosity_uo)[ _qp ] + _delta_porosity_chem[ _qp ];
  if (_is_mechanics_on)
    total_porosity = (*_initial_porosity_uo)[ _qp ] + _delta_porosity_chem[ _qp ] * (1 + _mass_removal_rate[ _qp ]) +
                     _delta_porosity_mech[ _qp ];

  total_porosity = fmin(1.0, fmax(0.0, total_porosity));
  return total_porosity;
}
