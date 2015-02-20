[Mesh]
  type = FileMesh
  file = ../../meshes/Cylinder_hollow_reg.msh
  dim = 2
[]

[Variables]
  [./temp]
  [../]
  [./disp_x]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./disp_y]
    order = CONSTANT
    family = MONOMIAL
    block = 0
  [../]
  [./pore_pressure]
  [../]
  [./disp_z]
    order = CONSTANT
    family = MONOMIAL
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
  [./strain_rate]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./Loading]
    type = ParsedFunction
    value = 0.00001*t
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
  [./strain_rate]
    type = MaterialRealAux
    variable = strain_rate
    property = mises_strain_rate
  [../]
  [./solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  [../]
[]

[BCs]
  active = 'low_temp disp_y disp_z disp_x press_bc Inner_loading_x'
  [./disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 2
    value = 0
  [../]
  [./press_bc]
    type = DirichletBC
    variable = pore_pressure
    boundary = 2
    value = 0
  [../]
  [./low_temp]
    type = DirichletBC
    variable = temp
    boundary = 2
    value = 0
  [../]
  [./high_temp]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2'
    value = 0.1
  [../]
  [./disp_z]
    type = DirichletBC
    variable = disp_z
    boundary = 2
    value = 0
  [../]
  [./disp_x]
    type = DirichletBC
    variable = disp_x
    boundary = 2
    value = 0
  [../]
  [./Inner_loading_x]
    type = NeumannBC
    variable = disp_x
    boundary = 3
    value = 1
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
    gr = 11
    pore_pres = pore_pressure
    temperature = temp
    is_mechanics_on = false
    ref_lewis_nb = 1
    Kc = 10
    ar_F = 20
    ar_R = 10
    phi0 = 0.1
    eta1 = 1e3
    Aphi = 1
    da_endo = 1e-4
    is_chemistry_on = true
  [../]
  [./Rock_mechanics]
    type = RedbackMechMaterialJ2
    block = 0
    youngs_modulus = 10
    exponent = 3
    disp_y = disp_y
    disp_x = disp_x
    pore_pres = pore_pressure
    yield_stress = '0 1 1 1'
    temperature = temp
    poisson_ratio = 0.25
    ref_pe_rate = 1
    disp_z = disp_z
  [../]
[]

[Postprocessors]
  active = 'solid_ratio_middle strain_rate_middle middle_press Lewis_middle porosity_middle middle_temp'
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0.51 0 0.25'
  [../]
  [./strain]
    type = StrainRatePoint
    variable = temp
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0.51 0 0.25'
  [../]
  [./porosity_middle]
    type = PointValue
    variable = porosity
    point = '0.51 0 0.25'
  [../]
  [./Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0.51 0 0.25'
  [../]
  [./strain_rate_middle]
    type = PointValue
    variable = strain_rate
    point = '0.51 0 0.25'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0.51 0 0.25'
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
    type = ConstantDT
    dt = 0.0001
  [../]
[]

[Outputs]
  exodus = true
  base_file = bench_THC_poro_out
  file_base = Ring_shear_mechanics
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
  [./Mechanics]
    disp_z = disp_z
    pore_pres = pore_pressure
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

