[Mesh]
  type = FileMesh
  file = test2.msh
[]

[MeshModifiers]
  # [subdomain]
  #   type = SubdomainBoundingBox
  #   bottom_left = '0 0.5 0'
  #   block_id = 1
  #   top_right = '1 1 0'
  # []
  [break]
    type = InterfaceFromSideset
    boundaries = 'top bottom left right'
    sidesets =  'ss2 ss3'
    split_interface = false
  []
[]

[Variables]
  [p]
  []
[]

[AuxVariables]
  [lewis_fault]
  []
[]

[Kernels]
  [diff]
    type = RedbackMassDiffusion
    variable = p
  []
[]

[InterfaceKernels]
  [interface_ss2]
    type = InterfaceDarcy
    variable = p
    neighbor_var = p
    boundary = interface_ss2
    fault_lewis_number = lewis_fault
    fault_thickness = 0.1
  []
  [interface_ss3]
    type = InterfaceDarcy
    variable = p
    neighbor_var = p
    boundary = interface_ss3
    fault_lewis_number = lewis_fault
    fault_thickness = 0.05
  []
[]

[Materials]
  [mat]
    type = RedbackMaterial
    pore_pres = p
    ref_lewis_nb = 1
    are_convective_terms_on = true
    outputs = all
    solid_compressibility = 1
    total_porosity =  0.1
  []
[]

[ICs]
  [lewis_fault]
    type = ConstantIC
    variable = lewis_fault
    value = 1
  []
[]

[BCs]
  [left]
    type = DirichletBC
    variable = p
    boundary = 'left'
    value = 1
  []
  [right]
    type = DirichletBC
    variable = p
    boundary = 'right'
    value = 0
  []
[]

[Postprocessors]
  [p]
    type = NodalVariableValue
    nodeid = 5
    variable = p
  []
[]

[Preconditioning]
  [smp]
    type = SMP
    full = true
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
[]

[Outputs]
  file_base = interface_test
  csv = true
  exodus = true
[]
