[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 40
  xmax = 0.04
  ymax = 0.04
  zmax = 0.04
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
  active  = 'tangential_force disp_y_top normal_force number_nonlin dt number_lin disp_x_bottom wc_z_top disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39'
  [./disp_x_0]
    type = PointValue
    point = '0. 0.0 0.'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0. 0.001 0.'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0. 0.002 0.'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0. 0.003 0.'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0. 0.004 0.'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0. 0.005 0.'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0. 0.006 0.'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0. 0.007 0.'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0. 0.008 0.'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0. 0.009 0.'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0. 0.01 0.'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0. 0.011 0.'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0. 0.012 0.'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0. 0.013 0.'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0. 0.014 0.'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0. 0.015 0.'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0. 0.016 0.'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0. 0.017 0.'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0. 0.018 0.'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0. 0.019 0.'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0. 0.02 0.'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0. 0.021 0.'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0. 0.022 0.'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0. 0.023 0.'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0. 0.024 0.'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0. 0.025 0.'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0. 0.026 0.'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0. 0.027 0.'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0. 0.028 0.'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0. 0.029 0.'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0. 0.03 0.'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0. 0.031 0.'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0. 0.032 0.'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0. 0.033 0.'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0. 0.034 0.'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0. 0.035 0.'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0. 0.036 0.'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0. 0.037 0.'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0. 0.038 0.'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0. 0.039 0.'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0. 0.04 0.'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0. 0.0005 0.'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0. 0.0015 0.'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0. 0.0025 0.'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0. 0.0035 0.'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0. 0.0045 0.'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0. 0.0055 0.'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0. 0.0065 0.'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0. 0.0075 0.'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0. 0.0085 0.'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0. 0.0095 0.'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0. 0.0105 0.'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0. 0.0115 0.'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0. 0.0125 0.'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0. 0.0135 0.'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0. 0.0145 0.'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0. 0.0155 0.'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0. 0.0165 0.'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0. 0.0175 0.'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0. 0.0185 0.'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0. 0.0195 0.'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0. 0.0205 0.'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0. 0.0215 0.'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0. 0.0225 0.'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0. 0.0235 0.'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0. 0.0245 0.'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0. 0.0255 0.'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0. 0.0265 0.'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0. 0.0275 0.'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0. 0.0285 0.'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0. 0.0295 0.'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0. 0.0305 0.'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0. 0.0315 0.'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0. 0.0325 0.'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0. 0.0335 0.'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0. 0.0345 0.'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0. 0.0355 0.'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0. 0.0365 0.'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0. 0.0375 0.'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0. 0.0385 0.'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0. 0.0395 0.'
    variable = lagrange
  [../]
  [./disp_y_top]
    type = PointValue
    point = '0.04 0.04 0.04'
    variable = disp_y
  [../]
  [./wc_z_top]
    type = PointValue
    point = '0.04 0.04 0.04'
    variable = wc_z
  [../]
  [./Rotation_wcz_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 1'
  [../]
  [./Rotation_wcz_0_8]
    type = PointValue
    variable = wc_z
    point = '0.5 0.8 1'
  [../]
  [./Rotation_wcz_0_7]
    type = PointValue
    variable = wc_z
    point = '0.5 0.7 1'
  [../]
  [./Rotation_wcz_0_6]
    type = PointValue
    variable = wc_z
    point = '0.5 0.6 1'
  [../]
  [./Rotation_wcz_0_5]
    type = PointValue
    variable = wc_z
    point = '0.5 0.5 1'
  [../]
  [./Rotation_wcz_0_4]
    type = PointValue
    variable = wc_z
    point = '0.5 0.4 1'
  [../]
  [./Rotation_wcz_0_3]
    type = PointValue
    variable = wc_z
    point = '0.5 0.3 1'
  [../]
  [./Rotation_wcz_0_2]
    type = PointValue
    variable = wc_z
    point = '0.5 0.2 1'
  [../]
  [./Rotation_wcz_0_1]
    type = PointValue
    variable = wc_z
    point = '0.5 0.1 1'
  [../]
  [./Displ_u_x_0_9]
    type = PointValue
    variable = wc_z
    point = '0.5 0.9 1'
  [../]
  [./Displ_u_x_0_8]
    type = PointValue
    variable = disp_x
    point = '0.5 0.8 1'
  [../]
  [./Displ_u_x_0_7]
    type = PointValue
    variable = disp_x
    point = '0.5 0.7 1'
  [../]
  [./Displ_u_x_0_6]
    type = PointValue
    variable = disp_x
    point = '0.5 0.6 1'
  [../]
  [./Displ_u_x_0_5]
    type = PointValue
    variable = disp_x
    point = '0.5 0.5 1'
  [../]
  [./Displ_u_x_0_4]
    type = PointValue
    variable = disp_x
    point = '0.5 0.4 1'
  [../]
  [./Displ_u_x_0_3]
    type = PointValue
    variable = disp_x
    point = '0.5 0.3 1'
  [../]
  [./Displ_u_x_0_2]
    type = PointValue
    variable = disp_x
    point = '0.5 0.2 1'
  [../]
  [./Displ_u_x_0_1]
    type = PointValue
    variable = disp_x
    point = '0.5 0.1 1'
  [../]
  [./antisymmetric_top]
    type = SideAverageValue
    variable = macro_rot
    execute_on = linear
    boundary = top
  [../]
  [./number_nonlin]
    type = NumNonlinearIterations
  [../]
  [./number_lin]
    type = NumLinearIterations
  [../]
  [./normal_force]
    type = SideAverageValue
    variable = stress_22
    execute_on = linear
    boundary = top
  [../]
  [./tangential_force]
    type = SideAverageValue
    variable = stress_12
    boundary = top
  [../]
  [./antisymmetric_bottom]
    type = SideAverageValue
    variable = macro_rot
    execute_on = linear
    boundary = bottom
  [../]
  [./disp_x_bottom]
    type = PointValue
    variable = disp_x
    point = '0.04 0 0.04'
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
  active = 'ramp_neg ramp'
  [./ramp]
    # -0.0005*t
    type = ParsedFunction
    value = 0.0001*t
  [../]
  [./ramp_neg]
    type = ParsedFunction
    value = -0.0005*t
  [../]
  [./perturb]
    type = ParsedFunction
    value = 0.001*sin(pi*y/(0.04))
  [../]
[]

[Kernels]
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
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
    disp_z = wc_y
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
    type = MomentBalancing
    variable = wc_x
    component = 0
  [../]
  [./y_moment]
    type = MomentBalancing
    variable = wc_y
    component = 1
  [../]
  [./z_moment]
    type = MomentBalancing
    variable = wc_z
    component = 2
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
    execute_on = timestep_end
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
  active = 'Periodic wcy_equals_zero_on_top wc_x_bottom wcz_imposed_top ux_shear_bottom wcx_equals_zero_on_top confining_pres uz_bottom wc_z_bottom_zero uy_bottom ux_zero_top wc_y_bottom'
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
    value = 0
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
    type = FunctionDirichletBC
    variable = disp_x
    boundary = bottom
    function = ramp
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
    value = 0
  [../]
  [./wc_z_bottom_zero]
    type = DirichletBC
    variable = wc_z
    boundary = bottom
    value = 0
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
  [./Periodic]
    [./x_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
      auto_direction = x
    [../]
    [./z_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
      auto_direction = z
    [../]
  [../]
  [./u_x_right_left]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
  [./ux_nodes_zero]
    type = DirichletBC
    variable = disp_x
    boundary = '77 78'
    value = 0
  [../]
  [./uy_nodes_zero]
    type = DirichletBC
    variable = disp_z
    boundary = '79 80'
    value = 0
  [../]
  [./ux_shear_bottom]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = bottom
    function = ramp
  [../]
  [./Rotation_wcz_top]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = top
    postprocessor = antisymmetric_pp
  [../]
  [./confining_pres]
    type = NeumannBC
    variable = disp_y
    boundary = top
    value = -1E5
  [../]
  [./Rotation_wc_z_bottom]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = bottom
    postprocessor = antisymmetric_bottom
  [../]
  [./rotation_wcz_top]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = top
    postprocessor = antisymmetric_top
  [../]
  [./ux_zero_top]
    type = DirichletBC
    variable = disp_x
    boundary = top
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
    # 0 2.6549E3 2.6549E3
    type = RedbackMechMaterialHO
    block = 0
    B_ijkl = '0 1.6991E1 1.6991E1'
    C_ijkl = '4.6640E6 1.3274E7 6.6372E6'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 1E5
    hardening_mech_modulus = -10
    friction_coefficient = 0.4
    min_stepsize = 1e-8
    plasticity_type = DruckerPrager_friction3D
    ignore_failures = false
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type    -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres          bjacobi     1E-10          1E-8          20                1E-12      1E-10 '
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
  dt = 0.2
  solve_type = NEWTON
  num_steps = 10000
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = plastic_shear_r08
  print_linear_residuals = false
[]
