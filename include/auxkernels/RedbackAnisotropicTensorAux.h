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

#ifndef REDBACKANISOTROPICTENSORAUX
#define REDBACKANISOTROPICTENSORAUX

#include "AuxKernel.h"
#include "RankTwoTensor.h"
#include "FunctionParserUtils.h"

/**
 * AuxKernel to compute anisotropic tensor component, defined by
 * its longitudinal and transversal permeability components, as well as
 * a directionality provided by a normal (potential) field. The longitudinal
 * direction follows the isopotential surfaces.
 * (Used in practice to set permeability tensor.)
 */

// Forward declarations
class RedbackAnisotropicTensorAux;

template <>
InputParameters validParams<RedbackAnisotropicTensorAux>();

class RedbackAnisotropicTensorAux : public AuxKernel, public FunctionParserUtils<false>
{
public:
  RedbackAnisotropicTensorAux(const InputParameters & parameters);
  virtual ~RedbackAnisotropicTensorAux() {}

protected:
  virtual Real computeValue();
  const VariableValue & _potential;
  const VariableGradient & _n; // normal vector (non-normalised) to iso-potentials
  std::string _function_long; // function expression for longitudinal component
  std::string _function_tran; // function expression for longitudinal component
  SymFunctionPtr _func_F_long; // function parser object
  SymFunctionPtr _func_F_tran; // function parser object
  usingFunctionParserUtilsMembers(false);

  int _i_row, _i_column; // indices i,j of tensor to set
  Real _k_long, _k_tran; // values for longitudinal and transversal components (computed from functions)
};

#endif // REDBACKANISOTROPICTENSORAUX
