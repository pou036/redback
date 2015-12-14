[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./u]
  [../]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
[]

[Kernels]
  [./du_dt]
    type = TimeDerivative
    variable = u
  [../]
  [./diff_u]
    type = RedbackVarAnisotropicDiffusion
    variable = u
  [../]
[]

[BCs]
  [./u_bound]
    type = DirichletBC
    variable = u
    boundary = left
    value = 1
  [../]
  [./u_dir]
    type = DirichletBC
    variable = u
    boundary = top
    value = 1
  [../]
  [./disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = 'bottom top'
    value = 0
  [../]
  [./disp_x]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = 'left right'
    function = 0.01*t
  [../]
[]

[Materials]
  [./red_mat]
    type = RedbackMaterial
    block = 0
    disp_x = disp_x
    disp_y = disp_y
  [../]
  [./mat]
    type = RedbackMaterialElasticVarDiff
    block = 0
    youngs_modulus = 1
    cracks = '0 0 0 0'
    disp_y = disp_y
    disp_x = disp_x
    poisson_ratio = 0.2
    Prefactor = 0.04
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 200
  dt = 0.1
  nl_abs_tol = 1e-10
  nl_rel_step_tol = 1e-10
  nl_rel_tol = 1e-10
  nl_abs_step_tol = 1e-10
[]

[Outputs]
  exodus = true
  file_base = eleni_test
[]

[RedbackMechAction]
  [./solid]
    disp_y = disp_y
    disp_x = disp_x
  [../]
[]

