[Mesh]
  type = FileMesh
  file = ../../meshes/cylinder_slim.msh
  dim = 2
[]

[MeshModifiers]
  [./middle_point]
    type = AddExtraNodeset
    new_boundary = 3
    tolerance = 1e-01
    coord = '0 0 0'
  [../]
[]

[Variables]
  [./temp]
  [../]
  [./disp_x]
    block = 0
  [../]
  [./disp_y]
    block = 0
  [../]
  [./pore_pressure]
  [../]
  [./disp_z]
  [../]
[]

[AuxVariables]
  [./porosity]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mises_strain]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mises_strain_rate]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mises_stress]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./td_temp]
    type = TimeDerivative
    variable = temp
  [../]
  [./diff_temp]
    type = Diffusion
    variable = temp
  [../]
  [./mh_temp]
    type = RedbackMechDissip
    variable = temp
  [../]
  [./td_press]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
  [./chem_press]
    type = RedbackChemPressure
    variable = pore_pressure
    block = 0
  [../]
  [./Chem_endo_temp]
    type = RedbackChemEndo
    variable = temp
    block = 0
  [../]
  [./poromech]
    type = RedbackPoromechanics
    variable = pore_pressure
  [../]
  [./thermal_pres]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temp
  [../]
[]

[AuxKernels]
  [./porosity]
    type = MaterialRealAux
    variable = porosity
    property = porosity
    block = 0
  [../]
  [./Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  [../]
  [./solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  [../]
  [./mises_strain_rate]
    type = MaterialRealAux
    variable = mises_strain_rate
    property = mises_strain_rate
  [../]
  [./mises_strain]
    type = MaterialRealAux
    variable = mises_strain
    property = mises_strain
  [../]
  [./mises_stress]
    type = MaterialRealAux
    variable = mises_stress
    property = mises_stress
  [../]
[]

[BCs]
  active = 'press_bc temp disp_x disp_y disp_z'
  [./disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 3
    value = 0
  [../]
  [./press_bc]
    type = DirichletBC
    variable = pore_pressure
    boundary = 0
    value = 0
  [../]
  [./high_temp]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2'
    value = 0.1
  [../]
  [./temp]
    type = DirichletBC
    variable = temp
    boundary = '1 2'
    value = 1
  [../]
  [./disp_z]
    type = DirichletBC
    variable = disp_z
    boundary = '1 2'
    value = 0
  [../]
  [./disp_x]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
[]

[Materials]
  [./adim_rock]
    type = RedbackMaterial
    block = 0
    m = 3
    mu = 1e-3
    ar = 10
    yield_stress = '0 1 1 1'
    gr = 1e-2
    pore_pres = pore_pressure
    temperature = temp
    is_mechanics_on = false
    ref_lewis_nb = 0.1
    Kc = 1e5
    ar_F = 20
    ar_R = 0
    phi0 = 0.1
    eta1 = 1e3
    Aphi = 1
    da_endo = 1e-4
    is_chemistry_on = true
    pressurization_coefficient = 1
    disp_z = disp_z
    disp_x = disp_x
    solid_thermal_expansion = 1e-5
    disp_y = disp_y
  [../]
  [./mech_mat]
    type = RedbackMechMaterialDP
    block = 0
    youngs_modulus = 1000
    exponent = 1
    disp_y = disp_y
    disp_x = disp_x
    pore_pres = pore_pressure
    yield_stress = '0 0.2 1 0.2'
    temperature = temp
    poisson_ratio = 0.3
    ref_pe_rate = 1
    disp_z = disp_z
  [../]
[]

[Postprocessors]
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0 0 0'
  [../]
  [./porosity_middle]
    type = PointValue
    variable = porosity
    point = '0 0 0'
  [../]
  [./Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0 0 0'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  [../]
  [./timestep]
    type = TimestepSize
  [../]
  [./num_nli]
    type = NumNonlinearIterations
  [../]
  [./mises_strain]
    type = PointValue
    variable = mises_strain
    point = '0 0 0'
  [../]
  [./mises_strain_rate]
    type = PointValue
    variable = mises_strain_rate
    point = '0 0 0'
  [../]
  [./mises_stress]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 10000
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  end_time = 7.5
  dtmax = 0.1
  scheme = bdf2
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    dt = 0.001
  [../]
[]

[Outputs]
  output_initial = true
  exodus = true
  file_base = experiment
  csv = true
[]

[ICs]
  [./temp_ic]
    variable = temp
    value = 0
    type = ConstantIC
    block = 0
  [../]
  [./press_ic]
    variable = pore_pressure
    type = ConstantIC
    value = 0
  [../]
[]

[RedbackAction]
  [./solid]
    disp_z = disp_z
    temp = temp
    disp_x = disp_x
    pore_pres = pore_pressure
    disp_y = disp_y
  [../]
[]

