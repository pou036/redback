#!/bin/bash -vx

# this script allows you to install or rebuild Moose and Redback on Leonardi
# the first time:  chmod u+x leonardi_build.sh
#                  dos2unix leonardi_build.sh
# to run it:       ./leonardi_build.sh

#No space around the equal sign!
DO_INSTALL_PREREQ=0
# 0 not to install prerequisite softwares // 1 to install some
DO_INSTALL_MINICONDA=0
DO_INSTALL_OPENMPI1_8_4=0
DO_INSTALL_PETSC3_6_1=0
DO_INSTALL_VTK6_3=0
# 0 not to install the softwares // 1 to install the softwares
# if 1, you need to download the file found at http://mooseframework.org/wiki/buildingredistributable/deb_redist/deb_redist-downloads/
# and place it in your $STACK_SRC directory
DO_COMPILE_LIBMESH=0
# 0 not to compile libmesh // 1 to compile libmesh
DO_INSTALL_OR_UPDATE_MOOSE=1
# 0 not to compile moose // 1 to compile moose // 2 to compile moose and all the modules
DO_INSTALL_OR_UPDATE_REDBACK=1
# 0 not to compile redback // 1 to compile redback


echo "starting:" `date`
#setting up environment variables
export PACKAGES_DIR=/home/z5014651/opt/moose
export STACK_SRC=/share/scratch/z5014651/opt/moose/stack_src
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

if [ $DO_INSTALL_PREREQ -eq 1 ]
  then
    mkdir -p $STACK_SRC
    mkdir -p $PACKAGES_DIR
    if [ $DO_INSTALL_MINICONDA -eq 1 ]
      then
        # Build of Miniconda, folowing instructions at
        # http://mooseframework.org/wiki/buildingredistributable/deb_redist/deb_redist-install/miniconda/
        cd $STACK_SRC/
        curl -L -O http://repo.continuum.io/miniconda/Miniconda-3.8.3-Linux-x86_64.sh
        bash Miniconda-3.8.3-Linux-x86_64.sh -b -p $PACKAGES_DIR/miniconda
        export PATH=$PACKAGES_DIR/miniconda/bin:$PATH
        export DYLD_LIBRARY_PATH=$PACKAGES_DIR/miniconda/lib:$DYLD_LIBRARY_PATH
        export LD_LIBRARY_PATH=$PACKAGES_DIR/miniconda/lib:$LD_LIBRARY_PATH

        conda update conda
        conda install coverage vtk=5.10 pyyaml matplotlib pyside
    fi
    if [ $DO_INSTALL_OPENMPI1_8_4 -eq 1 ]
      then
        # Extract the downloaded file
        cd $STACK_SRC/
        tar -xf openmpi-1.8.4.tar.gz -C $STACK_SRC
        # Build of openmpi 1.8.4, folowing instructions at
        # http://mooseframework.org/wiki/buildingredistributable/deb_redist/deb_redist-install/openmpi_gcc_openmpi/
        cd $STACK_SRC/openmpi-1.8.4
        mkdir gcc-opt
        cd gcc-opt
        ../configure --prefix=$PACKAGES_DIR/openmpi/openmpi-1.8.4/gcc-opt \
        CC=gcc CXX=g++ FC=gfortran F77=gfortran \
        CFLAGS='' CXXFLAGS='' FFLAGS='' FCFLAGS='' F77FLAGS=''
        make -j $MOOSE_JOBS
        make install

        export MPI_HOME=$PACKAGES_DIR/openmpi/openmpi-1.8.4/gcc-opt
        export PATH=$MPI_HOME/bin:$PATH
        export DYLD_LIBRARY_PATH=$MPI_HOME/lib:$MPI_HOME/lib/openmpi:$DYLD_LIBRARY_PATH
        export LD_LIBRARY_PATH=$MPI_HOME/lib:$MPI_HOME/lib/openmpi:$LD_LIBRARY_PATH

        cd $MPI_HOME/lib
        for sfile in `find . -type f -name "*.la"`; do \
          if [ `grep -c '/opt/moose/stack_src' $sfile` -ge 1 ]; then \
            echo 'editing file: '$sfile
            perl -pi -e "s/-L.\S*stack_src\S*[^'\s+]//g" $sfile; \
          fi; \
        done
    fi
    if [ $DO_INSTALL_PETSC3_6_1 -eq 1 ]
      then
        # Extract the downloaded file
        cd $STACK_SRC/
        tar -xf petsc-3.6.1.tar.gz -C $STACK_SRC
        # Build of petsc 3.6.1, folowing instructions at
        # http://mooseframework.org/wiki/buildingredistributable/deb_redist/deb_redist-install/openmpi_gcc_openmpi/
        cd $STACK_SRC/petsc-3.6.1
        ./configure \
        --prefix=$PACKAGES_DIR/petsc/openmpi_petsc-3.6.1/gcc-opt-superlu \
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
        --download-scalapack=1 \
        --download-mumps=1 \
        CC=mpicc CXX=mpicxx FC=mpif90 F77=mpif77 F90=mpif90 \
        CFLAGS='-fPIC -fopenmp' \
        CXXFLAGS='-fPIC -fopenmp' \
        FFLAGS='-fPIC -fopenmp' \
        FCFLAGS='-fPIC -fopenmp' \
        F90FLAGS='-fPIC -fopenmp' \
        F77FLAGS='-fPIC -fopenmp' \
        PETSC_DIR=`pwd`
        # The following commands are taken from instructions during
        # the configure/build process. Your mileage may vary, so pay
        # close attention to what PETSc is telling you to do next
        make PETSC_DIR=$STACK_SRC/petsc-3.6.1 PETSC_ARCH=arch-linux2-c-opt all
        make PETSC_DIR=$STACK_SRC/petsc-3.6.1 PETSC_ARCH=arch-linux2-c-opt install
        make PETSC_DIR=$PACKAGES_DIR/petsc/openmpi_petsc-3.6.1/gcc-opt-superlu PETSC_ARCH="" test
        # PETSc will ask you to perform additional tests, you can if
        # you want, but we are done.
        export PETSC_DIR=$PACKAGES_DIR/petsc-3.6.1/gcc-opt-superlu
    fi
    if [ $DO_INSTALL_VTK6_3 -eq 1 ]
      then
        # Extract the downloaded file
        cd $STACK_SRC/
        tar -xf VTK-6.3.0.tar.gz -C $STACK_SRC
        # Build of VTK 6.3, folowing instructions at
        # http://mooseframework.org/wiki/buildingredistributable/deb_redist/deb_redist-install/vtk/
        mkdir -p $STACK_SRC/VTK6-Builds/gcc-opt
        cd $STACK_SRC/VTK6-Builds/gcc-opt
        cmake ../../VTK-6.3.0 \
              -DCMAKE_INSTALL_PREFIX=$PACKAGES_DIR/vtk-6.3/gcc-opt \
              -DCMAKE_BUILD_TYPE=Release \
              -DVTK_Group_Rendering=OFF \
              -DVTK_WRAP_PYTHON=ON \
              -Wno-dev
        make -j$MOOSE_JOBS
        make install

        #depends on vtk build
        export VTKINCLUDE_DIR=$PACKAGES_DIR/vtk-6.3/gcc-opt/include/vtk-6.3
        export VTKLIB_DIR=$PACKAGES_DIR/vtk-6.3/gcc-opt/lib
        export DYLD_LIBRARY_PATH=$VTKLIB_DIR:$DYLD_LIBRARY_PATH
        export LD_LIBRARY_PATH=$VTKLIB_DIR:$LD_LIBRARY_PATH
    fi
fi

if [ $DO_COMPILE_LIBMESH -eq 1 ] || [ $DO_INSTALL_OR_UPDATE_MOOSE -eq 1 ]
  then
    # Set top-level MOOSE directory and clone MOOSE git repo
    mkdir -p $MOOSE_DIR
    cd $MOOSE_DIR/..
    git clone https://github.com/idaholab/moose.git
    cd $MOOSE_DIR
    git clean -xfd
    git checkout master
fi

if [ $DO_COMPILE_LIBMESH -eq 1 ]
  then
    #this is the slow part - takes an hour or more.
    printf "\n\n**** libmesh setup ****\n\n"
    cd $MOOSE_DIR
    scripts/update_and_rebuild_libmesh.sh --with-vtk-include=$VTKINCLUDE_DIR --with-vtk-lib=$VTKLIB_DIR
fi

if [ $DO_INSTALL_OR_UPDATE_MOOSE -ge 1 ]
  then
    printf "\n\n**** moose build ****\n\n"
    cd $MOOSE_DIR/test
    make -j$MOOSE_JOBS
    printf "\n\n**** moose tests ****\n\n"
    ./run_tests -j$MOOSE_JOBS
    #TODO: pipe the results; make sure it says "0 failed"
    if [ $DO_INSTALL_OR_UPDATE_MOOSE -eq 2 ]
      then
        cd $MOOSE_DIR/modules
        printf "\n\n**** moose modules ****\n\n"
        make -j$MOOSE_JOBS
    fi
fi

if [ $DO_INSTALL_OR_UPDATE_REDBACK -eq 1 ]
  then
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
fi

echo "ended:" `date`
