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
#include "RedbackApp.h"
#include "Moose.h"
#include "MooseSyntax.h"
#include "AppFactory.h"
#include "ActionFactory.h"

// Modules
#include "TensorMechanicsApp.h"

// Actions
#include "RedbackAction.h"
#include "RedbackMechAction.h"
#include "RedbackMechAction_UO.h"

// Boundary conditions
#include "FunctionDirichletTransverseBC.h"

// Initial conditions
#include "FunctionWithRandomIC.h"
#include "FunctionTimesRandomIC.h"

// Kernels
#include "RedbackChemEndo.h"
#include "RedbackChemExo.h"
#include "RedbackChemPressure.h"
#include "RedbackFluidDivergence.h"
#include "RedbackFluidStressDivergenceTensors.h"
#include "RedbackMassConvection.h"
#include "RedbackMassDiffusion.h"
#include "RedbackMechDissip.h"
#include "RedbackNavier.h"
#include "RedbackPoromechanics.h"
#include "RedbackStressDivergenceTensors.h"
#include "RedbackStressDivergenceTensors_UO.h"
#include "RedbackThermalConvection.h"
#include "RedbackThermalDiffusion.h"
#include "RedbackThermalPressurization.h"
#include "RedbackDamage.h"

// Scalar Kernels
#include "RedbackContinuation.h"

// Dirac Kernels
#include "FunctionPointSource.h"

// Materials
#include "RedbackFluidMaterial.h"
#include "ImageProcessing.h"
#include "RedbackMaterial.h"
#include "RedbackMaterial_UO.h"
#include "RedbackMechMaterialJ2.h"
#include "RedbackMechMaterialJ2_UO.h"
#include "RedbackMechMaterialDP.h"
#include "RedbackMechMaterialDP_UO.h"
#include "RedbackMechMaterialCC.h"
#include "RedbackMechMaterialCC_UO.h"
#include "RedbackMechMaterialCCanisotropic.h"
#include "RedbackMechMaterialElastic.h"
#include "RedbackMechMaterialElastic_UO.h"

// MeshModifiers
#include "ElementFileSubdomain.h"

// Timesteppers
#include "ReturnMapIterDT.h"

// AuxKernels
#include "RedbackContinuationTangentAux.h"
#include "RedbackDiffVarsAux.h"
#include "RedbackTotalPorosityAux.h"
#include "RedbackPolarTensorMaterialAux.h"

#include "RedbackTotalPorosityAux_UO.h"

// User objects
#include "RedbackElementParameters.h"
#include "RedbackMaterialUserObject.h"


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
  registerKernel(RedbackStressDivergenceTensors_UO);
  registerKernel(RedbackThermalConvection);
  registerKernel(RedbackThermalDiffusion);
  registerKernel(RedbackThermalPressurization);
  registerKernel(RedbackDamage);

  registerScalarKernel(RedbackContinuation);

  registerDiracKernel(FunctionPointSource);

  registerMaterial(RedbackFluidMaterial);
  registerMaterial(ImageProcessing);
  registerMaterial(RedbackMaterial);
  registerMaterial(RedbackMaterial_UO);
  registerMaterial(RedbackMechMaterialJ2);
  registerMaterial(RedbackMechMaterialJ2_UO);
  registerMaterial(RedbackMechMaterialDP);
  registerMaterial(RedbackMechMaterialDP_UO);
  registerMaterial(RedbackMechMaterialCC);
  registerMaterial(RedbackMechMaterialCC_UO);
  registerMaterial(RedbackMechMaterialCCanisotropic);
  registerMaterial(RedbackMechMaterialElastic);
  registerMaterial(RedbackMechMaterial_Elastic_UO);

  registerMeshModifier(ElementFileSubdomain);

  registerExecutioner(ReturnMapIterDT);

  registerAux(RedbackContinuationTangentAux);
  registerAux(RedbackDiffVarsAux);
  registerAux(RedbackTotalPorosityAux);
  registerAux(RedbackPolarTensorMaterialAux);

  // user objects
  registerAux(RedbackTotalPorosityAux_UO);

  // material parameter objects
  registerUserObject(RedbackElementParameters);
  registerUserObject(RedbackMaterialConstant);

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
  syntax.registerActionSyntax("RedbackMechAction_UO", "RedbackMechAction_UO/*");
  registerAction(RedbackMechAction_UO, "add_kernel");
// syntax.registerActionSyntax("RedbackAction", "RedbackAction/*");
// registerAction(RedbackMechAction, "add_aux_variable");
#undef registerAction
#define registerAction(tplt, action) action_factory.regLegacy<tplt>(stringifyName(tplt), action)
}
