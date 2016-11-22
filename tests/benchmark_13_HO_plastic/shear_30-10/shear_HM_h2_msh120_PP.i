[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 120
  xmax = 2
  ymax = 2
  zmax = 2
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
  active  = 'number_lin disp_y_top tangential_force normal_force number_nonlin disp_x_bottom wc_z_top dt disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 disp_x_41 disp_x_42 disp_x_43 disp_x_44 disp_x_45 disp_x_46 disp_x_47 disp_x_48 disp_x_49 disp_x_50 disp_x_51 disp_x_52 disp_x_53 disp_x_54 disp_x_55 disp_x_56 disp_x_57 disp_x_58 disp_x_59 disp_x_60 disp_x_61 disp_x_62 disp_x_63 disp_x_64 disp_x_65 disp_x_66 disp_x_67 disp_x_68 disp_x_69 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 disp_x_80 disp_x_81 disp_x_82 disp_x_83 disp_x_84 disp_x_85 disp_x_86 disp_x_87 disp_x_88 disp_x_89 disp_x_90 disp_x_91 disp_x_92 disp_x_93 disp_x_94 disp_x_95 disp_x_96 disp_x_97 disp_x_98 disp_x_99 disp_x_100 disp_x_101 disp_x_102 disp_x_103 disp_x_104 disp_x_105 disp_x_106 disp_x_107 disp_x_108 disp_x_109 disp_x_110 disp_x_111 disp_x_112 disp_x_113 disp_x_114 disp_x_115 disp_x_116 disp_x_117 disp_x_118 disp_x_119 disp_x_120 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 lagrange_40 lagrange_41 lagrange_42 lagrange_43 lagrange_44 lagrange_45 lagrange_46 lagrange_47 lagrange_48 lagrange_49 lagrange_50 lagrange_51 lagrange_52 lagrange_53 lagrange_54 lagrange_55 lagrange_56 lagrange_57 lagrange_58 lagrange_59 lagrange_60 lagrange_61 lagrange_62 lagrange_63 lagrange_64 lagrange_65 lagrange_66 lagrange_67 lagrange_68 lagrange_69 lagrange_70 lagrange_71 lagrange_72 lagrange_73 lagrange_74 lagrange_75 lagrange_76 lagrange_77 lagrange_78 lagrange_79 lagrange_80 lagrange_81 lagrange_82 lagrange_83 lagrange_84 lagrange_85 lagrange_86 lagrange_87 lagrange_88 lagrange_89 lagrange_90 lagrange_91 lagrange_92 lagrange_93 lagrange_94 lagrange_95 lagrange_96 lagrange_97 lagrange_98 lagrange_99 lagrange_100 lagrange_101 lagrange_102 lagrange_103 lagrange_104 lagrange_105 lagrange_106 lagrange_107 lagrange_108 lagrange_109 lagrange_110 lagrange_111 lagrange_112 lagrange_113 lagrange_114 lagrange_115 lagrange_116 lagrange_117 lagrange_118 lagrange_119'
  [./disp_x_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0.0 0.0166666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 0.0333333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 0.05 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 0.0666666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 0.0833333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 0.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 0.116666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 0.133333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 0.15 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 0.166666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 0.183333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 0.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 0.216666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 0.233333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 0.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 0.266666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 0.283333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 0.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 0.316666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 0.333333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 0.35 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 0.366666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 0.383333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 0.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 0.416666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 0.433333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 0.45 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 0.466666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 0.483333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 0.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 0.516666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 0.533333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 0.55 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 0.566666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 0.583333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 0.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 0.616666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 0.633333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 0.65 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 0.666666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '0.0 0.683333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '0.0 0.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '0.0 0.716666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '0.0 0.733333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '0.0 0.766666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '0.0 0.783333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '0.0 0.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '0.0 0.816666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '0.0 0.833333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '0.0 0.85 0.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '0.0 0.866666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '0.0 0.883333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '0.0 0.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '0.0 0.916666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '0.0 0.933333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '0.0 0.95 0.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '0.0 0.966666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '0.0 0.983333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '0.0 1.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '0.0 1.01666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '0.0 1.03333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '0.0 1.05 0.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '0.0 1.06666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '0.0 1.08333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '0.0 1.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '0.0 1.11666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '0.0 1.13333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '0.0 1.15 0.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '0.0 1.16666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '0.0 1.18333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '0.0 1.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '0.0 1.21666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '0.0 1.23333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '0.0 1.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '0.0 1.26666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '0.0 1.28333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '0.0 1.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '0.0 1.31666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '0.0 1.33333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_81]
    type = PointValue
    point = '0.0 1.35 0.0'
    variable = disp_x
  [../]
  [./disp_x_82]
    type = PointValue
    point = '0.0 1.36666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_83]
    type = PointValue
    point = '0.0 1.38333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_84]
    type = PointValue
    point = '0.0 1.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_85]
    type = PointValue
    point = '0.0 1.41666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_86]
    type = PointValue
    point = '0.0 1.43333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_87]
    type = PointValue
    point = '0.0 1.45 0.0'
    variable = disp_x
  [../]
  [./disp_x_88]
    type = PointValue
    point = '0.0 1.46666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_89]
    type = PointValue
    point = '0.0 1.48333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_90]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_91]
    type = PointValue
    point = '0.0 1.51666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_92]
    type = PointValue
    point = '0.0 1.53333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_93]
    type = PointValue
    point = '0.0 1.55 0.0'
    variable = disp_x
  [../]
  [./disp_x_94]
    type = PointValue
    point = '0.0 1.56666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_95]
    type = PointValue
    point = '0.0 1.58333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_96]
    type = PointValue
    point = '0.0 1.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_97]
    type = PointValue
    point = '0.0 1.61666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_98]
    type = PointValue
    point = '0.0 1.63333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_99]
    type = PointValue
    point = '0.0 1.65 0.0'
    variable = disp_x
  [../]
  [./disp_x_100]
    type = PointValue
    point = '0.0 1.66666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_101]
    type = PointValue
    point = '0.0 1.68333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_102]
    type = PointValue
    point = '0.0 1.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_103]
    type = PointValue
    point = '0.0 1.71666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_104]
    type = PointValue
    point = '0.0 1.73333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_105]
    type = PointValue
    point = '0.0 1.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_106]
    type = PointValue
    point = '0.0 1.76666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_107]
    type = PointValue
    point = '0.0 1.78333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_108]
    type = PointValue
    point = '0.0 1.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_109]
    type = PointValue
    point = '0.0 1.81666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_110]
    type = PointValue
    point = '0.0 1.83333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_111]
    type = PointValue
    point = '0.0 1.85 0.0'
    variable = disp_x
  [../]
  [./disp_x_112]
    type = PointValue
    point = '0.0 1.86666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_113]
    type = PointValue
    point = '0.0 1.88333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_114]
    type = PointValue
    point = '0.0 1.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_115]
    type = PointValue
    point = '0.0 1.91666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_116]
    type = PointValue
    point = '0.0 1.93333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_117]
    type = PointValue
    point = '0.0 1.95 0.0'
    variable = disp_x
  [../]
  [./disp_x_118]
    type = PointValue
    point = '0.0 1.96666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_119]
    type = PointValue
    point = '0.0 1.98333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_120]
    type = PointValue
    point = '0.0 2.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.00833333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 0.025 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 0.0416666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 0.0583333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 0.075 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 0.0916666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 0.108333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 0.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 0.141666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 0.158333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 0.175 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 0.191666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 0.208333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 0.225 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 0.241666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 0.258333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 0.275 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 0.291666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 0.308333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 0.325 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 0.341666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 0.358333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 0.391666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 0.408333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 0.425 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 0.441666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 0.458333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 0.475 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 0.491666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 0.508333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 0.525 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 0.541666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 0.558333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 0.575 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 0.591666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 0.608333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 0.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 0.641666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 0.658333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '0.0 0.675 0.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '0.0 0.691666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '0.0 0.708333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '0.0 0.725 0.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '0.0 0.741666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '0.0 0.758333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '0.0 0.775 0.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '0.0 0.791666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '0.0 0.808333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '0.0 0.825 0.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '0.0 0.841666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '0.0 0.858333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '0.0 0.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '0.0 0.891666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '0.0 0.908333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '0.0 0.925 0.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '0.0 0.941666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '0.0 0.958333333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '0.0 0.975 0.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '0.0 0.991666666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '0.0 1.00833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '0.0 1.025 0.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '0.0 1.04166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '0.0 1.05833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '0.0 1.075 0.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '0.0 1.09166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '0.0 1.10833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '0.0 1.125 0.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '0.0 1.14166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '0.0 1.15833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '0.0 1.175 0.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '0.0 1.19166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '0.0 1.20833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '0.0 1.225 0.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '0.0 1.24166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '0.0 1.25833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '0.0 1.275 0.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '0.0 1.29166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '0.0 1.30833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '0.0 1.325 0.0'
    variable = lagrange
  [../]
  [./lagrange_80]
    type = PointValue
    point = '0.0 1.34166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_81]
    type = PointValue
    point = '0.0 1.35833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_82]
    type = PointValue
    point = '0.0 1.375 0.0'
    variable = lagrange
  [../]
  [./lagrange_83]
    type = PointValue
    point = '0.0 1.39166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_84]
    type = PointValue
    point = '0.0 1.40833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_85]
    type = PointValue
    point = '0.0 1.425 0.0'
    variable = lagrange
  [../]
  [./lagrange_86]
    type = PointValue
    point = '0.0 1.44166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_87]
    type = PointValue
    point = '0.0 1.45833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_88]
    type = PointValue
    point = '0.0 1.475 0.0'
    variable = lagrange
  [../]
  [./lagrange_89]
    type = PointValue
    point = '0.0 1.49166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_90]
    type = PointValue
    point = '0.0 1.50833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_91]
    type = PointValue
    point = '0.0 1.525 0.0'
    variable = lagrange
  [../]
  [./lagrange_92]
    type = PointValue
    point = '0.0 1.54166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_93]
    type = PointValue
    point = '0.0 1.55833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_94]
    type = PointValue
    point = '0.0 1.575 0.0'
    variable = lagrange
  [../]
  [./lagrange_95]
    type = PointValue
    point = '0.0 1.59166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_96]
    type = PointValue
    point = '0.0 1.60833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_97]
    type = PointValue
    point = '0.0 1.625 0.0'
    variable = lagrange
  [../]
  [./lagrange_98]
    type = PointValue
    point = '0.0 1.64166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_99]
    type = PointValue
    point = '0.0 1.65833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_100]
    type = PointValue
    point = '0.0 1.675 0.0'
    variable = lagrange
  [../]
  [./lagrange_101]
    type = PointValue
    point = '0.0 1.69166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_102]
    type = PointValue
    point = '0.0 1.70833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_103]
    type = PointValue
    point = '0.0 1.725 0.0'
    variable = lagrange
  [../]
  [./lagrange_104]
    type = PointValue
    point = '0.0 1.74166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_105]
    type = PointValue
    point = '0.0 1.75833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_106]
    type = PointValue
    point = '0.0 1.775 0.0'
    variable = lagrange
  [../]
  [./lagrange_107]
    type = PointValue
    point = '0.0 1.79166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_108]
    type = PointValue
    point = '0.0 1.80833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_109]
    type = PointValue
    point = '0.0 1.825 0.0'
    variable = lagrange
  [../]
  [./lagrange_110]
    type = PointValue
    point = '0.0 1.84166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_111]
    type = PointValue
    point = '0.0 1.85833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_112]
    type = PointValue
    point = '0.0 1.875 0.0'
    variable = lagrange
  [../]
  [./lagrange_113]
    type = PointValue
    point = '0.0 1.89166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_114]
    type = PointValue
    point = '0.0 1.90833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_115]
    type = PointValue
    point = '0.0 1.925 0.0'
    variable = lagrange
  [../]
  [./lagrange_116]
    type = PointValue
    point = '0.0 1.94166666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_117]
    type = PointValue
    point = '0.0 1.95833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_118]
    type = PointValue
    point = '0.0 1.975 0.0'
    variable = lagrange
  [../]
  [./lagrange_119]
    type = PointValue
    point = '0.0 1.99166666667 0.0'
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
  [./temperature]
  [../]
  [./pressure]
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
  active = 'ramp'
  [./ramp]
    # -0.0005*t
    type = ParsedFunction
    value = 10000*t
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
  active = 'p_diff x_couple cz_elastic cy_elastic cx_elastic y_moment z_couple dT_dt x_moment y_couple z_moment dp_dt poromech'
  [./cx_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_x
    displacements = 'disp_x disp_y disp_z'
    component = 0
    temp = temperature
    pore_pres = pressure
  [../]
  [./cy_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_y
    displacements = 'disp_x disp_y disp_z'
    component = 1
    temp = temperature
    pore_pres = pressure
  [../]
  [./cz_elastic]
    type = RedbackCosseratStressDivergenceTensors
    variable = disp_z
    component = 2
    displacements = 'disp_x disp_y disp_z'
    temp = temperature
    pore_pres = pressure
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
    pore_pres = pressure
    temp = temperature
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
    pore_pres = pressure
    temp = temperature
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
    pore_pres = pressure
    temp = temperature
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
  [./dp_dt]
    type = TimeDerivative
    variable = pressure
  [../]
  [./p_diff]
    type = RedbackMassDiffusion
    variable = pressure
  [../]
  [./T_diff]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
  [./mech_dissip]
    type = RedbackMechDissip
    variable = temperature
  [../]
  [./T_press]
    type = RedbackThermalPressurization
    variable = pressure
    temperature = temperature
  [../]
  [./poromech]
    type = RedbackPoroMechHO
    variable = pressure
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
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
      auto_direction = x
    [../]
    [./z_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
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
    value = -0.666667
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
    B_ijkl = '0 1 1'
    C_ijkl = '66.6667 50 25'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    hardening_mech_modulus = -0.2
    friction_coefficient = 0.5
    min_stepsize = 1e-8
    plasticity_type = DruckerPrager_friction3D
    ignore_failures = true
    pore_pres = pressure
    temperature = temperature
    beta_star = 1/50
    dilatancy_coefficient = -0.01
    cohesion = 0.001
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
    solid_thermal_expansion = 0.01
    pore_pres = pressure
    pressurization_coefficient = 1
    temperature = temperature
    gr = 0.17857
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type    -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres          bjacobi     1E-7          1E-6          40                1E-12      1E-10 '
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
  num_steps = 100000
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = plastic_shear_HM_h2_msh120_30-10
  print_linear_residuals = false
[]

