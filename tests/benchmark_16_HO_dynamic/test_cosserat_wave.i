[Mesh]
  # when xmax>45 no convergence
  # nx=30, ny=2, nz=2
  type = GeneratedMesh
  dim = 3
  nx = 50
  ny = 5
  nz = 5
  xmax = 1000
  ymax = 100
  zmax = 100
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./wc_x]
  [../]
  [./wc_y]
  [../]
  [./wc_z]
  [../]
[]

[AuxVariables]
  [./vel_x]
  [../]
  [./vel_y]
  [../]
  [./vel_z]
  [../]
  [./accel_x]
  [../]
  [./accel_y]
  [../]
  [./accel_z]
  [../]
  [./vel_wc_x]
  [../]
  [./vel_wc_y]
  [../]
  [./vel_wc_z]
  [../]
  [./accel_wc_x]
  [../]
  [./accel_wc_y]
  [../]
  [./accel_wc_z]
  [../]
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
[]

[Functions]
  [./ramp]
    type = ParsedFunction
    value = -10*sin(6*t)
  [../]
[]

[Kernels]
  [./inertia_x]
    type = InertialForce
    variable = disp_x
    velocity = vel_x
    acceleration = accel_x
    beta = 0.25
    gamma = 0.5
  [../]
  [./inertia_y]
    type = InertialForce
    variable = disp_y
    velocity = vel_y
    acceleration = accel_y
    beta = 0.25
    gamma = 0.5
  [../]
  [./inertia_z]
    type = InertialForce
    variable = disp_z
    velocity = vel_z
    acceleration = accel_z
    beta = 0.25
    gamma = 0.5
  [../]
  [./inertia_wc_x]
    type = InertialForce
    variable = wc_x
    velocity = vel_wc_x
    acceleration = accel_wc_x
    beta = 0.25
    gamma = 0.5
  [../]
  [./inertia_wc_y]
    type = InertialForce
    variable = wc_y
    velocity = vel_wc_y
    acceleration = accel_wc_y
    beta = 0.25
    gamma = 0.5
  [../]
  [./inertia_wc_z]
    type = InertialForce
    variable = wc_z
    velocity = vel_wc_z
    acceleration = accel_wc_z
    beta = 0.25
    gamma = 0.5
  [../]
  [./cx_elastic]
    type = RedbackCosseratDynamicStressDivergenceTensors2
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
  [../]
  [./cy_elastic]
    type = RedbackCosseratDynamicStressDivergenceTensors2
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
  [../]
  [./cz_elastic]
    type = RedbackCosseratDynamicStressDivergenceTensors2
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
  [../]
  [./x_couple]
    type = RedbackCosseratDynamicStressDivergenceTensors2
    variable = wc_x
    displacements = 'wc_x wc_y wc_z'
    component = 0
    base_name = coupled
  [../]
  [./y_couple]
    type = RedbackCosseratDynamicStressDivergenceTensors2
    variable = wc_y
    displacements = 'wc_x wc_y wc_z'
    component = 1
    base_name = coupled
  [../]
  [./z_couple]
    type = DynamicStressDivergenceTensors
    variable = wc_z
    displacements = 'wc_x wc_y wc_z'
    component = 2
    base_name = coupled
  [../]
  [./x_moment]
    type = RedbackDynamicMomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = RedbackDynamicMomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = RedbackDynamicMomentBalancing
    variable = wc_z
    component = 2
  [../]
[]

[AuxKernels]
  [./accel_x]
    type = NewmarkAccelAux
    variable = accel_x
    displacement = disp_x
    velocity = vel_x
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_x]
    type = NewmarkVelAux
    variable = vel_x
    acceleration = accel_x
    gamma = 0.5
    execute_on = timestep_end
  [../]
  [./accel_y]
    type = NewmarkAccelAux
    variable = accel_y
    displacement = disp_y
    velocity = vel_y
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_y]
    type = NewmarkVelAux
    variable = vel_y
    acceleration = accel_y
    gamma = 0.5
    execute_on = timestep_end
  [../]
  [./accel_z]
    type = NewmarkAccelAux
    variable = accel_z
    displacement = disp_z
    velocity = vel_z
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_z]
    type = NewmarkVelAux
    variable = vel_z
    acceleration = accel_z
    gamma = 0.5
    execute_on = timestep_end
  [../]
  [./accel_wc_x]
    type = NewmarkAccelAux
    variable = accel_wc_x
    displacement = wc_x
    velocity = vel_wc_x
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_wc_x]
    type = NewmarkVelAux
    variable = vel_wc_x
    acceleration = accel_wc_x
    gamma = 0.5
    execute_on = timestep_end
  [../]
  [./accel_wc_y]
    type = NewmarkAccelAux
    variable = accel_wc_y
    displacement = wc_y
    velocity = vel_wc_y
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_wc_y]
    type = NewmarkVelAux
    variable = vel_wc_y
    acceleration = accel_wc_y
    gamma = 0.5
    execute_on = timestep_end
  [../]
  [./accel_wc_z]
    type = NewmarkAccelAux
    variable = accel_wc_z
    displacement = wc_z
    velocity = vel_wc_z
    beta = 0.25
    execute_on = timestep_end
  [../]
  [./vel_wc_z]
    type = NewmarkVelAux
    variable = vel_wc_z
    acceleration = accel_wc_z
    gamma = 0.5
    execute_on = timestep_end
  [../]
[]

[BCs]
  [./hold_ux]
    type = DirichletBC
    variable = disp_x
    boundary = left
    value = 0
  [../]
  [./hold_uy]
    type = DirichletBC
    variable = disp_y
    boundary = left
    value = 0
  [../]
  [./hold_uz]
    type = DirichletBC
    variable = disp_z
    boundary = left
    value = 0
  [../]
  [./load]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = right
    function = ramp
  [../]
[]

[Materials]
  [./cosserat]
    # B_ijkl 0.5
    # C_ijkl 1 2 1.3333
    type = RedbackMechMaterialHO
    block = 0
    B_ijkl = '0 5 5'
    C_ijkl = '0 2 1'
    fill_method = general_isotropic
    friction_coefficient = 0.5
    poisson_ratio = 999999
    youngs_modulus = 9999999
  [../]
  [./density]
    type = GenericConstantMaterial
    block = 0
    prop_names = density
    prop_values = 8E-6
  [../]
  [./microinertia]
    type = GenericConstantMaterial
    block = 0
    prop_names = microinertia
    prop_values = 1
  [../]
  [./redbackmat]
    type = RedbackMaterial
  [../]
[]

[Preconditioning]
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres bjacobi 1E-8              1E-7                    50             1E-15             1E-10'
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  dt = 0.02
  solve_type = Newton
  num_steps = 100
[]

[Outputs]
  execute_on = 'initial timestep_end'
  exodus = true
  print_linear_residuals = false
  file_base = test_cosserat_wave
[]

