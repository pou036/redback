[Mesh]
  type = FileMesh
  file = ../second/cascadia_simple2.e
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
    block = subduction_zone
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    yield_stress = '0. 445. 0.05 480. 0.1 500'
    C_ijkl = '2.827e5 1.21e5 1.21e5 2.827e5 1.21e5 2.827e5 0.808e5 0.808e5 0.808e5'
    temperature = temp
    exponent = 2
    heat_capacity = 1
    activation_energy = 1e4
    ref_pe_rate = 100
  [../]
  [./mat1]
    type = FiniteStrainRatePlasticTemperatureMaterial
    block = 'crust mantle'
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    yield_stress = '0. 400. 0.05 400. 0.1 400'
    C_ijkl = '2.827e4 1.21e4 1.21e4 2.827e4 1.21e4 2.827e4 0.808e4 0.808e4 0.808e4'
    temperature = temp
    exponent = 2
    heat_capacity = 1
    activation_energy = 1e4
    ref_pe_rate = 100
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
  active = 'isotherm right_disp left_disp'
  [./left_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 4
    function = upfunc
  [../]
  [./right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 2
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
  [./isotherm]
    type = DirichletBC
    variable = temp
    boundary = '1 3'
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
    block = '1 2 3'
  [../]
  [./temp_diff]
    type = AnisotropicDiffusion
    variable = temp
    block = '1 2 3'
    tensor_coeff = '1e-6 0 0 0 1e-6 0 0 0 1e-6'
  [../]
  [./temp_dissip]
    type = MechDissip
    variable = temp
    block = 2
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
    block = '1 2 3'
  [../]
[]

