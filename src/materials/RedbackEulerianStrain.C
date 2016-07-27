/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#include "RedbackEulerianStrain.h"
#include "Assembly.h"
#include "MooseMesh.h"

// libmesh includes
#include "libmesh/quadrature.h"


template<>
InputParameters validParams<RedbackEulerianStrain>()
{
  InputParameters params = validParams<ComputeStrainBase>();
  params.addClassDescription("Compute a strain increment and rotation increment for eulerian solver.");
  params.set<bool>("stateful_displacements") = true;

  //params.addRequiredCoupledVar("vel_x", "The x velocity");
  //params.addCoupledVar("vel_y", 0.0, "The y velocity");
  //params.addCoupledVar("vel_z", 0.0, "The z velocity");

//  params.addRequiredCoupledVar("velocity", "The material point velocity field (vel_x, vel_y etc)");

  params.addRequiredCoupledVar("eta", "The material point x coordinates (eta_x, eta_y etc)");
  //params.addRequiredCoupledVar("eta_x", "The material point x coordinate (eta_x)");
  //params.addCoupledVar("eta_y", 0.0, "The material point y coordinate (eta_y)");
  //params.addCoupledVar("eta_z", 0.0, "The material point z coordinate (eta_z)");

  return params;
}

RedbackEulerianStrain::RedbackEulerianStrain(const InputParameters & parameters) :
    ComputeStrainBase(parameters),
	_strain_rate(declareProperty<RankTwoTensor>(_base_name + "strain_rate")),
	_strain_increment(declareProperty<RankTwoTensor>(_base_name + "strain_increment")),
	_mechanical_strain_old(declarePropertyOld<RankTwoTensor>(_base_name + "mechanical_strain")),
	_total_strain_old(declarePropertyOld<RankTwoTensor>(_base_name + "total_strain")),
	_rotation_increment(declareProperty<RankTwoTensor>(_base_name + "rotation_increment")),
	_deformation_gradient(declareProperty<RankTwoTensor>(_base_name + "deformation_gradient")),
	_deformation_gradient_old(declarePropertyOld<RankTwoTensor>(_base_name + "deformation_gradient")),
	_stress_free_strain_increment(getDefaultMaterialProperty<RankTwoTensor>(_base_name + "stress_free_strain_increment")),
	_current_elem_volume(_assembly.elemVolume()),
	_Fhat(_fe_problem.getMaxQps()),

    _neta(coupledComponents("eta")),
    _eta(3),
    _grad_eta(3),
    _grad_eta_old(3)
	//_eta_x(coupledValue("eta_x")),
	///_eta_y(isCoupled("eta_y") ? coupledValue("eta_y") : _zero),
	//_eta_z(isCoupled("eta_z") ? coupledValue("eta_z") : _zero),
	//_grad_eta_x(coupledGradient("eta_x")),
	//_grad_eta_y( isCoupled("eta_y") ? coupledGradient("eta_y") : _zero),
	//_grad_eta_z( isCoupled("eta_z") ? coupledGradient("eta_z") : _zero),
	//_grad_eta_x_old(coupledGradientOld("eta_x")),
	//_grad_eta_y_old( isCoupled("eta_y") ? coupledGradientOld("eta_y") : _zero),
	//_grad_eta_z_old( isCoupled("eta_z") ? coupledGradientOld("eta_z") : _zero)
{
    if (_neta != _mesh.dimension())
		    mooseError("The number of variables supplied in 'eta' must match the mesh dimension.");

    // fetch coupled variables and gradients (as stateful properties if necessary)
      for (unsigned int i = 0; i < _neta; ++i)
      {
        _eta[i] = &coupledValue("eta", i);
        _grad_eta[i] = &coupledGradient("eta", i);

        _grad_eta_old[i] = &coupledGradientOld("eta" ,i);
      }

      // set unused dimensions to zero
      for (unsigned i = _neta; i < 3; ++i)
      {
        _eta[i] = &_zero;
        _grad_eta[i] = &_grad_zero; // fixme NQR -> ideally want diagonal terms = 1
        _grad_eta_old[i] = _grad_eta[i];
      }

}

void
RedbackEulerianStrain::initQpStatefulProperties()
{
  ComputeStrainBase::initQpStatefulProperties();

  _strain_rate[_qp].zero();
  _strain_increment[_qp].zero();
  _rotation_increment[_qp].zero();
  _deformation_gradient[_qp].zero();
  _deformation_gradient[_qp].addIa(1.0);
  _deformation_gradient_old[_qp] = _deformation_gradient[_qp];
  _mechanical_strain_old[_qp] = _mechanical_strain[_qp];
  _total_strain_old[_qp] = _total_strain[_qp];

}

void
RedbackEulerianStrain::computeProperties()
{


  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
    // Deformation gradient
   // RankTwoTensor A((*_grad_disp[0])[_qp], (*_grad_disp[1])[_qp], (*_grad_disp[2])[_qp]); //Deformation gradient
   // RankTwoTensor Fbar((*_grad_disp_old[0])[_qp], (*_grad_disp_old[1])[_qp], (*_grad_disp_old[2])[_qp]); //Old Deformation gradient


	RankTwoTensor Finv((*_grad_eta[0])[_qp], (*_grad_eta[1])[_qp], (*_grad_eta[2])[_qp]);
	RankTwoTensor FbarInv((*_grad_eta_old[0])[_qp], (*_grad_eta_old[1])[_qp], (*_grad_eta_old[2])[_qp]);

	// handle 0 gradient in undefined dimensions
	for(unsigned i = _neta; i < 3; ++i){
		Finv(i,i) += 1;
		FbarInv(i,i) += 1;
	}

	_deformation_gradient[_qp] = Finv.inverse();

    //_deformation_gradient[_qp] = A;
    //_deformation_gradient[_qp].addIa(1.0);//Gauss point deformation gradient

    //RankTwoTensor F = Finv.inverse();

    // A = gradU - gradUold
    RankTwoTensor A(_deformation_gradient[_qp] - _deformation_gradient_old[_qp]);

    // Fbar = ( I + gradUold)

    // Incremental deformation gradient _Fhat = I + A Fbar^-1
    _Fhat[_qp] = A * FbarInv; // Fbar.inverse();
    _Fhat[_qp].addIa(1.0);

  }


  for (_qp = 0; _qp < _qrule->n_points(); ++_qp)
  {
    computeQpStrain();
  }
}

void
RedbackEulerianStrain::computeQpStrain()
{
  // inverse of _Fhat
  RankTwoTensor invFhat(_Fhat[_qp].inverse());

  // A = I - _Fhat^-1
  RankTwoTensor A(RankTwoTensor::initIdentity);
  A -= invFhat;

  // Cinv - I = A A^T - A - A^T;
  RankTwoTensor Cinv_I = A * A.transpose() - A - A.transpose();

  // strain rate D from Taylor expansion, Chat = (-1/2(Chat^-1 - I) + 1/4*(Chat^-1 - I)^2 + ...
  RankTwoTensor total_strain_increment = -Cinv_I * 0.5 + Cinv_I * Cinv_I * 0.25;

  _strain_increment[_qp] = total_strain_increment;

  /*
    if (_no_thermal_eigenstrains) //Deprecated; use ComputeThermalExpansionEigenStrains instead
    {
      if (_t_step == 1) // total strain form always uses the ref temp
        _strain_increment[_qp].addIa(-_thermal_expansion_coeff * (_T[_qp] - _T0));

      else
        _strain_increment[_qp].addIa(-_thermal_expansion_coeff * (_T[_qp] - _T_old[_qp]));
    }
    */

  // Remove the Eigen strain increment
  _strain_increment[_qp] -= _stress_free_strain_increment[_qp];

  RankTwoTensor D = _strain_increment[_qp] / _dt;
  _strain_rate[_qp] = D;

  const Real a[3] = {
    invFhat(1,2) - invFhat(2,1),
    invFhat(2,0) - invFhat(0,2),
    invFhat(0,1) - invFhat(1,0)
  };

  Real q = (a[0]*a[0] + a[1]*a[1] + a[2]*a[2]) / 4.0;
  Real trFhatinv_1 = invFhat.trace() - 1.0;
  const Real p = trFhatinv_1 * trFhatinv_1 / 4.0;

  // cos theta_a
  const Real C1 = std::sqrt(p + 3.0*p*p*(1.0 - (p + q))/((p+q)*(p+q)) - 2.0*p*p*p*(1-(p+q))/((p+q)*(p+q)*(p+q)));

  Real C2;
  if (q > 0.01)
    // (1-cos theta_a)/4q
    C2 = (1.0 - C1) / (4.0 * q);
  else
    //alternate form for small q
    C2 = 0.125 + q * 0.03125 * (p*p - 12 * (p-1)) / (p*p)
          + q*q * (p - 2.0) * (p*p - 10.0 * p + 32.0) / (p*p*p)
          + q*q*q * (1104.0 - 992.0 * p + 376.0 * p*p - 72 * p*p*p + 5.0 * p*p*p*p) / (512.0*p*p*p*p);

  const Real C3 = 0.5 * std::sqrt((p * q * (3.0 - q) + p*p*p + q*q) / ((p + q) * (p + q) * (p + q))); //sin theta_a/(2 sqrt(q))

  // Calculate incremental rotation. Note that this value is the transpose of that from Rashid, 93, so we transpose it before storing
  RankTwoTensor R_incr;
  R_incr.addIa(C1);
  for (unsigned int i = 0; i < 3; ++i)
    for (unsigned int j = 0; j < 3; ++j)
      R_incr(i,j) += C2 * a[i] * a[j];

  R_incr(0,1) += C3 * a[2];
  R_incr(0,2) -= C3 * a[1];
  R_incr(1,0) -= C3 * a[2];
  R_incr(1,2) += C3 * a[0];
  R_incr(2,0) += C3 * a[1];
  R_incr(2,1) -= C3 * a[0];
  _rotation_increment[_qp] = R_incr.transpose();

  //Update strain in intermediate configuration
  _mechanical_strain[_qp] = _mechanical_strain_old[_qp] + _strain_increment[_qp];
  _total_strain[_qp] = _total_strain_old[_qp] + total_strain_increment;

  //Rotate strain to current configuration
  _mechanical_strain[_qp] = _rotation_increment[_qp] * _mechanical_strain[_qp] * _rotation_increment[_qp].transpose();
  _total_strain[_qp] = _rotation_increment[_qp] * _total_strain[_qp] * _rotation_increment[_qp].transpose();
}
