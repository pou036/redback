/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO                                  */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

// AuxKernel to compute anisotropic tensor component, defined by
// its longitudinal and transversal components, as well as
// a directionality provided by a normal (potential) field. The longitudinal
// direction follows the isopotential surfaces.
// (Used in practice to set permeability tensor.)
#include "RedbackAnisotropicTensorAux.h"

registerMooseObject("RedbackApp", RedbackAnisotropicTensorAux);

template <>
InputParameters
validParams<RedbackAnisotropicTensorAux>()
{
  MooseEnum component("x=0 y=1 z=2");
  InputParameters params = AuxKernel::validParams();
  params += FunctionParserUtils<false>::validParams();
  params.addClassDescription("AuxKernel to set anisotropic tensor from "
    "longitudinal and transversal components.");

  params.addRequiredCoupledVar("potential_field", "Scalar field from which "
    "to infer directions in that block. "
    "(longitudinal = along iso-potentials; transversal = normal to iso-potentials)");
  params.addRequiredCustomTypeParam<std::string>(
    "function_long", "FunctionExpression", "function expression defining "
    "longitudinal component of tensor. It can use the potential field as argument.");
  params.addRequiredCustomTypeParam<std::string>(
    "function_tran", "FunctionExpression", "function expression defining "
    "transversal component of tensor. It can use the potential field as argument.");
  params.addParam<std::vector<std::string>>(
    "constant_names", "Vector of constants used in the parsed functions.");
  params.addParam<std::vector<std::string>>(
    "constant_expressions",
    "Vector of values for the constants in constant_names (can be an FParser expression)");
  params.addParam<MooseEnum>("row", component, "The tensor component (row) to assign: x, y or z");
  params.addParam<MooseEnum>("column", component, "The tensor component (column) to assign: x, y or z");

  return params;
}

RedbackAnisotropicTensorAux::RedbackAnisotropicTensorAux(const InputParameters & parameters)
  : AuxKernel(parameters),
    FunctionParserUtils(parameters),
    _potential(coupledValue("potential_field")),
    _n(coupledGradient("potential_field")),
    _function_long(getParam<std::string>("function_long")),
    _function_tran(getParam<std::string>("function_tran")),
    _i_row(getParam<MooseEnum>("row")),
    _i_column(getParam<MooseEnum>("column"))
{
  // build variables argument (single variable representing the potential field)
  std::string variables;
  variables += getVar("potential_field", 0)->name();

  // base function objects
  _func_F_long = std::make_shared<SymFunction>();
  _func_F_tran = std::make_shared<SymFunction>();

  // set FParser internal feature flags
  setParserFeatureFlags(_func_F_long);
  setParserFeatureFlags(_func_F_tran);

  // add the constant expressions
  addFParserConstants(_func_F_long,
                      getParam<std::vector<std::string>>("constant_names"),
                      getParam<std::vector<std::string>>("constant_expressions"));
  addFParserConstants(_func_F_tran,
                      getParam<std::vector<std::string>>("constant_names"),
                      getParam<std::vector<std::string>>("constant_expressions"));

  // parse functions
  if (_func_F_long->Parse(_function_long, variables) >= 0)
    mooseError(
        "Invalid function\n", _function_long, "\nin RedbackAnisotropicTensorAux ", name(), ".\n", _func_F_long->ErrorMsg());
  if (_func_F_tran->Parse(_function_tran, variables) >= 0)
    mooseError(
        "Invalid function\n", _function_tran, "\nin RedbackAnisotropicTensorAux ", name(), ".\n", _func_F_tran->ErrorMsg());

  // optimize
  if (!_disable_fpoptimizer)
  {
    _func_F_long->Optimize();
    _func_F_tran->Optimize();
  }

  // just-in-time compile
  if (_enable_jit)
  {
    _func_F_long->JITCompile();
    _func_F_tran->JITCompile();
  }

  // reserve storage for parameter passing bufefr
  _func_params.resize(1); // single argument for the potential field
}

Real
RedbackAnisotropicTensorAux::computeValue()
{
  RealTensorValue my_tensor, transfer_matrix;
  // Set first column of transfer matrix as normalised normal vector
  RealVectorValue u(_n[_qp]);//(0), _n[_qp](1), _n[_qp](2));
  u /= u.norm();
  // Second column vector is orthogonal to first one
  RealVectorValue v(0, 0, 0);
  if (_n[_qp](2) == 0) {
    // normal vector in horizontal plane
    if (_n[_qp](1) == 0) {
      v(1) = 1;
      // keep other 2 components zero
    } else {
      v(0) = _n[_qp](1);
      v(1) = -_n[_qp](0);
      // keep third component zero
    }
  } else {
    // normal vector has non-zero vertical component
    // keep first component zero
    v(1) = _n[_qp](2);
    v(2) = -_n[_qp](1);
  }
  v /= v.norm();
  // Third vector as cross product to get orthonormal basis
  transfer_matrix = RealTensorValue(u, v, u.cross(v)).transpose();

  // Set function parameter for potential field and evaluate both functions
  _func_params[0] = _potential[_qp];
  _k_long = evaluate(_func_F_long);
  _k_tran = evaluate(_func_F_tran);

  // Define tensor in rotated referential (aligned with iso-potentials)
  RealTensorValue k_prime;
  k_prime.zero();
  k_prime(0, 0) = _k_tran;
  k_prime(1, 1) = _k_long;
  k_prime(2, 2) = _k_long;

  // Get tensor in original referential
  my_tensor = transfer_matrix * (k_prime * transfer_matrix.transpose());

  return my_tensor(_i_row, _i_column);
}
