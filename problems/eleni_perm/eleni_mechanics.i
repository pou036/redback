[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
  xmin = -0.5
  xmax = 0.5
  ymin = -0.5
  ymax = 0.5
  elem_type = TRI3
[]

[Variables]
  [./disp_x]
    initial_condition = 0.0001
  [../]
  [./disp_y]
    initial_condition = 0.0001
  [../]
[]

[Kernels]
  [./TensorMechanics]
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

[BCs]
  [./1]
    type = DirichletBC
    variable = disp_x
    boundary = 'left right'
    value = 0.001
  [../]
  [./2]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0.0001
  [../]
  [./top_load]
    type = FunctionDirichletBC
    variable = disp_y
    boundary = top
    function = 0.1*t
  [../]
[]

[Materials]
  [./lnelast]
    type = FiniteStrainElasticMaterial
    block = 0
    fill_method = symmetric_isotropic
    disp_y = disp_y
    disp_x = disp_x
    C_ijkl = '1 0.25'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 4
  dt = 0.5
[]

[Outputs]
  exodus = true
  file_base = eleni_mechaniccs
[]

