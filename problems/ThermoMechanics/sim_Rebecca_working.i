
[Mesh]
  type = FileMesh
  file = benchmark100x100.msh
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
[]

[TensorMechanics]
  [./solid]
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
  [../]
[]

[Materials]
  [./felastic0]
    type = FiniteStrainRatePlasticMaterial
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    C_ijkl = '2.827e5 1.21e5 1.21e5 2.827e5 1.21e5 2.827e5 0.808e5 0.808e5 0.808e5'
    yield_stress = '0. 445. 0.05 440. 0.1 435. 0.38 430. 0.95 425. 2. 400.'
    exponent = 2
    ref_pe_rate = 1e8
  [../]
  [./felastic1]
    type = FiniteStrainPlasticMaterial
    block = 1
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    C_ijkl = '2.827e4 1.21e4 1.21e4 2.827e4 1.21e4 2.827e4 0.808e4 0.808e4 0.808e4'
    yield_stress = '0. 445. 0.05 440. 0.1 435. 0.38 430. 0.95 425. 2. 400.'
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
  [./line1]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 1
    function = upfunc
  [../]
  [./line3]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 3
    function = downfunc
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
  end_time = 2.13e-3
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
  print_linear_residuals = true
  [./console]
    type = Console
    perf_log = true
  [../]
[]

  