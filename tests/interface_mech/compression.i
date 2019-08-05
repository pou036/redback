[Mesh]
  type = GeneratedMesh
  uniform_refine = 0
  dim = 2
  nx = 4
  ny = 4
[]

[Variables]
  [./disp_x0]
    block = '0'
  [../]
  [./disp_y0]
    block = '0'
  [../]
[]

[AuxVariables]
  [./stress_yy0]
    block = '0'
    family = MONOMIAL
    order = CONSTANT
  [../]
[]

[AuxKernels]
  [./stress_yy0]
    type = RankTwoAux
    rank_two_tensor = 0_stress
    index_j = 1
    index_i = 1
    variable = stress_yy0
  [../]
[]

[Materials]
  [./Elasticity_tensor]
    type = ComputeIsotropicElasticityTensor
    poissons_ratio = 0.3
    youngs_modulus = 10000
    block = 0
    base_name = 0
  [../]
  [./mc]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = 0
    base_name = 0
  [../]
  [./small_strain0]
    type = ComputePlaneFiniteStrain
    block = '0'
    displacements = 'disp_x0 disp_y0'
    base_name = 0
  [../]
[]

[Functions]
  [./loading]
    type = ParsedFunction
    value = '-5*t'
  [../]
  [./loading_vel]
    type = ParsedFunction
    value = 'if(t>0.001,0.0002*t,0)'
  [../]
  [./loading_stress]
    type = ParsedFunction
    value = 'min(-5*t,confine)'
    vals = '-0'
    vars = 'confine'
  [../]
  [./confinement]
    type = ConstantFunction
    value = -0
  [../]
[]

[BCs]
  # pin particle along symmetry planes
  # [./uz_front]
  # type = FunctionPresetBC
  # variable = disp_z
  # boundary = front
  # function = loading_vel
  # [../]
  # [./ux_right]
  # type = FunctionPresetBC
  # variable = disp_x
  # boundary = right
  # function = loading_vel
  # [../]
  [./uy_top]
    type = FunctionPresetBC
    variable = disp_y0
    boundary = 'top'
    function = loading_vel
  [../]
  [./no_disp_x]
    type = PresetBC
    variable = disp_x0
    boundary = 'left'
    value = 0.0
  [../]
  [./no_disp_y]
    type = PresetBC
    variable = disp_y0
    boundary = 'bottom'
    value = 0.0
  [../]
  [./Pressure]
    # [./loading]
    # function = loading_stress
    # boundary = 'top'
    # [../]
    [./confinement]
      function = confinement
      boundary = 'right'
      displacements = 'disp_x0 disp_y0'
    [../]
  [../]
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  type = Transient
  dt = 1
  l_max_its = 50
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-5
  nl_rel_tol = 1e-5
  reset_dt = true
  line_search = basic
  start_time = 0.0
  end_time = 2
[]

[Outputs]
  exodus = true
  file_base = compression
[]

[UserObjects]
  [./str]
    type = TensorMechanicsHardeningConstant
    value = 1
  [../]
  [./j2]
    type = TensorMechanicsPlasticJ2
    yield_strength = str
    yield_function_tolerance = 1E-9
    internal_constraint_tolerance = 1E-9
  [../]
[]

[Kernels]
  [./disp_y0]
    type = StressDivergenceTensors
    component = 1
    variable = disp_y0
    displacements = 'disp_x0 disp_y0'
    block = '0'
    base_name = 0
  [../]
  [./disp_x0]
    type = StressDivergenceTensors
    component = 0
    variable = disp_x0
    displacements = 'disp_x0 disp_y0'
    block = '0'
    base_name = 0
  [../]
[]
