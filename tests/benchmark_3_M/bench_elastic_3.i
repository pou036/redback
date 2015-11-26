[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 4
  ny = 4
  xmin = -1
  ymin = -1
[]

[Variables]
  [./disp_x]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_y]
    order = FIRST
    family = LAGRANGE
  [../]
  [./disp_z]
    order = FIRST
    family = LAGRANGE
  [../]
  [./temp]
  [../]
[]

[Materials]
  [./mat0]
    type = RedbackMechMaterialElastic
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    disp_z = 0
    temperature = temp
    C_ijkl = '1.346e+03 5.769e+02 5.769e+02 1.346e+03 5.769e+02 1.346e+03 3.846e+02 3.846e+02 3.846e+2'
    yield_stress = '0. 1 1. 1'
    exponent = 1
    ref_pe_rate = 1
    youngs_modulus = 1000
    poisson_ratio = 0.3
    total_porosity = total_porosity
  [../]
  [./mat1]
    type = RedbackMaterial
    block = 0
    disp_y = disp_y
    disp_x = disp_x
    disp_z = 0
    temperature = temp
    Aphi = 0
    ar = 5
    gr = 1
    alpha_2 = 2
    pore_pres = 0
    is_mechanics_on = true
    phi0 = 0.5
    ref_lewis_nb = 1
    ar_F = 1
    ar_R = 1
    total_porosity = total_porosity
  [../]
[]

[BCs]
  [./left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = 3
    value = 0
  [../]
  [./left_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 3
    value = 0
  [../]
  [./rigth_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 1
    value = 0
  [../]
  [./temp_box]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2 3'
    value = 0
  [../]
  [./constant_force_right]
    type = NeumannBC
    variable = disp_x
    boundary = 1
    value = -100
  [../]
[]

[AuxVariables]
  [./total_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
  [./mech_porosity]
    order = FIRST
    family = MONOMIAL
  [../]
[]

[Kernels]
  [./temp_td]
    type = TimeDerivative
    variable = temp
  [../]
  [./temp_diff]
    type = AnisotropicDiffusion
    variable = temp
    tensor_coeff = '1 0 0 0 1 0 0 0 1'
  [../]
  [./temp_dissip]
    type = RedbackMechDissip
    variable = temp
  [../]
[]

[AuxKernels]
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = mech_porosity
  [../]
  [./mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = timestep_end
    property = mechanical_porosity
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  start_time = 0.0
  end_time = 5
  dtmax = 1
  dtmin = 1e-7
  type = Transient
  num_steps = 3
  l_max_its = 500
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  petsc_options_value = 'hypre boomeramg cp 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    type = ConstantDT
    dt = 1e-3
  [../]
[]

[Outputs]
  file_base = bench_elastic_3
  output_initial = true
  exodus = true
  csv = true
  [./console]
    type = Console
    perf_log = true
    linear_output = false
  [../]
[]

[ICs]
  active = 'ic_temp'
  [./ic_temp]
    variable = temp
    value = 0
    type = ConstantIC
  [../]
  [./Spline_IC]
    function = spline_IC
    variable = temp
    type = FunctionIC
    block = 0
  [../]
[]

[RedbackMechAction]
  [./solid]
    disp_z = disp_z
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

