[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 6
  ny = 6
  ymin = 0
  ymax = 10
  nz = 1
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
[]

[Postprocessors]
  [./disp_y_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = disp_y
  [../]
  [./disp_x_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = disp_x
  [../]
  [./wc_z_top]
    type = PointValue
    point = '0.5 1 0.1'
    variable = wc_z
  [../]
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./wc_x]
  [../]
  [./wc_y]
  [../]
  [./wc_z]
  [../]
[]

[Functions]
  [./velocity_function]
    type = ParsedFunction
    value = 1*t
  [../]
[]

[Kernels]
  [./cx_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_x
    component = 0
  [../]
  [./cy_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_y
    component = 1
  [../]
  [./cz_elastic]
    type = CosseratStressDivergenceTensors
    variable = disp_z
    component = 2
  [../]
  [./x_couple]
    type = StressDivergenceTensors
    variable = wc_x
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
    component = 0
    base_name = coupled
  [../]
  [./y_couple]
    type = StressDivergenceTensors
    variable = wc_y
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
    component = 1
    base_name = coupled
  [../]
  [./z_couple]
    type = StressDivergenceTensors
    variable = wc_z
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
    component = 2
    base_name = coupled
  [../]
  [./x_moment]
    type = MomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = MomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = MomentBalancing
    variable = wc_z
    component = 2
  [../]
[]

[BCs]
  # following is natural BC
  active = 'Periodic uy_bottom wcx_equals_zero_on_top wcy_equals_zero_on_top top_cauchy_zero wcz_equals_zero_on_top ux_equals_zero_on_top wc_x_bottom uz_bottom wc_y_bottom wc_z_bottom ux_bottom_vel'
  [./Periodic]
    active = 'zperiodic xperiodic'
    [./xperiodic]
      auto_direction = x
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
    [../]
    [./zperiodic]
      auto_direction = z
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
    [../]
    [./xperiodic2]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
      translation = '1 0 0'
      secondary = right
      primary = left
    [../]
    [./zperiodic2]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
      translation = '0 0 1'
      secondary = front
      primary = back
    [../]
  [../]
  [./ux_equals_zero_on_top]
    type = DirichletBC
    variable = disp_x
    boundary = top
    value = 0
  [../]
  [./wcx_equals_zero_on_top]
    type = DirichletBC
    variable = wc_x
    boundary = top
    value = 0
  [../]
  [./wcy_equals_zero_on_top]
    type = DirichletBC
    variable = wc_y
    boundary = top
    value = 0
  [../]
  [./wcz_equals_zero_on_top]
    type = DirichletBC
    variable = wc_z
    boundary = top
    value = 0
  [../]
  [./top_cauchy_zero]
    type = NeumannBC
    variable = disp_x
    boundary = top
    value = 0
  [../]
  [./ux_bottom]
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 1.0
  [../]
  [./uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0.0
  [../]
  [./uz_bottom]
    type = DirichletBC
    variable = disp_z
    boundary = bottom
    value = 0.0
  [../]
  [./wc_x_bottom]
    type = DirichletBC
    variable = wc_x
    boundary = bottom
    value = 0.0
  [../]
  [./wc_y_bottom]
    type = DirichletBC
    variable = wc_y
    boundary = bottom
    value = 0.0
  [../]
  [./wc_z_bottom]
    type = DirichletBC
    variable = wc_z
    boundary = bottom
    value = 0.17
  [../]
  [./ux_bottom_vel]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = bottom
    function = velocity_function
  [../]
[]

[Materials]
  [./cosserat]
    type = CosseratLinearElasticMaterial
    block = 0
    B_ijkl = 40
    C_ijkl = '5 10 5'
    fill_method = general_isotropic
  [../]
[]

[Preconditioning]
  [./andy]
    # petsc_options = '-snes_test_display'
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres bjacobi 1E-10 1E-10 10 1E-15 1E-10'
  [../]
[]

[Executioner]
  type = Transient
  dt = 0.1
  solve_type = Newton
  num_steps = 10
[]

[Outputs]
  output_initial = true
  exodus = true
  print_perf_log = true
[]

