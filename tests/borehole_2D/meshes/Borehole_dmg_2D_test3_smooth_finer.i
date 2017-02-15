[Mesh]
  type = FileMesh
  file = Cylinder_hollow_perturb_fine_2D_smooth.msh
  boundary_name = 'bottom top inside outside'
  boundary_id = '109 110 112 111'
  displacements = 'disp_x disp_y'
[]

[GlobalParams]
  displacements = 'disp_x disp_y disp_z'
  porepressure = porepressure
  block = 0
[]

[Variables]
  active = 'temperature disp_y disp_x porepressure damage'
  [./disp_x]
    block = '0 1'
  [../]
  [./disp_y]
    block = '0 1'
  [../]
  [./disp_z]
    block = 0
  [../]
  [./porepressure]
    scaling = 1E9 # Notice the scaling, to make porepressure's kernels roughly of same magnitude as disp's kernels
    block = '0 1'
  [../]
  [./damage]
    block = '0 1'
  [../]
  [./temperature]
    block = '0 1'
  [../]
[]

[AuxVariables]
  [./strain_r_r]
    order = CONSTANT
    family = MONOMIAL
    block = '0 1'
  [../]
  [./strain_r_theta]
    order = CONSTANT
    family = MONOMIAL
    block = '0 1'
  [../]
[]

[Functions]
  [./temp_ic]
    type = ParsedFunction
    value = 'sqrt(x*x+y*y)/0.9 - 1/9' # -sqrt(x*x+y*y)/0.9 + 10/9
  [../]
  [./inner_pressure_fct]
    type = ParsedFunction
    value = 0.01+1000*t
  [../]
  [./inner_displacement]
    type = ParsedFunction
    value = 1e-4+10*t
  [../]
[]

[Kernels]
  [./dp_dt]
    type = TimeDerivative
    variable = porepressure
    block = '0 1'
  [../]
  [./mass_diff]
    type = RedbackMassDiffusion
    variable = porepressure
    block = '0 1'
  [../]
  [./poromech]
    type = RedbackPoromechanics
    variable = porepressure
    block = '0 1'
  [../]
  [./damage_dt]
    type = TimeDerivative
    variable = damage
    block = '0 1'
  [../]
  [./damage_kernel]
    type = RedbackDamage
    variable = damage
    block = '0 1'
  [../]
  [./dt_temp]
    type = TimeDerivative
    variable = temperature
    block = '0 1'
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temperature
    block = '0 1'
  [../]
  [./mech_dissip]
    type = RedbackMechDissip
    variable = temperature
    block = '0 1'
  [../]
  [./Thermal_press]
    type = RedbackThermalPressurization
    variable = porepressure
    temperature = temperature
    block = '0 1'
  [../]
[]

[AuxKernels]
  [./plastic_strain_r_r]
    type = RedbackPolarTensorMaterialAux
    variable = strain_r_r
    rank_two_tensor = plastic_strain
    index_j = 0
    index_i = 0
    block = '0 1'
  [../]
  [./strain_r_theta]
    type = RedbackPolarTensorMaterialAux
    variable = strain_r_theta
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 0
    block = '0 1'
  [../]
[]

[BCs]
  [./Pressure]
    [./myPressure]
      function = inner_displacement
      boundary = 1
      disp_y = disp_y
      disp_x = disp_x
    [../]
  [../]
  [./Temp_borehole]
    type = DirichletBC
    variable = temperature
    boundary = 1
    value = 0
  [../]
  [./Temp_outside]
    type = DirichletBC
    variable = temperature
    boundary = 0
    value = 1
  [../]
  [./fixed_outer_x]
    type = PresetBC
    variable = disp_x
    boundary = 0
    value = 0
  [../]
  [./fixed_outer_y]
    type = PresetBC
    variable = disp_y
    boundary = 0
    value = 0
  [../]
[]

[Materials]
  active = 'no_mech plastic_material'
  [./no_mech]
    type = RedbackMaterial
    block = '0 1'
    disp_y = disp_y
    disp_x = disp_y
    pore_pres = porepressure
    total_porosity = 0.1
    phi0 = 0.1
    pressurization_coefficient = 1e-7
    temperature = temperature
    gr = 10
    ar = 10
  [../]
  [./elastic_material]
    type = RedbackMechMaterialElastic
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    poisson_ratio = 0.25
    youngs_modulus = 100
    outputs = all
  [../]
  [./plastic_material]
    # 0 0.001 0.1 0.0008
    type = RedbackMechMaterialDP
    block = '0 1'
    disp_y = disp_y
    disp_x = disp_x
    outputs = all
    pore_pres = porepressure
    yield_stress = '0 0.001 0.1 0.0008' # 0 0.006 1 0.006
    poisson_ratio = 0.25
    youngs_modulus = 100
    damage = damage
    damage_coefficient = 1e4
    damage_method = BrittleDamage
    temperature = temperature
    exponent = 10
    slope_yield_surface = -0.6
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    # gmres asm 1E0 1E-10 200 500 lu NONZERO
    type = SMP
    full = true
    solve_type = NEWTON
    petsc_options = '-snes_monitor -snes_linesearch_monitor -ksp_monitor'
    petsc_options_iname = '-ksp_type -pc_type  -snes_atol -snes_rtol -snes_max_it -ksp_max_it -ksp_atol -sub_pc_type -sub_pc_factor_shift_type'
    petsc_options_value = 'gmres        asm        1E-2          1E-8        200                500                  1e-4        lu                      NONZERO'
    line_search = basic
  [../]
  [./manolis]
    type = SMP
    solve_type = NEWTON
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
  [../]
  [./default]
    type = SMP
    solve_type = NEWTON
  [../]
  [./Manman]
    type = SMP
    solve_type = NEWTON
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
  [../]
[]

[Executioner]
  # [./TimeStepper]
  # type = PostprocessorDT
  # postprocessor = dt
  # dt = 0.003
  # [../]
  type = Transient
  l_max_its = 100
  end_time = 0.3
  dt = 1e-6 # 1e-5
  l_tol = 1e-5 # 1e-05
[]

[Outputs]
  exodus = true
  execute_on = 'timestep_end initial'
  file_base = borehole_dmg_2D_test3_smooth
[]

[RedbackMechAction]
  [./mechanics]
    pore_pres = porepressure
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

[ICs]
  [./random_dmg_ic]
    variable = damage
    max = 0.01
    type = RandomIC
    block = '0 1'
  [../]
  [./random_temp_ic]
    function = temp_ic
    max = 0.1
    type = FunctionWithRandomIC
    variable = temperature
    block = '0 1'
  [../]
[]

