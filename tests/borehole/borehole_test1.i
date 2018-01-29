[Mesh]
  type = FileMesh
  file = Cylinder_hollow_iso.msh
  boundary_name = 'bottom top inside outside'
  boundary_id = '1 0 3 2'
[]

[GlobalParams]
  displacements = 'disp_x disp_y disp_z'
  porepressure = porepressure
  block = 0
[]

[Variables]
  [./disp_x]
    block = 0
  [../]
  [./disp_y]
    block = 0
  [../]
  [./disp_z]
    block = 0
  [../]
  [./porepressure]
    scaling = 1E9 # Notice the scaling, to make porepressure's kernels roughly of same magnitude as disp's kernels
    block = 0
  [../]
[]

[BCs]
  [./fixed_outer_x]
    type = PresetBC
    variable = disp_x
    value = 0
    boundary = outside
  [../]
  [./fixed_outer_y]
    type = PresetBC
    variable = disp_y
    value = 0
    boundary = outside
  [../]
  [./plane_strain]
    type = PresetBC
    variable = disp_z
    value = 0
    boundary = 'top bottom'
  [../]
  [./borehole_wall]
    type = DirichletBC
    variable = porepressure
    value = 1e-2
    boundary = inside
  [../]
[]

[Kernels]
  [./dp_dt]
    type = TimeDerivative
    variable = porepressure
    block = 0
  [../]
  [./mass_diff]
    type = RedbackMassDiffusion
    variable = porepressure
  [../]
  [./poromech]
    type = RedbackPoromechanics
    variable = porepressure
  [../]
[]

[Materials]
  active = 'no_mech plastic_material'
  [./no_mech]
    type = RedbackMaterial
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_y
    pore_pres = porepressure
    total_porosity = 0.1
    phi0 = 0.1
  [../]
  [./elastic_material]
    type = RedbackMechMaterialElastic
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    poisson_ratio = 0.25
    youngs_modulus = 100
    outputs = all
  [../]
  [./plastic_material]
    type = RedbackMechMaterialJ2
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
    outputs = all
    pore_pres = porepressure
    yield_stress = '0 0.006 1 0.006'
    poisson_ratio = 0.25
    youngs_modulus = 100
  [../]
[]

[Postprocessors]
  [./Int_PoreP]
    type = PointValue
    variable = porepressure
    point = '0.1 0 0.1'
    execute_on = timestep_begin
  [../]
  [./PorePress]
    type = PointValue
    variable = porepressure
    point = '0.2 0 0.1'
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    # gmres asm 1E0 1E-10 200 500 lu NONZERO
    type = SMP
    full = true
    solve_type = PJFNK
    petsc_options = '-snes_monitor -snes_linesearch_monitor -ksp_monitor'
    petsc_options_iname = '-ksp_type -pc_type  -snes_atol -snes_rtol -snes_max_it -ksp_max_it -ksp_atol -sub_pc_type -sub_pc_factor_shift_type'
    petsc_options_value = 'gmres        asm        1E-2          1E-10        200                500                  1e-4        lu                      NONZERO'
  [../]
  [./manolis]
    type = SMP
    solve_type = NEWTON
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
  [../]
  [./default]
    type = SMP
    solve_type = NEWTON
  [../]
  [./Manman]
    type = SMP
    solve_type = NEWTON
    petsc_options_iname = '-ksp_type -pc_type -snes_atol -snes_rtol -snes_max_it'
    petsc_options_value = 'bcgs bjacobi 1E-14 1E-10 10000'
  [../]
[]

[Executioner]
  # [./TimeStepper]
  # type = PostprocessorDT
  # postprocessor = dt
  # dt = 0.003
  # [../]
  type = Transient
  l_max_its = 100
  end_time = 0.3
  dt = 1e-5
  l_tol = 1e-5 # 1e-05
[]

[Outputs]
  active = 'exodus'
  execute_on = timestep_end
  file_base = borehole_test1
  sync_times = '0.003 0.3'
  [./csv_p]
    file_base = borehole_highres_p
    type = CSV
  [../]
  [./csv_s]
    file_base = borehole_highres_s
    type = CSV
  [../]
  [./csv_t]
    file_base = borehole_highres_t
    type = CSV
  [../]
  [./exodus]
    type = Exodus
    elemental_as_nodal = true
  [../]
[]

[RedbackMechAction]
  [./mechanics]
    disp_z = disp_z
    pore_pres = porepressure
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

