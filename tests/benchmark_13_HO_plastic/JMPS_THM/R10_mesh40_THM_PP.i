[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 40
  xmax = 1
  ymax = 1
  zmax = 1
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
  active  = 'number_nonlin wc_z_mid Temperature_mid pressure_mid disp_y_top number_lin normal_force tangential_force disp_x_top dt strain_12_mid strain_12_pl_mid disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 moment_0 moment_1 moment_2 moment_3 moment_4 moment_5 moment_6 moment_7 moment_8 moment_9 moment_10 moment_11 moment_12 moment_13 moment_14 moment_15 moment_16 moment_17 moment_18 moment_19 moment_20 moment_21 moment_22 moment_23 moment_24 moment_25 moment_26 moment_27 moment_28 moment_29 moment_30 moment_31 moment_32 moment_33 moment_34 moment_35 moment_36 moment_37 moment_38 moment_39 failure_0 failure_1 failure_2 failure_3 failure_4 failure_5 failure_6 failure_7 failure_8 failure_9 failure_10 failure_11 failure_12 failure_13 failure_14 failure_15 failure_16 failure_17 failure_18 failure_19 failure_20 failure_21 failure_22 failure_23 failure_24 failure_25 failure_26 failure_27 failure_28 failure_29 failure_30 failure_31 failure_32 failure_33 failure_34 failure_35 failure_36 failure_37 failure_38 failure_39'
  [./disp_x_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0.0 0.025 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 0.05 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 0.075 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 0.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 0.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 0.15 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 0.175 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 0.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 0.225 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 0.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 0.275 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 0.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 0.325 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 0.35 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 0.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 0.425 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 0.45 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 0.475 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 0.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 0.525 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 0.55 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 0.575 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 0.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 0.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 0.65 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 0.675 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 0.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 0.725 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 0.775 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 0.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 0.825 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 0.85 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 0.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 0.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 0.925 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 0.95 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 0.975 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 1.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.0125 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 0.0375 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 0.0625 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 0.0875 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 0.1125 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 0.1375 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 0.1625 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 0.1875 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 0.2125 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 0.2375 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 0.2625 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 0.2875 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 0.3125 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 0.3375 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 0.3625 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 0.3875 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 0.4125 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 0.4375 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 0.4625 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 0.4875 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 0.5125 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 0.5375 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 0.5625 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 0.5875 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 0.6125 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 0.6375 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 0.6625 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 0.6875 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 0.7125 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 0.7375 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 0.7625 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 0.7875 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 0.8125 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 0.8375 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 0.8625 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 0.8875 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 0.9125 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 0.9375 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 0.9625 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 0.9875 0.0'
    variable = lagrange
  [../]
  [./moment_0]
    type = PointValue
    point = '0.0 0.0125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_1]
    type = PointValue
    point = '0.0 0.0375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_2]
    type = PointValue
    point = '0.0 0.0625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_3]
    type = PointValue
    point = '0.0 0.0875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_4]
    type = PointValue
    point = '0.0 0.1125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_5]
    type = PointValue
    point = '0.0 0.1375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_6]
    type = PointValue
    point = '0.0 0.1625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_7]
    type = PointValue
    point = '0.0 0.1875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_8]
    type = PointValue
    point = '0.0 0.2125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_9]
    type = PointValue
    point = '0.0 0.2375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_10]
    type = PointValue
    point = '0.0 0.2625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_11]
    type = PointValue
    point = '0.0 0.2875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_12]
    type = PointValue
    point = '0.0 0.3125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_13]
    type = PointValue
    point = '0.0 0.3375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_14]
    type = PointValue
    point = '0.0 0.3625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_15]
    type = PointValue
    point = '0.0 0.3875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_16]
    type = PointValue
    point = '0.0 0.4125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_17]
    type = PointValue
    point = '0.0 0.4375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_18]
    type = PointValue
    point = '0.0 0.4625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_19]
    type = PointValue
    point = '0.0 0.4875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_20]
    type = PointValue
    point = '0.0 0.5125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_21]
    type = PointValue
    point = '0.0 0.5375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_22]
    type = PointValue
    point = '0.0 0.5625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_23]
    type = PointValue
    point = '0.0 0.5875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_24]
    type = PointValue
    point = '0.0 0.6125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_25]
    type = PointValue
    point = '0.0 0.6375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_26]
    type = PointValue
    point = '0.0 0.6625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_27]
    type = PointValue
    point = '0.0 0.6875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_28]
    type = PointValue
    point = '0.0 0.7125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_29]
    type = PointValue
    point = '0.0 0.7375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_30]
    type = PointValue
    point = '0.0 0.7625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_31]
    type = PointValue
    point = '0.0 0.7875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_32]
    type = PointValue
    point = '0.0 0.8125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_33]
    type = PointValue
    point = '0.0 0.8375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_34]
    type = PointValue
    point = '0.0 0.8625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_35]
    type = PointValue
    point = '0.0 0.8875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_36]
    type = PointValue
    point = '0.0 0.9125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_37]
    type = PointValue
    point = '0.0 0.9375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_38]
    type = PointValue
    point = '0.0 0.9625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_39]
    type = PointValue
    point = '0.0 0.9875 0.0'
    variable = couple_stress_32
  [../]
  [./failure_0]
    type = PointValue
    point = '0.0 0.0125 0.0'
    variable = failure
  [../]
  [./failure_1]
    type = PointValue
    point = '0.0 0.0375 0.0'
    variable = failure
  [../]
  [./failure_2]
    type = PointValue
    point = '0.0 0.0625 0.0'
    variable = failure
  [../]
  [./failure_3]
    type = PointValue
    point = '0.0 0.0875 0.0'
    variable = failure
  [../]
  [./failure_4]
    type = PointValue
    point = '0.0 0.1125 0.0'
    variable = failure
  [../]
  [./failure_5]
    type = PointValue
    point = '0.0 0.1375 0.0'
    variable = failure
  [../]
  [./failure_6]
    type = PointValue
    point = '0.0 0.1625 0.0'
    variable = failure
  [../]
  [./failure_7]
    type = PointValue
    point = '0.0 0.1875 0.0'
    variable = failure
  [../]
  [./failure_8]
    type = PointValue
    point = '0.0 0.2125 0.0'
    variable = failure
  [../]
  [./failure_9]
    type = PointValue
    point = '0.0 0.2375 0.0'
    variable = failure
  [../]
  [./failure_10]
    type = PointValue
    point = '0.0 0.2625 0.0'
    variable = failure
  [../]
  [./failure_11]
    type = PointValue
    point = '0.0 0.2875 0.0'
    variable = failure
  [../]
  [./failure_12]
    type = PointValue
    point = '0.0 0.3125 0.0'
    variable = failure
  [../]
  [./failure_13]
    type = PointValue
    point = '0.0 0.3375 0.0'
    variable = failure
  [../]
  [./failure_14]
    type = PointValue
    point = '0.0 0.3625 0.0'
    variable = failure
  [../]
  [./failure_15]
    type = PointValue
    point = '0.0 0.3875 0.0'
    variable = failure
  [../]
  [./failure_16]
    type = PointValue
    point = '0.0 0.4125 0.0'
    variable = failure
  [../]
  [./failure_17]
    type = PointValue
    point = '0.0 0.4375 0.0'
    variable = failure
  [../]
  [./failure_18]
    type = PointValue
    point = '0.0 0.4625 0.0'
    variable = failure
  [../]
  [./failure_19]
    type = PointValue
    point = '0.0 0.4875 0.0'
    variable = failure
  [../]
  [./failure_20]
    type = PointValue
    point = '0.0 0.5125 0.0'
    variable = failure
  [../]
  [./failure_21]
    type = PointValue
    point = '0.0 0.5375 0.0'
    variable = failure
  [../]
  [./failure_22]
    type = PointValue
    point = '0.0 0.5625 0.0'
    variable = failure
  [../]
  [./failure_23]
    type = PointValue
    point = '0.0 0.5875 0.0'
    variable = failure
  [../]
  [./failure_24]
    type = PointValue
    point = '0.0 0.6125 0.0'
    variable = failure
  [../]
  [./failure_25]
    type = PointValue
    point = '0.0 0.6375 0.0'
    variable = failure
  [../]
  [./failure_26]
    type = PointValue
    point = '0.0 0.6625 0.0'
    variable = failure
  [../]
  [./failure_27]
    type = PointValue
    point = '0.0 0.6875 0.0'
    variable = failure
  [../]
  [./failure_28]
    type = PointValue
    point = '0.0 0.7125 0.0'
    variable = failure
  [../]
  [./failure_29]
    type = PointValue
    point = '0.0 0.7375 0.0'
    variable = failure
  [../]
  [./failure_30]
    type = PointValue
    point = '0.0 0.7625 0.0'
    variable = failure
  [../]
  [./failure_31]
    type = PointValue
    point = '0.0 0.7875 0.0'
    variable = failure
  [../]
  [./failure_32]
    type = PointValue
    point = '0.0 0.8125 0.0'
    variable = failure
  [../]
  [./failure_33]
    type = PointValue
    point = '0.0 0.8375 0.0'
    variable = failure
  [../]
  [./failure_34]
    type = PointValue
    point = '0.0 0.8625 0.0'
    variable = failure
  [../]
  [./failure_35]
    type = PointValue
    point = '0.0 0.8875 0.0'
    variable = failure
  [../]
  [./failure_36]
    type = PointValue
    point = '0.0 0.9125 0.0'
    variable = failure
  [../]
  [./failure_37]
    type = PointValue
    point = '0.0 0.9375 0.0'
    variable = failure
  [../]
  [./failure_38]
    type = PointValue
    point = '0.0 0.9625 0.0'
    variable = failure
  [../]
  [./failure_39]
    type = PointValue
    point = '0.0 0.9875 0.0'
    variable = failure
  [../]
  [./disp_y_top]
    type = SideAverageValue
    variable = disp_y
    execute_on = linear
    boundary = top
  [../]
  [./wc_z_mid]
    type = PointValue
    point = '1 0.5 1'
    variable = wc_z
  [../]
  [./Temperature_mid]
    type = PointValue
    point = '1 0.5 1'
    variable = temperature
  [../]
  [./pressure_mid]
    type = PointValue
    point = '1 0.5 1'
    variable = pore_pressure
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
  [./disp_x_top]
    type = PointValue
    variable = disp_x
    point = '1 1 1'
  [../]
  [./dt]
    type = TimestepSize
  [../]
  [./strain_12_mid]
    type = PointValue
    point = '1 0.5 1'
    variable = strain_12
  [../]
  [./strain_12_pl_mid]
    type = PointValue
    point = '1 0.5 1'
    variable = plastic_12
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
  [./stress_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_33]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_21]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_23]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_32]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_13]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./stress_31]
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
  [./epsilon_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./epsilon_22]
    family = MONOMIAL
  [../]
  [./strain_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_21]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./strain_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./macro_rot]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_21]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_33]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./plastic_cur_21]
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
  [./plastic_cur_13]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_11]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_22]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_33]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_12]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_21]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_32]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_23]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_31]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./elastic_strain_13]
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
  [./mech_dissip]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./mech_dissip_energy]
    order = CONSTANT
    family = MONOMIAL
  [../]

[]

[Functions]
  active = 'ramp_neg ramp'
  [./ramp]
    type = ParsedFunction
    value = if(t>0.000002,1000*(t-0.000002),0)
  [../]
  [./ramp_neg]
    type = ParsedFunction
    value = -0.0005*t
  [../]
  [./perturb]
    type = ParsedFunction
    value = 0.001*sin(pi*y/(60))
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
  [./mech_dissip]
    type = RedbackMechDissip
    variable = temperature
    displacements = 'disp_x disp_y disp_z'
    rotations = 'wc_x wc_y wc_z'
  [../]
  [./dT_dt]
    type = TimeDerivative
    variable = temperature
  [../]
  [./dp_dt]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./thermal_press]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temperature
  [../]
  [./poromech]
    type = RedbackPoroMechHO
    variable = pore_pressure
    displacements = 'disp_x disp_y disp_z'
  [../]
  [./T_diff]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
  [./P_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
[]

[AuxKernels]
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
  [./stress_11]
    type = RankTwoAux
    variable = stress_11
    rank_two_tensor = stress
    index_j = 0
    index_i = 0
  [../]
  [./stress_22]
    type = RankTwoAux
    variable = stress_22
    rank_two_tensor = stress
    index_j = 1
    index_i = 1
  [../]
  [./stress_33]
    type = RankTwoAux
    variable = stress_33
    rank_two_tensor = stress
    index_j = 2
    index_i = 2
  [../]
  [./stress_12]
    type = RankTwoAux
    variable = stress_12
    rank_two_tensor = stress
    index_j = 1
    index_i = 0
  [../]
  [./stress_21]
    type = RankTwoAux
    variable = stress_21
    rank_two_tensor = stress
    index_j = 0
    index_i = 1
  [../]
  [./stress_23]
    type = RankTwoAux
    variable = stress_23
    rank_two_tensor = stress
    index_j = 2
    index_i = 1
  [../]
  [./stress_32]
    type = RankTwoAux
    variable = stress_32
    rank_two_tensor = stress
    index_j = 1
    index_i = 2
  [../]
  [./stress_31]
    type = RankTwoAux
    variable = stress_31
    rank_two_tensor = stress
    index_j = 0
    index_i = 2
  [../]
  [./stress_13]
    type = RankTwoAux
    variable = stress_13
    rank_two_tensor = stress
    index_j = 2
    index_i = 0
  [../]
  [./couple_stress_32]
    type = RankTwoAux
    variable = couple_stress_32
    rank_two_tensor = coupled_stress
    index_j = 1
    index_i = 2
    execute_on = nonlinear
  [../]
  [./couple_stress_23]
    type = RankTwoAux
    variable = couple_stress_23
    rank_two_tensor = coupled_stress
    index_j = 2
    index_i = 1
    execute_on = nonlinear
  [../]
  [./epsilon_11]
    type = RankTwoAux
    variable = epsilon_11
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./epsilon_22]
    type = RankTwoAux
    variable = epsilon_22
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./strain_12]
    type = RankTwoAux
    variable = strain_12
    rank_two_tensor = total_strain
    index_j = 1
    index_i = 0
  [../]
  [./strain_21]
    type = RankTwoAux
    variable = strain_21
    rank_two_tensor = total_strain
    index_j = 0
    index_i = 1
  [../]
  [./strain_22]
    type = RankTwoAux
    variable = strain_22
    rank_two_tensor = total_strain
    index_j = 1
    index_i = 1
  [../]
  [./strain_11]
    type = RankTwoAux
    variable = strain_11
    rank_two_tensor = total_strain
    index_j = 0
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
  [./plastic_yx]
    type = RankTwoAux
    variable = plastic_21
    rank_two_tensor = plastic_strain
    index_j = 0
    index_i = 1
  [../]
  [./plastic_curv_11]
    type = RankTwoAux
    variable = plastic_cur_11
    rank_two_tensor = plastic_curvature
    index_j = 0
    index_i = 0
  [../]
  [./plastic_curv_22]
    type = RankTwoAux
    variable = plastic_cur_22
    rank_two_tensor = plastic_curvature
    index_j = 1
    index_i = 1
  [../]
  [./plastic_curv_33]
    type = RankTwoAux
    variable = plastic_cur_33
    rank_two_tensor = plastic_curvature
    index_j = 2
    index_i = 2
  [../]
  [./plastic_curv_12]
    type = RankTwoAux
    variable = plastic_cur_12
    rank_two_tensor = plastic_curvature
    index_j = 1
    index_i = 0
  [../]
  [./plastic_curv_21]
    type = RankTwoAux
    variable = plastic_cur_21
    rank_two_tensor = plastic_curvature
    index_j = 0
    index_i = 1
  [../]
  [./plastic_curv_32]
    type = RankTwoAux
    variable = plastic_cur_32
    rank_two_tensor = plastic_curvature
    index_j = 1
    index_i = 2
  [../]
  [./plastic_curv_23]
    type = RankTwoAux
    variable = plastic_cur_23
    rank_two_tensor = plastic_curvature
    index_j = 2
    index_i = 1
  [../]
  [./plastic_curv_31]
    type = RankTwoAux
    variable = plastic_cur_31
    rank_two_tensor = plastic_curvature
    index_j = 0
    index_i = 2
  [../]
  [./plastic_curv_13]
    type = RankTwoAux
    variable = plastic_cur_13
    rank_two_tensor = plastic_curvature
    index_j = 2
    index_i = 0
  [../]
  [./elastic_strain_11]
    type = RankTwoAux
    variable = elastic_strain_11
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 0
  [../]
  [./elastic_strain_22]
    type = RankTwoAux
    variable = elastic_strain_22
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 1
  [../]
  [./elastic_strain_33]
    type = RankTwoAux
    variable = elastic_strain_33
    rank_two_tensor = elastic_strain
    index_j = 2
    index_i = 2
  [../]
  [./elastic_strain_12]
    type = RankTwoAux
    variable = elastic_strain_12
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 0
  [../]
  [./elastic_strain_21]
    type = RankTwoAux
    variable = elastic_strain_21
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 1
  [../]
  [./elastic_strain_32]
    type = RankTwoAux
    variable = elastic_strain_32
    rank_two_tensor = elastic_strain
    index_j = 1
    index_i = 2
  [../]
  [./elastic_strain_23]
    type = RankTwoAux
    variable = elastic_strain_23
    rank_two_tensor = elastic_strain
    index_j = 2
    index_i = 1
  [../]
  [./elastic_strain_31]
    type = RankTwoAux
    variable = elastic_strain_31
    rank_two_tensor = elastic_strain
    index_j = 0
    index_i = 2
  [../]
  [./elastic_strain_13]
    type = RankTwoAux
    variable = elastic_strain_13
    rank_two_tensor = elastic_strain
    index_j = 2
    index_i = 0
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
  [./mech_dissip]
    type = MaterialRealAux
    variable = mech_dissip
    property = mechanical_dissipation_mech
  [../]
  [./mech_dissip_energy]
    type = MaterialRealAux
    variable = mech_dissip_energy
    property = mechanical_dissipation_tot
  [../]
[]

[BCs]
  # following is natural BC
  active = 'Periodic uy_bottom uy_ramp_top ux_ramp_top wcz_imposed_top wcx_equals_zero_on_top ux_zero_bottom wcy_equals_zero_on_top wc_x_bottom uz_bottom wc_z_bottom_zero wc_y_bottom'
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
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 0
    function = 0.0
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
    type = NeumannBC
    variable = disp_y
    boundary = top
    value = -133.333
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
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pore_pressure'
      auto_direction = x
    [../]
    [./z_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pore_pressure'
      auto_direction = z
    [../]
  [../]
  [./u_x_right_left]
    type = DirichletBC
    variable = disp_x
    boundary = right
    value = 0
  [../]
  [./Rotation_wcz_top]
    type = PostprocessorDirichletBC
    variable = wc_z
    boundary = top
    postprocessor = antisymmetric_pp
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
  [./ux_ramp_top]
    type = FunctionDirichletBC
    variable = disp_x
    boundary = top
    function = ramp
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
    B_ijkl = '0 2.0 2.0'
    C_ijkl = '1.3333E4 1.0E4 5.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.01
    hardening_mech_modulus = -1
    friction_coefficient = 0.5
    min_stepsize = 1e-8
    beta_star = 8.19672E5
    plasticity_type = DruckerPrager_friction3D
    pore_pres = pore_pressure
    temperature = temperature
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
    gr = 0.357142857
    pressurization_coefficient = 0.9
    solid_thermal_expansion = 2.5E-5
    ref_lewis_nb = 0.08196721
    pore_pres = pore_pressure
    temperature = temperature
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type    -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres          bjacobi     1E-6        1E-8      40      1E-12      1E-10 '
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
  dt = 0.000001
  solve_type = NEWTON
  num_steps = 2000
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = shear_R10_mesh40_THM_rice
  print_linear_residuals = false
[]

