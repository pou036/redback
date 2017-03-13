[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 200
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
  active = 'lagrange_110 lagrange_111 lagrange_112 lagrange_113 lagrange_114 lagrange_115 lagrange_116 disp_x_187 lagrange_118 lagrange_119 strain_xy_199 strain_xy_197 wc_z_145 wc_z_144 wc_z_147 wc_z_146 wc_z_141 wc_z_140 wc_z_143 wc_z_142 strain_xy_191 wc_z_149 wc_z_148 strain_xy_190 disp_x_107 disp_x_106 disp_x_105 disp_x_104 disp_x_103 disp_x_102 disp_x_101 disp_x_100 lagrange_58 lagrange_59 disp_x_163 disp_x_109 disp_x_108 disp_x_162 lagrange_132 disp_x_29 disp_x_28 disp_x_23 disp_x_22 disp_x_21 disp_x_20 disp_x_27 disp_x_26 disp_x_25 disp_x_24 disp_x_169 lagrange_133 strain_xy_108 disp_x_168 strain_xy_106 strain_xy_107 strain_xy_104 strain_xy_105 strain_xy_102 strain_xy_103 lagrange_65 strain_xy_101 wc_z_130 wc_z_131 wc_z_132 wc_z_133 wc_z_134 wc_z_135 wc_z_136 wc_z_137 wc_z_138 wc_z_139 disp_x_172 disp_x_173 disp_x_170 disp_x_171 wc_z_69 wc_z_68 disp_x_98 disp_x_99 wc_z_65 wc_z_64 wc_z_67 wc_z_66 disp_x_92 wc_z_60 wc_z_63 disp_x_91 lagrange_60 lagrange_67 lagrange_66 wc_z_87 wc_z_86 wc_z_85 wc_z_84 wc_z_83 wc_z_82 wc_z_81 wc_z_80 strain_xy_192 lagrange_64 wc_z_89 wc_z_88 strain_xy_24 strain_xy_25 strain_xy_26 strain_xy_27 strain_xy_20 strain_xy_21 strain_xy_22 strain_xy_23 strain_xy_28 strain_xy_29 lagrange_81 lagrange_52 lagrange_83 lagrange_82 lagrange_85 lagrange_84 lagrange_87 lagrange_53 lagrange_89 lagrange_88 lagrange_50 strain_xy_1 strain_xy_0 strain_xy_3 lagrange_51 strain_xy_5 strain_xy_4 strain_xy_7 strain_xy_6 strain_xy_9 lagrange_56 lagrange_57 disp_x_49 lagrange_54 wc_z_95 lagrange_55 wc_z_93 lagrange_18 lagrange_19 lagrange_16 lagrange_17 lagrange_14 lagrange_15 lagrange_12 lagrange_13 lagrange_10 lagrange_11 disp_x_45 disp_x_44 lagrange_149 lagrange_148 lagrange_147 lagrange_146 lagrange_145 lagrange_144 lagrange_143 lagrange_142 lagrange_141 lagrange_140 strain_xy_142 strain_xy_143 strain_xy_140 strain_xy_141 wc_z_178 wc_z_179 strain_xy_144 strain_xy_145 wc_z_174 wc_z_175 wc_z_176 wc_z_177 wc_z_170 wc_z_171 wc_z_172 wc_z_173 lagrange_69 lagrange_68 disp_x_138 disp_x_139 disp_x_136 disp_x_137 disp_x_134 disp_x_135 disp_x_132 disp_x_133 disp_x_130 disp_x_131 wc_z_7 lagrange_157 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 strain_xy_68 strain_xy_69 strain_xy_60 strain_xy_61 strain_xy_62 strain_xy_63 strain_xy_64 strain_xy_65 strain_xy_66 strain_xy_67 wc_z_36 wc_z_37 wc_z_34 wc_z_35 wc_z_32 wc_z_33 wc_z_30 wc_z_31 wc_z_38 wc_z_39 strain_xy_31 strain_xy_30 wc_z_195 strain_xy_39 strain_xy_38 strain_xy_193 strain_xy_109 disp_x_177 lagrange_91 lagrange_154 strain_xy_100 lagrange_155 strain_xy_149 lagrange_156 lagrange_103 lagrange_102 lagrange_101 lagrange_100 lagrange_107 lagrange_106 lagrange_105 lagrange_104 lagrange_150 lagrange_109 lagrange_108 strain_xy_53 strain_xy_188 lagrange_151 normal_force lagrange_70 lagrange_152 strain_xy_55 strain_xy_32 lagrange_153 strain_xy_54 lagrange_27 lagrange_26 lagrange_25 lagrange_24 lagrange_23 lagrange_22 lagrange_21 lagrange_20 lagrange_190 lagrange_191 lagrange_192 lagrange_193 lagrange_194 lagrange_195 lagrange_29 lagrange_28 lagrange_71 strain_xy_58 strain_xy_168 disp_x_38 disp_x_39 strain_xy_169 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_30 disp_x_31 disp_x_32 disp_x_33 strain_xy_159 strain_xy_139 strain_xy_138 strain_xy_158 strain_xy_133 strain_xy_132 strain_xy_131 strain_xy_130 strain_xy_137 strain_xy_136 strain_xy_135 lagrange_160 wc_z_123 wc_z_122 wc_z_121 wc_z_120 wc_z_127 wc_z_126 wc_z_125 wc_z_124 wc_z_129 wc_z_128 lagrange_73 disp_x_161 disp_x_160 wc_z_78 wc_z_79 disp_x_165 disp_x_164 disp_x_167 disp_x_166 wc_z_72 wc_z_73 wc_z_70 wc_z_71 wc_z_76 wc_z_77 wc_z_74 wc_z_75 strain_xy_88 strain_xy_89 disp_x_174 strain_xy_2 strain_xy_82 strain_xy_83 strain_xy_80 disp_x_175 strain_xy_86 strain_xy_87 strain_xy_84 strain_xy_85 wc_z_94 disp_x_48 wc_z_96 wc_z_97 wc_z_90 wc_z_91 wc_z_92 disp_x_97 disp_x_41 disp_x_40 disp_x_43 disp_x_42 wc_z_98 wc_z_99 disp_x_47 disp_x_46 disp_x_95 wc_z_8 wc_z_9 wc_z_6 wc_z_61 wc_z_4 wc_z_5 wc_z_2 wc_z_3 wc_z_0 wc_z_1 strain_xy_37 strain_xy_36 strain_xy_35 strain_xy_34 strain_xy_33 disp_x_90 wc_z_198 wc_z_199 wc_z_196 wc_z_197 wc_z_194 wc_z_62 wc_z_192 wc_z_193 wc_z_190 wc_z_191 lagrange_96 lagrange_97 lagrange_94 lagrange_95 lagrange_92 lagrange_93 lagrange_90 lagrange_76 lagrange_98 lagrange_99 lagrange_77 strain_xy_164 lagrange_49 strain_xy_151 lagrange_48 lagrange_45 lagrange_44 wc_z_top strain_xy_150 strain_xy_163 lagrange_178 lagrange_179 strain_xy_179 strain_xy_178 lagrange_172 lagrange_173 lagrange_170 lagrange_171 lagrange_176 lagrange_177 lagrange_174 lagrange_175 strain_xy_146 wc_z_169 wc_z_168 wc_z_167 wc_z_166 wc_z_165 wc_z_164 wc_z_163 wc_z_162 wc_z_161 wc_z_160 lagrange_78 lagrange_79 disp_x_8 disp_x_9 disp_x_125 disp_x_124 disp_x_6 disp_x_126 disp_x_121 disp_x_120 disp_x_123 disp_x_122 strain_xy_165 lagrange_189 lagrange_188 strain_xy_79 strain_xy_78 strain_xy_73 strain_xy_72 strain_xy_71 strain_xy_70 strain_xy_77 strain_xy_76 strain_xy_75 strain_xy_74 wc_z_43 wc_z_42 wc_z_41 wc_z_40 wc_z_47 wc_z_46 wc_z_45 wc_z_44 disp_x_190 disp_x_191 wc_z_49 wc_z_48 disp_x_194 disp_x_195 disp_x_196 disp_x_197 lagrange_180 strain_xy_176 lagrange_187 disp_x_68 strain_xy_51 lagrange_186 dt strain_xy_196 lagrange_8 lagrange_9 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_0 lagrange_1 lagrange_2 lagrange_3 disp_x_2 wc_z_200 disp_x_96 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_183 lagrange_182 lagrange_181 lagrange_86 lagrange_38 lagrange_39 lagrange_185 lagrange_184 strain_xy_113 strain_xy_112 lagrange_63 wc_z_18 wc_z_19 wc_z_14 wc_z_15 wc_z_16 wc_z_17 wc_z_10 wc_z_11 wc_z_12 wc_z_13 strain_xy_124 strain_xy_125 strain_xy_126 strain_xy_127 strain_xy_120 disp_x_94 strain_xy_122 strain_xy_123 strain_xy_128 strain_xy_129 lagrange_62 wc_z_116 wc_z_117 wc_z_114 wc_z_115 wc_z_112 wc_z_113 wc_z_110 wc_z_111 wc_z_118 wc_z_119 disp_x_154 disp_x_155 disp_x_156 disp_x_157 disp_x_150 disp_x_151 disp_x_152 disp_x_153 lagrange_136 lagrange_137 lagrange_134 lagrange_135 disp_x_158 disp_x_159 lagrange_130 lagrange_131 strain_xy_95 strain_xy_94 strain_xy_97 strain_xy_96 strain_xy_91 strain_xy_90 strain_xy_93 strain_xy_92 strain_xy_99 strain_xy_98 disp_x_58 disp_x_59 strain_xy_8 disp_x_52 disp_x_53 disp_x_50 disp_x_51 disp_x_56 disp_x_57 disp_x_54 disp_x_55 disp_x_176 disp_x_93 wc_z_181 wc_z_180 wc_z_183 wc_z_182 wc_z_185 wc_z_184 wc_z_187 wc_z_186 wc_z_189 disp_x_89 strain_xy_175 disp_x_88 strain_xy_174 disp_x_189 strain_xy_173 disp_x_188 strain_xy_172 disp_x_85 strain_xy_171 disp_x_84 strain_xy_170 disp_x_185 disp_x_184 disp_x_186 disp_x_183 disp_x_182 disp_x_181 disp_x_180 disp_x_200 strain_xy_186 strain_xy_187 strain_xy_184 strain_xy_119 strain_xy_177 strain_xy_185 strain_xy_182 strain_xy_183 strain_xy_180 disp_x_178 strain_xy_181 strain_xy_118 lagrange_72 lagrange_165 lagrange_164 lagrange_167 lagrange_166 lagrange_161 lagrange_138 lagrange_163 lagrange_162 strain_xy_160 strain_xy_161 strain_xy_162 lagrange_139 lagrange_169 lagrange_168 strain_xy_166 strain_xy_167 wc_z_152 wc_z_153 wc_z_150 wc_z_151 wc_z_156 wc_z_157 wc_z_154 wc_z_155 disp_x_129 wc_z_158 wc_z_159 disp_x_128 disp_x_110 disp_x_111 disp_x_112 disp_x_113 disp_x_114 disp_x_115 disp_x_116 disp_x_117 disp_x_118 disp_x_119 lagrange_47 lagrange_46 lagrange_41 lagrange_40 lagrange_43 lagrange_42 disp_x_4 disp_x_179 disp_x_5 disp_x_127 disp_x_7 lagrange_61 disp_x_0 disp_x_1 disp_x_16 disp_x_17 disp_x_14 disp_x_15 disp_x_12 disp_x_13 disp_x_10 disp_x_11 strain_xy_115 strain_xy_114 strain_xy_117 disp_x_3 strain_xy_111 strain_xy_110 disp_x_18 disp_x_19 strain_xy_46 strain_xy_47 strain_xy_44 strain_xy_45 strain_xy_42 strain_xy_43 strain_xy_40 strain_xy_41 lagrange_80 strain_xy_48 strain_xy_49 wc_z_50 wc_z_51 wc_z_52 wc_z_53 wc_z_54 wc_z_55 wc_z_56 wc_z_57 wc_z_58 wc_z_59 disp_x_87 disp_x_86 disp_x_81 disp_x_80 disp_x_83 disp_x_82 lagrange_198 disp_y_top lagrange_199 number_nonlin strain_xy_116 strain_xy_121 number_lin strain_xy_198 strain_xy_81 lagrange_196 lagrange_197 lagrange_74 wc_z_29 wc_z_28 lagrange_158 lagrange_159 wc_z_21 wc_z_20 wc_z_23 wc_z_22 wc_z_25 wc_z_24 wc_z_27 wc_z_26 wc_z_109 wc_z_108 strain_xy_153 strain_xy_152 strain_xy_155 strain_xy_154 strain_xy_157 strain_xy_156 wc_z_101 wc_z_100 wc_z_103 wc_z_102 wc_z_105 wc_z_104 wc_z_107 wc_z_106 disp_x_149 disp_x_148 strain_xy_50 disp_x_143 disp_x_142 disp_x_141 disp_x_140 disp_x_147 disp_x_146 disp_x_145 disp_x_144 lagrange_129 lagrange_128 lagrange_121 lagrange_120 lagrange_123 lagrange_122 lagrange_125 lagrange_124 lagrange_127 lagrange_126 strain_xy_189 lagrange_117 disp_x_69 wc_z_188 disp_x_67 disp_x_66 disp_x_65 disp_x_64 disp_x_63 disp_x_62 disp_x_61 disp_x_60 strain_xy_148 strain_xy_52 strain_xy_19 strain_xy_18 strain_xy_15 strain_xy_14 strain_xy_17 strain_xy_16 strain_xy_11 strain_xy_10 strain_xy_13 strain_xy_12 lagrange_75 tangential_force disp_x_198 disp_x_199 strain_xy_134 strain_xy_57 strain_xy_195 disp_x_bottom strain_xy_56 disp_x_192 disp_x_193 strain_xy_194 strain_xy_59 strain_xy_147 tau gamma_p'
  [./wc_z_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_1]
    type = PointValue
    point = '0.0 0.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_2]
    type = PointValue
    point = '0.0 0.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_3]
    type = PointValue
    point = '0.0 0.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_4]
    type = PointValue
    point = '0.0 1.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_5]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_6]
    type = PointValue
    point = '0.0 1.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_7]
    type = PointValue
    point = '0.0 2.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_8]
    type = PointValue
    point = '0.0 2.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_9]
    type = PointValue
    point = '0.0 2.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_10]
    type = PointValue
    point = '0.0 3.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_11]
    type = PointValue
    point = '0.0 3.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_12]
    type = PointValue
    point = '0.0 3.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_13]
    type = PointValue
    point = '0.0 3.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_14]
    type = PointValue
    point = '0.0 4.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_15]
    type = PointValue
    point = '0.0 4.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_16]
    type = PointValue
    point = '0.0 4.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_17]
    type = PointValue
    point = '0.0 5.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_18]
    type = PointValue
    point = '0.0 5.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_19]
    type = PointValue
    point = '0.0 5.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_20]
    type = PointValue
    point = '0.0 6.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_21]
    type = PointValue
    point = '0.0 6.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_22]
    type = PointValue
    point = '0.0 6.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_23]
    type = PointValue
    point = '0.0 6.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_24]
    type = PointValue
    point = '0.0 7.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_25]
    type = PointValue
    point = '0.0 7.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_26]
    type = PointValue
    point = '0.0 7.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_27]
    type = PointValue
    point = '0.0 8.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_28]
    type = PointValue
    point = '0.0 8.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_29]
    type = PointValue
    point = '0.0 8.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_30]
    type = PointValue
    point = '0.0 9.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_31]
    type = PointValue
    point = '0.0 9.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_32]
    type = PointValue
    point = '0.0 9.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_33]
    type = PointValue
    point = '0.0 9.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_34]
    type = PointValue
    point = '0.0 10.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_35]
    type = PointValue
    point = '0.0 10.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_36]
    type = PointValue
    point = '0.0 10.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_37]
    type = PointValue
    point = '0.0 11.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_38]
    type = PointValue
    point = '0.0 11.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_39]
    type = PointValue
    point = '0.0 11.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_40]
    type = PointValue
    point = '0.0 12.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_41]
    type = PointValue
    point = '0.0 12.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_42]
    type = PointValue
    point = '0.0 12.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_43]
    type = PointValue
    point = '0.0 12.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_44]
    type = PointValue
    point = '0.0 13.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_45]
    type = PointValue
    point = '0.0 13.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_46]
    type = PointValue
    point = '0.0 13.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_47]
    type = PointValue
    point = '0.0 14.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_48]
    type = PointValue
    point = '0.0 14.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_49]
    type = PointValue
    point = '0.0 14.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_50]
    type = PointValue
    point = '0.0 15.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_51]
    type = PointValue
    point = '0.0 15.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_52]
    type = PointValue
    point = '0.0 15.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_53]
    type = PointValue
    point = '0.0 15.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_54]
    type = PointValue
    point = '0.0 16.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_55]
    type = PointValue
    point = '0.0 16.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_56]
    type = PointValue
    point = '0.0 16.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_57]
    type = PointValue
    point = '0.0 17.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_58]
    type = PointValue
    point = '0.0 17.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_59]
    type = PointValue
    point = '0.0 17.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_60]
    type = PointValue
    point = '0.0 18.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_61]
    type = PointValue
    point = '0.0 18.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_62]
    type = PointValue
    point = '0.0 18.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_63]
    type = PointValue
    point = '0.0 18.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_64]
    type = PointValue
    point = '0.0 19.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_65]
    type = PointValue
    point = '0.0 19.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_66]
    type = PointValue
    point = '0.0 19.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_67]
    type = PointValue
    point = '0.0 20.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_68]
    type = PointValue
    point = '0.0 20.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_69]
    type = PointValue
    point = '0.0 20.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_70]
    type = PointValue
    point = '0.0 21.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_71]
    type = PointValue
    point = '0.0 21.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_72]
    type = PointValue
    point = '0.0 21.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_73]
    type = PointValue
    point = '0.0 21.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_74]
    type = PointValue
    point = '0.0 22.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_75]
    type = PointValue
    point = '0.0 22.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_76]
    type = PointValue
    point = '0.0 22.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_77]
    type = PointValue
    point = '0.0 23.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_78]
    type = PointValue
    point = '0.0 23.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_79]
    type = PointValue
    point = '0.0 23.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_80]
    type = PointValue
    point = '0.0 24.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_81]
    type = PointValue
    point = '0.0 24.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_82]
    type = PointValue
    point = '0.0 24.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_83]
    type = PointValue
    point = '0.0 24.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_84]
    type = PointValue
    point = '0.0 25.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_85]
    type = PointValue
    point = '0.0 25.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_86]
    type = PointValue
    point = '0.0 25.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_87]
    type = PointValue
    point = '0.0 26.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_88]
    type = PointValue
    point = '0.0 26.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_89]
    type = PointValue
    point = '0.0 26.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_90]
    type = PointValue
    point = '0.0 27.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_91]
    type = PointValue
    point = '0.0 27.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_92]
    type = PointValue
    point = '0.0 27.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_93]
    type = PointValue
    point = '0.0 27.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_94]
    type = PointValue
    point = '0.0 28.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_95]
    type = PointValue
    point = '0.0 28.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_96]
    type = PointValue
    point = '0.0 28.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_97]
    type = PointValue
    point = '0.0 29.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_98]
    type = PointValue
    point = '0.0 29.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_99]
    type = PointValue
    point = '0.0 29.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_100]
    type = PointValue
    point = '0.0 30.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_101]
    type = PointValue
    point = '0.0 30.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_102]
    type = PointValue
    point = '0.0 30.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_103]
    type = PointValue
    point = '0.0 30.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_104]
    type = PointValue
    point = '0.0 31.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_105]
    type = PointValue
    point = '0.0 31.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_106]
    type = PointValue
    point = '0.0 31.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_107]
    type = PointValue
    point = '0.0 32.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_108]
    type = PointValue
    point = '0.0 32.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_109]
    type = PointValue
    point = '0.0 32.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_110]
    type = PointValue
    point = '0.0 33.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_111]
    type = PointValue
    point = '0.0 33.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_112]
    type = PointValue
    point = '0.0 33.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_113]
    type = PointValue
    point = '0.0 33.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_114]
    type = PointValue
    point = '0.0 34.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_115]
    type = PointValue
    point = '0.0 34.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_116]
    type = PointValue
    point = '0.0 34.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_117]
    type = PointValue
    point = '0.0 35.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_118]
    type = PointValue
    point = '0.0 35.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_119]
    type = PointValue
    point = '0.0 35.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_120]
    type = PointValue
    point = '0.0 36.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_121]
    type = PointValue
    point = '0.0 36.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_122]
    type = PointValue
    point = '0.0 36.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_123]
    type = PointValue
    point = '0.0 36.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_124]
    type = PointValue
    point = '0.0 37.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_125]
    type = PointValue
    point = '0.0 37.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_126]
    type = PointValue
    point = '0.0 37.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_127]
    type = PointValue
    point = '0.0 38.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_128]
    type = PointValue
    point = '0.0 38.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_129]
    type = PointValue
    point = '0.0 38.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_130]
    type = PointValue
    point = '0.0 39.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_131]
    type = PointValue
    point = '0.0 39.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_132]
    type = PointValue
    point = '0.0 39.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_133]
    type = PointValue
    point = '0.0 39.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_134]
    type = PointValue
    point = '0.0 40.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_135]
    type = PointValue
    point = '0.0 40.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_136]
    type = PointValue
    point = '0.0 40.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_137]
    type = PointValue
    point = '0.0 41.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_138]
    type = PointValue
    point = '0.0 41.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_139]
    type = PointValue
    point = '0.0 41.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_140]
    type = PointValue
    point = '0.0 42.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_141]
    type = PointValue
    point = '0.0 42.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_142]
    type = PointValue
    point = '0.0 42.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_143]
    type = PointValue
    point = '0.0 42.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_144]
    type = PointValue
    point = '0.0 43.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_145]
    type = PointValue
    point = '0.0 43.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_146]
    type = PointValue
    point = '0.0 43.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_147]
    type = PointValue
    point = '0.0 44.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_148]
    type = PointValue
    point = '0.0 44.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_149]
    type = PointValue
    point = '0.0 44.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_150]
    type = PointValue
    point = '0.0 45.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_151]
    type = PointValue
    point = '0.0 45.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_152]
    type = PointValue
    point = '0.0 45.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_153]
    type = PointValue
    point = '0.0 45.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_154]
    type = PointValue
    point = '0.0 46.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_155]
    type = PointValue
    point = '0.0 46.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_156]
    type = PointValue
    point = '0.0 46.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_157]
    type = PointValue
    point = '0.0 47.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_158]
    type = PointValue
    point = '0.0 47.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_159]
    type = PointValue
    point = '0.0 47.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_160]
    type = PointValue
    point = '0.0 48.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_161]
    type = PointValue
    point = '0.0 48.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_162]
    type = PointValue
    point = '0.0 48.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_163]
    type = PointValue
    point = '0.0 48.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_164]
    type = PointValue
    point = '0.0 49.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_165]
    type = PointValue
    point = '0.0 49.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_166]
    type = PointValue
    point = '0.0 49.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_167]
    type = PointValue
    point = '0.0 50.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_168]
    type = PointValue
    point = '0.0 50.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_169]
    type = PointValue
    point = '0.0 50.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_170]
    type = PointValue
    point = '0.0 51.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_171]
    type = PointValue
    point = '0.0 51.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_172]
    type = PointValue
    point = '0.0 51.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_173]
    type = PointValue
    point = '0.0 51.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_174]
    type = PointValue
    point = '0.0 52.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_175]
    type = PointValue
    point = '0.0 52.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_176]
    type = PointValue
    point = '0.0 52.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_177]
    type = PointValue
    point = '0.0 53.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_178]
    type = PointValue
    point = '0.0 53.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_179]
    type = PointValue
    point = '0.0 53.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_180]
    type = PointValue
    point = '0.0 54.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_181]
    type = PointValue
    point = '0.0 54.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_182]
    type = PointValue
    point = '0.0 54.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_183]
    type = PointValue
    point = '0.0 54.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_184]
    type = PointValue
    point = '0.0 55.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_185]
    type = PointValue
    point = '0.0 55.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_186]
    type = PointValue
    point = '0.0 55.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_187]
    type = PointValue
    point = '0.0 56.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_188]
    type = PointValue
    point = '0.0 56.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_189]
    type = PointValue
    point = '0.0 56.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_190]
    type = PointValue
    point = '0.0 57.0 0.0'
    variable = wc_z
  [../]
  [./wc_z_191]
    type = PointValue
    point = '0.0 57.3 0.0'
    variable = wc_z
  [../]
  [./wc_z_192]
    type = PointValue
    point = '0.0 57.6 0.0'
    variable = wc_z
  [../]
  [./wc_z_193]
    type = PointValue
    point = '0.0 57.9 0.0'
    variable = wc_z
  [../]
  [./wc_z_194]
    type = PointValue
    point = '0.0 58.2 0.0'
    variable = wc_z
  [../]
  [./wc_z_195]
    type = PointValue
    point = '0.0 58.5 0.0'
    variable = wc_z
  [../]
  [./wc_z_196]
    type = PointValue
    point = '0.0 58.8 0.0'
    variable = wc_z
  [../]
  [./wc_z_197]
    type = PointValue
    point = '0.0 59.1 0.0'
    variable = wc_z
  [../]
  [./wc_z_198]
    type = PointValue
    point = '0.0 59.4 0.0'
    variable = wc_z
  [../]
  [./wc_z_199]
    type = PointValue
    point = '0.0 59.7 0.0'
    variable = wc_z
  [../]
  [./wc_z_200]
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
    point = '0.0 0.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 0.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 0.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 1.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 1.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 2.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 2.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 2.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 3.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 3.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 3.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 3.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 4.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 4.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 4.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 5.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 5.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 5.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 6.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 6.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 6.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 6.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 7.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 7.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 7.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 8.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 8.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 8.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 9.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 9.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 9.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 9.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 10.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 10.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 10.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 11.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 11.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 11.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 12.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '0.0 12.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '0.0 12.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '0.0 12.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '0.0 13.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '0.0 13.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '0.0 13.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '0.0 14.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '0.0 14.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '0.0 14.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '0.0 15.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '0.0 15.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '0.0 15.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '0.0 15.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '0.0 16.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '0.0 16.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '0.0 16.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '0.0 17.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '0.0 17.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '0.0 17.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '0.0 18.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '0.0 18.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '0.0 18.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '0.0 18.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '0.0 19.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '0.0 19.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '0.0 19.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '0.0 20.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '0.0 20.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '0.0 20.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '0.0 21.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '0.0 21.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '0.0 21.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '0.0 21.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '0.0 22.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '0.0 22.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '0.0 22.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '0.0 23.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '0.0 23.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '0.0 23.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '0.0 24.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_81]
    type = PointValue
    point = '0.0 24.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_82]
    type = PointValue
    point = '0.0 24.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_83]
    type = PointValue
    point = '0.0 24.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_84]
    type = PointValue
    point = '0.0 25.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_85]
    type = PointValue
    point = '0.0 25.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_86]
    type = PointValue
    point = '0.0 25.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_87]
    type = PointValue
    point = '0.0 26.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_88]
    type = PointValue
    point = '0.0 26.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_89]
    type = PointValue
    point = '0.0 26.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_90]
    type = PointValue
    point = '0.0 27.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_91]
    type = PointValue
    point = '0.0 27.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_92]
    type = PointValue
    point = '0.0 27.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_93]
    type = PointValue
    point = '0.0 27.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_94]
    type = PointValue
    point = '0.0 28.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_95]
    type = PointValue
    point = '0.0 28.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_96]
    type = PointValue
    point = '0.0 28.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_97]
    type = PointValue
    point = '0.0 29.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_98]
    type = PointValue
    point = '0.0 29.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_99]
    type = PointValue
    point = '0.0 29.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_100]
    type = PointValue
    point = '0.0 30.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_101]
    type = PointValue
    point = '0.0 30.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_102]
    type = PointValue
    point = '0.0 30.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_103]
    type = PointValue
    point = '0.0 30.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_104]
    type = PointValue
    point = '0.0 31.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_105]
    type = PointValue
    point = '0.0 31.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_106]
    type = PointValue
    point = '0.0 31.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_107]
    type = PointValue
    point = '0.0 32.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_108]
    type = PointValue
    point = '0.0 32.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_109]
    type = PointValue
    point = '0.0 32.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_110]
    type = PointValue
    point = '0.0 33.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_111]
    type = PointValue
    point = '0.0 33.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_112]
    type = PointValue
    point = '0.0 33.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_113]
    type = PointValue
    point = '0.0 33.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_114]
    type = PointValue
    point = '0.0 34.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_115]
    type = PointValue
    point = '0.0 34.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_116]
    type = PointValue
    point = '0.0 34.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_117]
    type = PointValue
    point = '0.0 35.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_118]
    type = PointValue
    point = '0.0 35.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_119]
    type = PointValue
    point = '0.0 35.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_120]
    type = PointValue
    point = '0.0 36.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_121]
    type = PointValue
    point = '0.0 36.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_122]
    type = PointValue
    point = '0.0 36.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_123]
    type = PointValue
    point = '0.0 36.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_124]
    type = PointValue
    point = '0.0 37.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_125]
    type = PointValue
    point = '0.0 37.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_126]
    type = PointValue
    point = '0.0 37.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_127]
    type = PointValue
    point = '0.0 38.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_128]
    type = PointValue
    point = '0.0 38.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_129]
    type = PointValue
    point = '0.0 38.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_130]
    type = PointValue
    point = '0.0 39.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_131]
    type = PointValue
    point = '0.0 39.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_132]
    type = PointValue
    point = '0.0 39.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_133]
    type = PointValue
    point = '0.0 39.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_134]
    type = PointValue
    point = '0.0 40.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_135]
    type = PointValue
    point = '0.0 40.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_136]
    type = PointValue
    point = '0.0 40.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_137]
    type = PointValue
    point = '0.0 41.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_138]
    type = PointValue
    point = '0.0 41.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_139]
    type = PointValue
    point = '0.0 41.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_140]
    type = PointValue
    point = '0.0 42.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_141]
    type = PointValue
    point = '0.0 42.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_142]
    type = PointValue
    point = '0.0 42.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_143]
    type = PointValue
    point = '0.0 42.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_144]
    type = PointValue
    point = '0.0 43.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_145]
    type = PointValue
    point = '0.0 43.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_146]
    type = PointValue
    point = '0.0 43.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_147]
    type = PointValue
    point = '0.0 44.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_148]
    type = PointValue
    point = '0.0 44.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_149]
    type = PointValue
    point = '0.0 44.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_150]
    type = PointValue
    point = '0.0 45.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_151]
    type = PointValue
    point = '0.0 45.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_152]
    type = PointValue
    point = '0.0 45.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_153]
    type = PointValue
    point = '0.0 45.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_154]
    type = PointValue
    point = '0.0 46.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_155]
    type = PointValue
    point = '0.0 46.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_156]
    type = PointValue
    point = '0.0 46.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_157]
    type = PointValue
    point = '0.0 47.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_158]
    type = PointValue
    point = '0.0 47.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_159]
    type = PointValue
    point = '0.0 47.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_160]
    type = PointValue
    point = '0.0 48.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_161]
    type = PointValue
    point = '0.0 48.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_162]
    type = PointValue
    point = '0.0 48.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_163]
    type = PointValue
    point = '0.0 48.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_164]
    type = PointValue
    point = '0.0 49.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_165]
    type = PointValue
    point = '0.0 49.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_166]
    type = PointValue
    point = '0.0 49.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_167]
    type = PointValue
    point = '0.0 50.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_168]
    type = PointValue
    point = '0.0 50.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_169]
    type = PointValue
    point = '0.0 50.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_170]
    type = PointValue
    point = '0.0 51.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_171]
    type = PointValue
    point = '0.0 51.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_172]
    type = PointValue
    point = '0.0 51.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_173]
    type = PointValue
    point = '0.0 51.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_174]
    type = PointValue
    point = '0.0 52.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_175]
    type = PointValue
    point = '0.0 52.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_176]
    type = PointValue
    point = '0.0 52.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_177]
    type = PointValue
    point = '0.0 53.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_178]
    type = PointValue
    point = '0.0 53.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_179]
    type = PointValue
    point = '0.0 53.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_180]
    type = PointValue
    point = '0.0 54.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_181]
    type = PointValue
    point = '0.0 54.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_182]
    type = PointValue
    point = '0.0 54.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_183]
    type = PointValue
    point = '0.0 54.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_184]
    type = PointValue
    point = '0.0 55.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_185]
    type = PointValue
    point = '0.0 55.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_186]
    type = PointValue
    point = '0.0 55.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_187]
    type = PointValue
    point = '0.0 56.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_188]
    type = PointValue
    point = '0.0 56.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_189]
    type = PointValue
    point = '0.0 56.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_190]
    type = PointValue
    point = '0.0 57.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_191]
    type = PointValue
    point = '0.0 57.3 0.0'
    variable = disp_x
  [../]
  [./disp_x_192]
    type = PointValue
    point = '0.0 57.6 0.0'
    variable = disp_x
  [../]
  [./disp_x_193]
    type = PointValue
    point = '0.0 57.9 0.0'
    variable = disp_x
  [../]
  [./disp_x_194]
    type = PointValue
    point = '0.0 58.2 0.0'
    variable = disp_x
  [../]
  [./disp_x_195]
    type = PointValue
    point = '0.0 58.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_196]
    type = PointValue
    point = '0.0 58.8 0.0'
    variable = disp_x
  [../]
  [./disp_x_197]
    type = PointValue
    point = '0.0 59.1 0.0'
    variable = disp_x
  [../]
  [./disp_x_198]
    type = PointValue
    point = '0.0 59.4 0.0'
    variable = disp_x
  [../]
  [./disp_x_199]
    type = PointValue
    point = '0.0 59.7 0.0'
    variable = disp_x
  [../]
  [./disp_x_200]
    type = PointValue
    point = '0.0 60.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 0.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 1.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 1.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 1.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 1.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 2.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 2.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 2.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 3.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 3.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 3.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 4.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 4.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 4.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 4.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 5.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 5.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 5.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 6.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 6.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 6.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 7.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 7.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 7.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 7.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 8.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 8.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 8.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 9.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 9.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 9.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 10.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 10.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 10.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 10.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 11.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 11.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 11.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '0.0 12.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '0.0 12.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '0.0 12.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '0.0 13.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '0.0 13.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '0.0 13.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '0.0 13.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '0.0 14.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '0.0 14.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '0.0 14.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '0.0 15.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '0.0 15.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '0.0 15.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '0.0 16.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '0.0 16.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '0.0 16.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '0.0 16.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '0.0 17.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '0.0 17.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '0.0 17.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '0.0 18.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '0.0 18.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '0.0 18.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '0.0 19.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '0.0 19.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '0.0 19.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '0.0 19.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '0.0 20.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '0.0 20.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '0.0 20.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '0.0 21.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '0.0 21.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '0.0 21.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '0.0 22.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '0.0 22.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '0.0 22.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '0.0 22.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '0.0 23.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '0.0 23.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '0.0 23.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_80]
    type = PointValue
    point = '0.0 24.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_81]
    type = PointValue
    point = '0.0 24.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_82]
    type = PointValue
    point = '0.0 24.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_83]
    type = PointValue
    point = '0.0 25.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_84]
    type = PointValue
    point = '0.0 25.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_85]
    type = PointValue
    point = '0.0 25.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_86]
    type = PointValue
    point = '0.0 25.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_87]
    type = PointValue
    point = '0.0 26.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_88]
    type = PointValue
    point = '0.0 26.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_89]
    type = PointValue
    point = '0.0 26.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_90]
    type = PointValue
    point = '0.0 27.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_91]
    type = PointValue
    point = '0.0 27.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_92]
    type = PointValue
    point = '0.0 27.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_93]
    type = PointValue
    point = '0.0 28.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_94]
    type = PointValue
    point = '0.0 28.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_95]
    type = PointValue
    point = '0.0 28.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_96]
    type = PointValue
    point = '0.0 28.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_97]
    type = PointValue
    point = '0.0 29.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_98]
    type = PointValue
    point = '0.0 29.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_99]
    type = PointValue
    point = '0.0 29.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_100]
    type = PointValue
    point = '0.0 30.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_101]
    type = PointValue
    point = '0.0 30.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_102]
    type = PointValue
    point = '0.0 30.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_103]
    type = PointValue
    point = '0.0 31.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_104]
    type = PointValue
    point = '0.0 31.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_105]
    type = PointValue
    point = '0.0 31.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_106]
    type = PointValue
    point = '0.0 31.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_107]
    type = PointValue
    point = '0.0 32.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_108]
    type = PointValue
    point = '0.0 32.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_109]
    type = PointValue
    point = '0.0 32.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_110]
    type = PointValue
    point = '0.0 33.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_111]
    type = PointValue
    point = '0.0 33.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_112]
    type = PointValue
    point = '0.0 33.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_113]
    type = PointValue
    point = '0.0 34.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_114]
    type = PointValue
    point = '0.0 34.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_115]
    type = PointValue
    point = '0.0 34.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_116]
    type = PointValue
    point = '0.0 34.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_117]
    type = PointValue
    point = '0.0 35.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_118]
    type = PointValue
    point = '0.0 35.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_119]
    type = PointValue
    point = '0.0 35.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_120]
    type = PointValue
    point = '0.0 36.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_121]
    type = PointValue
    point = '0.0 36.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_122]
    type = PointValue
    point = '0.0 36.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_123]
    type = PointValue
    point = '0.0 37.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_124]
    type = PointValue
    point = '0.0 37.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_125]
    type = PointValue
    point = '0.0 37.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_126]
    type = PointValue
    point = '0.0 37.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_127]
    type = PointValue
    point = '0.0 38.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_128]
    type = PointValue
    point = '0.0 38.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_129]
    type = PointValue
    point = '0.0 38.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_130]
    type = PointValue
    point = '0.0 39.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_131]
    type = PointValue
    point = '0.0 39.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_132]
    type = PointValue
    point = '0.0 39.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_133]
    type = PointValue
    point = '0.0 40.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_134]
    type = PointValue
    point = '0.0 40.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_135]
    type = PointValue
    point = '0.0 40.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_136]
    type = PointValue
    point = '0.0 40.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_137]
    type = PointValue
    point = '0.0 41.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_138]
    type = PointValue
    point = '0.0 41.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_139]
    type = PointValue
    point = '0.0 41.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_140]
    type = PointValue
    point = '0.0 42.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_141]
    type = PointValue
    point = '0.0 42.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_142]
    type = PointValue
    point = '0.0 42.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_143]
    type = PointValue
    point = '0.0 43.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_144]
    type = PointValue
    point = '0.0 43.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_145]
    type = PointValue
    point = '0.0 43.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_146]
    type = PointValue
    point = '0.0 43.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_147]
    type = PointValue
    point = '0.0 44.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_148]
    type = PointValue
    point = '0.0 44.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_149]
    type = PointValue
    point = '0.0 44.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_150]
    type = PointValue
    point = '0.0 45.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_151]
    type = PointValue
    point = '0.0 45.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_152]
    type = PointValue
    point = '0.0 45.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_153]
    type = PointValue
    point = '0.0 46.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_154]
    type = PointValue
    point = '0.0 46.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_155]
    type = PointValue
    point = '0.0 46.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_156]
    type = PointValue
    point = '0.0 46.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_157]
    type = PointValue
    point = '0.0 47.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_158]
    type = PointValue
    point = '0.0 47.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_159]
    type = PointValue
    point = '0.0 47.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_160]
    type = PointValue
    point = '0.0 48.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_161]
    type = PointValue
    point = '0.0 48.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_162]
    type = PointValue
    point = '0.0 48.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_163]
    type = PointValue
    point = '0.0 49.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_164]
    type = PointValue
    point = '0.0 49.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_165]
    type = PointValue
    point = '0.0 49.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_166]
    type = PointValue
    point = '0.0 49.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_167]
    type = PointValue
    point = '0.0 50.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_168]
    type = PointValue
    point = '0.0 50.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_169]
    type = PointValue
    point = '0.0 50.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_170]
    type = PointValue
    point = '0.0 51.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_171]
    type = PointValue
    point = '0.0 51.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_172]
    type = PointValue
    point = '0.0 51.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_173]
    type = PointValue
    point = '0.0 52.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_174]
    type = PointValue
    point = '0.0 52.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_175]
    type = PointValue
    point = '0.0 52.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_176]
    type = PointValue
    point = '0.0 52.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_177]
    type = PointValue
    point = '0.0 53.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_178]
    type = PointValue
    point = '0.0 53.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_179]
    type = PointValue
    point = '0.0 53.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_180]
    type = PointValue
    point = '0.0 54.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_181]
    type = PointValue
    point = '0.0 54.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_182]
    type = PointValue
    point = '0.0 54.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_183]
    type = PointValue
    point = '0.0 55.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_184]
    type = PointValue
    point = '0.0 55.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_185]
    type = PointValue
    point = '0.0 55.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_186]
    type = PointValue
    point = '0.0 55.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_187]
    type = PointValue
    point = '0.0 56.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_188]
    type = PointValue
    point = '0.0 56.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_189]
    type = PointValue
    point = '0.0 56.85 0.0'
    variable = lagrange
  [../]
  [./lagrange_190]
    type = PointValue
    point = '0.0 57.15 0.0'
    variable = lagrange
  [../]
  [./lagrange_191]
    type = PointValue
    point = '0.0 57.45 0.0'
    variable = lagrange
  [../]
  [./lagrange_192]
    type = PointValue
    point = '0.0 57.75 0.0'
    variable = lagrange
  [../]
  [./lagrange_193]
    type = PointValue
    point = '0.0 58.05 0.0'
    variable = lagrange
  [../]
  [./lagrange_194]
    type = PointValue
    point = '0.0 58.35 0.0'
    variable = lagrange
  [../]
  [./lagrange_195]
    type = PointValue
    point = '0.0 58.65 0.0'
    variable = lagrange
  [../]
  [./lagrange_196]
    type = PointValue
    point = '0.0 58.95 0.0'
    variable = lagrange
  [../]
  [./lagrange_197]
    type = PointValue
    point = '0.0 59.25 0.0'
    variable = lagrange
  [../]
  [./lagrange_198]
    type = PointValue
    point = '0.0 59.55 0.0'
    variable = lagrange
  [../]
  [./lagrange_199]
    type = PointValue
    point = '0.0 59.85 0.0'
    variable = lagrange
  [../]
  [./strain_xy_0]
    type = PointValue
    point = '0.0 0.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_1]
    type = PointValue
    point = '0.0 0.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_2]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_3]
    type = PointValue
    point = '0.0 1.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_4]
    type = PointValue
    point = '0.0 1.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_5]
    type = PointValue
    point = '0.0 1.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_6]
    type = PointValue
    point = '0.0 1.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_7]
    type = PointValue
    point = '0.0 2.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_8]
    type = PointValue
    point = '0.0 2.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_9]
    type = PointValue
    point = '0.0 2.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_10]
    type = PointValue
    point = '0.0 3.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_11]
    type = PointValue
    point = '0.0 3.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_12]
    type = PointValue
    point = '0.0 3.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_13]
    type = PointValue
    point = '0.0 4.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_14]
    type = PointValue
    point = '0.0 4.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_15]
    type = PointValue
    point = '0.0 4.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_16]
    type = PointValue
    point = '0.0 4.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_17]
    type = PointValue
    point = '0.0 5.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_18]
    type = PointValue
    point = '0.0 5.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_19]
    type = PointValue
    point = '0.0 5.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_20]
    type = PointValue
    point = '0.0 6.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_21]
    type = PointValue
    point = '0.0 6.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_22]
    type = PointValue
    point = '0.0 6.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_23]
    type = PointValue
    point = '0.0 7.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_24]
    type = PointValue
    point = '0.0 7.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_25]
    type = PointValue
    point = '0.0 7.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_26]
    type = PointValue
    point = '0.0 7.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_27]
    type = PointValue
    point = '0.0 8.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_28]
    type = PointValue
    point = '0.0 8.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_29]
    type = PointValue
    point = '0.0 8.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_30]
    type = PointValue
    point = '0.0 9.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_31]
    type = PointValue
    point = '0.0 9.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_32]
    type = PointValue
    point = '0.0 9.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_33]
    type = PointValue
    point = '0.0 10.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_34]
    type = PointValue
    point = '0.0 10.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_35]
    type = PointValue
    point = '0.0 10.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_36]
    type = PointValue
    point = '0.0 10.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_37]
    type = PointValue
    point = '0.0 11.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_38]
    type = PointValue
    point = '0.0 11.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_39]
    type = PointValue
    point = '0.0 11.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_40]
    type = PointValue
    point = '0.0 12.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_41]
    type = PointValue
    point = '0.0 12.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_42]
    type = PointValue
    point = '0.0 12.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_43]
    type = PointValue
    point = '0.0 13.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_44]
    type = PointValue
    point = '0.0 13.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_45]
    type = PointValue
    point = '0.0 13.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_46]
    type = PointValue
    point = '0.0 13.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_47]
    type = PointValue
    point = '0.0 14.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_48]
    type = PointValue
    point = '0.0 14.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_49]
    type = PointValue
    point = '0.0 14.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_50]
    type = PointValue
    point = '0.0 15.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_51]
    type = PointValue
    point = '0.0 15.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_52]
    type = PointValue
    point = '0.0 15.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_53]
    type = PointValue
    point = '0.0 16.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_54]
    type = PointValue
    point = '0.0 16.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_55]
    type = PointValue
    point = '0.0 16.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_56]
    type = PointValue
    point = '0.0 16.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_57]
    type = PointValue
    point = '0.0 17.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_58]
    type = PointValue
    point = '0.0 17.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_59]
    type = PointValue
    point = '0.0 17.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_60]
    type = PointValue
    point = '0.0 18.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_61]
    type = PointValue
    point = '0.0 18.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_62]
    type = PointValue
    point = '0.0 18.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_63]
    type = PointValue
    point = '0.0 19.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_64]
    type = PointValue
    point = '0.0 19.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_65]
    type = PointValue
    point = '0.0 19.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_66]
    type = PointValue
    point = '0.0 19.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_67]
    type = PointValue
    point = '0.0 20.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_68]
    type = PointValue
    point = '0.0 20.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_69]
    type = PointValue
    point = '0.0 20.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_70]
    type = PointValue
    point = '0.0 21.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_71]
    type = PointValue
    point = '0.0 21.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_72]
    type = PointValue
    point = '0.0 21.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_73]
    type = PointValue
    point = '0.0 22.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_74]
    type = PointValue
    point = '0.0 22.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_75]
    type = PointValue
    point = '0.0 22.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_76]
    type = PointValue
    point = '0.0 22.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_77]
    type = PointValue
    point = '0.0 23.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_78]
    type = PointValue
    point = '0.0 23.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_79]
    type = PointValue
    point = '0.0 23.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_80]
    type = PointValue
    point = '0.0 24.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_81]
    type = PointValue
    point = '0.0 24.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_82]
    type = PointValue
    point = '0.0 24.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_83]
    type = PointValue
    point = '0.0 25.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_84]
    type = PointValue
    point = '0.0 25.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_85]
    type = PointValue
    point = '0.0 25.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_86]
    type = PointValue
    point = '0.0 25.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_87]
    type = PointValue
    point = '0.0 26.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_88]
    type = PointValue
    point = '0.0 26.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_89]
    type = PointValue
    point = '0.0 26.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_90]
    type = PointValue
    point = '0.0 27.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_91]
    type = PointValue
    point = '0.0 27.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_92]
    type = PointValue
    point = '0.0 27.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_93]
    type = PointValue
    point = '0.0 28.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_94]
    type = PointValue
    point = '0.0 28.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_95]
    type = PointValue
    point = '0.0 28.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_96]
    type = PointValue
    point = '0.0 28.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_97]
    type = PointValue
    point = '0.0 29.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_98]
    type = PointValue
    point = '0.0 29.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_99]
    type = PointValue
    point = '0.0 29.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_100]
    type = PointValue
    point = '0.0 30.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_101]
    type = PointValue
    point = '0.0 30.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_102]
    type = PointValue
    point = '0.0 30.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_103]
    type = PointValue
    point = '0.0 31.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_104]
    type = PointValue
    point = '0.0 31.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_105]
    type = PointValue
    point = '0.0 31.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_106]
    type = PointValue
    point = '0.0 31.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_107]
    type = PointValue
    point = '0.0 32.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_108]
    type = PointValue
    point = '0.0 32.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_109]
    type = PointValue
    point = '0.0 32.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_110]
    type = PointValue
    point = '0.0 33.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_111]
    type = PointValue
    point = '0.0 33.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_112]
    type = PointValue
    point = '0.0 33.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_113]
    type = PointValue
    point = '0.0 34.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_114]
    type = PointValue
    point = '0.0 34.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_115]
    type = PointValue
    point = '0.0 34.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_116]
    type = PointValue
    point = '0.0 34.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_117]
    type = PointValue
    point = '0.0 35.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_118]
    type = PointValue
    point = '0.0 35.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_119]
    type = PointValue
    point = '0.0 35.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_120]
    type = PointValue
    point = '0.0 36.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_121]
    type = PointValue
    point = '0.0 36.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_122]
    type = PointValue
    point = '0.0 36.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_123]
    type = PointValue
    point = '0.0 37.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_124]
    type = PointValue
    point = '0.0 37.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_125]
    type = PointValue
    point = '0.0 37.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_126]
    type = PointValue
    point = '0.0 37.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_127]
    type = PointValue
    point = '0.0 38.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_128]
    type = PointValue
    point = '0.0 38.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_129]
    type = PointValue
    point = '0.0 38.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_130]
    type = PointValue
    point = '0.0 39.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_131]
    type = PointValue
    point = '0.0 39.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_132]
    type = PointValue
    point = '0.0 39.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_133]
    type = PointValue
    point = '0.0 40.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_134]
    type = PointValue
    point = '0.0 40.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_135]
    type = PointValue
    point = '0.0 40.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_136]
    type = PointValue
    point = '0.0 40.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_137]
    type = PointValue
    point = '0.0 41.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_138]
    type = PointValue
    point = '0.0 41.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_139]
    type = PointValue
    point = '0.0 41.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_140]
    type = PointValue
    point = '0.0 42.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_141]
    type = PointValue
    point = '0.0 42.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_142]
    type = PointValue
    point = '0.0 42.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_143]
    type = PointValue
    point = '0.0 43.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_144]
    type = PointValue
    point = '0.0 43.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_145]
    type = PointValue
    point = '0.0 43.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_146]
    type = PointValue
    point = '0.0 43.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_147]
    type = PointValue
    point = '0.0 44.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_148]
    type = PointValue
    point = '0.0 44.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_149]
    type = PointValue
    point = '0.0 44.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_150]
    type = PointValue
    point = '0.0 45.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_151]
    type = PointValue
    point = '0.0 45.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_152]
    type = PointValue
    point = '0.0 45.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_153]
    type = PointValue
    point = '0.0 46.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_154]
    type = PointValue
    point = '0.0 46.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_155]
    type = PointValue
    point = '0.0 46.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_156]
    type = PointValue
    point = '0.0 46.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_157]
    type = PointValue
    point = '0.0 47.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_158]
    type = PointValue
    point = '0.0 47.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_159]
    type = PointValue
    point = '0.0 47.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_160]
    type = PointValue
    point = '0.0 48.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_161]
    type = PointValue
    point = '0.0 48.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_162]
    type = PointValue
    point = '0.0 48.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_163]
    type = PointValue
    point = '0.0 49.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_164]
    type = PointValue
    point = '0.0 49.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_165]
    type = PointValue
    point = '0.0 49.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_166]
    type = PointValue
    point = '0.0 49.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_167]
    type = PointValue
    point = '0.0 50.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_168]
    type = PointValue
    point = '0.0 50.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_169]
    type = PointValue
    point = '0.0 50.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_170]
    type = PointValue
    point = '0.0 51.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_171]
    type = PointValue
    point = '0.0 51.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_172]
    type = PointValue
    point = '0.0 51.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_173]
    type = PointValue
    point = '0.0 52.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_174]
    type = PointValue
    point = '0.0 52.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_175]
    type = PointValue
    point = '0.0 52.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_176]
    type = PointValue
    point = '0.0 52.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_177]
    type = PointValue
    point = '0.0 53.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_178]
    type = PointValue
    point = '0.0 53.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_179]
    type = PointValue
    point = '0.0 53.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_180]
    type = PointValue
    point = '0.0 54.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_181]
    type = PointValue
    point = '0.0 54.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_182]
    type = PointValue
    point = '0.0 54.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_183]
    type = PointValue
    point = '0.0 55.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_184]
    type = PointValue
    point = '0.0 55.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_185]
    type = PointValue
    point = '0.0 55.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_186]
    type = PointValue
    point = '0.0 55.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_187]
    type = PointValue
    point = '0.0 56.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_188]
    type = PointValue
    point = '0.0 56.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_189]
    type = PointValue
    point = '0.0 56.85 0.0'
    variable = strain_12
  [../]
  [./strain_xy_190]
    type = PointValue
    point = '0.0 57.15 0.0'
    variable = strain_12
  [../]
  [./strain_xy_191]
    type = PointValue
    point = '0.0 57.45 0.0'
    variable = strain_12
  [../]
  [./strain_xy_192]
    type = PointValue
    point = '0.0 57.75 0.0'
    variable = strain_12
  [../]
  [./strain_xy_193]
    type = PointValue
    point = '0.0 58.05 0.0'
    variable = strain_12
  [../]
  [./strain_xy_194]
    type = PointValue
    point = '0.0 58.35 0.0'
    variable = strain_12
  [../]
  [./strain_xy_195]
    type = PointValue
    point = '0.0 58.65 0.0'
    variable = strain_12
  [../]
  [./strain_xy_196]
    type = PointValue
    point = '0.0 58.95 0.0'
    variable = strain_12
  [../]
  [./strain_xy_197]
    type = PointValue
    point = '0.0 59.25 0.0'
    variable = strain_12
  [../]
  [./strain_xy_198]
    type = PointValue
    point = '0.0 59.55 0.0'
    variable = strain_12
  [../]
  [./strain_xy_199]
    type = PointValue
    point = '0.0 59.85 0.0'
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
  [./tau]
    type = PointValue
    variable = stress_invariant
    point = '0 60 0'
  [../]
  [./gamma_p]
    type = PointValue
    variable = plastic_strain
    point = '0 60 0'
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
    B_ijkl = '0 1.28E5  1.28E5'
    C_ijkl = '1.3333E3 4.0E3 2.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 100
    hardening_mech_modulus = -4
    friction_coefficient = 0.0
    min_stepsize = 1e-8
    plasticity_type = DeBorst_2D
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
    petsc_options_value = 'gmres          bjacobi     1E-6          1E-7          40                1E-12      1E-10 '
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
  file_base = plastic_shear_R4_h400_200DB
  print_linear_residuals = false
[]

