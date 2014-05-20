[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 20
  xmin = -1
[]

[Variables]
  [./pressure]
  [../]
  [./temp]
  [../]
[]

[Kernels]
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
[]

[BCs]
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
    value = 0
  [../]
  [./right_temp]
    type = DirichletBC
    variable = temp
    boundary = right
    value = 0
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
  ss_check_tol = 1e-6
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

