[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 1000
  xmin = -1
[]

[Variables]
  active = 'temp'
  [./pressure]
  [../]
  [./temp]
  [../]
  [./u]
    block = 0
  [../]
[]

[Kernels]
  active = 'cube_term diff_temp td_temp'
  [./td_pressure]
    type = TimeDerivative
    variable = pressure
  [../]
  [./diff_pressure]
    type = CoefDiffusion
    variable = pressure
    coef = 1
  [../]
  [./td_temp]
    type = TimeDerivative
    variable = temp
    block = 0
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temp
  [../]
  [./mh_temp]
    type = MechHeat
    variable = temp
    ar = 10
    gr = 100
  [../]
  [./cube_term]
    type = CubeTerm
    variable = temp
    block = 0
    lambda = 60
  [../]
[]

[BCs]
  active = 'left_temp right_temp'
  [./left_pressure]
    type = DirichletBC
    variable = pressure
    boundary = left
    value = 0
  [../]
  [./right_pressure]
    type = DirichletBC
    variable = pressure
    boundary = right
    value = 0
  [../]
  [./left_temp]
    type = DirichletBC
    variable = temp
    boundary = left
    value = 1
  [../]
  [./right_temp]
    type = DirichletBC
    variable = temp
    boundary = right
    value = 1
  [../]
[]

[Postprocessors]
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1000
  dt = 1e-2
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  end_time = 1e+2
  dtmax = 1e+2
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    percent_change = 0.3
    dt = 1e-4
  [../]
[]

[Outputs]
  exodus = true
  console = true
[]

[ICs]
  [./my_ic]
    variable = temp
    value = 1
    type = ConstantIC
    block = 0
  [../]
[]

