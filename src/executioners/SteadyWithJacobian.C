/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

// MOOSE includes
#include "SteadyWithJacobian.h"
#include "FEProblem.h"
#include "Factory.h"
#include "MooseApp.h"
#include "NonlinearSystem.h"

#include "Conversion.h"

// libMesh includes
#include "libmesh/equation_systems.h"
#include "libmesh/sparse_matrix.h"




#ifdef LIBMESH_HAVE_PETSC
#include <petsc/private/snesimpl.h>


#include "libmesh/petsc_matrix.h"
//#include <Eigen/Eigenvalues>


#ifdef LIBMESH_HAVE_SLEPC
#include <slepceps.h>
#endif

#endif

template<>
InputParameters validParams<SteadyWithJacobian>()
{
  return validParams<Executioner>();
}


SteadyWithJacobian::SteadyWithJacobian(const InputParameters & parameters) :
    Executioner(parameters),
    _problem(_fe_problem),
    _time_step(_problem.timeStep()),
    _time(_problem.time())
{
  _problem.getNonlinearSystem().setDecomposition(_splitting);

  if (!_restart_file_base.empty())
    _problem.setRestartFile(_restart_file_base);

  {
    std::string ti_str = "SteadyState";
    InputParameters params = _app.getFactory().getValidParams(ti_str);
    _problem.addTimeIntegrator(ti_str, "ti", params);
  }
}

SteadyWithJacobian::~SteadyWithJacobian()
{
}

void
SteadyWithJacobian::init()
{
  if (_app.isRecovering())
  {
    _console << "\nCannot recover steady solves!\nExiting...\n" << std::endl;
    return;
  }

  checkIntegrity();
  _problem.initialSetup();

  _problem.outputStep(EXEC_INITIAL);
}

void
SteadyWithJacobian::execute()
{
  if (_app.isRecovering())
    return;

  preExecute();

  _problem.advanceState();

  // first step in any steady state solve is always 1 (preserving backwards compatibility)
  _time_step = 1;
  _time = _time_step;                 // need to keep _time in sync with _time_step to get correct output

#ifdef LIBMESH_ENABLE_AMR

  // Define the refinement loop
  unsigned int steps = _problem.adaptivity().getSteps();
  for (unsigned int r_step=0; r_step<=steps; r_step++)
  {
#endif //LIBMESH_ENABLE_AMR
    preSolve();
    _problem.timestepSetup();
    _problem.execute(EXEC_TIMESTEP_BEGIN);
    _problem.outputStep(EXEC_TIMESTEP_BEGIN);

    // Update warehouse active objects
    _problem.updateActiveObjects();

    _problem.solve();
    postSolve();

    if (!lastSolveConverged())
    {
      _console << "Aborting as solve did not converge\n";
      break;
    }

    // The system has been solved - now we change the flags sent to Petsc and to output the Jacobian.

    _console <<  std::scientific << COLOR_GREEN
            << "\n +++ Steady state solution found - calculating Jacobian +++ \n"
	        << COLOR_DEFAULT
	        << std::endl;

    // update Petsc flags
#ifdef LIBMESH_HAVE_PETSC
  /**
   * Retrieve a writable reference the PETSc options (used by PetscSupport)
   */

    bool doOriginalMethod = false;
    if(doOriginalMethod){
    	Moose::PetscSupport::PetscOptions &  thePetscOptions  =  _problem.getPetscOptions();

    	// '-snes_type', 'test', '-snes_test_display', '-mat_fd_type', 'ds'

    	thePetscOptions.flags.push_back("-snes_test_display");

    	thePetscOptions.inames.push_back("-snes_type");
    	thePetscOptions.values.push_back("test");

    	thePetscOptions.inames.push_back("-mat_fd_type");
    	thePetscOptions.values.push_back("ds");


    	// change solve type to Newton
    	_problem.solverParams()._type = Moose::stringToEnum<Moose::SolveType>("NEWTON");

    	_problem.solve();

    	// At this point Petsc should dump the jacobian std out in the PETSc format and then exit.
    } else {

        // Needed? The following options set methods used for the finite difference calculation of the jacobian.
    	//Moose::PetscSupport::PetscOptions &  thePetscOptions  =  _problem.getPetscOptions();
    	//thePetscOptions.inames.push_back("-mat_fd_type");
    	//thePetscOptions.values.push_back("ds");

    	// change solve type to Newton (to guarantee jacobian is built) and solve again
    	_problem.solverParams()._type = Moose::stringToEnum<Moose::SolveType>("NEWTON");

    	_problem.solve();


    	// attempt to get jacobian directly

    	NonlinearSystem & nl =  _problem.getNonlinearSystem();
    	nl.sys().assembly(/*residual*/false,/*jacobian*/true);  // system matrix should hold jacobian


    	//std::cout << "System type " << nl.sys().system_type() << std::endl; // TransientNonlinearImplicit

    	nl.sys().matrix->close();  // needed to complete assembly?

    	bool doPrintToScreen = false;
    	if(doPrintToScreen){
    	  nl.sys().matrix->print(std::cout,true);
    	}

    	bool doDumpToFile = false;
    	if (doDumpToFile){
    		//
    		std::ofstream fout("jacobian.txt");
    		nl.sys().matrix->print(fout,true);
    	}


    	bool doFindEigenValues = true;
    	if(doFindEigenValues){ // run eigen solver



#ifdef LIBMESH_HAVE_SLEPC

    	// get reference to petsc matrix holder
        PetscMatrix<Number>* petMat  = dynamic_cast< PetscMatrix<Number>*  >( nl.sys().matrix ); // explicit copy - slow but safe

        if(petMat){

          // extract the actual petsc matrix
          Mat A = petMat->mat();   /* Ax = kx */

          EPS        eps; /* eigen value solver context */ // need slepc for this
          Vec         xr, xi;    /*  eigenvector, x (real and imag) */
          PetscScalar kr, ki;    /*  eigenvalue, k (real and imag)  */

          MatCreateVecs(A,NULL,&xr);
          MatCreateVecs(A,NULL,&xi);

          EPSCreate(PETSC_COMM_WORLD, &eps); // PETSC_COMM_WORLD ??? > seems ok but might be a better option.

          EPSSetOperators(eps, A, NULL);

          EPSSetProblemType(eps, EPS_NHEP); // are they hermitian? > assuming they are not (unlikely given bcs)

          EPSSetFromOptions(eps); // sets from command line - can be used to return more eigen vectors

          EPSSolve(eps);

          if(true){
        	  // report on solve
        	PetscInt       Istart,Iend,nev,maxit,its;
        	PetscReal      tol;
        	EPSType        type;
            EPSGetIterationNumber(eps,&its);
            PetscPrintf(PETSC_COMM_WORLD," Number of iterations of the method: %D\n",its);
            EPSGetType(eps,&type);
            PetscPrintf(PETSC_COMM_WORLD," Solution method: %s\n\n",type);
            EPSGetDimensions(eps,&nev,NULL,NULL);
            PetscPrintf(PETSC_COMM_WORLD," Number of requested eigenvalues: %D\n",nev);
            EPSGetTolerances(eps,&tol,&maxit);
            PetscPrintf(PETSC_COMM_WORLD," Stopping condition: tol=%.4g, maxit=%D\n",(double)tol,maxit);
          }

          PetscInt nconv;
          EPSGetConverged(eps, &nconv);
          PetscInt m, n;
          MatGetSize(A,&m, &n);

          for (int i=0; i<nconv; i++) {

      	      PetscReal      re,im,error;

        	  EPSGetEigenpair(eps, i, &kr, &ki, xr, xi);

        	  // compute error
        	  if(true){
        	    EPSComputeError(eps,i,EPS_ERROR_RELATIVE,&error);
        	  }

        	  // display eigen values
#if defined(PETSC_USE_COMPLEX)
        	  re = PetscRealPart(kr);
        	  im = PetscImaginaryPart(kr);
#else
        	  re = kr;
        	  im = ki;
#endif
        	  if (im!=0.0) {
        		  PetscPrintf(PETSC_COMM_WORLD," %9f%+9fi %12g\n",(double)re,(double)im,(double)error);
        	  } else {
        		  PetscPrintf(PETSC_COMM_WORLD,"   %12f       %12g\n",(double)re,(double)error);
        	  }

        	  // display eigen vector
        	  VecView(xr,PETSC_VIEWER_STDOUT_WORLD);

          }


          // clean up
          EPSDestroy(&eps);
        }

#else
        // need slepc to run eigen solver (can still calculate from "jacobian.txt" though if it has been created)
        _console <<  std::scientific << COLOR_RED
		<< "Error!! Calculation of eigenvalues requires libMesh to be compiled with SLEPc eigen solver support!\n"
        << COLOR_DEFAULT;
        break;

#endif  // LIBMESH_HAVE_SLEPC

    	}

    }




#else
  _console << "Aborting as unable to modify Petsc options\n";
  break;

#endif //LIBMESH_HAVE_PETSC

    _problem.onTimestepEnd();
    _problem.execute(EXEC_TIMESTEP_END);

    _problem.computeIndicators();
    _problem.computeMarkers();

    _problem.outputStep(EXEC_TIMESTEP_END);

#ifdef LIBMESH_ENABLE_AMR
    if (r_step != steps)
    {
      _problem.adaptMesh();
    }

    _time_step++;
    _time = _time_step;                 // need to keep _time in sync with _time_step to get correct output
  }
#endif

  postExecute();
}

void
SteadyWithJacobian::checkIntegrity()
{
  // check to make sure that we don't have any time kernels in this simulation (Steady State)
  if (_problem.getNonlinearSystem().containsTimeKernel())
    mooseError("You have specified time kernels in your steady state simulation");
}
