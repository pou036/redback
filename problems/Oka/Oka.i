[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 4
  ny = 8
  nz = 4
  xmin = -1
  ymin = -2
  ymax = 2
  zmin = -1
[]

[MeshModifiers]
  [./edge_centre_point_front]
    type = AddExtraNodeset
    coord = '0 -2 -1'
    new_boundary = 6
  [../]
  [./edge_centre_point_back]
    type = AddExtraNodeset
    coord = '0 -2 1'
    new_boundary = 7
  [../]
  [./edge_centre_point_left]
    type = AddExtraNodeset
    coord = '-1 -2 0'
    new_boundary = 8
  [../]
  [./edge_centre_point_right]
    type = AddExtraNodeset
    coord = '1 -2 0'
    new_boundary = 9
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
  [./pore_pressure]
  [../]
[]

[Materials]
  [./mat_mech]
    type = RedbackMechMaterialCC
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    pore_pres = pore_pressure
    temperature = temp
    exponent = 2
    ref_pe_rate = 1e4
    slope_yield_surface = 1.44
    yield_stress = '0. 1 1 1'
    youngs_modulus = 80
    poisson_ratio = 0.2
    total_porosity = total_porosity
    mhc = 1e3
    exponent_p = -30
  [../]
  [./mat_nomech]
    type = RedbackMaterial
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    pore_pres = pore_pressure
    temperature = temp
    m = 3
    mu = 1
    ar = 10
    gr = 1
    ref_lewis_nb = 1
    Kc = 1
    ar_F = 20
    ar_R = 10
    phi0 = 0.1
    Aphi = 1
    eta2 = 1e4
    da_exo = 1e-3
    total_porosity = total_porosity
    solid_compressibility = 0.0125
    pressurization_coefficient = 1
  [../]
[]

[Functions]
  active = 'timestep_function downfunc'
  [./upfunc]
    type = ParsedFunction
    value = t
  [../]
  [./downfunc]
    type = ParsedFunction
    value = -6.67e-0*t
  [../]
  [./spline_IC]
    type = ConstantFunction
  [../]
  [./geothermal_gradient]
    type = ParsedFunction
    value = 0.1+0.1*(2-y)
  [../]
  [./timestep_function]
    type = ParsedFunction
    value = 'max(1e-5, min(4e-4, dt*min(1-0.04*(m-10), max(1-0.1*(n-4.1), 0.2))))'
    vals = 'num_nli dt max_returnmap_iter'
    vars = 'n dt m'
  [../]
[]

[BCs]
  active = 'drained_top_bottom bottom_fix_x bottom_fix_y bottom_fix_z top_fix_x top_fix_z confinement_back confinement_left confinement_right constant_y_velocity_top side_temp confinement_front'
  [./temp_box]
    type = NeumannBC
    variable = temp
    boundary = '0 1 2 3 4 5'
  [../]
  [./constant_force_top]
    type = NeumannBC
    variable = disp_y
    boundary = top
    value = -1.5
  [../]
  [./back_fix_z]
    type = NeumannBC
    variable = disp_z
    boundary = 0
  [../]
  [./right_fix_x]
    type = DirichletBC
    variable = disp_z
    boundary = right
    value = 0
  [../]
  [./bottom_fix_y]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0
  [../]
  [./constant_y_velocity_top]
    type = FunctionPresetBC
    variable = disp_y
    boundary = top
    function = downfunc
  [../]
  [./bottom_fix_x]
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 0
  [../]
  [./bottom_fix_z]
    type = DirichletBC
    variable = disp_z
    boundary = bottom
    value = 0
  [../]
  [./top_fix_x]
    type = DirichletBC
    variable = disp_x
    boundary = top
    value = 0
  [../]
  [./top_fix_z]
    type = DirichletBC
    variable = disp_z
    boundary = top
    value = 0
  [../]
  [./confinement_left]
    type = NeumannBC
    variable = disp_x
    boundary = left
    value = 0.11
  [../]
  [./confinement_right]
    type = NeumannBC
    variable = disp_x
    boundary = right
    value = -0.11
  [../]
  [./confinement_back]
    type = NeumannBC
    variable = disp_z
    boundary = back
    value = 0.11
  [../]
  [./side_temp]
    type = DirichletBC
    variable = temp
    boundary = '0 2 4 5'
    value = 0
  [../]
  [./drained_top_bottom]
    type = DirichletBC
    variable = pore_pressure
    boundary = '1 3'
    value = 0
  [../]
  [./bottom_fix_x_left]
    type = DirichletBC
    variable = disp_z
    boundary = 8
    value = 0
  [../]
  [./bottom_fix_x_right]
    type = DirichletBC
    variable = disp_z
    boundary = 9
    value = 0
  [../]
  [./bottom_fix_x_front]
    type = DirichletBC
    variable = disp_x
    boundary = 6
    value = 0
  [../]
  [./bottom_fix_x_back]
    type = DirichletBC
    variable = disp_x
    boundary = 7
    value = 0
  [../]
  [./confinement_front]
    type = NeumannBC
    variable = disp_z
    boundary = front
    value = -0.11
  [../]
[]

[AuxVariables]
  active = 'mech_porosity Mod_Gruntfest_number solid_ratio total_porosity returnmap_iter mises_strain mech_diss mises_strain_rate volumetric_strain_rate stress_yy stress_xx mises_stress volumetric_strain mean_stress stress_zz Lewis_number'
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
    block = 0
  [../]
  [./Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_xx]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_yy]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./total_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./mech_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./returnmap_iter]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  active = 'td_press temp_diff temp_dissip press_thermPress td_temp press_diff'
  [./td_temp]
    type = TimeDerivative
    variable = temp
  [../]
  [./temp_diff]
    type = Diffusion
    variable = temp
  [../]
  [./temp_dissip]
    type = RedbackMechDissip
    variable = temp
  [../]
  [./temp_endo_chem]
    type = RedbackChemEndo
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
  [./press_poromech]
    type = RedbackPoromechanics
    variable = pore_pressure
  [../]
  [./press_thermPress]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temp
  [../]
[]

[AuxKernels]
  active = 'mech_porosity volumetric_strain solid_ratio total_porosity mises_strain Lewis_number mises_strain_rate volumetric_strain_rate stress_yy stress_xx mises_stress mean_stress mech_dissipation stress_zz returnmap_iter Gruntfest_Number'
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
    property = eqv_plastic_strain
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
  [./mean_stress]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
    block = 0
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
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = mech_porosity
    execute_on = linear
    is_mechanics_on = true
  [../]
  [./mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = timestep_end
    property = mechanical_porosity
  [../]
  [./Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  [../]
  [./solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  [../]
  [./stress_xx]
    type = RankTwoAux
    variable = stress_xx
    rank_two_tensor = stress
    index_j = 0
    index_i = 0
  [../]
  [./stress_yy]
    type = RankTwoAux
    variable = stress_yy
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  [../]
  [./returnmap_iter]
    type = MaterialRealAux
    variable = returnmap_iter
    property = returnmap_iter
  [../]
[]

[Postprocessors]
  active = 'volumetric_strain new_timestep num_nli mises_strain mises_strain_rate max_returnmap_iter num_li middle_press solid_ratio_middle total_volume_strain volumetric_strain_rate mises_stress mean_stress Lewis_middle temp_middle porosity_middle dt top_avg_stress_yy'
  [./mises_stress]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  [../]
  [./mises_strain]
    type = PointValue
    variable = mises_strain
    point = '0 0 0'
  [../]
  [./mises_strain_rate]
    type = PointValue
    variable = mises_strain_rate
    point = '0 0 0'
  [../]
  [./temp_middle]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
  [./mean_stress]
    type = PointValue
    variable = mean_stress
    point = '0 0 0'
  [../]
  [./volumetric_strain]
    type = PointValue
    variable = volumetric_strain
    point = '0 0 0'
  [../]
  [./volumetric_strain_rate]
    type = PointValue
    variable = volumetric_strain_rate
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0 0 0'
  [../]
  [./porosity_middle]
    type = PointValue
    variable = total_porosity
    point = '0 0 0'
  [../]
  [./Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0 0 0'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  [../]
  [./right_avg_sigma_xx]
    type = SideAverageValue
    variable = stress_xx
    boundary = right
  [../]
  [./total_volume_strain]
    type = ElementIntegralMaterialProperty
    mat_prop = total_volumetric_strain
    use_displaced_mesh = true
  [../]
  [./top_avg_stress_yy]
    type = SideAverageValue
    variable = stress_yy
    boundary = top
  [../]
  [./max_returnmap_iter]
    type = ElementExtremeValue
    variable = returnmap_iter
  [../]
  [./dt]
    type = TimestepSize
  [../]
  [./num_li]
    type = NumLinearIterations
  [../]
  [./num_nli]
    type = NumNonlinearIterations
  [../]
  [./new_timestep]
    type = PlotFunction
    function = timestep_function
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    # petsc_options = '-snes_monitor -snes_linesearch_monitor'
    # petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol -ksp_max_it'
    # petsc_options_value = 'bcgs bjacobi 1E-13 1E-13 100 1E-20 1E-50 20'
    type = SMP
    full = true
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  start_time = 0.0
  end_time = 0.12
  dtmax = 1e4
  dtmin = 1e-7
  type = Transient
  num_steps = 10000
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-8 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    type = PostprocessorDT
    dt = 0.0002
    postprocessor = new_timestep
  [../]
[]

[Outputs]
  file_base = Oka
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
  [../]
[]

[RedbackMechAction]
  [./solid]
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    temp = temp
    pore_pres = pore_pressure
  [../]
[]

[ICs]
  active = 'press_ic temp_IC'
  [./temp_IC]
    variable = temp
    type = ConstantIC
    value = 0
  [../]
  [./press_ic]
    variable = pore_pressure
    type = ConstantIC
    value = 0
  [../]
  [./temp_random_IC]
    function = geothermal_gradient
    max = 0.01
    type = FunctionWithRandomIC
    variable = temp
  [../]
[]

