/*****************************************/
/* AuxKernel to compute porosity         */
/*****************************************/

#ifndef REDBACKPOROSITYAUX_H
#define REDBACKPOROSITYAUX_H

#include "AuxKernel.h"
#include "Function.h"

//Forward Declarations
class RedbackPorosityAux;

template<>
InputParameters validParams<RedbackPorosityAux>();

class RedbackPorosityAux : public AuxKernel
{
public:
  RedbackPorosityAux(const std::string & name, InputParameters parameters);
  virtual ~RedbackPorosityAux() {};

protected:
  virtual Real computeValue();

private:
  MaterialProperty<Real> &  _phi0;
};

#endif // REDBACKPOROSITYAUX_H
