#!/bin/bash -vx
#this script allows you to install Moose and Redback on Leonardi
#before running this script, .moose-profile and moose-dev-gcc must be in ~/.
#to use: ./install.sh

DO_INSTALL_PREREQUISITES=1 # value 0 or 1. No space around the equal sign!
DO_COMPILE_LIBMESH=1 # value 0 or 1. No space around the equal sign!  This al
DO_INSTALL_OR_UPDATE_MOOSE_REDBACK=1 # value 0 or 1. No space around the equal sign!


####### Nothing to touch below ! #############################
export INSTALL_ROOT_DIR=~
mkdir $INSTALL_ROOT_DIR
#setting up environment variables
echo "starting:" `date`
export NUM_PROC=12
export MOOSE_JOBS=$NUM_PROC

mkdir $INSTALL_ROOT_DIR/moose-compilers
export PACKAGES_DIR=$INSTALL_ROOT_DIR/moose-compilers

mkdir $INSTALL_ROOT_DIR/moose-compilers/modulefiles
export MODULEPATH=$MODULEPATH:$PACKAGES_DIR/modulefiles

#copy the module file over if it doesn't already exist
cp ~/moose-dev-gcc $INSTALL_ROOT_DIR/moose-compilers/modulefiles

# loading modules
#these two are preexisting
module purge
module load rocks-openmpi
module load opt-python
# this one is in $PACKAGES_DIR/modulefiles
module load moose-dev-gcc

#deprecated
#source ~/.moose-profile

set base_path   $INSTALL_ROOT_DIR/moose-compilers
export CC=mpicc
export CXX=mpicxx
export F90=mpif90
export F77=mpif77
export FC=mpif90
export ARCH=gcc
export PETSC_DIR=$PACKAGES_DIR/petsc/petsc-3.6.0/$ARCH-opt

if [ $DO_INSTALL_PREREQUISITES -eq 1 ]
  then
    printf "\n\n**** step 1: petsc ****\n\n"

    # petsc
    mkdir $INSTALL_ROOT_DIR/tmp
    export CLUSTER_TEMP=`mktemp -d $INSTALL_ROOT_DIR/tmp/cluster_temp.XXXXXX`
    cd $CLUSTER_TEMP
    curl -L -O http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/petsc-3.6.0.tar.gz
    umask 0022
    cd $CLUSTER_TEMP
    tar -xf petsc-3.6.0.tar.gz

    #PETSC setup
    cd $CLUSTER_TEMP/petsc-3.6.0
    ./configure \
    --prefix=$PETSC_DIR \
    --download-hypre=1 \
    --with-ssl=0 \
    --with-debugging=no \
    --with-pic=1 \
    --with-shared-libraries=1 \
    --with-cc=mpicc \
    --with-cxx=mpicxx \
    --with-fc=mpif90 \
    --download-fblaslapack=1 \
    --download-metis=1 \
    --download-parmetis=1 \
    --download-superlu_dist=1 \
    CC=mpicc CXX=mpicxx FC=mpif90 F77=mpif77 F90=mpif90 \
    CFLAGS='-fPIC -fopenmp' \
    CXXFLAGS='-fPIC -fopenmp' \
    FFLAGS='-fPIC -fopenmp' \
    FCFLAGS='-fPIC -fopenmp' \
    F90FLAGS='-fPIC -fopenmp' \
    F77FLAGS='-fPIC -fopenmp' \
    PETSC_DIR=`pwd`

    make PETSC_DIR=$CLUSTER_TEMP/petsc-3.6.0 PETSC_ARCH=arch-linux2-c-opt all
    make PETSC_DIR=$CLUSTER_TEMP/petsc-3.6.0 PETSC_ARCH=arch-linux2-c-opt install


    #TODO: are these actually necessary? seem to be just benchmarks
    #make PETSC_DIR=$INSTALL_ROOT_DIR/moose-compilers/petsc/petsc-3.6.0/gcc-opt PETSC_ARCH="" test
    #make PETSC_DIR=$INSTALL_ROOT_DIR/moose-compilers/petsc/petsc-3.6.0/gcc-opt PETSC_ARCH= streams NPMAX=$NUM_PROC


    #cleaning up
    rm -rf $CLUSTER_TEMP
    # done with dependencies
fi # end of step 1

if [ $DO_COMPILE_LIBMESH -eq 1 ] || [ $DO_INSTALL_OR_UPDATE_MOOSE_REDBACK -eq 1 ]
  then
    printf "\n\n**** step 2: download moose ****\n\n"


    #setting up Moose
    mkdir $INSTALL_ROOT_DIR/projects
    cd $INSTALL_ROOT_DIR/projects
    git clone https://github.com/idaholab/moose.git
    cd $INSTALL_ROOT_DIR/projects/moose
    git checkout master
    git pull
    #here we force the libmesh configure file to use PAX in single-volume mode.
    #https://lists.gnu.org/archive/html/automake/2011-03/msg00113.html
    #sed is different on osx and linux.  this is the osx version:
    #sed -i '' "s/'pax -r'/'pax -O -r'/g" $INSTALL_ROOT_DIR/projects/moose/libmesh/configure
    #and this is the linux version:
    #doesn't work, too bad.
    #sed -i -e 's/pax -r/pax -r -O/g' $INSTALL_ROOT_DIR/projects/moose/libmesh/configure

fi # end of step 2


if [ $DO_COMPILE_LIBMESH -eq 1 ]
  then
    #this is the slow part - takes an hour or more.
    printf "\n\n**** step 3: libmesh setup ****\n\n"
    cd $INSTALL_ROOT_DIR/projects/moose
    scripts/update_and_rebuild_libmesh.sh
fi


if [ $DO_INSTALL_OR_UPDATE_MOOSE_REDBACK -eq 1 ]
  then
    printf "\n\n**** step 4: moose build and tests ****\n\n"
    cd $INSTALL_ROOT_DIR/projects/moose/test
    make -j$NUM_PROC
    ./run_tests -j$NUM_PROC
    #TODO: pipe the results; make sure it says "0 failed"

    printf "\n\n**** step 5: redback ****\n\n"
    #setting up Redback
    cd $INSTALL_ROOT_DIR/projects
    git clone https://github.com/pou036/redback
    cd $INSTALL_ROOT_DIR/projects/redback
    git checkout master
    git pull
    make -j$NUM_PROC
    ./run_tests -j$NUM_PROC
    #TODO: pipe the results; make sure it says "0 failed"
fi #end of step 4 and 5

echo "ended:" `date`
