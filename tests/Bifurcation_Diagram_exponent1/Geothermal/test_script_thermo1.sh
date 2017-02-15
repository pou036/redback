#!/bin/sh
for PARAM_SLOPE in 0 '''0.15 0.3'''
do
    echo $PARAM_SLOPE
for PARAM_SIGMA_IN in 4 2 5 '''3 1.5 1.33'''
do
    echo $PARAM_SLOPE $PARAM_SIGMA_IN
    mpiexec -n 1 /Users/manman/projects/redback/redback-opt -i Thermo_slope0.1_linear1.i --n-threads=2 Outputs/csv=true Functions/inner_pressure_fct/value=1e-3*$PARAM_SIGMA_IN Materials/plastic_material/slope_yield_surface=$PARAM_SLOPE Outputs/file_base=geothermo_bifur_slope_${PARAM_SLOPE}_sigmain_${PARAM_SIGMA_IN}

done


done
