[Mesh]
  type = GeneratedMesh
  dim = 3
  xmin = -0.5
  xmax = 0.5
  ymin = -0.5
  ymax = 0.5
  zmin = -0.5
  zmax = 0.5
[]

[Variables]
  [./P]
  [../]
[]

[Functions]
  [./linear_fct]
    type = ParsedFunction
    value = t
  [../]
  [./cst_fct]
    type = ConstantFunction
    value = 1
  [../]
[]

[Kernels]
  [./dP_dt]
    type = TimeDerivative
    variable = P
  [../]
[]

[Postprocessors]
  active = 'center_P_point'
  [./center_P_point]
    type = PointValue
    variable = P
    point = '0 0 0 '
  [../]
  [./centre_P_elt]
    type = ElementalVariableValue
    variable = P
    elementid = 8
  [../]
  [./max_P_elt]
    type = ElementExtremeValue
    variable = P
  [../]
[]

[Executioner]
  type = Transient
  end_time = 10
[]

[Outputs]
  file_base = test_DK
  csv = true
[]

[DiracKernels]
  [./injection_DK]
    function = cst_fct
    variable = P
    type = FunctionPointSource
    point = '0 0 0'
  [../]
[]

