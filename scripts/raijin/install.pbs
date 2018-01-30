#!/bin/bash
#PBS -P ws55
#PBS -q copyq
#PBS -l walltime=10:00:00
#PBS -l mem=4GB
#PBS -l jobfs=10GB
#PBS -l ncpus=1
#email when starting and ending
## For licensed software, you have to specify it to get the job running. For unlicensed software, you should also specify it to help us analyse the software usage on our system.
#PBS -l software=Petsc
#PBS -l wd
#PBS -o job_out.txt
#PBS -e job_err.txt
echo "Starting:" `date`
echo "Loading modules..."
module load gcc/5.2.0
module load llvm/3.9.1
module load vtk/6.3.0
module load cmake/3.6.2
module load intel-mpi/2017.0.098
export CC=mpicc 
export CXX=mpicxx
export FC=mpif90 
export F90=mpif90 
export STACK_SRC="/short/ws55/<username>/tmp"
export PACKAGES_DIR="/short/ws55/<username>/opt/moose"
export PATH="/short/ws55/jl1719/opt/anaconda2/bin:$PATH"
unset PETSC_DIR
cd $STACK_SRC
rm -rf petsc-3.7.4
curl -L -O http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/petsc-3.7.4.tar.gz
tar -xf petsc-3.7.4.tar.gz -C .
cd $STACK_SRC/petsc-3.7.4
./configure \
--prefix=$PACKAGES_DIR/petsc-3.7.4 \
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
--download-mumps=1 \
--download-scalapack=1 \
--CC=mpicc --CXX=mpicxx --FC=mpif90 --F77=mpif77 --F90=mpif90 \
--CFLAGS='-fPIC -fopenmp' \
--CXXFLAGS='-fPIC -fopenmp' \
--FFLAGS='-fPIC -fopenmp' \
--FCFLAGS='-fPIC -fopenmp' \
--F90FLAGS='-fPIC -fopenmp' \
--F77FLAGS='-fPIC -fopenmp' \
--LDFLAGS='-L/apps/gcc/5.2.0/lib64'
make PETSC_DIR=/short/ws55/<username>/tmp/petsc-3.7.4 PETSC_ARCH=arch-linux2-c-opt all
make PETSC_DIR=/short/ws55/<username>/tmp/petsc-3.7.4 PETSC_ARCH=arch-linux2-c-opt install
export PETSC_DIR="/short/ws55/<username>/opt/moose/petsc-3.7.4"
mkdir /short/ws55/<username>/project
cd /short/ws55/<username>/project
git clone https://github.com/idaholab/moose.git
cd moose
git checkout master
#this queue only has 1 CPU.
#this will be slow since MOOSE_JOBS is set to 1.
#set it to 32 on interactive sessions.
export MOOSE_JOBS=1
scripts/update_and_rebuild_libmesh.sh
cd test
#on interactive use make -j32
make
cd ..
cd modules
make
echo "Ending:" `date`