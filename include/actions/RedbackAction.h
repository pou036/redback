#ifndef REDBACKACTION_H
#define REDBACKACTION_H

#include "Action.h"

class RedbackAction;

template <>
InputParameters validParams<RedbackAction>();

class RedbackAction : public Action
{
public:
  RedbackAction(InputParameters params);

  virtual void act();

private:
  const std::string _disp_x;
  const std::string _disp_y;
  const std::string _disp_z;
  const std::string _temp;
  const std::string _pore_pres;
};

#endif // REDBACKACTION_H
