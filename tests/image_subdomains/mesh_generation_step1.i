# first step of creating a mesh from CT scan image
# This generates the file `1block_mesh.e` containing the mesh with 1block but the level of refinement/adaptivity that we want.

[Mesh]
  type = GeneratedMesh
  #dimension of your mesh
  dim = 3
  #choose the element type of your mesh (triangle,tetrahedra,hexagone...)
  elem_type = HEX
  #level of refinement, mesh resolution of 5 in x is equal to nx*2^5
  #the more levels of refinement you have the more you can coarsen the mesh
  uniform_refine = 3
  nx = 1
  ny = 1
  nz = 1
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

[Adaptivity]
  #the number of adaptivity steps has to be equal or inferior to the level of refinement
  max_h_level = 3
  initial_steps = 1
  initial_marker = marker
  [./Indicators]
    [./indicator]
      type = GradientJumpIndicator
      variable = u
    [../]
  [../]
  [./Markers]
    [./marker]
      type = ErrorFractionMarker
      indicator = indicator
      # in percentage. 0 means no refinement/coarsening
      coarsen = 0.3
      refine = 0.3
    [../]
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
  file_base = 1block_mesh
  exodus = true
[]
