[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 160
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
  active  = 'number_nonlin wc_z_mid Temperature_mid pressure_mid disp_y_top number_lin normal_force tangential_force disp_x_top dt strain_12_mid strain_12_pl_mid disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 disp_x_41 disp_x_42 disp_x_43 disp_x_44 disp_x_45 disp_x_46 disp_x_47 disp_x_48 disp_x_49 disp_x_50 disp_x_51 disp_x_52 disp_x_53 disp_x_54 disp_x_55 disp_x_56 disp_x_57 disp_x_58 disp_x_59 disp_x_60 disp_x_61 disp_x_62 disp_x_63 disp_x_64 disp_x_65 disp_x_66 disp_x_67 disp_x_68 disp_x_69 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 disp_x_80 disp_x_81 disp_x_82 disp_x_83 disp_x_84 disp_x_85 disp_x_86 disp_x_87 disp_x_88 disp_x_89 disp_x_90 disp_x_91 disp_x_92 disp_x_93 disp_x_94 disp_x_95 disp_x_96 disp_x_97 disp_x_98 disp_x_99 disp_x_100 disp_x_101 disp_x_102 disp_x_103 disp_x_104 disp_x_105 disp_x_106 disp_x_107 disp_x_108 disp_x_109 disp_x_110 disp_x_111 disp_x_112 disp_x_113 disp_x_114 disp_x_115 disp_x_116 disp_x_117 disp_x_118 disp_x_119 disp_x_120 disp_x_121 disp_x_122 disp_x_123 disp_x_124 disp_x_125 disp_x_126 disp_x_127 disp_x_128 disp_x_129 disp_x_130 disp_x_131 disp_x_132 disp_x_133 disp_x_134 disp_x_135 disp_x_136 disp_x_137 disp_x_138 disp_x_139 disp_x_140 disp_x_141 disp_x_142 disp_x_143 disp_x_144 disp_x_145 disp_x_146 disp_x_147 disp_x_148 disp_x_149 disp_x_150 disp_x_151 disp_x_152 disp_x_153 disp_x_154 disp_x_155 disp_x_156 disp_x_157 disp_x_158 disp_x_159 disp_x_160 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 lagrange_40 lagrange_41 lagrange_42 lagrange_43 lagrange_44 lagrange_45 lagrange_46 lagrange_47 lagrange_48 lagrange_49 lagrange_50 lagrange_51 lagrange_52 lagrange_53 lagrange_54 lagrange_55 lagrange_56 lagrange_57 lagrange_58 lagrange_59 lagrange_60 lagrange_61 lagrange_62 lagrange_63 lagrange_64 lagrange_65 lagrange_66 lagrange_67 lagrange_68 lagrange_69 lagrange_70 lagrange_71 lagrange_72 lagrange_73 lagrange_74 lagrange_75 lagrange_76 lagrange_77 lagrange_78 lagrange_79 lagrange_80 lagrange_81 lagrange_82 lagrange_83 lagrange_84 lagrange_85 lagrange_86 lagrange_87 lagrange_88 lagrange_89 lagrange_90 lagrange_91 lagrange_92 lagrange_93 lagrange_94 lagrange_95 lagrange_96 lagrange_97 lagrange_98 lagrange_99 lagrange_100 lagrange_101 lagrange_102 lagrange_103 lagrange_104 lagrange_105 lagrange_106 lagrange_107 lagrange_108 lagrange_109 lagrange_110 lagrange_111 lagrange_112 lagrange_113 lagrange_114 lagrange_115 lagrange_116 lagrange_117 lagrange_118 lagrange_119 lagrange_120 lagrange_121 lagrange_122 lagrange_123 lagrange_124 lagrange_125 lagrange_126 lagrange_127 lagrange_128 lagrange_129 lagrange_130 lagrange_131 lagrange_132 lagrange_133 lagrange_134 lagrange_135 lagrange_136 lagrange_137 lagrange_138 lagrange_139 lagrange_140 lagrange_141 lagrange_142 lagrange_143 lagrange_144 lagrange_145 lagrange_146 lagrange_147 lagrange_148 lagrange_149 lagrange_150 lagrange_151 lagrange_152 lagrange_153 lagrange_154 lagrange_155 lagrange_156 lagrange_157 lagrange_158 lagrange_159 moment_0 moment_1 moment_2 moment_3 moment_4 moment_5 moment_6 moment_7 moment_8 moment_9 moment_10 moment_11 moment_12 moment_13 moment_14 moment_15 moment_16 moment_17 moment_18 moment_19 moment_20 moment_21 moment_22 moment_23 moment_24 moment_25 moment_26 moment_27 moment_28 moment_29 moment_30 moment_31 moment_32 moment_33 moment_34 moment_35 moment_36 moment_37 moment_38 moment_39 moment_40 moment_41 moment_42 moment_43 moment_44 moment_45 moment_46 moment_47 moment_48 moment_49 moment_50 moment_51 moment_52 moment_53 moment_54 moment_55 moment_56 moment_57 moment_58 moment_59 moment_60 moment_61 moment_62 moment_63 moment_64 moment_65 moment_66 moment_67 moment_68 moment_69 moment_70 moment_71 moment_72 moment_73 moment_74 moment_75 moment_76 moment_77 moment_78 moment_79 moment_80 moment_81 moment_82 moment_83 moment_84 moment_85 moment_86 moment_87 moment_88 moment_89 moment_90 moment_91 moment_92 moment_93 moment_94 moment_95 moment_96 moment_97 moment_98 moment_99 moment_100 moment_101 moment_102 moment_103 moment_104 moment_105 moment_106 moment_107 moment_108 moment_109 moment_110 moment_111 moment_112 moment_113 moment_114 moment_115 moment_116 moment_117 moment_118 moment_119 moment_120 moment_121 moment_122 moment_123 moment_124 moment_125 moment_126 moment_127 moment_128 moment_129 moment_130 moment_131 moment_132 moment_133 moment_134 moment_135 moment_136 moment_137 moment_138 moment_139 moment_140 moment_141 moment_142 moment_143 moment_144 moment_145 moment_146 moment_147 moment_148 moment_149 moment_150 moment_151 moment_152 moment_153 moment_154 moment_155 moment_156 moment_157 moment_158 moment_159 failure_0 failure_1 failure_2 failure_3 failure_4 failure_5 failure_6 failure_7 failure_8 failure_9 failure_10 failure_11 failure_12 failure_13 failure_14 failure_15 failure_16 failure_17 failure_18 failure_19 failure_20 failure_21 failure_22 failure_23 failure_24 failure_25 failure_26 failure_27 failure_28 failure_29 failure_30 failure_31 failure_32 failure_33 failure_34 failure_35 failure_36 failure_37 failure_38 failure_39 failure_40 failure_41 failure_42 failure_43 failure_44 failure_45 failure_46 failure_47 failure_48 failure_49 failure_50 failure_51 failure_52 failure_53 failure_54 failure_55 failure_56 failure_57 failure_58 failure_59 failure_60 failure_61 failure_62 failure_63 failure_64 failure_65 failure_66 failure_67 failure_68 failure_69 failure_70 failure_71 failure_72 failure_73 failure_74 failure_75 failure_76 failure_77 failure_78 failure_79 failure_80 failure_81 failure_82 failure_83 failure_84 failure_85 failure_86 failure_87 failure_88 failure_89 failure_90 failure_91 failure_92 failure_93 failure_94 failure_95 failure_96 failure_97 failure_98 failure_99 failure_100 failure_101 failure_102 failure_103 failure_104 failure_105 failure_106 failure_107 failure_108 failure_109 failure_110 failure_111 failure_112 failure_113 failure_114 failure_115 failure_116 failure_117 failure_118 failure_119 failure_120 failure_121 failure_122 failure_123 failure_124 failure_125 failure_126 failure_127 failure_128 failure_129 failure_130 failure_131 failure_132 failure_133 failure_134 failure_135 failure_136 failure_137 failure_138 failure_139 failure_140 failure_141 failure_142 failure_143 failure_144 failure_145 failure_146 failure_147 failure_148 failure_149 failure_150 failure_151 failure_152 failure_153 failure_154 failure_155 failure_156 failure_157 failure_158 failure_159'
  [./disp_x_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0.0 0.00625 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 0.0125 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 0.01875 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 0.025 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 0.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 0.0375 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 0.04375 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 0.05 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 0.05625 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 0.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 0.06875 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 0.075 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 0.08125 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 0.0875 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 0.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 0.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 0.10625 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 0.1125 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 0.11875 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 0.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 0.13125 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 0.1375 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 0.14375 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 0.15 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 0.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 0.1625 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 0.16875 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 0.175 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 0.18125 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 0.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 0.19375 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 0.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 0.20625 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 0.2125 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 0.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 0.225 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 0.23125 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 0.2375 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 0.24375 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 0.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '0.0 0.25625 0.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '0.0 0.2625 0.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '0.0 0.26875 0.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '0.0 0.275 0.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '0.0 0.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '0.0 0.2875 0.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '0.0 0.29375 0.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '0.0 0.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '0.0 0.30625 0.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '0.0 0.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '0.0 0.31875 0.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '0.0 0.325 0.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '0.0 0.33125 0.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '0.0 0.3375 0.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '0.0 0.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '0.0 0.35 0.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '0.0 0.35625 0.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '0.0 0.3625 0.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '0.0 0.36875 0.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '0.0 0.38125 0.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '0.0 0.3875 0.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '0.0 0.39375 0.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '0.0 0.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '0.0 0.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '0.0 0.4125 0.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '0.0 0.41875 0.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '0.0 0.425 0.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '0.0 0.43125 0.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '0.0 0.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '0.0 0.44375 0.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '0.0 0.45 0.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '0.0 0.45625 0.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '0.0 0.4625 0.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '0.0 0.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '0.0 0.475 0.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '0.0 0.48125 0.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '0.0 0.4875 0.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '0.0 0.49375 0.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '0.0 0.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_81]
    type = PointValue
    point = '0.0 0.50625 0.0'
    variable = disp_x
  [../]
  [./disp_x_82]
    type = PointValue
    point = '0.0 0.5125 0.0'
    variable = disp_x
  [../]
  [./disp_x_83]
    type = PointValue
    point = '0.0 0.51875 0.0'
    variable = disp_x
  [../]
  [./disp_x_84]
    type = PointValue
    point = '0.0 0.525 0.0'
    variable = disp_x
  [../]
  [./disp_x_85]
    type = PointValue
    point = '0.0 0.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_86]
    type = PointValue
    point = '0.0 0.5375 0.0'
    variable = disp_x
  [../]
  [./disp_x_87]
    type = PointValue
    point = '0.0 0.54375 0.0'
    variable = disp_x
  [../]
  [./disp_x_88]
    type = PointValue
    point = '0.0 0.55 0.0'
    variable = disp_x
  [../]
  [./disp_x_89]
    type = PointValue
    point = '0.0 0.55625 0.0'
    variable = disp_x
  [../]
  [./disp_x_90]
    type = PointValue
    point = '0.0 0.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_91]
    type = PointValue
    point = '0.0 0.56875 0.0'
    variable = disp_x
  [../]
  [./disp_x_92]
    type = PointValue
    point = '0.0 0.575 0.0'
    variable = disp_x
  [../]
  [./disp_x_93]
    type = PointValue
    point = '0.0 0.58125 0.0'
    variable = disp_x
  [../]
  [./disp_x_94]
    type = PointValue
    point = '0.0 0.5875 0.0'
    variable = disp_x
  [../]
  [./disp_x_95]
    type = PointValue
    point = '0.0 0.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_96]
    type = PointValue
    point = '0.0 0.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_97]
    type = PointValue
    point = '0.0 0.60625 0.0'
    variable = disp_x
  [../]
  [./disp_x_98]
    type = PointValue
    point = '0.0 0.6125 0.0'
    variable = disp_x
  [../]
  [./disp_x_99]
    type = PointValue
    point = '0.0 0.61875 0.0'
    variable = disp_x
  [../]
  [./disp_x_100]
    type = PointValue
    point = '0.0 0.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_101]
    type = PointValue
    point = '0.0 0.63125 0.0'
    variable = disp_x
  [../]
  [./disp_x_102]
    type = PointValue
    point = '0.0 0.6375 0.0'
    variable = disp_x
  [../]
  [./disp_x_103]
    type = PointValue
    point = '0.0 0.64375 0.0'
    variable = disp_x
  [../]
  [./disp_x_104]
    type = PointValue
    point = '0.0 0.65 0.0'
    variable = disp_x
  [../]
  [./disp_x_105]
    type = PointValue
    point = '0.0 0.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_106]
    type = PointValue
    point = '0.0 0.6625 0.0'
    variable = disp_x
  [../]
  [./disp_x_107]
    type = PointValue
    point = '0.0 0.66875 0.0'
    variable = disp_x
  [../]
  [./disp_x_108]
    type = PointValue
    point = '0.0 0.675 0.0'
    variable = disp_x
  [../]
  [./disp_x_109]
    type = PointValue
    point = '0.0 0.68125 0.0'
    variable = disp_x
  [../]
  [./disp_x_110]
    type = PointValue
    point = '0.0 0.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_111]
    type = PointValue
    point = '0.0 0.69375 0.0'
    variable = disp_x
  [../]
  [./disp_x_112]
    type = PointValue
    point = '0.0 0.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_113]
    type = PointValue
    point = '0.0 0.70625 0.0'
    variable = disp_x
  [../]
  [./disp_x_114]
    type = PointValue
    point = '0.0 0.7125 0.0'
    variable = disp_x
  [../]
  [./disp_x_115]
    type = PointValue
    point = '0.0 0.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_116]
    type = PointValue
    point = '0.0 0.725 0.0'
    variable = disp_x
  [../]
  [./disp_x_117]
    type = PointValue
    point = '0.0 0.73125 0.0'
    variable = disp_x
  [../]
  [./disp_x_118]
    type = PointValue
    point = '0.0 0.7375 0.0'
    variable = disp_x
  [../]
  [./disp_x_119]
    type = PointValue
    point = '0.0 0.74375 0.0'
    variable = disp_x
  [../]
  [./disp_x_120]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_121]
    type = PointValue
    point = '0.0 0.75625 0.0'
    variable = disp_x
  [../]
  [./disp_x_122]
    type = PointValue
    point = '0.0 0.7625 0.0'
    variable = disp_x
  [../]
  [./disp_x_123]
    type = PointValue
    point = '0.0 0.76875 0.0'
    variable = disp_x
  [../]
  [./disp_x_124]
    type = PointValue
    point = '0.0 0.775 0.0'
    variable = disp_x
  [../]
  [./disp_x_125]
    type = PointValue
    point = '0.0 0.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_126]
    type = PointValue
    point = '0.0 0.7875 0.0'
    variable = disp_x
  [../]
  [./disp_x_127]
    type = PointValue
    point = '0.0 0.79375 0.0'
    variable = disp_x
  [../]
  [./disp_x_128]
    type = PointValue
    point = '0.0 0.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_129]
    type = PointValue
    point = '0.0 0.80625 0.0'
    variable = disp_x
  [../]
  [./disp_x_130]
    type = PointValue
    point = '0.0 0.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_131]
    type = PointValue
    point = '0.0 0.81875 0.0'
    variable = disp_x
  [../]
  [./disp_x_132]
    type = PointValue
    point = '0.0 0.825 0.0'
    variable = disp_x
  [../]
  [./disp_x_133]
    type = PointValue
    point = '0.0 0.83125 0.0'
    variable = disp_x
  [../]
  [./disp_x_134]
    type = PointValue
    point = '0.0 0.8375 0.0'
    variable = disp_x
  [../]
  [./disp_x_135]
    type = PointValue
    point = '0.0 0.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_136]
    type = PointValue
    point = '0.0 0.85 0.0'
    variable = disp_x
  [../]
  [./disp_x_137]
    type = PointValue
    point = '0.0 0.85625 0.0'
    variable = disp_x
  [../]
  [./disp_x_138]
    type = PointValue
    point = '0.0 0.8625 0.0'
    variable = disp_x
  [../]
  [./disp_x_139]
    type = PointValue
    point = '0.0 0.86875 0.0'
    variable = disp_x
  [../]
  [./disp_x_140]
    type = PointValue
    point = '0.0 0.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_141]
    type = PointValue
    point = '0.0 0.88125 0.0'
    variable = disp_x
  [../]
  [./disp_x_142]
    type = PointValue
    point = '0.0 0.8875 0.0'
    variable = disp_x
  [../]
  [./disp_x_143]
    type = PointValue
    point = '0.0 0.89375 0.0'
    variable = disp_x
  [../]
  [./disp_x_144]
    type = PointValue
    point = '0.0 0.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_145]
    type = PointValue
    point = '0.0 0.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_146]
    type = PointValue
    point = '0.0 0.9125 0.0'
    variable = disp_x
  [../]
  [./disp_x_147]
    type = PointValue
    point = '0.0 0.91875 0.0'
    variable = disp_x
  [../]
  [./disp_x_148]
    type = PointValue
    point = '0.0 0.925 0.0'
    variable = disp_x
  [../]
  [./disp_x_149]
    type = PointValue
    point = '0.0 0.93125 0.0'
    variable = disp_x
  [../]
  [./disp_x_150]
    type = PointValue
    point = '0.0 0.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_151]
    type = PointValue
    point = '0.0 0.94375 0.0'
    variable = disp_x
  [../]
  [./disp_x_152]
    type = PointValue
    point = '0.0 0.95 0.0'
    variable = disp_x
  [../]
  [./disp_x_153]
    type = PointValue
    point = '0.0 0.95625 0.0'
    variable = disp_x
  [../]
  [./disp_x_154]
    type = PointValue
    point = '0.0 0.9625 0.0'
    variable = disp_x
  [../]
  [./disp_x_155]
    type = PointValue
    point = '0.0 0.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_156]
    type = PointValue
    point = '0.0 0.975 0.0'
    variable = disp_x
  [../]
  [./disp_x_157]
    type = PointValue
    point = '0.0 0.98125 0.0'
    variable = disp_x
  [../]
  [./disp_x_158]
    type = PointValue
    point = '0.0 0.9875 0.0'
    variable = disp_x
  [../]
  [./disp_x_159]
    type = PointValue
    point = '0.0 0.99375 0.0'
    variable = disp_x
  [../]
  [./disp_x_160]
    type = PointValue
    point = '0.0 1.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.003125 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 0.009375 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 0.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 0.021875 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 0.028125 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 0.034375 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 0.040625 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 0.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 0.053125 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 0.059375 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 0.065625 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 0.071875 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 0.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 0.084375 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 0.090625 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 0.096875 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 0.103125 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 0.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 0.115625 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 0.121875 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 0.128125 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 0.134375 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 0.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 0.146875 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 0.153125 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 0.159375 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 0.165625 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 0.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 0.178125 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 0.184375 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 0.190625 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 0.196875 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 0.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 0.209375 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 0.215625 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 0.221875 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 0.228125 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 0.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 0.240625 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 0.246875 0.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '0.0 0.253125 0.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '0.0 0.259375 0.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '0.0 0.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '0.0 0.271875 0.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '0.0 0.278125 0.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '0.0 0.284375 0.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '0.0 0.290625 0.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '0.0 0.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '0.0 0.303125 0.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '0.0 0.309375 0.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '0.0 0.315625 0.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '0.0 0.321875 0.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '0.0 0.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '0.0 0.334375 0.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '0.0 0.340625 0.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '0.0 0.346875 0.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '0.0 0.353125 0.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '0.0 0.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '0.0 0.365625 0.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '0.0 0.371875 0.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '0.0 0.378125 0.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '0.0 0.384375 0.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '0.0 0.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '0.0 0.396875 0.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '0.0 0.403125 0.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '0.0 0.409375 0.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '0.0 0.415625 0.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '0.0 0.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '0.0 0.428125 0.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '0.0 0.434375 0.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '0.0 0.440625 0.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '0.0 0.446875 0.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '0.0 0.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '0.0 0.459375 0.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '0.0 0.465625 0.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '0.0 0.471875 0.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '0.0 0.478125 0.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '0.0 0.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '0.0 0.490625 0.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '0.0 0.496875 0.0'
    variable = lagrange
  [../]
  [./lagrange_80]
    type = PointValue
    point = '0.0 0.503125 0.0'
    variable = lagrange
  [../]
  [./lagrange_81]
    type = PointValue
    point = '0.0 0.509375 0.0'
    variable = lagrange
  [../]
  [./lagrange_82]
    type = PointValue
    point = '0.0 0.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_83]
    type = PointValue
    point = '0.0 0.521875 0.0'
    variable = lagrange
  [../]
  [./lagrange_84]
    type = PointValue
    point = '0.0 0.528125 0.0'
    variable = lagrange
  [../]
  [./lagrange_85]
    type = PointValue
    point = '0.0 0.534375 0.0'
    variable = lagrange
  [../]
  [./lagrange_86]
    type = PointValue
    point = '0.0 0.540625 0.0'
    variable = lagrange
  [../]
  [./lagrange_87]
    type = PointValue
    point = '0.0 0.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_88]
    type = PointValue
    point = '0.0 0.553125 0.0'
    variable = lagrange
  [../]
  [./lagrange_89]
    type = PointValue
    point = '0.0 0.559375 0.0'
    variable = lagrange
  [../]
  [./lagrange_90]
    type = PointValue
    point = '0.0 0.565625 0.0'
    variable = lagrange
  [../]
  [./lagrange_91]
    type = PointValue
    point = '0.0 0.571875 0.0'
    variable = lagrange
  [../]
  [./lagrange_92]
    type = PointValue
    point = '0.0 0.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_93]
    type = PointValue
    point = '0.0 0.584375 0.0'
    variable = lagrange
  [../]
  [./lagrange_94]
    type = PointValue
    point = '0.0 0.590625 0.0'
    variable = lagrange
  [../]
  [./lagrange_95]
    type = PointValue
    point = '0.0 0.596875 0.0'
    variable = lagrange
  [../]
  [./lagrange_96]
    type = PointValue
    point = '0.0 0.603125 0.0'
    variable = lagrange
  [../]
  [./lagrange_97]
    type = PointValue
    point = '0.0 0.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_98]
    type = PointValue
    point = '0.0 0.615625 0.0'
    variable = lagrange
  [../]
  [./lagrange_99]
    type = PointValue
    point = '0.0 0.621875 0.0'
    variable = lagrange
  [../]
  [./lagrange_100]
    type = PointValue
    point = '0.0 0.628125 0.0'
    variable = lagrange
  [../]
  [./lagrange_101]
    type = PointValue
    point = '0.0 0.634375 0.0'
    variable = lagrange
  [../]
  [./lagrange_102]
    type = PointValue
    point = '0.0 0.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_103]
    type = PointValue
    point = '0.0 0.646875 0.0'
    variable = lagrange
  [../]
  [./lagrange_104]
    type = PointValue
    point = '0.0 0.653125 0.0'
    variable = lagrange
  [../]
  [./lagrange_105]
    type = PointValue
    point = '0.0 0.659375 0.0'
    variable = lagrange
  [../]
  [./lagrange_106]
    type = PointValue
    point = '0.0 0.665625 0.0'
    variable = lagrange
  [../]
  [./lagrange_107]
    type = PointValue
    point = '0.0 0.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_108]
    type = PointValue
    point = '0.0 0.678125 0.0'
    variable = lagrange
  [../]
  [./lagrange_109]
    type = PointValue
    point = '0.0 0.684375 0.0'
    variable = lagrange
  [../]
  [./lagrange_110]
    type = PointValue
    point = '0.0 0.690625 0.0'
    variable = lagrange
  [../]
  [./lagrange_111]
    type = PointValue
    point = '0.0 0.696875 0.0'
    variable = lagrange
  [../]
  [./lagrange_112]
    type = PointValue
    point = '0.0 0.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_113]
    type = PointValue
    point = '0.0 0.709375 0.0'
    variable = lagrange
  [../]
  [./lagrange_114]
    type = PointValue
    point = '0.0 0.715625 0.0'
    variable = lagrange
  [../]
  [./lagrange_115]
    type = PointValue
    point = '0.0 0.721875 0.0'
    variable = lagrange
  [../]
  [./lagrange_116]
    type = PointValue
    point = '0.0 0.728125 0.0'
    variable = lagrange
  [../]
  [./lagrange_117]
    type = PointValue
    point = '0.0 0.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_118]
    type = PointValue
    point = '0.0 0.740625 0.0'
    variable = lagrange
  [../]
  [./lagrange_119]
    type = PointValue
    point = '0.0 0.746875 0.0'
    variable = lagrange
  [../]
  [./lagrange_120]
    type = PointValue
    point = '0.0 0.753125 0.0'
    variable = lagrange
  [../]
  [./lagrange_121]
    type = PointValue
    point = '0.0 0.759375 0.0'
    variable = lagrange
  [../]
  [./lagrange_122]
    type = PointValue
    point = '0.0 0.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_123]
    type = PointValue
    point = '0.0 0.771875 0.0'
    variable = lagrange
  [../]
  [./lagrange_124]
    type = PointValue
    point = '0.0 0.778125 0.0'
    variable = lagrange
  [../]
  [./lagrange_125]
    type = PointValue
    point = '0.0 0.784375 0.0'
    variable = lagrange
  [../]
  [./lagrange_126]
    type = PointValue
    point = '0.0 0.790625 0.0'
    variable = lagrange
  [../]
  [./lagrange_127]
    type = PointValue
    point = '0.0 0.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_128]
    type = PointValue
    point = '0.0 0.803125 0.0'
    variable = lagrange
  [../]
  [./lagrange_129]
    type = PointValue
    point = '0.0 0.809375 0.0'
    variable = lagrange
  [../]
  [./lagrange_130]
    type = PointValue
    point = '0.0 0.815625 0.0'
    variable = lagrange
  [../]
  [./lagrange_131]
    type = PointValue
    point = '0.0 0.821875 0.0'
    variable = lagrange
  [../]
  [./lagrange_132]
    type = PointValue
    point = '0.0 0.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_133]
    type = PointValue
    point = '0.0 0.834375 0.0'
    variable = lagrange
  [../]
  [./lagrange_134]
    type = PointValue
    point = '0.0 0.840625 0.0'
    variable = lagrange
  [../]
  [./lagrange_135]
    type = PointValue
    point = '0.0 0.846875 0.0'
    variable = lagrange
  [../]
  [./lagrange_136]
    type = PointValue
    point = '0.0 0.853125 0.0'
    variable = lagrange
  [../]
  [./lagrange_137]
    type = PointValue
    point = '0.0 0.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_138]
    type = PointValue
    point = '0.0 0.865625 0.0'
    variable = lagrange
  [../]
  [./lagrange_139]
    type = PointValue
    point = '0.0 0.871875 0.0'
    variable = lagrange
  [../]
  [./lagrange_140]
    type = PointValue
    point = '0.0 0.878125 0.0'
    variable = lagrange
  [../]
  [./lagrange_141]
    type = PointValue
    point = '0.0 0.884375 0.0'
    variable = lagrange
  [../]
  [./lagrange_142]
    type = PointValue
    point = '0.0 0.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_143]
    type = PointValue
    point = '0.0 0.896875 0.0'
    variable = lagrange
  [../]
  [./lagrange_144]
    type = PointValue
    point = '0.0 0.903125 0.0'
    variable = lagrange
  [../]
  [./lagrange_145]
    type = PointValue
    point = '0.0 0.909375 0.0'
    variable = lagrange
  [../]
  [./lagrange_146]
    type = PointValue
    point = '0.0 0.915625 0.0'
    variable = lagrange
  [../]
  [./lagrange_147]
    type = PointValue
    point = '0.0 0.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_148]
    type = PointValue
    point = '0.0 0.928125 0.0'
    variable = lagrange
  [../]
  [./lagrange_149]
    type = PointValue
    point = '0.0 0.934375 0.0'
    variable = lagrange
  [../]
  [./lagrange_150]
    type = PointValue
    point = '0.0 0.940625 0.0'
    variable = lagrange
  [../]
  [./lagrange_151]
    type = PointValue
    point = '0.0 0.946875 0.0'
    variable = lagrange
  [../]
  [./lagrange_152]
    type = PointValue
    point = '0.0 0.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_153]
    type = PointValue
    point = '0.0 0.959375 0.0'
    variable = lagrange
  [../]
  [./lagrange_154]
    type = PointValue
    point = '0.0 0.965625 0.0'
    variable = lagrange
  [../]
  [./lagrange_155]
    type = PointValue
    point = '0.0 0.971875 0.0'
    variable = lagrange
  [../]
  [./lagrange_156]
    type = PointValue
    point = '0.0 0.978125 0.0'
    variable = lagrange
  [../]
  [./lagrange_157]
    type = PointValue
    point = '0.0 0.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_158]
    type = PointValue
    point = '0.0 0.990625 0.0'
    variable = lagrange
  [../]
  [./lagrange_159]
    type = PointValue
    point = '0.0 0.996875 0.0'
    variable = lagrange
  [../]
  [./moment_0]
    type = PointValue
    point = '0.0 0.003125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_1]
    type = PointValue
    point = '0.0 0.009375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_2]
    type = PointValue
    point = '0.0 0.015625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_3]
    type = PointValue
    point = '0.0 0.021875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_4]
    type = PointValue
    point = '0.0 0.028125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_5]
    type = PointValue
    point = '0.0 0.034375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_6]
    type = PointValue
    point = '0.0 0.040625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_7]
    type = PointValue
    point = '0.0 0.046875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_8]
    type = PointValue
    point = '0.0 0.053125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_9]
    type = PointValue
    point = '0.0 0.059375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_10]
    type = PointValue
    point = '0.0 0.065625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_11]
    type = PointValue
    point = '0.0 0.071875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_12]
    type = PointValue
    point = '0.0 0.078125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_13]
    type = PointValue
    point = '0.0 0.084375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_14]
    type = PointValue
    point = '0.0 0.090625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_15]
    type = PointValue
    point = '0.0 0.096875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_16]
    type = PointValue
    point = '0.0 0.103125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_17]
    type = PointValue
    point = '0.0 0.109375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_18]
    type = PointValue
    point = '0.0 0.115625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_19]
    type = PointValue
    point = '0.0 0.121875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_20]
    type = PointValue
    point = '0.0 0.128125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_21]
    type = PointValue
    point = '0.0 0.134375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_22]
    type = PointValue
    point = '0.0 0.140625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_23]
    type = PointValue
    point = '0.0 0.146875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_24]
    type = PointValue
    point = '0.0 0.153125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_25]
    type = PointValue
    point = '0.0 0.159375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_26]
    type = PointValue
    point = '0.0 0.165625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_27]
    type = PointValue
    point = '0.0 0.171875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_28]
    type = PointValue
    point = '0.0 0.178125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_29]
    type = PointValue
    point = '0.0 0.184375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_30]
    type = PointValue
    point = '0.0 0.190625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_31]
    type = PointValue
    point = '0.0 0.196875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_32]
    type = PointValue
    point = '0.0 0.203125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_33]
    type = PointValue
    point = '0.0 0.209375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_34]
    type = PointValue
    point = '0.0 0.215625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_35]
    type = PointValue
    point = '0.0 0.221875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_36]
    type = PointValue
    point = '0.0 0.228125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_37]
    type = PointValue
    point = '0.0 0.234375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_38]
    type = PointValue
    point = '0.0 0.240625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_39]
    type = PointValue
    point = '0.0 0.246875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_40]
    type = PointValue
    point = '0.0 0.253125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_41]
    type = PointValue
    point = '0.0 0.259375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_42]
    type = PointValue
    point = '0.0 0.265625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_43]
    type = PointValue
    point = '0.0 0.271875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_44]
    type = PointValue
    point = '0.0 0.278125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_45]
    type = PointValue
    point = '0.0 0.284375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_46]
    type = PointValue
    point = '0.0 0.290625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_47]
    type = PointValue
    point = '0.0 0.296875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_48]
    type = PointValue
    point = '0.0 0.303125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_49]
    type = PointValue
    point = '0.0 0.309375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_50]
    type = PointValue
    point = '0.0 0.315625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_51]
    type = PointValue
    point = '0.0 0.321875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_52]
    type = PointValue
    point = '0.0 0.328125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_53]
    type = PointValue
    point = '0.0 0.334375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_54]
    type = PointValue
    point = '0.0 0.340625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_55]
    type = PointValue
    point = '0.0 0.346875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_56]
    type = PointValue
    point = '0.0 0.353125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_57]
    type = PointValue
    point = '0.0 0.359375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_58]
    type = PointValue
    point = '0.0 0.365625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_59]
    type = PointValue
    point = '0.0 0.371875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_60]
    type = PointValue
    point = '0.0 0.378125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_61]
    type = PointValue
    point = '0.0 0.384375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_62]
    type = PointValue
    point = '0.0 0.390625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_63]
    type = PointValue
    point = '0.0 0.396875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_64]
    type = PointValue
    point = '0.0 0.403125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_65]
    type = PointValue
    point = '0.0 0.409375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_66]
    type = PointValue
    point = '0.0 0.415625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_67]
    type = PointValue
    point = '0.0 0.421875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_68]
    type = PointValue
    point = '0.0 0.428125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_69]
    type = PointValue
    point = '0.0 0.434375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_70]
    type = PointValue
    point = '0.0 0.440625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_71]
    type = PointValue
    point = '0.0 0.446875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_72]
    type = PointValue
    point = '0.0 0.453125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_73]
    type = PointValue
    point = '0.0 0.459375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_74]
    type = PointValue
    point = '0.0 0.465625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_75]
    type = PointValue
    point = '0.0 0.471875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_76]
    type = PointValue
    point = '0.0 0.478125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_77]
    type = PointValue
    point = '0.0 0.484375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_78]
    type = PointValue
    point = '0.0 0.490625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_79]
    type = PointValue
    point = '0.0 0.496875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_80]
    type = PointValue
    point = '0.0 0.503125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_81]
    type = PointValue
    point = '0.0 0.509375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_82]
    type = PointValue
    point = '0.0 0.515625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_83]
    type = PointValue
    point = '0.0 0.521875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_84]
    type = PointValue
    point = '0.0 0.528125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_85]
    type = PointValue
    point = '0.0 0.534375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_86]
    type = PointValue
    point = '0.0 0.540625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_87]
    type = PointValue
    point = '0.0 0.546875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_88]
    type = PointValue
    point = '0.0 0.553125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_89]
    type = PointValue
    point = '0.0 0.559375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_90]
    type = PointValue
    point = '0.0 0.565625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_91]
    type = PointValue
    point = '0.0 0.571875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_92]
    type = PointValue
    point = '0.0 0.578125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_93]
    type = PointValue
    point = '0.0 0.584375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_94]
    type = PointValue
    point = '0.0 0.590625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_95]
    type = PointValue
    point = '0.0 0.596875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_96]
    type = PointValue
    point = '0.0 0.603125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_97]
    type = PointValue
    point = '0.0 0.609375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_98]
    type = PointValue
    point = '0.0 0.615625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_99]
    type = PointValue
    point = '0.0 0.621875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_100]
    type = PointValue
    point = '0.0 0.628125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_101]
    type = PointValue
    point = '0.0 0.634375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_102]
    type = PointValue
    point = '0.0 0.640625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_103]
    type = PointValue
    point = '0.0 0.646875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_104]
    type = PointValue
    point = '0.0 0.653125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_105]
    type = PointValue
    point = '0.0 0.659375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_106]
    type = PointValue
    point = '0.0 0.665625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_107]
    type = PointValue
    point = '0.0 0.671875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_108]
    type = PointValue
    point = '0.0 0.678125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_109]
    type = PointValue
    point = '0.0 0.684375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_110]
    type = PointValue
    point = '0.0 0.690625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_111]
    type = PointValue
    point = '0.0 0.696875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_112]
    type = PointValue
    point = '0.0 0.703125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_113]
    type = PointValue
    point = '0.0 0.709375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_114]
    type = PointValue
    point = '0.0 0.715625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_115]
    type = PointValue
    point = '0.0 0.721875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_116]
    type = PointValue
    point = '0.0 0.728125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_117]
    type = PointValue
    point = '0.0 0.734375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_118]
    type = PointValue
    point = '0.0 0.740625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_119]
    type = PointValue
    point = '0.0 0.746875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_120]
    type = PointValue
    point = '0.0 0.753125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_121]
    type = PointValue
    point = '0.0 0.759375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_122]
    type = PointValue
    point = '0.0 0.765625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_123]
    type = PointValue
    point = '0.0 0.771875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_124]
    type = PointValue
    point = '0.0 0.778125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_125]
    type = PointValue
    point = '0.0 0.784375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_126]
    type = PointValue
    point = '0.0 0.790625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_127]
    type = PointValue
    point = '0.0 0.796875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_128]
    type = PointValue
    point = '0.0 0.803125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_129]
    type = PointValue
    point = '0.0 0.809375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_130]
    type = PointValue
    point = '0.0 0.815625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_131]
    type = PointValue
    point = '0.0 0.821875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_132]
    type = PointValue
    point = '0.0 0.828125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_133]
    type = PointValue
    point = '0.0 0.834375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_134]
    type = PointValue
    point = '0.0 0.840625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_135]
    type = PointValue
    point = '0.0 0.846875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_136]
    type = PointValue
    point = '0.0 0.853125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_137]
    type = PointValue
    point = '0.0 0.859375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_138]
    type = PointValue
    point = '0.0 0.865625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_139]
    type = PointValue
    point = '0.0 0.871875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_140]
    type = PointValue
    point = '0.0 0.878125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_141]
    type = PointValue
    point = '0.0 0.884375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_142]
    type = PointValue
    point = '0.0 0.890625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_143]
    type = PointValue
    point = '0.0 0.896875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_144]
    type = PointValue
    point = '0.0 0.903125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_145]
    type = PointValue
    point = '0.0 0.909375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_146]
    type = PointValue
    point = '0.0 0.915625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_147]
    type = PointValue
    point = '0.0 0.921875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_148]
    type = PointValue
    point = '0.0 0.928125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_149]
    type = PointValue
    point = '0.0 0.934375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_150]
    type = PointValue
    point = '0.0 0.940625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_151]
    type = PointValue
    point = '0.0 0.946875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_152]
    type = PointValue
    point = '0.0 0.953125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_153]
    type = PointValue
    point = '0.0 0.959375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_154]
    type = PointValue
    point = '0.0 0.965625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_155]
    type = PointValue
    point = '0.0 0.971875 0.0'
    variable = couple_stress_32
  [../]
  [./moment_156]
    type = PointValue
    point = '0.0 0.978125 0.0'
    variable = couple_stress_32
  [../]
  [./moment_157]
    type = PointValue
    point = '0.0 0.984375 0.0'
    variable = couple_stress_32
  [../]
  [./moment_158]
    type = PointValue
    point = '0.0 0.990625 0.0'
    variable = couple_stress_32
  [../]
  [./moment_159]
    type = PointValue
    point = '0.0 0.996875 0.0'
    variable = couple_stress_32
  [../]
  [./failure_0]
    type = PointValue
    point = '0.0 0.003125 0.0'
    variable = failure
  [../]
  [./failure_1]
    type = PointValue
    point = '0.0 0.009375 0.0'
    variable = failure
  [../]
  [./failure_2]
    type = PointValue
    point = '0.0 0.015625 0.0'
    variable = failure
  [../]
  [./failure_3]
    type = PointValue
    point = '0.0 0.021875 0.0'
    variable = failure
  [../]
  [./failure_4]
    type = PointValue
    point = '0.0 0.028125 0.0'
    variable = failure
  [../]
  [./failure_5]
    type = PointValue
    point = '0.0 0.034375 0.0'
    variable = failure
  [../]
  [./failure_6]
    type = PointValue
    point = '0.0 0.040625 0.0'
    variable = failure
  [../]
  [./failure_7]
    type = PointValue
    point = '0.0 0.046875 0.0'
    variable = failure
  [../]
  [./failure_8]
    type = PointValue
    point = '0.0 0.053125 0.0'
    variable = failure
  [../]
  [./failure_9]
    type = PointValue
    point = '0.0 0.059375 0.0'
    variable = failure
  [../]
  [./failure_10]
    type = PointValue
    point = '0.0 0.065625 0.0'
    variable = failure
  [../]
  [./failure_11]
    type = PointValue
    point = '0.0 0.071875 0.0'
    variable = failure
  [../]
  [./failure_12]
    type = PointValue
    point = '0.0 0.078125 0.0'
    variable = failure
  [../]
  [./failure_13]
    type = PointValue
    point = '0.0 0.084375 0.0'
    variable = failure
  [../]
  [./failure_14]
    type = PointValue
    point = '0.0 0.090625 0.0'
    variable = failure
  [../]
  [./failure_15]
    type = PointValue
    point = '0.0 0.096875 0.0'
    variable = failure
  [../]
  [./failure_16]
    type = PointValue
    point = '0.0 0.103125 0.0'
    variable = failure
  [../]
  [./failure_17]
    type = PointValue
    point = '0.0 0.109375 0.0'
    variable = failure
  [../]
  [./failure_18]
    type = PointValue
    point = '0.0 0.115625 0.0'
    variable = failure
  [../]
  [./failure_19]
    type = PointValue
    point = '0.0 0.121875 0.0'
    variable = failure
  [../]
  [./failure_20]
    type = PointValue
    point = '0.0 0.128125 0.0'
    variable = failure
  [../]
  [./failure_21]
    type = PointValue
    point = '0.0 0.134375 0.0'
    variable = failure
  [../]
  [./failure_22]
    type = PointValue
    point = '0.0 0.140625 0.0'
    variable = failure
  [../]
  [./failure_23]
    type = PointValue
    point = '0.0 0.146875 0.0'
    variable = failure
  [../]
  [./failure_24]
    type = PointValue
    point = '0.0 0.153125 0.0'
    variable = failure
  [../]
  [./failure_25]
    type = PointValue
    point = '0.0 0.159375 0.0'
    variable = failure
  [../]
  [./failure_26]
    type = PointValue
    point = '0.0 0.165625 0.0'
    variable = failure
  [../]
  [./failure_27]
    type = PointValue
    point = '0.0 0.171875 0.0'
    variable = failure
  [../]
  [./failure_28]
    type = PointValue
    point = '0.0 0.178125 0.0'
    variable = failure
  [../]
  [./failure_29]
    type = PointValue
    point = '0.0 0.184375 0.0'
    variable = failure
  [../]
  [./failure_30]
    type = PointValue
    point = '0.0 0.190625 0.0'
    variable = failure
  [../]
  [./failure_31]
    type = PointValue
    point = '0.0 0.196875 0.0'
    variable = failure
  [../]
  [./failure_32]
    type = PointValue
    point = '0.0 0.203125 0.0'
    variable = failure
  [../]
  [./failure_33]
    type = PointValue
    point = '0.0 0.209375 0.0'
    variable = failure
  [../]
  [./failure_34]
    type = PointValue
    point = '0.0 0.215625 0.0'
    variable = failure
  [../]
  [./failure_35]
    type = PointValue
    point = '0.0 0.221875 0.0'
    variable = failure
  [../]
  [./failure_36]
    type = PointValue
    point = '0.0 0.228125 0.0'
    variable = failure
  [../]
  [./failure_37]
    type = PointValue
    point = '0.0 0.234375 0.0'
    variable = failure
  [../]
  [./failure_38]
    type = PointValue
    point = '0.0 0.240625 0.0'
    variable = failure
  [../]
  [./failure_39]
    type = PointValue
    point = '0.0 0.246875 0.0'
    variable = failure
  [../]
  [./failure_40]
    type = PointValue
    point = '0.0 0.253125 0.0'
    variable = failure
  [../]
  [./failure_41]
    type = PointValue
    point = '0.0 0.259375 0.0'
    variable = failure
  [../]
  [./failure_42]
    type = PointValue
    point = '0.0 0.265625 0.0'
    variable = failure
  [../]
  [./failure_43]
    type = PointValue
    point = '0.0 0.271875 0.0'
    variable = failure
  [../]
  [./failure_44]
    type = PointValue
    point = '0.0 0.278125 0.0'
    variable = failure
  [../]
  [./failure_45]
    type = PointValue
    point = '0.0 0.284375 0.0'
    variable = failure
  [../]
  [./failure_46]
    type = PointValue
    point = '0.0 0.290625 0.0'
    variable = failure
  [../]
  [./failure_47]
    type = PointValue
    point = '0.0 0.296875 0.0'
    variable = failure
  [../]
  [./failure_48]
    type = PointValue
    point = '0.0 0.303125 0.0'
    variable = failure
  [../]
  [./failure_49]
    type = PointValue
    point = '0.0 0.309375 0.0'
    variable = failure
  [../]
  [./failure_50]
    type = PointValue
    point = '0.0 0.315625 0.0'
    variable = failure
  [../]
  [./failure_51]
    type = PointValue
    point = '0.0 0.321875 0.0'
    variable = failure
  [../]
  [./failure_52]
    type = PointValue
    point = '0.0 0.328125 0.0'
    variable = failure
  [../]
  [./failure_53]
    type = PointValue
    point = '0.0 0.334375 0.0'
    variable = failure
  [../]
  [./failure_54]
    type = PointValue
    point = '0.0 0.340625 0.0'
    variable = failure
  [../]
  [./failure_55]
    type = PointValue
    point = '0.0 0.346875 0.0'
    variable = failure
  [../]
  [./failure_56]
    type = PointValue
    point = '0.0 0.353125 0.0'
    variable = failure
  [../]
  [./failure_57]
    type = PointValue
    point = '0.0 0.359375 0.0'
    variable = failure
  [../]
  [./failure_58]
    type = PointValue
    point = '0.0 0.365625 0.0'
    variable = failure
  [../]
  [./failure_59]
    type = PointValue
    point = '0.0 0.371875 0.0'
    variable = failure
  [../]
  [./failure_60]
    type = PointValue
    point = '0.0 0.378125 0.0'
    variable = failure
  [../]
  [./failure_61]
    type = PointValue
    point = '0.0 0.384375 0.0'
    variable = failure
  [../]
  [./failure_62]
    type = PointValue
    point = '0.0 0.390625 0.0'
    variable = failure
  [../]
  [./failure_63]
    type = PointValue
    point = '0.0 0.396875 0.0'
    variable = failure
  [../]
  [./failure_64]
    type = PointValue
    point = '0.0 0.403125 0.0'
    variable = failure
  [../]
  [./failure_65]
    type = PointValue
    point = '0.0 0.409375 0.0'
    variable = failure
  [../]
  [./failure_66]
    type = PointValue
    point = '0.0 0.415625 0.0'
    variable = failure
  [../]
  [./failure_67]
    type = PointValue
    point = '0.0 0.421875 0.0'
    variable = failure
  [../]
  [./failure_68]
    type = PointValue
    point = '0.0 0.428125 0.0'
    variable = failure
  [../]
  [./failure_69]
    type = PointValue
    point = '0.0 0.434375 0.0'
    variable = failure
  [../]
  [./failure_70]
    type = PointValue
    point = '0.0 0.440625 0.0'
    variable = failure
  [../]
  [./failure_71]
    type = PointValue
    point = '0.0 0.446875 0.0'
    variable = failure
  [../]
  [./failure_72]
    type = PointValue
    point = '0.0 0.453125 0.0'
    variable = failure
  [../]
  [./failure_73]
    type = PointValue
    point = '0.0 0.459375 0.0'
    variable = failure
  [../]
  [./failure_74]
    type = PointValue
    point = '0.0 0.465625 0.0'
    variable = failure
  [../]
  [./failure_75]
    type = PointValue
    point = '0.0 0.471875 0.0'
    variable = failure
  [../]
  [./failure_76]
    type = PointValue
    point = '0.0 0.478125 0.0'
    variable = failure
  [../]
  [./failure_77]
    type = PointValue
    point = '0.0 0.484375 0.0'
    variable = failure
  [../]
  [./failure_78]
    type = PointValue
    point = '0.0 0.490625 0.0'
    variable = failure
  [../]
  [./failure_79]
    type = PointValue
    point = '0.0 0.496875 0.0'
    variable = failure
  [../]
  [./failure_80]
    type = PointValue
    point = '0.0 0.503125 0.0'
    variable = failure
  [../]
  [./failure_81]
    type = PointValue
    point = '0.0 0.509375 0.0'
    variable = failure
  [../]
  [./failure_82]
    type = PointValue
    point = '0.0 0.515625 0.0'
    variable = failure
  [../]
  [./failure_83]
    type = PointValue
    point = '0.0 0.521875 0.0'
    variable = failure
  [../]
  [./failure_84]
    type = PointValue
    point = '0.0 0.528125 0.0'
    variable = failure
  [../]
  [./failure_85]
    type = PointValue
    point = '0.0 0.534375 0.0'
    variable = failure
  [../]
  [./failure_86]
    type = PointValue
    point = '0.0 0.540625 0.0'
    variable = failure
  [../]
  [./failure_87]
    type = PointValue
    point = '0.0 0.546875 0.0'
    variable = failure
  [../]
  [./failure_88]
    type = PointValue
    point = '0.0 0.553125 0.0'
    variable = failure
  [../]
  [./failure_89]
    type = PointValue
    point = '0.0 0.559375 0.0'
    variable = failure
  [../]
  [./failure_90]
    type = PointValue
    point = '0.0 0.565625 0.0'
    variable = failure
  [../]
  [./failure_91]
    type = PointValue
    point = '0.0 0.571875 0.0'
    variable = failure
  [../]
  [./failure_92]
    type = PointValue
    point = '0.0 0.578125 0.0'
    variable = failure
  [../]
  [./failure_93]
    type = PointValue
    point = '0.0 0.584375 0.0'
    variable = failure
  [../]
  [./failure_94]
    type = PointValue
    point = '0.0 0.590625 0.0'
    variable = failure
  [../]
  [./failure_95]
    type = PointValue
    point = '0.0 0.596875 0.0'
    variable = failure
  [../]
  [./failure_96]
    type = PointValue
    point = '0.0 0.603125 0.0'
    variable = failure
  [../]
  [./failure_97]
    type = PointValue
    point = '0.0 0.609375 0.0'
    variable = failure
  [../]
  [./failure_98]
    type = PointValue
    point = '0.0 0.615625 0.0'
    variable = failure
  [../]
  [./failure_99]
    type = PointValue
    point = '0.0 0.621875 0.0'
    variable = failure
  [../]
  [./failure_100]
    type = PointValue
    point = '0.0 0.628125 0.0'
    variable = failure
  [../]
  [./failure_101]
    type = PointValue
    point = '0.0 0.634375 0.0'
    variable = failure
  [../]
  [./failure_102]
    type = PointValue
    point = '0.0 0.640625 0.0'
    variable = failure
  [../]
  [./failure_103]
    type = PointValue
    point = '0.0 0.646875 0.0'
    variable = failure
  [../]
  [./failure_104]
    type = PointValue
    point = '0.0 0.653125 0.0'
    variable = failure
  [../]
  [./failure_105]
    type = PointValue
    point = '0.0 0.659375 0.0'
    variable = failure
  [../]
  [./failure_106]
    type = PointValue
    point = '0.0 0.665625 0.0'
    variable = failure
  [../]
  [./failure_107]
    type = PointValue
    point = '0.0 0.671875 0.0'
    variable = failure
  [../]
  [./failure_108]
    type = PointValue
    point = '0.0 0.678125 0.0'
    variable = failure
  [../]
  [./failure_109]
    type = PointValue
    point = '0.0 0.684375 0.0'
    variable = failure
  [../]
  [./failure_110]
    type = PointValue
    point = '0.0 0.690625 0.0'
    variable = failure
  [../]
  [./failure_111]
    type = PointValue
    point = '0.0 0.696875 0.0'
    variable = failure
  [../]
  [./failure_112]
    type = PointValue
    point = '0.0 0.703125 0.0'
    variable = failure
  [../]
  [./failure_113]
    type = PointValue
    point = '0.0 0.709375 0.0'
    variable = failure
  [../]
  [./failure_114]
    type = PointValue
    point = '0.0 0.715625 0.0'
    variable = failure
  [../]
  [./failure_115]
    type = PointValue
    point = '0.0 0.721875 0.0'
    variable = failure
  [../]
  [./failure_116]
    type = PointValue
    point = '0.0 0.728125 0.0'
    variable = failure
  [../]
  [./failure_117]
    type = PointValue
    point = '0.0 0.734375 0.0'
    variable = failure
  [../]
  [./failure_118]
    type = PointValue
    point = '0.0 0.740625 0.0'
    variable = failure
  [../]
  [./failure_119]
    type = PointValue
    point = '0.0 0.746875 0.0'
    variable = failure
  [../]
  [./failure_120]
    type = PointValue
    point = '0.0 0.753125 0.0'
    variable = failure
  [../]
  [./failure_121]
    type = PointValue
    point = '0.0 0.759375 0.0'
    variable = failure
  [../]
  [./failure_122]
    type = PointValue
    point = '0.0 0.765625 0.0'
    variable = failure
  [../]
  [./failure_123]
    type = PointValue
    point = '0.0 0.771875 0.0'
    variable = failure
  [../]
  [./failure_124]
    type = PointValue
    point = '0.0 0.778125 0.0'
    variable = failure
  [../]
  [./failure_125]
    type = PointValue
    point = '0.0 0.784375 0.0'
    variable = failure
  [../]
  [./failure_126]
    type = PointValue
    point = '0.0 0.790625 0.0'
    variable = failure
  [../]
  [./failure_127]
    type = PointValue
    point = '0.0 0.796875 0.0'
    variable = failure
  [../]
  [./failure_128]
    type = PointValue
    point = '0.0 0.803125 0.0'
    variable = failure
  [../]
  [./failure_129]
    type = PointValue
    point = '0.0 0.809375 0.0'
    variable = failure
  [../]
  [./failure_130]
    type = PointValue
    point = '0.0 0.815625 0.0'
    variable = failure
  [../]
  [./failure_131]
    type = PointValue
    point = '0.0 0.821875 0.0'
    variable = failure
  [../]
  [./failure_132]
    type = PointValue
    point = '0.0 0.828125 0.0'
    variable = failure
  [../]
  [./failure_133]
    type = PointValue
    point = '0.0 0.834375 0.0'
    variable = failure
  [../]
  [./failure_134]
    type = PointValue
    point = '0.0 0.840625 0.0'
    variable = failure
  [../]
  [./failure_135]
    type = PointValue
    point = '0.0 0.846875 0.0'
    variable = failure
  [../]
  [./failure_136]
    type = PointValue
    point = '0.0 0.853125 0.0'
    variable = failure
  [../]
  [./failure_137]
    type = PointValue
    point = '0.0 0.859375 0.0'
    variable = failure
  [../]
  [./failure_138]
    type = PointValue
    point = '0.0 0.865625 0.0'
    variable = failure
  [../]
  [./failure_139]
    type = PointValue
    point = '0.0 0.871875 0.0'
    variable = failure
  [../]
  [./failure_140]
    type = PointValue
    point = '0.0 0.878125 0.0'
    variable = failure
  [../]
  [./failure_141]
    type = PointValue
    point = '0.0 0.884375 0.0'
    variable = failure
  [../]
  [./failure_142]
    type = PointValue
    point = '0.0 0.890625 0.0'
    variable = failure
  [../]
  [./failure_143]
    type = PointValue
    point = '0.0 0.896875 0.0'
    variable = failure
  [../]
  [./failure_144]
    type = PointValue
    point = '0.0 0.903125 0.0'
    variable = failure
  [../]
  [./failure_145]
    type = PointValue
    point = '0.0 0.909375 0.0'
    variable = failure
  [../]
  [./failure_146]
    type = PointValue
    point = '0.0 0.915625 0.0'
    variable = failure
  [../]
  [./failure_147]
    type = PointValue
    point = '0.0 0.921875 0.0'
    variable = failure
  [../]
  [./failure_148]
    type = PointValue
    point = '0.0 0.928125 0.0'
    variable = failure
  [../]
  [./failure_149]
    type = PointValue
    point = '0.0 0.934375 0.0'
    variable = failure
  [../]
  [./failure_150]
    type = PointValue
    point = '0.0 0.940625 0.0'
    variable = failure
  [../]
  [./failure_151]
    type = PointValue
    point = '0.0 0.946875 0.0'
    variable = failure
  [../]
  [./failure_152]
    type = PointValue
    point = '0.0 0.953125 0.0'
    variable = failure
  [../]
  [./failure_153]
    type = PointValue
    point = '0.0 0.959375 0.0'
    variable = failure
  [../]
  [./failure_154]
    type = PointValue
    point = '0.0 0.965625 0.0'
    variable = failure
  [../]
  [./failure_155]
    type = PointValue
    point = '0.0 0.971875 0.0'
    variable = failure
  [../]
  [./failure_156]
    type = PointValue
    point = '0.0 0.978125 0.0'
    variable = failure
  [../]
  [./failure_157]
    type = PointValue
    point = '0.0 0.984375 0.0'
    variable = failure
  [../]
  [./failure_158]
    type = PointValue
    point = '0.0 0.990625 0.0'
    variable = failure
  [../]
  [./failure_159]
    type = PointValue
    point = '0.0 0.996875 0.0'
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
    # if(t>0.000002,1000*(t-0.000002),0)
    type = ParsedFunction
    value = 1000*t
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
    temp = temperature
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
  [./strain_11]
    type = RankTwoAux
    variable = strain_11
    rank_two_tensor = total_strain
    index_j = 0
    index_i = 0
  [../]
  [./strain_22]
    type = RankTwoAux
    variable = strain_22
    rank_two_tensor = total_strain
    index_j = 1
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
    value = -133.3333
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
    type = RedbackMechMaterialHOexp
    block = 0
    B_ijkl = '0 2.0 2.0'
    C_ijkl = '1.3333E4 1.0E4 5.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 0.01
    hardening_mech_modulus = 0.25
    friction_coefficient = 0.4
    min_stepsize = 1e-8
    beta_star = 8.196721E-5
    plasticity_type = DruckerPrager_friction3D
    pore_pres = pore_pressure
    temperature = temperature
    initial_stress = '-133.3333 0 0 0 -133.3333 0 0 0 -133.3333'
	plast_factor = 5
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = 0
    gr = 0.357142857
    pressurization_coefficient = 0.9
    solid_thermal_expansion = 2.5E-5
    ref_lewis_nb = 0.0819672
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
  file_base = shear_R10_mesh160_THM_prst_mures04pl5
  print_linear_residuals = false
[]

