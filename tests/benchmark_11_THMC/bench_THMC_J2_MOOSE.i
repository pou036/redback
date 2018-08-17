# Example of input file using RedbackMooseMechMaterial with a J2 material from MOOSE
# Based on bench_THMC_J2 but hasn't been tested properly to be a benchmark

[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 5
  ny = 4
  xmin = -1.5
  xmax = 1.5
  ymin = -1
[]

[MeshModifiers]
  [middle_left]
    type = AddExtraNodeset
    new_boundary = '4'
    coord = '-1.5 0'
  []
[]

[GlobalParams]
  displacements = 'disp_x disp_y'
[]

[Modules]
  [TensorMechanics]
    [Master]
      [all]
        strain = FINITE
      []
    []
  []
[]

[Variables]
  [disp_x]
    order = FIRST
    family = LAGRANGE
  []
  [disp_y]
    order = FIRST
    family = LAGRANGE
  []
  [temp]
  []
  [pore_pressure]
  []
[]

[Materials]
  [Elasticity_tensor]
    type = ComputeIsotropicElasticityTensor
    block = '0'
    poissons_ratio = 0.3
    youngs_modulus = 1000
  []
  [mc]
    type = ComputeMultiPlasticityStress
    block = '0'
    ep_plastic_tolerance = 1E-9
    plastic_models = 'j2'
  []
  [mat_mech]
    type = RedbackMooseMechMaterial
    block = '0'
    disp_x = 'disp_x'
    disp_y = 'disp_y'
    pore_pres = 'pore_pressure'
    temperature = 'temp'
    total_porosity = 'total_porosity'
  []
  [mat_nomech]
    type = RedbackMaterial
    block = '0'
    is_chemistry_on = true
    is_mechanics_on = false
    disp_x = 'disp_x'
    disp_y = 'disp_y'
    pore_pres = 'pore_pressure'
    temperature = 'temp'
    Aphi = 1
    Kc = 1
    ar = 10
    ar_F = 20
    ar_R = 10
    da_endo = 1e-5
    eta1 = 1e3
    gr = 9.08e-6 # 0.2*exp(-Ar), Ar=10
    alpha_2 = 3
    mu = 1e-3
    phi0 = 0.1
    ref_lewis_nb = 1
    total_porosity = 'total_porosity'
    solid_compressibility = 1e-10
  []
[]

[UserObjects]
  [str]
    type = TensorMechanicsHardeningConstant
    value = 1
  []
  [j2]
    type = TensorMechanicsPlasticJ2
    yield_strength = str
    yield_function_tolerance = 1E-9
    internal_constraint_tolerance = 1E-9
  []
[]

[Functions]
  inactive = 'upfunc spline_IC'
  [upfunc]
    type = ParsedFunction
    value = 't'
  []
  [downfunc]
    type = ParsedFunction
    value = '-3e-2*t'
  []
  [spline_IC]
    type = ConstantFunction
  []
[]

[BCs]
  inactive = 'right_disp bottom_temp top_temp temp_box'
  [left_disp]
    type = DirichletBC
    variable = disp_x
    boundary = '3'
    value = 0
  []
  [right_disp]
    type = FunctionPresetBC
    variable = disp_x
    boundary = '1'
    function = downfunc
  []
  [bottom_temp]
    type = NeumannBC
    variable = temp
    boundary = '0'
    value = -1
  []
  [top_temp]
    type = NeumannBC
    variable = temp
    boundary = '2'
    value = -1
  []
  [left_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = '3'
    value = 0
  []
  [temp_mid_pts]
    type = DirichletBC
    variable = temp
    boundary = '4'
    value = 0
  []
  [rigth_disp_y]
    type = DirichletBC
    variable = disp_y
    boundary = '1'
    value = 0
  []
  [temp_box]
    type = DirichletBC
    variable = temp
    boundary = '0 1 2 3'
    value = 0
  []
  [constant_force_right]
    type = NeumannBC
    variable = disp_x
    boundary = '1'
    value = -2
  []
  [press_bc]
    type = DirichletBC
    variable = pore_pressure
    boundary = 'left right'
    value = 0
  []
[]

[AuxVariables]
  inactive = 'stress_zz peeq pe11 pe22 pe33 mises_strain Mod_Gruntfest_number'
  [stress_zz]
    order = CONSTANT
    family = MONOMIAL
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
    block = '0'
  []
  [Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
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
    order = FIRST
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
  [solid_ratio]
    order = CONSTANT
    family = MONOMIAL
  []
[]

[Kernels]
  [td_temp]
    type = TimeDerivative
    variable = temp
  []
  [temp_diff]
    type = Diffusion
    variable = temp
  []
  [temp_dissip]
    type = RedbackMechDissip
    variable = temp
  []
  [temp_endo_chem]
    type = RedbackChemEndo
    variable = temp
  []
  [td_press]
    type = TimeDerivative
    variable = pore_pressure
  []
  [press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  []
  [chem_press]
    type = RedbackChemPressure
    variable = pore_pressure
    block = '0'
  []
  [poromech_x]
    type = PoroMechanicsCoupling
    component = 0
    porepressure = 'pore_pressure'
    variable = disp_x
  []
  [poromech_y]
    type = PoroMechanicsCoupling
    component = 1
    porepressure = 'pore_pressure'
    variable = disp_y
  []
[]

[AuxKernels]
  inactive = 'stress_zz pe11 pe22 pe33 eqv_plastic_strain mises_strain Gruntfest_Number'
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
    property = eqv_plastic_strain
  []
  [mises_strain_rate]
    type = MaterialRealAux
    variable = mises_strain_rate
    block = '0'
    property = mises_strain_rate
  []
  [Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
    block = '0'
  []
  [mean_stress]
    type = MaterialRealAux
    variable = mean_stress
    property = mean_stress
    block = '0'
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
    execute_on = 'initial LINEAR'
  []
  [mech_porosity]
    type = MaterialRealAux
    variable = mech_porosity
    execute_on = 'initial timestep_end'
    property = mechanical_porosity
  []
  [Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  []
  [solid_ratio]
    type = MaterialRealAux
    variable = solid_ratio
    property = solid_ratio
  []
[]

[Postprocessors]
  inactive = 'mises_strain'
  [mises_stress]
    type = PointValue
    variable = mises_stress
    point = '0 0 0'
  []
  [mises_strain]
    type = PointValue
    variable = mises_strain
    point = '0 0 0'
  []
  [mises_strain_rate]
    type = PointValue
    variable = mises_strain_rate
    point = '0 0 0'
  []
  [temp_middle]
    type = PointValue
    variable = temp
    point = '0 0 0'
  []
  [mean_stress]
    type = PointValue
    variable = mean_stress
    point = '0 0 0'
  []
  [volumetric_strain]
    type = PointValue
    variable = volumetric_strain
    point = '0 0 0'
  []
  [volumetric_strain_rate]
    type = PointValue
    variable = volumetric_strain_rate
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
  [solid_ratio_middle]
    type = PointValue
    variable = solid_ratio
    point = '0 0 0'
  []
[]

[Preconditioning]
  # active = ''
  [SMP]
    type = SMP
    full = true
  []
[]

[Executioner]
  # Preconditioned JFNK (default)
  # petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart'
  # petsc_options_value = 'hypre boomeramg cp 201'
  type = Transient
  start_time = 0.0
  end_time = 0.03
  dtmax = 1
  dtmin = 1e-7
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  nl_abs_tol = 1e-10 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [TimeStepper]
    type = ConstantDT
    dt = 1e-2
  []
[]

[Outputs]
  # output_initial = true
  file_base = bench_THMC_J2_MOOSE_out
  exodus = true
  [console]
    type = Console
    perf_log = true
  []
[]

[ICs]
  [temp_IC]
    type = ConstantIC
    variable = temp
    value = 0
  []
  [press_ic]
    type = ConstantIC
    variable = pore_pressure
    value = 0
  []
[]
