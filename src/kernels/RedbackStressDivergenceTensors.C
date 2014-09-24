#include "RedbackStressDivergenceTensors.h"

#include "Material.h"

template<>
InputParameters validParams<RedbackStressDivergenceTensors>()
{
  InputParameters params = validParams<Kernel>();
  params.addRequiredParam<unsigned int>("component", "An integer corresponding to the direction the variable this kernel acts in. (0 for x, 1 for y, 2 for z)");
  params.addCoupledVar("disp_x", "The x displacement");
  params.addCoupledVar("disp_y", "The y displacement");
  params.addCoupledVar("disp_z", "The z displacement");
  params.addCoupledVar("temp", "The temperature");
  params.addCoupledVar("pore_pres", 0, "The pore fluid pressure");
  params.addParam<std::string>("appended_property_name", "", "Name appended to material properties to make them unique");

//  params.set<bool>("use_displaced_mesh") = true;
  // Using the displaced mesh will be set in the solid mechanics action input now.
  params.set<bool>("use_displaced_mesh") = false;

  return params;
}


RedbackStressDivergenceTensors::RedbackStressDivergenceTensors(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters),
    _pore_pres(coupledValue("pore_pres")),

    _stress(getMaterialProperty<RankTwoTensor>("stress" + getParam<std::string>("appended_property_name"))),
    _Jacobian_mult(getMaterialProperty<ElasticityTensorR4>("Jacobian_mult" + getParam<std::string>("appended_property_name"))),
    // _d_stress_dT(getMaterialProperty<RankTwoTensor>("d_stress_dT"+ getParam<std::string>("appended_property_name"))),
    _component(getParam<unsigned int>("component")),

    _xdisp_coupled(isCoupled("disp_x")),
    _ydisp_coupled(isCoupled("disp_y")),
    _zdisp_coupled(isCoupled("disp_z")),
    _temp_coupled(isCoupled("temp")),
    _pore_pres_coupled(isCoupled("pore_pres")),

    _xdisp_var(_xdisp_coupled ? coupled("disp_x") : 0),
    _ydisp_var(_ydisp_coupled ? coupled("disp_y") : 0),
    _zdisp_var(_zdisp_coupled ? coupled("disp_z") : 0),
    _temp_var(_temp_coupled ? coupled("temp") : 0),

    _gravity_term(getMaterialProperty<RealVectorValue>("mixture_gravity_term"))
{
}

Real
RedbackStressDivergenceTensors::computeQpResidual()
{
	/* Handling the case where pore pressure is active. In this case pore pressure
	 * is not depending on displacements (incompressible case) and the stresses of
	 * TensorMechanics are now effective stresses
	 * The quantity _poromech_stress is the total stress obeying to Terzaghi's
	 * principle: poromech_stress(ij) = stress(ij) + pore_pressure * delta(ij).
	 * Jacobians are the same, since pore pressure is not depending on displacements
	 */

	if ( _pore_pres_coupled)
	{
		_poromech_stress_row = _stress[_qp].row(_component);
		_poromech_stress_row(_component) += _pore_pres[_qp];
		return (_poromech_stress_row + _gravity_term[_qp])* _grad_test[_i][_qp];
	}

	return (_stress[_qp].row(_component) + _gravity_term[_qp])* _grad_test[_i][_qp]; //TODO: Add the gravity kernel
}

Real
RedbackStressDivergenceTensors::computeQpJacobian()
{
  return _Jacobian_mult[_qp].elasticJacobian(_component, _component, _grad_test[_i][_qp], _grad_phi[_j][_qp]);
}

Real
RedbackStressDivergenceTensors::computeQpOffDiagJacobian(unsigned int jvar)
{
  unsigned int coupled_component = 0;
  bool active(false);

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

  if ( active )
    return _Jacobian_mult[_qp].elasticJacobian(_component, coupled_component,
                                          _grad_test[_i][_qp], _grad_phi[_j][_qp]);

  if (_temp_coupled && jvar == _temp_var)
  {
    //return _d_stress_dT[_qp].rowDot(_component, _grad_test[_i][_qp]) * _phi[_j][_qp];
    return 0.0;
  }

  return 0;
}