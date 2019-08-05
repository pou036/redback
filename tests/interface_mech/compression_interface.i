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
  [./disp_x1]
    block = '1'
  [../]
  [./disp_y0]
    block = '0'
  [../]
  [./disp_y1]
    block = '1'
  [../]
[]

[AuxVariables]
  [./stress_yy0]
    block = '0'
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./stress_yy1]
    block = '1'
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
  [./stress_yy1]
    type = RankTwoAux
    rank_two_tensor = 1_stress
    index_j = 1
    index_i = 1
    variable = stress_yy1
  [../]
[]

[MeshModifiers]
  [./subdomain]
    type = SubdomainBoundingBox
    bottom_left = '0 0.5 0'
    block_id = 1
    top_right = '1 1 0'
  [../]
  [./left_break]
    type = BreakBoundaryOnSubdomain
    depends_on = 'subdomain'
    boundaries = 'left'
  [../]
  [./right_break]
    type = BreakBoundaryOnSubdomain
    depends_on = 'subdomain'
    boundaries = 'right'
  [../]
  [./interface_bottom]
    type = SideSetsBetweenSubdomains
    master_block = '0'
    depends_on = 'subdomain'
    new_boundary = 'interface_bottom'
    paired_block = '1'
  [../]
  [./interface_top]
    type = SideSetsBetweenSubdomains
    master_block = '1'
    depends_on = 'subdomain'
    new_boundary = 'interface_top'
    paired_block = '0'
  [../]
[]

[InterfaceKernels]
  [./interface_x]
    type = InterfaceStress
    variable = disp_x0
    neighbor_var = disp_x1
    stress_master = 0_stress
    stress_slave = 1_stress
    boundary = interface_bottom
    component = 0
  [../]
  [./interface_y]
    type = InterfaceStress
    variable = disp_y0
    neighbor_var = disp_y1
    stress_master = 0_stress
    stress_slave = 1_stress
    boundary = interface_bottom
    component = 1
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
  [./Elasticity_tensor1]
    type = ComputeIsotropicElasticityTensor
    poissons_ratio = 0.3
    youngs_modulus = 10000
    block = 1
    base_name = 1
  [../]
  [./mc]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = 0
    base_name = 0
  [../]
  [./mc1]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = 1
    base_name = 1
  [../]
  [./small_strain0]
    type = ComputePlaneFiniteStrain
    block = '0'
    displacements = 'disp_x0 disp_y0'
    base_name = 0
  [../]
  [./small_strain1]
    type = ComputePlaneFiniteStrain
    displacements = 'disp_x1 disp_y1'
    block = '1'
    base_name = 1
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
    variable = disp_y1
    boundary = 'top'
    function = loading_vel
  [../]
  [./no_disp_x0]
    type = PresetBC
    variable = disp_x0
    boundary = 'left_to_0'
    value = 0.0
  [../]
  [./no_disp_x1]
    type = PresetBC
    variable = disp_x1
    boundary = 'left_to_1'
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
    [./confinement0]
      function = confinement
      boundary = 'right_to_0'
      displacements = 'disp_x0 disp_y0'
    [../]
    [./confinement1]
      function = confinement
      boundary = 'right_to_1'
      displacements = 'disp_x1 disp_y1'
    [../]
  [../]
  [./matchx]
    type = MatchedValueJumpBC
    variable = disp_x0
    boundary = 'interface_bottom'
    v = 'disp_x1'
    tangent_jump = 0
    fault_angle = 0
    component = 0
  [../]
  [./matchy]
    type = MatchedValueJumpBC
    variable = disp_y0
    boundary = 'interface_bottom'
    v = 'disp_y1'
    tangent_jump = 0
    fault_angle = 0
    component = 1
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
  file_base = compression_interface
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
  [./disp_x1]
    type = StressDivergenceTensors
    component = 0
    variable = disp_x1
    displacements = 'disp_x1 disp_y1'
    block = '1'
    base_name = 1
  [../]
  [./disp_y1]
    type = StressDivergenceTensors
    component = 1
    variable = disp_y1
    displacements = 'disp_x1 disp_y1'
    block = '1'
    base_name = 1
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
