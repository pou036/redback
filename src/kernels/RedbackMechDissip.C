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

#include "RedbackMechDissip.h"
#include "MooseMesh.h"
#include "PermutationTensor.h"

template <>
InputParameters
validParams<RedbackMechDissip>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("displacements", "The string of displacements suitable for the problem statement");
  params.addCoupledVar("rotations", "The string of rotations suitable for the problem statement");
  params.addParam<Real>("time_factor", 1.0, "Time rescaling factor (global parameter!)");
  return params;
}

RedbackMechDissip::RedbackMechDissip(const InputParameters & parameters) :
    Kernel(parameters),
    _mechanical_dissipation(hasMaterialProperty<Real>("mechanical_dissipation_mech")
                              ? getMaterialProperty<Real>("mechanical_dissipation_mech")
                              : getMaterialProperty<Real>("mechanical_dissipation_no_mech")),
    _mechanical_dissipation_jac(hasMaterialProperty<Real>("mechanical_dissipation_jacobian_mech")
                                  ? getMaterialProperty<Real>("mechanical_dissipation_jacobian_mech")
                                  : getMaterialProperty<Real>("mechanical_dissipation_jacobian_no_mech")),
   // _mechanical_dissipation(getMaterialProperty<Real>("mechanical_dissipation_mech")),
   //_mechanical_dissipation_jac(getMaterialProperty<Real>("mechanical_dissipation_jacobian_mech")),
   _dplastic_heat_dstrain(getMaterialProperty<RankTwoTensor>("dplastic_heat_dstrain")),
   _dplastic_heat_dcurvature(getMaterialProperty<RankTwoTensor>("dplastic_heat_dcurvature")),
   _ndisp(coupledComponents("displacements")),
   _disp_var(_ndisp),
   _nwc(coupledComponents("rotations")),
   _wc_var(_nwc),

   _time_factor(getParam<Real>("time_factor"))
{
  for (unsigned int i = 0; i < _ndisp; ++i)
    _disp_var[i] = coupled("displacements", i);

  for (unsigned int i = 0; i < _nwc; ++i)
    _wc_var[i] = coupled("rotations", i);

  // Checking for consistency between mesh size and length of the provided displacements vector
  if (_ndisp != _mesh.dimension())
    //mooseError("PlasticHeatEnergy: The number of displacement variables supplied must match the "
               //"mesh dimension.");
    mooseWarning("PlasticHeatEnergy: The number of displacement variables supplied must match the "
               "mesh dimension.");
}

RedbackMechDissip::~RedbackMechDissip()
{
}

Real
RedbackMechDissip::computeQpResidual()
{
  return -_time_factor * _test[ _i ][ _qp ] * _mechanical_dissipation[ _qp ];
}

Real
RedbackMechDissip::computeQpJacobian()
{
  return - _time_factor * _test[ _i ][ _qp ] * _mechanical_dissipation_jac[ _qp ] * _phi[ _j ][ _qp ];
}

Real
RedbackMechDissip::computeQpOffDiagJacobian(unsigned int jvar)
{
  for (unsigned int i = 0; i < _ndisp; ++i)
    if (jvar == _disp_var[i])
      return -_test[_i][_qp] * (_dplastic_heat_dstrain[_qp] * _grad_phi[_j][_qp])(i);

  Real sum = 0.0;
    for (unsigned int i = 0; i < _nwc; ++i){
    if (jvar == _wc_var[i]){
        for (unsigned int j = 0; j < LIBMESH_DIM; ++j){
          for (unsigned int l = 0; l < LIBMESH_DIM; ++l){
            sum -= (_dplastic_heat_dstrain[_qp] )(j,l) * PermutationTensor::eps(j, l, i);}}

        sum *= _test[_i][_qp]*_phi[_j][_qp];
        sum -= _test[_i][_qp] * (_dplastic_heat_dcurvature[_qp] * _grad_phi[_j][_qp])(i);}}

    return sum;


  return 0.0;
}
