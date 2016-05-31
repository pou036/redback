[Mesh]
  type = FileMesh
  file = Cylinder_hollow_3D_quarter.msh
  boundary_name = 'bottom top inside outside left right'
  boundary_id = '0 1 2 3 4 5'
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
[]

[Variables]
  active = 'disp_y disp_x porepressure wc_z wc_y wc_x disp_z'
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./porepressure]
    scaling = 1E9 # Notice the scaling, to make porepressure's kernels roughly of same magnitude as disp's kernels
  [../]
  [./damage]
  [../]
  [./temperature]
    block = '0 1'
  [../]
  [./wc_x]
  [../]
  [./wc_y]
  [../]
  [./wc_z]
  [../]
[]

[AuxVariables]
  [./strain_r_r]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_r_theta]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_theta_theta]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_r_r]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_r_theta]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_theta_theta]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mech_dissip]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  active = 'timestep_function inner_pressure_fct outer_pressure_fct'
  [./temp_ic]
    type = ParsedFunction
    value = 'sqrt(x*x+y*y)/0.9 - 1/9' # -sqrt(x*x+y*y)/0.9 + 10/9
  [../]
  [./inner_pressure_fct]
    # 1e-2
    type = ParsedFunction
    value = 1e-3+2e-2*t # 1e-3+4e-2*t
  [../]
  [./timestep_function]
    # if(t>0.0225, 5e-5, 5e-4)
    # 1e-3
    # 
    # if (t<0.13,1e-3,  dt*max(0.2, 1-0.1*(n-30)))
    # 
    # if(t>0.03, 5e-5, 5e-4)
    # 
    type = ParsedFunction
    value = 'if(t>0.06, 1e-4, 1e-3)' # if(t>0.0169, 1e-7, if(t>0.0168, 2e-6,1e-4))
    vals = 'nnli old_timestep'
    vars = 'n dt'
  [../]
  [./outer_pressure_fct]
    type = ParsedFunction
    value = 1e-3 # 1e-3
  [../]
[]

[Kernels]
  active = 'y_moment cz_elastic cy_elastic cx_elastic z_couple x_couple x_moment y_couple z_moment dp_dt mass_diff'
  [./dp_dt]
    type = TimeDerivative
    variable = porepressure
  [../]
  [./mass_diff]
    type = RedbackMassDiffusion
    variable = porepressure
  [../]
  [./poromech]
    type = RedbackPoromechanics
    variable = porepressure
    block = '0 1'
  [../]
  [./damage_dt]
    type = TimeDerivative
    variable = damage
  [../]
  [./damage_kernel]
    type = RedbackDamage
    variable = damage
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
    block = '0 1'
  [../]
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
    pore_pres = porepressure
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
    pore_pres = porepressure
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
    pore_pres = porepressure
  [../]
  [./x_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_x
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    component = 0
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./y_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_y
    component = 1
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./z_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_z
    component = 2
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./x_moment]
    type = RedbackMomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = RedbackMomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = RedbackMomentBalancing
    variable = wc_z
    component = 2
  [../]
[]

[AuxKernels]
  [./plastic_strain_r_r]
    type = RedbackPolarTensorMaterialAux
    variable = strain_r_r
    rank_two_tensor = plastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./strain_r_theta]
    type = RedbackPolarTensorMaterialAux
    variable = strain_r_theta
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 0
  [../]
  [./strain_theta_theta]
    type = RedbackPolarTensorMaterialAux
    variable = strain_theta_theta
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./stress_r_r]
    type = RedbackPolarTensorMaterialAux
    variable = stress_r_r
    rank_two_tensor = stress
    index_j = 0
    index_i = 0
  [../]
  [./stress_r_theta]
    type = RedbackPolarTensorMaterialAux
    variable = stress_r_theta
    rank_two_tensor = stress
    index_j = 1
    index_i = 0
  [../]
  [./stress_theta_theta]
    type = RedbackPolarTensorMaterialAux
    variable = stress_theta_theta
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  [../]
  [./dissip]
    type = MaterialRealAux
    variable = mech_dissip
    property = mechanical_dissipation_mech
    execute_on = timestep_end
  [../]
[]

[BCs]
  active = 'Pressure fixed_outer_x fixed_outer_y wcz_left_right'
  [./Pressure]
    [./press_inner]
      function = inner_pressure_fct
      boundary = 2
    [../]
    [./press_outer]
      function = outer_pressure_fct
      boundary = 3
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
    boundary = 4
    value = 0
  [../]
  [./fixed_outer_y]
    type = PresetBC
    variable = disp_y
    boundary = 5
    value = 0
  [../]
  [./confine_x]
    type = PresetBC
    variable = disp_x
    boundary = '101 102'
    value = 0
  [../]
  [./confine_y]
    type = PresetBC
    variable = disp_y
    boundary = '103 104'
    value = 0
  [../]
  [./wcz_left_right]
    type = DirichletBC
    variable = wc_z
    boundary = '4 5'
    value = 0
  [../]
[]

[Materials]
  active = 'no_mech Redbackcosserat'
  [./no_mech]
    type = RedbackMaterial
    disp_y = disp_y
    disp_x = disp_y
    pore_pres = porepressure
    total_porosity = 0.1
    phi0 = 0.1
    pressurization_coefficient = 1e-7
    gr = 1000
    ar = 10
    solid_compressibility = 1000
    is_mechanics_on = true
  [../]
  [./elastic_material]
    type = RedbackMechMaterialElastic
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    poisson_ratio = 0.25
    youngs_modulus = 100
    outputs = none
  [../]
  [./plastic_material]
    # 0 0.001 0.1 0.0008
    type = RedbackMechMaterialDP
    disp_y = disp_y
    disp_x = disp_x
    outputs = none
    pore_pres = porepressure
    yield_stress = '0 0.006 1 0.0054' # 0 0.006 1 0.006
    poisson_ratio = 0.25
    youngs_modulus = 100
    damage = damage
    damage_coefficient = 6e2 # 3e3
    damage_method = BrittleDamage
    exponent = 10
  [../]
  [./Redbackcosserat]
    type = RedbackMechMaterialHO
    block = 0
    B_ijkl = '0.0 9.6616E-2  9.6616E-2'
    C_ijkl = '1.8634E1 4.3478E1 2.1739E1'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.001
    hardening_mech_modulus = -0.1
    pore_pres = porepressure
    plasticity_type = DruckerPrager_friction3D
    friction_coefficient = 0.3
  [../]
[]

[Postprocessors]
  active = 'Num_elements disp_hole_x avg_dissip nnli max_r_theta new_timestep nli disp_hole_y old_timestep'
  [./max_temp]
    type = NodalMaxValue
    variable = temperature
  [../]
  [./new_timestep]
    type = FunctionValuePostprocessor
    function = timestep_function
  [../]
  [./max_temp_old]
    type = NodalMaxValue
    variable = temperature
    execute_on = timestep_begin
  [../]
  [./old_timestep]
    type = TimestepSize
    execute_on = timestep_begin
  [../]
  [./max_r_theta]
    type = ElementExtremeValue
    variable = strain_r_theta
  [../]
  [./nli]
    type = NumLinearIterations
  [../]
  [./nnli]
    type = NumNonlinearIterations
  [../]
  [./avg_dissip]
    type = ElementAverageValue
    variable = mech_dissip
    block = 0
  [../]
  [./Num_elements]
    type = NumElems
  [../]
  [./disp_hole_x]
    type = PointValue
    variable = disp_x
    point = '0.1 0 0'
  [../]
  [./disp_hole_y]
    type = PointValue
    variable = disp_y
    point = '0 0.1 0'
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
    petsc_options_value = 'gmres        asm        1E-10          1E-5        200                500                  1e-8        lu                      NONZERO'
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
  end_time = 100 # 0.5
  dt = 1e-3 # 1e-5
  l_tol = 1e-5 # 1e-05
  [./TimeStepper]
    type = PostprocessorDT
    postprocessor = new_timestep
  [../]
[]

[Outputs]
  exodus = true
  execute_on = 'timestep_end initial'
  file_base = Cylinder_thin_quarter_perturb8
  interval = 10
[]

[ICs]
  [./random_variable]
    max = 1e-7
    variable = wc_z
    boundary = 2
    type = RandomIC
    block = 0
  [../]
[]

