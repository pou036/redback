#!/usr/bin/env bash

### script that runs all steps for creating a mesh from a Ct scan image

echo  'Start of first step on' `date`
~/projects/redback/redback-opt -i mesh_generation_step1.i -j $MOOSE_JOBS > result.txt
echo  'End of first step, created adapted 1block mesh on' `date`
~/projects/redback/redback-opt -i mesh_generation_step2.i -j $MOOSE_JOBS >> result.txt
echo  'End of second step, created file "idfile.txt" on' `date`
python remove_duplicates.py
~/projects/redback/redback-opt -i mesh_generation_step3.i -j $MOOSE_JOBS >> result.txt
echo  'End of last step, created adapted 2blocks mesh on' `date`
