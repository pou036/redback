[GlobalParams]
  ar = 12
  gr = 1
[]

[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 20
  ny = 5
  nz = 5
  xmin = -1
[]

[Variables]
  [./pressure]
  [../]
  [./temp]
  [../]
[]

[AuxVariables]
  [./strain_rate]
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
  [../]
[]

[AuxKernels]
  [./strain_rate]
    type = StrainRateAux
    variable = strain_rate
    execute_on = timestep
    temp = temp
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
  [./strain]
    type = StrainRatePoint
    variable = temp
    point = '0 0 0'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1000
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    percent_change = 0.3
    dt = 1e-4
  [../]
[]

[Adaptivity]
  marker = efm
  max_h_level = 3
  [./Indicators]
    [./strain_indicator]
      type = GradientJumpIndicator
      variable = strain_rate
    [../]
  [../]
  [./Markers]
    [./efm]
      type = ErrorFractionMarker
      coarsen = 0.05
      indicator = strain_indicator
      refine = 0.8
    [../]
  [../]
[]

[Outputs]
  exodus = true
  console = true
[]

