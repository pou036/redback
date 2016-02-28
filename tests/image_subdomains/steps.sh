#!/usr/bin/env bash

### script that runs all steps for creating a mesh from a Ct scan image

~/projects/redback/redback-opt -i mesh_generation_step1.i > result.txt
echo  end of first step, created adapted 1block mesh
~/projects/redback/redback-opt -i mesh_generation_step2.i >> result.txt
echo  end of second step, created file "idfile.txt"
python remove_duplicates.py
~/projects/redback/redback-opt -i mesh_generation_step3.i >> result.txt
echo  end of last step, created adapted 2blocks mesh
