/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef REDBACKPLASTICITYUOBASE_H
#define REDBACKPLASTICITYUOBASE_H

#include "GeneralUserObject.h"
#include "RankTwoTensor.h"
#include "RankFourTensor.h"
#include "ElasticityTensorR4.h"
#include "RotationTensor.h"
#include "Function.h"
#include "libmesh/quadrature.h"

class RedbackPlasticityUOBase;

template <>
InputParameters validParams<RedbackPlasticityUOBase>();

/**
 * This user object is a pure virtual base classs
 * Derived classes computes material resistances and derivatives
 */
class RedbackPlasticityUOBase : public GeneralUserObject
{
public:
  RedbackPlasticityUOBase(const InputParameters & parameters);
  virtual ~RedbackPlasticityUOBase()
  {
  }

  void
  initialize()
  {
    // Explicitly call the initialization routines for our base class
    // GeneralUserObject::initialize();
  }
  void
  execute()
  {
  }
  void
  finalize()
  {
  }

  virtual Real getFlowIncrement(Real, Real, Real, Real, Real, Real, Real, Real, Real) const = 0;

  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) const = 0;

  virtual void getJac(const RankTwoTensor &,
                      const RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      Real,
                      RankFourTensor &,
                      Real,
                      Real,
                      Real,
                      Real) const = 0;

  virtual void get_py_qy(Real, Real, Real &, Real &, Real) const = 0;

  // void threadJoin(const UserObject &) {}
  // The following functions are needed in the return map, but the definition
  // is dependant on the yield criterion. Therefore we define them as abstract
  // virtual functions here such that no implementation is needed in
  // RedbackMechMaterial.C

  // virtual void
  // getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &) = 0;
  // virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, RankTwoTensor &) = 0;
  // virtual Real getFlowIncrement(Real, Real, Real, Real, Real) = 0;
  // virtual void get_py_qy(Real, Real, Real &, Real &, Real) = 0;

protected:
  // needs these set up:
  // Real _ref_pe_rate;
  // Real _exponent;
  // Real _exponential;
  // Real _dt;

  // some math functions that the called functions use

  // the signature of getDerivativeFlowIncrement depends on the model, so omitted here.
  // virtual Real getDerivativeFlowIncrement(const RankTwoTensor &, Real, Real, Real, Real, Real) const = 0;
  Real macaulayBracket(Real) const;
  Real getSigEqv(const RankTwoTensor & stress) const;
  Real deltaFunc(unsigned int i, unsigned int j) const;

  // _ref_pe_rate
  // _dt
  // _exponent
  // _exponential

  // TODO
  // std::string _strength_prop_name;
  // std::string _base_name;
  // const MaterialProperty<Real> & _strength;
  // std::string _pk2_prop_name;
  // const MaterialProperty<RankTwoTensor> & _pk2;
  // const MaterialProperty<RankTwoTensor> & _ce;
};

#endif // REDBACKPLASTICITYUOBASE_H
