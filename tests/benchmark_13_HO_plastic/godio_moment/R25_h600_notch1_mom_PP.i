[Mesh]
  type = FileMesh
  file = fault_h120_notch1.msh
  boundary_name = 'top left_top left_mid left_bot front bottom right_top right_mid right_bot back'
  boundary_id = '0 1 2 3 4 5 6 7 8 9'
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
  active  = 'number_nonlin number_lin disp_y_top tangential_force normal_force number_nonlin disp_x_bottom wc_z_top dt disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 disp_x_41 disp_x_42 disp_x_43 disp_x_44 disp_x_45 disp_x_46 disp_x_47 disp_x_48 disp_x_49 disp_x_50 disp_x_51 disp_x_52 disp_x_53 disp_x_54 disp_x_55 disp_x_56 disp_x_57 disp_x_58 disp_x_59 disp_x_60 disp_x_61 disp_x_62 disp_x_63 disp_x_64 disp_x_65 disp_x_66 disp_x_67 disp_x_68 disp_x_69 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 disp_x_80 disp_x_81 disp_x_82 disp_x_83 disp_x_84 disp_x_85 disp_x_86 disp_x_87 disp_x_88 disp_x_89 disp_x_90 disp_x_91 disp_x_92 disp_x_93 disp_x_94 disp_x_95 disp_x_96 disp_x_97 disp_x_98 disp_x_99 disp_x_100 disp_x_101 disp_x_102 disp_x_103 disp_x_104 disp_x_105 disp_x_106 disp_x_107 disp_x_108 disp_x_109 disp_x_110 disp_x_111 disp_x_112 disp_x_113 disp_x_114 disp_x_115 disp_x_116 disp_x_117 disp_x_118 disp_x_119 disp_x_120 disp_x_121 disp_x_122 disp_x_123 disp_x_124 disp_x_125 disp_x_126 disp_x_127 disp_x_128 disp_x_129 disp_x_130 disp_x_131 disp_x_132 disp_x_133 disp_x_134 disp_x_135 disp_x_136 disp_x_137 disp_x_138 disp_x_139 disp_x_140 disp_x_141 disp_x_142 disp_x_143 disp_x_144 disp_x_145 disp_x_146 disp_x_147 disp_x_148 disp_x_149 disp_x_150 disp_x_151 disp_x_152 disp_x_153 disp_x_154 disp_x_155 disp_x_156 disp_x_157 disp_x_158 disp_x_159 disp_x_160 disp_x_161 disp_x_162 disp_x_163 disp_x_164 disp_x_165 disp_x_166 disp_x_167 disp_x_168 disp_x_169 disp_x_170 disp_x_171 disp_x_172 disp_x_173 disp_x_174 disp_x_175 disp_x_176 disp_x_177 disp_x_178 disp_x_179 disp_x_180 disp_x_181 disp_x_182 disp_x_183 disp_x_184 disp_x_185 disp_x_186 disp_x_187 disp_x_188 disp_x_189 disp_x_190 disp_x_191 disp_x_192 disp_x_193 disp_x_194 disp_x_195 disp_x_196 disp_x_197 disp_x_198 disp_x_199 disp_x_200 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 lagrange_40 lagrange_41 lagrange_42 lagrange_43 lagrange_44 lagrange_45 lagrange_46 lagrange_47 lagrange_48 lagrange_49 lagrange_50 lagrange_51 lagrange_52 lagrange_53 lagrange_54 lagrange_55 lagrange_56 lagrange_57 lagrange_58 lagrange_59 lagrange_60 lagrange_61 lagrange_62 lagrange_63 lagrange_64 lagrange_65 lagrange_66 lagrange_67 lagrange_68 lagrange_69 lagrange_70 lagrange_71 lagrange_72 lagrange_73 lagrange_74 lagrange_75 lagrange_76 lagrange_77 lagrange_78 lagrange_79 lagrange_80 lagrange_81 lagrange_82 lagrange_83 lagrange_84 lagrange_85 lagrange_86 lagrange_87 lagrange_88 lagrange_89 lagrange_90 lagrange_91 lagrange_92 lagrange_93 lagrange_94 lagrange_95 lagrange_96 lagrange_97 lagrange_98 lagrange_99 lagrange_100 lagrange_101 lagrange_102 lagrange_103 lagrange_104 lagrange_105 lagrange_106 lagrange_107 lagrange_108 lagrange_109 lagrange_110 lagrange_111 lagrange_112 lagrange_113 lagrange_114 lagrange_115 lagrange_116 lagrange_117 lagrange_118 lagrange_119 lagrange_120 lagrange_121 lagrange_122 lagrange_123 lagrange_124 lagrange_125 lagrange_126 lagrange_127 lagrange_128 lagrange_129 lagrange_130 lagrange_131 lagrange_132 lagrange_133 lagrange_134 lagrange_135 lagrange_136 lagrange_137 lagrange_138 lagrange_139 lagrange_140 lagrange_141 lagrange_142 lagrange_143 lagrange_144 lagrange_145 lagrange_146 lagrange_147 lagrange_148 lagrange_149 lagrange_150 lagrange_151 lagrange_152 lagrange_153 lagrange_154 lagrange_155 lagrange_156 lagrange_157 lagrange_158 lagrange_159 lagrange_160 lagrange_161 lagrange_162 lagrange_163 lagrange_164 lagrange_165 lagrange_166 lagrange_167 lagrange_168 lagrange_169 lagrange_170 lagrange_171 lagrange_172 lagrange_173 lagrange_174 lagrange_175 lagrange_176 lagrange_177 lagrange_178 lagrange_179 lagrange_180 lagrange_181 lagrange_182 lagrange_183 lagrange_184 lagrange_185 lagrange_186 lagrange_187 lagrange_188 lagrange_189 lagrange_190 lagrange_191 lagrange_192 lagrange_193 lagrange_194 lagrange_195 lagrange_196 lagrange_197 lagrange_198 lagrange_199 moment_0 moment_1 moment_2 moment_3 moment_4 moment_5 moment_6 moment_7 moment_8 moment_9 moment_10 moment_11 moment_12 moment_13 moment_14 moment_15 moment_16 moment_17 moment_18 moment_19 moment_20 moment_21 moment_22 moment_23 moment_24 moment_25 moment_26 moment_27 moment_28 moment_29 moment_30 moment_31 moment_32 moment_33 moment_34 moment_35 moment_36 moment_37 moment_38 moment_39 moment_40 moment_41 moment_42 moment_43 moment_44 moment_45 moment_46 moment_47 moment_48 moment_49 moment_50 moment_51 moment_52 moment_53 moment_54 moment_55 moment_56 moment_57 moment_58 moment_59 moment_60 moment_61 moment_62 moment_63 moment_64 moment_65 moment_66 moment_67 moment_68 moment_69 moment_70 moment_71 moment_72 moment_73 moment_74 moment_75 moment_76 moment_77 moment_78 moment_79 moment_80 moment_81 moment_82 moment_83 moment_84 moment_85 moment_86 moment_87 moment_88 moment_89 moment_90 moment_91 moment_92 moment_93 moment_94 moment_95 moment_96 moment_97 moment_98 moment_99 moment_100 moment_101 moment_102 moment_103 moment_104 moment_105 moment_106 moment_107 moment_108 moment_109 moment_110 moment_111 moment_112 moment_113 moment_114 moment_115 moment_116 moment_117 moment_118 moment_119 moment_120 moment_121 moment_122 moment_123 moment_124 moment_125 moment_126 moment_127 moment_128 moment_129 moment_130 moment_131 moment_132 moment_133 moment_134 moment_135 moment_136 moment_137 moment_138 moment_139 moment_140 moment_141 moment_142 moment_143 moment_144 moment_145 moment_146 moment_147 moment_148 moment_149 moment_150 moment_151 moment_152 moment_153 moment_154 moment_155 moment_156 moment_157 moment_158 moment_159 moment_160 moment_161 moment_162 moment_163 moment_164 moment_165 moment_166 moment_167 moment_168 moment_169 moment_170 moment_171 moment_172 moment_173 moment_174 moment_175 moment_176 moment_177 moment_178 moment_179 moment_180 moment_181 moment_182 moment_183 moment_184 moment_185 moment_186 moment_187 moment_188 moment_189 moment_190 moment_191 moment_192 moment_193 moment_194 moment_195 moment_196 moment_197 moment_198 moment_199 failure_0 failure_1 failure_2 failure_3 failure_4 failure_5 failure_6 failure_7 failure_8 failure_9 failure_10 failure_11 failure_12 failure_13 failure_14 failure_15 failure_16 failure_17 failure_18 failure_19 failure_20 failure_21 failure_22 failure_23 failure_24 failure_25 failure_26 failure_27 failure_28 failure_29 failure_30 failure_31 failure_32 failure_33 failure_34 failure_35 failure_36 failure_37 failure_38 failure_39 failure_40 failure_41 failure_42 failure_43 failure_44 failure_45 failure_46 failure_47 failure_48 failure_49 failure_50 failure_51 failure_52 failure_53 failure_54 failure_55 failure_56 failure_57 failure_58 failure_59 failure_60 failure_61 failure_62 failure_63 failure_64 failure_65 failure_66 failure_67 failure_68 failure_69 failure_70 failure_71 failure_72 failure_73 failure_74 failure_75 failure_76 failure_77 failure_78 failure_79 failure_80 failure_81 failure_82 failure_83 failure_84 failure_85 failure_86 failure_87 failure_88 failure_89 failure_90 failure_91 failure_92 failure_93 failure_94 failure_95 failure_96 failure_97 failure_98 failure_99 failure_100 failure_101 failure_102 failure_103 failure_104 failure_105 failure_106 failure_107 failure_108 failure_109 failure_110 failure_111 failure_112 failure_113 failure_114 failure_115 failure_116 failure_117 failure_118 failure_119 failure_120 failure_121 failure_122 failure_123 failure_124 failure_125 failure_126 failure_127 failure_128 failure_129 failure_130 failure_131 failure_132 failure_133 failure_134 failure_135 failure_136 failure_137 failure_138 failure_139 failure_140 failure_141 failure_142 failure_143 failure_144 failure_145 failure_146 failure_147 failure_148 failure_149 failure_150 failure_151 failure_152 failure_153 failure_154 failure_155 failure_156 failure_157 failure_158 failure_159 failure_160 failure_161 failure_162 failure_163 failure_164 failure_165 failure_166 failure_167 failure_168 failure_169 failure_170 failure_171 failure_172 failure_173 failure_174 failure_175 failure_176 failure_177 failure_178 failure_179 failure_180 failure_181 failure_182 failure_183 failure_184 failure_185 failure_186 failure_187 failure_188 failure_189 failure_190 failure_191 failure_192 failure_193 failure_194 failure_195 failure_196 failure_197 failure_198 failure_199'
  [./disp_x_0]
    type = PointValue
    point = '1.0 0.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '1.0 0.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '1.0 1.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '1.0 1.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '1.0 2.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '1.0 3.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '1.0 3.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '1.0 4.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '1.0 4.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '1.0 5.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '1.0 6.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '1.0 6.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '1.0 7.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '1.0 7.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '1.0 8.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '1.0 9.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '1.0 9.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '1.0 10.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '1.0 10.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '1.0 11.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '1.0 12.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '1.0 12.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '1.0 13.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '1.0 13.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '1.0 14.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '1.0 15.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '1.0 15.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '1.0 16.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '1.0 16.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '1.0 17.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '1.0 18.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '1.0 18.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '1.0 19.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '1.0 19.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '1.0 20.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '1.0 21.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '1.0 21.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '1.0 22.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '1.0 22.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '1.0 23.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '1.0 24.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '1.0 24.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '1.0 25.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '1.0 25.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '1.0 26.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '1.0 27.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '1.0 27.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '1.0 28.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '1.0 28.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '1.0 29.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '1.0 30.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '1.0 30.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '1.0 31.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '1.0 31.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '1.0 32.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '1.0 33.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '1.0 33.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '1.0 34.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '1.0 34.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '1.0 35.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '1.0 36.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '1.0 36.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '1.0 37.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '1.0 37.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '1.0 38.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '1.0 39.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '1.0 39.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '1.0 40.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '1.0 40.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '1.0 41.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '1.0 42.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '1.0 42.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '1.0 43.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '1.0 43.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '1.0 44.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '1.0 45.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '1.0 45.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '1.0 46.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '1.0 46.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '1.0 47.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '1.0 48.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_81]
    type = PointValue
    point = '1.0 48.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_82]
    type = PointValue
    point = '1.0 49.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_83]
    type = PointValue
    point = '1.0 49.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_84]
    type = PointValue
    point = '1.0 50.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_85]
    type = PointValue
    point = '1.0 51.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_86]
    type = PointValue
    point = '1.0 51.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_87]
    type = PointValue
    point = '1.0 52.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_88]
    type = PointValue
    point = '1.0 52.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_89]
    type = PointValue
    point = '1.0 53.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_90]
    type = PointValue
    point = '1.0 54.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_91]
    type = PointValue
    point = '1.0 54.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_92]
    type = PointValue
    point = '1.0 55.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_93]
    type = PointValue
    point = '1.0 55.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_94]
    type = PointValue
    point = '1.0 56.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_95]
    type = PointValue
    point = '1.0 57.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_96]
    type = PointValue
    point = '1.0 57.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_97]
    type = PointValue
    point = '1.0 58.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_98]
    type = PointValue
    point = '1.0 58.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_99]
    type = PointValue
    point = '1.0 59.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_100]
    type = PointValue
    point = '1.0 60.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_101]
    type = PointValue
    point = '1.0 60.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_102]
    type = PointValue
    point = '1.0 61.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_103]
    type = PointValue
    point = '1.0 61.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_104]
    type = PointValue
    point = '1.0 62.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_105]
    type = PointValue
    point = '1.0 63.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_106]
    type = PointValue
    point = '1.0 63.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_107]
    type = PointValue
    point = '1.0 64.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_108]
    type = PointValue
    point = '1.0 64.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_109]
    type = PointValue
    point = '1.0 65.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_110]
    type = PointValue
    point = '1.0 66.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_111]
    type = PointValue
    point = '1.0 66.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_112]
    type = PointValue
    point = '1.0 67.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_113]
    type = PointValue
    point = '1.0 67.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_114]
    type = PointValue
    point = '1.0 68.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_115]
    type = PointValue
    point = '1.0 69.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_116]
    type = PointValue
    point = '1.0 69.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_117]
    type = PointValue
    point = '1.0 70.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_118]
    type = PointValue
    point = '1.0 70.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_119]
    type = PointValue
    point = '1.0 71.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_120]
    type = PointValue
    point = '1.0 72.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_121]
    type = PointValue
    point = '1.0 72.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_122]
    type = PointValue
    point = '1.0 73.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_123]
    type = PointValue
    point = '1.0 73.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_124]
    type = PointValue
    point = '1.0 74.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_125]
    type = PointValue
    point = '1.0 75.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_126]
    type = PointValue
    point = '1.0 75.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_127]
    type = PointValue
    point = '1.0 76.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_128]
    type = PointValue
    point = '1.0 76.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_129]
    type = PointValue
    point = '1.0 77.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_130]
    type = PointValue
    point = '1.0 78.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_131]
    type = PointValue
    point = '1.0 78.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_132]
    type = PointValue
    point = '1.0 79.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_133]
    type = PointValue
    point = '1.0 79.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_134]
    type = PointValue
    point = '1.0 80.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_135]
    type = PointValue
    point = '1.0 81.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_136]
    type = PointValue
    point = '1.0 81.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_137]
    type = PointValue
    point = '1.0 82.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_138]
    type = PointValue
    point = '1.0 82.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_139]
    type = PointValue
    point = '1.0 83.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_140]
    type = PointValue
    point = '1.0 84.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_141]
    type = PointValue
    point = '1.0 84.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_142]
    type = PointValue
    point = '1.0 85.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_143]
    type = PointValue
    point = '1.0 85.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_144]
    type = PointValue
    point = '1.0 86.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_145]
    type = PointValue
    point = '1.0 87.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_146]
    type = PointValue
    point = '1.0 87.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_147]
    type = PointValue
    point = '1.0 88.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_148]
    type = PointValue
    point = '1.0 88.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_149]
    type = PointValue
    point = '1.0 89.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_150]
    type = PointValue
    point = '1.0 90.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_151]
    type = PointValue
    point = '1.0 90.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_152]
    type = PointValue
    point = '1.0 91.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_153]
    type = PointValue
    point = '1.0 91.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_154]
    type = PointValue
    point = '1.0 92.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_155]
    type = PointValue
    point = '1.0 93.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_156]
    type = PointValue
    point = '1.0 93.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_157]
    type = PointValue
    point = '1.0 94.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_158]
    type = PointValue
    point = '1.0 94.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_159]
    type = PointValue
    point = '1.0 95.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_160]
    type = PointValue
    point = '1.0 96.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_161]
    type = PointValue
    point = '1.0 96.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_162]
    type = PointValue
    point = '1.0 97.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_163]
    type = PointValue
    point = '1.0 97.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_164]
    type = PointValue
    point = '1.0 98.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_165]
    type = PointValue
    point = '1.0 99.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_166]
    type = PointValue
    point = '1.0 99.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_167]
    type = PointValue
    point = '1.0 100.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_168]
    type = PointValue
    point = '1.0 100.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_169]
    type = PointValue
    point = '1.0 101.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_170]
    type = PointValue
    point = '1.0 102.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_171]
    type = PointValue
    point = '1.0 102.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_172]
    type = PointValue
    point = '1.0 103.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_173]
    type = PointValue
    point = '1.0 103.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_174]
    type = PointValue
    point = '1.0 104.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_175]
    type = PointValue
    point = '1.0 105.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_176]
    type = PointValue
    point = '1.0 105.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_177]
    type = PointValue
    point = '1.0 106.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_178]
    type = PointValue
    point = '1.0 106.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_179]
    type = PointValue
    point = '1.0 107.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_180]
    type = PointValue
    point = '1.0 108.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_181]
    type = PointValue
    point = '1.0 108.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_182]
    type = PointValue
    point = '1.0 109.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_183]
    type = PointValue
    point = '1.0 109.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_184]
    type = PointValue
    point = '1.0 110.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_185]
    type = PointValue
    point = '1.0 111.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_186]
    type = PointValue
    point = '1.0 111.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_187]
    type = PointValue
    point = '1.0 112.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_188]
    type = PointValue
    point = '1.0 112.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_189]
    type = PointValue
    point = '1.0 113.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_190]
    type = PointValue
    point = '1.0 114.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_191]
    type = PointValue
    point = '1.0 114.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_192]
    type = PointValue
    point = '1.0 115.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_193]
    type = PointValue
    point = '1.0 115.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_194]
    type = PointValue
    point = '1.0 116.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_195]
    type = PointValue
    point = '1.0 117.0 1.0'
    variable = disp_x
  [../]
  [./disp_x_196]
    type = PointValue
    point = '1.0 117.6 1.0'
    variable = disp_x
  [../]
  [./disp_x_197]
    type = PointValue
    point = '1.0 118.2 1.0'
    variable = disp_x
  [../]
  [./disp_x_198]
    type = PointValue
    point = '1.0 118.8 1.0'
    variable = disp_x
  [../]
  [./disp_x_199]
    type = PointValue
    point = '1.0 119.4 1.0'
    variable = disp_x
  [../]
  [./disp_x_200]
    type = PointValue
    point = '1.0 120.0 1.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '1.0 0.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '1.0 0.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '1.0 1.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '1.0 2.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '1.0 2.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '1.0 3.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '1.0 3.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '1.0 4.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '1.0 5.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '1.0 5.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '1.0 6.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '1.0 6.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '1.0 7.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '1.0 8.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '1.0 8.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '1.0 9.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '1.0 9.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '1.0 10.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '1.0 11.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '1.0 11.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '1.0 12.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '1.0 12.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '1.0 13.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '1.0 14.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '1.0 14.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '1.0 15.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '1.0 15.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '1.0 16.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '1.0 17.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '1.0 17.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '1.0 18.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '1.0 18.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '1.0 19.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '1.0 20.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '1.0 20.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '1.0 21.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '1.0 21.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '1.0 22.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '1.0 23.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '1.0 23.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '1.0 24.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '1.0 24.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '1.0 25.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '1.0 26.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '1.0 26.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '1.0 27.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '1.0 27.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '1.0 28.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '1.0 29.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '1.0 29.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '1.0 30.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '1.0 30.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '1.0 31.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '1.0 32.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '1.0 32.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '1.0 33.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '1.0 33.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '1.0 34.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '1.0 35.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '1.0 35.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '1.0 36.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '1.0 36.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '1.0 37.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '1.0 38.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '1.0 38.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '1.0 39.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '1.0 39.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '1.0 40.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '1.0 41.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '1.0 41.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '1.0 42.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '1.0 42.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '1.0 43.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '1.0 44.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '1.0 44.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '1.0 45.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '1.0 45.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '1.0 46.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '1.0 47.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '1.0 47.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_80]
    type = PointValue
    point = '1.0 48.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_81]
    type = PointValue
    point = '1.0 48.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_82]
    type = PointValue
    point = '1.0 49.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_83]
    type = PointValue
    point = '1.0 50.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_84]
    type = PointValue
    point = '1.0 50.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_85]
    type = PointValue
    point = '1.0 51.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_86]
    type = PointValue
    point = '1.0 51.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_87]
    type = PointValue
    point = '1.0 52.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_88]
    type = PointValue
    point = '1.0 53.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_89]
    type = PointValue
    point = '1.0 53.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_90]
    type = PointValue
    point = '1.0 54.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_91]
    type = PointValue
    point = '1.0 54.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_92]
    type = PointValue
    point = '1.0 55.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_93]
    type = PointValue
    point = '1.0 56.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_94]
    type = PointValue
    point = '1.0 56.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_95]
    type = PointValue
    point = '1.0 57.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_96]
    type = PointValue
    point = '1.0 57.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_97]
    type = PointValue
    point = '1.0 58.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_98]
    type = PointValue
    point = '1.0 59.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_99]
    type = PointValue
    point = '1.0 59.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_100]
    type = PointValue
    point = '1.0 60.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_101]
    type = PointValue
    point = '1.0 60.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_102]
    type = PointValue
    point = '1.0 61.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_103]
    type = PointValue
    point = '1.0 62.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_104]
    type = PointValue
    point = '1.0 62.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_105]
    type = PointValue
    point = '1.0 63.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_106]
    type = PointValue
    point = '1.0 63.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_107]
    type = PointValue
    point = '1.0 64.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_108]
    type = PointValue
    point = '1.0 65.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_109]
    type = PointValue
    point = '1.0 65.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_110]
    type = PointValue
    point = '1.0 66.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_111]
    type = PointValue
    point = '1.0 66.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_112]
    type = PointValue
    point = '1.0 67.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_113]
    type = PointValue
    point = '1.0 68.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_114]
    type = PointValue
    point = '1.0 68.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_115]
    type = PointValue
    point = '1.0 69.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_116]
    type = PointValue
    point = '1.0 69.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_117]
    type = PointValue
    point = '1.0 70.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_118]
    type = PointValue
    point = '1.0 71.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_119]
    type = PointValue
    point = '1.0 71.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_120]
    type = PointValue
    point = '1.0 72.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_121]
    type = PointValue
    point = '1.0 72.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_122]
    type = PointValue
    point = '1.0 73.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_123]
    type = PointValue
    point = '1.0 74.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_124]
    type = PointValue
    point = '1.0 74.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_125]
    type = PointValue
    point = '1.0 75.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_126]
    type = PointValue
    point = '1.0 75.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_127]
    type = PointValue
    point = '1.0 76.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_128]
    type = PointValue
    point = '1.0 77.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_129]
    type = PointValue
    point = '1.0 77.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_130]
    type = PointValue
    point = '1.0 78.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_131]
    type = PointValue
    point = '1.0 78.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_132]
    type = PointValue
    point = '1.0 79.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_133]
    type = PointValue
    point = '1.0 80.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_134]
    type = PointValue
    point = '1.0 80.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_135]
    type = PointValue
    point = '1.0 81.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_136]
    type = PointValue
    point = '1.0 81.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_137]
    type = PointValue
    point = '1.0 82.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_138]
    type = PointValue
    point = '1.0 83.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_139]
    type = PointValue
    point = '1.0 83.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_140]
    type = PointValue
    point = '1.0 84.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_141]
    type = PointValue
    point = '1.0 84.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_142]
    type = PointValue
    point = '1.0 85.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_143]
    type = PointValue
    point = '1.0 86.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_144]
    type = PointValue
    point = '1.0 86.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_145]
    type = PointValue
    point = '1.0 87.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_146]
    type = PointValue
    point = '1.0 87.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_147]
    type = PointValue
    point = '1.0 88.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_148]
    type = PointValue
    point = '1.0 89.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_149]
    type = PointValue
    point = '1.0 89.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_150]
    type = PointValue
    point = '1.0 90.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_151]
    type = PointValue
    point = '1.0 90.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_152]
    type = PointValue
    point = '1.0 91.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_153]
    type = PointValue
    point = '1.0 92.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_154]
    type = PointValue
    point = '1.0 92.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_155]
    type = PointValue
    point = '1.0 93.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_156]
    type = PointValue
    point = '1.0 93.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_157]
    type = PointValue
    point = '1.0 94.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_158]
    type = PointValue
    point = '1.0 95.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_159]
    type = PointValue
    point = '1.0 95.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_160]
    type = PointValue
    point = '1.0 96.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_161]
    type = PointValue
    point = '1.0 96.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_162]
    type = PointValue
    point = '1.0 97.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_163]
    type = PointValue
    point = '1.0 98.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_164]
    type = PointValue
    point = '1.0 98.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_165]
    type = PointValue
    point = '1.0 99.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_166]
    type = PointValue
    point = '1.0 99.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_167]
    type = PointValue
    point = '1.0 100.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_168]
    type = PointValue
    point = '1.0 101.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_169]
    type = PointValue
    point = '1.0 101.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_170]
    type = PointValue
    point = '1.0 102.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_171]
    type = PointValue
    point = '1.0 102.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_172]
    type = PointValue
    point = '1.0 103.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_173]
    type = PointValue
    point = '1.0 104.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_174]
    type = PointValue
    point = '1.0 104.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_175]
    type = PointValue
    point = '1.0 105.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_176]
    type = PointValue
    point = '1.0 105.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_177]
    type = PointValue
    point = '1.0 106.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_178]
    type = PointValue
    point = '1.0 107.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_179]
    type = PointValue
    point = '1.0 107.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_180]
    type = PointValue
    point = '1.0 108.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_181]
    type = PointValue
    point = '1.0 108.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_182]
    type = PointValue
    point = '1.0 109.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_183]
    type = PointValue
    point = '1.0 110.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_184]
    type = PointValue
    point = '1.0 110.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_185]
    type = PointValue
    point = '1.0 111.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_186]
    type = PointValue
    point = '1.0 111.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_187]
    type = PointValue
    point = '1.0 112.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_188]
    type = PointValue
    point = '1.0 113.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_189]
    type = PointValue
    point = '1.0 113.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_190]
    type = PointValue
    point = '1.0 114.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_191]
    type = PointValue
    point = '1.0 114.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_192]
    type = PointValue
    point = '1.0 115.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_193]
    type = PointValue
    point = '1.0 116.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_194]
    type = PointValue
    point = '1.0 116.7 1.0'
    variable = lagrange
  [../]
  [./lagrange_195]
    type = PointValue
    point = '1.0 117.3 1.0'
    variable = lagrange
  [../]
  [./lagrange_196]
    type = PointValue
    point = '1.0 117.9 1.0'
    variable = lagrange
  [../]
  [./lagrange_197]
    type = PointValue
    point = '1.0 118.5 1.0'
    variable = lagrange
  [../]
  [./lagrange_198]
    type = PointValue
    point = '1.0 119.1 1.0'
    variable = lagrange
  [../]
  [./lagrange_199]
    type = PointValue
    point = '1.0 119.7 1.0'
    variable = lagrange
  [../]
  [./moment_0]
    type = PointValue
    point = '1.0 0.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_1]
    type = PointValue
    point = '1.0 0.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_2]
    type = PointValue
    point = '1.0 1.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_3]
    type = PointValue
    point = '1.0 2.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_4]
    type = PointValue
    point = '1.0 2.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_5]
    type = PointValue
    point = '1.0 3.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_6]
    type = PointValue
    point = '1.0 3.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_7]
    type = PointValue
    point = '1.0 4.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_8]
    type = PointValue
    point = '1.0 5.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_9]
    type = PointValue
    point = '1.0 5.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_10]
    type = PointValue
    point = '1.0 6.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_11]
    type = PointValue
    point = '1.0 6.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_12]
    type = PointValue
    point = '1.0 7.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_13]
    type = PointValue
    point = '1.0 8.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_14]
    type = PointValue
    point = '1.0 8.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_15]
    type = PointValue
    point = '1.0 9.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_16]
    type = PointValue
    point = '1.0 9.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_17]
    type = PointValue
    point = '1.0 10.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_18]
    type = PointValue
    point = '1.0 11.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_19]
    type = PointValue
    point = '1.0 11.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_20]
    type = PointValue
    point = '1.0 12.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_21]
    type = PointValue
    point = '1.0 12.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_22]
    type = PointValue
    point = '1.0 13.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_23]
    type = PointValue
    point = '1.0 14.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_24]
    type = PointValue
    point = '1.0 14.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_25]
    type = PointValue
    point = '1.0 15.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_26]
    type = PointValue
    point = '1.0 15.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_27]
    type = PointValue
    point = '1.0 16.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_28]
    type = PointValue
    point = '1.0 17.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_29]
    type = PointValue
    point = '1.0 17.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_30]
    type = PointValue
    point = '1.0 18.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_31]
    type = PointValue
    point = '1.0 18.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_32]
    type = PointValue
    point = '1.0 19.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_33]
    type = PointValue
    point = '1.0 20.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_34]
    type = PointValue
    point = '1.0 20.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_35]
    type = PointValue
    point = '1.0 21.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_36]
    type = PointValue
    point = '1.0 21.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_37]
    type = PointValue
    point = '1.0 22.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_38]
    type = PointValue
    point = '1.0 23.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_39]
    type = PointValue
    point = '1.0 23.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_40]
    type = PointValue
    point = '1.0 24.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_41]
    type = PointValue
    point = '1.0 24.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_42]
    type = PointValue
    point = '1.0 25.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_43]
    type = PointValue
    point = '1.0 26.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_44]
    type = PointValue
    point = '1.0 26.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_45]
    type = PointValue
    point = '1.0 27.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_46]
    type = PointValue
    point = '1.0 27.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_47]
    type = PointValue
    point = '1.0 28.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_48]
    type = PointValue
    point = '1.0 29.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_49]
    type = PointValue
    point = '1.0 29.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_50]
    type = PointValue
    point = '1.0 30.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_51]
    type = PointValue
    point = '1.0 30.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_52]
    type = PointValue
    point = '1.0 31.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_53]
    type = PointValue
    point = '1.0 32.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_54]
    type = PointValue
    point = '1.0 32.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_55]
    type = PointValue
    point = '1.0 33.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_56]
    type = PointValue
    point = '1.0 33.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_57]
    type = PointValue
    point = '1.0 34.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_58]
    type = PointValue
    point = '1.0 35.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_59]
    type = PointValue
    point = '1.0 35.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_60]
    type = PointValue
    point = '1.0 36.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_61]
    type = PointValue
    point = '1.0 36.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_62]
    type = PointValue
    point = '1.0 37.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_63]
    type = PointValue
    point = '1.0 38.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_64]
    type = PointValue
    point = '1.0 38.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_65]
    type = PointValue
    point = '1.0 39.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_66]
    type = PointValue
    point = '1.0 39.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_67]
    type = PointValue
    point = '1.0 40.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_68]
    type = PointValue
    point = '1.0 41.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_69]
    type = PointValue
    point = '1.0 41.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_70]
    type = PointValue
    point = '1.0 42.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_71]
    type = PointValue
    point = '1.0 42.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_72]
    type = PointValue
    point = '1.0 43.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_73]
    type = PointValue
    point = '1.0 44.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_74]
    type = PointValue
    point = '1.0 44.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_75]
    type = PointValue
    point = '1.0 45.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_76]
    type = PointValue
    point = '1.0 45.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_77]
    type = PointValue
    point = '1.0 46.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_78]
    type = PointValue
    point = '1.0 47.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_79]
    type = PointValue
    point = '1.0 47.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_80]
    type = PointValue
    point = '1.0 48.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_81]
    type = PointValue
    point = '1.0 48.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_82]
    type = PointValue
    point = '1.0 49.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_83]
    type = PointValue
    point = '1.0 50.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_84]
    type = PointValue
    point = '1.0 50.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_85]
    type = PointValue
    point = '1.0 51.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_86]
    type = PointValue
    point = '1.0 51.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_87]
    type = PointValue
    point = '1.0 52.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_88]
    type = PointValue
    point = '1.0 53.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_89]
    type = PointValue
    point = '1.0 53.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_90]
    type = PointValue
    point = '1.0 54.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_91]
    type = PointValue
    point = '1.0 54.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_92]
    type = PointValue
    point = '1.0 55.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_93]
    type = PointValue
    point = '1.0 56.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_94]
    type = PointValue
    point = '1.0 56.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_95]
    type = PointValue
    point = '1.0 57.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_96]
    type = PointValue
    point = '1.0 57.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_97]
    type = PointValue
    point = '1.0 58.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_98]
    type = PointValue
    point = '1.0 59.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_99]
    type = PointValue
    point = '1.0 59.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_100]
    type = PointValue
    point = '1.0 60.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_101]
    type = PointValue
    point = '1.0 60.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_102]
    type = PointValue
    point = '1.0 61.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_103]
    type = PointValue
    point = '1.0 62.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_104]
    type = PointValue
    point = '1.0 62.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_105]
    type = PointValue
    point = '1.0 63.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_106]
    type = PointValue
    point = '1.0 63.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_107]
    type = PointValue
    point = '1.0 64.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_108]
    type = PointValue
    point = '1.0 65.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_109]
    type = PointValue
    point = '1.0 65.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_110]
    type = PointValue
    point = '1.0 66.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_111]
    type = PointValue
    point = '1.0 66.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_112]
    type = PointValue
    point = '1.0 67.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_113]
    type = PointValue
    point = '1.0 68.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_114]
    type = PointValue
    point = '1.0 68.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_115]
    type = PointValue
    point = '1.0 69.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_116]
    type = PointValue
    point = '1.0 69.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_117]
    type = PointValue
    point = '1.0 70.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_118]
    type = PointValue
    point = '1.0 71.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_119]
    type = PointValue
    point = '1.0 71.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_120]
    type = PointValue
    point = '1.0 72.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_121]
    type = PointValue
    point = '1.0 72.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_122]
    type = PointValue
    point = '1.0 73.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_123]
    type = PointValue
    point = '1.0 74.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_124]
    type = PointValue
    point = '1.0 74.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_125]
    type = PointValue
    point = '1.0 75.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_126]
    type = PointValue
    point = '1.0 75.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_127]
    type = PointValue
    point = '1.0 76.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_128]
    type = PointValue
    point = '1.0 77.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_129]
    type = PointValue
    point = '1.0 77.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_130]
    type = PointValue
    point = '1.0 78.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_131]
    type = PointValue
    point = '1.0 78.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_132]
    type = PointValue
    point = '1.0 79.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_133]
    type = PointValue
    point = '1.0 80.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_134]
    type = PointValue
    point = '1.0 80.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_135]
    type = PointValue
    point = '1.0 81.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_136]
    type = PointValue
    point = '1.0 81.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_137]
    type = PointValue
    point = '1.0 82.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_138]
    type = PointValue
    point = '1.0 83.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_139]
    type = PointValue
    point = '1.0 83.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_140]
    type = PointValue
    point = '1.0 84.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_141]
    type = PointValue
    point = '1.0 84.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_142]
    type = PointValue
    point = '1.0 85.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_143]
    type = PointValue
    point = '1.0 86.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_144]
    type = PointValue
    point = '1.0 86.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_145]
    type = PointValue
    point = '1.0 87.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_146]
    type = PointValue
    point = '1.0 87.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_147]
    type = PointValue
    point = '1.0 88.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_148]
    type = PointValue
    point = '1.0 89.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_149]
    type = PointValue
    point = '1.0 89.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_150]
    type = PointValue
    point = '1.0 90.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_151]
    type = PointValue
    point = '1.0 90.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_152]
    type = PointValue
    point = '1.0 91.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_153]
    type = PointValue
    point = '1.0 92.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_154]
    type = PointValue
    point = '1.0 92.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_155]
    type = PointValue
    point = '1.0 93.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_156]
    type = PointValue
    point = '1.0 93.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_157]
    type = PointValue
    point = '1.0 94.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_158]
    type = PointValue
    point = '1.0 95.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_159]
    type = PointValue
    point = '1.0 95.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_160]
    type = PointValue
    point = '1.0 96.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_161]
    type = PointValue
    point = '1.0 96.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_162]
    type = PointValue
    point = '1.0 97.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_163]
    type = PointValue
    point = '1.0 98.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_164]
    type = PointValue
    point = '1.0 98.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_165]
    type = PointValue
    point = '1.0 99.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_166]
    type = PointValue
    point = '1.0 99.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_167]
    type = PointValue
    point = '1.0 100.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_168]
    type = PointValue
    point = '1.0 101.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_169]
    type = PointValue
    point = '1.0 101.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_170]
    type = PointValue
    point = '1.0 102.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_171]
    type = PointValue
    point = '1.0 102.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_172]
    type = PointValue
    point = '1.0 103.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_173]
    type = PointValue
    point = '1.0 104.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_174]
    type = PointValue
    point = '1.0 104.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_175]
    type = PointValue
    point = '1.0 105.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_176]
    type = PointValue
    point = '1.0 105.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_177]
    type = PointValue
    point = '1.0 106.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_178]
    type = PointValue
    point = '1.0 107.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_179]
    type = PointValue
    point = '1.0 107.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_180]
    type = PointValue
    point = '1.0 108.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_181]
    type = PointValue
    point = '1.0 108.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_182]
    type = PointValue
    point = '1.0 109.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_183]
    type = PointValue
    point = '1.0 110.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_184]
    type = PointValue
    point = '1.0 110.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_185]
    type = PointValue
    point = '1.0 111.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_186]
    type = PointValue
    point = '1.0 111.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_187]
    type = PointValue
    point = '1.0 112.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_188]
    type = PointValue
    point = '1.0 113.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_189]
    type = PointValue
    point = '1.0 113.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_190]
    type = PointValue
    point = '1.0 114.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_191]
    type = PointValue
    point = '1.0 114.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_192]
    type = PointValue
    point = '1.0 115.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_193]
    type = PointValue
    point = '1.0 116.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_194]
    type = PointValue
    point = '1.0 116.7 1.0'
    variable = couple_stress_32
  [../]
  [./moment_195]
    type = PointValue
    point = '1.0 117.3 1.0'
    variable = couple_stress_32
  [../]
  [./moment_196]
    type = PointValue
    point = '1.0 117.9 1.0'
    variable = couple_stress_32
  [../]
  [./moment_197]
    type = PointValue
    point = '1.0 118.5 1.0'
    variable = couple_stress_32
  [../]
  [./moment_198]
    type = PointValue
    point = '1.0 119.1 1.0'
    variable = couple_stress_32
  [../]
  [./moment_199]
    type = PointValue
    point = '1.0 119.7 1.0'
    variable = couple_stress_32
  [../]
  [./failure_0]
    type = PointValue
    point = '1.0 0.3 1.0'
    variable = failure
  [../]
  [./failure_1]
    type = PointValue
    point = '1.0 0.9 1.0'
    variable = failure
  [../]
  [./failure_2]
    type = PointValue
    point = '1.0 1.5 1.0'
    variable = failure
  [../]
  [./failure_3]
    type = PointValue
    point = '1.0 2.1 1.0'
    variable = failure
  [../]
  [./failure_4]
    type = PointValue
    point = '1.0 2.7 1.0'
    variable = failure
  [../]
  [./failure_5]
    type = PointValue
    point = '1.0 3.3 1.0'
    variable = failure
  [../]
  [./failure_6]
    type = PointValue
    point = '1.0 3.9 1.0'
    variable = failure
  [../]
  [./failure_7]
    type = PointValue
    point = '1.0 4.5 1.0'
    variable = failure
  [../]
  [./failure_8]
    type = PointValue
    point = '1.0 5.1 1.0'
    variable = failure
  [../]
  [./failure_9]
    type = PointValue
    point = '1.0 5.7 1.0'
    variable = failure
  [../]
  [./failure_10]
    type = PointValue
    point = '1.0 6.3 1.0'
    variable = failure
  [../]
  [./failure_11]
    type = PointValue
    point = '1.0 6.9 1.0'
    variable = failure
  [../]
  [./failure_12]
    type = PointValue
    point = '1.0 7.5 1.0'
    variable = failure
  [../]
  [./failure_13]
    type = PointValue
    point = '1.0 8.1 1.0'
    variable = failure
  [../]
  [./failure_14]
    type = PointValue
    point = '1.0 8.7 1.0'
    variable = failure
  [../]
  [./failure_15]
    type = PointValue
    point = '1.0 9.3 1.0'
    variable = failure
  [../]
  [./failure_16]
    type = PointValue
    point = '1.0 9.9 1.0'
    variable = failure
  [../]
  [./failure_17]
    type = PointValue
    point = '1.0 10.5 1.0'
    variable = failure
  [../]
  [./failure_18]
    type = PointValue
    point = '1.0 11.1 1.0'
    variable = failure
  [../]
  [./failure_19]
    type = PointValue
    point = '1.0 11.7 1.0'
    variable = failure
  [../]
  [./failure_20]
    type = PointValue
    point = '1.0 12.3 1.0'
    variable = failure
  [../]
  [./failure_21]
    type = PointValue
    point = '1.0 12.9 1.0'
    variable = failure
  [../]
  [./failure_22]
    type = PointValue
    point = '1.0 13.5 1.0'
    variable = failure
  [../]
  [./failure_23]
    type = PointValue
    point = '1.0 14.1 1.0'
    variable = failure
  [../]
  [./failure_24]
    type = PointValue
    point = '1.0 14.7 1.0'
    variable = failure
  [../]
  [./failure_25]
    type = PointValue
    point = '1.0 15.3 1.0'
    variable = failure
  [../]
  [./failure_26]
    type = PointValue
    point = '1.0 15.9 1.0'
    variable = failure
  [../]
  [./failure_27]
    type = PointValue
    point = '1.0 16.5 1.0'
    variable = failure
  [../]
  [./failure_28]
    type = PointValue
    point = '1.0 17.1 1.0'
    variable = failure
  [../]
  [./failure_29]
    type = PointValue
    point = '1.0 17.7 1.0'
    variable = failure
  [../]
  [./failure_30]
    type = PointValue
    point = '1.0 18.3 1.0'
    variable = failure
  [../]
  [./failure_31]
    type = PointValue
    point = '1.0 18.9 1.0'
    variable = failure
  [../]
  [./failure_32]
    type = PointValue
    point = '1.0 19.5 1.0'
    variable = failure
  [../]
  [./failure_33]
    type = PointValue
    point = '1.0 20.1 1.0'
    variable = failure
  [../]
  [./failure_34]
    type = PointValue
    point = '1.0 20.7 1.0'
    variable = failure
  [../]
  [./failure_35]
    type = PointValue
    point = '1.0 21.3 1.0'
    variable = failure
  [../]
  [./failure_36]
    type = PointValue
    point = '1.0 21.9 1.0'
    variable = failure
  [../]
  [./failure_37]
    type = PointValue
    point = '1.0 22.5 1.0'
    variable = failure
  [../]
  [./failure_38]
    type = PointValue
    point = '1.0 23.1 1.0'
    variable = failure
  [../]
  [./failure_39]
    type = PointValue
    point = '1.0 23.7 1.0'
    variable = failure
  [../]
  [./failure_40]
    type = PointValue
    point = '1.0 24.3 1.0'
    variable = failure
  [../]
  [./failure_41]
    type = PointValue
    point = '1.0 24.9 1.0'
    variable = failure
  [../]
  [./failure_42]
    type = PointValue
    point = '1.0 25.5 1.0'
    variable = failure
  [../]
  [./failure_43]
    type = PointValue
    point = '1.0 26.1 1.0'
    variable = failure
  [../]
  [./failure_44]
    type = PointValue
    point = '1.0 26.7 1.0'
    variable = failure
  [../]
  [./failure_45]
    type = PointValue
    point = '1.0 27.3 1.0'
    variable = failure
  [../]
  [./failure_46]
    type = PointValue
    point = '1.0 27.9 1.0'
    variable = failure
  [../]
  [./failure_47]
    type = PointValue
    point = '1.0 28.5 1.0'
    variable = failure
  [../]
  [./failure_48]
    type = PointValue
    point = '1.0 29.1 1.0'
    variable = failure
  [../]
  [./failure_49]
    type = PointValue
    point = '1.0 29.7 1.0'
    variable = failure
  [../]
  [./failure_50]
    type = PointValue
    point = '1.0 30.3 1.0'
    variable = failure
  [../]
  [./failure_51]
    type = PointValue
    point = '1.0 30.9 1.0'
    variable = failure
  [../]
  [./failure_52]
    type = PointValue
    point = '1.0 31.5 1.0'
    variable = failure
  [../]
  [./failure_53]
    type = PointValue
    point = '1.0 32.1 1.0'
    variable = failure
  [../]
  [./failure_54]
    type = PointValue
    point = '1.0 32.7 1.0'
    variable = failure
  [../]
  [./failure_55]
    type = PointValue
    point = '1.0 33.3 1.0'
    variable = failure
  [../]
  [./failure_56]
    type = PointValue
    point = '1.0 33.9 1.0'
    variable = failure
  [../]
  [./failure_57]
    type = PointValue
    point = '1.0 34.5 1.0'
    variable = failure
  [../]
  [./failure_58]
    type = PointValue
    point = '1.0 35.1 1.0'
    variable = failure
  [../]
  [./failure_59]
    type = PointValue
    point = '1.0 35.7 1.0'
    variable = failure
  [../]
  [./failure_60]
    type = PointValue
    point = '1.0 36.3 1.0'
    variable = failure
  [../]
  [./failure_61]
    type = PointValue
    point = '1.0 36.9 1.0'
    variable = failure
  [../]
  [./failure_62]
    type = PointValue
    point = '1.0 37.5 1.0'
    variable = failure
  [../]
  [./failure_63]
    type = PointValue
    point = '1.0 38.1 1.0'
    variable = failure
  [../]
  [./failure_64]
    type = PointValue
    point = '1.0 38.7 1.0'
    variable = failure
  [../]
  [./failure_65]
    type = PointValue
    point = '1.0 39.3 1.0'
    variable = failure
  [../]
  [./failure_66]
    type = PointValue
    point = '1.0 39.9 1.0'
    variable = failure
  [../]
  [./failure_67]
    type = PointValue
    point = '1.0 40.5 1.0'
    variable = failure
  [../]
  [./failure_68]
    type = PointValue
    point = '1.0 41.1 1.0'
    variable = failure
  [../]
  [./failure_69]
    type = PointValue
    point = '1.0 41.7 1.0'
    variable = failure
  [../]
  [./failure_70]
    type = PointValue
    point = '1.0 42.3 1.0'
    variable = failure
  [../]
  [./failure_71]
    type = PointValue
    point = '1.0 42.9 1.0'
    variable = failure
  [../]
  [./failure_72]
    type = PointValue
    point = '1.0 43.5 1.0'
    variable = failure
  [../]
  [./failure_73]
    type = PointValue
    point = '1.0 44.1 1.0'
    variable = failure
  [../]
  [./failure_74]
    type = PointValue
    point = '1.0 44.7 1.0'
    variable = failure
  [../]
  [./failure_75]
    type = PointValue
    point = '1.0 45.3 1.0'
    variable = failure
  [../]
  [./failure_76]
    type = PointValue
    point = '1.0 45.9 1.0'
    variable = failure
  [../]
  [./failure_77]
    type = PointValue
    point = '1.0 46.5 1.0'
    variable = failure
  [../]
  [./failure_78]
    type = PointValue
    point = '1.0 47.1 1.0'
    variable = failure
  [../]
  [./failure_79]
    type = PointValue
    point = '1.0 47.7 1.0'
    variable = failure
  [../]
  [./failure_80]
    type = PointValue
    point = '1.0 48.3 1.0'
    variable = failure
  [../]
  [./failure_81]
    type = PointValue
    point = '1.0 48.9 1.0'
    variable = failure
  [../]
  [./failure_82]
    type = PointValue
    point = '1.0 49.5 1.0'
    variable = failure
  [../]
  [./failure_83]
    type = PointValue
    point = '1.0 50.1 1.0'
    variable = failure
  [../]
  [./failure_84]
    type = PointValue
    point = '1.0 50.7 1.0'
    variable = failure
  [../]
  [./failure_85]
    type = PointValue
    point = '1.0 51.3 1.0'
    variable = failure
  [../]
  [./failure_86]
    type = PointValue
    point = '1.0 51.9 1.0'
    variable = failure
  [../]
  [./failure_87]
    type = PointValue
    point = '1.0 52.5 1.0'
    variable = failure
  [../]
  [./failure_88]
    type = PointValue
    point = '1.0 53.1 1.0'
    variable = failure
  [../]
  [./failure_89]
    type = PointValue
    point = '1.0 53.7 1.0'
    variable = failure
  [../]
  [./failure_90]
    type = PointValue
    point = '1.0 54.3 1.0'
    variable = failure
  [../]
  [./failure_91]
    type = PointValue
    point = '1.0 54.9 1.0'
    variable = failure
  [../]
  [./failure_92]
    type = PointValue
    point = '1.0 55.5 1.0'
    variable = failure
  [../]
  [./failure_93]
    type = PointValue
    point = '1.0 56.1 1.0'
    variable = failure
  [../]
  [./failure_94]
    type = PointValue
    point = '1.0 56.7 1.0'
    variable = failure
  [../]
  [./failure_95]
    type = PointValue
    point = '1.0 57.3 1.0'
    variable = failure
  [../]
  [./failure_96]
    type = PointValue
    point = '1.0 57.9 1.0'
    variable = failure
  [../]
  [./failure_97]
    type = PointValue
    point = '1.0 58.5 1.0'
    variable = failure
  [../]
  [./failure_98]
    type = PointValue
    point = '1.0 59.1 1.0'
    variable = failure
  [../]
  [./failure_99]
    type = PointValue
    point = '1.0 59.7 1.0'
    variable = failure
  [../]
  [./failure_100]
    type = PointValue
    point = '1.0 60.3 1.0'
    variable = failure
  [../]
  [./failure_101]
    type = PointValue
    point = '1.0 60.9 1.0'
    variable = failure
  [../]
  [./failure_102]
    type = PointValue
    point = '1.0 61.5 1.0'
    variable = failure
  [../]
  [./failure_103]
    type = PointValue
    point = '1.0 62.1 1.0'
    variable = failure
  [../]
  [./failure_104]
    type = PointValue
    point = '1.0 62.7 1.0'
    variable = failure
  [../]
  [./failure_105]
    type = PointValue
    point = '1.0 63.3 1.0'
    variable = failure
  [../]
  [./failure_106]
    type = PointValue
    point = '1.0 63.9 1.0'
    variable = failure
  [../]
  [./failure_107]
    type = PointValue
    point = '1.0 64.5 1.0'
    variable = failure
  [../]
  [./failure_108]
    type = PointValue
    point = '1.0 65.1 1.0'
    variable = failure
  [../]
  [./failure_109]
    type = PointValue
    point = '1.0 65.7 1.0'
    variable = failure
  [../]
  [./failure_110]
    type = PointValue
    point = '1.0 66.3 1.0'
    variable = failure
  [../]
  [./failure_111]
    type = PointValue
    point = '1.0 66.9 1.0'
    variable = failure
  [../]
  [./failure_112]
    type = PointValue
    point = '1.0 67.5 1.0'
    variable = failure
  [../]
  [./failure_113]
    type = PointValue
    point = '1.0 68.1 1.0'
    variable = failure
  [../]
  [./failure_114]
    type = PointValue
    point = '1.0 68.7 1.0'
    variable = failure
  [../]
  [./failure_115]
    type = PointValue
    point = '1.0 69.3 1.0'
    variable = failure
  [../]
  [./failure_116]
    type = PointValue
    point = '1.0 69.9 1.0'
    variable = failure
  [../]
  [./failure_117]
    type = PointValue
    point = '1.0 70.5 1.0'
    variable = failure
  [../]
  [./failure_118]
    type = PointValue
    point = '1.0 71.1 1.0'
    variable = failure
  [../]
  [./failure_119]
    type = PointValue
    point = '1.0 71.7 1.0'
    variable = failure
  [../]
  [./failure_120]
    type = PointValue
    point = '1.0 72.3 1.0'
    variable = failure
  [../]
  [./failure_121]
    type = PointValue
    point = '1.0 72.9 1.0'
    variable = failure
  [../]
  [./failure_122]
    type = PointValue
    point = '1.0 73.5 1.0'
    variable = failure
  [../]
  [./failure_123]
    type = PointValue
    point = '1.0 74.1 1.0'
    variable = failure
  [../]
  [./failure_124]
    type = PointValue
    point = '1.0 74.7 1.0'
    variable = failure
  [../]
  [./failure_125]
    type = PointValue
    point = '1.0 75.3 1.0'
    variable = failure
  [../]
  [./failure_126]
    type = PointValue
    point = '1.0 75.9 1.0'
    variable = failure
  [../]
  [./failure_127]
    type = PointValue
    point = '1.0 76.5 1.0'
    variable = failure
  [../]
  [./failure_128]
    type = PointValue
    point = '1.0 77.1 1.0'
    variable = failure
  [../]
  [./failure_129]
    type = PointValue
    point = '1.0 77.7 1.0'
    variable = failure
  [../]
  [./failure_130]
    type = PointValue
    point = '1.0 78.3 1.0'
    variable = failure
  [../]
  [./failure_131]
    type = PointValue
    point = '1.0 78.9 1.0'
    variable = failure
  [../]
  [./failure_132]
    type = PointValue
    point = '1.0 79.5 1.0'
    variable = failure
  [../]
  [./failure_133]
    type = PointValue
    point = '1.0 80.1 1.0'
    variable = failure
  [../]
  [./failure_134]
    type = PointValue
    point = '1.0 80.7 1.0'
    variable = failure
  [../]
  [./failure_135]
    type = PointValue
    point = '1.0 81.3 1.0'
    variable = failure
  [../]
  [./failure_136]
    type = PointValue
    point = '1.0 81.9 1.0'
    variable = failure
  [../]
  [./failure_137]
    type = PointValue
    point = '1.0 82.5 1.0'
    variable = failure
  [../]
  [./failure_138]
    type = PointValue
    point = '1.0 83.1 1.0'
    variable = failure
  [../]
  [./failure_139]
    type = PointValue
    point = '1.0 83.7 1.0'
    variable = failure
  [../]
  [./failure_140]
    type = PointValue
    point = '1.0 84.3 1.0'
    variable = failure
  [../]
  [./failure_141]
    type = PointValue
    point = '1.0 84.9 1.0'
    variable = failure
  [../]
  [./failure_142]
    type = PointValue
    point = '1.0 85.5 1.0'
    variable = failure
  [../]
  [./failure_143]
    type = PointValue
    point = '1.0 86.1 1.0'
    variable = failure
  [../]
  [./failure_144]
    type = PointValue
    point = '1.0 86.7 1.0'
    variable = failure
  [../]
  [./failure_145]
    type = PointValue
    point = '1.0 87.3 1.0'
    variable = failure
  [../]
  [./failure_146]
    type = PointValue
    point = '1.0 87.9 1.0'
    variable = failure
  [../]
  [./failure_147]
    type = PointValue
    point = '1.0 88.5 1.0'
    variable = failure
  [../]
  [./failure_148]
    type = PointValue
    point = '1.0 89.1 1.0'
    variable = failure
  [../]
  [./failure_149]
    type = PointValue
    point = '1.0 89.7 1.0'
    variable = failure
  [../]
  [./failure_150]
    type = PointValue
    point = '1.0 90.3 1.0'
    variable = failure
  [../]
  [./failure_151]
    type = PointValue
    point = '1.0 90.9 1.0'
    variable = failure
  [../]
  [./failure_152]
    type = PointValue
    point = '1.0 91.5 1.0'
    variable = failure
  [../]
  [./failure_153]
    type = PointValue
    point = '1.0 92.1 1.0'
    variable = failure
  [../]
  [./failure_154]
    type = PointValue
    point = '1.0 92.7 1.0'
    variable = failure
  [../]
  [./failure_155]
    type = PointValue
    point = '1.0 93.3 1.0'
    variable = failure
  [../]
  [./failure_156]
    type = PointValue
    point = '1.0 93.9 1.0'
    variable = failure
  [../]
  [./failure_157]
    type = PointValue
    point = '1.0 94.5 1.0'
    variable = failure
  [../]
  [./failure_158]
    type = PointValue
    point = '1.0 95.1 1.0'
    variable = failure
  [../]
  [./failure_159]
    type = PointValue
    point = '1.0 95.7 1.0'
    variable = failure
  [../]
  [./failure_160]
    type = PointValue
    point = '1.0 96.3 1.0'
    variable = failure
  [../]
  [./failure_161]
    type = PointValue
    point = '1.0 96.9 1.0'
    variable = failure
  [../]
  [./failure_162]
    type = PointValue
    point = '1.0 97.5 1.0'
    variable = failure
  [../]
  [./failure_163]
    type = PointValue
    point = '1.0 98.1 1.0'
    variable = failure
  [../]
  [./failure_164]
    type = PointValue
    point = '1.0 98.7 1.0'
    variable = failure
  [../]
  [./failure_165]
    type = PointValue
    point = '1.0 99.3 1.0'
    variable = failure
  [../]
  [./failure_166]
    type = PointValue
    point = '1.0 99.9 1.0'
    variable = failure
  [../]
  [./failure_167]
    type = PointValue
    point = '1.0 100.5 1.0'
    variable = failure
  [../]
  [./failure_168]
    type = PointValue
    point = '1.0 101.1 1.0'
    variable = failure
  [../]
  [./failure_169]
    type = PointValue
    point = '1.0 101.7 1.0'
    variable = failure
  [../]
  [./failure_170]
    type = PointValue
    point = '1.0 102.3 1.0'
    variable = failure
  [../]
  [./failure_171]
    type = PointValue
    point = '1.0 102.9 1.0'
    variable = failure
  [../]
  [./failure_172]
    type = PointValue
    point = '1.0 103.5 1.0'
    variable = failure
  [../]
  [./failure_173]
    type = PointValue
    point = '1.0 104.1 1.0'
    variable = failure
  [../]
  [./failure_174]
    type = PointValue
    point = '1.0 104.7 1.0'
    variable = failure
  [../]
  [./failure_175]
    type = PointValue
    point = '1.0 105.3 1.0'
    variable = failure
  [../]
  [./failure_176]
    type = PointValue
    point = '1.0 105.9 1.0'
    variable = failure
  [../]
  [./failure_177]
    type = PointValue
    point = '1.0 106.5 1.0'
    variable = failure
  [../]
  [./failure_178]
    type = PointValue
    point = '1.0 107.1 1.0'
    variable = failure
  [../]
  [./failure_179]
    type = PointValue
    point = '1.0 107.7 1.0'
    variable = failure
  [../]
  [./failure_180]
    type = PointValue
    point = '1.0 108.3 1.0'
    variable = failure
  [../]
  [./failure_181]
    type = PointValue
    point = '1.0 108.9 1.0'
    variable = failure
  [../]
  [./failure_182]
    type = PointValue
    point = '1.0 109.5 1.0'
    variable = failure
  [../]
  [./failure_183]
    type = PointValue
    point = '1.0 110.1 1.0'
    variable = failure
  [../]
  [./failure_184]
    type = PointValue
    point = '1.0 110.7 1.0'
    variable = failure
  [../]
  [./failure_185]
    type = PointValue
    point = '1.0 111.3 1.0'
    variable = failure
  [../]
  [./failure_186]
    type = PointValue
    point = '1.0 111.9 1.0'
    variable = failure
  [../]
  [./failure_187]
    type = PointValue
    point = '1.0 112.5 1.0'
    variable = failure
  [../]
  [./failure_188]
    type = PointValue
    point = '1.0 113.1 1.0'
    variable = failure
  [../]
  [./failure_189]
    type = PointValue
    point = '1.0 113.7 1.0'
    variable = failure
  [../]
  [./failure_190]
    type = PointValue
    point = '1.0 114.3 1.0'
    variable = failure
  [../]
  [./failure_191]
    type = PointValue
    point = '1.0 114.9 1.0'
    variable = failure
  [../]
  [./failure_192]
    type = PointValue
    point = '1.0 115.5 1.0'
    variable = failure
  [../]
  [./failure_193]
    type = PointValue
    point = '1.0 116.1 1.0'
    variable = failure
  [../]
  [./failure_194]
    type = PointValue
    point = '1.0 116.7 1.0'
    variable = failure
  [../]
  [./failure_195]
    type = PointValue
    point = '1.0 117.3 1.0'
    variable = failure
  [../]
  [./failure_196]
    type = PointValue
    point = '1.0 117.9 1.0'
    variable = failure
  [../]
  [./failure_197]
    type = PointValue
    point = '1.0 118.5 1.0'
    variable = failure
  [../]
  [./failure_198]
    type = PointValue
    point = '1.0 119.1 1.0'
    variable = failure
  [../]
  [./failure_199]
    type = PointValue
    point = '1.0 119.7 1.0'
    variable = failure
  [../]
  [./disp_y_top]
    type = SideAverageValue
    variable = disp_y
	execute_on = linear
    boundary = top
  [../]
  [./wc_z_top]
    type = PointValue
    point = '120 120 120'
    variable = wc_z
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
  [./disp_x_bottom]
    type = PointValue
    variable = disp_x
    point = '120 0 120'
  [../]
  [./dt]
    type = TimestepSize
  [../]
[]

[Variables]
  [./disp_x]
    block = '1 2 3'
  [../]
  [./disp_y]
    block = '1 2 3'
  [../]
  [./disp_z]
    block = '1 2 3'
  [../]
  [./wc_x]
    block = '1 2 3'
  [../]
  [./wc_y]
    block = '1 2 3'
  [../]
  [./wc_z]
    block = '1 2 3'
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
  active = 'Periodic uy_bottom ux_ramp_top wcx_equals_zero_on_top ux_zero_bottom wcy_equals_zero_on_top wc_x_bottom uz_bottom wc_y_bottom'
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
      translation = '120 0 0'
      secondary = right_top
      primary = left_top
    [../]
    [./z_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z'
      translation = '0 0 -120'
      secondary = back
      primary = front
    [../]
    [./x_direction_2]
      translation = '120 0 0'
      secondary = right_bot
      primary = left_bot
    [../]
    [./x_direction_3]
      translation = '118 0 0'
      secondary = right_mid
      primary = left_mid
    [../]
	[./y_direction]
      variable = 'wc_z'
      translation = '0 -120 0'
      secondary = bottom
      primary = top
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
    block = '1 2 3'
    B_ijkl = '0 9.8E4 9.8E4'
    C_ijkl = '1.3333E3 4.0E3 2.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 100
    hardening_mech_modulus = -6
    friction_coefficient = 0.0
    min_stepsize = 1e-8
    plasticity_type = DeBorst_2D
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = '1 2 3'
  [../]
[]

[Preconditioning]
  active = 'andy'
  [./andy]
    type = SMP
    full = true
    petsc_options_iname = '-ksp_type -pc_type    -snes_atol -snes_rtol -snes_max_it -ksp_atol -ksp_rtol'
    petsc_options_value = 'gmres          bjacobi     1E-5        1E-8      40      1E-12      1E-10 '
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
  dt = 0.5
  solve_type = NEWTON
  num_steps = 2000
  nl_abs_tol = 1e-8
  l_tol = 1e-10
  nl_rel_tol = 1e-04
[]

[Outputs]
  execute_on = 'timestep_end initial'
  exodus = true
  file_base = plastic_shear_R25_Hs600_h120_not1_mom 
  print_linear_residuals = false
[]

