#ifndef REDBACKAPP_H
#define REDBACKAPP_H

#include "MooseApp.h"

class RedbackApp;

template <>
InputParameters validParams<RedbackApp>();

class RedbackApp : public MooseApp
{
public:
  RedbackApp(InputParameters parameters);
  virtual ~RedbackApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* REDBACKAPP_H */
