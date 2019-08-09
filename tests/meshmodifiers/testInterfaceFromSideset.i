# Test for InterfaceFromSideset MeshModifier on 2D block
# with simple X fractures (touching all sides)

[Mesh]
  file = ../../meshes/fractureX.msh
[]

[MeshModifiers]
  [New_0]
    type = InterfaceFromSideset
    sidesets = 'ss2 ss3'
    boundaries = 'left right top bottom'
  []
[]
