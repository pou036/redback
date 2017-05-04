#!/bin/bash

# submit using "sbatch run_job.sh"
# Lines starting with "#SBATCH" are directives to the scheduler

# Job name
#SBATCH --job-name=run

# details of queues at http://leonardi.unsw.wikispaces.net/Queues+and+Job+Sizes
# Replace the partition to run in other queues
#SBATCH --partition=short48

# Job attributes (depending on partition as well)
# These attributes indicate the maximum allocated
#SBATCH --time=00:15:00
#SBATCH --nodes=1
# ntasks is the total number of processors
#SBATCH --ntasks=48

# Output name and location
#SBATCH --output=/home/z5014651/logs/run-%j.log

# The job proper start here
echo "Starting:" `date`

echo "Loading modules..."
module purge
module load gcc/5.4.0
module list

#setting up environment variables
export PACKAGES_DIR=/home/z5014651/opt/moose
#/var/spool/slurmd/job55629/slurm_script: line 62: mpirun: command not found
export MPI_HOME=$PACKAGES_DIR/openmpi/openmpi-1.8.4/gcc-opt
#/home/z5014651/projects/redback/redback-opt: error while loading shared libraries: libvtkCommonExecutionModel-6.3.so.1: cannot open shared object file: No such file or directory
export VTKLIB_DIR=$PACKAGES_DIR/vtk-6.3/gcc-opt/lib
export LD_LIBRARY_PATH=$VTKLIB_DIR:$LD_LIBRARY_PATH
export PATH=$MPI_HOME/bin:$PATH

echo "Defining directories..."
export EXECUTABLE=$HOME/projects/redback/redback-opt
export SIMULATION_DIR=$HOME/run_files

cd $SIMULATION_DIR

echo "Running..."
# N is the number of processors per node
# n is the total number of processors
mpirun -N 47 -n 47 $EXECUTABLE -i input_file.i
echo "Ending:" `date`
