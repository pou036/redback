#!/bin/sh
for PARAM_SLOPE in 0.45 0.5 0.55 0.6 0.64
do
    echo $PARAM_SLOPE
for PARAM_SIGMA_IN in 1 0.85 0.8 0.75
do
    echo $PARAM_SLOPE $PARAM_SIGMA_IN
    mpiexec -n 1 /Users/manman/projects/redback/redback-opt -i Thin_test_slope0.1_linear1.i --n-threads=2 Outputs/csv=true Functions/inner_pressure_fct/value=1e-3*$PARAM_SIGMA_IN Materials/plastic_material/slope_yield_surface=$PARAM_SLOPE Outputs/file_base=bifur_exp1_slope_${PARAM_SLOPE}_sigmain_${PARAM_SIGMA_IN}

done


done
