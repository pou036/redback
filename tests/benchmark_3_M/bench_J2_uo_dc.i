[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 5
  ny = 5
  xmin = -1.5
  xmax = 1.5
  ymin = -1
[]

[Variables]
  active = 'disp_z disp_y disp_x'
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

[Materials]
  [./elasticity_tensor]
    type = ComputeElasticityTensor
    block = 0
    fill_method = symmetric_isotropic
    #with E = 2.1e5 and nu = 0.3
    #Hooke's law: E-nu to Lambda-G
    #C_ijkl = '121154 80769.2'  ### fixme 
    #with E = 1000 and nu = 0.3
    C_ijkl = '576.9230769230769 384.6153846153846'
  [../]
  [./strain]
    type = ComputeFiniteStrain
    block = 0
    displacements = 'disp_x disp_y'
  [../]
  [./mat_mech]
    type = RedbackMechMaterialJ2_UO_DC
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    exponent = 1
   # youngs_modulus = 1000
   # poisson_ratio = 0.3
    ref_pe_rate = 1
    slope_yield_surface = -0.6
    yield_stress = '0. 1 1. 1'
    total_porosity = total_porosity
    redback_material_parameters = redback_material_parameters_uo
  [../]
  
  
  
  [./mat_nomech]
    type = RedbackMaterial_UO
    block = 0
    is_mechanics_on = false
    Aphi = 0
    
    redback_material_parameters = redback_material_parameters_uo
    
    ar_F = 1
    ar_R = 1
    exponent = 1
    
    total_porosity = total_porosity
  [../]
[]

[Functions]
  active = 'downfunc'
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
[]

[BCs]
  active = 'constant_force_right left_disp rigth_disp_y left_disp_y'
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
    value = -2
  [../]
[]

[AuxVariables]
  active = 'mech_porosity Mod_Gruntfest_number total_porosity mises_strain mises_strain_rate volumetric_strain_rate mises_stress volumetric_strain mean_stress'
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
  [./total_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./mech_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
[]

[AuxKernels]
  active = 'mech_porosity volumetric_strain total_porosity mises_strain mises_strain_rate volumetric_strain_rate mises_stress mean_stress Gruntfest_Number'
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
    type = RedbackTotalPorosityAux_UO
    variable = total_porosity
    mechanical_porosity = mech_porosity
    redback_material_parameters = redback_material_parameters_uo
  [../]
  [./mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = timestep_end
    property = mechanical_porosity
  [../]
[]


[UserObjects]

### User objects

### Material Parameter User objects
  [./ar_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./gr_uo]
    type = RedbackMaterialConstant
    value = 0.1
  [../]
  
  [./alpha_2_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./confining_pressure_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./initial_porosity_uo]
    type = RedbackMaterialConstant
    value = 0.1
  [../]
  
  [./ref_lewis_nb_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]

  [./redback_material_parameters_uo]
    type = RedbackElementParameters
    ar                  = ar_uo
    gr                  = gr_uo
    alpha_2             = alpha_2_uo
    confining_pressure  = confining_pressure_uo
    initial_porosity    = initial_porosity_uo
    ref_lewis_number    = ref_lewis_nb_uo

  [../]
  
  
[]

[Postprocessors]
  active = 'volumetric_strain mises_strain mises_strain_rate volumetric_strain_rate mises_stress mean_stress'
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
  end_time = 0.005
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
    type = ConstantDT
    dt = 1e-3
  [../]
[]

[Outputs]
  file_base = bench_J2_out_uo_dc
  output_initial = true
  exodus = true
  print_linear_residuals = true
  [./console]
    type = Console
    perf_log = true
  [../]
[]

[RedbackMechAction_UO]
  [./solid]
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    
    redback_material_parameters = redback_material_parameters_uo
  [../]
[]

