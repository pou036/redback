# Testing damage functionality from Karrech et al 2011

[Mesh]
  type = GeneratedMesh
  dim = 2
  xmax = 2
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./damage]
  [../]
[]

[GlobalParams]
  time_factor = 1
[]

[Materials]
  [./mat_mech]
    type = RedbackMechMaterialDP
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    youngs_modulus = 100
    poisson_ratio = 0.2
    yield_stress = '0 1 0 1'
    total_porosity = 0.1
    damage = damage
    damage_method = Karrech2011Damage
    outputs = all
  [../]
  [./mat_nomech]
    type = RedbackMaterial
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    phi0 = 0.1
    total_porosity = 0.1
    is_mechanics_on = true
  [../]
[]

[BCs]
  active = 'confine_x confine_y vel_x_right'
  [./confine_x]
    type = PresetBC
    variable = disp_x
    boundary = left
    value = 0
  [../]
  [./confine_y]
    type = PresetBC
    variable = disp_y
    value = 0
    boundary = bottom
  [../]
  [./vel_x_right]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = right
    function = vel_right_fct
  [../]
  [./D_top]
    type = DirichletBC
    variable = damage
    boundary = top
    value = 0
  [../]
[]

[Functions]
  active = 'vel_right_fct'
  [./applied_load_fct]
    type = ParsedFunction
    value = 10*tanh(1e3*t)
  [../]
  [./vel_right_fct]
    type = ParsedFunction
    value = 2e-1*t
  [../]
[]

[Kernels]
  [./td_damage]
    type = TimeDerivative
    variable = damage
  [../]
  [./damage_kernel]
    type = RedbackDamage
    variable = damage
  [../]
[]

[Preconditioning]
  active = 'SMP2'
  [./SMP]
    # petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    # petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
    # 
    petsc_options = '-snes_monitor -snes_linesearch_monitor -ksp_monitor'
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it' # -ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_max_it -sub_pc_type -sub_pc_factor_shift_type
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000' # gmres asm 1E0 1E-6 200 500 lu NONZERO
    type = SMP
    full = true
  [../]
  [./SMP2]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 25
  solve_type = PJFNK
  end_time = 9999999999
  dt = 1e-2
  petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart'
  petsc_options_value = 'gmres asm lu 201'
  nl_abs_tol = 1e-10
  nl_rel_step_tol = 1e-10
  nl_rel_tol = 1e-06
  nl_abs_step_tol = 1e-10
[]

[Outputs]
  exodus = true
  file_base = Karrech2011
[]

[RedbackMechAction]
  [./solid]
    disp_x = disp_x
    disp_y = disp_y
  [../]
[]

