[Mesh]
  type = FileMesh
  file = angled_interface.msh
[]

[MeshModifiers]
  [interface_bottom]
    type = SideSetsBetweenSubdomains
    master_block = 'bottom_block'
    new_boundary = 'interface_bottom'
    paired_block = 'top_block'
  []
  [interface_top]
    type = SideSetsBetweenSubdomains
    master_block = 'top_block'
    new_boundary = 'interface_top'
    paired_block = 'bottom_block'
  []
[]

[Variables]
  [disp0_x]
    block = 'bottom_block'
  []
  [disp1_x]
    block = 'top_block'
  []
  [disp0_y]
    block = 'bottom_block'
  []
  [disp1_y]
    block = 'top_block'
  []
[]

[AuxVariables]
  [stress0_yy]
    block = 'bottom_block'
    family = MONOMIAL
    order = CONSTANT
  []
  [stress1_yy]
    block = 'top_block'
    family = MONOMIAL
    order = CONSTANT
  []
[]

[AuxKernels]
  [stress0_yy]
    type = RankTwoAux
    rank_two_tensor = 0_stress
    index_j = 1
    index_i = 1
    variable = stress0_yy
  []
  [stress1_yy]
    type = RankTwoAux
    rank_two_tensor = 1_stress
    index_j = 1
    index_i = 1
    variable = stress1_yy
  []
[]

[InterfaceKernels]
  [interface_x]
    type = InterfaceStress
    variable = disp0_x
    neighbor_var = 'disp1_x'
    boundary = 'interface_bottom'
    component = 0
    base_name_master = 0
    base_name_slave = 1
    other_disp_master = 'disp0_y'
    other_disp_slave = 'disp1_y'
  []
  [interface_y]
    type = InterfaceStress
    variable = disp0_y
    neighbor_var = 'disp1_y'
    boundary = 'interface_bottom'
    component = 1
    base_name_master = 0
    base_name_slave = 1
    other_disp_master = 'disp0_x'
    other_disp_slave = 'disp1_x'
  []
[]

[Kernels]
  [disp0_x]
    type = StressDivergenceTensors
    component = 0
    variable = disp0_x
    displacements = 'disp0_x disp0_y'
    block = 'bottom_block'
    base_name = 0
  []
  [disp0_y]
    type = StressDivergenceTensors
    component = 1
    variable = disp0_y
    displacements = 'disp0_x disp0_y'
    block = 'bottom_block'
    base_name = 0
  []
  [disp1_x]
    type = StressDivergenceTensors
    component = 0
    variable = disp1_x
    displacements = 'disp1_x disp1_y'
    block = 'top_block'
    base_name = 1
  []
  [disp1_y]
    type = StressDivergenceTensors
    component = 1
    variable = disp1_y
    displacements = 'disp1_x disp1_y'
    block = 'top_block'
    base_name = 1
  []
[]

[Materials]
  [Elasticity_tensor]
    type = ComputeIsotropicElasticityTensor
    poissons_ratio = 0.3
    youngs_modulus = 10000
    block = 'bottom_block'
    base_name = 0
  []
  [Elasticity_tensor1]
    type = ComputeIsotropicElasticityTensor
    poissons_ratio = 0.3
    youngs_modulus = 10000
    block = 'top_block'
    base_name = 1
  []
  [mc]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = 'bottom_block'
    base_name = 0
  []
  [mc1]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = 'top_block'
    base_name = 1
  []
  [finite_strain0]
    type = ComputePlaneFiniteStrain
    block = 'bottom_block'
    displacements = 'disp0_x disp0_y'
    base_name = 0
  []
  [finite_strain1]
    type = ComputePlaneFiniteStrain
    displacements = 'disp1_x disp1_y'
    block = 'top_block'
    base_name = 1
  []
[]

[UserObjects]
  [str]
    type = TensorMechanicsHardeningConstant
    value = 1
  []
  [j2]
    type = TensorMechanicsPlasticJ2
    yield_strength = str
    yield_function_tolerance = 1E-9
    internal_constraint_tolerance = 1E-9
  []
[]

[Functions]
  [loading_vel]
    type = ParsedFunction
    value = '-0.0002*t'
  []
[]

[BCs]
  [uy_top]
    type = FunctionPresetBC
    variable = disp1_y
    boundary = 'top'
    function = loading_vel
  []
  [no_disp0_x]
    type = PresetBC
    variable = disp0_x
    boundary = 'left_to_0'
    value = 0.0
  []
  [no_disp_y]
    type = PresetBC
    variable = disp0_y
    boundary = 'bottom'
    value = 0.0
  []
  [matchx]
    type = MatchedValueJumpBC
    variable = disp0_x
    boundary = 'interface_bottom'
    v = 'disp1_x'
    tangent_jump = -2e-5
    component = 0
  []
  [matchy]
    type = MatchedValueJumpBC
    variable = disp0_y
    boundary = 'interface_bottom'
    v = 'disp1_y'
    tangent_jump = -2e-5
    component = 1
  []
[]

[Preconditioning]
  [SMP]
    type = SMP
    full = true
  []
[]

[Executioner]
  type = Transient
  dt = 0.1
  l_max_its = 50
  nl_max_its = 10
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-8
  nl_rel_tol = 1e-8
  reset_dt = true
  line_search = basic
  start_time = 0.0
  end_time = 0.2
[]

[Outputs]
  exodus = true
  file_base = compression_angled_interface
[]
