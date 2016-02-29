/****************************************************************/
/* Dirichlet boundary condition to impose displacement in a     */
/* direction transversal to element normal vector, by taking a  */
/* vectorial product of the normal with a given vector          */
/****************************************************************/

#include "FunctionDirichletTransverseBC.h"
#include "Function.h"

template <>
InputParameters
validParams<FunctionDirichletTransverseBC>()
{
  InputParameters params = validParams<PresetNodalBC>();
  params.addRequiredParam<FunctionName>("function", "The forcing function.");
  params.addRequiredParam<RealVectorValue>("center",
                                           "Center point to calculate transversal direction for boundary point.");
  params.addRequiredParam<RealVectorValue>("axis",
                                           "Axis of rotation, vector to calculate transversal direction for "
                                           "boundary point.");
  params.addRequiredParam<unsigned int>("dir_index", "Direction index (0 for X, 1 for Y, 2 for Z)");
  return params;
}

FunctionDirichletTransverseBC::FunctionDirichletTransverseBC(const InputParameters & parameters) :
    PresetNodalBC(parameters),
    _func(getFunction("function")),
    _center(getParam<RealVectorValue>("center")),
    _axis(getParam<RealVectorValue>("axis")),
    _dir_index(getParam<unsigned int>("dir_index"))
{
}

Real
FunctionDirichletTransverseBC::computeQpValue()
{
  TypeVector<Real> vector1 = TypeVector<Real>(_axis);
  TypeVector<Real> vector2 = *static_cast<const TypeVector<Real> *>(_current_node) - TypeVector<Real>(_center);
  TypeVector<Real> vector3 = vector1.cross(vector2);
  vector3 /= vector3.norm();
  return vector3(_dir_index) * _func.value(_t, *_current_node);
}
