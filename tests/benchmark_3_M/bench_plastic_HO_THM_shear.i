[Mesh]
  type = FileMesh
  file = 3D_shear.msh
  boundary_name = 'back bottom right top left front'
  boundary_id = '0 1 2 3 4 5'
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
  pore_pres = pressure
  temperature = temperature
  temp = temperature
[]

[Postprocessors]
  [./disp_y_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = disp_y
  [../]
  [./disp_x_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = disp_x
  [../]
  [./wc_z_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = wc_z
  [../]
  [./antisymmetric_pp]
    type = SideAverageValue
    variable = antisymmetric_strain_bc
    boundary = bottom
    execute_on = linear
  [../]
  [./Rotation_wcz_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 0.5'
  [../]
  [./Rotation_wcz_0_8]
    type = PointValue
    variable = wc_z
    point = '0.5 0.8 0.5'
  [../]
  [./Rotation_wcz_0_7]
    type = PointValue
    variable = wc_z
    point = '0.5 0.7 0.5'
  [../]
  [./Rotation_wcz_0_6]
    type = PointValue
    variable = wc_z
    point = '0.5 0.6 0.5'
  [../]
  [./Rotation_wcz_0_5]
    type = PointValue
    variable = wc_z
    point = '0.5 0.5 0.5'
  [../]
  [./Rotation_wcz_0_4]
    type = PointValue
    variable = wc_z
    point = '0.5 0.4 0.5'
  [../]
  [./Rotation_wcz_0_3]
    type = PointValue
    variable = wc_z
    point = '0.5 0.3 0.5'
  [../]
  [./Rotation_wcz_0_2]
    type = PointValue
    variable = wc_z
    point = '0.5 0.2 0.5'
  [../]
  [./Rotation_wcz_0_1]
    type = PointValue
    variable = wc_z
    point = '0.5 0.1 0.5'
  [../]
  [./Displ_u_x_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 0.5'
  [../]
  [./Displ_u_x_0_8]
    type = PointValue
    variable = disp_x
    point = '0.5 0.8 0.5'
  [../]
  [./Displ_u_x_0_7]
    type = PointValue
    variable = disp_x
    point = '0.5 0.7 0.5'
  [../]
  [./Displ_u_x_0_6]
    type = PointValue
    variable = disp_x
    point = '0.5 0.6 0.5'
  [../]
  [./Displ_u_x_0_5]
    type = PointValue
    variable = disp_x
    point = '0.5 0.5 0.5'
  [../]
  [./Displ_u_x_0_4]
    type = PointValue
    variable = disp_x
    point = '0.5 0.4 0.5'
  [../]
  [./Displ_u_x_0_3]
    type = PointValue
    variable = disp_x
    point = '0.5 0.3 0.5'
  [../]
  [./Displ_u_x_0_2]
    type = PointValue
    variable = disp_x
    point = '0.5 0.2 0.5'
  [../]
  [./Displ_u_x_0_1]
    type = PointValue
    variable = disp_x
    point = '0.5 0.1 0.5'
  [../]
  [./antisymmetric_2]
    type = SideAverageValue
    variable = antisymmetric_strain_tc
    execute_on = linear
    boundary = top
  [../]
  [./nb_nli]
    type = NumNonlinearIterations
  [../]
  [./nb_li]
    type = NumLinearIterations
  [../]
  [./centre_T]
    type = PointValue
    variable = temperature
    point = '0 0.5 0'
  [../]
  [./centre_T_old]
    type = PointValue
    variable = temperature
    execute_on = timestep_begin
    point = '0 0.5 0'
  [../]
  [./centre_P]
    type = PointValue
    variable = pressure
    point = '0 0.5 0'
  [../]
  [./dt]
    type = TimestepSize
  [../]
  [./new_timestep]
    type = FunctionValuePostprocessor
    function = timestep_function
  [../]
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
  [./temperature]
  [../]
  [./pressure]
  [../]
[]

[AuxVariables]
  [./antisymmetric_strain_bc]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./epsilon_22]
    family = MONOMIAL
  [../]
  [./epsilon_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_strain]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_invariant]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./total_porosity]
    family = MONOMIAL
  [../]
  [./mechanical_porosity]
    family = MONOMIAL
  [../]
  [./antisymmetric_strain_tc]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./ramp_top]
    type = ParsedFunction
    value = 0.1*t
  [../]
  [./ramp_bottom]
    type = ParsedFunction
    value = -0.1*t
  [../]
  [./timestep_function]
    # if((t>252)&(t<251),0.1 ,999))
    # 
    # max(dt_min,  min(dt_max, dt*(  min(   1-0.1*(nnli-14),  1-5*((T-T_old)-0.2)   )   )))
    type = ParsedFunction
    value = 0.005
    vals = 'nb_li nb_nli dt centre_T_old centre_T 1e-5 1e-2'
    vars = 'nli nnli dt T_old T dt_min dt_max'
  [../]
[]

[Kernels]
  active = 'thermal_press T_diff mech_dissip x_couple cz_elastic cy_elastic cx_elastic poromech diff_p y_moment z_couple dT_dt x_moment y_couple z_moment dp_dt'
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
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
  [../]
  [./x_moment]
    type = MomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = MomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = MomentBalancing
    variable = wc_z
    component = 2
  [../]
  [./dT_dt]
    type = TimeDerivative
    variable = temperature
  [../]
  [./T_diff]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
  [./mech_dissip]
    type = RedbackMechDissip
    variable = temperature
  [../]
  [./dp_dt]
    type = TimeDerivative
    variable = pressure
  [../]
  [./diff_p]
    type = RedbackMassDiffusion
    variable = pressure
  [../]
  [./poromech]
    type = RedbackPoromechanics
    variable = pressure
  [../]
  [./thermal_press]
    type = RedbackThermalPressurization
    variable = pressure
    temperature = temperature
  [../]
  [./chem_press]
    type = RedbackChemPressure
    variable = pressure
  [../]
  [./chem_endo]
    type = RedbackChemEndo
    variable = temperature
  [../]
[]

[AuxKernels]
  [./antisymmetric_strain_xy]
    type = RankTwoAux
    variable = antisymmetric_strain_bc
    rank_two_tensor = macro_rotation
    index_j = 1
    index_i = 0
    execute_on = linear
  [../]
  [./stress_22]
    type = RankTwoAux
    variable = stress_22
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  [../]
  [./epsilon_22]
    type = RankTwoAux
    variable = epsilon_22
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./epsilon_11]
    type = RankTwoAux
    variable = epsilon_11
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./plastic_strain]
    type = MaterialRealAux
    variable = plastic_strain
    property = eqv_plastic_strain
  [../]
  [./stress_invariant]
    type = MaterialRealAux
    variable = stress_invariant
    property = stress_invariant
  [../]
  [./mech_porosity]
    type = MaterialRealAux
    variable = mechanical_porosity
    execute_on = timestep_end
    property = mechanical_porosity
  [../]
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = mechanical_porosity
    execute_on = timestep_end
    is_mechanics_on = true
  [../]
  [./antisymmetric_top]
    type = RankTwoAux
    variable = antisymmetric_strain_tc
    rank_two_tensor = macro_rotation
    index_j = 1
    index_i = 0
  [../]
[]

[BCs]
  # following is natural BC
  active = 'Periodic uy_bottom ux_imposed_top wcx_equals_zero_on_top ux_zero_bottom T_bottom wcy_equals_zero_on_top wc_x_bottom uz_bottom wc_y_bottom T_top'
  [./Periodic]
    [./xperiodic]
      auto_direction = x
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
    [../]
    [./zperiodic]
      auto_direction = z
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
    [../]
    [./wcz_periodic]
      variable = wc_z
      auto_direction = y
    [../]
  [../]
  [./wcx_equals_zero_on_top]
    type = DirichletBC
    variable = wc_x
    boundary = top
    value = 0
  [../]
  [./wcy_equals_zero_on_top]
    type = DirichletBC
    variable = wc_y
    boundary = top
    value = 0
  [../]
  [./uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0.0
  [../]
  [./uz_bottom]
    type = DirichletBC
    variable = disp_z
    boundary = bottom
    value = 0.0
  [../]
  [./wc_x_bottom]
    type = DirichletBC
    variable = wc_x
    boundary = bottom
    value = 0.0
  [../]
  [./wc_y_bottom]
    type = DirichletBC
    variable = wc_y
    boundary = bottom
    value = 0.0
  [../]
  [./ux_zero_bottom]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = bottom
    function = ramp_bottom
  [../]
  [./wc_z_rotationBC]
    type = RedbackRotationBC
    variable = wc_z
    boundary = bottom
    dir1 = 1
    antisymmetric_strain_ij = antisymmetric_strain_ij
    some_var_1 = disp_x
    some_var_2 = disp_y
    grad_ux = _grad_ux
  [../]
  [./dux_top]
    type = NeumannBC
    variable = disp_z
    boundary = top
  [../]
  [./wcz_imposed_top]
    type = DirichletBC
    variable = wc_z
    boundary = top
    value = 0.0
  [../]
  [./ux_imposed_top]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = top
    function = ramp_top
  [../]
  [./wc_z_bottom_zero]
    type = DirichletBC
    variable = wc_z
    boundary = bottom
    value = 0
  [../]
  [./Rotation_wc_z_BC]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = bottom
    postprocessor = antisymmetric_pp
  [../]
  [./T_bottom]
    type = DirichletBC
    variable = temperature
    boundary = bottom
    value = 0
  [../]
  [./T_top]
    type = DirichletBC
    variable = temperature
    boundary = top
    value = 0
  [../]
  [./Rotation_wc_z_TC]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = top
    postprocessor = antisymmetric_2
  [../]
  [./delta_T_centre]
    type = PointValue
    variable = delta_temp
    point = '0 0.5 0'
  [../]
[]

[Materials]
  active = 'Redbackcosserat redback_mat'
  [./cosserat]
    type = CosseratLinearElasticMaterial
    block = 0
    B_ijkl = 40
    C_ijkl = '5 10 5'
    fill_method = general_isotropic
  [../]
  [./Redbackcosserat]
    type = RedbackMechMaterialHO
    block = 0
    B_ijkl = '0.0 0.5 0.5'
    C_ijkl = '33.333333 100 200'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.1
    total_porosity = total_porosity
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
    solid_thermal_expansion = 1e-1
    pressurization_coefficient = 1e-3
    Kc = 1
    is_chemistry_on = true
    ar_F = 2
    mu = 1e-3
    ar_R = 1
    ar = 1
    da_exo = 1
    phi0 = 0.1
    total_porosity = total_porosity
    is_mechanics_on = true
    Aphi = 1
    eta2 = 1e-3
  [../]
[]

[Preconditioning]
  [./andy]
    # gmres bjacobi 1E-10 1E-10 10 1E-15 1E-10
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres bjacobi 1E-10 1E-8 50 1E-10 1E-8'
  [../]
[]

[Executioner]
  type = Transient
  dt = 0.01
  l_max_its = 100
  solve_type = Newton
  num_steps = 2000
  [./TimeStepper]
    type = PostprocessorDT
    dt = 0.01
    postprocessor = new_timestep
  [../]
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = bench_plastic_HO_shear_THM
  print_linear_residuals = false
[]

