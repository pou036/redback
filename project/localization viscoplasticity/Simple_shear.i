[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 1
  ny = 30
  xmax = 1
  zmax = 1
[]

[Variables]
  [./Temperature]
  [../]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./pore_pressure]
  [../]
[]

[AuxVariables]
  [stress_22]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe11]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe22]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe33]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_stress]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_strain]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_strain_rate]
    order = CONSTANT
    family = MONOMIAL
    block = '0'
  []
  [Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
  []
  [volumetric_strain]
    order = CONSTANT
    family = MONOMIAL
  []
  [volumetric_strain_rate]
    order = CONSTANT
    family = MONOMIAL
  []
  [mean_stress]
    order = CONSTANT
    family = MONOMIAL
    block = '0'
  []
  [total_porosity]
    order = FIRST
    family = MONOMIAL
  []
  [mech_porosity]
    order = FIRST
    family = MONOMIAL
  []
  [plastic_p]
    family = MONOMIAL
    order = CONSTANT
  []
  [stress_12]
    order = CONSTANT
    family = MONOMIAL
  []
[]


[AuxKernels]
  [stress_22]
    type = RankTwoAux
    rank_two_tensor = stress
    variable = stress_22
    index_i = 1
    index_j = 1
  []
  [pe11]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe11
    index_i = 0
    index_j = 0
  []
  [pe22]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe22
    index_i = 1
    index_j = 1
  []
  [pe33]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe33
    index_i = 2
    index_j = 2
  []
  [mises_stress]
    type = MaterialRealAux
    variable = mises_stress
    property = mises_stress
  []
  [mises_strain]
    type = MaterialRealAux
    variable = mises_strain
    property = mises_strain
  []
  [mises_strain_rate]
    type = MaterialRealAux
    variable = mises_strain_rate
    block = '0'
    property = mises_strain_rate
  []
  [Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
    block = '0'
  []
  [mean_stress]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
    block = '0'
  []
  [volumetric_strain]
    type = MaterialRealAux
    variable = volumetric_strain
    property = volumetric_strain
  []
  [volumetric_strain_rate]
    type = MaterialRealAux
    variable = volumetric_strain_rate
    property = volumetric_strain_rate
  []
  [total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = 'mech_porosity'
  []
  [mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = 'timestep_end'
    property = mechanical_porosity
  []
  [plastic_strain]
    type = MaterialRealAux
    variable = plastic_p
    property = eqv_plastic_strain
  []
  [stress_12]
    type = RankTwoAux
    variable = stress_12
    rank_two_tensor = stress
    index_j = 1
    index_i = 0
  []
[]


[Functions]
  [./top_bc]
    type = ParsedFunction
    value = 0.01*t
  [../]
  [./bottom_bc]
    type = ParsedFunction
    value = -0.01*t
  [../]
[]

[Kernels]
  active = 'td_press temp_diff temp_dissip td_temp press_diff'
  [./td_temp]
    type = TimeDerivative
    variable = Temperature
  [../]
  [./td_press]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./temp_diff]
    type = Diffusion
    variable = Temperature
  [../]
  [./press_diff]
    type = Diffusion
    variable = pore_pressure
  [../]
  [./press_thermPress]
    type = RedbackThermalPressurization
    variable = disp_z
  [../]
  [./temp_dissip]
    type = RedbackMechDissip
    variable = Temperature
  [../]
  [./press_poromech]
    type = RedbackPoromechanics
    variable = pore_pressure
  [../]
[]

[BCs]
  [./ux_top]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = top
    function = top_bc
  [../]
  [./ux_bottom]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = bottom
    function = bottom_bc
  [../]
  [./uy_top]
    type = DirichletBC
    variable = disp_y
    boundary = top
    value = 0
  [../]
  [./Periodic]
    [./periodic_x]
      secondary = right
      primary = left
      auto_direction = x
    [../]
  [../]
  [./uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0
  [../]
  [./uz_back]
    type = DirichletBC
    variable = disp_z
    boundary = back
    value = 0
  [../]
  [./temp_top_bottom]
    type = DirichletBC
    variable = Temperature
    boundary = 'top bottom'
    value = 0
  [../]
  [./pp_top_bottom]
    type = DirichletBC
    variable = pore_pressure
    boundary = 'top bottom'
    value = 0
  [../]
[]

[Materials]
  active = 'no_mech_material mech_material'
  [./mech_material]
    type = RedbackMechMaterialDP
    block = 0
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    yield_stress = '0 1 0.1 1'
    C_ijkl = '5.77E2 3.85E2 0.0'
    fill_method = general_isotropic
    pore_pres = pore_pressure
    temperature = Temperature
  [../]
  [./no_mech_material]
    type = RedbackMaterial
    pore_pres = pore_pressure
    ar = 5.5 # it used to be 8 but we reduced it to get low T
    total_porosity = 0.1
    is_mechanics_on = true
    temperature = Temperature
  [../]
  [./mech_notch]
    type = RedbackMechMaterialJ2
    block = 1
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    yield_stress = '0 1 0.1 0.1'
    C_ijkl = '5.77E2 3.85E2 0.0'
    fill_method = general_isotropic
    pore_pres = pore_pressure
    temperature = Temperature
  [../]
[]

[Postprocessors]
  [./temp_middle_new]
    type = PointValue
    variable = Temperature
    point = '1 0.5 0.05'
  [../]
  [./mid_temp]
    type = PointValue
    variable = Temperature
    point = '1 0.5 0'
  [../]
  [tangential_force]
    type = SideAverageValue
    variable = 'stress_12'
    boundary = 'top'
  []
  [normal_force]
    type = SideAverageValue
    variable = 'stress_22'
    boundary = 'top'
  []
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
    solve_type = PJFNK
    petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart'
    petsc_options_value = 'gmres asm lu 201'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 100
  dt = 1e-6
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart '
  petsc_options_value = 'gmres asm lu 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  line_search = basic
  [./TimeStepper]
    type = ConstantDT
    dt = 0.05 # 0.1
  [../]
[]

[Outputs]
  exodus = true
  file_base = simple_shear_elastoviscoplastic
  print_perf_log = true
[]

[RedbackMechAction]
  [./my_action]
    disp_z = disp_z
    disp_x = disp_x
    disp_y = disp_y
    temp = Temperature
    pore_pres = pore_pressure
  [../]
[]
