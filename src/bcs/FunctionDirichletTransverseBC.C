/****************************************************************/
/* Dirichlet boundary condition to impose displacement in a     */
/* direction transversal to element normal vector, by taking a  */
/* vectorial product of the normal with a given vector          */
/****************************************************************/

#include "FunctionDirichletTransverseBC.h"
#include "Function.h"

template<>
InputParameters validParams<FunctionDirichletTransverseBC>()
{
  InputParameters params = validParams<PresetNodalBC>();
  params.addRequiredParam<FunctionName>("function", "The forcing function.");
  params.addRequiredParam<RealVectorValue>("center", "Center point to calculate transversal direction for boundary point.");
  params.addRequiredParam<RealVectorValue>("axis", "Axis of rotation, vector to calculate transversal direction for boundary point.");
  params.addRequiredParam<unsigned int>("dir_index", "Direction index (0 for X, 1 for Y, 2 for Z)");
  return params;
}

FunctionDirichletTransverseBC::FunctionDirichletTransverseBC(const std::string & name, InputParameters parameters) :
    PresetNodalBC(name, parameters),
    _func(getFunction("function")),
    _center(getParam<RealVectorValue>("center")),
    _axis(getParam<RealVectorValue>("axis")),
    _dir_index(getParam<unsigned int>("dir_index")),
    _feproblem(dynamic_cast<FEProblem &>(_subproblem))
{
}

Real
FunctionDirichletTransverseBC::computeQpValue()
{
  TypeVector<Real> node = *static_cast<const TypeVector<Real>*>(_current_node) - TypeVector<Real>(_center);
  Real x = node(0);
  Real y = node(1);
  Real radius = std::sqrt(x*x + y*y);
  Real theta = std::acos(x / radius); // 0 <= theta <= pi

  if ((x < 0 && y < 0) || (x >= 0 && y < 0)) // third quadrant or fourth quadrant
    theta *= -1;

  if (_dir_index == 0)
  {
    //return radius * (std::cos(theta + _func.value(_t, *_current_node)) - std::cos(theta));
    return radius * (std::cos(theta + _feproblem.dt()) - std::cos(theta));
  }
  else if (_dir_index == 1)
    return radius * (std::sin(theta + _feproblem.dt()) - std::sin(theta));
  else
    mooseError("dir_index out of bounds.");
}
