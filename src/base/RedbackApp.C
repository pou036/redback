#include "RedbackApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

// Actions
#include "RedbackAction.h"
#include "RedbackMechAction.h"

// Boundary conditions
#include "FunctionDirichletTransverseBC.h"

// Functions
#include "RedbackMorFunction.h"

// Initial conditions
#include "FunctionWithRandomIC.h"
#include "FunctionTimesRandomIC.h"

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
#include "RedbackThermalDiffusion.h"
#include "RedbackThermalPressurization.h"
#include "RedbackVariableEqualsFunction.h"

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

RedbackApp::RedbackApp(InputParameters parameters) :
    MooseApp(parameters)
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
  #undef  registerApp
  #define registerApp(name) AppFactory::instance().reg<name>(#name)
  registerApp(RedbackApp);
  #undef  registerApp
  #define registerApp(name) AppFactory::instance().regLegacy<name>(#name)
}

void
RedbackApp::registerObjects(Factory & factory)
{
  #undef registerObject
  #define registerObject(name) factory.reg<name>(stringifyName(name))
  registerBoundaryCondition(FunctionDirichletTransverseBC);

  registerFunction(RedbackMorFunction);

  registerInitialCondition(FunctionWithRandomIC);
  registerInitialCondition(FunctionTimesRandomIC);

  registerKernel(RedbackChemEndo);
  registerKernel(RedbackChemExo);
  registerKernel(RedbackChemPressure);
  registerKernel(RedbackMassConvection);
  registerKernel(RedbackMassDiffusion);
  registerKernel(RedbackMechDissip);
  registerKernel(RedbackPoromechanics);
  registerKernel(RedbackStressDivergenceTensors);
  registerKernel(RedbackThermalConvection);
  registerKernel(RedbackThermalDiffusion);
  registerKernel(RedbackThermalPressurization);
  registerKernel(RedbackVariableEqualsFunction);

  registerMaterial(RedbackMaterial);
  registerMaterial(RedbackMechMaterialJ2);
  registerMaterial(RedbackMechMaterialDP);
  registerMaterial(RedbackMechMaterialCC);
  registerMaterial(RedbackMechMaterialCCanisotropic);
  registerMaterial(RedbackMechMaterialElastic);

  registerExecutioner(ReturnMapIterDT);

  registerAux(RedbackTotalPorosityAux);
  #undef registerObject
  #define registerObject(name) factory.regLegacy<name>(stringifyName(name))
}

void
RedbackApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  #undef registerAction
  #define registerAction(tplt, action) action_factory.reg<tplt>(stringifyName(tplt), action)
  syntax.registerActionSyntax("RedbackMechAction", "RedbackMechAction/*");
  registerAction(RedbackMechAction, "add_kernel");
  //syntax.registerActionSyntax("RedbackAction", "RedbackAction/*");
  //registerAction(RedbackMechAction, "add_aux_variable");
  #undef registerAction
  #define registerAction(tplt, action) action_factory.regLegacy<tplt>(stringifyName(tplt), action)
}
