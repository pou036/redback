[Mesh]
  type = FileMesh
  file = ../second/cascadia_simple2.e
[]

[Variables]
  active = 'temp'
  [./pressure]
  [../]
  [./temp]
  [../]
[]

[Kernels]
  active = 'td_temp diff_temp mh_temp'
  [./td_temp]
    type = TimeDerivative
    variable = temp
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temp
  [../]
  [./mh_temp]
    type = MechHeat
    variable = temp
    ar = 5
    block = subduction_zone
  [../]
  [./td_pres]
    type = TimeDerivative
    variable = pressure
  [../]
[]

[BCs]
  [./surface_temp]
    type = DirichletBC
    variable = temp
    boundary = surface
    value = 0
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
  console = true
[]

[ICs]
  [./ic_temp]
    variable = temp
    type = ConstantIC
    value = 0
  [../]
[]

