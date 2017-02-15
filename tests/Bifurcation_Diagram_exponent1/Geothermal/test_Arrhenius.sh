#!/bin/sh

'''slope is set as 0; test bifurcation stress_in with different values of Ar '''
for PARAM_Ar in 0 2 '''0 2 5 7 10'''
do
    echo $PARAM_Ar
for PARAM_SIGMA_IN in 3 2.5 1.5 '''4 2 1.5 1.33 1'''
do
    echo $PARAM_Ar $PARAM_SIGMA_IN
    mpiexec -n 1 /Users/manman/projects/redback/redback-opt -i Thermo_slope0.1_linear1.i --n-threads=2 Outputs/csv=true \
    Functions/inner_pressure_fct/value=1e-3*$PARAM_SIGMA_IN Materials/no_mech/ar=$PARAM_Ar \
    Materials/plastic_material/slope_yield_surface=0 \
    Outputs/file_base=test_bifur_Ar_${PARAM_Ar}_sigmain_${PARAM_SIGMA_IN}

done


done
