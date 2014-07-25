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
    type = DimensionlessRock
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    C_ijkl = '1.346e+05 5.769e+04 5.769e+04 1.346e+05 5.769e+04 1.346e+05 3.846e+04 3.846e+04 3.846e+04'
    temperature = temp
    yield_stress = '0. 1 1. 1'
    disp_z = disp_z
    ar_c = 1
    m = 2
    da = 1
    mu = 1
    ar = 100
    delta = 1
    gr = 1e-50
  [../]
  [./mat1]
    type = DimensionlessRock
    block = 1
    disp_y = disp_y
    disp_x = disp_x
    C_ijkl = '1.346e+05 5.769e+04 5.769e+04 1.346e+05 5.769e+04 1.346e+05 3.846e+04 3.846e+04 3.846e+04'
    temperature = temp
    yield_stress = '0. 0.9 1 0.9'
    disp_z = disp_z
    ar_c = 1
    m = 2
    da = 1
    mu = 1
    ar = 100
    delta = 1
    gr = 1e-50
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
  active = 'temp_left_mid_pt right_disp left_disp'
  [./left_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 3
    function = upfunc
  [../]
  [./right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 1
    function = downfunc
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
  [./mises_stress]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  active = 'temp_diff temp_td temp_mht'
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
  [./temp_mht]
    type = MechHeatTensor
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
  [./mises_stress]
    type = MisesStressAux
    variable = mises_stress
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

