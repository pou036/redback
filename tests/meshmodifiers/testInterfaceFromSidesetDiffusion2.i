[Mesh]
  type = FileMesh
  file = ../../meshes/fractureX.msh
[]

[MeshModifiers]
  [break]
    type = InterfaceFromSideset
    boundaries = 'top bottom left right'
    sidesets =  'ss2 ss3'
    split_interface = false
  []
[]

[Variables]
  [dymmy_var]
  []
[]

[Kernels]
  [diff]
    type = Diffusion
    variable = dymmy_var
  []
[]

[BCs]
  [left]
    type = DirichletBC
    variable = dymmy_var
    boundary = 'left'
    value = 0
  []
  [right]
    type = DirichletBC
    variable = dymmy_var
    boundary = 'right'
    value = 1
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
[]

[Outputs]
  file_base = testInterfaceFromSidesetDiffusion2
  exodus = true
[]
