# Implementing the mass balance for a fluid in a porous medium

[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 10
  xmin = 0
  xmax = 1
[]

[Variables]
  [./sat]
  [../]
  [./phi]
  [../]
  [./rho]
  [../]
[]

[ICs]
  [./satinit]
    type = FunctionIC
    function = 1-x
    variable = sat
  [../]
  [./phiinit]
    type = ConstantIC
    value = 1
    variable = phi
  [../]
  [./rhoinit]
    type = ConstantIC
    value = 1
    variable = rho
  [../]
[]

[Kernels]
  [./mass0]
    type = LneFluidMassTimeDerivative
    variable = sat
    phi = phi
    rho = rho
    block = 0
  [../]
  [./diffphi]
    type = Diffusion
    variable = phi
    block = 0
  [../] 
  [./diffrho]
    type = Diffusion
    variable = rho
    block = 0
  [../]    
[]

[Executioner]
  type = Transient
  solve_type = Newton
  dt = 0.1
  end_time = 1
[]

[Outputs]
  exodus = true
  execute_on = timestep_end
  file_base = eleni02
  csv = true
  show = 'sat phi rho'
  dofmap = true
[]

