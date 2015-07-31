#include "RedbackFlowLaw.h"

template<>
InputParameters validParams<RedbackFlowLaw>()
{
  InputParameters params = validParams<GeneralUserObject>();
  params.addClassDescription("Flow law base class. Override strainRate in your class");
  return params;
}

RedbackFlowLaw::RedbackFlowLaw(const InputParameters parameters) :
    GeneralUserObject(parameters)
{}

void
RedbackFlowLaw::initialize()
{}

void
RedbackFlowLaw::execute()
{}

void RedbackFlowLaw::finalize()
{}


// DEPRECATED CONSTRUCTOR
RedbackFlowLaw::RedbackFlowLaw(const std::string & deprecated_name, InputParameters parameters) :
    GeneralUserObject(deprecated_name, parameters)
{}
