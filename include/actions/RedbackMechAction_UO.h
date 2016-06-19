#ifndef RedbackMechAction_UO_UO_H
#define RedbackMechAction_UO_UO_H

#include "Action.h"

class RedbackMechAction_UO;

template <>
InputParameters validParams<RedbackMechAction_UO>();

class RedbackMechAction_UO : public Action
{
public:
  RedbackMechAction_UO(InputParameters params);

  virtual void act();

private:
  const std::string _disp_x;
  const std::string _disp_y;
  const std::string _disp_z;
  const std::string _disp_r;
  const std::string _temp;
  const std::string _pore_pres;
  const std::string _rep_uo_name;
};

#endif // RedbackMechAction_UO_H
