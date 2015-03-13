[Mesh]
  type = FileMesh
  file = ../../meshes/Cylinder_hollow_3reg.msh
  dim = 2
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
  [./pore_pressure]
  [../]
[]

[Materials]
  [./mat_mech]
    type = RedbackMechMaterialJ2
    block = '1 2'
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    exponent = 1
    youngs_modulus = 1000
    poisson_ratio = 0.3
    ref_pe_rate = 1
    yield_stress = '0. 1 1. 1'
    pore_pres = pore_pressure
    temperature = stress_zz
  [../]
  [./mat_nomech]
    type = RedbackMaterial
    block = '0 1 2'
    m = 3
    mu = 1e-3
    ar = 10
    gr = 1 # 11
    pore_pres = pore_pressure
    temperature = temp
    is_mechanics_on = false
    ref_lewis_nb = 1
    Kc = 10
    ar_F = 20
    ar_R = 10
    phi0 = 0.1
    eta1 = 1e3
    Aphi = 1
    da_endo = 1e-4
    is_chemistry_on = true
    disp_z = disp_z
    disp_x = disp_x
    disp_y = disp_y
  [../]
  [./elastic_mat]
    type = RedbackMechMaterialElastic
    block = 0
    youngs_modulus = 1000
    exponent = 1
    disp_y = disp_y
    disp_x = disp_x
    pore_pres = 'Lewis_number Lewis_number Lewis_number Lewis_number Lewis_number'
    yield_stress = '0. 1 1. 1'
    temperature = temp
    poisson_ratio = 0.3
    ref_pe_rate = 1
    disp_z = disp_z
  [../]
[]

[Functions]
  active = 'central_rotation downfunc'
  [./upfunc]
    type = ParsedFunction
    value = t
  [../]
  [./downfunc]
    type = ParsedFunction
    value = -3e-2*t
  [../]
  [./spline_IC]
    type = ConstantFunction
  [../]
  [./central_rotation]
    type = ParsedFunction
    value = 1e-3*t
  [../]
[]

[BCs]
  active = 'central_disp_y central_disp_x press_bc low_temp left_disp rigth_disp_y left_disp_y'
  [./left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = 2
    value = 0
  [../]
  [./right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = 1
    function = downfunc
  [../]
  [./left_disp_y]
    type = DirichletBC
    variable = disp_z
    boundary = 2
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
    boundary = 2
    value = 0
  [../]
  [./press_bc]
    type = DirichletBC
    variable = pore_pressure
    boundary = 2
    value = 0
  [../]
  [./low_temp]
    type = DirichletBC
    variable = temp
    boundary = 2
    value = 0
  [../]
  [./constant_force_inner_x]
    type = NeumannBC
    variable = disp_x
    boundary = 3
    value = -1
  [../]
  [./constant_force_inner_y]
    type = NeumannBC
    variable = disp_y
    boundary = 3
    value = -1
  [../]
  [./central_disp_x]
    type = FunctionDirichletTransverseBC
    variable = disp_x
    boundary = 3
    function = central_rotation
    center = '0 0 0'
    dir_index = 0
    axis = '0 0 1'
  [../]
  [./central_disp_y]
    type = FunctionDirichletTransverseBC
    variable = disp_y
    boundary = 3
    function = central_rotation
    center = '0 0 0'
    dir_index = 1
    axis = '0 0 1'
  [../]
[]

[AuxVariables]
  active = 'Mod_Gruntfest_number solid_ratio Return_map mises_strain mech_diss mises_strain_rate strain_rate volumetric_strain_rate mises_stress volumetric_strain mean_stress stress_zz Lewis_number porosity'
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
  [../]
  [./mech_diss]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./volumetric_strain]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./volumetric_strain_rate]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mean_stress]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./porosity]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_rate]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./Return_map]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./td_temp]
    type = TimeDerivative
    variable = temp
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temp
  [../]
  [./mh_temp]
    type = RedbackMechDissip
    variable = temp
  [../]
  [./td_press]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
  [./chem_press]
    type = RedbackChemPressure
    variable = pore_pressure
    block = 0
  [../]
  [./Chem_endo_temp]
    type = RedbackChemEndo
    variable = temp
    block = 0
  [../]
[]

[AuxKernels]
  active = 'volumetric_strain solid_ratio Return_map mises_strain Lewis_number mises_strain_rate strain_rate volumetric_strain_rate mises_stress mean_stress mech_dissipation stress_zz porosity Gruntfest_Number'
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
  [../]
  [./mean_stress]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
  [../]
  [./volumetric_strain]
    type = MaterialRealAux
    variable = volumetric_strain
    property = volumetric_strain
  [../]
  [./volumetric_strain_rate]
    type = MaterialRealAux
    variable = volumetric_strain_rate
    property = volumetric_strain_rate
  [../]
  [./porosity]
    type = MaterialRealAux
    variable = porosity
    property = porosity
  [../]
  [./Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  [../]
  [./strain_rate]
    type = MaterialRealAux
    variable = strain_rate
    property = mises_strain_rate
  [../]
  [./solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  [../]
  [./Return_map]
    type = MaterialRealAux
    variable = Return_map
    property = returnmap_iter
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Postprocessors]
  active = 'solid_ratio_middle mises_stress_centre strain_rate_middle middle_press Return_map_postprocessor Lewis_middle porosity_middle middle_temp'
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0.51 0 0.25'
  [../]
  [./strain]
    type = StrainRatePoint
    variable = temp
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0.51 0 0.25'
  [../]
  [./porosity_middle]
    type = PointValue
    variable = porosity
    point = '0.51 0 0.25'
  [../]
  [./Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0.51 0 0.25'
  [../]
  [./strain_rate_middle]
    type = PointValue
    variable = strain_rate
    point = '0.51 0 0.25'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0.51 0 0.25'
  [../]
  [./mises_stress_centre]
    type = PointValue
    variable = mises_stress
    point = '0.51 0 0.25'
  [../]
  [./Return_map_postprocessor]
    type = ElementExtremeValue
    variable = Return_map
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  start_time = 0.0
  end_time = 100
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
    type = ReturnMapIterDT
    dt = 1e-4
    min_iter = 5
    ratio = 0.5
    max_iter = 15
    dt_max = 1e-2
    postprocessor = Return_map_postprocessor
    dt_min = 1e-8
  [../]
[]

[Outputs]
  file_base = ring_shear_out
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
  [../]
[]

[RedbackAction]
  [./solid]
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

[ICs]
  [./temp_ic]
    variable = temp
    value = 0
    type = ConstantIC
    block = 0
  [../]
  [./press_ic]
    variable = pore_pressure
    type = ConstantIC
    value = 0
  [../]
[]

