#!/usr/bin/env bash

EXEC=~/projects/redback/redback-opt

for N in {8..16}
do
	echo $N
	mpiexec -n ${N} ${EXEC} -i two_material_folding_tm.i > foo.txt 2>&1
	grep 'Redback Performance' foo.txt
done
#rm foo.txt
