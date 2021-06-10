[Mesh]
  type = GeneratedMesh
  dim = 2
  xmin = 0
  xmax = 1
  ymin = 0
  ymax = 1
  nx = 10
  ny = 10
[]

[Variables]
  [dummy]
    order = FIRST
    family = LAGRANGE
  []
[]

[AuxVariables]
  [potential]
    family = LAGRANGE
    order = FIRST
  []
  [k_xx]
    family = MONOMIAL
    order = CONSTANT
  []
  [k_xy]
    family = MONOMIAL
    order = CONSTANT
  []
  [k_yy]
    family = MONOMIAL
    order = CONSTANT
  []
[]

[Kernels]
  [diff_dummy]
    type = Diffusion
    variable = dummy
  []
[]

[Functions]
  [set_potential]
    type = ParsedFunction
    value = 'x+y'
  []
[]

[GlobalParams]
  # Parameters for the three anisotropic AuxKernels
  potential_field = potential
  function_long = '10*potential*potential' # uses the name of the fault_normal_field variable
  function_tran = '2*potential*potential' # uses the name of the fault_normal_field variable
[]

[AuxKernels]
  [potential_kernel]
    type = FunctionAux
    variable = potential
    function = set_potential
    execute_on = 'initial'
  []
  [k_xx]
    type = RedbackAnisotropicTensorAux
    variable = k_xx
    row = x
    column = x
    execute_on = 'FINAL'
  []
  [k_xy]
    type = RedbackAnisotropicTensorAux
    variable = k_xy
    row = x
    column = y
    execute_on = 'FINAL'
  []
  [k_yy]
    type = RedbackAnisotropicTensorAux
    variable = k_yy
    row = y
    column = y
    execute_on = 'FINAL'
  []
[]

[BCs]
  [left_dummy]
    type = DirichletBC
    variable = dummy
    boundary = 'left'
    value = 0
  []

  [right_dummy]
    type = DirichletBC
    variable = dummy
    boundary = 'right'
    value = 1
  []
[]

[Executioner]
  type = Steady
  solve_type = 'PJFNK'
[]

[Outputs]
  file_base = anisotropic_tensor_aux
  exodus = true
  execute_on = 'FINAL'
[]
