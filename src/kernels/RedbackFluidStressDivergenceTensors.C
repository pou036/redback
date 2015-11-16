#include "RedbackFluidStressDivergenceTensors.h"

#include "Material.h"

template<>
InputParameters validParams<RedbackFluidStressDivergenceTensors>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<unsigned int>("component", "An integer corresponding to the direction the variable this kernel acts in. (0 for x, 1 for y, 2 for z)");
  //params.addRequiredCoupledVar("vel_fluid_x", "The x-component of fluid velocity");
  //params.addRequiredCoupledVar("vel_fluid_y", "The y-component of fluid velocity");
  //params.addCoupledVar("vel_fluid_z", 0.0, "The z-component of fluid velocity");
  //params.addRequiredCoupledVar("temp", 0.0, "The temperature");
  params.addRequiredCoupledVar("pore_pres", "The pore fluid pressure");

  // Using the displaced mesh will be set in the solid mechanics action input now.
  //params.set<bool>("use_displaced_mesh") = true;

  return params;
}


RedbackFluidStressDivergenceTensors::RedbackFluidStressDivergenceTensors(const InputParameters & parameters) :
    Kernel(parameters),
    //_pore_pres(coupledValue("pore_pres")),
    _grad_pore_pressure(coupledGradient("pore_pres")),
    _fluid_stress(getMaterialProperty<RankTwoTensor>("fluid_stress")),
    //_Jacobian_fluid_mult(getMaterialProperty<ElasticityTensorR4>("Jacobian_fluid_mult")),
    _component(getParam<unsigned int>("component")),
    _fluid_density(getMaterialProperty<Real>("fluid_density")),

    //_vel_fluid_x_coupled(isCoupled("vel_fluid_x")),
    //_vel_fluid_y_coupled(isCoupled("vel_fluid_y")),
    //_vel_fluid_coupled(isCoupled("vel_fluid_z")),
    //_temp_coupled(isCoupled("temp")),

    //_vel_fluid_x_var(coupled("vel_fluid_x")),
    //_vel_fluid_y_var(coupled("vel_fluid_y")),
    //_vel_fluid_z_var(coupled("vel_fluid_z")),
    //_temp_var(coupled("temp")),
    //_porepressure_var(coupled("pore_pres")),

    _gravity_term(getMaterialProperty<RealVectorValue>("gravity_term"))
{
}

Real
RedbackFluidStressDivergenceTensors::computeQpResidual()
{
  return (_fluid_stress[_qp].row(_component))* _grad_test[_i][_qp] / _fluid_density[_qp]
         + (_grad_pore_pressure[_qp](_component)/_fluid_density[_qp] - _gravity_term[_qp](_component)*_test[_i][_qp]);
}

Real
RedbackFluidStressDivergenceTensors::computeQpJacobian()
{
  return 0;
  //return _Jacobian_fluid_mult[_qp].elasticJacobian(_component, _component, _grad_test[_i][_qp], _grad_phi[_j][_qp]);
  /*Real result = _Jacobian_fluid_mult[_qp].elasticJacobian(_component, _component, _grad_test[_i][_qp], _grad_phi[_j][_qp]);
  if (_var.number() != _porepressure_var)
    return result;
  return result + _phi[_j][_qp]*_grad_test[_i][_qp](_component);*/
}

Real
RedbackFluidStressDivergenceTensors::computeQpOffDiagJacobian(unsigned int jvar)
{
  /*unsigned int coupled_component = 0;
  bool active(false);
  Real porepressure_term = 0;

  if (_xdisp_coupled && jvar == _xdisp_var)
  {
    coupled_component = 0;
    active = true;
  }
  else if (_ydisp_coupled && jvar == _ydisp_var)
  {
    coupled_component = 1;
    active = true;
  }
  else if (_zdisp_coupled && jvar == _zdisp_var)
  {
    coupled_component = 2;
    active = true;
  }

  // Porepressure term (disabled for now, doesn't seem to make any difference...)
  //if (_pore_pres_coupled && jvar == _porepressure_var)
  //  porepressure_term = _phi[_j][_qp]*_grad_test[_i][_qp](_component);

  if ( active )
    return _Jacobian_fluid_mult[_qp].elasticJacobian(_component, coupled_component,
                                          _grad_test[_i][_qp], _grad_phi[_j][_qp]) + porepressure_term; // (porepressure_term = 0 here)

  if (_temp_coupled && jvar == _temp_var)
  {
    //return _d_stress_dT[_qp].rowDot(_component, _grad_test[_i][_qp]) * _phi[_j][_qp];
    return 0.0 + porepressure_term; // (porepressure_term = 0 here)
  }

  return 0 + porepressure_term;*/
  return 0;
}
