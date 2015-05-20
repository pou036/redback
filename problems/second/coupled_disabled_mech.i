[Mesh]
  type = FileMesh
  file = ../second/cascadia_simple2.e
[]

[Variables]
  active = 'pressure temp'
  [./pressure]
  [../]
  [./temp]
  [../]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
[]

[Kernels]
  active = 'td_temp diff_temp td_pres mht_temp diff_pres ce_temp cp_press'
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
    ar = 5
    block = subduction_zone
  [../]
  [./td_pres]
    type = TimeDerivative
    variable = pressure
  [../]
  [./mht_temp]
    type = MechHeatTensor
    variable = temp
    ar = 20
    block = subduction_zone
    gr = 1e-6
    alpha_2 = 4
    pressure = pressure
  [../]
  [./diff_pres]
    type = CoefDiffusion
    variable = pressure
    coef = 1 # Le
  [../]
  [./ce_temp]
    type = ChemEndo
    variable = temp
    ar_c = 40 # Arrhenius
    da = 1e-3
    block = subduction_zone
  [../]
  [./cp_press]
    type = ChemPressure
    variable = pressure
    ar_c = 40
    temp = temp
    mu = 1e-3
    block = subduction_zone
  [../]
[]

[BCs]
  active = 'surface_temp surface_pres'
  [./surface_temp]
    type = PresetBC
    variable = temp
    boundary = surface
    value = 0
  [../]
  [./surface_hold_x]
    type = DirichletBC
    variable = disp_x
    boundary = surface
    value = 0
  [../]
  [./surface_hold_y]
    type = DirichletBC
    variable = disp_y
    boundary = surface
    value = 0
  [../]
  [./bottom_stress]
    type = NeumannBC
    variable = disp_x
    boundary = lower_mantle
    value = 1
  [../]
  [./bottom_fix_y]
    type = DirichletBC
    variable = disp_y
    boundary = lower_mantle
    value = 0
  [../]
  [./surface_pres]
    type = DirichletBC
    variable = pressure
    boundary = surface
    value = 0
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 10000
  dt = 1e-5
  l_max_its = 100
  nl_max_its = 10
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    dt = 0.1
  [../]
[]

[Outputs]
  active = 'myconsole'
  output_initial = true
  exodus = true
  [./linear_iter]
    linear_residuals = true
    type = Console
  [../]
  [./myconsole]
    all_variable_norms = true
    type = Console
  [../]
[]

[ICs]
  [./ic_temp]
    variable = temp
    type = ConstantIC
    value = 0
  [../]
  [./ic_pres]
    variable = pressure
    type = ConstantIC
    value = 0
  [../]
[]

[TensorMechanics]
  active = ''
  [./tensor_mech]
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

