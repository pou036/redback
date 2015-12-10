#ifndef REDBACKMECHACTION_H
#define REDBACKMECHACTION_H

#include "Action.h"

class RedbackMechAction;

template <>
InputParameters validParams<RedbackMechAction>();

class RedbackMechAction : public Action
{
public:
  RedbackMechAction(InputParameters params);

  virtual void act();

private:
  const std::string _disp_x;
  const std::string _disp_y;
  const std::string _disp_z;
  const std::string _disp_r;
  const std::string _temp;
  const std::string _pore_pres;
};

#endif // REDBACKMECHACTION_H
