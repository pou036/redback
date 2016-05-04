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
            << "\n +++ Steady state solution found - outputting Jacobian +++ \n"
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

    	// Petsc will exit at this point after the jacobian is be dumped to std out
    } else if(false){

    	Moose::PetscSupport::PetscOptions &  thePetscOptions  =  _problem.getPetscOptions();
    	thePetscOptions.inames.push_back("-mat_fd_type");
    	thePetscOptions.values.push_back("ds");

    	// change solve type to Newton
    	_problem.solverParams()._type = Moose::stringToEnum<Moose::SolveType>("NEWTON");

    	//_problem.solve();  // solve releases the jacobian on exit?

        Moose::PetscSupport::petscSetOptions(_problem); // Make sure the PETSc options are setup for this app
        Moose::setSolverDefaults(_problem);

        // Setup the output system for printing linear/nonlinear iteration information
        _problem.initPetscOutput();

        _problem.possiblyRebuildGeomSearchPatches();


    	std::cout << "Got here A " << std::endl ;

    	// attempt to get jacobian directly (reproduce snestest.c routines)

    	NonlinearSystem & nl =  _problem.getNonlinearSystem();

    	//nl.init();
    	nl.solve();

        nl.update();

    	//PetscNonlinearSolver<Number> *petsc_solver = dynamic_cast<PetscNonlinearSolver<Number> *>(nl.sys().nonlinear_solver.get());

    	//std::cout << "petsc_solver " << petsc_solver << std::endl ;

    	//SNES snes = petsc_solver->snes();

    	PetscNonlinearSolver<Real> & petsc_solver = static_cast<PetscNonlinearSolver<Real> &>(*nl.sys().nonlinear_solver);

    	SNES snes = petsc_solver.snes();

    	std::cout << "snes " << snes << std::endl ;


    	std::cout << "Got here B " << std::endl ;

    	// snestest.c
    	Mat            A = snes->jacobian,B;
    	Vec            x = snes->vec_sol,f = snes->vec_func,f1 = snes->vec_sol_update;
    	PetscInt       i;
    	PetscReal      nrm,gnorm;
    	//SNES_Test      *neP = (SNES_Test*)snes->data;
    	PetscErrorCode (*objective)(SNES,Vec,PetscReal*,void*);
    	void           *ctx;
    	PetscReal      fnorm,f1norm,dnorm;

    	if (A != snes->jacobian_pre){
    		//SETERRQ(PETSC_COMM_SELF,PETSC_ERR_ARG_WRONG,"Cannot test with alternative preconditioner");

    	      _console << "Aborting as cannot output Petsc jacobian with alternative preconditioner\n";
    	      break;
    	}

    	std::cout << "A " << A << std::endl ;  // this is not being populated
    	std::cout << "x " << x << std::endl ;
    	std::cout << "f " << f << std::endl ;
    	std::cout << "f1 " << f1 << std::endl ;
    	std::cout << "Got here C " << std::endl ;

    	/* evaluate the function at this point because SNESComputeJacobianDefaultColor() assumes that the function has been evaluated and put into snes->vec_func */
    	/*
    	 * This is failing - could not this line in snestest.c for version 2.3.3
    	 *
    	SNESComputeFunction(snes,x,f);
    	if (snes->domainerror) {
    	    PetscPrintf(PetscObjectComm((PetscObject)snes),"Domain error at user-defined state\n");
    	    snes->domainerror = PETSC_FALSE;
    	    continue;
    	}
    	*/
    	PetscInt                 m,n,M,N;
        MatGetSize(A,&M,&N);
        std::cout << M << " " << N << std::endl;

    	std::cout << "Got here D " << std::endl ;

    	// user defined jacobian
    	SNESComputeJacobian(snes,x,A,A);

    	// finite difference jacobian
    	/*

    	//PetscInt                 m,n,M,N;
    	 MatCreate(PetscObjectComm((PetscObject)A),&B);
         MatGetSize(A,&M,&N);
    	 MatGetLocalSize(A,&m,&n);
    	 MatSetSizes(B,m,n,M,N);
    	 MatSetType(B,((PetscObject)A)->type_name);
    	 MatSetUp(B);
    	 MatSetOption(B,MAT_NEW_NONZERO_ALLOCATION_ERR,PETSC_FALSE);

    	 SNESGetFunction(snes,NULL,NULL,&functx);
    	 SNESComputeJacobianDefault(snes,x,B,B,functx);
    	 */

    	MPI_Comm    comm;
    	PetscViewer viewer;
    	//PetscPrintf(PetscObjectComm((PetscObject)snes),"Hand-coded Jacobian (%s)\n",loc[i]);
    	PetscObjectGetComm((PetscObject)A,&comm);
    	PetscViewerASCIIGetStdout(comm,&viewer);
    	MatView(A,viewer);





    } else {


    	Moose::PetscSupport::PetscOptions &  thePetscOptions  =  _problem.getPetscOptions();
    	thePetscOptions.inames.push_back("-mat_fd_type");
    	thePetscOptions.values.push_back("ds");

    	// change solve type to Newton
    	_problem.solverParams()._type = Moose::stringToEnum<Moose::SolveType>("NEWTON");

    	_problem.solve();  // solve releases the jacobian on exit?

    	/*
    	Moose::PetscSupport::petscSetOptions(_problem); // Make sure the PETSc options are setup for this app
    	Moose::setSolverDefaults(_problem);

    	// Setup the output system for printing linear/nonlinear iteration information
    	_problem.initPetscOutput();

    	_problem.possiblyRebuildGeomSearchPatches();


    	std::cout << "Got here A " << std::endl ;
    	*/

    	// attempt to get jacobian directly

    	NonlinearSystem & nl =  _problem.getNonlinearSystem();
    	nl.sys().assembly(false,true);


    	std::cout << "System type" << nl.sys().system_type() << std::endl;


    	nl.sys().matrix->close();

    	nl.sys().matrix->print();

    	//SparseMatrix<Number>

    	/*
    	PetscMatrix<Number> theJacobian(nl.comm());


    	std::cout << "Setting solution " << std::endl ;

    	nl.setSolution(*(nl.sys().current_local_solution.get()));
    	std::cout << "Computing jacobian " << std::endl ;
    	//nl.computeJacobian( theJacobian);

    	std::cout << nl.sys().current_local_solution.get() << std::endl;

    	_problem.computeJacobian(nl.sys(),*(nl.sys().current_local_solution.get()),theJacobian);

*/

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
