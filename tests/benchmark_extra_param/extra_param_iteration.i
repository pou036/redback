[Mesh]
  type = FileMesh
  file = extra_param_initial_guess2.e
  dim = 1
[]

[Variables]
  [./temp]
    # 0.03276648
    initial_condition = 0.03276648
  [../]
  [./lambda]
    family = SCALAR
    initial_condition = 2.4e-6 # 2*lambda_old - lambda_older
  [../]
[]

[GlobalParams]
  ds = 1e-5 # 0.026146068099760434
  ds_old = 1e-5 # 0.010300165599414025
[]

[AuxVariables]
  [./total_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./old_temp]
    initial_from_file_var = temp
  [../]
  [./older_temp]
    initial_from_file_var = old_temp
  [../]
  [./directional_derivative]
    family = SCALAR
  [../]
[]

[Kernels]
  active = 'diff_temp mh_temp'
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
    type = RedbackTotalPorosityAux
    variable = total_porosity
  [../]
[]

[AuxScalarKernels]
  [./directional_derivative]
    type = RedbackContinuationTangentAux
    variable = directional_derivative
    sum_var_2_older = 0
    sum_var_1_old = old_temp
    sum_var_3_older = 0
    sum_var_5_old = 0
    sum_var_2_old = 0
    sum_var_4_old = 0
    sum_var_1 = temp
    sum_var_older_1 = older_temp
    sum_var_old_1 = old_temp
    sum_var_4_older = 0
    sum_var_6_old = 0
    nodes = '0 1 2 3 4 5 6 7 8 9 10'
    sum_var_1_older = older_temp
    sum_var_6_older = 0
    sum_var_5_older = 0
    sum_var_3_old = 0
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
  [./disp_x_rigth]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
[]

[Materials]
  [./adim_rock]
    type = RedbackMaterial
    block = 0
    alpha_2 = 1
    ar = 10
    temperature = temp
    ar_F = 40
    ar_R = 1
    phi0 = 0.1
    da_endo = 1
    total_porosity = total_porosity
    continuation_parameter = lambda
  [../]
[]

[Postprocessors]
  active = 'temp_pt_1 temp_pt_0 temp_pt_3 temp_pt_2 temp_pt_5 temp_pt_4'
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
  [./temp_pt_0]
    type = PointValue
    variable = temp
    point = '-1 0 0'
  [../]
  [./temp_pt_1]
    type = PointValue
    variable = temp
    point = '-0.8 0 0'
  [../]
  [./temp_pt_2]
    type = PointValue
    variable = temp
    point = '-0.6 0 0'
  [../]
  [./temp_pt_3]
    type = PointValue
    variable = temp
    point = '-0.4 0 0'
  [../]
  [./temp_pt_4]
    type = PointValue
    variable = temp
    point = '-0.2 0 0'
  [../]
  [./temp_pt_5]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
[]

[Executioner]
  type = Steady
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  file_base = extra_param_iteration
  exodus = true
  csv = true
  execute_on = 'initial timestep_end'
[]

[ScalarKernels]
  [./continuation_kernel]
    continuation_parameter_old = 1.7e-6
    continuation_parameter_older = 1e-6
    directional_derivative = directional_derivative
    variable = lambda
    type = RedbackContinuation
  [../]
[]

