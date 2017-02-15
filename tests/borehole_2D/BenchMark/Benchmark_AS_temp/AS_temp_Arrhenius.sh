#!/bin/sh

'''slope is set as 0; test bifurcation stress_in with different values of Ar '''
for PARAM_Ar in 8 10
do
    echo $PARAM_Ar

    echo $PARAM_Ar
    mpiexec -n 1 /Users/manman/projects/redback/redback-opt -i Benchmark_highE_test_1_Ar.i --n-threads=2 Outputs/csv=true \
    Materials/no_mech/ar=$PARAM_Ar \
    Materials/plastic_material/slope_yield_surface=0 \
    Outputs/file_base=benchmark_highE_Ar_${PARAM_Ar}


done
