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

#include "Function.h"
#include "RedbackMechMaterialHO.h"
#include "multisurfaceplasticityhard.h"

/**
 * RedbackMechMaterialHO handles a high order material.
 */
template <>
InputParameters
validParams<RedbackMechMaterialHO>()
{
  InputParameters params = validParams<RedbackMechMaterial>();
  params.addCoupledVar("wc_x", 0, "Cosserat rotation around x axis");
  params.addCoupledVar("wc_y", 0, "Cosserat rotation around y axis");
  params.addCoupledVar("wc_z", 0, "Cosserat rotation around z axis");
  params.addRequiredParam<std::vector<Real> >("B_ijkl", "Flexural bending rigidity tensor.  Should have 9 entries.");
  //params.addParam<Real>("bulk_modulus", 0.0, "Bulk modulus, K");
  //params.addParam<Real>("shear_modulus", 0.0, "Shear modulus, G");
  //params.addParam<Real>("cosserat_shear_modulus", 0.0, "Cosserat shear modulus, G_c");
  params.addParam<Real>("cohesion", 1, "Material cohesion value");
  params.addParam<Real>("friction_coefficient", 0, "Friction coefficient");
  params.addParam<Real>("hardening_mech_modulus", 0, " mechanical hardening parameter value");

  MooseEnum fm = RankFourTensor::fillMethodEnum();
  fm = "general_isotropic";
  params.addParam<MooseEnum>("fill_method_bending", fm, "The fill method for the 'bending' tensor.");

  return params;
}

RedbackMechMaterialHO::RedbackMechMaterialHO(const InputParameters & parameters) :
    RedbackMechMaterial(parameters),
    _symmetric_strain(declareProperty<RankTwoTensor>("symmetric_strain")),
    _antisymmetric_strain(declareProperty<RankTwoTensor>("antisymmetric_strain")),
    _symmetric_plastic_strain(declareProperty<RankTwoTensor>("symmetric_strain")),
    _antisymmetric_plastic_strain(declareProperty<RankTwoTensor>("antisymmetric_strain")),
    _curvature(declareProperty<RankTwoTensor>("curvature")),
    _elastic_curvature(declareProperty<RankTwoTensor>("elastic_curvature")),
    _elastic_curvature_old(declarePropertyOld<RankTwoTensor>("elastic_curvature")),
    _total_curvature(declareProperty<RankTwoTensor>("total_curvature")),
    _total_curvature_old(declarePropertyOld<RankTwoTensor>("total_curvature")),
    _symmetric_stress(declareProperty<RankTwoTensor>("symmetric_stress")),
    _symmetric_stress_old(declarePropertyOld<RankTwoTensor>("symmetric_stress")),
    _antisymmetric_stress(declareProperty<RankTwoTensor>("antisymmetric_stress")),
    _antisymmetric_stress_old(declarePropertyOld<RankTwoTensor>("antisymmetric_stress")),
    _stress_couple(declareProperty<RankTwoTensor>("coupled_stress")),
    _stress_couple_old(declarePropertyOld<RankTwoTensor>("coupled_stress")),
    _stress_trace(declareProperty<Real>("stress_trace")),
    _macro_rotation(declareProperty<RankTwoTensor>("macro_rotation")),
    _elastic_flexural_rigidity_tensor(declareProperty<RankFourTensor>("elastic_flexural_rigidity_tensor")),
    _Jacobian_mult_couple(declareProperty<RankFourTensor>("coupled_Jacobian_mult")),
    _Jacobian_offdiag_bc(declareProperty<RankFourTensor>("coupled_Jacobian_off")),
    _Jacobian_offdiag_cb(declareProperty<RankFourTensor>("Jacobian_off")),
    _Bijkl_vector(getParam<std::vector<Real> >("B_ijkl")),
    _Cijkl_vector(getParam<std::vector<Real> >("C_ijkl")),
    _Bijkl(),
    _curvature_increment(declareProperty<RankTwoTensor>("curvature_increment")),
    _plastic_curvature(declareProperty<RankTwoTensor>("plastic_curvature")),
    _plastic_curvature_old(declarePropertyOld<RankTwoTensor>("plastic_curvature")),
    _deviatoric_plastic_strain(declareProperty<RankTwoTensor>("deviatoric_plastic_strain")),
    _deviatoric_stress(declareProperty<RankTwoTensor>("deviatoric_stress")),
    _volumetric_stress(declareProperty<Real>("volumetric_stress")),
    _stress_invariant(declareProperty<Real>("stress_invariant")),
    _hardening_variable(declareProperty<Real>("hardening_variable")),
    _hardening_variable_old(declarePropertyOld<Real>("hardening_variable")),
    _active_surfaces(declareProperty<Real>("active_surfaces")),
    _lagrange_multiplier(declareProperty<Real>("lagrange_multiplier")),
    _failure_surface(declareProperty<Real>("failure_surface")),
    _wc_x(coupledValue("wc_x")),
    _wc_y(coupledValue("wc_y")),
    _wc_z(coupledValue("wc_z")),
    _grad_wc_x(coupledGradient("wc_x")),
    _grad_wc_y(coupledGradient("wc_y")),
    _grad_wc_z(coupledGradient("wc_z")),
    _grad_wc_x_old(_fe_problem.isTransient() ? coupledGradientOld("wc_x") : _grad_zero),
    _grad_wc_y_old(_fe_problem.isTransient() ? coupledGradientOld("wc_y") : _grad_zero),
    _grad_wc_z_old(_fe_problem.isTransient() ? coupledGradientOld("wc_z") : _grad_zero),
    _fill_method_bending(getParam<MooseEnum>("fill_method_bending")),
    _cohesion(getParam<Real>("cohesion")),
    _friction_coefficient(getParam<Real>("friction_coefficient")),
    _hardening_mech_modulus(getParam<Real>("hardening_mech_modulus"))

{
  _Bijkl.fillFromInputVector(_Bijkl_vector, (RankFourTensor::FillMethod)(int)_fill_method_bending);
  _shear_modulus = _Cijkl_vector[ 1 ];
  _bulk_modulus = _Cijkl_vector[ 0 ] + 2*_shear_modulus/3.0;
  _cosserat_shear_modulus = _Cijkl_vector[ 2 ];
  _cosserat_radius = std::sqrt(_Bijkl_vector[ 1 ]/(2 * _shear_modulus));

}

void
RedbackMechMaterialHO::initQpStatefulProperties()
{
  RedbackMechMaterial::initQpStatefulProperties();
  _symmetric_strain[ _qp ].zero();
  _antisymmetric_strain[ _qp ].zero();
  _symmetric_plastic_strain[ _qp ].zero();
  _antisymmetric_plastic_strain[ _qp ].zero();
  _curvature[ _qp ].zero();
  _elastic_curvature[ _qp ].zero();
  _total_curvature[ _qp ].zero();
  _symmetric_stress[ _qp ].zero();
  _antisymmetric_stress[ _qp ].zero();
  _stress_couple[ _qp ].zero();
  _stress_trace[ _qp ] = 0.0;
  _macro_rotation[ _qp ].zero();
  _elastic_flexural_rigidity_tensor[ _qp ] = _Bijkl;
  _Jacobian_mult_couple[ _qp ] = _Bijkl;
  _Jacobian_offdiag_bc[ _qp ].zero();
  _Jacobian_offdiag_cb[ _qp ].zero();
  _curvature_increment[ _qp ].zero();
  _plastic_curvature[ _qp ].zero();
  _deviatoric_stress[ _qp ].zero();
  _volumetric_stress[ _qp ] = 0.0;
  _stress_invariant[ _qp ] = 0.0;
  _hardening_variable[ _qp ] = 0.0;
  _active_surfaces[ _qp ] = 0.0;
  _lagrange_multiplier[ _qp ] = 0.0;
  _failure_surface[ _qp ] = 0.0;
}


void
RedbackMechMaterialHO::computeQpStrain(const RankTwoTensor & Fhat)
{
  //strain = (grad_disp + grad_disp^T)/2
  RankTwoTensor grad_tensor(_grad_disp_x[_qp], _grad_disp_y[_qp], _grad_disp_z[_qp]);
  RealVectorValue wc_vector(_wc_x[_qp], _wc_y[_qp], _wc_z[_qp]);

  for (unsigned i = 0; i < LIBMESH_DIM; ++i)
    for (unsigned j = 0; j < LIBMESH_DIM; ++j)
      for (unsigned k = 0; k < LIBMESH_DIM; ++k)
        {
        grad_tensor(i, j) += PermutationTensor::eps(i, j, k) * wc_vector(k);
        //Real tmp = grad_tensor(i, j);
        //std::cout << "grad_tensor(" << i <<", " << j << " = " << tmp << std::endl;
      }
  _symmetric_strain[_qp] = (grad_tensor + grad_tensor.transpose()) / 2.0;
  _antisymmetric_strain[_qp] = (grad_tensor - grad_tensor.transpose()) / 2.0;
  _total_strain[_qp] = grad_tensor;

  RankTwoTensor old_deformation(_grad_disp_x_old[_qp],
                     _grad_disp_y_old[_qp],
                     _grad_disp_z_old[_qp]); // Old Deformation gradient

  _strain_increment[_qp]= grad_tensor - old_deformation;
  _strain_increment[_qp].addIa(-_solid_thermal_expansion[_qp] * (_T[_qp] - _T_old[_qp]));

  /* Setting up a macro-rotation (antisymmetric part of the strain) tensor to be used in Cosserat BCs*/
  RankTwoTensor mgrad_tensor(_grad_disp_x[_qp], _grad_disp_y[_qp], _grad_disp_z[_qp]);
  _macro_rotation[_qp] = (mgrad_tensor - mgrad_tensor.transpose()) / 2.0;

  /*Real tmp = _antisymmetric_strain[_qp](0,1) ;
  if (std::abs(tmp) > 1e-50)
    std::cout << "_antisymmetric_strain[" << _qp<<"](0,1) = " << tmp << std::endl;
*/
  _rotation_increment[_qp].zero();
  _rotation_increment[_qp].addIa(1);

  RankTwoTensor wc_grad_tensor(_grad_wc_x[_qp], _grad_wc_y[_qp], _grad_wc_z[_qp]);
  _curvature[_qp] = wc_grad_tensor;

  RankTwoTensor old_curvature(_grad_wc_x_old[_qp],
                     _grad_wc_y_old[_qp],
                     _grad_wc_z_old[_qp]); // Old Deformation gradient

_curvature_increment[_qp] = wc_grad_tensor - old_curvature;
}

void
RedbackMechMaterialHO::computeQpStress()
{
  //RedbackMechMaterial::computeQpStress();

  _plastic_potential_multiplier = 1;
  if (_has_T)
  {
    // Q/(RT) = Ar/(1+delta T*)
    _plastic_potential_multiplier = std::exp(-_ar[ _qp ]) * std::exp(_ar[ _qp ] * _delta[ _qp ] * _T[ _qp ] / (1 + _delta[ _qp ] * _T[ _qp ]));
  }

int NPROPS = 9;
int NSTR = 18;
int NILL = 1;
int NSVARSGP = 76;

Real STRESSF[NSTR];
Real DEFORT[NSTR];
Real DSDE[NSTR*NSTR];
Real SVARSGP[NSVARSGP];
Real PROPS[NPROPS];

Real Kbulk = _bulk_modulus;
Real Gshear = _shear_modulus;
Real GCshear = _cosserat_shear_modulus;
Real Radius = _cosserat_radius;
Real mufor = _friction_coefficient; // essai avec le critere le plus simple possible
Real cfor = _cohesion;
Real Hp = _hardening_mech_modulus;
int nb_hardening = 1;

Real g_1 = 8./5.;
Real g_2 = 2./5.;
Real g_3 = 8./5.;
Real g_4 = 2./5.;

Real h_1 = 2./3.;
Real h_2 = -1./6.;
Real h_3 = 2./3.;
Real h_4 = -1./6.;


PROPS[0]=Kbulk;
PROPS[1]=Gshear;
PROPS[2]=GCshear;
PROPS[3]=Radius;
PROPS[4]=mufor;
PROPS[5]=cfor;
PROPS[6]=Hp;
PROPS[7]=0.0;
PROPS[8]=0.0;

//PROPS[8]=_plastic_potential_multiplier;



remplSigmaOld(_strain_increment[_qp], DEFORT, 0);
remplMomentOld(_curvature_increment[_qp], DEFORT, 0);

remplSigmaOld(_stress_old[_qp], STRESSF, 0);
remplMomentOld(_stress_couple_old[_qp], STRESSF, 0);


remplSigmaOld(_stress_old[_qp], SVARSGP, 0);
remplMomentOld(_stress_couple_old[_qp], SVARSGP, 0);

remplSigmaOld(_total_strain_old[_qp], SVARSGP, NSTR);
remplMomentOld(_total_curvature_old[_qp], SVARSGP, NSTR);

//if (nb_hardening != 0) {
  SVARSGP[2*NSTR] = _hardening_variable_old[_qp];
//}


remplSigmaOld(_plastic_strain_old[_qp], SVARSGP, 2*NSTR + nb_hardening);
remplMomentOld(_plastic_curvature_old[_qp], SVARSGP, 2*NSTR + nb_hardening);

SVARSGP[3*NSTR + nb_hardening] = 0.0;
SVARSGP[3*NSTR + 1 + nb_hardening] = 0.0;
SVARSGP[3*NSTR + 2 + nb_hardening] = 0.0;


remplSigmaOld(_elastic_strain_old[_qp], SVARSGP, 3*NSTR+3+ nb_hardening);
remplMomentOld(_elastic_curvature_old[_qp], SVARSGP, 3*NSTR+3+ nb_hardening);


for (unsigned i = 0; i < NSTR*NSTR; ++i){
DSDE[i] = 0;
}

/*
Real verbose = 0;
Real y_coord = _current_elem->centroid()(1);
if (y_coord > 0.45 && y_coord < 0.55 && _qp==0)
  verbose = 1;
*/

usermat_(STRESSF,DEFORT,DSDE,&NSTR,PROPS,&NPROPS,SVARSGP,&NSVARSGP,&NILL);

Real verbose = 0;
Real y_coord = _current_elem->centroid()(1);
Real x_coord = _current_elem->centroid()(0);
if (y_coord > 0.45 && y_coord < 0.55 && x_coord > 0.45 && x_coord < 0.55  && _qp==0)
  verbose = 1;
if (verbose == 1 && NILL != 0)std::cout << " fortran not converging******************************** " << std::endl;


recupSigmaNew(_stress[_qp], STRESSF, 0);
recupMomentNew(_stress_couple[_qp], STRESSF, 0);


recupSigmaNew(_plastic_strain[_qp], SVARSGP, 2*NSTR + nb_hardening);
recupMomentNew(_plastic_curvature[_qp], SVARSGP, 2*NSTR + nb_hardening);


_symmetric_plastic_strain[_qp] = (_plastic_strain[_qp] + _plastic_strain[_qp].transpose()) / 2.0;
_antisymmetric_plastic_strain[_qp] = (_plastic_strain[_qp] - _plastic_strain[_qp].transpose()) / 2.0;

_deviatoric_plastic_strain[_qp] = _plastic_strain[_qp].deviatoric();

Real normL2;
normL2 = 0.0;
for (unsigned int i = 0; i < 3; ++i)
  for (unsigned int j = 0; j < 3; ++j)
    normL2 += g_1 * _deviatoric_plastic_strain[_qp](i,j) * _deviatoric_plastic_strain[_qp](i,j)
            + g_2 * _deviatoric_plastic_strain[_qp](i,j) * _deviatoric_plastic_strain[_qp](j,i)
            + ( g_3 * _plastic_curvature[_qp](i,j) * _plastic_curvature[_qp](i,j)
              + g_4 * _plastic_curvature[_qp](i,j) * _plastic_curvature[_qp](j,i) )  * (std::pow(Radius, 2.0));

_eqv_plastic_strain[_qp] = std::pow(normL2, 0.5);

_volumetric_strain[_qp] = _plastic_strain[_qp].trace(); // PLASTIC vol strain


recupSigmaNew(_elastic_strain[_qp], SVARSGP, 3*NSTR+3+ nb_hardening);
recupMomentNew(_elastic_curvature[_qp], SVARSGP, 3*NSTR+3+ nb_hardening);


//if (nb_hardening != 0) {
  _hardening_variable[_qp] = SVARSGP[2*NSTR];
//}



_active_surfaces[_qp]=SVARSGP[3*NSTR+1+ nb_hardening];
_failure_surface[_qp]=SVARSGP[3*NSTR+1+ nb_hardening];
_lagrange_multiplier[_qp]=SVARSGP[3*NSTR+2+ nb_hardening];



_total_strain[_qp] = _total_strain_old[_qp] + _strain_increment[_qp];
_total_curvature[_qp] = _total_curvature_old[_qp] + _curvature_increment[_qp];

_total_volumetric_strain[_qp] = _total_strain[_qp].trace();

_symmetric_stress[_qp] = (_stress[_qp] + _stress[_qp].transpose()) / 2.0;
_antisymmetric_stress[_qp] = (_stress[_qp] - _stress[_qp].transpose()) / 2.0;

_volumetric_stress[_qp] = (_stress[_qp].trace())/3;

_deviatoric_stress[_qp] = _stress[_qp].deviatoric();


Real normL2_stress;
normL2_stress=0.0;

for (unsigned int i = 0; i < 3; ++i){
  for (unsigned int j = 0; j < 3; ++j){
  normL2_stress += h_1 * _deviatoric_stress[_qp](i,j) * _deviatoric_stress[_qp](i,j)
                + h_2 * _deviatoric_stress[_qp](i,j) * _deviatoric_stress[_qp](j,i)
                + ( h_3 * _stress_couple[_qp](i,j) * _stress_couple[_qp](i,j)
                + h_4 * _stress_couple[_qp](i,j) * _stress_couple[_qp](j,i) ) / (std::pow(Radius, 2.0));
}}
_stress_invariant[_qp] = std::pow(normL2_stress, 0.5);
//mise a jour des termes de la matrice tangente


for (unsigned int i = 0; i < 3; ++i){
  for (unsigned int j = 0; j < 3; ++j){
    for (unsigned int k = 0; k < 3; ++k){
      for (unsigned int l = 0; l < 3; ++l){
        int test = NSTR*corsigma(k,l) + corsigma(i,j);
        //std::cout << " i="<<i<<", j="<<j<<", k="<<k<<", l="<<l<<", _Jacobian_mult = "<<DSDE[NSTR*corsigma(k,l) + corsigma(i,j)]<< std::endl;
_Jacobian_mult[_qp](i,j,k,l) = DSDE[NSTR*corsigma(k,l) + corsigma(i,j)];
}}}}

for (unsigned int i = 0; i < 3; ++i){
  for (unsigned int j = 0; j < 3; ++j){
    for (unsigned int k = 0; k < 3; ++k){
      for (unsigned int l = 0; l < 3; ++l){
      //  std::cout << " i="<<i<<", j="<<j<<", k="<<k<<", l="<<l<<", _Jacobian_mult_couple = "<< DSDE[NSTR*(cormoment(k,l) + NSTR / 2) + cormoment(i,j)+ NSTR / 2] << std::endl;
_Jacobian_mult_couple[_qp](i,j,k,l) = DSDE[NSTR*(cormoment(k,l) + NSTR / 2) + cormoment(i,j)+ NSTR / 2];
}}}}

for (unsigned int i = 0; i < 3; ++i){
  for (unsigned int j = 0; j < 3; ++j){
    for (unsigned int k = 0; k < 3; ++k){
      for (unsigned int l = 0; l < 3; ++l){
        //std::cout << " i="<<i<<", j="<<j<<", k="<<k<<", l="<<l<<", _Jacobian_offdiag_bc = "<< DSDE[NSTR*corsigma(k,l) + cormoment(i,j)+ NSTR / 2] << std::endl;
_Jacobian_offdiag_bc[_qp](i,j,k,l) = DSDE[NSTR*corsigma(k,l) + cormoment(i,j)+ NSTR / 2];
}}}}

for (unsigned int i = 0; i < 3; ++i){
  for (unsigned int j = 0; j < 3; ++j){
    for (unsigned int k = 0; k < 3; ++k){
      for (unsigned int l = 0; l < 3; ++l){
        //std::cout << " i="<<i<<", j="<<j<<", k="<<k<<", l="<<l<<", _Jacobian_offdiag_cb = "<< DSDE[NSTR*(cormoment(k,l) + NSTR / 2) + corsigma(i,j)] << std::endl;
_Jacobian_offdiag_cb[_qp](i,j,k,l) = DSDE[NSTR*(cormoment(k,l) + NSTR / 2) + corsigma(i,j)];
}}}}


// Compute the energy dissipation and the properties declared
computeRedbackTerms(_stress[_qp], 0, 0);

}

int RedbackMechMaterialHO::corsigma(int num1, int num2){
  int result;

  if (num1 == 0 && num2 == 0){
    result = 0;
  }
  else if (num1 == 1 && num2 == 1){
    result = 1;
  }
  else if (num1 == 2 && num2 == 2){
    result = 2;
  }
  else if (num1 == 1 && num2 == 2){
    result = 3;
  }
  else if (num1 == 0 && num2 == 2){
    result = 4;
  }
  else if (num1 == 0 && num2 == 1){
    result = 5;
  }
  else if (num1 == 2 && num2 == 1){
    result = 6;
  }
  else if (num1 == 2 && num2 == 0){
    result = 7;
  }
  else if (num1 == 1 && num2 == 0){
    result = 8;
  }
  return result;
}

int RedbackMechMaterialHO::cormoment(int num1, int num2){
  int result;

  if (num1 == 0 && num2 == 0){
    result = 0;
  }
  else if (num1 == 0 && num2 == 1){
    result = 1;
  }
  else if (num1 == 0 && num2 == 2){
    result = 2;
  }
  else if (num1 == 1 && num2 == 0){
    result = 3;
  }
  else if (num1 == 1 && num2 == 1){
    result = 4;
  }
  else if (num1 == 1 && num2 == 2){
    result = 5;
  }
  else if (num1 == 2 && num2 == 0){
    result = 6;
  }
  else if (num1 == 2 && num2 == 1){
    result = 7;
  }
  else if (num1 == 2 && num2 == 2){
    result = 8;
  }

return result;
}

void RedbackMechMaterialHO::remplSigmaOld(RankTwoTensor & tens_old,  Real* vect, int  ini){
  for (unsigned i = 0; i < 3; ++i){
    vect[ini + i]=tens_old(i,i);
  }
  vect[ini +3]=tens_old(1,2);
  vect[ini+4]=tens_old(0,2);
  vect[ini+5]=tens_old(0,1);
  vect[ini+6]=tens_old(2,1);
  vect[ini+7]=tens_old(2,0);
  vect[ini+8]=tens_old(1,0);
}


void RedbackMechMaterialHO::remplMomentOld(RankTwoTensor & tens_old, Real* vect, int  ini){

  vect[ini+9]=tens_old(0,0);
  vect[ini+10]=tens_old(0,1);
  vect[ini+11]=tens_old(0,2);
  vect[ini+12]=tens_old(1,0);
  vect[ini+13]=tens_old(1,1);
  vect[ini+14]=tens_old(1,2);
  vect[ini+15]=tens_old(2,0);
  vect[ini+16]=tens_old(2,1);
  vect[ini+17]=tens_old(2,2);
}


void RedbackMechMaterialHO::recupSigmaNew(RankTwoTensor & tens_new, Real* vect, int  ini){
  for (unsigned i = 0; i < 3; ++i){
  tens_new(i,i) = vect[ini + i];
  }

  tens_new(1,2) = vect[ini + 3];
  tens_new(0,2) = vect[ini + 4];
  tens_new(0,1) = vect[ini + 5];
  tens_new(2,1) = vect[ini + 6];
  tens_new(2,0) = vect[ini + 7];
  tens_new(1,0) = vect[ini + 8];

}


void RedbackMechMaterialHO::recupMomentNew(RankTwoTensor & tens_new, Real* vect, int  ini){
  tens_new(0,0)=vect[ini + 9];
  tens_new(0,1)=vect[ini + 10];
  tens_new(0,2)=vect[ini + 11];
  tens_new(1,0)=vect[ini + 12];
  tens_new(1,1)=vect[ini + 13];
  tens_new(1,2)=vect[ini + 14];
  tens_new(2,0)=vect[ini + 15];
  tens_new(2,1)=vect[ini + 16];
  tens_new(2,2)=vect[ini + 17];
}



void RedbackMechMaterialHO::computeQpElasticityTensor()
{
//  RedbackMechMaterial::computeQpElasticityTensor();

//  _elastic_flexural_rigidity_tensor[_qp] = _Bijkl;
//  _Jacobian_mult_couple[_qp] = _Bijkl;
}

/*
 * STARTING PSEUDO-LOOP IN PLASTICITY FUNCTIONS. NEED TO BE OVERWRITTEN WHEN IN PLASTICITY
 */

void
RedbackMechMaterialHO::returnMap(const RankTwoTensor & sig_old,
                                      const RankTwoTensor & delta_d,
                                      const RankFourTensor & E_ijkl,
                                      RankTwoTensor & dp,
                                      RankTwoTensor & sig,
                                      Real & p_y,
                                      Real & q_y)
{
  //  _stress[_qp] = _elasticity_tensor[_qp] * _elastic_strain[_qp];

   sig = _elasticity_tensor[_qp] * _elastic_strain[_qp];
   //std::cout << std::setprecision(12) << std::fixed;

  //sig = sig_old + E_ijkl * delta_d;
  dp = RankTwoTensor(); // Plastic rate of deformation tensor in unrotated configuration
}

/**
 * Get unitary flow tensor in deviatoric direction
 */
void
RedbackMechMaterialHO::getFlowTensor(const RankTwoTensor & sig, Real q, Real p, Real pc, RankTwoTensor & flow_tensor)
{
  flow_tensor.zero(); // TODO: not implemented yet
}

/**
 * Compute the flow incrmement for modified Cam-clay
 * pc ... pre-consolidation pressure (pc = -getYieldStress(eqvpstrain))
 */
Real
RedbackMechMaterialHO::getFlowIncrement(Real sig_eqv, Real pressure, Real q_yield_stress, Real p_yield_stress, Real pc)
{
  return 0; // TODO: not implemented yet
}

Real
RedbackMechMaterialHO::getDerivativeFlowIncrement(
  const RankTwoTensor & sig, Real pressure, Real sig_eqv, Real pc, Real q_yield_stress, Real p_yield_stress)
{
  return 0; // TODO: not implemented yet
}

void
RedbackMechMaterialHO::getJac(const RankTwoTensor & sig,
                              const RankFourTensor & E_ijkl,
                              Real flow_incr,
                              Real sig_eqv,
                              Real pressure,
                              Real p_yield_stress,
                              Real q_yield_stress,
                              Real pc,
                              RankFourTensor & dresid_dsig)
{
  dresid_dsig.zero();
}

void
RedbackMechMaterialHO::get_py_qy(Real p, Real q, Real & p_y, Real & q_y, Real yield_stress)
{
  // TODO: not implemented yet
  p_y = 0;
  q_y = 0;
}

void
RedbackMechMaterialHO::computeRedbackTerms(RankTwoTensor & sig, Real q_y, Real p_y)
{
  // Update the mechanical dissipation
  RankTwoTensor instantaneous_strain_rate;
  RankTwoTensor instantaneous_curvature_rate;

  instantaneous_strain_rate = (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]) / _dt;
  instantaneous_curvature_rate = (_plastic_curvature[ _qp ] - _plastic_curvature_old[ _qp ]) / _dt;

  instantaneous_strain_rate *= _plastic_potential_multiplier;
  instantaneous_curvature_rate *= _plastic_potential_multiplier;

  _mechanical_dissipation_mech[ _qp ] =  sig.doubleContraction(instantaneous_strain_rate) +
                                      _stress_couple[_qp].doubleContraction(instantaneous_curvature_rate) ;
  _mechanical_dissipation_mech[ _qp ] *= _gr[ _qp ];

  _mechanical_dissipation_jac_mech[ _qp ] = _mechanical_dissipation_mech[ _qp ];
  if (_has_T)
  {
   _mechanical_dissipation_jac_mech[ _qp ] = _mechanical_dissipation_jac_mech[ _qp ] / (1 + _delta[ _qp ] * _T[ _qp ]) / (1 + _delta[ _qp ] * _T[ _qp ]);
  }

  // Update the mechanical porosity
  Real delta_phi_mech_el, delta_phi_mech_pl;
  delta_phi_mech_el =
    (1.0 - _total_porosity[ _qp ]) * (_solid_compressibility[ _qp ] * (_pore_pres[ _qp ] - _P0_param) -
                                      _solid_thermal_expansion[ _qp ] * (_T[ _qp ] - _T0_param) +
                                      (_elastic_strain[ _qp ] - _elastic_strain_old[ _qp ]).trace());
  delta_phi_mech_pl = (1.0 - _total_porosity[ _qp ]) * (_plastic_strain[ _qp ] - _plastic_strain_old[ _qp ]).trace();

  _mechanical_porosity[ _qp ] = delta_phi_mech_el + delta_phi_mech_pl;

}
