[Mesh]
  type = GeneratedMesh
  dim = 3
  xmin = -0.5
  xmax = 0.5
  ymin = -0.5
  ymax = 0.5
  zmin = -5
  zmax = 5
  nz = 4
[]

[Variables]
  [./temperature]
  [../]
[]

[Materials]
  [./mat_nomech]
    type = RedbackMaterial
    block = 0
    eta1 = 0
    gr = 0
    total_porosity = 0.1
    Peclet_number = 1
    solid_density = 0
    confining_pressure = 0
    delta = 0
    fluid_density = 0
    eta2 = 0
    solid_compressibility = 0 # 1/(0.9*0.3)
    solid_thermal_expansion = 2.5E-3
  [../]
[]

[BCs]
  active = 'temp_imposed'
  [./confinex]
    type = PresetBC
    variable = disp_x
    boundary = 'left right'
    value = 0
  [../]
  [./confiney]
    type = PresetBC
    variable = disp_y
    value = 0
    boundary = 'bottom top'
  [../]
  [./basefixed_z]
    type = PresetBC
    variable = disp_z
    boundary = back
    value = 0
  [../]
  [./temp_imposed]
    type = FunctionDirichletBC
    variable = temperature
    boundary = front
    function = 1
  [../]
[]

[Kernels]
  [./td_pres]
    type = TimeDerivative
    variable = temperature
  [../]
  [./diffusion]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
[]

[Postprocessors]
  [./temperature0]
    type = PointValue
    variable = temperature
    point = '0 0 -5'
  [../]
  [./temperature1]
    type = PointValue
    variable = temperature
    point = '0 0 -2.5'
  [../]
  [./temperature2]
    type = PointValue
    variable = temperature
    point = '0 0 0'
  [../]
  [./temperature3]
    type = PointValue
    variable = temperature
    point = '0 0 2.5'
  [../]
  [./temperature4]
    type = PointValue
    variable = temperature
    point = '0 0 5'
  [../]
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
    solve_type = NEWTON
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
  [../]
[]

[Executioner]
  type = Transient
  solve_type = Newton
  end_time = 500
  dt = 50
[]

[Outputs]
  exodus = true
  execute_on = 'timestep_end initial'
  file_base = bench_TM_test
  csv = true
[]

