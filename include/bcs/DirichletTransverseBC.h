/****************************************************************/
/* Dirichlet boundary condition to impose displacement in a     */
/* direction transversal to element normal vector, by taking a  */
/* vectorial product of the normal with a given vector          */
/****************************************************************/

#ifndef DIRICHLETTRANSVERSEBC
#define DIRICHLETTRANSVERSEBC

#include "PresetNodalBC.h"

//Forward Declarations
class DirichletTransverseBC;
class Function;

template<>
InputParameters validParams<DirichletTransverseBC>();

/**
 * Defines a boundary condition that forces the value to be a user specified
 * function at the boundary.
 */
class DirichletTransverseBC : public PresetNodalBC
{
public:
  DirichletTransverseBC(const std::string & name, InputParameters parameters);

protected:
  /**
   * Evaluate the function at the current quadrature point and timestep.
   */
  virtual Real computeQpValue();

  /// Function being used for evaluation of this BC
  Function & _func;
  
  /// Center point to calculate transversal direction for boundary point.
  const RealVectorValue & _center;
  
  /// Axis of rotation, vector to calculate transversal direction for boundary point.
  const RealVectorValue & _axis;
};

#endif /* DIRICHLETTRANSVERSEBC */
