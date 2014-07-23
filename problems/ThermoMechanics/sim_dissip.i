[Mesh]
  type = FileMesh
  file = 2d_square_400elements_2corners_inclusion.msh
[]

[MeshModifiers]
  [./left_mid_point]
    type = AddExtraNodeset
    boundary = 4
    coord = '0.0 0.5'
  [../]
[]

[Variables]
  [./disp_x]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_y]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_z]
    order = FIRST
    family = LAGRANGE
  [../]
  [./temp]
  [../]
[]

[TensorMechanics]
  [./solid]
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    temp = temp
  [../]
[]

[Materials]
  [./mat0]
    type = FiniteStrainRatePlasticTemperatureMaterial
    block = 0
    exponent = 2
    disp_y = disp_y
    disp_x = disp_x
    heat_capacity = 1e5
    activation_energy = 50
    C_ijkl = '2.827e5 1.21e5 1.21e5 2.827e5 1.21e5 2.827e5 0.808e5 0.808e5 0.808e5'
    temperature = temp
    yield_stress = '0. 445. 0.05 480. 0.1 500'
    ref_pe_rate = 1e4
    disp_z = disp_z
  [../]
  [./mat1]
    type = FiniteStrainPlasticMaterial
    block = 1
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    yield_stress = '0. 445. 0.05 480. 0.1 500'
    C_ijkl = '2.827e5 1.21e5 1.21e5 2.827e5 1.21e5 2.827e5 0.808e5 0.808e5 0.808e5'
    temperature = temp
  [../]
[]

[Functions]
  [./upfunc]
    type = ParsedFunction
    value = t
  [../]
  [./downfunc]
    type = ParsedFunction
    value = -t
  [../]
[]

[BCs]
  active = 'right_disp left_disp temp_left_mid_pt'
  [./left_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 3
    function = downfunc
  [../]
  [./right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 1
    function = upfunc
  [../]
  [./bottom_temp]
    type = DirichletBC
    variable = temp
    boundary = 0
    value = 1
  [../]
  [./top_temp]
    type = DirichletBC
    variable = temp
    boundary = 2
    value = 1
  [../]
  [./temp_left_mid_pt]
    type = DirichletBC
    variable = temp
    boundary = 4
    value = 300
  [../]
[]

[AuxVariables]
  [./stress_zz]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./peeq]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./pe11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./pe22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./pe33]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./temp_td]
    type = TimeDerivative
    variable = temp
    block = '0 1'
  [../]
  [./temp_diff]
    type = AnisotropicDiffusion
    variable = temp
    block = '0 1'
    tensor_coeff = '1 0 0 0 1 0 0 0 1'
  [../]
  [./temp_dissip]
    type = MechDissip
    variable = temp
    block = 0
  [../]
[]

[AuxKernels]
  [./stress_zz]
    type = RankTwoAux
    rank_two_tensor = stress
    variable = stress_zz
    index_i = 2
    index_j = 2
  [../]
  [./pe11]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe11
    index_i = 0
    index_j = 0
  [../]
  [./pe22]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe22
    index_i = 1
    index_j = 1
  [../]
  [./pe33]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe33
    index_i = 2
    index_j = 2
  [../]
  [./eqv_plastic_strain]
    type = FiniteStrainPlasticAux
    variable = peeq
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  start_time = 0.0
  end_time = 1
  dt = 1e-4
  dtmax = 1
  dtmin = 1e-7
  type = Transient
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
[]

[Outputs]
  file_base = out
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
    linear_residuals = true
  [../]
[]

[ICs]
  [./ic_temp]
    variable = temp
    value = 300
    type = ConstantIC
    block = '0 1'
  [../]
[]

