#!/usr/bin/env bash

EXEC=~/projects/redback/redback-opt

for CONFINEMENT in 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8
do
    echo $CONFINEMENT
    mpiexec -n  1 $EXEC -i Oka.i --n-threads=2 Outputs/csv=true BCs/confinement_left/value=$CONFINEMENT BCs/confinement_right/value=-$CONFINEMENT BCs/confinement_front/value=-$CONFINEMENT BCs/confinement_back/value=$CONFINEMENT
    python create_postprocess_pics_from_csv.py
    mv Oka.csv oka_confinement_${CONFINEMENT}.csv
    mv Oka.e oka_confinement_${CONFINEMENT}.e
    mv pics_postprocess/P-Q/P-Q_00050.png pics_postprocess/P-Q/confinement_${CONFINEMENT}.png
done
