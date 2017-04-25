# undrained oedometric test, similar to the one used in Redback
# 

[Mesh]
  type = GeneratedMesh
  dim = 3
  xmin = -0.5
  xmax = 0.5
  ymin = -0.5
  ymax = 0.5
  zmin = -5
  zmax = 5
  nz = 40
[]

[Variables]
  active = 'pore_pressure'
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
  [./pore_pressure]
  [../]
[]

[GlobalParams]
  pore_pres = pore_pressure
[]

[Materials]
  active = 'mat_nomech'
  [./mat_mech]
    type = RedbackMechMaterialHO
    block = 0
    exponent = 0
    fill_method = general_isotropic
    B_ijkl = '1 1 1'
    cohesion = 100
    C_ijkl = '1 1.5 0.75'
    plasticity_type = DeBorst_2D
    beta_star = 2
  [../]
  [./mat_nomech]
    # 3.7037
    type = RedbackMaterial
    block = 0
    eta1 = 0
    gr = 0
    total_porosity = 1
    solid_density = 0
    confining_pressure = 0
    delta = 0
    fluid_density = 0
    eta2 = 0
    solid_compressibility = 0 # 1/(0.9*0.3)
    solid_thermal_expansion = 2.5E-3
    ref_lewis_nb = 1
  [../]
[]

[BCs]
  active = 'pres_0'
  [./confinex]
    type = PresetBC
    variable = disp_x
    boundary = left
    value = 0
  [../]
  [./confiney]
    type = PresetBC
    variable = disp_y
    value = 0
    boundary = bottom
  [../]
  [./basefixed_z]
    type = PresetBC
    variable = disp_z
    boundary = back
    value = 0
  [../]
  [./top_velocity]
    type = FunctionDirichletBC
    variable = disp_z
    boundary = front
    function = -0.01*t
  [../]
  [./pres_0]
    type = DirichletBC
    variable = pore_pressure
    boundary = back
    value = 0.01
  [../]
[]

[Kernels]
  active = 'td_pres p_diff'
  [./td_pres]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./poromech]
    type = RedbackPoroMechHO
    variable = pore_pressure
  [../]
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
  [../]
  [./x_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_x
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    component = 0
    base_name = coupled
    disp_z = wc_y
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./y_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_y
    component = 1
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./z_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_z
    component = 2
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./x_moment]
    type = RedbackMomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = RedbackMomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = RedbackMomentBalancing
    variable = wc_z
    component = 2
  [../]
  [./p_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
[]

[Postprocessors]
  active = 'p0'
  [./p0]
    type = PointValue
    point = '0 0 0'
    variable = pore_pressure
  [../]
  [./zdisp]
    type = PointValue
    point = '0 0 0.5'
    variable = disp_z
  [../]
  [./strain_zz]
    type = PointValue
    point = '0 0 0'
    variable = strain_zz
  [../]
  [./stress_xx]
    type = PointValue
    point = '0 0 0'
    variable = stress_11
  [../]
  [./stress_yy]
    type = PointValue
    point = '0 0 0'
    variable = stress_22
  [../]
  [./stress_zz]
    type = PointValue
    point = '0 0 0'
    variable = stress_33
  [../]
  [./temperature]
    type = PointValue
    variable = temp
    point = '0 0 0'
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
  end_time = 200
  dt = 10
[]

[Outputs]
  exodus = true
  execute_on = 'timestep_end initial'
  file_base = bench_HM_diff
  csv = true
[]

