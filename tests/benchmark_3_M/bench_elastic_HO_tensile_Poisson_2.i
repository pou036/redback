[Mesh]
  type = GeneratedMesh
  dim = 3
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
[]

[Postprocessors]
  active = 'Rotation_wcz_0_7 Rotation_wcz_0_6 Rotation_wcz_0_5 Rotation_wcz_0_4 Rotation_wcz_0_3 Rotation_wcz_0_2 Rotation_wcz_0_1 Rotation_wcz_0_9 Rotation_wcz_0_8 Displ_u_x_0_8 Displ_u_x_0_9 Displ_u_x_0_1 Displ_u_x_0_2 Displ_u_x_0_3 Displ_u_x_0_4 Displ_u_x_0_5 Displ_u_x_0_6 Displ_u_x_0_7 disp_y_top disp_x_top wc_z_top'
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
  [./epsilon_33]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./total_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_L2]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./ramp]
    type = ParsedFunction
    value = t
  [../]
[]

[Kernels]
  [./cx_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
  [../]
  [./cy_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
  [../]
  [./cz_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
  [../]
  [./x_couple]
    type = StressDivergenceTensors
    variable = wc_x
    displacements = 'wc_x wc_y wc_z'
    component = 0
    base_name = coupled
  [../]
  [./y_couple]
    type = StressDivergenceTensors
    variable = wc_y
    component = 1
    displacements = 'wc_x wc_y wc_z'
    base_name = coupled
  [../]
  [./z_couple]
    type = StressDivergenceTensors
    variable = wc_z
    component = 2
    displacements = 'wc_x wc_y wc_z'
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
[]

[AuxKernels]
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
  [./epsilon_33]
    type = RankTwoAux
    variable = epsilon_33
    rank_two_tensor = elastic_strain
    index_j = 2
    index_i = 2
  [../]
  [./plastic_22]
    type = RankTwoAux
    variable = plastic_22
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./total_22]
    type = RankTwoAux
    variable = total_22
    rank_two_tensor = total_strain
    index_j = 1
    index_i = 1
  [../]
  [./stress_L2]
    type = MaterialRealAux
    variable = stress_L2
    property = stress_invariant
  [../]
[]

[BCs]
  # following is natural BC
  active = 'uy_bottom u_z_face wcx_equals_zero_on_top wcy_equals_zero_on_top uy_ramp_top wc_x_bottom wc_z_bottom_zero wc_y_bottom u_x_right'
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
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 0
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
    value = -0.1
  [../]
  [./ux_imposed_top]
    type = DirichletBC
    variable = disp_x
    boundary = top
    value = 0.01
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
  [./uy_ramp_top]
    type = FunctionDirichletBC
    variable = disp_y
    boundary = top
    function = ramp
  [../]
  [./u_x_right]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
  [./u_z_face]
    type = DirichletBC
    variable = disp_z
    boundary = front
    value = 0
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
    B_ijkl = '-0.0333333 0.05 0.05'
    C_ijkl = '0.75 0.375 0.1875'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.28867513459
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
  [../]
[]

[Preconditioning]
  [./andy]
    # gmres bjacobi 1E-10 1E-10 10 1E-15 1E-10
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres bjacobi 1E-10 1E-10 50 1E-15 1E-10'
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  solve_type = Newton
  num_steps = 2
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = bench_elastic_HO_tensile_shear
[]

