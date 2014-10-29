[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 100
  ny = 5
  nz = 5
  xmin = -1
[]

[Variables]
  [./temp]
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
[]

[BCs]
  [./left_temp]
    type = DirichletBC
    variable = temp
    boundary = left
    value = 0
  [../]
  [./right_temp]
    type = DirichletBC
    variable = temp
    boundary = right
    value = 0
  [../]
[]

[Materials]
  [./adim_rock]
    type = RedbackMaterial
    block = 0
    m = 1
    ar = 10
    yield_stress = '0 1 1 1'
    C_ijkl = '1.346e+03 5.769e+02 5.769e+02 1.346e+03 5.769e+02 1.346e+03 3.846e+02 3.846e+02 3.846e+2'
    gr = 0.095
    pore_pres = 0
    temperature = temp
    is_mechanics_on = false
    ref_lewis_nb = 1
    ar_F = 40
    ar_R = 1
    Aphi = 0
    phi0 = 0.1
    da_endo = 1
  [../]
[]

[Postprocessors]
  active = 'middle_temp'
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
[]

[Executioner]
  type = Transient
  num_steps = 10000
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  ss_check_tol = 1e-6
  end_time = 15
  dtmax = 0.1
  scheme = bdf2
  [./TimeStepper]
    type = ConstantDT
    dt = 0.1
  [../]
[]

[Outputs]
  file_base = bench1_c_out
  exodus = true
  csv = true
  console = true
[]

[ICs]
  [./temp_ic]
    variable = temp
    value = 0.25
    type = ConstantIC
    block = 0
  [../]
[]

