[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 1
  ny = 30
  xmax = 1
  zmax = 1
[]

[Variables]
  [Temperature]
  []
  [disp_x]
  []
  [disp_y]
  []
  [disp_z]
  []
  [pore_pressure]
  []
[]

[Functions]
  [top_bc]
    type = ParsedFunction
    value = '0.01*t'
  []
  [bottom_bc]
    type = ParsedFunction
    value = '-0.01*t'
  []
[]

[Kernels]
  inactive = 'press_thermPress press_poromech'
  [td_temp]
    type = TimeDerivative
    variable = Temperature
  []
  [td_press]
    type = TimeDerivative
    variable = pore_pressure
  []
  [temp_diff]
    type = Diffusion
    variable = Temperature
  []
  [press_diff]
    type = Diffusion
    variable = pore_pressure
  []
  [press_thermPress]
    type = RedbackThermalPressurization
    variable = disp_z
  []
  [temp_dissip]
    type = RedbackMechDissip
    variable = Temperature
  []
  [press_poromech]
    type = RedbackPoromechanics
    variable = pore_pressure
  []
[]

[BCs]
  [ux_top]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = 'top'
    function = top_bc
  []
  [ux_bottom]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = 'bottom'
    function = bottom_bc
  []
  [uy_top]
    type = DirichletBC
    variable = disp_y
    boundary = 'top'
    value = 0
  []
  [Periodic]
    [periodic_x]
      secondary = right
      primary = left
      auto_direction = 'x'
    []
  []
  [uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = 'bottom'
    value = 0
  []
  [uz_back]
    type = DirichletBC
    variable = disp_z
    boundary = 'back'
    value = 0
  []
  [temp_top_bottom]
    type = DirichletBC
    variable = Temperature
    boundary = 'top bottom'
    value = 0
  []
  [pp_top_bottom]
    type = DirichletBC
    variable = pore_pressure
    boundary = 'top bottom'
    value = 0
  []
[]

[Materials]
  inactive = 'mech_notch'
  [mech_material]
    type = RedbackMechMaterialJ2
    block = '0'
    disp_z = 'disp_z'
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    outputs = 'all'
    yield_stress = '0 1 0.1 1'
    C_ijkl = '5.77E2 3.85E2 0.0'
    fill_method = general_isotropic
    pore_pres = 'pore_pressure'
    temperature = 'Temperature'
  []
  [no_mech_material]
    type = RedbackMaterial
    pore_pres = 'pore_pressure'
    ar = 5.5 # it used to be 8 but we reduced it to get low T
    total_porosity = '0.1'
    is_mechanics_on = true
    temperature = 'Temperature'
  []
  [mech_notch]
    type = RedbackMechMaterialJ2
    poisson_ratio = '0.3'
    youngs_modulus = '99'
    block = '1'
    disp_z = 'disp_z'
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    outputs = 'all'
    yield_stress = '0 1 0.1 0.1'
    pore_pres = 'pore_pressure'
    temperature = 'Temperature'
  []
[]

[Postprocessors]
  [temp_middle_new]
    type = PointValue
    variable = Temperature
    point = '1 0.5 0.05'
  []
  [mid_temp]
    type = PointValue
    variable = Temperature
    point = '1 0.5 0'
  []
[]

[Preconditioning]
  [SMP]
    type = SMP
    full = true
    solve_type = PJFNK
    petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart'
    petsc_options_value = 'gmres asm lu 201'
  []
[]

[Executioner]
  type = Transient
  num_steps = 1000
  dt = 1e-6
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart '
  petsc_options_value = 'gmres asm lu 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  line_search = basic
  [TimeStepper]
    type = ConstantDT
    dt = 0.05 # 0.1
  []
[]

[Outputs]
  exodus = true
  file_base = simple_shear_elastoviscoplastic
  print_perf_log = true
[]

[RedbackMechAction]
  [my_action]
    disp_z = disp_z
    disp_x = disp_x
    disp_y = disp_y
    temp = Temperature
    pore_pres = pore_pressure
  []
[]
