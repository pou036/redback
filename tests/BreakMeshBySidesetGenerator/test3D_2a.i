# Test 3D case without boundary tags
[Mesh]
  [fmg]
    type = FileMeshGenerator
    file = 3Dcase2a.msh
  []
  [tag]
    type = AllSideSetsByNormalsShoeboxGenerator
    input = fmg
  []
  [rename]
    type = RenameBoundaryGenerator
    input = tag
    new_boundary = 'top bottom back front right left'
    old_boundary = '1 2 3 4 5 6'
  []
  [transform]
    type = TransformGenerator
    input = rename
    transform = SCALE
    vector_value = '1e-4 1e-4 1e-4'
  []
  [breakmesh]
    type = BreakMeshBySidesetGenerator
    input = transform
    boundaries = 'inexistant_tag_for_test_purposes' # 'bottom top left right front back'
    sidesets = 'surface_16 surface_18 surface_20 surface_22'
    split_interface = false
    create_lower_D_blocks = true
    connect_T_junctions = false
    verbose = true
  []
[]

[Variables]
  [dummy_var]
  []
[]

[AuxVariables]
  [lewis_fault1_trans]
    initial_condition = 100 #'0.1' # 1/D=1/10
  []
[]

[Kernels]
  [diff]
    type = CoeffParamDiffusion
    variable = dummy_var
    D = 1
  []
[]

[InterfaceKernels]
  [interface1]
    type = InterfaceDarcy
    variable = dummy_var
    neighbor_var = dummy_var
    boundary = 'interface'
    fault_lewis_number = lewis_fault1_trans
    fault_thickness = 0.01 # a
  []
[]

[Materials]
  [matrix]
    type = RedbackMaterial
    # just to get fluid_gravity_term
  []
[]

[BCs]
  [high]
    type = DirichletBC
    variable = dummy_var
    boundary = 'back'
    value = 1
  []
  [low]
    type = DirichletBC
    variable = dummy_var
    boundary = 'front'
    value = 0
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
  # dt = 0.1
  # end_time = 1
  petsc_options_iname = '-pc_type -pc_factor_mat_solver_package'
  # petsc_options_value = ' lu       mumps'
  petsc_options_value = ' lu       superlu_dist'
[]

[Outputs]
  file_base = test3D_2a
  exodus = false
  csv = true
[]

[VectorPostprocessors]
  # [sampler]
  #   type = LineValueSampler
  #   variable = 'dummy_var'
  #   start_point = '0.1 0.1 0.1'
  #   end_point = '0.9 0.9 0.9'
  #   num_points = 10
  #   sort_by = z
  # []
  [nodal_sample]
    type = NodalValueSampler
    sort_by = id
    variable = 'dummy_var'
  []
[]
