gravity = '0.56 0.98 0'

[Mesh]
  type = FileMesh
  file = angled_interface.msh
[]

[MeshModifiers]
  [./interface_left]
    type = SideSetsBetweenSubdomains
    master_block = 'left_block'
    new_boundary = 'interface_left'
    paired_block = 'right_block'
  [../]
  [./interface_right]
    type = SideSetsBetweenSubdomains
    master_block = 'right_block'
    new_boundary = 'interface_right'
    paired_block = 'left_block'
  [../]
[]

[Variables]
  [./p_left]
    order = FIRST
    family = LAGRANGE
    block = left_block
  [../]
  [./p_right]
    order = FIRST
    family = LAGRANGE
    block = right_block
  [../]
[]

[AuxVariables]
  [./lewis_fault]
  [../]
[]

[Kernels]
  [./diff_left]
    type = RedbackMassDiffusion
    variable = p_left
    block = 'left_block'
  [../]
  [./diff_right]
    type = RedbackMassDiffusion
    variable = p_right
    block = 'right_block'
  [../]
[]

[InterfaceKernels]
  [./interface]
    type = InterfaceDarcy
    variable = p_left
    neighbor_var = 'p_right'
    boundary = 'interface_left'
    fault_lewis_number = lewis_fault
    fault_thickness = 0.1
  [../]
[]

[Materials]
  [./mat]
    type = RedbackMaterial
    ref_lewis_nb = 1
    gravity = ${gravity}
  [../]
[]

[ICs]
  [./lewis_fault]
    type = ConstantIC
    variable = lewis_fault
    value = 10
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = p_left
    boundary = 'left'
    value = 1
  [../]
  [./right]
    type = DirichletBC
    variable = p_right
    boundary = 'right'
    value = 0
  [../]
  [./middle_left]
    type = DarcyFluxBC
    variable = p_left
    boundary = interface_left
  [../]
  [./middle_right]
    type = DarcyFluxBC
    variable = p_right
    boundary = interface_right
  [../]
[]

[Postprocessors]
  [p_left]
    type = SideAverageValue
    variable = 'p_left'
    boundary = 'interface_left'
  []
  [p_right]
    type = SideAverageValue
    variable = 'p_right'
    boundary = 'interface_right'
  []
[]

[Preconditioning]
  [./smp]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  type = Steady
[]

[Outputs]
  file_base = interface_darcy_grav_test
  csv = true
[]
