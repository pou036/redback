#include "RedbackApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

// Kernels
#include "ChemEndo.h"
#include "ChemPressure.h"
#include "CubeTerm.h"
#include "MechHeat.h"
#include "MechHeatTensor.h"

// Materials
#include "DimensionlessRock.h"

// AuxKernels
#include "StrainRateAux.h"

// Postprocessors
#include "StrainRatePoint.h"


template<>
InputParameters validParams<RedbackApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RedbackApp::RedbackApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RedbackApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RedbackApp::associateSyntax(_syntax, _action_factory);
}

RedbackApp::~RedbackApp()
{
}

void
RedbackApp::registerApps()
{
  registerApp(RedbackApp);
}

void
RedbackApp::registerObjects(Factory & factory)
{
  registerKernel(ChemEndo);
  registerKernel(ChemPressure);
  registerKernel(CubeTerm);
  registerKernel(MechHeat);
  registerKernel(MechHeatTensor);

  registerMaterial(DimensionlessRock);

  registerAux(StrainRateAux);

  registerPostprocessor(StrainRatePoint);
}

void
RedbackApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
