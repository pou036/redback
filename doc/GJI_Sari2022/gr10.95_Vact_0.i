[Mesh]
  type = FileMesh
  file = 2d_4layers_subduction.msh
[]

[Variables]
  inactive = 'disp_z'
  [disp_x]
    block = '0 1 2 3'
  []
  [disp_y]
    block = '0 1 2 3'
  []
  [disp_z]
    block = '0 1 2 3'
  []
  [temp]
    block = '0 1 2 3'
  []
  [pore_pressure]
    block = '0 1 2 3'
  []
[]

[Materials]
  [redback_nomech]
    type = RedbackMaterial
    block = '0 1 2 3'
    ar = 8 # 10
    da_endo = 2.05e-5
    da_exo = 8.29e-2
    phi0 = 0.03
    Kc = 2e2
    ref_lewis_nb = 20 # 10
    ar_F = 20.2 # 20.2
    ar_R = 10.1
    eta1 = 2.27
    eta2 = 0.26
    mu = 3.4e-3 # 3.4e-5
    Aphi = 1
    is_chemistry_on = true
    temperature = 'temp'
    pore_pres = 'pore_pressure'
    total_porosity = 'total_porosity'
    disp_x = 'disp_x'
    disp_y = 'disp_y'
    pressurization_coefficient = 0.4 # 1
    gr = 10.95 # 3.25
    is_mechanics_on = true
    alpha_2 = 0
  []
  [fault_mech]
    type = RedbackMechMaterialJ2
    param_2 = '4'
    block = '1'
    youngs_modulus = 10000
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    pore_pres = 'pore_pressure'
    yield_stress = '0. 1 1. 1'
    temperature = 'temp'
    poisson_ratio = 0.3
    total_porosity = 'total_porosity'
  []
  [rock_bottom]
    type = RedbackMechMaterialElastic
    block = '2 3'
    youngs_modulus = 20000
    exponent = 1
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    pore_pres = 'pore_pressure'
    yield_stress = '0 100 1 100'
    total_porosity = 'total_porosity'
    temperature = 'temp Lewis_number'
    poisson_ratio = 0.3
    ref_pe_rate = 1
  []
  [rock_top]
    type = RedbackMechMaterialElastic
    block = '0'
    youngs_modulus = 10000
    exponent = 1
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    pore_pres = 'pore_pressure'
    yield_stress = '0 1.1 1 1.1'
    total_porosity = 'total_porosity'
    temperature = 'temp'
    poisson_ratio = 0.3
    ref_pe_rate = 1
  []
[]

[Functions]
  inactive = 'ramp_neg'
  [ramp_pos]
    type = ParsedFunction
    value = '0.7*tanh(0.1*t)'
  []
  [ramp_neg]
    type = ParsedFunction
    value = '-2*tanh(t)'
  []
  [timestep_function]
    # value = 'min(if((t<32.5)&(t>32.2),1e-3 ,999 ) , max(1e-7, min(1e0, dt*max(0.2,min(1-5*(deltaT-0.2),min(1-0.04*(m-10),  1-0.1*(n-4.1)))))))'
    #
    # max(if(t>5e9,0.2 ,0), min(if((t<0)&(t>5e9),1e-2 ,999 ) , max(1e-7, min(1e1, dt*max(0.2,min(1-5*(deltaT-0.2),min(1-0.04*(m-10),  1-0.1*(n2-4.1))))))))
    type = ParsedFunction
    value = 'max(if((t<0)&(t>5e9)&((T-T_old)<1e-3)&((T-T_old)>-1e-3),0.3 ,0), min(if((t<0)&(t>5e9),1e-2 ,999 ) , max(1e0, min(3e2, dt*max(0.2,min(1-5*((T-T_old)-0.2),min(1-0.04*(m-10),  1-0.2*(n2-4.1))))))))'
    vals = 'num_li num_nli dt max_returnmap_iter middle_temp middle_temp_old'
    vars = 'n n2 dt m T T_old'
  []
  [linear_temp]
    # T_bottom + (T_top-T_bottom)/(y_top - y_bottom) * (y - y_bottom)
    type = ParsedFunction
    value = '((0-0.001)/(5+6)) * (y + 6) + 0.001'
  []
  [confinement_fct]
    type = ConstantFunction
    value = 0.5
  []
  [bottom_ux_fct]
    type = ParsedFunction
    value = 'if (t<t1, alpha1*t, if (t<t2, alpha2*(t-t1)+alpha1*t1, alpha1*(t-t2+t1)+alpha2*(t2-t1)))'
    vals = '1e-6 1e-5 2500 4000'
    vars = 'alpha1 alpha2 t1 t2'
  []
[]

[BCs]
  inactive = 'ux_force_bottom_base left_Neumann right_Neumann'
  [Periodic]
    inactive = 'zperiodic'
    [xperiodic]
      variable = 'disp_x disp_y temp pore_pressure'
      translation = '1.0 0 0'
      secondary = '2 7'
      primary = '4 6'
    []
    [zperiodic]
      variable = 'disp_x disp_y temp pore_pressure'
      translation = '0 0 1'
      secondary = 5
      primary = 0
    []
  []
  [ux_equals_zero_on_top]
    type = DirichletBC
    variable = disp_x
    boundary = '3'
    value = 0
  []
  [top_cauchy_zero]
    type = NeumannBC
    variable = disp_x
    boundary = '3'
  []
  [ux_bottom_vel]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = '1'
    function = bottom_ux_fct
  []
  [pore_pressure]
    type = DirichletBC
    variable = pore_pressure
    boundary = '1 3'
    value = 0
  []
  [ux_force_bottom_base]
    type = FunctionNeumannBC
    variable = disp_x
    boundary = '6'
    function = ramp_pos
  []
  [temperature_top]
    type = DirichletBC
    variable = temp
    boundary = '3'
    value = 0
  []
  [temperature_bottom]
    type = DirichletBC
    variable = temp
    boundary = '1'
    value = 0.001 # 0.1
  []
  [Pressure]
    boundary = '1'
    function = 'confinement_fct'
    disp_y = 'disp_y'
    disp_x = 'disp_x'
    [confinement_left]
      function = confinement_fct
      disp_y = 'disp_y'
      disp_x = 'disp_x'
      boundary = '4 6'
    []
    [confinement_right]
      function = confinement_fct
      disp_y = 'disp_y'
      disp_x = 'disp_x'
      boundary = '2 7'
    []
    [confinement_top]
      function = confinement_fct
      disp_y = 'disp_y'
      disp_x = 'disp_x'
      boundary = '3'
    []
  []
  [left_Neumann]
    type = NeumannBC
    variable = disp_x
    boundary = '4 6'
    value = 1e0
  []
  [right_Neumann]
    type = NeumannBC
    variable = disp_x
    boundary = '2 7'
    value = -1e0
  []
  [uy_top]
    type = DirichletBC
    variable = disp_y
    boundary = '3'
    value = 0.0
  []
  [stress_bottom]
    type = NeumannBC
    variable = disp_y
    boundary = '1'
    value = 1
  []
[]

[AuxVariables]
  inactive = 'peeq pe11 pe22 pe33 mech_diss delta_temp'
  [stress_zz]
    order = CONSTANT
    family = MONOMIAL
    block = '1'
  []
  [peeq]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe11]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe22]
    order = CONSTANT
    family = MONOMIAL
  []
  [pe33]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_stress]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_strain]
    order = CONSTANT
    family = MONOMIAL
  []
  [mises_strain_rate]
    order = CONSTANT
    family = MONOMIAL
  []
  [mech_diss]
    order = CONSTANT
    family = MONOMIAL
  []
  [Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
    block = '1'
  []
  [volumetric_strain]
    order = CONSTANT
    family = MONOMIAL
  []
  [volumetric_strain_rate]
    order = CONSTANT
    family = MONOMIAL
  []
  [mean_stress]
    order = CONSTANT
    family = MONOMIAL
  []
  [total_porosity]
    family = MONOMIAL
  []
  [mech_porosity]
    order = FIRST
    family = MONOMIAL
  []
  [Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  []
  [strain_rate]
    order = CONSTANT
    family = MONOMIAL
  []
  [solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  []
  [returnmap_iter]
    order = CONSTANT
    family = MONOMIAL
    block = '1'
  []
  [delta_temp]
    order = CONSTANT
    family = MONOMIAL
    block = '1'
  []
  [stress_xx]
    order = CONSTANT
    family = MONOMIAL
  []
  [stress_xy]
    order = CONSTANT
    family = MONOMIAL
  []
  [stress_yy]
    order = CONSTANT
    family = MONOMIAL
  []
[]

[Kernels]
  [td_temp]
    type = TimeDerivative
    variable = temp
    block = '0 1 2 3'
  []
  [diff_temp]
    type = Diffusion
    variable = temp
    block = '0 1 2 3'
  []
  [mh_temp]
    type = RedbackMechDissip
    variable = temp
    block = '1'
  []
  [td_press]
    type = TimeDerivative
    variable = pore_pressure
    block = '0 1 2 3'
  []
  [press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
    block = '0 1 2 3'
  []
  [chem_press]
    type = RedbackChemPressure
    variable = pore_pressure
    block = '1'
    temperature = 'temp'
  []
  [Chem_endo_temp]
    type = RedbackChemEndo
    variable = temp
    block = '1'
  []
  [thermal_press]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = 'temp'
  []
[]

[AuxKernels]
  inactive = 'pe11 pe22 pe33 eqv_plastic_strain mech_dissipation delta_temp'
  [stress_zz]
    type = RankTwoAux
    rank_two_tensor = stress
    variable = stress_zz
    index_i = 2
    index_j = 2
  []
  [pe11]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe11
    index_i = 0
    index_j = 0
  []
  [pe22]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe22
    index_i = 1
    index_j = 1
  []
  [pe33]
    type = RankTwoAux
    rank_two_tensor = plastic_strain
    variable = pe33
    index_i = 2
    index_j = 2
  []
  [eqv_plastic_strain]
    type = FiniteStrainPlasticAux
    variable = 'peeq'
  []
  [mises_stress]
    type = MaterialRealAux
    variable = mises_stress
    property = mises_stress
  []
  [mises_strain]
    type = MaterialRealAux
    variable = mises_strain
    property = mises_strain
  []
  [mises_strain_rate]
    type = MaterialRealAux
    variable = mises_strain_rate
    property = mises_strain_rate
  []
  [mech_dissipation]
    type = MaterialRealAux
    variable = mech_diss
    property = mechanical_dissipation
  []
  [Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
  []
  [mean_stress]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
  []
  [volumetric_strain]
    type = MaterialRealAux
    variable = volumetric_strain
    property = volumetric_strain
  []
  [volumetric_strain_rate]
    type = MaterialRealAux
    variable = volumetric_strain_rate
    property = volumetric_strain_rate
  []
  [total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = 'mech_porosity'
    execute_on = 'linear'
  []
  [mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = 'timestep_end'
    property = mechanical_porosity
  []
  [Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  []
  [strain_rate]
    type = MaterialRealAux
    variable = strain_rate
    property = mises_strain_rate
  []
  [solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  []
  [returnmap_iter]
    type = MaterialRealAux
    variable = returnmap_iter
    property = returnmap_iter
    block = '1'
  []
  [delta_temp]
    type = MaterialRealAux
    variable = delta_temp
    property = delta_T
    block = '1'
  []
  [stress_xx]
    type = RankTwoAux
    variable = stress_xx
    rank_two_tensor = stress
    index_j = 0
    index_i = 0
  []
  [stress_xy]
    type = RankTwoAux
    variable = stress_xy
    rank_two_tensor = stress
    index_j = 1
    index_i = 0
  []
  [stress_yy]
    type = RankTwoAux
    variable = stress_yy
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  []
[]

[Preconditioning]
  # active = ''
  [SMP]
    type = SMP
    full = true
  []
[]

[Postprocessors]
  inactive = 'strain delta_T_centre'
  [middle_temp]
    type = PointValue
    variable = temp
    point = '0 0 0'
  []
  [strain]
    type = StrainRatePoint
    variable = 'temp'
    point = '0 0 0'
  []
  [middle_press]
    type = PointValue
    variable = pore_pressure
    point = '0 0 0'
  []
  [porosity_middle]
    type = PointValue
    variable = total_porosity
    point = '0 0 0'
  []
  [Lewis_middle]
    type = PointValue
    variable = Lewis_number
    point = '0 0 0'
  []
  [strain_rate_middle]
    type = PointValue
    variable = strain_rate
    point = '0 0 0'
  []
  [solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  []
  [mises_stress_centre]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  []
  [dt]
    type = TimestepSize
  []
  [num_li]
    type = NumLinearIterations
  []
  [num_nli]
    type = NumNonlinearIterations
  []
  [new_timestep]
    type = FunctionValuePostprocessor
    function = timestep_function
  []
  [max_returnmap_iter]
    type = ElementExtremeValue
    variable = 'returnmap_iter'
    block = '1'
  []
  [disp_fault]
    type = PointValue
    variable = disp_x
    point = '0 0 0'
  []
  [delta_T_centre]
    type = PointValue
    variable = delta_temp
    point = '0 0 0'
  []
  [mean_stress_centre]
    type = PointValue
    variable = mean_stress
    point = '0 0 0'
  []
  [middle_temp_old]
    type = PointValue
    variable = temp
    execute_on = 'timestep_begin'
    point = '0 0 0'
  []
  [bottom_stress_xx]
    type = PointValue
    variable = stress_xx
    point = '0 -6 0'
  []
  [bottom_stress_xy]
    type = PointValue
    variable = stress_xy
    point = '0 -6 0'
  []
  [bottom_stress_yy]
    type = PointValue
    variable = stress_yy
    point = '0 -6 0'
  []
[]

[Executioner]
  # Preconditioned JFNK (default)
  # [./TimeStepper]
  # type = ConstantDT
  # dt = 1e-1
  # [../]
  # [./TimeStepper]
  # type = SolutionTimeAdaptiveDT
  # dt = 0.1
  # adapt_log = true
  # [../]
  type = Transient
  start_time = 0.0
  end_time = 6000
  dtmax = 10
  dtmin = 1e-11
  num_steps = 1000000
  dt = 0.1
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart '
  petsc_options_value = 'gmres asm lu 201'
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  line_search = basic
  [TimeStepper]
    type = PostprocessorDT
    dt = 0.1
    postprocessor = new_timestep
  []
[]

[Outputs]
  file_base = 2D_JGR4_vel_vact_0
  output_initial = 'true'
  exodus = true
  execute_on = 'timestep_end final failed'
  [console]
    type = Console
    perf_log = true
    linear_residuals = true
    execute_on = 'timestep_end final failed'
  []
[]

[RedbackMechAction]
  [solid]
    disp_y = disp_y
    disp_x = disp_x
    temp = temp
    pore_pres = pore_pressure
  []
[]

[ICs]
  [temp_ic]
    type = FunctionIC
    variable = temp
    function = linear_temp
  []
  [press_ic]
    type = ConstantIC
    variable = pore_pressure
    value = 0
  []
[]
