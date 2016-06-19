[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 4
  ny = 4
  xmin = -1
  ymin = -1
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

[Materials]
  [./mat0]
    type = RedbackMechMaterial_Elastic_UO
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    disp_z = 0
    temperature = temp
    C_ijkl = '1.346e+03 5.769e+02 5.769e+02 1.346e+03 5.769e+02 1.346e+03 3.846e+02 3.846e+02 3.846e+2'
    yield_stress = '0. 1 1. 1'
    exponent = 1
    ref_pe_rate = 1
    youngs_modulus = 1000
    poisson_ratio = 0.3
    total_porosity = total_porosity
    redback_material_parameters = redback_material_parameters_uo
    
  [../]
  [./mat1]
    type = RedbackMaterial_UO
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    disp_z = 0
    temperature = temp
    Aphi = 0
    #ar = 5
    #gr = 1
    
    redback_material_parameters = redback_material_parameters_uo
    #alpha_2 = 2
    pore_pres = 0
    is_mechanics_on = true
    #phi0 = 0.5
    #ref_lewis_nb = 1
    ar_F = 1
    ar_R = 1
    total_porosity = total_porosity
  [../]
[]

[BCs]
  [./left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
  [./left_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 3
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
    value = -1
  [../]
[]

[AuxVariables]
  [./total_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./mech_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./temp_td]
    type = TimeDerivative
    variable = temp
  [../]
  [./temp_diff]
    type = AnisotropicDiffusion
    variable = temp
    tensor_coeff = '1 0 0 0 1 0 0 0 1'
  [../]
  [./temp_dissip]
    type = RedbackMechDissip
    variable = temp
  [../]
[]

[AuxKernels]
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

  [./ar_uo]
    type = RedbackMaterialConstant
    value = 5
  [../]
  
  [./delta_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./gr_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./alpha_2_uo]
    type = RedbackMaterialConstant
    value = 2
  [../]
  
  
  [./confining_pressure_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./initial_porosity_uo]
    type = RedbackMaterialConstant
    value = 0.5
  [../]
  
    
  [./solid_compressibility_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  
  [./fluid_compressibility_uo]
    type = RedbackMaterialConstant
    value = 0.0
  [../]
  
  
  [./ref_lewis_nb_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]

  [./redback_material_parameters_uo]
    type = RedbackElementParameters
  #  parameters = 'ar      delta    gr    alpha_2 confining_pressure solid_compressibility fluid_compressibility initial_porosity ref_lewis_number'
  #  user_objects = 'ar_uo delta_uo gr_uo alpha_2_uo confining_pressure_uo initial_porosity_uo ref_lewis_nb_uo'
    ar                  = ar_uo
    delta               = delta_uo
    gr                  = gr_uo
    alpha_2             = alpha_2_uo
    confining_pressure  = confining_pressure_uo
    initial_porosity    = initial_porosity_uo
    ref_lewis_number    = ref_lewis_nb_uo

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
  end_time = 5
  dtmax = 1
  dtmin = 1e-7
  type = Transient
  num_steps = 3
  l_max_its = 500
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
  file_base = bench_elastic_1_uo
  output_initial = true
  exodus = true
  csv = true
  [./console]
    type = Console
    perf_log = true
    linear_output = false
  [../]
[]

[ICs]
  active = 'ic_temp'
  [./ic_temp]
    variable = temp
    value = 0
    type = ConstantIC
  [../]
  [./Spline_IC]
    function = spline_IC
    variable = temp
    type = FunctionIC
    block = 0
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

