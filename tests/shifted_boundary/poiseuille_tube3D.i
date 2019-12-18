# This input file tests the behavior of NS equations

[GlobalParams]
  gravity = '0 0 0'
  laplace = true
  integrate_p_by_parts = false
  pspg = true
  alpha = 1e-1
  convective_term = false
  penalty = 2
  mesh_resolution = 0.08
  distance = d
[]

[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 10
  ny = 10
  nz = 2
  zmax = 0.2
  elem_type = HEX
  block_name = 'pores grains'
  block_id = '0 1'
  boundary_name = grains
  boundary_id = 10
[]

[MeshModifiers]
  [./image]
    type = ImageSubdomain
    file = tube/tube.png
    #file_base = ../output_files/tube/tube
    # file_suffix = png
    threshold = 100
  [../]
  [./interface]
    type = SideSetsBetweenSubdomains
    master_block = 0
    new_boundary = 10
    paired_block = 1
    depends_on = image
  [../]
  [./delete]
    type = BlockDeleter
    depends_on = interface
    block_id = 1
  [../]
[]

[Variables]
  [./vel_x]
    block = pores
  [../]
  [./vel_y]
    block = pores
  [../]
  [./vel_z]
    block = pores
  [../]
  [./p]
    block = pores
  [../]
[]

[Kernels]
  [./mass]
    type = INSMass
    variable = p
    u = vel_x
    v = vel_y
    w = vel_z
    p = p
    block = pores
  [../]
  [./x_momentum_space]
    type = INSMomentumLaplaceForm
    variable = vel_x
    u = vel_x
    v = vel_y
    w = vel_z
    p = p
    component = 0
    block = pores
  [../]
  [./y_momentum_space]
    type = INSMomentumLaplaceForm
    variable = vel_y
    u = vel_x
    v = vel_y
    w = vel_z
    p = p
    component = 1
    block = pores
  [../]
  [./z_momentum_space]
    type = INSMomentumLaplaceForm
    variable = vel_z
    u = vel_x
    v = vel_y
    w = vel_z
    p = p
    component = 2
    block = pores
  [../]
[]


[AuxVariables]
  [./d]
    family = LAGRANGE_VEC
  [../]
[]

[AuxKernels]
  [./distance]
    type = DistanceToInterfaceAux
    stl_name = "tube.stl"
    execute_on = 'INITIAL'
    variable = d
    boundary = grains
  [../]
[]

[Materials]
  [./const]
    type = GenericConstantMaterial
    block = pores
    prop_names = 'rho mu'
    prop_values = '1  1'
  [../]
[]

[Functions]
  # [perm_f]
  #   # resolution of image is 10.002 micrometer and we want perm in Darcy
  #   # (normalised by artificial coefficient to match with meso)
  #   type = ParsedFunction
  #   value = 'phi*v*0.2'
  #   vals = 'vol vel_avg'
  #   vars = 'phi v'
  # []
  [linear_p]
    type = ParsedFunction
    value = '1-z'
  []
[]

[ICs]
  [linear_p]
    type = FunctionIC
    function = linear_p
    variable = p
  []
[]

[BCs]
  [./x_no_slip_shifted]
    type = PenaltyShiftedDirichletBC #
    variable = vel_x
    boundary = 'grains'
    value = 0.0
  [../]
  [./y_no_slip_shifted]
    type = PenaltyShiftedDirichletBC
    variable = vel_y
    boundary = 'grains'
    value = 0.0
  [../]
  [./z_no_slip_shifted]
    type = PenaltyShiftedDirichletBC
    variable = vel_z
    boundary = 'grains'
    value = 0.0
  [../]
  [./x_no_slip]
    type = DirichletBC
    variable = vel_x
    boundary = 'back front'
    value = 0.0
  [../]
  [./y_no_slip]
    type = DirichletBC
    variable = vel_y
    boundary = 'back front'
    value = 0.0
  [../]
  [./lowp]
    type = DirichletBC
    variable = p
    boundary = front
    value = 0
  [../]
  [./inlet]
    type = DirichletBC
    variable = p
    boundary = back
    value = 1
  [../]
  # [inlet]
  #   type = NeumannBC
  #   variable = vel_z
  #   boundary = 'back'
  #   value = 1
  # []
[]

[Postprocessors]
  [./vol]
    type = VolumePostprocessor
    execute_on = initial
    block = pores
  [../]
  [./area]
    type = AreaPostprocessor
    execute_on = initial
    boundary = grains
  [../]
  [./integral_in]
    type = SideIntegralVariablePostprocessor
    variable = vel_z
    boundary = back
  [../]
  [./integral_out]
    type = SideIntegralVariablePostprocessor
    variable = vel_z
    boundary = front
  [../]
  [./vel_z_integral]
    type = ElementIntegralVariablePostprocessor
    variable = vel_z
    block = pores
  [../]
  [./vel_z_max]
    type = ElementExtremeValue
    value_type = max
    variable = vel_z
    block = pores
  [../]
  # [permeability]
  #   type = FunctionValuePostprocessor
  #   function = perm_f
  # []
  [mem]
    type = MemoryUsage
    mem_type = physical_memory
    execute_on = 'INITIAL TIMESTEP_END'
  []
[]

[Executioner]
  # This is setup automatically in MOOSE (SetupPBPAction.C)
  # petsc_options = '-snes_mf_operator'
  # petsc_options_iname = '-pc_type'
  # petsc_options_value =  'asm'
  # petsc_options_iname = '-pc_type -pc_asm_overlap -sub_pc_type -sub_pc_factor_levels'
  # petsc_options_value = 'asm      2               ilu          4'
  # line_search = 'none'
  # nl_rel_tol = 1e-12
  # nl_abs_tol = 1e-13
  # nl_max_its = 6
  # l_tol = 1e-6
  # l_max_its = 500
  # Solver tolerances and iteration limits
  # nl_rel_tol = 1e-8
  # nl_abs_tol = 1e-12
  # nl_max_its = 10
  # l_tol = 1e-6
  # l_max_its = 50 #10
  # line_search = none
  # # Options passed directly to PETSc
  # petsc_options = '-snes_converged_reason -ksp_converged_reason '
  # petsc_options_iname = '-pc_type -pc_factor_shift_type -pc_factor_mat_solver_package '
  # petsc_options_value = 'lu NONZERO superlu_dist '
  type = Steady #Transient
  nl_abs_tol = 1e-7
  solve_type = 'NEWTON'
  # line_search = 'bt'
[]

[Preconditioning]
  inactive = 'SMP_PJFNK FSP FSP2'
  [SMP_PJFNK]
    type = SMP
    full = true
    solve_type = NEWTON
  []
  [FSP]
    # It is the starting point of splitting
    type = FSP
    petsc_options = '-ksp_converged_reason -snes_converged_reason'
    petsc_options_iname = '-snes_type -ksp_type -ksp_rtol -ksp_atol -ksp_max_it -snes_atol -snes_rtol -snes_max_it -snes_max_funcs'
    petsc_options_value = 'newtonls     fgmres     1e-2     1e-15       200       1e-10        1e-15       200           100000'
    topsplit = 'uv'
    [uv]
      # Generally speaking, there are four types of splitting we could choose
      # <additive,multiplicative,symmetric_multiplicative,schur>
      # An approximate solution to the original system
      # | A_uu  A_uv | | u | _ |f_u|
      # |  0    A_vv | | v | - |f_v|
      # is obtained by solving the following subsystems
      # A_uu u = f_u and A_vv v = f_v
      # If splitting type is specified as schur, we may also want to set more options to
      # control how schur works using PETSc options
      # multiplicative
      petsc_options_iname = '-pc_fieldsplit_schur_fact_type -pc_fieldsplit_schur_precondition'
      petsc_options_value = 'upper selfp'
      splitting = 'u v' # 'u' and 'v'
      splitting_type = schur
    []
    [u]
      # PETSc options for this subsolver
      # A prefix will be applied, so just put the options for this subsolver only
      vars = 'vel_x vel_y vel_z'
      petsc_options_iname = '-pc_type -ksp_type -pc_hypre_type'
      petsc_options_value = '  hypre    preonly     boomeramg '
    []
    [v]
      # PETSc options for this subsolver
      vars = 'p'
      petsc_options_iname = '-pc_type -ksp_type -sub_pc_type -sub_pc_factor_levels'
      petsc_options_value = '  jacobi  preonly        ilu            3'
    []
  []
  [asm_ilu]
    type = SMP
    full = true
    solve_type = PJFNK
    petsc_options = '-ksp_converged_reason -snes_converged_reason' # -snes_monitor -snes_linesearch_monitor -ksp_monitor'
    petsc_options_iname = '-ksp_type -pc_type  -snes_atol -snes_rtol -snes_max_it -ksp_max_it -ksp_atol -sub_pc_type -sub_pc_factor_shift_type'
    petsc_options_value = 'gmres        asm        1E-8      1E-15        200        100         1e-8        lu                   NONZERO'
  []
  [./FSP2]
    type = FSP
    # It is the starting point of splitting
    topsplit = 'up' # 'up' should match the following block name
    [./up]
      splitting = 'u p' # 'u' and 'p' are the names of subsolvers
      splitting_type  = schur
      # Splitting type is set as schur, because the pressure part of Stokes-like systems
      # is not diagonally dominant. CAN NOT use additive, multiplicative and etc.
      # Original system:
      # | A B | | u | = | f_u |
      # | C 0 | | p |   | f_v |
      # is factorized into
      # |I        0 | | A    0|  | I  A^{-1}B | | u | = | f_u |
      # |CA^{-1}  I | | 0   -S|  | 0    I     | | p |   | f_v |
      # S = CA^{-1}B
      # The preconditioning is accomplished via the following steps
      # (1) p^{(0)} = f_v - CA^{-1}f_u,
      # (2) p = (-S)^{-1} p^{(0)}
      # (3) u = A^{-1}(f_u-Bp)
      petsc_options_iname = '-pc_fieldsplit_schur_fact_type  -pc_fieldsplit_schur_precondition'
      petsc_options_value = 'upper selfp'
      # Factorization type here is full, which means we approximate the original system
      # exactly. There are three other options:
      # diag:
      # | A    0|
      # | 0   -S|
      # lower:
      # |I        0  |
      # |CA^{-1}  -S |
      # upper:
      # | I  A^{-1}B |
      # | 0    -S    |
      # The preconditioning matrix is set as selfp, which means we explicitly form a
      # matrix \hat{S} = C(diag(A))^{-1}B. We do not compute the inverse of A, but instead, we compute
      # the inverse of diag(A).
    [../]
    [./u]
      vars = 'vel_x vel_y vel_z'
      # PETSc options for this subsolver
      # A prefix will be applied, so just put the options for this subsolver only
      petsc_options_iname = '-pc_type -ksp_type -ksp_rtol'
      petsc_options_value = '     hypre gmres 1e-4'
      # Specify options to solve A^{-1} in the steps (1), (2) and (3).
      # Solvers for A^{-1} could be different in different steps. We could
      # choose in the following pressure block.
    [../]
    [./p]
      vars = 'p'
      # PETSc options for this subsolver in the step (2)
      petsc_options_iname = '-pc_type -ksp_type -ksp_rtol'
      petsc_options_value = '   jacobi    gmres     1e-4'
      # Use -inner_ksp_type and -inner_pc_type to override A^{-1} in the step (2)
      # Use -lower_ksp_type and -lower_pc_type to override A^{-1} in the step (1)
    [../]
  [../]
[]

#[Problem]
#  type = FEProblem
#  material_coverage_check = false
#  kernel_coverage_check = false
#[]

[Outputs]
  file_base = poiseuille_tube3D
  #csv = true
  exodus = true
  #perf_graph = true
[]
