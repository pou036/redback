#!/usr/bin/env bash

/Users/martin/projects/redback/redback-opt -i mesh_generation_step1.i > result.txt
echo  end of first step, created adapted 1block mesh
/Users/martin/projects/redback/redback-opt -i mesh_generation_step2.i >> result.txt
echo  end of second step, created file "idfile.txt"
python remove_duplicates.py
/Users/martin/projects/redback/redback-opt -i mesh_generation_step3.i >> result.txt
echo  end of last step, created adapted 2blocks mesh
