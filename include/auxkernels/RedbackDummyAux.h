/*****************************************/
/* AuxKernel to compute porosity         */
/*****************************************/

#ifndef REDBACKDUMMYAUX_H
#define REDBACKDUMMYAUX_H

#include "AuxKernel.h"
#include "Function.h"

//Forward Declarations
class RedbackDummyAux;

template<>
InputParameters validParams<RedbackDummyAux>();

class RedbackDummyAux : public AuxKernel
{
public:
  RedbackDummyAux(const std::string & name, InputParameters parameters);
  virtual ~RedbackDummyAux() {};

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> &  _dummy_mat_prop;
};

#endif // REDBACKDUMMYAUX_H
