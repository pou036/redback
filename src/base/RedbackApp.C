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
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

// Modules
#include "TensorMechanicsApp.h"

// Actions
//#include "RankTwoScalarAction.h"
//#include "RedbackAction.h"
//#include "RedbackMechAction.h"

template <>
InputParameters
validParams<RedbackApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RedbackApp::RedbackApp(InputParameters parameters) : MooseApp(parameters)
{
  RedbackApp::registerAll(_factory, _action_factory, _syntax);
}

RedbackApp::~RedbackApp() {}

void
RedbackApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Registry::registerObjectsTo(f, {"RedbackApp"});
  Registry::registerActionsTo(af, {"RedbackApp"});

  ModulesApp::registerAll(f, af, s);

  /* register custom execute flags, action syntax, etc. here */
  RedbackApp::associateSyntax(s, af);
}

void
RedbackApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"RedbackApp"});

  registerSyntax("RankTwoScalarAction", "RankTwoScalarAction/*");
  registerSyntax("RedbackMechAction", "RedbackMechAction/*");
}

void
RedbackApp::registerApps()
{
  registerApp(RedbackApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
RedbackApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RedbackApp::registerAll(f, af, s);
}
extern "C" void
RedbackApp__registerApps()
{
  RedbackApp::registerApps();
}
