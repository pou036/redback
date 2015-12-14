[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./du_dt]
    type = TimeDerivative
    variable = u
  [../]
  [./diff_u]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./u_bound]
    type = DirichletBC
    variable = u
    boundary = left
    value = 1
  [../]
  [./u_dir]
    type = DirichletBC
    variable = u
    boundary = 'bottom right top'
    value = 0
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 2
[]

[Outputs]
  exodus = true
  file_base = eleni_test
[]

