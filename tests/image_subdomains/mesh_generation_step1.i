# first step of creating a mesh from CT scan image
# This generates the file `1block_mesh.e` containing the mesh with 1block but the level of refinement/adaptivity that we want.

[Mesh]
  type = GeneratedMesh
  dim = 3
  uniform_refine = 3
  elem_type = HEX
[]

[Adaptivity]
  max_h_level = 3
  initial_steps = 3
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
      coarsen = 0.6
      refine = 0.8
    [../]
  [../]
[]

[Variables]
  [./u]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./td]
    type = TimeDerivative
    variable = u
  [../]
[]

[Functions]
  [./image_func]
    type = ImageFunction
    threshold = 90
    upper_value = 1
    lower_value = 0
    file_suffix = png
    file_base = stack/test_0
    file_range = '0 3'
  [../]
[]

[ICs]
  [./u_ic]
    type = FunctionIC
    function = image_func
    variable = u
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1
  dt = 0.00001
  solve_type = PJFNK
[]

[Outputs]
  file_base = 1block_mesh
  exodus = true
[]

