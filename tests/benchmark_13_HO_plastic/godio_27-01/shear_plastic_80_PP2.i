[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 80
  xmax = 60
  ymax = 60
  zmax = 60
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
  active  = 'number_lin disp_y_top tangential_force normal_force number_nonlin disp_x_bottom wc_z_top dt disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 disp_x_41 disp_x_42 disp_x_43 disp_x_44 disp_x_45 disp_x_46 disp_x_47 disp_x_48 disp_x_49 disp_x_50 disp_x_51 disp_x_52 disp_x_53 disp_x_54 disp_x_55 disp_x_56 disp_x_57 disp_x_58 disp_x_59 disp_x_60 disp_x_61 disp_x_62 disp_x_63 disp_x_64 disp_x_65 disp_x_66 disp_x_67 disp_x_68 disp_x_69 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 disp_x_80 wc_z_0 wc_z_1 wc_z_2 wc_z_3 wc_z_4 wc_z_5 wc_z_6 wc_z_7 wc_z_8 wc_z_9 wc_z_10 wc_z_11 wc_z_12 wc_z_13 wc_z_14 wc_z_15 wc_z_16 wc_z_17 wc_z_18 wc_z_19 wc_z_20 wc_z_21 wc_z_22 wc_z_23 wc_z_24 wc_z_25 wc_z_26 wc_z_27 wc_z_28 wc_z_29 wc_z_30 wc_z_31 wc_z_32 wc_z_33 wc_z_34 wc_z_35 wc_z_36 wc_z_37 wc_z_38 wc_z_39 wc_z_40 wc_z_41 wc_z_42 wc_z_43 wc_z_44 wc_z_45 wc_z_46 wc_z_47 wc_z_48 wc_z_49 wc_z_50 wc_z_51 wc_z_52 wc_z_53 wc_z_54 wc_z_55 wc_z_56 wc_z_57 wc_z_58 wc_z_59 wc_z_60 wc_z_61 wc_z_62 wc_z_63 wc_z_64 wc_z_65 wc_z_66 wc_z_67 wc_z_68 wc_z_69 wc_z_70 wc_z_71 wc_z_72 wc_z_73 wc_z_74 wc_z_75 wc_z_76 wc_z_77 wc_z_78 wc_z_79 wc_z_80 strain_xy_0 strain_xy_1 strain_xy_2 strain_xy_3 strain_xy_4 strain_xy_5 strain_xy_6 strain_xy_7 strain_xy_8 strain_xy_9 strain_xy_10 strain_xy_11 strain_xy_12 strain_xy_13 strain_xy_14 strain_xy_15 strain_xy_16 strain_xy_17 strain_xy_18 strain_xy_19 strain_xy_20 strain_xy_21 strain_xy_22 strain_xy_23 strain_xy_24 strain_xy_25 strain_xy_26 strain_xy_27 strain_xy_28 strain_xy_29 strain_xy_30 strain_xy_31 strain_xy_32 strain_xy_33 strain_xy_34 strain_xy_35 strain_xy_36 strain_xy_37 strain_xy_38 strain_xy_39 strain_xy_40 strain_xy_41 strain_xy_42 strain_xy_43 strain_xy_44 strain_xy_45 strain_xy_46 strain_xy_47 strain_xy_48 strain_xy_49 strain_xy_50 strain_xy_51 strain_xy_52 strain_xy_53 strain_xy_54 strain_xy_55 strain_xy_56 strain_xy_57 strain_xy_58 strain_xy_59 strain_xy_60 strain_xy_61 strain_xy_62 strain_xy_63 strain_xy_64 strain_xy_65 strain_xy_66 strain_xy_67 strain_xy_68 strain_xy_69 strain_xy_70 strain_xy_71 strain_xy_72 strain_xy_73 strain_xy_74 strain_xy_75 strain_xy_76 strain_xy_77 strain_xy_78 strain_xy_79 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 lagrange_40 lagrange_41 lagrange_42 lagrange_43 lagrange_44 lagrange_45 lagrange_46 lagrange_47 lagrange_48 lagrange_49 lagrange_50 lagrange_51 lagrange_52 lagrange_53 lagrange_54 lagrange_55 lagrange_56 lagrange_57 lagrange_58 lagrange_59 lagrange_60 lagrange_61 lagrange_62 lagrange_63 lagrange_64 lagrange_65 lagrange_66 lagrange_67 lagrange_68 lagrange_69 lagrange_70 lagrange_71 lagrange_72 lagrange_73 lagrange_74 lagrange_75 lagrange_76 lagrange_77 lagrange_78 lagrange_79'
  [./wc_z_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_1]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_2]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_3]
    type = PointValue
    point = '0.0 2.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_4]
    type = PointValue
    point = '0.0 3.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_5]
    type = PointValue
    point = '0.0 3.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_6]
    type = PointValue
    point = '0.0 4.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_7]
    type = PointValue
    point = '0.0 5.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_8]
    type = PointValue
    point = '0.0 6.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_9]
    type = PointValue
    point = '0.0 6.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_10]
    type = PointValue
    point = '0.0 7.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_11]
    type = PointValue
    point = '0.0 8.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_12]
    type = PointValue
    point = '0.0 9.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_13]
    type = PointValue
    point = '0.0 9.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_14]
    type = PointValue
    point = '0.0 10.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_15]
    type = PointValue
    point = '0.0 11.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_16]
    type = PointValue
    point = '0.0 12.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_17]
    type = PointValue
    point = '0.0 12.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_18]
    type = PointValue
    point = '0.0 13.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_19]
    type = PointValue
    point = '0.0 14.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_20]
    type = PointValue
    point = '0.0 15.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_21]
    type = PointValue
    point = '0.0 15.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_22]
    type = PointValue
    point = '0.0 16.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_23]
    type = PointValue
    point = '0.0 17.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_24]
    type = PointValue
    point = '0.0 18.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_25]
    type = PointValue
    point = '0.0 18.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_26]
    type = PointValue
    point = '0.0 19.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_27]
    type = PointValue
    point = '0.0 20.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_28]
    type = PointValue
    point = '0.0 21.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_29]
    type = PointValue
    point = '0.0 21.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_30]
    type = PointValue
    point = '0.0 22.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_31]
    type = PointValue
    point = '0.0 23.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_32]
    type = PointValue
    point = '0.0 24.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_33]
    type = PointValue
    point = '0.0 24.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_34]
    type = PointValue
    point = '0.0 25.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_35]
    type = PointValue
    point = '0.0 26.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_36]
    type = PointValue
    point = '0.0 27.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_37]
    type = PointValue
    point = '0.0 27.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_38]
    type = PointValue
    point = '0.0 28.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_39]
    type = PointValue
    point = '0.0 29.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_40]
    type = PointValue
    point = '0.0 30.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_41]
    type = PointValue
    point = '0.0 30.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_42]
    type = PointValue
    point = '0.0 31.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_43]
    type = PointValue
    point = '0.0 32.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_44]
    type = PointValue
    point = '0.0 33.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_45]
    type = PointValue
    point = '0.0 33.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_46]
    type = PointValue
    point = '0.0 34.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_47]
    type = PointValue
    point = '0.0 35.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_48]
    type = PointValue
    point = '0.0 36.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_49]
    type = PointValue
    point = '0.0 36.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_50]
    type = PointValue
    point = '0.0 37.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_51]
    type = PointValue
    point = '0.0 38.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_52]
    type = PointValue
    point = '0.0 39.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_53]
    type = PointValue
    point = '0.0 39.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_54]
    type = PointValue
    point = '0.0 40.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_55]
    type = PointValue
    point = '0.0 41.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_56]
    type = PointValue
    point = '0.0 42.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_57]
    type = PointValue
    point = '0.0 42.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_58]
    type = PointValue
    point = '0.0 43.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_59]
    type = PointValue
    point = '0.0 44.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_60]
    type = PointValue
    point = '0.0 45.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_61]
    type = PointValue
    point = '0.0 45.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_62]
    type = PointValue
    point = '0.0 46.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_63]
    type = PointValue
    point = '0.0 47.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_64]
    type = PointValue
    point = '0.0 48.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_65]
    type = PointValue
    point = '0.0 48.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_66]
    type = PointValue
    point = '0.0 49.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_67]
    type = PointValue
    point = '0.0 50.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_68]
    type = PointValue
    point = '0.0 51.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_69]
    type = PointValue
    point = '0.0 51.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_70]
    type = PointValue
    point = '0.0 52.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_71]
    type = PointValue
    point = '0.0 53.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_72]
    type = PointValue
    point = '0.0 54.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_73]
    type = PointValue
    point = '0.0 54.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_74]
    type = PointValue
    point = '0.0 55.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_75]
    type = PointValue
    point = '0.0 56.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_76]
    type = PointValue
    point = '0.0 57.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_77]
    type = PointValue
    point = '0.0 57.75 0.0'
    variable = wc_z
  [../]
  [./wc_z_78]
    type = PointValue
    point = '0.0 58.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_79]
    type = PointValue
    point = '0.0 59.25 0.0'
    variable = wc_z
  [../]
  [./wc_z_80]
    type = PointValue
    point = '0.0 60.0 0.0'
    variable = wc_z
  [../]
  [./disp_x_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 2.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 3.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 3.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 4.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 5.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 6.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 6.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 7.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 8.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 9.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 9.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 10.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 11.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 12.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 12.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 13.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 14.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 15.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 15.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 16.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 17.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 18.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 18.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 19.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 20.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 21.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 21.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 22.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 23.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 24.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 24.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 25.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 26.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 27.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 27.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 28.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 29.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 30.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '0.0 30.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '0.0 31.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '0.0 32.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '0.0 33.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '0.0 33.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '0.0 34.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '0.0 35.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '0.0 36.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '0.0 36.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '0.0 37.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '0.0 38.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '0.0 39.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '0.0 39.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '0.0 40.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '0.0 41.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '0.0 42.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '0.0 42.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '0.0 43.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '0.0 44.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '0.0 45.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '0.0 45.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '0.0 46.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '0.0 47.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '0.0 48.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '0.0 48.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '0.0 49.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '0.0 50.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '0.0 51.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '0.0 51.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '0.0 52.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '0.0 53.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '0.0 54.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '0.0 54.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '0.0 55.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '0.0 56.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '0.0 57.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '0.0 57.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '0.0 58.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '0.0 59.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '0.0 60.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 1.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 1.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 2.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 3.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 4.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 4.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 5.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 6.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 7.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 7.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 8.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 9.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 10.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 10.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 11.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 12.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 13.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 13.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 14.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 15.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 16.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 16.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 17.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 18.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 19.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 19.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 20.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 21.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 22.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 22.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 23.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 24.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 25.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 25.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 26.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 27.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 28.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 28.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 29.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '0.0 30.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '0.0 31.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '0.0 31.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '0.0 32.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '0.0 33.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '0.0 34.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '0.0 34.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '0.0 35.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '0.0 36.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '0.0 37.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '0.0 37.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '0.0 38.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '0.0 39.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '0.0 40.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '0.0 40.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '0.0 41.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '0.0 42.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '0.0 43.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '0.0 43.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '0.0 44.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '0.0 45.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '0.0 46.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '0.0 46.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '0.0 47.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '0.0 48.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '0.0 49.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '0.0 49.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '0.0 50.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '0.0 51.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '0.0 52.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '0.0 52.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '0.0 53.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '0.0 54.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '0.0 55.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '0.0 55.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '0.0 56.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '0.0 57.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '0.0 58.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '0.0 58.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '0.0 59.625 0.0'
    variable = lagrange
  [../]
  [./strain_xy_0]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_1]
    type = PointValue
    point = '0.0 1.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_2]
    type = PointValue
    point = '0.0 1.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_3]
    type = PointValue
    point = '0.0 2.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_4]
    type = PointValue
    point = '0.0 3.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_5]
    type = PointValue
    point = '0.0 4.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_6]
    type = PointValue
    point = '0.0 4.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_7]
    type = PointValue
    point = '0.0 5.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_8]
    type = PointValue
    point = '0.0 6.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_9]
    type = PointValue
    point = '0.0 7.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_10]
    type = PointValue
    point = '0.0 7.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_11]
    type = PointValue
    point = '0.0 8.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_12]
    type = PointValue
    point = '0.0 9.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_13]
    type = PointValue
    point = '0.0 10.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_14]
    type = PointValue
    point = '0.0 10.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_15]
    type = PointValue
    point = '0.0 11.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_16]
    type = PointValue
    point = '0.0 12.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_17]
    type = PointValue
    point = '0.0 13.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_18]
    type = PointValue
    point = '0.0 13.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_19]
    type = PointValue
    point = '0.0 14.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_20]
    type = PointValue
    point = '0.0 15.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_21]
    type = PointValue
    point = '0.0 16.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_22]
    type = PointValue
    point = '0.0 16.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_23]
    type = PointValue
    point = '0.0 17.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_24]
    type = PointValue
    point = '0.0 18.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_25]
    type = PointValue
    point = '0.0 19.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_26]
    type = PointValue
    point = '0.0 19.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_27]
    type = PointValue
    point = '0.0 20.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_28]
    type = PointValue
    point = '0.0 21.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_29]
    type = PointValue
    point = '0.0 22.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_30]
    type = PointValue
    point = '0.0 22.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_31]
    type = PointValue
    point = '0.0 23.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_32]
    type = PointValue
    point = '0.0 24.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_33]
    type = PointValue
    point = '0.0 25.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_34]
    type = PointValue
    point = '0.0 25.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_35]
    type = PointValue
    point = '0.0 26.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_36]
    type = PointValue
    point = '0.0 27.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_37]
    type = PointValue
    point = '0.0 28.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_38]
    type = PointValue
    point = '0.0 28.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_39]
    type = PointValue
    point = '0.0 29.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_40]
    type = PointValue
    point = '0.0 30.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_41]
    type = PointValue
    point = '0.0 31.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_42]
    type = PointValue
    point = '0.0 31.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_43]
    type = PointValue
    point = '0.0 32.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_44]
    type = PointValue
    point = '0.0 33.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_45]
    type = PointValue
    point = '0.0 34.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_46]
    type = PointValue
    point = '0.0 34.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_47]
    type = PointValue
    point = '0.0 35.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_48]
    type = PointValue
    point = '0.0 36.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_49]
    type = PointValue
    point = '0.0 37.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_50]
    type = PointValue
    point = '0.0 37.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_51]
    type = PointValue
    point = '0.0 38.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_52]
    type = PointValue
    point = '0.0 39.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_53]
    type = PointValue
    point = '0.0 40.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_54]
    type = PointValue
    point = '0.0 40.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_55]
    type = PointValue
    point = '0.0 41.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_56]
    type = PointValue
    point = '0.0 42.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_57]
    type = PointValue
    point = '0.0 43.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_58]
    type = PointValue
    point = '0.0 43.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_59]
    type = PointValue
    point = '0.0 44.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_60]
    type = PointValue
    point = '0.0 45.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_61]
    type = PointValue
    point = '0.0 46.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_62]
    type = PointValue
    point = '0.0 46.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_63]
    type = PointValue
    point = '0.0 47.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_64]
    type = PointValue
    point = '0.0 48.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_65]
    type = PointValue
    point = '0.0 49.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_66]
    type = PointValue
    point = '0.0 49.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_67]
    type = PointValue
    point = '0.0 50.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_68]
    type = PointValue
    point = '0.0 51.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_69]
    type = PointValue
    point = '0.0 52.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_70]
    type = PointValue
    point = '0.0 52.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_71]
    type = PointValue
    point = '0.0 53.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_72]
    type = PointValue
    point = '0.0 54.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_73]
    type = PointValue
    point = '0.0 55.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_74]
    type = PointValue
    point = '0.0 55.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_75]
    type = PointValue
    point = '0.0 56.625 0.0'
    variable = strain_12
  [../]
  [./strain_xy_76]
    type = PointValue
    point = '0.0 57.375 0.0'
    variable = strain_12
  [../]
  [./strain_xy_77]
    type = PointValue
    point = '0.0 58.125 0.0'
    variable = strain_12
  [../]
  [./strain_xy_78]
    type = PointValue
    point = '0.0 58.875 0.0'
    variable = strain_12
  [../]
  [./strain_xy_79]
    type = PointValue
    point = '0.0 59.625 0.0'
    variable = strain_12
  [../]
  [./disp_y_top]
    type = PointValue
    point = '60 60 60'
    variable = disp_y
  [../]
  [./wc_z_top]
    type = PointValue
    point = '60 60 60'
    variable = wc_z
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
    point = '60 0 60'
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
[]

[Functions]
  active = 'ramp_neg ramp'
  [./ramp]
    # -0.0005*t
    type = ParsedFunction
    value = 0.1*t
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
[]

[BCs]
  # following is natural BC
  active = 'Periodic uy_bottom ux_ramp_top wcz_imposed_top wcx_equals_zero_on_top ux_zero_bottom wcy_equals_zero_on_top wc_x_bottom uz_bottom wc_z_bottom_zero wc_y_bottom'
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
    B_ijkl = '0 5.0E4 5.0E4'
    C_ijkl = '1.3333E3 4.0E3 2.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 100
    hardening_mech_modulus = -8
    friction_coefficient = 0.0
    min_stepsize = 1e-8
    plasticity_type = DruckerPrager_cohesion2D
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
    petsc_options_value = 'gmres          bjacobi     1E-6          1E-8          40                1E-12      1E-10 '
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
  num_steps = 2000
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = plastic_shear_h800_mesh80DB
  print_linear_residuals = false
[]

