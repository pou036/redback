/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/*     REDBACK - Rock mEchanics with Dissipative feedBACKs      */
/*                                                              */
/*              (c) 2014 CSIRO and UNSW Australia               */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*            Prepared by CSIRO and UNSW Australia              */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/
// Main Application
#include "ActionFactory.h"
#include "AppFactory.h"
#include "Moose.h"
#include "MooseSyntax.h"
#include "RedbackApp.h"

// Modules
#include "TensorMechanicsApp.h"

// Actions
#include "RedbackAction.h"
#include "RedbackMechAction.h"

// Boundary conditions
#include "FunctionDirichletTransverseBC.h"
#include "PressureNeumannBC.h"

// Functions
#include "RedbackRandomFunction.h"

// Initial conditions
#include "FunctionLogNormalDistributionIC.h"
#include "FunctionNormalDistributionIC.h"
#include "FunctionTimesRandomIC.h"
#include "FunctionWithRandomIC.h"

// Kernels
#include "RedbackChemEndo.h"
#include "RedbackChemExo.h"
#include "RedbackChemPressure.h"
#include "RedbackDamage.h"
#include "RedbackFluidDivergence.h"
#include "RedbackFluidStressDivergenceTensors.h"
#include "RedbackMassConvection.h"
#include "RedbackMassDiffusion.h"
#include "RedbackMechDissip.h"
#include "RedbackNavier.h"
#include "RedbackPoromechanics.h"
#include "RedbackStressDivergenceTensors.h"
#include "RedbackThermalConvection.h"
#include "RedbackThermalDiffusion.h"
#include "RedbackThermalPressurization.h"
#include "RedbackVariableEqualsFunction.h"

// Scalar Kernels
#include "RedbackContinuation.h"

// Dirac Kernels
#include "FunctionPointSource.h"

// Materials
#include "ImageProcessing.h"
#include "RedbackFluidMaterial.h"
#include "RedbackMaterial.h"
#include "RedbackMechMaterialCC.h"
#include "RedbackMechMaterialCCanisotropic.h"
#include "RedbackMechMaterialDP.h"
#include "RedbackMechMaterialElastic.h"
#include "RedbackMechMaterialJ2.h"

// MeshModifiers
#include "ElementFileSubdomain.h"

// Timesteppers
#include "ReturnMapIterDT.h"

// AuxKernels
#include "RedbackContinuationTangentAux.h"
#include "RedbackDiffVarsAux.h"
#include "RedbackPolarTensorMaterialAux.h"
#include "RedbackTotalPorosityAux.h"

template <>
InputParameters
validParams<RedbackApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RedbackApp::RedbackApp(InputParameters parameters) : MooseApp(parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  TensorMechanicsApp::registerObjects(_factory);
  RedbackApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  TensorMechanicsApp::associateSyntax(_syntax, _action_factory);
  RedbackApp::associateSyntax(_syntax, _action_factory);
}

RedbackApp::~RedbackApp()
{
}

void
RedbackApp::registerApps()
{
#undef registerApp
#define registerApp(name) AppFactory::instance().reg<name>(#name)
  registerApp(RedbackApp);
#undef registerApp
#define registerApp(name) AppFactory::instance().regLegacy<name>(#name)
}

void
RedbackApp::registerObjects(Factory & factory)
{
#undef registerObject
#define registerObject(name) factory.reg<name>(stringifyName(name))
  registerBoundaryCondition(FunctionDirichletTransverseBC);
  registerBoundaryCondition(PressureNeumannBC);

  registerFunction(RedbackRandomFunction);

  registerInitialCondition(FunctionNormalDistributionIC);
  registerInitialCondition(FunctionLogNormalDistributionIC);
  registerInitialCondition(FunctionWithRandomIC);
  registerInitialCondition(FunctionTimesRandomIC);

  registerKernel(RedbackChemEndo);
  registerKernel(RedbackChemExo);
  registerKernel(RedbackChemPressure);
  registerKernel(RedbackFluidDivergence);
  registerKernel(RedbackFluidStressDivergenceTensors);
  registerKernel(RedbackMassConvection);
  registerKernel(RedbackMassDiffusion);
  registerKernel(RedbackMechDissip);
  registerKernel(RedbackNavier);
  registerKernel(RedbackPoromechanics);
  registerKernel(RedbackStressDivergenceTensors);
  registerKernel(RedbackThermalConvection);
  registerKernel(RedbackThermalDiffusion);
  registerKernel(RedbackThermalPressurization);
  registerKernel(RedbackDamage);
  registerKernel(RedbackVariableEqualsFunction);

  registerScalarKernel(RedbackContinuation);

  registerDiracKernel(FunctionPointSource);

  registerMaterial(RedbackFluidMaterial);
  registerMaterial(ImageProcessing);
  registerMaterial(RedbackMaterial);
  registerMaterial(RedbackMechMaterialJ2);
  registerMaterial(RedbackMechMaterialDP);
  registerMaterial(RedbackMechMaterialCC);
  registerMaterial(RedbackMechMaterialCCanisotropic);
  registerMaterial(RedbackMechMaterialElastic);

  registerMeshModifier(ElementFileSubdomain);

  registerExecutioner(ReturnMapIterDT);

  registerAux(RedbackContinuationTangentAux);
  registerAux(RedbackDiffVarsAux);
  registerAux(RedbackTotalPorosityAux);
  registerAux(RedbackPolarTensorMaterialAux);
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
// syntax.registerActionSyntax("RedbackAction", "RedbackAction/*");
// registerAction(RedbackMechAction, "add_aux_variable");
#undef registerAction
#define registerAction(tplt, action) action_factory.regLegacy<tplt>(stringifyName(tplt), action)
}
