#include "RedbackFluidStressDivergenceTensors_UO.h"

#include "Material.h"
#include "ElasticityTensorTools.h"

template <>
InputParameters
validParams<RedbackFluidStressDivergenceTensors_UO>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<unsigned int>(
    "component",
    "An integer corresponding to the direction the variable this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addRequiredCoupledVar("fluid_vel_x", "The x-component of fluid velocity");
  params.addRequiredCoupledVar("fluid_vel_y", "The y-component of fluid velocity");
  params.addCoupledVar("fluid_vel_z", 0.0, "The z-component of fluid velocity");
  // params.addRequiredCoupledVar("temp", 0.0, "The temperature");
  params.addRequiredCoupledVar("pore_pres", "The pore fluid pressure");

  // Using the displaced mesh will be set in the solid mechanics action input now.
  params.set<bool>("use_displaced_mesh") = true;

  params.addRequiredParam<UserObjectName>("redback_material_parameters","User object holding common redback material parameters");

  return params;
}

RedbackFluidStressDivergenceTensors_UO::RedbackFluidStressDivergenceTensors_UO(const InputParameters & parameters) :
    Kernel(parameters),
    //_pore_pres(coupledValue("pore_pres")),
    _grad_pore_pressure(coupledGradient("pore_pres")),
    _fluid_stress(getMaterialProperty<RankTwoTensor>("fluid_stress")),
    //_Jacobian_fluid_mult(getMaterialProperty<RankFourTensor>("Jacobian_fluid_mult")),
    _component(getParam<unsigned int>("component")),
    _fluid_density(getMaterialProperty<Real>("NS_fluid_density")),

    //_reynolds_number(getMaterialProperty<Real>("Reynolds_number")),
    _viscosity_ratio(getMaterialProperty<Real>("viscosity_ratio")),

    //_vel_fluid_x_coupled(isCoupled("fluid_vel_x")),
    //_vel_fluid_y_coupled(isCoupled("fluid_vel_y")),
    //_vel_fluid_coupled(isCoupled("fluid_vel_z")),
    //_temp_coupled(isCoupled("temp")),

    _vel_fluid_x_var(coupled("fluid_vel_x")),
    _vel_fluid_y_var(coupled("fluid_vel_y")),
    _vel_fluid_z_var(coupled("fluid_vel_z")),
    //_temp_var(coupled("temp")),
    _porepressure_var(coupled("pore_pres")),

    _gravity_term(getMaterialProperty<RealVectorValue>("gravity_term"))
{

	UserObjectName rep_uo_name = getParam<UserObjectName>("redback_material_parameters");
	_common_redback_material_parameters = &getUserObjectByName<RedbackElementParameters>( rep_uo_name);

	// extract pointers to active parameters
	_reynolds_number_uo = _common_redback_material_parameters->GetRequiredParameterObject( RedbackParameters::ReynoldsNumber.str );

}

Real
RedbackFluidStressDivergenceTensors_UO::computeQpResidual()
{
  return (_fluid_stress[ _qp ].row(_component)) * _grad_test[ _i ][ _qp ] /
           ( (*_reynolds_number_uo)[ _qp ] * _fluid_density[ _qp ]) +
         (_grad_pore_pressure[ _qp ](_component) / _fluid_density[ _qp ] - _gravity_term[ _qp ](_component)) *
           _test[ _i ][ _qp ];
}

Real
RedbackFluidStressDivergenceTensors_UO::computeQpJacobian()
{
  return 1 / (*_reynolds_number_uo)[ _qp ] *
         (_grad_phi[ _j ][ _qp ] * _grad_test[ _i ][ _qp ] +
          //                   _grad_phi[_j][_qp](_component) * _grad_test[_i][_qp](_component));
          1 / 3 * _grad_phi[ _j ][ _qp ](_component)*_grad_test[ _i ][ _qp ](_component) + // input of div u
          _viscosity_ratio[ _qp ] * _grad_phi[ _j ][ _qp ](_component)*_grad_test[ _i ][ _qp ](_component));
}

Real
RedbackFluidStressDivergenceTensors_UO::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _vel_fluid_x_var)
    return 1 / (*_reynolds_number_uo)[ _qp ] * _grad_phi[ _j ][ _qp ](_component)*_grad_test[ _i ][ _qp ](0);
  else if (jvar == _vel_fluid_y_var)
    return 1 / (*_reynolds_number_uo)[ _qp ] * _grad_phi[ _j ][ _qp ](_component)*_grad_test[ _i ][ _qp ](1);
  else if (jvar == _vel_fluid_z_var)
    return 1 / (*_reynolds_number_uo)[ _qp ] * _grad_phi[ _j ][ _qp ](_component)*_grad_test[ _i ][ _qp ](2);
  // Porepressure term
  else if (jvar == _porepressure_var)
    return _grad_phi[ _j ][ _qp ](_component)*_test[ _i ][ _qp ];

  else
    return 0;
}
