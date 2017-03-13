[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 4
  ny = 4
  xmin = -1
  ymin = -1
  elem_type = QUAD4
[]

[Variables]
  active = 'disp_y disp_x'
  [./disp_x]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_y]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_z]
    order = FIRST
    family = LAGRANGE
  [../]
  [./temp]
  [../]
[]

[Materials]
  [./mat_mech]
    type = RedbackMechMaterialElastic
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    poisson_ratio = 0.3
    youngs_modulus = 1000
  [../]
  [./mat_nomech]
    type = RedbackMaterial
    block = 0
    is_mechanics_on = true
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

[BCs]
  active = 'force_right Fix_left_x Fix_left_y'
  [./left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
  [./left_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 3
    value = 0
  [../]
  [./rigth_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 1
    value = 0
  [../]
  [./temp_box]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2 3'
    value = 0
  [../]
  [./force_right]
    type = FunctionNeumannBC
    variable = disp_x
    boundary = 1
    function = BC_force_right
  [../]
  [./Fix_left_x]
    type = DirichletBC
    variable = disp_x
    boundary = left
    value = 0
  [../]
  [./Fix_left_y]
    type = DirichletBC
    variable = disp_y
    boundary = left
    value = 0
  [../]
[]

[AuxVariables]
  [./mises_stress]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./mean_stress]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./BC_force_right]
    type = ParsedFunction
    value = -100*t
  [../]
[]

[Kernels]
[]

[AuxKernels]
  [./mises_stress_ker]
    type = MaterialRealAux
    variable = mises_stress
    property = mises_stress
    execute_on = 'LINEAR timestep_end'
  [../]
  [./mean_stress_ker]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
  [../]
[]

[Postprocessors]
  [./mean_stress]
    type = PointValue
    variable = mean_stress
    execute_on = 'TIMESTEP_END custom'
    point = '0 0 0 '
  [../]
  [./mises_stress]
    type = ElementalVariableValue
    variable = mises_stress
    execute_on = timestep_end
    elementid = 10
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 1000
  nl_abs_tol = 1e-12
  end_time = 5
  [./TimeStepper]
    type = ConstantDT
    dt = 1
  [../]
[]

[Outputs]
  exodus = true
  file_base = bench_abaqus_elastic_04
  csv = true
[]

[RedbackMechAction]
  [./action]
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

