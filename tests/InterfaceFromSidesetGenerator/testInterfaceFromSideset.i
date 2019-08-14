# Test for InterfaceFromSideset MeshModifier on 2D block
# with simple X fractures (touching all sides)

[MeshGenerators]
  [./fmg]
    type = FileMeshGenerator
    file = fractureX.msh
  []

  [./create_interfaces]
    type = InterfaceFromSidesetGenerator
    input = fmg
    sidesets = 'ss2 ss3'
    boundaries = 'left right top bottom'
  []
[]

[Mesh]
  type = MeshGeneratorMesh
[]
