[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 20
  ny = 10
  xmin = -500
  xmax = 500
  ymin = -500
  ymax = 0
[]

[Variables]
  [./temp]
  [../]
  [./pore_pressure]
  [../]
[]

[Materials]
  [./redback_nomech]
    type = RedbackMaterial
    Aphi = 1
    are_convective_terms_on = true
    block = 0
    temperature = temp
    pore_pres = pore_pressure
    ar = 10
    ar_F = 1
    ar_R = 1
    eta1 = 1e3
    fluid_density = 1000
    fluid_thermal_expansion = 1e-6
    gr = 1
    gravity = '0 -9.81 0'
    mu = 1e-4
    phi0 = 0.1
    ref_lewis_nb = 1
    pressurization_coefficient = 1
    solid_compressibility = 0
    solid_density = 2500
    total_porosity = total_porosity
  [../]
[]

[Functions]
  [./init_gradient_T]
    type = ParsedFunction
    value = 293-y*(350-291)/(500-0)
  [../]
  [./init_gradient_P]
    # P_top-rho*g*y
    type = ParsedFunction
    value = 1e5-1000*9.81*y
  [../]
[]

[BCs]
  [./temperature_top]
    type = DirichletBC
    variable = temp
    boundary = top
    value = 0
  [../]
  [./temperature_bottom]
    type = DirichletBC
    variable = temp
    boundary = bottom
    value = 1
  [../]
  [./pore_pressure_top]
    type = DirichletBC
    variable = pore_pressure
    boundary = top
    value = 1
  [../]
[]

[AuxVariables]
  [./Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./total_porosity]
    family = MONOMIAL
  [../]
  [./Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./temp_td]
    type = TimeDerivative
    variable = temp
  [../]
  [./temp_diff]
    type = Diffusion
    variable = temp
  [../]
  [./temp_conv]
    type = RedbackThermalConvection
    variable = temp
  [../]
  [./press_td]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
  [./pres_conv]
    type = RedbackMassConvection
    variable = pore_pressure
    temperature = temp
  [../]
  [./press_thermPress]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temp
  [../]
[]

[AuxKernels]
  [./Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
  [../]
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = 0
    execute_on = linear
  [../]
  [./Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Postprocessors]
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0 -250 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0 -250 0'
  [../]
  [./middle_porosity]
    type = PointValue
    variable = total_porosity
    point = '0 -250 0'
  [../]
  [./dt]
    type = TimestepSize
  [../]
  [./num_li]
    type = NumLinearIterations
  [../]
  [./num_nli]
    type = NumNonlinearIterations
  [../]
[]

[Executioner]
  # [./TimeStepper]
  # type = ConstantDT
  # dt = 1e-1
  # [../]
  # [./TimeStepper]
  # type = PostprocessorDT
  # dt = 0.123
  # postprocessor = new_timestep
  # [../]
  start_time = 0.0
  end_time = 10000
  dtmax = 1
  dtmin = 1e-9
  type = Transient
  num_steps = 100000
  dt = 0.1
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart -snes_converged_reason'
  petsc_options_value = 'hypre boomeramg cp 201 1'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    # adapt_log = true
    type = SolutionTimeAdaptiveDT
    dt = 0.1
  [../]
[]

[Outputs]
  file_base = convection2D
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
    linear_residuals = true
  [../]
[]

[ICs]
  [./temp_IC]
    variable = temp
    type = FunctionIC
    function = init_gradient_T
  [../]
  [./press_IC]
    variable = pore_pressure
    type = FunctionIC
    function = init_gradient_P
  [../]
[]
