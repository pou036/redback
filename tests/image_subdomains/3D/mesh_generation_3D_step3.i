[Mesh]
  type = FileMesh
  file = 1block_mesh_3D.e
[]

[MeshModifiers]
  [./subdomain]
    type = ElementFileSubdomain
    subdomain_ids = 2
    file = idfile_unique.txt
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
  file_base = 2blocks_mesh_3D
  exodus = true
[]

