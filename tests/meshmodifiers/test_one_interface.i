[Mesh]
  file = test.msh
[]

[MeshModifiers]
  [New_0]
    type = InterfaceFromSideset
    sidesets = 'ss3'
    boundaries = 'left right top bottom'
  []
[]

[Outputs]
  exodus = true
  file_base = myoutput
[]
