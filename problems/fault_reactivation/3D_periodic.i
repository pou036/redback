[Mesh]
  type = FileMesh
  file = ../../meshes/3d_3layers.msh
[]

[MeshModifiers]
  [./bottom_rhs_corner]
    type = AddExtraNodeset
    new_boundary = 6
    coord = '0 -5 0'
  [../]
[]

[Variables]
  [./disp_x]
    block = '0 1 2'
  [../]
  [./disp_y]
    block = '0 1 2'
  [../]
  [./disp_z]
    block = '0 1 2'
  [../]
  [./temp]
    block = '0 1 2'
  [../]
  [./pore_pressure]
    block = '0 1 2'
  [../]
[]

[Materials]
  [./redback_nomech]
    type = RedbackMaterial
    block = '0 1 2'
    gr = 1 # 11
    ar = 10
    da_endo = 1e-4
    disp_z = disp_z
    is_chemistry_on = true
    temperature = temp
    pore_pres = pore_pressure
    phi0 = 0.1
    Kc = 10
    ref_lewis_nb = 1
    ar_F = 20
    disp_x = disp_x
    ar_R = 10
    is_mechanics_on = false
    disp_y = disp_y
    eta1 = 1e3
    m = 3
    mu = 1e-3
    Aphi = 1
  [../]
  [./fault_mech]
    type = RedbackMechMaterialJ2
    block = 1
    youngs_modulus = 10
    exponent = 1
    disp_y = disp_y
    disp_x = disp_x
    pore_pres = pore_pressure
    yield_stress = '0. 1 1. 1'
    temperature = temp
    poisson_ratio = 0.3
    ref_pe_rate = 1e2
    disp_z = disp_z
  [../]
  [./rock_elastic]
    type = RedbackMechMaterialElastic
    block = '0 2'
    youngs_modulus = 1000
    exponent = 1
    disp_y = disp_y
    disp_x = disp_x
    pore_pres = pore_pressure
    yield_stress = '0 100 1 100'
    temperature = temp
    poisson_ratio = 0.3
    ref_pe_rate = 1
    disp_z = disp_z
  [../]
[]

[Functions]
  active = 'linear_pos'
  [./ramp_pos]
    type = ParsedFunction
    value = 2*tanh(t)
  [../]
  [./ramp_neg]
    type = ParsedFunction
    value = -2*tanh(t)
  [../]
  [./linear_neg]
    type = ParsedFunction
    value = -1e-1*t
  [../]
  [./linear_pos]
    type = ParsedFunction
    value = 1e-4*t
  [../]
[]

[BCs]
  [./Periodic]
    [./xperiodic]
      variable = 'disp_x disp_y disp_z temp pore_pressure'
      translation = '1 0 0'
      secondary = 2
      primary = 4
    [../]
    [./zperiodic]
      variable = 'disp_x disp_y disp_z temp pore_pressure'
      translation = '0 0 1'
      secondary = 5
      primary = 0
    [../]
  [../]
  [./ux_equals_zero_on_top]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
  [./top_cauchy_zero]
    type = NeumannBC
    variable = disp_x
    boundary = 3
  [../]
  [./ux_bottom_vel]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = 1
    function = linear_pos
  [../]
  [./uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = 1
    value = 0.0
  [../]
  [./uz_bottom]
    type = DirichletBC
    variable = disp_z
    boundary = 1
    value = 0.0
  [../]
  [./temperature]
    type = DirichletBC
    variable = temp
    boundary = '1 3'
    value = 0
  [../]
  [./pore_pressure]
    type = DirichletBC
    variable = pore_pressure
    boundary = '1 3'
    value = 0
  [../]
[]

[AuxVariables]
  active = 'Mod_Gruntfest_number solid_ratio returnmap_iter mises_strain mech_diss mises_strain_rate strain_rate volumetric_strain_rate mises_stress volumetric_strain mean_stress stress_zz Lewis_number porosity'
  [./stress_zz]
    order = CONSTANT
    family = MONOMIAL
    block = 1
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
    block = 1
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
  [./returnmap_iter]
    order = CONSTANT
    family = MONOMIAL
    block = 1
  [../]
[]

[Kernels]
  [./td_temp]
    type = TimeDerivative
    variable = temp
    block = '0 1 2'
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temp
    block = '0 1 2'
  [../]
  [./mh_temp]
    type = RedbackMechDissip
    variable = temp
    block = 1
  [../]
  [./td_press]
    type = TimeDerivative
    variable = pore_pressure
    block = '0 1 2'
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
    block = '0 1 2'
  [../]
  [./chem_press]
    type = RedbackChemPressure
    variable = pore_pressure
    block = 1
  [../]
  [./Chem_endo_temp]
    type = RedbackChemEndo
    variable = temp
    block = 1
  [../]
[]

[AuxKernels]
  active = 'volumetric_strain solid_ratio returnmap_iter mises_strain Lewis_number mises_strain_rate strain_rate volumetric_strain_rate mises_stress mean_stress mech_dissipation stress_zz porosity Gruntfest_Number'
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
  [./returnmap_iter]
    type = MaterialRealAux
    variable = returnmap_iter
    property = returnmap_iter
    block = 1
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
  active = 'solid_ratio_middle mises_stress_centre timestep max_returnmap_iter strain_rate_middle middle_press Lewis_middle porosity_middle middle_temp'
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
  [./strain]
    type = StrainRatePoint
    variable = temp
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0 0 0'
  [../]
  [./porosity_middle]
    type = PointValue
    variable = porosity
    point = '0 0 0'
  [../]
  [./Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0 0 0'
  [../]
  [./strain_rate_middle]
    type = PointValue
    variable = strain_rate
    point = '0 0 0'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  [../]
  [./mises_stress_centre]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  [../]
  [./max_returnmap_iter]
    type = ElementExtremeValue
    variable = returnmap_iter
  [../]
  [./timestep]
    type = TimestepSize
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  # [./TimeStepper]
  # type = ConstantDT
  # dt = 1e-1
  # [../]
  start_time = 0.0
  end_time = 10000
  dtmax = 1
  dtmin = 1e-9
  type = Transient
  num_steps = 100000
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
[]

[Outputs]
  file_base = 3D_periodic
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
    linear_residuals = true
  [../]
[]

[RedbackAction]
  [./solid]
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    temp = temp
    pore_pres = pore_pressure
  [../]
[]

[ICs]
  [./temp_ic]
    variable = temp
    value = 0
    type = ConstantIC
  [../]
  [./press_ic]
    variable = pore_pressure
    type = ConstantIC
    value = 0
  [../]
[]

