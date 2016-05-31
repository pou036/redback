[Mesh]
  type = FileMesh
  file = ../3D_biaxial.msh
  boundary_name = 'back bottom right top left front'
  boundary_id = '0 1 2 3 4 5'
[]

[GlobalParams]
  disp_z = disp_z
  disp_y = disp_y
  disp_x = disp_x
  wc_z = wc_z
  wc_y = wc_y
  wc_x = wc_x
[]

[Postprocessors]
  active = 'nb_nonlin disp_x_16 disp_x_17 disp_x_14 disp_x_15 disp_x_12 disp_x_13 disp_x_10 disp_x_11 disp_x_18 disp_x_19 disp_x_29 disp_x_28 disp_y_top disp_x_23 disp_x_22 disp_x_21 disp_x_20 disp_x_27 disp_x_26 disp_x_25 disp_x_24 lagrange_27 lagrange_26 lagrange_25 lagrange_24 lagrange_23 lagrange_22 lagrange_21 lagrange_20 lagrange_29 lagrange_28 lagrange_8 lagrange_9 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_0 lagrange_1 lagrange_2 lagrange_3 disp_x_38 disp_x_39 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_30 disp_x_31 disp_x_32 disp_x_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_38 lagrange_39 disp_x_40 timestep nb_lin lagrange_18 lagrange_19 lagrange_16 lagrange_17 lagrange_14 lagrange_15 lagrange_12 lagrange_13 lagrange_10 lagrange_11 disp_x_top wc_z_top force disp_x_8 disp_x_9 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_0 disp_x_1 disp_x_2 disp_x_3 dt'
  [./disp_x_0]
    type = PointValue
    point = '3 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '3 3.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '3 6.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '3 9.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '3 12.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '3 15.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '3 18.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '3 21.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '3 24.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '3 27.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '3 30.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '3 33.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '3 36.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '3 39.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '3 42.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '3 45.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '3 48.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '3 51.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '3 54.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '3 57.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '3 60.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '3 63.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '3 66.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '3 69.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '3 72.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '3 75.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '3 78.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '3 81.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '3 84.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '3 87.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '3 90.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '3 93.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '3 96.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '3 99.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '3 102.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '3 105.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '3 108.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '3 111.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '3 114.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '3 117.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '3 120.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '3 1.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '3 4.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '3 7.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '3 10.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '3 13.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '3 16.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '3 19.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '3 22.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '3 25.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '3 28.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '3 31.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '3 34.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '3 37.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '3 40.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '3 43.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '3 46.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '3 49.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '3 52.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '3 55.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '3 58.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '3 61.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '3 64.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '3 67.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '3 70.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '3 73.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '3 76.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '3 79.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '3 82.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '3 85.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '3 88.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '3 91.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '3 94.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '3 97.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '3 100.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '3 103.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '3 106.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '3 109.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '3 112.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '3 115.5 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '3 118.5 0.0'
    variable = lagrange
  [../]
  [./disp_y_top]
    type = PointValue
    point = '0.0 120 0.0'
    variable = disp_y
  [../]
  [./disp_x_top]
    type = PointValue
    point = '0.0 120 0.0'
    variable = disp_x
  [../]
  [./wc_z_top]
    type = PointValue
    point = '0.0 120 0'
    variable = wc_z
  [../]
  [./antisymmetric_pp]
    type = SideAverageValue
    variable = antisymmetric_strain_bc
    boundary = bottom
  [../]
  [./Rotation_wcz_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 0.5'
  [../]
  [./Rotation_wcz_0_8]
    type = PointValue
    variable = wc_z
    point = '0.5 0.8 0.5'
  [../]
  [./Rotation_wcz_0_7]
    type = PointValue
    variable = wc_z
    point = '0.5 0.7 0.5'
  [../]
  [./Rotation_wcz_0_6]
    type = PointValue
    variable = wc_z
    point = '0.5 0.6 0.5'
  [../]
  [./Rotation_wcz_0_5]
    type = PointValue
    variable = wc_z
    point = '0.5 0.5 0.5'
  [../]
  [./Rotation_wcz_0_4]
    type = PointValue
    variable = wc_z
    point = '0.5 0.4 0.5'
  [../]
  [./Rotation_wcz_0_3]
    type = PointValue
    variable = wc_z
    point = '0.5 0.3 0.5'
  [../]
  [./Rotation_wcz_0_2]
    type = PointValue
    variable = wc_z
    point = '0.5 0.2 0.5'
  [../]
  [./Rotation_wcz_0_1]
    type = PointValue
    variable = wc_z
    point = '0.5 0.1 0.5'
  [../]
  [./Displ_u_x_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 0.5'
  [../]
  [./Displ_u_x_0_8]
    type = PointValue
    variable = disp_x
    point = '0.5 0.8 0.5'
  [../]
  [./Displ_u_x_0_7]
    type = PointValue
    variable = disp_x
    point = '0.5 0.7 0.5'
  [../]
  [./Displ_u_x_0_6]
    type = PointValue
    variable = disp_x
    point = '0.5 0.6 0.5'
  [../]
  [./Displ_u_x_0_5]
    type = PointValue
    variable = disp_x
    point = '0.5 0.5 0.5'
  [../]
  [./Displ_u_x_0_4]
    type = PointValue
    variable = disp_x
    point = '0.5 0.4 0.5'
  [../]
  [./Displ_u_x_0_3]
    type = PointValue
    variable = disp_x
    point = '0.5 0.3 0.5'
  [../]
  [./Displ_u_x_0_2]
    type = PointValue
    variable = disp_x
    point = '0.5 0.2 0.5'
  [../]
  [./Displ_u_x_0_1]
    type = PointValue
    variable = disp_x
    point = '0.5 0.1 0.5'
  [../]
  [./force]
    type = SideAverageValue
    variable = stress_22
    execute_on = linear
    boundary = top
  [../]
  [./nb_lin]
    type = NumLinearIterations
  [../]
  [./nb_nonlin]
    type = NumNonlinearIterations
  [../]
  [./timestep]
    type = FunctionValuePostprocessor
    function = timestep_fct
  [../]
  [./dt]
    type = TimestepSize
  [../]
[]

[Variables]
  [./disp_x]
  [../]
  [./disp_y]
  [../]
  [./disp_z]
  [../]
  [./wc_x]
  [../]
  [./wc_y]
  [../]
  [./wc_z]
  [../]
  [./temperature]
  [../]
  [./pore_pressure]
  [../]
[]

[AuxVariables]
  [./stress_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./epsilon_22]
    family = MONOMIAL
  [../]
  [./epsilon_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_strain]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_invariant]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./ecroui]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./failure]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./lagrange]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./macro_rot]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_32]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_23]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_31]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_33]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plast_cur_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./couple_stress_32]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./couple_stress_23]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_curvature_23]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_curvature_32]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./ramp]
    type = ParsedFunction
    value = -0.1*t
  [../]
  [./timestep_fct]
    type = ParsedFunction
    value = if(t<16,2,2)
    vals = dt
    vars = dt
  [../]
[]

[Kernels]
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
    temp = temperature
    pore_pres = pore_pressure
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
    temp = temperature
    pore_pres = pore_pressure
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
    temp = temperature
    pore_pres = pore_pressure
  [../]
  [./x_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_x
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    component = 0
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./y_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_y
    component = 1
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./z_couple]
    type = RedbackCosseratStressDivergenceTensors
    variable = wc_z
    component = 2
    displacements = 'wc_x wc_y wc_z'
    wc_x = disp_x
    wc_y = disp_y
    wc_z = disp_z
    base_name = coupled
    disp_z = wc_z
    disp_y = wc_y
    disp_x = wc_x
  [../]
  [./x_moment]
    type = RedbackMomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = RedbackMomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = RedbackMomentBalancing
    variable = wc_z
    component = 2
  [../]
  [./dT_dt]
    type = TimeDerivative
    variable = temperature
  [../]
  [./T_diff]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
  [./dissip]
    type = RedbackMechDissip
    variable = temperature
  [../]
  [./dp_dt]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./diff_p]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
  [./thermal_press]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temperature
  [../]
[]

[AuxKernels]
  [./stress_22]
    type = RankTwoAux
    variable = stress_22
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  [../]
  [./epsilon_22]
    type = RankTwoAux
    variable = epsilon_22
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./epsilon_11]
    type = RankTwoAux
    variable = epsilon_11
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./plastic_strain]
    type = MaterialRealAux
    variable = plastic_strain
    property = eqv_plastic_strain
  [../]
  [./stress_invariant]
    type = MaterialRealAux
    variable = stress_invariant
    property = stress_invariant
  [../]
  [./ecroui_param]
    type = MaterialRealAux
    variable = ecroui
    property = hardening_variable
  [../]
  [./failure_surf]
    type = MaterialRealAux
    variable = failure
    property = failure_surface
  [../]
  [./lagrange_mult]
    type = MaterialRealAux
    variable = lagrange
    property = lagrange_multiplier
  [../]
  [./plastic_xx]
    type = RankTwoAux
    variable = plastic_11
    rank_two_tensor = plastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./plastic_yy]
    type = RankTwoAux
    variable = plastic_22
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./plastic_xy]
    type = RankTwoAux
    variable = plastic_12
    rank_two_tensor = plastic_strain
    index_j = 1
    index_i = 0
  [../]
  [./antisymmetric_strain]
    type = RankTwoAux
    variable = macro_rot
    rank_two_tensor = macro_rotation
    index_j = 1
    index_i = 0
    execute_on = linear
  [../]
  [./stress_11]
    type = RankTwoAux
    variable = stress_11
    rank_two_tensor = stress
    index_j = 0
    index_i = 0
  [../]
  [./stress_12]
    type = RankTwoAux
    variable = stress_12
    rank_two_tensor = stress
    index_j = 1
    index_i = 0
  [../]
  [./plastic_curv_32]
    type = RankTwoAux
    variable = plastic_cur_32
    rank_two_tensor = plastic_curvature
    index_j = 1
    index_i = 2
  [../]
  [./couple_stress_23]
    type = RankTwoAux
    variable = couple_stress_23
    rank_two_tensor = coupled_stress
    index_j = 2
    index_i = 1
    execute_on = nonlinear
  [../]
  [./couple_stress_32]
    type = RankTwoAux
    variable = couple_stress_32
    rank_two_tensor = coupled_stress
    index_j = 1
    index_i = 2
    execute_on = nonlinear
  [../]
  [./elastic_curvature_32]
    type = RankTwoAux
    variable = elastic_curvature_32
    rank_two_tensor = elastic_curvature
    index_j = 1
    index_i = 2
  [../]
  [./elastic_curvature_23]
    type = RankTwoAux
    variable = elastic_curvature_23
    rank_two_tensor = elastic_curvature
    index_j = 2
    index_i = 1
  [../]
[]

[BCs]
  # following is natural BC
  active = 'uy_bottom u_z_face uy_ramp_top wc_x_bottom u_x_right wc_z_bottom_zero wc_y_bottom uz_back'
  [./wcx_equals_zero_on_top]
    type = DirichletBC
    variable = wc_x
    boundary = top
    value = 0
  [../]
  [./wcy_equals_zero_on_top]
    type = DirichletBC
    variable = wc_y
    boundary = top
    value = 0
  [../]
  [./uy_bottom]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0.0
  [../]
  [./uz_bottom]
    type = DirichletBC
    variable = disp_z
    boundary = bottom
    value = 0.0
  [../]
  [./wc_x_bottom]
    type = DirichletBC
    variable = wc_x
    boundary = bottom
    value = 0.0
  [../]
  [./wc_y_bottom]
    type = DirichletBC
    variable = wc_y
    boundary = bottom
    value = 0.0
  [../]
  [./ux_zero_bottom]
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 0.
  [../]
  [./wc_z_rotationBC]
    type = RedbackRotationBC
    variable = wc_z
    boundary = bottom
    dir1 = 1
    antisymmetric_strain_ij = antisymmetric_strain_ij
    some_var_1 = disp_x
    some_var_2 = disp_y
    grad_ux = _grad_ux
  [../]
  [./dux_top]
    type = NeumannBC
    variable = disp_z
    boundary = top
  [../]
  [./wcz_imposed_top]
    type = DirichletBC
    variable = wc_z
    boundary = top
    value = -0.1
  [../]
  [./ux_imposed_top]
    type = DirichletBC
    variable = disp_x
    boundary = top
    value = 0.01
  [../]
  [./wc_z_bottom_zero]
    type = DirichletBC
    variable = wc_z
    boundary = bottom
    value = 0
  [../]
  [./Rotation_wc_z_BC]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = bottom
    postprocessor = antisymmetric_pp
  [../]
  [./uy_ramp_top]
    type = FunctionDirichletBC
    variable = disp_y
    boundary = top
    function = ramp
  [../]
  [./u_z_face]
    type = DirichletBC
    variable = disp_z
    boundary = front
    value = 0
  [../]
  [./uz_back]
    type = DirichletBC
    variable = disp_z
    boundary = back
    value = 0
  [../]
  [./u_x_right]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
  [./fixed_point]
    type = DirichletBC
    variable = disp_x
    boundary = 101
    value = 0
  [../]
[]

[Materials]
  active = 'Redbackcosserat redback_mat'
  [./cosserat]
    type = CosseratLinearElasticMaterial
    block = 0
    B_ijkl = 40
    C_ijkl = '5 10 5'
    fill_method = general_isotropic
  [../]
  [./Redbackcosserat]
    type = RedbackMechMaterialHO
    block = 0
    B_ijkl = '0.0 4.624E2  4.624E2'
    C_ijkl = '8.0E1 2.0E1 1.0E1'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.5
    hardening_mech_modulus = 0.1
    pore_pres = pore_pressure
    plasticity_type = DeBorst_2D
    temperature = temperature
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
    pressurization_coefficient = 1
    solid_thermal_expansion = 8e-4
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type    -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres          bjacobi     1E-6           1E-8          30                1E-8     1E-10 '
    line_search = basic
  [../]
  [./debug_jacob]
    type = FDP
    full = true
  [../]
  [./default]
    type = SMP
    solve_type = NEWTON
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  dt = 0.25
  l_max_its = 200
  solve_type = NEWTON
  num_steps = 500
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
  [./TimeStepper]
    type = PostprocessorDT
    postprocessor = timestep
  [../]
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = biaxial_pres_msh20_lh02_dt025_hardpos01_thermpres1
  print_linear_residuals = false
[]
