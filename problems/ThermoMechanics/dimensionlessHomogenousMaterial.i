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
  [./right_mid_point]
    type = AddExtraNodeset
    boundary = 5
    coord = '1 0.5'
  [../]
  [./top_mid_point]
    type = AddExtraNodeset
    boundary = 6
    coord = '0.5 1'
  [../]
  [./bottom_mid_point]
    type = AddExtraNodeset
    boundary = 7
    coord = '0.5 0'
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
  active = 'mat0'
  [./mat0]
    type = DimensionlessRock
    block = '0 1'
    disp_y = disp_y
    disp_x = disp_x
    C_ijkl = '1.346e+03 5.769e+02 5.769e+02 1.346e+03 5.769e+02 1.346e+03 3.846e+02 3.846e+02 3.846e+2'
    temperature = temp
    yield_stress = '0. 1 1. 1'
    disp_z = disp_z
    ar_c = 1
    m = 2
    da = 1
    mu = 1
    ar = 5
    delta = 1
    gr = 0.5
  [../]
  [./mat1]
    type = DimensionlessRock
    block = 1
    disp_y = disp_y
    disp_x = disp_x
    C_ijkl = '1.346e+01 5.769e+00 5.769e+00 1.346e+01 5.769e+00 1.346e+01 3.846e+00 3.846e+00 3.846e+00'
    temperature = temp
    yield_stress = '0. 1 1 1'
    disp_z = disp_z
    ar_c = 1
    m = 2
    da = 1
    mu = 1
    ar = 10
    delta = 1
    gr = 1e0
  [../]
[]

[Functions]
  active = 'spline_IC'
  [./upfunc]
    type = ParsedFunction
    value = t
  [../]
  [./downfunc]
    type = ParsedFunction
    value = -t
  [../]
  [./spline_IC]
    type = ConstantFunction
    value = 1
  [../]
[]

[BCs]
  active = 'left_disp rigth_disp_y left_disp_y temp_box constant_force_right'
  [./left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
  [./right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 1
    function = downfunc
  [../]
  [./bottom_temp]
    type = NeumannBC
    variable = temp
    boundary = 0
    value = -1
  [../]
  [./top_temp]
    type = NeumannBC
    variable = temp
    boundary = 2
    value = -1
  [../]
  [./left_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 3
    value = 0
  [../]
  [./temp_mid_pts]
    type = DirichletBC
    variable = temp
    boundary = '4 5 6 7'
    value = 0
  [../]
  [./rigth_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 1
    value = 0
  [../]
  [./temp_box]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2 3'
    value = 0
  [../]
  [./constant_force_right]
    type = NeumannBC
    variable = disp_x
    boundary = 1
    value = 2
  [../]
[]

[AuxVariables]
  active = 'mises_strain mech_diss mises_strain_rate mises_stress'
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
  [./mises_strain]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mises_strain_rate]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./mech_diss]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
[]

[Kernels]
  active = 'temp_diff temp_mht temp_td'
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
    block = '0 1'
  [../]
[]

[AuxKernels]
  active = 'mises_strain mises_strain_rate mises_stress mech_dissipation'
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
  [./mises_strain]
    type = MisesStrainAux
    variable = mises_strain
  [../]
  [./mises_strain_rate]
    type = MisesStrainRateAux
    variable = mises_strain_rate
    block = 0
  [../]
  [./mech_dissipation]
    type = MechDissipationAux
    variable = mech_diss
    block = 0
  [../]
[]

[Postprocessors]
  active = 'temp_centre'
  [./test]
    type = StrainRatePoint
    variable = temp
    point = ' 0.5 0.5 0'
  [../]
  [./temp_centre]
    type = RedbackPost
    variable = temp
    point = '0.5 0.5 0'
  [../]
  [./strain_rate]
    type = RedbackPost
    variable = mises_strain_rate
    point = '0.5 0.5 0'
  [../]
  [./mises_stress]
    type = RedbackPost
    variable = mises_stress
    point = '0.5 0.5 0'
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
  end_time = 10
  dtmax = 1
  dtmin = 1e-7
  type = Transient
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    dt = 5e-3
  [../]
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
  active = 'ic_temp'
  [./ic_temp]
    variable = temp
    value = 0
    type = ConstantIC
    block = '0 1'
  [../]
  [./Spline_IC]
    function = spline_IC
    variable = temp
    type = FunctionIC
    block = 0
  [../]
[]

