# This input file tests the behavior of NS equations

[GlobalParams]
  fluid_vel_x = vel_x
  fluid_vel_y = vel_y
  fluid_vel_z = vel_z
[]

[Mesh]
  type = GeneratedMesh
  dim = 3
  uniform_refine = 1
  block_name = pore
  block_id = 0
  elem_type = HEX20
[]

[Variables]
  [./vel_x]
    order = SECOND
    [./InitialCondition]
      type = ConstantIC
      value = 0.0
    [../]
  [../]
  [./vel_y]
    order = SECOND
    [./InitialCondition]
      type = ConstantIC
      value = 0.0
    [../]
  [../]
  [./p]
    [./InitialCondition]
      type = ConstantIC
      value = 0 # This number is arbitrary for NS...
    [../]
  [../]
  [./vel_z]
    order = SECOND
  [../]
[]

[Kernels]
  active = 'stress_div_y stress_div_x stress_div_z navier_x navier_y navier_z mass_fluid_divergence'
  [./mass_fluid_divergence]
    type = RedbackFluidDivergence
    variable = p
  [../]
  [./stress_div_x]
    type = RedbackFluidStressDivergenceTensors
    variable = vel_x
    component = 0
    pore_pres = p
  [../]
  [./stress_div_y]
    type = RedbackFluidStressDivergenceTensors
    variable = vel_y
    component = 1
    pore_pres = p
  [../]
  [./stress_div_z]
    type = RedbackFluidStressDivergenceTensors
    variable = vel_z
    component = 2
    pore_pres = p
  [../]
  [./dt_v_x]
    type = TimeDerivative
    variable = vel_x
  [../]
  [./dt_v_y]
    type = TimeDerivative
    variable = vel_y
  [../]
  [./dt_v_z]
    type = TimeDerivative
    variable = vel_z
  [../]
  [./dt_p]
    type = TimeDerivative
    variable = p
  [../]
  [./navier_x]
    type = RedbackNavier
    variable = vel_x
    component = 0
  [../]
  [./navier_y]
    type = RedbackNavier
    variable = vel_y
    component = 1
  [../]
  [./navier_z]
    type = RedbackNavier
    variable = vel_z
    component = 2
  [../]
[]

[BCs]
  [./x_no_slip]
    type = DirichletBC
    variable = vel_x
    boundary = 'top bottom left right'
    value = 0.0
  [../]
  [./y_no_slip]
    type = DirichletBC
    variable = vel_y
    boundary = 'top bottom left right'
    value = 0.0
  [../]
  [./z_no_slip]
    type = DirichletBC
    variable = vel_z
    boundary = 'top bottom left right'
    value = 0
  [../]
  [./lowp]
    type = DirichletBC
    variable = p
    boundary = back
    value = 0
  [../]
  [./inlet]
    type = DirichletBC
    variable = p
    boundary = front
    value = 1
  [../]
[]

[Materials]
  [./fluid]
    type = RedbackFluidMaterial
    block = pore
    pore_pres = p
  [../]
[]

[Preconditioning]
  [./SMP_PJFNK]
    # Preconditioned JFNK (default)
    type = SMP
    full = true
    solve_type = PJFNK
  [../]
[]

[Executioner]
  # type = Steady
  type = Steady
  petsc_options_iname = '-ksp_gmres_restart '
  petsc_options_value = '300                '
  line_search = none
  nl_rel_tol = 1e-6
  nl_max_its = 6
  l_tol = 1e-8
  l_max_its = 50
  nl_abs_tol = 1e-10
  nl_rel_step_tol = 1e-10
  nl_abs_step_tol = 1e-10
  [./TimeStepper]
    type = ConstantDT
    dt = 0.1
  [../]
[]

[Outputs]
  file_base = NSRedback_test
  csv = true
  exodus = true
[]

