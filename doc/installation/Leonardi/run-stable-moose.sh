#instructions to run stable install of Moose in Thomas's directory
export PBS_NUM_PPN=4
export STABLE_MOOSE_ROOT_DIR=/home/z3506778
echo "starting:" `date`
echo "    host:" `hostname`
echo "  loading modules"
module purge
module load rocks-openmpi
module load opt-python
mpirun -n $PBS_NUM_PPN $STABLE_MOOSE_ROOT_DIR/projects/redback/redback-opt -i $STABLE_MOOSE_ROOT_DIR/projects/redback/tests/benchmark_11_THMC/bench_THMC_CC.i
echo "  ending:" `date`
echo "bye"
