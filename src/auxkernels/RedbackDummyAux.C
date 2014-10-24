/*****************************************/
/* AuxKernel to compute porosity         */
/*****************************************/

#include "RedbackDummyAux.h"
#include "Function.h"

template<>
InputParameters validParams<RedbackDummyAux>()
{
  InputParameters params = validParams<AuxKernel>();
  //params.addRequiredCoupledVar("t_variable", "Variable that will be substituted into the 't' slot of the function");
  //params.addRequiredParam<FunctionName>("function", "The function to use.  The t_variable gets substituted in the 't' slot of this function");
  //params.addClassDescription("AuxVariable = function(t_variable, current_point).  That is, define a function of t and this will substitute your variable for t and give you the result as an AuxVariable");
  return params;
}

RedbackDummyAux::RedbackDummyAux(const std::string & name, InputParameters parameters) :
  AuxKernel(name, parameters),
  _dummy_mat_prop(getMaterialProperty<Real>("dummy_prop")) // initial porosity
  //_t_variable(coupledValue("t_variable")),
  //_func(getFunction("function"))
{}

Real
RedbackDummyAux::computeValue()
{
  return _dummy_mat_prop[_qp];
}
