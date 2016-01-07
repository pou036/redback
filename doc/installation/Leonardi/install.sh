#!/bin/bash
#install Moose and Redback on Leonardi

#to use: ./install.sh

#before running this script:
#TODO: put the file .moose-profile in ~/
#this will get called in jobs

#TODO: put the file moose-dev-gcc in ~/
#this will get loaded as a module

echo "starting:" `date`
#TODO: NUM_PROC should be set externally by user
export NUM_PROC=48
export MOOSE_JOBS=$NUM_PROC

printf "\n\n**** step 1: petsc ****\n\n"
# step 1 doesn't work in the job system; complains about CMake

# dependencies
mkdir ~/tmp
export CLUSTER_TEMP=`mktemp -d ~/tmp/cluster_temp.XXXXXX`
cd $CLUSTER_TEMP
curl -L -O http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/petsc-3.6.0.tar.gz
umask 0022
mkdir ~/moose-compilers
export PACKAGES_DIR=~/moose-compilers

cd $CLUSTER_TEMP
tar -xf petsc-3.6.0.tar.gz
mkdir ~/moose-compilers/modulefiles

export MODULEPATH=$MODULEPATH:$PACKAGES_DIR/modulefiles

source ~/.moose-profile
cp ~/moose-dev-gcc ~/moose-compilers/modulefiles

# loading modules; these two are preexisting
module purge
module load rocks-openmpi
module load opt-python

# this one is in $PACKAGES_DIR/modulefiles
module load moose-dev-gcc

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
#make PETSC_DIR=~/moose-compilers/petsc/petsc-3.6.0/gcc-opt PETSC_ARCH="" test
#make PETSC_DIR=/home/z3465651/moose-compilers/petsc/petsc-3.6.0/gcc-opt PETSC_ARCH= streams NPMAX=$NUM_PROC


#cleaning up
rm -rf $CLUSTER_TEMP
# done with dependencies
printf "\n\n**** step 2: download moose ****\n\n"


#setting up Moose
mkdir ~/projects
cd ~/projects
git clone https://github.com/idaholab/moose.git
cd ~/projects/moose
git checkout master
#here we force the libmesh configure file to use PAX in single-volume mode.
sed -i '' "s/'pax -'/'pax -O -'/g" ~/projects/moose/libmesh/configure

#this is the slow part - takes an hour or more.
printf "\n\n**** step 3: libmesh setup ****\n\n"
scripts/update_and_rebuild_libmesh.sh

printf "\n\n**** step 4: moose build and tests ****\n\n"
cd ~/projects/moose/test
make -j$NUM_PROC
./run_tests -j$NUM_PROC
#TODO: pipe the results; make sure it says "0 failed"

printf "\n\n**** step 5: redback ****\n\n"
#setting up Redback
cd ~/projects
git clone https://github.com/pou036/redback
cd ~/projects/redback
git checkout master
make -j$NUM_PROC
./run_tests -j$NUM_PROC
#TODO: pipe the results; make sure it says "0 failed"

echo "ended:" `date`
