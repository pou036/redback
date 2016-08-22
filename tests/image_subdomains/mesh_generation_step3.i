# last step of creating a mesh from CT scan image
# This generates the file `2blocks_mesh.e` containing the mesh of 2blocks. The subdomain has been created.

[Mesh]
  type = FileMesh
  file = gold/1block_mesh.e
[]

#paragraph that needs to be paste in all three steps of the simulation
[Functions]
  [./image_func]
    type = ImageFunction
    threshold = 90
    file_suffix = png
    file_base = stack/test_0
    file_range = '0 3'
  [../]
[]

[MeshModifiers]
  #differentiate the block 2 (pores) from the block 0 (grains)
  [./subdomain]
    type = ElementFileSubdomain
    subdomain_ids = 2
    file = gold/idfile_unique.txt
  [../]
  #creates the interface boundary
  [./edge]
    type = SideSetsBetweenSubdomains
    master_block = 0
    new_boundary = 10
    paired_block = 2
  [../]
[]

[Variables]
  [./u]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[ICs]
  [./u_ic]
    type = FunctionIC
    function = image_func
    variable = u
  [../]
[]

[Problem]
  type = FEProblem
  solve = false
[]

[Executioner]
  type = Steady
[]

[Outputs]
  file_base = 2blocks_mesh
  exodus = true
[]
