#include "RedbackApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

#include "RedbackAction.h"

// Boundary conditions
#include "FunctionDirichletTransverseBC.h"

// Initial conditions
#include "FunctionWithRandomIC.h"

// Kernels
#include "RedbackChemEndo.h"
#include "RedbackChemExo.h"
#include "RedbackChemPressure.h"
#include "RedbackMassConvection.h"
#include "RedbackMassDiffusion.h"
#include "RedbackMechDissip.h"
#include "RedbackPoromechanics.h"
#include "RedbackStressDivergenceTensors.h"
#include "RedbackThermalConvection.h"
#include "RedbackThermalPressurization.h"

// Materials
#include "RedbackMaterial.h"
#include "RedbackMechMaterialJ2.h"
#include "RedbackMechMaterialDP.h"
#include "RedbackMechMaterialCC.h"
#include "RedbackMechMaterialCCanisotropic.h"
#include "RedbackMechMaterialElastic.h"

// Timesteppers
#include "ReturnMapIterDT.h"

// AuxKernels
#include "RedbackTotalPorosityAux.h"


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
  registerBoundaryCondition(FunctionDirichletTransverseBC);

  registerInitialCondition(FunctionWithRandomIC);

  registerKernel(RedbackChemEndo);
  registerKernel(RedbackChemExo);
  registerKernel(RedbackChemPressure);
  registerKernel(RedbackMassConvection);
  registerKernel(RedbackMassDiffusion);
  registerKernel(RedbackMechDissip);
  registerKernel(RedbackPoromechanics);
  registerKernel(RedbackStressDivergenceTensors);
  registerKernel(RedbackThermalConvection);
  registerKernel(RedbackThermalPressurization);

  registerMaterial(RedbackMaterial);
  registerMaterial(RedbackMechMaterialJ2);
  registerMaterial(RedbackMechMaterialDP);
  registerMaterial(RedbackMechMaterialCC);
  registerMaterial(RedbackMechMaterialCCanisotropic);
  registerMaterial(RedbackMechMaterialElastic);

  registerExecutioner(ReturnMapIterDT);

  registerAux(RedbackTotalPorosityAux);
}

void
RedbackApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  syntax.registerActionSyntax("RedbackAction", "RedbackAction/*");
  registerAction(RedbackAction, "add_kernel");
}
