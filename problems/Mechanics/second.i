[Mesh]
  type = FileMesh
  file = first_cp/0001_mesh.cpr
  displacements = 'x_disp y_disp z_disp'
  distribution = SERIAL
[]

[Variables]
  [./x_disp]
    order = FIRST
    family = LAGRANGE
  [../]
  [./y_disp]
    order = FIRST
    family = LAGRANGE
  [../]
  [./z_disp]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Functions]
  [./top_func]
    type = ParsedFunction
    value = -0.002 - 0.0001*t
  [../]
[]

[Kernels]
  [./TensorMechanics]
    disp_x = x_disp
    disp_y = y_disp
    disp_z = z_disp
    use_displaced_mesh = true
  [../]
[]

[Materials]
  [./rock]
    type = LinearElasticMaterial
    block = 0
    disp_z = z_disp
    disp_y = y_disp
    disp_x = x_disp
    C_ijkl = '2.827e5 1.21e5 1.21e5 2.827e5 1.21e5 2.827e5 0.808e5 0.808e5 0.808e5'
  [../]
[]

[BCs]
  active = 'bottom1 bottom2 bottom3 top_disp_fct'
  [./bottom1]
    type = PresetBC
    variable = x_disp
    boundary = bottom
    value = 0
  [../]
  [./bottom2]
    type = PresetBC
    variable = y_disp
    boundary = bottom
    value = 0
  [../]
  [./bottom3]
    type = PresetBC
    variable = z_disp
    boundary = bottom
    value = 0.0
  [../]
  [./top_confinement]
    type = NeumannBC
    variable = y_disp
    boundary = top
    value = -500
  [../]
  [./top_disp_fct]
    type = FunctionPresetBC
    variable = y_disp
    boundary = top
    function = top_func
  [../]
[]

[AuxVariables]
  [./stress_zz]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[AuxKernels]
  [./stress_zz]
    type = RankTwoAux
    rank_two_tensor = stress
    variable = stress_zz
    index_i = 2
    index_j = 2
  [../]
[]

[Postprocessors]
  [./top_disp]
    type = PointValue
    variable = y_disp
    point = '0.5 1 0.5'
  [../]
  [./stress_zz_centre]
    type = PointValue
    variable = stress_zz
    point = '0.5 0.5 0.5'
  [../]
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  start_time = 1
  end_time = 5
  type = Transient
  l_max_its = 200
  nl_max_its = 10
  restart_file_base = first_cp/0001
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-10
[]

[Outputs]
  file_base = second_out
  output_initial = true
  exodus = true
  csv = true
[]

