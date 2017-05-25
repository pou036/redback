[Mesh]
  type = GeneratedMesh
  dim = 3
[]

[Variables]
  active = 'y diffused z'
  [./diffused]
    order = FIRST
    family = LAGRANGE
  [../]
  [./z]
  [../]
  [./y]
    family = SCALAR
    initial_condition = 1.234
  [../]
  [./my_unused_scalarvar]
    family = SCALAR
  [../]
[]

[Functions]
  [./init_gradient]
    type = ParsedFunction
    value = z
  [../]
[]

[Kernels]
  active = 'diff td_z'
  [./diff]
    type = Diffusion
    variable = diffused
  [../]
  [./test]
    type = RedbackOffDiagonalScalarJacobian
    variable = diffused
    normal_variable = z
    scalar_variable = y
  [../]
  [./td_z]
    type = TimeDerivative
    variable = z
  [../]
[]

[BCs]
  [./bottom]
    type = DirichletBC
    variable = diffused
    boundary = bottom
    value = 1
  [../]
  [./top]
    type = DirichletBC
    variable = diffused
    boundary = top
    value = 0
  [../]
[]

[Preconditioning]
  [./smp]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1
  solve_type = PJFNK
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
[]

[ICs]
  [./diffused_init]
    function = init_gradient
    variable = diffused
    type = FunctionIC
  [../]
[]

[ScalarKernels]
  [./td_y]
    variable = y
    type = ODETimeDerivative
  [../]
  [./offidiag]
    variable = y
    type = RedbackOffDiagonalNonScalar
    non_scalar_variable = diffused
    x_older = z
    x_old = diffused
    x = diffused
  [../]
[]

