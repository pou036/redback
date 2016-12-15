# This test involves only thermal expansion strains on a 2x2x2 cube of approximate
# steel material.  An initial temperature of 25 degrees C is given for the material,
# and an auxkernel is used to calculate the temperature in the entire cube to
# raise the temperature each time step.  After the first timestep,in which the
# temperature jumps, the temperature increases by 6.25C each timestep.
# The thermal strain increment should therefore be
# 6.25 C * 1.3e-5 1/C = 8.125e-5 m/m.

[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 2
  ny = 2
  nz = 2
[]

[GlobalParams]
  # displacements = 'disp_x disp_y disp_z'
  order = FIRST
  family = LAGRANGE
  time_factor = 1
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./temp]
    initial_condition = 300.0
  [../]
[]

[AuxVariables]
  # [./temp]
  # [../]
  [./strain_yy]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_xx]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_zz]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./temperature_load]
    type = ParsedFunction
    value = t*(500.0)+300.0
  [../]
[]

[Kernels]
  # [./TensorMechanics]
  # use_displaced_mesh = true
  # [../]
  active = 'forcing_fct_temp'
  [./td_temp]
    type = TimeDerivative
    variable = temp
  [../]
  [./forcing_fct_temp]
    type = RedbackVariableEqualsFunction
    variable = temp
    function = temperature_load
  [../]
[]

[AuxKernels]
  # [./tempfuncaux]
  # type = FunctionAux
  # variable = temp
  # function = temperature_load
  # use_displaced_mesh = false
  # [../]
  [./strain_xx]
    type = RankTwoAux
    rank_two_tensor = total_strain
    variable = strain_xx
    index_i = 0
    index_j = 0
  [../]
  [./strain_yy]
    type = RankTwoAux
    rank_two_tensor = total_strain
    variable = strain_yy
    index_i = 1
    index_j = 1
  [../]
  [./strain_zz]
    type = RankTwoAux
    rank_two_tensor = total_strain
    variable = strain_zz
    index_i = 2
    index_j = 2
  [../]
[]

[BCs]
  [./x_bot]
    type = DirichletBC
    variable = disp_x
    boundary = left
    value = 0.0
  [../]
  [./y_bot]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0.0
  [../]
  [./z_bot]
    type = DirichletBC
    variable = disp_z
    boundary = back
    value = 0.0
  [../]
[]

[Materials]
  [./mat_mech]
    type = RedbackMechMaterialElastic
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    youngs_modulus = 2.1e5
    poisson_ratio = 0.3
    total_porosity = 0
    temperature = temp
    temperature_reference = 298.0
  [../]
  [./mat_nomech]
    type = RedbackMaterial
    block = 0
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    ar = 0
    gr = 0
    total_porosity = 0
    is_mechanics_on = true
    solid_thermal_expansion = 1.3e-5
    temperature = temp
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  type = Transient
  solve_type = PJFNK
  petsc_options = -snes_ksp_ew
  petsc_options_iname = -ksp_gmres_restart
  petsc_options_value = 101
  line_search = none
  l_max_its = 50
  nl_max_its = 50
  nl_rel_tol = 1e-12
  nl_abs_tol = 1e-10
  l_tol = 1e-9
  start_time = 0.0
  end_time = 0.075
  dt = 0.0125
  dtmin = 0.0001
[]

[Outputs]
  csv = true
  exodus = true
  file_base = thermo_elasticity
[]

[Postprocessors]
  [./strain_xx]
    type = ElementAverageValue
    variable = strain_xx
    block = 0
  [../]
  [./strain_yy]
    type = ElementAverageValue
    variable = strain_yy
    block = 0
  [../]
  [./strain_zz]
    type = ElementAverageValue
    variable = strain_zz
    block = 0
  [../]
  [./temperature]
    type = AverageNodalVariableValue
    variable = temp
    block = 0
  [../]
[]

[RedbackMechAction]
  [./solid]
    disp_x = disp_x
    disp_y = disp_y
    disp_z = disp_z
    temp = temp
  [../]
[]

