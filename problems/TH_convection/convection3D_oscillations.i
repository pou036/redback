[Mesh]
  type = GeneratedMesh
  dim = 3
  nx = 20
  ny = 10
  nz = 10
  xmax = 2
[]

[Variables]
  active = 'pore_pressure temp'
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
[]

[AuxVariables]
  active = 'fluid_velocity_z fluid_velocity_y fluid_velocity_x'
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
  [./fluid_velocity_x]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./fluid_velocity_y]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./fluid_velocity_z]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  active = 'td_press pres_conv thermal_pressurization diff_temp td_temp temp_conv press_diff'
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
  [./thermal_pressurization]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temp
  [../]
  [./temp_conv]
    type = RedbackThermalConvection
    variable = temp
  [../]
  [./pres_conv]
    type = RedbackMassConvection
    variable = pore_pressure
    temperature = temp
  [../]
[]

[AuxKernels]
  active = 'fluid_velocity_z fluid_velocity_y fluid_velocity_x'
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
  [./fluid_velocity_x]
    type = MaterialVectorAux
    variable = fluid_velocity_x
    index = 0
    vector = fluid_velocity
  [../]
  [./fluid_velocity_y]
    type = MaterialVectorAux
    variable = fluid_velocity_y
    index = 1
    vector = fluid_velocity
  [../]
  [./fluid_velocity_z]
    type = MaterialVectorAux
    variable = fluid_velocity_z
    index = 2
    vector = fluid_velocity
  [../]
[]

[BCs]
  active = 'top_temp bottom_temp press_bc temp_flux_left_right'
  [./disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 'left right'
    value = 0
  [../]
  [./disp_x_left]
    type = DirichletBC
    variable = disp_x
    boundary = left
    value = 1
  [../]
  [./disp_x_rigth]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
  [./press_bc]
    type = DirichletBC
    variable = pore_pressure
    boundary = 'top bottom'
    value = 0
  [../]
  [./top_temp]
    type = DirichletBC
    variable = temp
    boundary = top
    value = 0
  [../]
  [./bottom_temp]
    type = DirichletBC
    variable = temp
    boundary = bottom
    value = 3
  [../]
  [./temp_flux_left_right]
    type = NeumannBC
    variable = temp
    boundary = 'left right'
  [../]
[]

[Materials]
  [./adim_rock]
    type = RedbackMaterial
    block = 0
    alpha_2 = 3
    mu = 1e-3
    ar = 10
    yield_stress = '0 1 1 1'
    C_ijkl = '1.346e+03 5.769e+02 5.769e+02 1.346e+03 5.769e+02 1.346e+03 3.846e+02 3.846e+02 3.846e+2'
    gr = 0.11
    pore_pres = pore_pressure
    temperature = temp
    is_mechanics_on = false
    ref_lewis_nb = 1
    Kc = 1
    ar_F = 20
    ar_R = 10
    phi0 = 0.1
    eta1 = 1e3
    Aphi = 1
    da_endo = 1e-4
    pressurization_coefficient = 1
    are_convective_terms_on = true
    solid_compressibility = 0
    fluid_compressibility = 1e-2
  [../]
[]

[Postprocessors]
  active = 'middle_press temperature_middle'
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '0 0 0'
  [../]
  [./strain]
    type = StrainRatePoint
    variable = temp
    point = '0 0 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '1 0.5 0.5'
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
  [./strain_rate_middle]
    type = PointValue
    variable = strain_rate
    point = '0 0 0'
  [../]
  [./solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  [../]
  [./temperature_middle]
    type = PointValue
    variable = temp
    point = '1 0.5 0.5'
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 10000
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  end_time = 100
  dtmax = 0.1
  scheme = bdf2
  [./TimeStepper]
    type = ConstantDT
    dt = 1e-1
  [../]
[]

[Outputs]
  output_initial = true
  exodus = true
  file_base = convection1_out
[]

[ICs]
  [./temp_ic]
    variable = temp
    type = RandomIC
    block = 0
    max = 1e-3
  [../]
  [./press_ic]
    variable = pore_pressure
    type = ConstantIC
    value = 0
  [../]
[]

