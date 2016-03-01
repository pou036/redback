[Mesh]
  type = FileMesh
  file = extra_param_initial_guess.e
  dim = 1
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
  [./old_temp]
    initial_from_file_var = temp
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
    gr = 1.7e-6 # 0.095*exp(-Ar), Ar=10
    temperature = temp
    ar_F = 40
    ar_R = 1
    phi0 = 0.1
    da_endo = 1
    total_porosity = total_porosity
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
  file_base = extra_param_initial_guess2
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
