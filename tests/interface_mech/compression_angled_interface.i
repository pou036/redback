[Mesh]
  type = FileMesh
  file = angled_interface.msh
[]

[Variables]
  [./disp_x0]
    block = 'bottom_block'
  [../]
  [./disp_x1]
    block = 'top_block'
  [../]
  [./disp_y0]
    block = 'bottom_block'
  [../]
  [./disp_y1]
    block = 'top_block'
  [../]
[]

[AuxVariables]
  [./stress_yy0]
    block = 'bottom_block'
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./stress_yy1]
    block = 'top_block'
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
  [./interface_bottom]
    type = SideSetsBetweenSubdomains
    master_block = 'bottom_block'
    new_boundary = 'interface_bottom'
    paired_block = 'top_block'
  [../]
  [./interface_top]
    type = SideSetsBetweenSubdomains
    master_block = 'top_block'
    new_boundary = 'interface_top'
    paired_block = 'bottom_block'
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
    block = bottom_block
    base_name = 0
  [../]
  [./Elasticity_tensor1]
    type = ComputeIsotropicElasticityTensor
    poissons_ratio = 0.3
    youngs_modulus = 10000
    block = top_block
    base_name = 1
  [../]
  [./mc]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = bottom_block
    base_name = 0
  [../]
  [./mc1]
    type = ComputeMultiPlasticityStress
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
    block = top_block
    base_name = 1
  [../]
  [./small_strain0]
    type = ComputePlaneFiniteStrain
    block = bottom_block
    displacements = 'disp_x0 disp_y0'
    base_name = 0
  [../]
  [./small_strain1]
    type = ComputePlaneFiniteStrain
    displacements = 'disp_x1 disp_y1'
    block = top_block
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
  # [./no_disp_x0]
  #   type = PresetBC
  #   variable = disp_x0
  #   boundary = 'left_to_0'
  #   value = 0.0
  # [../]
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
    # [./confinement0]
    #   function = confinement
    #   boundary = 'right_to_0'
    #   displacements = 'disp_x0 disp_y0'
    # [../]
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
    tangent_jump = 1e-4
    fault_angle = 26.56
    component = 0
  [../]
  [./matchy]
    type = MatchedValueJumpBC
    variable = disp_y0
    boundary = 'interface_bottom'
    v = 'disp_y1'
    tangent_jump = 1e-4
    fault_angle = 26.56 #tan-1(0.5/1)
    component = 1
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
  type = Transient
  dt = 0.1
  l_max_its = 50
  nl_max_its = 10
  solve_type = PJFNK
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
    block = bottom_block
    base_name = 0
  [../]
  [./disp_x1]
    type = StressDivergenceTensors
    component = 0
    variable = disp_x1
    displacements = 'disp_x1 disp_y1'
    block = top_block
    base_name = 1
  [../]
  [./disp_y1]
    type = StressDivergenceTensors
    component = 1
    variable = disp_y1
    displacements = 'disp_x1 disp_y1'
    block = top_block
    base_name = 1
  [../]
  [./disp_x0]
    type = StressDivergenceTensors
    component = 0
    variable = disp_x0
    displacements = 'disp_x0 disp_y0'
    block = bottom_block
    base_name = 0
  [../]
[]
