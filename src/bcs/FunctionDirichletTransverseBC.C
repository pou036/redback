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
  params.addParam<Real>("angular_velocity", 1., "Angular velocity");
  params.addRequiredParam<unsigned int>("dir_index", "Direction index (0 for X, 1 for Y, 2 for Z)");
  return params;
}

FunctionDirichletTransverseBC::FunctionDirichletTransverseBC(const InputParameters & parameters) :
    PresetNodalBC(parameters),
    _u_old(valueOld()),
    _func(getFunction("function")),
    _center(getParam<RealVectorValue>("center")),
    _axis(getParam<RealVectorValue>("axis")),
    _angular_velocity(getParam<Real>("angular_velocity")),
    _dir_index(getParam<unsigned int>("dir_index"))
{
}

Real
FunctionDirichletTransverseBC::computeQpValue()
{
  /*TypeVector<Real> vector1 = TypeVector<Real>(_axis);
  TypeVector<Real> vector2 = *static_cast<const TypeVector<Real> *>(_current_node) - TypeVector<Real>(_center);
  TypeVector<Real> vector3 = vector1.cross(vector2);
  vector3 /= vector3.norm();
  return vector3(_dir_index) * _func.value(_t, *_current_node);*/

  Real x = (*_current_node)(0);
  Real y = (*_current_node)(1);
  Real z = (*_current_node)(2);
  Real a = _axis(0);
  Real b = _axis(1);
  Real c = _axis(2);
  Real d = std::sqrt(b*b+c*c);
  Real Ct = std::cos(_angular_velocity*_func.value(_t, *_current_node)*_t);
  Real St = std::sin(_angular_velocity*_func.value(_t, *_current_node)*_t);
  /* Construct Transformation Matrix */
  Real M11 = a*a+d*d*Ct;
  Real M12 = a*(b-b*Ct)-c*St;
  Real M13 = a*(c-c*Ct)+b*St;
  Real M14 = (1-a*a-d*d*Ct)*_center(0)+St*(c*_center(1)-b*_center(2)+a*(Ct-1)*(b*_center(1)+c*_center(2)));
  Real M21 = a*(b-b*Ct)+c*St;
  Real M22 = b*b*(1+a*a*b*b/(d*d)*Ct)+c*c*Ct/(d*d);
  Real M23 = b*c*((a*a-1)*Ct/(d*d)+1)-a*(b*b+c*c)*St/(d*d);
  Real M24 = -(a*b*(1-Ct)*d*d*_center(0)+c*d*d*St*_center(0)+c*c*Ct*_center(1)+(b*b-1)*d*d*_center(1)+b*c*(d*d-Ct)*_center(2)-a*(b*b+c*c)*St*_center(2)+a*a*b*Ct*(b*_center(1)+c*_center(2)))/(d*d);
  Real M31 = a*(c-c*Ct)-b*St;
  Real M32 = b*c*((a*a-1)*Ct/(d*d)+1)+a*(b*b+c*c)*St/(d*d);
  Real M33 = (b*b*Ct+c*c*(a*a*Ct+d*d))/(d*d);
  Real M34 = -(a*c*(1-Ct)*d*d*_center(0)-b*d*d*St*_center(0)+b*c*(-Ct+d*d)*_center(1)+a*(b*b+c*c)*St*_center(1)+b*b*Ct*_center(2)+(c*c-1)*d*d*_center(2)+a*a*c*Ct*(b*_center(1)+c*_center(2)))/(d*d);
  if (_dir_index == 0)
  {return M11*x+M12*y+M13*z+M14-x;
  }
  else if (_dir_index == 1)
  {return M21*x+M22*y+M23*z+M24-y;
  }
  else if (_dir_index == 2)
  {return M31*x+M32*y+M33*z+M34-z;
  }
  else
    mooseError("Case not implemented yet...");
  return 0;
}


/*
  Real x = (*_current_node)(0);
  Real y = (*_current_node)(1);
  Real z = (*_current_node)(2);
  Real radius = std::sqrt((x-_center(0))*(x-_center(0))+(y-_center(1))*(y-_center(1))); //assuming the axis is z direction;
  Real new_x = x + _u[_qp];
  Real old_angle = std::acos(x/radius)*(y <0 ? -1: 1);
  Real new_angle = old_angle + _angular_velocity*_func.value(_t, *_current_node)*_t;
  Real point_id = _current_node->id();

  if ((_current_node->id() == 2) && (_dir_index==0)  && (z<0.1) )
   {
     Real test_x = x + _u_old[_qp];
     std::cout << "x (point ID 2)= " << test_x <<std::endl;
   }
   if ((_current_node->id() == 2) && (_dir_index==1)  && (z<0.1)  )
    {
      Real test_y = y + _u_old[_qp];
      std::cout << "y (point ID 2)= " << test_y <<std::endl<<std::endl;
    }
  */

  /*
  if (_dir_index == 0)
  {
    Real current_x = x + _u_old[_qp];
    Real current_angle = std::acos(current_x/radius)*(y <0 ? -1: 1);
    Real new_angle = current_angle + _angular_velocity*_func.value(_t, *_current_node)*_dt;
    return radius*std::cos(new_angle) - x;
    //return _center(0) + (x-_center(0))*std::cos(_angular_velocity*_t) - (y-_center(1))*std::sin(_angular_velocity*_t)-x;

    if ((point_id == 2)||(point_id == 3)||(point_id == 17))
      return radius*std::cos(0*2*libMesh::pi/9.0 + _angular_velocity*_t) - radius*std::cos(0*2*libMesh::pi/9.0);
    else if ((point_id == 6)||(point_id == 7)||(point_id == 19))
      return radius*std::cos(1*2*libMesh::pi/9.0 + _angular_velocity*_t) - radius*std::cos(1*2*libMesh::pi/9.0);
    else if ((point_id == 10)||(point_id == 11)||(point_id == 21))
      return radius*std::cos(2*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(2*2*libMesh::pi/9.0);
    else if ((point_id == 14)||(point_id == 15)||(point_id == 23))
      return radius*std::cos(3*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(3*2*libMesh::pi/9.0);
    else if ((point_id == 38)||(point_id == 39)||(point_id == 49))
      return radius*std::cos(4*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(4*2*libMesh::pi/9.0);
    else if ((point_id == 42)||(point_id == 43)||(point_id == 51))
      return radius*std::cos(5*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(5*2*libMesh::pi/9.0);
    else if ((point_id == 46)||(point_id == 47)||(point_id == 53))
      return radius*std::cos(6*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(6*2*libMesh::pi/9.0);
    else if ((point_id == 65)||(point_id == 66)||(point_id == 72))
      return radius*std::cos(7*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(7*2*libMesh::pi/9.0);
    else if ((point_id == 69)||(point_id == 70)||(point_id == 74))
      return radius*std::cos(8*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::cos(8*2*libMesh::pi/9.0);
  }
  else if (_dir_index == 1)
  {
    Real current_y = y + _u_old[_qp];
    Real current_angle = (x <0 ? libMesh::pi - std::asin(current_y/radius): std::asin(current_y/radius));
    Real new_angle = current_angle + _angular_velocity*_func.value(_t, *_current_node)*_dt;
    return radius*std::sin(new_angle) - y; */
    //return _center(1) + (y-_center(1))*std::cos(_angular_velocity*_t) + (x-_center(0))*std::sin(_angular_velocity*_t)-y;

    /*if ((point_id == 2)||(point_id == 3)||(point_id == 17))
      return radius*std::sin(0*2*libMesh::pi/9.0 + _angular_velocity*_t) - radius*std::sin(0*2*libMesh::pi/9.0);
    else if ((point_id == 6)||(point_id == 7)||(point_id == 19))
      return radius*std::sin(1*2*libMesh::pi/9.0 + _angular_velocity*_t) - radius*std::sin(1*2*libMesh::pi/9.0);
    else if ((point_id == 10)||(point_id == 11)||(point_id == 21))
      return radius*std::sin(2*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(2*2*libMesh::pi/9.0);
    else if ((point_id == 14)||(point_id == 15)||(point_id == 23))
      return radius*std::sin(3*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(3*2*libMesh::pi/9.0);
    else if ((point_id == 38)||(point_id == 39)||(point_id == 49))
      return radius*std::sin(4*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(4*2*libMesh::pi/9.0);
    else if ((point_id == 42)||(point_id == 43)||(point_id == 51))
      return radius*std::sin(5*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(5*2*libMesh::pi/9.0);
    else if ((point_id == 46)||(point_id == 47)||(point_id == 53))
      return radius*std::sin(6*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(6*2*libMesh::pi/9.0);
    else if ((point_id == 65)||(point_id == 66)||(point_id == 72))
      return radius*std::sin(7*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(7*2*libMesh::pi/9.0);
    else if ((point_id == 69)||(point_id == 70)||(point_id == 74))
      return radius*std::sin(8*2*libMesh::pi/9.0  + _angular_velocity*_t) - radius*std::sin(8*2*libMesh::pi/9.0);*/
  /*}
  else
    mooseError("Case not implemented yet...");
  return 0;
}
*/
