#include "RedbackDGAdvection.h"

template<>
InputParameters validParams<RedbackDGAdvection>()
{
  InputParameters params = validParams<DGKernel>();
 // params.addRequiredParam<RealVectorValue>("velocity", "Velocity vector");


  params.addRequiredCoupledVar("vel_x", "The x velocity");
  params.addCoupledVar("vel_y", 0.0, "The y velocity");
  params.addCoupledVar("vel_z", 0.0, "The z velocity");
  return params;
}

RedbackDGAdvection::RedbackDGAdvection(const InputParameters & parameters) :
    DGKernel(parameters),
	_velocity(),
	_vel_x(coupledValue("vel_x")),
	_vel_y(isCoupled("vel_y") ? coupledValue("vel_y") : _zero),
	_vel_z(isCoupled("vel_z") ? coupledValue("vel_z") : _zero)
{}

Real
RedbackDGAdvection::computeQpResidual(Moose::DGResidualType type)
{
	Real r = 0;

	_velocity(0) = _vel_x[_qp];
	_velocity(1) = _vel_y[_qp];
	_velocity(2) = _vel_z[_qp];

  switch (type)
  {
    case Moose::Element:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += (_velocity * _normals[_qp]) * _u[_qp] * _test[_i][_qp];
      else
        r += (_velocity * _normals[_qp]) * _u_neighbor[_qp] * _test[_i][_qp];
      break;

    case Moose::Neighbor:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += -(_velocity * _normals[_qp]) * _u[_qp] * _test_neighbor[_i][_qp];
      else
        r += -(_velocity * _normals[_qp]) * _u_neighbor[_qp] * _test_neighbor[_i][_qp];
      break;
  }
  return r;
}

Real
RedbackDGAdvection::computeQpJacobian(Moose::DGJacobianType type)
{
  Real r = 0;

  switch (type)
  {

    case Moose::ElementElement:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += (_velocity * _normals[_qp]) * _phi[_j][_qp] * _test[_i][_qp];
      else
        r += 0.0;
      break;

    case Moose::ElementNeighbor:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += 0.0;
      else
        r += (_velocity * _normals[_qp]) * _phi_neighbor[_j][_qp] * _test[_i][_qp];
      break;

    case Moose::NeighborElement:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += -(_velocity * _normals[_qp]) * _phi[_j][_qp] * _test_neighbor[_i][_qp];
      else
        r += 0.0;
      break;

    case Moose::NeighborNeighbor:
      if ( (_velocity * _normals[_qp]) >= 0.0)
        r += 0.0;
      else
        r += -(_velocity * _normals[_qp]) * _phi_neighbor[_j][_qp] * _test_neighbor[_i][_qp];
      break;
  }
  return r;
}




///////////////
//#include "RedbackDGAdvectionBC.h"

template<>

InputParameters validParams<RedbackDGAdvectionBC>()

{

  InputParameters params = validParams<IntegratedBC>();

 // params.addRequiredParam<RealVectorValue>("velocity", "Velocity vector");

  params.addRequiredCoupledVar("vel_x", "The x velocity");
  params.addCoupledVar("vel_y", 0.0, "The y velocity");
  params.addCoupledVar("vel_z", 0.0, "The z velocity");

  return params;

}

RedbackDGAdvectionBC::RedbackDGAdvectionBC(const InputParameters& parameters):
  IntegratedBC(parameters),
 // _velocity(getParam<RealVectorValue>("velocity"))
  _vel_x(coupledValue("vel_x")),
  _vel_y(isCoupled("vel_y") ? coupledValue("vel_y") : _zero),
  _vel_z(isCoupled("vel_z") ? coupledValue("vel_z") : _zero)
{}

Real
RedbackDGAdvectionBC::computeQpResidual()
{

	_velocity(0) = _vel_x[_qp];
	_velocity(1) = _vel_y[_qp];
	_velocity(2) = _vel_z[_qp];

	Real vN = _velocity * _normals[_qp];
	Real r = vN * _u[_qp] * _test[_i][_qp];

	return r;

}
