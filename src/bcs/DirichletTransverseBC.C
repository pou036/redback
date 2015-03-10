/****************************************************************/
/* Dirichlet boundary condition to impose displacement in a     */
/* direction transversal to element normal vector, by taking a  */
/* vectorial product of the normal with a given vector          */
/****************************************************************/

#include "DirichletTransverseBC.h"
#include "Function.h"

template<>
InputParameters validParams<DirichletTransverseBC>()
{
  InputParameters params = validParams<PresetNodalBC>();
  params.addRequiredParam<FunctionName>("function", "The forcing function.");
  params.addRequiredParam<RealVectorValue>("center", "Center point to calculate transversal direction for boundary point.");
  params.addRequiredParam<RealVectorValue>("axis", "Axis of rotation, vector to calculate transversal direction for boundary point.");
    return params;
}

DirichletTransverseBC::DirichletTransverseBC(const std::string & name, InputParameters parameters) :
    PresetNodalBC(name, parameters),
    _func(getFunction("function")),
	_center(getParam<RealVectorValue>("center")),
    _axis(getParam<RealVectorValue>("axis"))
{
}

Real
DirichletTransverseBC::computeQpValue()
{
	//std::cout << "1) Hello Thomas, _current_node=" << *_current_node << std::endl;
	//std::cout << "2) Hello Thomas, _current_node.get_info()=" << _current_node->get_info() << std::endl;
	//std::cout << "3) Hello Thomas, Point coords = " << *static_cast<const Point*>(_current_node) << std::endl;
	//std::cout << "4) Hello Thomas, _q_point coords = " << _q_point[_qp] << std::endl;
	//std::cout << "5) Hello Thomas, _current_node.size() = " << _current_node->size() << std::endl;
	std::cout << "6) Hello Thomas, _current_node.x = " << (*static_cast<const Point*>(_current_node))(0) << std::endl;
	std::cout << "7) Hello Thomas, _current_node.y = " << (*static_cast<const Point*>(_current_node))(1) << std::endl;
	std::cout << "8) Hello Thomas, _current_node.z = " << (*static_cast<const Point*>(_current_node))(2) << std::endl<< std::endl;

	std::cout << "9) Hello Thomas, center.x = " << _center(0) << std::endl;
	std::cout << "10) Hello Thomas, center.x = " << _center(1) << std::endl;
	std::cout << "11) Hello Thomas, center.x = " << _center(2) << std::endl;

	//Point()

	return _func.value(_t, *_current_node);
}
