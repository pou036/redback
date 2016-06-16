[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 10
  ny = 5
  nz = 5
  xmin = -1
[]

[Variables]
  active = 'temp'
  [./temp]
  [../]
  [./disp_x]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./disp_y]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
[]

[AuxVariables]
  [./total_porosity]
    order = FIRST
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
[]

[AuxKernels]
  [./total_porosity]
    type = RedbackTotalPorosityAux_UO
    variable = total_porosity
    redback_material_parameters = redback_material_parameters_uo
  [../]
[]


[UserObjects]

  [./ar_uo]
    type = RedbackMaterialConstant
    value = 10
  [../]
  
  [./delta_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./gr_uo]
    type = RedbackMaterialConstant
    value = 4.313e-6
  [../]
  
  [./alpha_1_uo]
    type = RedbackMaterialConstant
    value = 0
  [../]
  
  [./alpha_2_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./alpha_3_uo]
    type = RedbackMaterialConstant
    value = 0
  [../]
  

  
  [./confining_pressure_uo]
    type = RedbackMaterialConstant
    value = 1
  [../]
  
  [./initial_porosity_uo]
    type = RedbackMaterialConstant
    value = 0.1
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
    parameters = 'ar delta gr alpha_1 alpha_2 alpha_3 confining_pressure solid_compressibility fluid_compressibility initial_porosity ref_lewis_number'
    user_objects = 'ar_uo delta_uo gr_uo alpha_1_uo alpha_2_uo alpha_3_uo confining_pressure_uo solid_compressibility_uo fluid_compressibility_uo initial_porosity_uo ref_lewis_nb_uo'
  [../]
  
[]

[BCs]
  active = 'left_temp right_temp'
  [./left_temp]
    type = DirichletBC
    variable = temp
    boundary = left
    value = 0
  [../]
  [./right_temp]
    type = DirichletBC
    variable = temp
    boundary = right
    value = 0
  [../]
  [./disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 'left right'
    value = 0
  [../]
  [./disp_x_left]
    type = DirichletBC
    variable = disp_x
    boundary = left
    value = 1
  [../]
  [./disp_x_right]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
[]

[Materials]
  [./adim_rock]
    type = RedbackMaterial_UO
    block = 0
    # alpha_2 = 1
    # ar = 10
    #gr = 4.313e-6 # 0.095*exp(-Ar), Ar=10
    
    pore_pres = 0
    
    redback_material_parameters = redback_material_parameters_uo
    
    temperature = temp
    ar_F = 40
    ar_R = 1
    Aphi = 0
    da_endo = 1
    total_porosity = total_porosity
  [../]
[]

[Postprocessors]
  active = 'middle_temp'
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
[]

[Executioner]
  type = Transient
  num_steps = 10000
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  end_time = 10
  dtmax = 0.1
  scheme = bdf2
  [./TimeStepper]
    type = ConstantDT
    dt = 1
  [../]
[]

[Outputs]
  file_base = bench1_a_out_uo
  exodus = true
  csv = true
  execute_on = TIMESTEP_END
  console = true
[]

[ICs]
  [./temp_ic]
    variable = temp
    value = 0
    type = ConstantIC
    block = 0
  [../]
[]

