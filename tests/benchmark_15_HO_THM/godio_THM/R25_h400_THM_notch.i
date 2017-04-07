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
  pore_pres = pressure
  temperature = temperature
  temp = temperature
[]

[Postprocessors]
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
  [./temperature]
    block = '1 2 3'
  [../]
  [./pressure]
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
  [./dT_dt]
    type = TimeDerivative
    variable = temperature
  [../]
  [./T_diff]
    type = RedbackThermalDiffusion
    variable = temperature
  [../]
  [./mech_dissip]
    type = RedbackMechDissip
    variable = temperature
  [../]
  [./dp_dt]
    type = TimeDerivative
    variable = pressure
  [../]
  [./diff_p]
    type = RedbackMassDiffusion
    variable = pressure
  [../]
  [./poromech]
    type = RedbackPoroMechHO
    variable = pressure
    block = '1 2 3'
  [../]
  [./thermal_press]
    type = RedbackThermalPressurization
    variable = pressure
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
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
      translation = '120 0 0'
      secondary = right_top
      primary = left_top
    [../]
    [./z_direction]
      variable = 'disp_x disp_y disp_z wc_x wc_y wc_z temperature pressure'
      translation = '0 0 -120'
      secondary = back
      primary = front
    [../]
    [./x_direction_2]
      translation = '120 0 0'
      secondary = right_bot
      primary = left_bot
      variable = 'wc_x wc_y wc_z disp_x disp_y disp_z temperature pressure'
    [../]
    [./x_direction_3]
      translation = '118 0 0'
      secondary = right_mid
      primary = left_mid
      variable = 'wc_x wc_y wc_z disp_x disp_y disp_z temperature pressure'
    [../]
    [./y_direction]
      variable = wc_z
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
    B_ijkl = '0 5.0E4 5.0E4'
    C_ijkl = '1.3333E3 4.0E3 2.0E3'
    fill_method = general_isotropic
    poisson_ratio = -9999
    youngs_modulus = -9999
    damage_method = BreakageMechanics
    cohesion = 100
    hardening_mech_modulus = 0
    friction_coefficient = 0.0
    min_stepsize = 1e-8
    plasticity_type = DeBorst_2D
    beta_star = 1/4000
    total_porosity = 0.04
  [../]
  [./redback_mat]
    type = RedbackMaterial
    block = '1 2 3'
    eta1 = 0
    total_porosity = 0.04
    solid_density = 0
    confining_pressure = 0
    delta = 0
    fluid_density = 0
    eta2 = 0
    ref_lewis_nb = 1/23
    solid_thermal_expansion = 2.5e-5
    pressurization_coefficient = 0.9
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
  file_base = plastic_shear_R25_Hs400_THM
  print_linear_residuals = false
[]

