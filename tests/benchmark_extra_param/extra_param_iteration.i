[Mesh]
  type = FileMesh
  file = extra_param_initial_guess2.e
  dim = 1
[]

[Variables]
  [./temp]
  [../]
  [./lambda]
    family = SCALAR
  [../]
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
    nodes = 0
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

[ICs]
  [./temp_ic]
    variable = temp
    value = 0
    type = ConstantIC
    block = 0
  [../]
[]

[ScalarKernels]
  [./continuation_kernel]
    ds_old = 1e-7
    continuation_parameter_old = 4.4e-6
    continuation_parameter_older = 4.316e-6
    directional_derivative = directional_derivative
    variable = lambda
    type = RedbackContinuation
    ds = 1e-4
  [../]
[]

