#
#  Default .profile for bash/ksh/sh user of NF systems.  
#
#  Commands in this file are executed:
#  when a bash user first logs in
#
#  This file may alternatively be called $HOME/.bash_profile,
#  $HOME/.bash_login or $HOME/.profile - the first one of these
#  found is used.
#
#  The environment variables (and ulimits) set here will be 
#  inherited by subshells.  Use this file to set up your 
#  environment for an interactive session or a batch job.  
#  Most of the environment can be set using module commands.
#  Include commonly used module commands below but be wary of 
#  loading too many modules - you are likely to incur conflicts.
#  It is usually better to load the modules required by a bacth
#  in the batch script.
#
#  See http://nf.nci.org.au/facilities/software/modules.php
#  for instructions on how to set your environment to use specific
#  software packages.
#
#  Note that the .bashrc file is NOT executed at login time but 
#  instead every time a sh or bash script is run. 
#
#  $Id: default.profile,v 1.4 2008/12/18 00:08:09 dbs900 Exp $
#

#  By default .bashrc file is NOT sourced at login time but is in
#  subshells.  Source here to pick up aliases etc.

[ -f $HOME/.bashrc ] && . $HOME/.bashrc

umask 027

# module load dot adds the current directory to the end of your commands
# search path

#module load dot
module load gcc/5.2.0
module load llvm/3.9.1
module load vtk/6.3.0
module load cmake/3.6.2
module load intel-mpi/2017.0.098
export CC=mpicc 
export CXX=mpicxx
export FC=mpif90 
export F90=mpif90 
export MOOSE_JOBS=32
export STACK_SRC="/short/ws55/jl1719/tmp"
export PACKAGES_DIR="/short/ws55/jl1719/opt/moose"
export PATH="/short/ws55/jl1719/opt/anaconda2/bin:$PATH"
export PETSC_DIR="$PACKAGES_DIR/petsc-3.7.4"
PS1="\[\`if [[ \$? = "0" ]]; then echo '\e[32m\h\e[0m'; else echo '\e[31m\h\e[0m' ; fi\`:\w\n\$ "
echo ".profile loaded."