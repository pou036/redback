#!/bin/sh

for PARAM_Ar in 4 6
do
    echo $PARAM_Ar
for PARAM_SIGMA_IN in 2 1.5
do
    echo $PARAM_Ar $PARAM_temp_OUT
for PARAM_temp_OUT in 10
do
    echo $PARAM_temp_OUT
    mpiexec -n 1 /Users/manman/projects/redback/redback-opt -i Thermo_slope0.1_linear1.i --n-threads=2 Outputs/csv=true \
    Functions/inner_pressure_fct/value=1e-3*$PARAM_SIGMA_IN Materials/no_mech/ar=$PARAM_Ar \
    Materials/plastic_material/slope_yield_surface=0 \
    BCs/Temp_outside/value=$PARAM_temp_OUT \
    Outputs/file_base=test_bifur_Ar_${PARAM_Ar}_sigmain_${PARAM_SIGMA_IN}_temp_${PARAM_temp_OUT}
done
done


done
