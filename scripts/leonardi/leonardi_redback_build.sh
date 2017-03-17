#!/bin/bash

# this script allows you to install or rebuild Moose and Redback on Leonardi
# the first time:  chmod u+x leonardi_redback_build.sh
#                  dos2unix leonardi_redback_build.sh
# to run it:       ./leonardi_redback_build.sh

echo "starting:" `date`
#setting up environment variables
export PACKAGES_DIR=/home/z5014651/opt/moose
export MOOSE_DIR=$PACKAGES_DIR/moose
export REDBACK_DIR=$HOME/projects/redback
export BRANCH_NAME=master
export MOOSE_JOBS=35

# loading modules
module purge
module load gcc/5.4.0
module list

#if you are using openmpi
export CC=mpicc
export CXX=mpicxx
export F90=mpif90
export F77=mpif77
export FC=mpif90
#if you are using gcc
export ARCH=gcc
export PETSC_ARCH=arch-linux2-c-opt
#depends on your petsc version
export PETSC_DIR=$PACKAGES_DIR/petsc/openmpi_petsc-3.6.1/gcc-opt-superlu

export GCC_HOME=/share/apps/gcc/5.4.0
export MPI_HOME=$PACKAGES_DIR/openmpi/openmpi-1.8.4/gcc-opt
#depends on vtk build
export VTKINCLUDE_DIR=$PACKAGES_DIR/vtk-6.3/gcc-opt/include/vtk-6.3
export VTKLIB_DIR=$PACKAGES_DIR/vtk-6.3/gcc-opt/lib

export DYLD_LIBRARY_PATH=$PACKAGES_DIR/miniconda/lib:$GCC_HOME/lib:$MPI_HOME/lib:$MPI_HOME/lib/openmpi:$VTKLIB_DIR:$DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$PACKAGES_DIR/miniconda/lib:$GCC_HOME/lib:$MPI_HOME/lib:$MPI_HOME/lib/openmpi:$VTKLIB_DIR:$LD_LIBRARY_PATH
export PATH=$PACKAGES_DIR/miniconda/bin:$GCC_HOME/bin:$MPI_HOME/bin:$PATH


printf "\n\n**** redback build ****\n\n"
#setting up Redback
mkdir -p $REDBACK_DIR
cd $REDBACK_DIR/..
git clone https://github.com/pou036/redback
cd $REDBACK_DIR
git clean -xfd
git checkout $BRANCH_NAME
#compile redback
make -j$MOOSE_JOBS
printf "\n\n**** redback tests ****\n\n"
./run_tests -j$MOOSE_JOBS
#TODO: pipe the results; make sure it says "0 failed"

echo "ended:" `date`
