[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 4
  ny = 4
  ymin = -0.5
  ymax = 0
[]

[Variables]
  [./pore_pressure]
  [../]
[]

[Materials]
  [./redback_nomech]
    # output_properties = mixture_density
    type = RedbackMaterial
    Aphi = 1
    are_convective_terms_on = true
    block = 0
    pore_pres = pore_pressure
    ar = 10
    ar_F = 1
    ar_R = 1
    eta1 = 1e3
    fluid_thermal_expansion = 7e-05
    gr = 1
    gravity = '0 -1.96 0'
    phi0 = 0.3
    ref_lewis_nb = 2.72175308814e-07
    pressurization_coefficient = 0.951461538462
    solid_compressibility = 2e-10
    total_porosity = total_porosity
    Peclet_number = 1.0
    solid_thermal_expansion = 1e-06
    delta = 0.194539249147
    fluid_compressibility = 4e-10
  [../]
[]

[Functions]
  [./init_gradient_P]
    # P_top-rho*g*y
    type = ParsedFunction
    value = 0.02-1.96*y
  [../]
[]

[BCs]
  [./pore_pressure_top]
    type = DirichletBC
    variable = pore_pressure
    boundary = top
    value = 0.02
  [../]
[]

[AuxVariables]
  [./total_porosity]
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./press_td]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
[]

[AuxKernels]
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = 0
    execute_on = linear
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
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0.5 -0.25 0'
  [../]
  [./middle_porosity]
    type = PointValue
    variable = total_porosity
    point = '0.5 -0.25 0'
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
  start_time = 0.0
  end_time = 1e-3
  dtmax = 1
  dtmin = 1e-15
  type = Transient
  num_steps = 20
  dt = 0.1
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart -snes_converged_reason'
  petsc_options_value = 'hypre boomeramg cp 201 1'
  nl_abs_tol = 1e-8 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    type = ConstantDT
    dt = 1e-7
  [../]
[]

[Outputs]
  file_base = gravity_vertical
  output_initial = true
  exodus = true
  print_linear_residuals = true
  [./console]
    type = Console
    perf_log = true
  [../]
[]

