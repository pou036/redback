[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 50
  ny = 10
  xmin = -10
  xmax = 10
  ymin = -0.5
  ymax = 0.5
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
    type = RedbackMaterial
    block = 0
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
    gr = 0.8
    pore_pres = 0
    is_mechanics_on = true
    ref_lewis_nb = 1
    phi0 = 0.1
  [../]
[]

[Functions]
  [./upfunc]
    type = ParsedFunction
    value = 0.1*t
  [../]
  [./downfunc]
    type = ParsedFunction
    value = -0.1*t
  [../]
  [./spline_IC]
    type = ConstantFunction
    value = 1
  [../]
[]

[BCs]
  active = 'right_disp temp_box left_disp rigth_disp_y left_disp_y'
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
  active = 'Mod_Gruntfest_number mises_strain mech_diss mises_strain_rate mises_stress'
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
  [./Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
    block = '0 1'
  [../]
[]

[Kernels]
  active = 'temp_dissip temp_td'
  [./temp_td]
    type = TimeDerivative
    variable = temp
    block = 0
  [../]
  [./temp_diff]
    type = AnisotropicDiffusion
    variable = temp
    block = 0
    tensor_coeff = '1 0 0 0 1 0 0 0 1'
  [../]
  [./temp_dissip]
    type = RedbackMechDissip
    variable = temp
    block = 0
  [../]
[]

[AuxKernels]
  active = 'mises_strain mises_strain_rate mises_stress mech_dissipation Gruntfest_Number'
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
    type = MaterialRealAux
    variable = mises_stress
    property = mises_stress
  [../]
  [./mises_strain]
    type = MaterialRealAux
    variable = mises_strain
    property = mises_strain
  [../]
  [./mises_strain_rate]
    type = MaterialRealAux
    variable = mises_strain_rate
    block = 0
    property = mises_strain_rate
  [../]
  [./mech_dissipation]
    type = MaterialRealAux
    variable = mech_diss
    property = mechanical_dissipation
  [../]
  [./Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
    block = 0
  [../]
[]

[Postprocessors]
  active = 'temp_centre mises_strain strain_rate mises_stress Gruntfest_number'
  [./test]
    type = StrainRatePoint
    variable = temp
    point = ' 0.5 0.5 0'
  [../]
  [./temp_centre]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
  [./strain_rate]
    type = PointValue
    variable = mises_strain_rate
    point = '0 0 0'
  [../]
  [./mises_stress]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  [../]
  [./Gruntfest_number]
    type = PointValue
    variable = Mod_Gruntfest_number
    point = '0 0 0'
  [../]
  [./mises_strain]
    type = PointValue
    variable = mises_strain
    point = '0 0 0'
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
    dt = 1e-3
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

