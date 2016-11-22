[Mesh]
  type = GeneratedMesh
  dim = 3
  ny = 480
  xmax = 5
  ymax = 5
  zmax = 5
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
  active  = 'number_lin disp_y_top tangential_force normal_force number_nonlin disp_x_bottom wc_z_top dt disp_x_0 disp_x_1 disp_x_2 disp_x_3 disp_x_4 disp_x_5 disp_x_6 disp_x_7 disp_x_8 disp_x_9 disp_x_10 disp_x_11 disp_x_12 disp_x_13 disp_x_14 disp_x_15 disp_x_16 disp_x_17 disp_x_18 disp_x_19 disp_x_20 disp_x_21 disp_x_22 disp_x_23 disp_x_24 disp_x_25 disp_x_26 disp_x_27 disp_x_28 disp_x_29 disp_x_30 disp_x_31 disp_x_32 disp_x_33 disp_x_34 disp_x_35 disp_x_36 disp_x_37 disp_x_38 disp_x_39 disp_x_40 disp_x_41 disp_x_42 disp_x_43 disp_x_44 disp_x_45 disp_x_46 disp_x_47 disp_x_48 disp_x_49 disp_x_50 disp_x_51 disp_x_52 disp_x_53 disp_x_54 disp_x_55 disp_x_56 disp_x_57 disp_x_58 disp_x_59 disp_x_60 disp_x_61 disp_x_62 disp_x_63 disp_x_64 disp_x_65 disp_x_66 disp_x_67 disp_x_68 disp_x_69 disp_x_70 disp_x_71 disp_x_72 disp_x_73 disp_x_74 disp_x_75 disp_x_76 disp_x_77 disp_x_78 disp_x_79 disp_x_80 disp_x_81 disp_x_82 disp_x_83 disp_x_84 disp_x_85 disp_x_86 disp_x_87 disp_x_88 disp_x_89 disp_x_90 disp_x_91 disp_x_92 disp_x_93 disp_x_94 disp_x_95 disp_x_96 disp_x_97 disp_x_98 disp_x_99 disp_x_100 disp_x_101 disp_x_102 disp_x_103 disp_x_104 disp_x_105 disp_x_106 disp_x_107 disp_x_108 disp_x_109 disp_x_110 disp_x_111 disp_x_112 disp_x_113 disp_x_114 disp_x_115 disp_x_116 disp_x_117 disp_x_118 disp_x_119 disp_x_120 disp_x_121 disp_x_122 disp_x_123 disp_x_124 disp_x_125 disp_x_126 disp_x_127 disp_x_128 disp_x_129 disp_x_130 disp_x_131 disp_x_132 disp_x_133 disp_x_134 disp_x_135 disp_x_136 disp_x_137 disp_x_138 disp_x_139 disp_x_140 disp_x_141 disp_x_142 disp_x_143 disp_x_144 disp_x_145 disp_x_146 disp_x_147 disp_x_148 disp_x_149 disp_x_150 disp_x_151 disp_x_152 disp_x_153 disp_x_154 disp_x_155 disp_x_156 disp_x_157 disp_x_158 disp_x_159 disp_x_160 disp_x_161 disp_x_162 disp_x_163 disp_x_164 disp_x_165 disp_x_166 disp_x_167 disp_x_168 disp_x_169 disp_x_170 disp_x_171 disp_x_172 disp_x_173 disp_x_174 disp_x_175 disp_x_176 disp_x_177 disp_x_178 disp_x_179 disp_x_180 disp_x_181 disp_x_182 disp_x_183 disp_x_184 disp_x_185 disp_x_186 disp_x_187 disp_x_188 disp_x_189 disp_x_190 disp_x_191 disp_x_192 disp_x_193 disp_x_194 disp_x_195 disp_x_196 disp_x_197 disp_x_198 disp_x_199 disp_x_200 disp_x_201 disp_x_202 disp_x_203 disp_x_204 disp_x_205 disp_x_206 disp_x_207 disp_x_208 disp_x_209 disp_x_210 disp_x_211 disp_x_212 disp_x_213 disp_x_214 disp_x_215 disp_x_216 disp_x_217 disp_x_218 disp_x_219 disp_x_220 disp_x_221 disp_x_222 disp_x_223 disp_x_224 disp_x_225 disp_x_226 disp_x_227 disp_x_228 disp_x_229 disp_x_230 disp_x_231 disp_x_232 disp_x_233 disp_x_234 disp_x_235 disp_x_236 disp_x_237 disp_x_238 disp_x_239 disp_x_240 disp_x_241 disp_x_242 disp_x_243 disp_x_244 disp_x_245 disp_x_246 disp_x_247 disp_x_248 disp_x_249 disp_x_250 disp_x_251 disp_x_252 disp_x_253 disp_x_254 disp_x_255 disp_x_256 disp_x_257 disp_x_258 disp_x_259 disp_x_260 disp_x_261 disp_x_262 disp_x_263 disp_x_264 disp_x_265 disp_x_266 disp_x_267 disp_x_268 disp_x_269 disp_x_270 disp_x_271 disp_x_272 disp_x_273 disp_x_274 disp_x_275 disp_x_276 disp_x_277 disp_x_278 disp_x_279 disp_x_280 disp_x_281 disp_x_282 disp_x_283 disp_x_284 disp_x_285 disp_x_286 disp_x_287 disp_x_288 disp_x_289 disp_x_290 disp_x_291 disp_x_292 disp_x_293 disp_x_294 disp_x_295 disp_x_296 disp_x_297 disp_x_298 disp_x_299 disp_x_300 disp_x_301 disp_x_302 disp_x_303 disp_x_304 disp_x_305 disp_x_306 disp_x_307 disp_x_308 disp_x_309 disp_x_310 disp_x_311 disp_x_312 disp_x_313 disp_x_314 disp_x_315 disp_x_316 disp_x_317 disp_x_318 disp_x_319 disp_x_320 disp_x_321 disp_x_322 disp_x_323 disp_x_324 disp_x_325 disp_x_326 disp_x_327 disp_x_328 disp_x_329 disp_x_330 disp_x_331 disp_x_332 disp_x_333 disp_x_334 disp_x_335 disp_x_336 disp_x_337 disp_x_338 disp_x_339 disp_x_340 disp_x_341 disp_x_342 disp_x_343 disp_x_344 disp_x_345 disp_x_346 disp_x_347 disp_x_348 disp_x_349 disp_x_350 disp_x_351 disp_x_352 disp_x_353 disp_x_354 disp_x_355 disp_x_356 disp_x_357 disp_x_358 disp_x_359 disp_x_360 disp_x_361 disp_x_362 disp_x_363 disp_x_364 disp_x_365 disp_x_366 disp_x_367 disp_x_368 disp_x_369 disp_x_370 disp_x_371 disp_x_372 disp_x_373 disp_x_374 disp_x_375 disp_x_376 disp_x_377 disp_x_378 disp_x_379 disp_x_380 disp_x_381 disp_x_382 disp_x_383 disp_x_384 disp_x_385 disp_x_386 disp_x_387 disp_x_388 disp_x_389 disp_x_390 disp_x_391 disp_x_392 disp_x_393 disp_x_394 disp_x_395 disp_x_396 disp_x_397 disp_x_398 disp_x_399 disp_x_400 disp_x_401 disp_x_402 disp_x_403 disp_x_404 disp_x_405 disp_x_406 disp_x_407 disp_x_408 disp_x_409 disp_x_410 disp_x_411 disp_x_412 disp_x_413 disp_x_414 disp_x_415 disp_x_416 disp_x_417 disp_x_418 disp_x_419 disp_x_420 disp_x_421 disp_x_422 disp_x_423 disp_x_424 disp_x_425 disp_x_426 disp_x_427 disp_x_428 disp_x_429 disp_x_430 disp_x_431 disp_x_432 disp_x_433 disp_x_434 disp_x_435 disp_x_436 disp_x_437 disp_x_438 disp_x_439 disp_x_440 disp_x_441 disp_x_442 disp_x_443 disp_x_444 disp_x_445 disp_x_446 disp_x_447 disp_x_448 disp_x_449 disp_x_450 disp_x_451 disp_x_452 disp_x_453 disp_x_454 disp_x_455 disp_x_456 disp_x_457 disp_x_458 disp_x_459 disp_x_460 disp_x_461 disp_x_462 disp_x_463 disp_x_464 disp_x_465 disp_x_466 disp_x_467 disp_x_468 disp_x_469 disp_x_470 disp_x_471 disp_x_472 disp_x_473 disp_x_474 disp_x_475 disp_x_476 disp_x_477 disp_x_478 disp_x_479 disp_x_480 lagrange_0 lagrange_1 lagrange_2 lagrange_3 lagrange_4 lagrange_5 lagrange_6 lagrange_7 lagrange_8 lagrange_9 lagrange_10 lagrange_11 lagrange_12 lagrange_13 lagrange_14 lagrange_15 lagrange_16 lagrange_17 lagrange_18 lagrange_19 lagrange_20 lagrange_21 lagrange_22 lagrange_23 lagrange_24 lagrange_25 lagrange_26 lagrange_27 lagrange_28 lagrange_29 lagrange_30 lagrange_31 lagrange_32 lagrange_33 lagrange_34 lagrange_35 lagrange_36 lagrange_37 lagrange_38 lagrange_39 lagrange_40 lagrange_41 lagrange_42 lagrange_43 lagrange_44 lagrange_45 lagrange_46 lagrange_47 lagrange_48 lagrange_49 lagrange_50 lagrange_51 lagrange_52 lagrange_53 lagrange_54 lagrange_55 lagrange_56 lagrange_57 lagrange_58 lagrange_59 lagrange_60 lagrange_61 lagrange_62 lagrange_63 lagrange_64 lagrange_65 lagrange_66 lagrange_67 lagrange_68 lagrange_69 lagrange_70 lagrange_71 lagrange_72 lagrange_73 lagrange_74 lagrange_75 lagrange_76 lagrange_77 lagrange_78 lagrange_79 lagrange_80 lagrange_81 lagrange_82 lagrange_83 lagrange_84 lagrange_85 lagrange_86 lagrange_87 lagrange_88 lagrange_89 lagrange_90 lagrange_91 lagrange_92 lagrange_93 lagrange_94 lagrange_95 lagrange_96 lagrange_97 lagrange_98 lagrange_99 lagrange_100 lagrange_101 lagrange_102 lagrange_103 lagrange_104 lagrange_105 lagrange_106 lagrange_107 lagrange_108 lagrange_109 lagrange_110 lagrange_111 lagrange_112 lagrange_113 lagrange_114 lagrange_115 lagrange_116 lagrange_117 lagrange_118 lagrange_119 lagrange_120 lagrange_121 lagrange_122 lagrange_123 lagrange_124 lagrange_125 lagrange_126 lagrange_127 lagrange_128 lagrange_129 lagrange_130 lagrange_131 lagrange_132 lagrange_133 lagrange_134 lagrange_135 lagrange_136 lagrange_137 lagrange_138 lagrange_139 lagrange_140 lagrange_141 lagrange_142 lagrange_143 lagrange_144 lagrange_145 lagrange_146 lagrange_147 lagrange_148 lagrange_149 lagrange_150 lagrange_151 lagrange_152 lagrange_153 lagrange_154 lagrange_155 lagrange_156 lagrange_157 lagrange_158 lagrange_159 lagrange_160 lagrange_161 lagrange_162 lagrange_163 lagrange_164 lagrange_165 lagrange_166 lagrange_167 lagrange_168 lagrange_169 lagrange_170 lagrange_171 lagrange_172 lagrange_173 lagrange_174 lagrange_175 lagrange_176 lagrange_177 lagrange_178 lagrange_179 lagrange_180 lagrange_181 lagrange_182 lagrange_183 lagrange_184 lagrange_185 lagrange_186 lagrange_187 lagrange_188 lagrange_189 lagrange_190 lagrange_191 lagrange_192 lagrange_193 lagrange_194 lagrange_195 lagrange_196 lagrange_197 lagrange_198 lagrange_199 lagrange_200 lagrange_201 lagrange_202 lagrange_203 lagrange_204 lagrange_205 lagrange_206 lagrange_207 lagrange_208 lagrange_209 lagrange_210 lagrange_211 lagrange_212 lagrange_213 lagrange_214 lagrange_215 lagrange_216 lagrange_217 lagrange_218 lagrange_219 lagrange_220 lagrange_221 lagrange_222 lagrange_223 lagrange_224 lagrange_225 lagrange_226 lagrange_227 lagrange_228 lagrange_229 lagrange_230 lagrange_231 lagrange_232 lagrange_233 lagrange_234 lagrange_235 lagrange_236 lagrange_237 lagrange_238 lagrange_239 lagrange_240 lagrange_241 lagrange_242 lagrange_243 lagrange_244 lagrange_245 lagrange_246 lagrange_247 lagrange_248 lagrange_249 lagrange_250 lagrange_251 lagrange_252 lagrange_253 lagrange_254 lagrange_255 lagrange_256 lagrange_257 lagrange_258 lagrange_259 lagrange_260 lagrange_261 lagrange_262 lagrange_263 lagrange_264 lagrange_265 lagrange_266 lagrange_267 lagrange_268 lagrange_269 lagrange_270 lagrange_271 lagrange_272 lagrange_273 lagrange_274 lagrange_275 lagrange_276 lagrange_277 lagrange_278 lagrange_279 lagrange_280 lagrange_281 lagrange_282 lagrange_283 lagrange_284 lagrange_285 lagrange_286 lagrange_287 lagrange_288 lagrange_289 lagrange_290 lagrange_291 lagrange_292 lagrange_293 lagrange_294 lagrange_295 lagrange_296 lagrange_297 lagrange_298 lagrange_299 lagrange_300 lagrange_301 lagrange_302 lagrange_303 lagrange_304 lagrange_305 lagrange_306 lagrange_307 lagrange_308 lagrange_309 lagrange_310 lagrange_311 lagrange_312 lagrange_313 lagrange_314 lagrange_315 lagrange_316 lagrange_317 lagrange_318 lagrange_319 lagrange_320 lagrange_321 lagrange_322 lagrange_323 lagrange_324 lagrange_325 lagrange_326 lagrange_327 lagrange_328 lagrange_329 lagrange_330 lagrange_331 lagrange_332 lagrange_333 lagrange_334 lagrange_335 lagrange_336 lagrange_337 lagrange_338 lagrange_339 lagrange_340 lagrange_341 lagrange_342 lagrange_343 lagrange_344 lagrange_345 lagrange_346 lagrange_347 lagrange_348 lagrange_349 lagrange_350 lagrange_351 lagrange_352 lagrange_353 lagrange_354 lagrange_355 lagrange_356 lagrange_357 lagrange_358 lagrange_359 lagrange_360 lagrange_361 lagrange_362 lagrange_363 lagrange_364 lagrange_365 lagrange_366 lagrange_367 lagrange_368 lagrange_369 lagrange_370 lagrange_371 lagrange_372 lagrange_373 lagrange_374 lagrange_375 lagrange_376 lagrange_377 lagrange_378 lagrange_379 lagrange_380 lagrange_381 lagrange_382 lagrange_383 lagrange_384 lagrange_385 lagrange_386 lagrange_387 lagrange_388 lagrange_389 lagrange_390 lagrange_391 lagrange_392 lagrange_393 lagrange_394 lagrange_395 lagrange_396 lagrange_397 lagrange_398 lagrange_399 lagrange_400 lagrange_401 lagrange_402 lagrange_403 lagrange_404 lagrange_405 lagrange_406 lagrange_407 lagrange_408 lagrange_409 lagrange_410 lagrange_411 lagrange_412 lagrange_413 lagrange_414 lagrange_415 lagrange_416 lagrange_417 lagrange_418 lagrange_419 lagrange_420 lagrange_421 lagrange_422 lagrange_423 lagrange_424 lagrange_425 lagrange_426 lagrange_427 lagrange_428 lagrange_429 lagrange_430 lagrange_431 lagrange_432 lagrange_433 lagrange_434 lagrange_435 lagrange_436 lagrange_437 lagrange_438 lagrange_439 lagrange_440 lagrange_441 lagrange_442 lagrange_443 lagrange_444 lagrange_445 lagrange_446 lagrange_447 lagrange_448 lagrange_449 lagrange_450 lagrange_451 lagrange_452 lagrange_453 lagrange_454 lagrange_455 lagrange_456 lagrange_457 lagrange_458 lagrange_459 lagrange_460 lagrange_461 lagrange_462 lagrange_463 lagrange_464 lagrange_465 lagrange_466 lagrange_467 lagrange_468 lagrange_469 lagrange_470 lagrange_471 lagrange_472 lagrange_473 lagrange_474 lagrange_475 lagrange_476 lagrange_477 lagrange_478 lagrange_479'
  [./disp_x_0]
    type = PointValue
    point = '0.0 0.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_1]
    type = PointValue
    point = '0.0 0.0104166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_2]
    type = PointValue
    point = '0.0 0.0208333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_3]
    type = PointValue
    point = '0.0 0.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_4]
    type = PointValue
    point = '0.0 0.0416666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_5]
    type = PointValue
    point = '0.0 0.0520833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_6]
    type = PointValue
    point = '0.0 0.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_7]
    type = PointValue
    point = '0.0 0.0729166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_8]
    type = PointValue
    point = '0.0 0.0833333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_9]
    type = PointValue
    point = '0.0 0.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_10]
    type = PointValue
    point = '0.0 0.104166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_11]
    type = PointValue
    point = '0.0 0.114583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_12]
    type = PointValue
    point = '0.0 0.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_13]
    type = PointValue
    point = '0.0 0.135416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_14]
    type = PointValue
    point = '0.0 0.145833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_15]
    type = PointValue
    point = '0.0 0.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_16]
    type = PointValue
    point = '0.0 0.166666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_17]
    type = PointValue
    point = '0.0 0.177083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_18]
    type = PointValue
    point = '0.0 0.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_19]
    type = PointValue
    point = '0.0 0.197916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_20]
    type = PointValue
    point = '0.0 0.208333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_21]
    type = PointValue
    point = '0.0 0.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_22]
    type = PointValue
    point = '0.0 0.229166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_23]
    type = PointValue
    point = '0.0 0.239583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_24]
    type = PointValue
    point = '0.0 0.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_25]
    type = PointValue
    point = '0.0 0.260416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_26]
    type = PointValue
    point = '0.0 0.270833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_27]
    type = PointValue
    point = '0.0 0.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_28]
    type = PointValue
    point = '0.0 0.291666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_29]
    type = PointValue
    point = '0.0 0.302083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_30]
    type = PointValue
    point = '0.0 0.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_31]
    type = PointValue
    point = '0.0 0.322916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_32]
    type = PointValue
    point = '0.0 0.333333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_33]
    type = PointValue
    point = '0.0 0.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_34]
    type = PointValue
    point = '0.0 0.354166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_35]
    type = PointValue
    point = '0.0 0.364583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_36]
    type = PointValue
    point = '0.0 0.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_37]
    type = PointValue
    point = '0.0 0.385416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_38]
    type = PointValue
    point = '0.0 0.395833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_39]
    type = PointValue
    point = '0.0 0.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_40]
    type = PointValue
    point = '0.0 0.416666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_41]
    type = PointValue
    point = '0.0 0.427083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_42]
    type = PointValue
    point = '0.0 0.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_43]
    type = PointValue
    point = '0.0 0.447916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_44]
    type = PointValue
    point = '0.0 0.458333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_45]
    type = PointValue
    point = '0.0 0.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_46]
    type = PointValue
    point = '0.0 0.479166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_47]
    type = PointValue
    point = '0.0 0.489583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_48]
    type = PointValue
    point = '0.0 0.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_49]
    type = PointValue
    point = '0.0 0.510416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_50]
    type = PointValue
    point = '0.0 0.520833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_51]
    type = PointValue
    point = '0.0 0.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_52]
    type = PointValue
    point = '0.0 0.541666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_53]
    type = PointValue
    point = '0.0 0.552083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_54]
    type = PointValue
    point = '0.0 0.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_55]
    type = PointValue
    point = '0.0 0.572916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_56]
    type = PointValue
    point = '0.0 0.583333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_57]
    type = PointValue
    point = '0.0 0.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_58]
    type = PointValue
    point = '0.0 0.604166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_59]
    type = PointValue
    point = '0.0 0.614583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_60]
    type = PointValue
    point = '0.0 0.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_61]
    type = PointValue
    point = '0.0 0.635416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_62]
    type = PointValue
    point = '0.0 0.645833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_63]
    type = PointValue
    point = '0.0 0.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_64]
    type = PointValue
    point = '0.0 0.666666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_65]
    type = PointValue
    point = '0.0 0.677083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_66]
    type = PointValue
    point = '0.0 0.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_67]
    type = PointValue
    point = '0.0 0.697916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_68]
    type = PointValue
    point = '0.0 0.708333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_69]
    type = PointValue
    point = '0.0 0.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_70]
    type = PointValue
    point = '0.0 0.729166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_71]
    type = PointValue
    point = '0.0 0.739583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_72]
    type = PointValue
    point = '0.0 0.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_73]
    type = PointValue
    point = '0.0 0.760416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_74]
    type = PointValue
    point = '0.0 0.770833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_75]
    type = PointValue
    point = '0.0 0.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_76]
    type = PointValue
    point = '0.0 0.791666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_77]
    type = PointValue
    point = '0.0 0.802083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_78]
    type = PointValue
    point = '0.0 0.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_79]
    type = PointValue
    point = '0.0 0.822916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_80]
    type = PointValue
    point = '0.0 0.833333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_81]
    type = PointValue
    point = '0.0 0.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_82]
    type = PointValue
    point = '0.0 0.854166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_83]
    type = PointValue
    point = '0.0 0.864583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_84]
    type = PointValue
    point = '0.0 0.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_85]
    type = PointValue
    point = '0.0 0.885416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_86]
    type = PointValue
    point = '0.0 0.895833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_87]
    type = PointValue
    point = '0.0 0.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_88]
    type = PointValue
    point = '0.0 0.916666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_89]
    type = PointValue
    point = '0.0 0.927083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_90]
    type = PointValue
    point = '0.0 0.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_91]
    type = PointValue
    point = '0.0 0.947916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_92]
    type = PointValue
    point = '0.0 0.958333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_93]
    type = PointValue
    point = '0.0 0.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_94]
    type = PointValue
    point = '0.0 0.979166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_95]
    type = PointValue
    point = '0.0 0.989583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_96]
    type = PointValue
    point = '0.0 1.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_97]
    type = PointValue
    point = '0.0 1.01041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_98]
    type = PointValue
    point = '0.0 1.02083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_99]
    type = PointValue
    point = '0.0 1.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_100]
    type = PointValue
    point = '0.0 1.04166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_101]
    type = PointValue
    point = '0.0 1.05208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_102]
    type = PointValue
    point = '0.0 1.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_103]
    type = PointValue
    point = '0.0 1.07291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_104]
    type = PointValue
    point = '0.0 1.08333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_105]
    type = PointValue
    point = '0.0 1.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_106]
    type = PointValue
    point = '0.0 1.10416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_107]
    type = PointValue
    point = '0.0 1.11458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_108]
    type = PointValue
    point = '0.0 1.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_109]
    type = PointValue
    point = '0.0 1.13541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_110]
    type = PointValue
    point = '0.0 1.14583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_111]
    type = PointValue
    point = '0.0 1.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_112]
    type = PointValue
    point = '0.0 1.16666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_113]
    type = PointValue
    point = '0.0 1.17708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_114]
    type = PointValue
    point = '0.0 1.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_115]
    type = PointValue
    point = '0.0 1.19791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_116]
    type = PointValue
    point = '0.0 1.20833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_117]
    type = PointValue
    point = '0.0 1.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_118]
    type = PointValue
    point = '0.0 1.22916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_119]
    type = PointValue
    point = '0.0 1.23958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_120]
    type = PointValue
    point = '0.0 1.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_121]
    type = PointValue
    point = '0.0 1.26041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_122]
    type = PointValue
    point = '0.0 1.27083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_123]
    type = PointValue
    point = '0.0 1.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_124]
    type = PointValue
    point = '0.0 1.29166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_125]
    type = PointValue
    point = '0.0 1.30208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_126]
    type = PointValue
    point = '0.0 1.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_127]
    type = PointValue
    point = '0.0 1.32291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_128]
    type = PointValue
    point = '0.0 1.33333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_129]
    type = PointValue
    point = '0.0 1.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_130]
    type = PointValue
    point = '0.0 1.35416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_131]
    type = PointValue
    point = '0.0 1.36458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_132]
    type = PointValue
    point = '0.0 1.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_133]
    type = PointValue
    point = '0.0 1.38541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_134]
    type = PointValue
    point = '0.0 1.39583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_135]
    type = PointValue
    point = '0.0 1.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_136]
    type = PointValue
    point = '0.0 1.41666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_137]
    type = PointValue
    point = '0.0 1.42708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_138]
    type = PointValue
    point = '0.0 1.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_139]
    type = PointValue
    point = '0.0 1.44791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_140]
    type = PointValue
    point = '0.0 1.45833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_141]
    type = PointValue
    point = '0.0 1.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_142]
    type = PointValue
    point = '0.0 1.47916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_143]
    type = PointValue
    point = '0.0 1.48958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_144]
    type = PointValue
    point = '0.0 1.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_145]
    type = PointValue
    point = '0.0 1.51041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_146]
    type = PointValue
    point = '0.0 1.52083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_147]
    type = PointValue
    point = '0.0 1.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_148]
    type = PointValue
    point = '0.0 1.54166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_149]
    type = PointValue
    point = '0.0 1.55208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_150]
    type = PointValue
    point = '0.0 1.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_151]
    type = PointValue
    point = '0.0 1.57291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_152]
    type = PointValue
    point = '0.0 1.58333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_153]
    type = PointValue
    point = '0.0 1.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_154]
    type = PointValue
    point = '0.0 1.60416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_155]
    type = PointValue
    point = '0.0 1.61458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_156]
    type = PointValue
    point = '0.0 1.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_157]
    type = PointValue
    point = '0.0 1.63541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_158]
    type = PointValue
    point = '0.0 1.64583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_159]
    type = PointValue
    point = '0.0 1.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_160]
    type = PointValue
    point = '0.0 1.66666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_161]
    type = PointValue
    point = '0.0 1.67708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_162]
    type = PointValue
    point = '0.0 1.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_163]
    type = PointValue
    point = '0.0 1.69791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_164]
    type = PointValue
    point = '0.0 1.70833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_165]
    type = PointValue
    point = '0.0 1.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_166]
    type = PointValue
    point = '0.0 1.72916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_167]
    type = PointValue
    point = '0.0 1.73958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_168]
    type = PointValue
    point = '0.0 1.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_169]
    type = PointValue
    point = '0.0 1.76041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_170]
    type = PointValue
    point = '0.0 1.77083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_171]
    type = PointValue
    point = '0.0 1.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_172]
    type = PointValue
    point = '0.0 1.79166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_173]
    type = PointValue
    point = '0.0 1.80208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_174]
    type = PointValue
    point = '0.0 1.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_175]
    type = PointValue
    point = '0.0 1.82291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_176]
    type = PointValue
    point = '0.0 1.83333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_177]
    type = PointValue
    point = '0.0 1.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_178]
    type = PointValue
    point = '0.0 1.85416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_179]
    type = PointValue
    point = '0.0 1.86458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_180]
    type = PointValue
    point = '0.0 1.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_181]
    type = PointValue
    point = '0.0 1.88541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_182]
    type = PointValue
    point = '0.0 1.89583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_183]
    type = PointValue
    point = '0.0 1.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_184]
    type = PointValue
    point = '0.0 1.91666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_185]
    type = PointValue
    point = '0.0 1.92708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_186]
    type = PointValue
    point = '0.0 1.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_187]
    type = PointValue
    point = '0.0 1.94791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_188]
    type = PointValue
    point = '0.0 1.95833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_189]
    type = PointValue
    point = '0.0 1.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_190]
    type = PointValue
    point = '0.0 1.97916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_191]
    type = PointValue
    point = '0.0 1.98958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_192]
    type = PointValue
    point = '0.0 2.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_193]
    type = PointValue
    point = '0.0 2.01041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_194]
    type = PointValue
    point = '0.0 2.02083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_195]
    type = PointValue
    point = '0.0 2.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_196]
    type = PointValue
    point = '0.0 2.04166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_197]
    type = PointValue
    point = '0.0 2.05208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_198]
    type = PointValue
    point = '0.0 2.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_199]
    type = PointValue
    point = '0.0 2.07291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_200]
    type = PointValue
    point = '0.0 2.08333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_201]
    type = PointValue
    point = '0.0 2.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_202]
    type = PointValue
    point = '0.0 2.10416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_203]
    type = PointValue
    point = '0.0 2.11458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_204]
    type = PointValue
    point = '0.0 2.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_205]
    type = PointValue
    point = '0.0 2.13541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_206]
    type = PointValue
    point = '0.0 2.14583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_207]
    type = PointValue
    point = '0.0 2.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_208]
    type = PointValue
    point = '0.0 2.16666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_209]
    type = PointValue
    point = '0.0 2.17708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_210]
    type = PointValue
    point = '0.0 2.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_211]
    type = PointValue
    point = '0.0 2.19791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_212]
    type = PointValue
    point = '0.0 2.20833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_213]
    type = PointValue
    point = '0.0 2.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_214]
    type = PointValue
    point = '0.0 2.22916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_215]
    type = PointValue
    point = '0.0 2.23958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_216]
    type = PointValue
    point = '0.0 2.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_217]
    type = PointValue
    point = '0.0 2.26041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_218]
    type = PointValue
    point = '0.0 2.27083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_219]
    type = PointValue
    point = '0.0 2.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_220]
    type = PointValue
    point = '0.0 2.29166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_221]
    type = PointValue
    point = '0.0 2.30208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_222]
    type = PointValue
    point = '0.0 2.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_223]
    type = PointValue
    point = '0.0 2.32291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_224]
    type = PointValue
    point = '0.0 2.33333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_225]
    type = PointValue
    point = '0.0 2.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_226]
    type = PointValue
    point = '0.0 2.35416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_227]
    type = PointValue
    point = '0.0 2.36458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_228]
    type = PointValue
    point = '0.0 2.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_229]
    type = PointValue
    point = '0.0 2.38541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_230]
    type = PointValue
    point = '0.0 2.39583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_231]
    type = PointValue
    point = '0.0 2.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_232]
    type = PointValue
    point = '0.0 2.41666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_233]
    type = PointValue
    point = '0.0 2.42708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_234]
    type = PointValue
    point = '0.0 2.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_235]
    type = PointValue
    point = '0.0 2.44791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_236]
    type = PointValue
    point = '0.0 2.45833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_237]
    type = PointValue
    point = '0.0 2.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_238]
    type = PointValue
    point = '0.0 2.47916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_239]
    type = PointValue
    point = '0.0 2.48958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_240]
    type = PointValue
    point = '0.0 2.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_241]
    type = PointValue
    point = '0.0 2.51041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_242]
    type = PointValue
    point = '0.0 2.52083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_243]
    type = PointValue
    point = '0.0 2.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_244]
    type = PointValue
    point = '0.0 2.54166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_245]
    type = PointValue
    point = '0.0 2.55208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_246]
    type = PointValue
    point = '0.0 2.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_247]
    type = PointValue
    point = '0.0 2.57291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_248]
    type = PointValue
    point = '0.0 2.58333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_249]
    type = PointValue
    point = '0.0 2.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_250]
    type = PointValue
    point = '0.0 2.60416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_251]
    type = PointValue
    point = '0.0 2.61458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_252]
    type = PointValue
    point = '0.0 2.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_253]
    type = PointValue
    point = '0.0 2.63541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_254]
    type = PointValue
    point = '0.0 2.64583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_255]
    type = PointValue
    point = '0.0 2.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_256]
    type = PointValue
    point = '0.0 2.66666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_257]
    type = PointValue
    point = '0.0 2.67708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_258]
    type = PointValue
    point = '0.0 2.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_259]
    type = PointValue
    point = '0.0 2.69791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_260]
    type = PointValue
    point = '0.0 2.70833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_261]
    type = PointValue
    point = '0.0 2.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_262]
    type = PointValue
    point = '0.0 2.72916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_263]
    type = PointValue
    point = '0.0 2.73958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_264]
    type = PointValue
    point = '0.0 2.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_265]
    type = PointValue
    point = '0.0 2.76041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_266]
    type = PointValue
    point = '0.0 2.77083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_267]
    type = PointValue
    point = '0.0 2.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_268]
    type = PointValue
    point = '0.0 2.79166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_269]
    type = PointValue
    point = '0.0 2.80208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_270]
    type = PointValue
    point = '0.0 2.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_271]
    type = PointValue
    point = '0.0 2.82291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_272]
    type = PointValue
    point = '0.0 2.83333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_273]
    type = PointValue
    point = '0.0 2.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_274]
    type = PointValue
    point = '0.0 2.85416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_275]
    type = PointValue
    point = '0.0 2.86458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_276]
    type = PointValue
    point = '0.0 2.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_277]
    type = PointValue
    point = '0.0 2.88541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_278]
    type = PointValue
    point = '0.0 2.89583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_279]
    type = PointValue
    point = '0.0 2.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_280]
    type = PointValue
    point = '0.0 2.91666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_281]
    type = PointValue
    point = '0.0 2.92708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_282]
    type = PointValue
    point = '0.0 2.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_283]
    type = PointValue
    point = '0.0 2.94791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_284]
    type = PointValue
    point = '0.0 2.95833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_285]
    type = PointValue
    point = '0.0 2.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_286]
    type = PointValue
    point = '0.0 2.97916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_287]
    type = PointValue
    point = '0.0 2.98958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_288]
    type = PointValue
    point = '0.0 3.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_289]
    type = PointValue
    point = '0.0 3.01041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_290]
    type = PointValue
    point = '0.0 3.02083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_291]
    type = PointValue
    point = '0.0 3.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_292]
    type = PointValue
    point = '0.0 3.04166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_293]
    type = PointValue
    point = '0.0 3.05208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_294]
    type = PointValue
    point = '0.0 3.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_295]
    type = PointValue
    point = '0.0 3.07291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_296]
    type = PointValue
    point = '0.0 3.08333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_297]
    type = PointValue
    point = '0.0 3.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_298]
    type = PointValue
    point = '0.0 3.10416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_299]
    type = PointValue
    point = '0.0 3.11458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_300]
    type = PointValue
    point = '0.0 3.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_301]
    type = PointValue
    point = '0.0 3.13541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_302]
    type = PointValue
    point = '0.0 3.14583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_303]
    type = PointValue
    point = '0.0 3.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_304]
    type = PointValue
    point = '0.0 3.16666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_305]
    type = PointValue
    point = '0.0 3.17708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_306]
    type = PointValue
    point = '0.0 3.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_307]
    type = PointValue
    point = '0.0 3.19791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_308]
    type = PointValue
    point = '0.0 3.20833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_309]
    type = PointValue
    point = '0.0 3.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_310]
    type = PointValue
    point = '0.0 3.22916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_311]
    type = PointValue
    point = '0.0 3.23958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_312]
    type = PointValue
    point = '0.0 3.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_313]
    type = PointValue
    point = '0.0 3.26041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_314]
    type = PointValue
    point = '0.0 3.27083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_315]
    type = PointValue
    point = '0.0 3.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_316]
    type = PointValue
    point = '0.0 3.29166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_317]
    type = PointValue
    point = '0.0 3.30208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_318]
    type = PointValue
    point = '0.0 3.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_319]
    type = PointValue
    point = '0.0 3.32291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_320]
    type = PointValue
    point = '0.0 3.33333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_321]
    type = PointValue
    point = '0.0 3.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_322]
    type = PointValue
    point = '0.0 3.35416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_323]
    type = PointValue
    point = '0.0 3.36458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_324]
    type = PointValue
    point = '0.0 3.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_325]
    type = PointValue
    point = '0.0 3.38541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_326]
    type = PointValue
    point = '0.0 3.39583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_327]
    type = PointValue
    point = '0.0 3.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_328]
    type = PointValue
    point = '0.0 3.41666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_329]
    type = PointValue
    point = '0.0 3.42708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_330]
    type = PointValue
    point = '0.0 3.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_331]
    type = PointValue
    point = '0.0 3.44791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_332]
    type = PointValue
    point = '0.0 3.45833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_333]
    type = PointValue
    point = '0.0 3.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_334]
    type = PointValue
    point = '0.0 3.47916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_335]
    type = PointValue
    point = '0.0 3.48958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_336]
    type = PointValue
    point = '0.0 3.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_337]
    type = PointValue
    point = '0.0 3.51041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_338]
    type = PointValue
    point = '0.0 3.52083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_339]
    type = PointValue
    point = '0.0 3.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_340]
    type = PointValue
    point = '0.0 3.54166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_341]
    type = PointValue
    point = '0.0 3.55208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_342]
    type = PointValue
    point = '0.0 3.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_343]
    type = PointValue
    point = '0.0 3.57291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_344]
    type = PointValue
    point = '0.0 3.58333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_345]
    type = PointValue
    point = '0.0 3.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_346]
    type = PointValue
    point = '0.0 3.60416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_347]
    type = PointValue
    point = '0.0 3.61458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_348]
    type = PointValue
    point = '0.0 3.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_349]
    type = PointValue
    point = '0.0 3.63541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_350]
    type = PointValue
    point = '0.0 3.64583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_351]
    type = PointValue
    point = '0.0 3.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_352]
    type = PointValue
    point = '0.0 3.66666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_353]
    type = PointValue
    point = '0.0 3.67708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_354]
    type = PointValue
    point = '0.0 3.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_355]
    type = PointValue
    point = '0.0 3.69791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_356]
    type = PointValue
    point = '0.0 3.70833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_357]
    type = PointValue
    point = '0.0 3.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_358]
    type = PointValue
    point = '0.0 3.72916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_359]
    type = PointValue
    point = '0.0 3.73958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_360]
    type = PointValue
    point = '0.0 3.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_361]
    type = PointValue
    point = '0.0 3.76041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_362]
    type = PointValue
    point = '0.0 3.77083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_363]
    type = PointValue
    point = '0.0 3.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_364]
    type = PointValue
    point = '0.0 3.79166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_365]
    type = PointValue
    point = '0.0 3.80208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_366]
    type = PointValue
    point = '0.0 3.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_367]
    type = PointValue
    point = '0.0 3.82291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_368]
    type = PointValue
    point = '0.0 3.83333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_369]
    type = PointValue
    point = '0.0 3.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_370]
    type = PointValue
    point = '0.0 3.85416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_371]
    type = PointValue
    point = '0.0 3.86458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_372]
    type = PointValue
    point = '0.0 3.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_373]
    type = PointValue
    point = '0.0 3.88541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_374]
    type = PointValue
    point = '0.0 3.89583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_375]
    type = PointValue
    point = '0.0 3.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_376]
    type = PointValue
    point = '0.0 3.91666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_377]
    type = PointValue
    point = '0.0 3.92708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_378]
    type = PointValue
    point = '0.0 3.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_379]
    type = PointValue
    point = '0.0 3.94791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_380]
    type = PointValue
    point = '0.0 3.95833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_381]
    type = PointValue
    point = '0.0 3.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_382]
    type = PointValue
    point = '0.0 3.97916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_383]
    type = PointValue
    point = '0.0 3.98958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_384]
    type = PointValue
    point = '0.0 4.0 0.0'
    variable = disp_x
  [../]
  [./disp_x_385]
    type = PointValue
    point = '0.0 4.01041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_386]
    type = PointValue
    point = '0.0 4.02083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_387]
    type = PointValue
    point = '0.0 4.03125 0.0'
    variable = disp_x
  [../]
  [./disp_x_388]
    type = PointValue
    point = '0.0 4.04166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_389]
    type = PointValue
    point = '0.0 4.05208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_390]
    type = PointValue
    point = '0.0 4.0625 0.0'
    variable = disp_x
  [../]
  [./disp_x_391]
    type = PointValue
    point = '0.0 4.07291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_392]
    type = PointValue
    point = '0.0 4.08333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_393]
    type = PointValue
    point = '0.0 4.09375 0.0'
    variable = disp_x
  [../]
  [./disp_x_394]
    type = PointValue
    point = '0.0 4.10416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_395]
    type = PointValue
    point = '0.0 4.11458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_396]
    type = PointValue
    point = '0.0 4.125 0.0'
    variable = disp_x
  [../]
  [./disp_x_397]
    type = PointValue
    point = '0.0 4.13541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_398]
    type = PointValue
    point = '0.0 4.14583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_399]
    type = PointValue
    point = '0.0 4.15625 0.0'
    variable = disp_x
  [../]
  [./disp_x_400]
    type = PointValue
    point = '0.0 4.16666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_401]
    type = PointValue
    point = '0.0 4.17708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_402]
    type = PointValue
    point = '0.0 4.1875 0.0'
    variable = disp_x
  [../]
  [./disp_x_403]
    type = PointValue
    point = '0.0 4.19791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_404]
    type = PointValue
    point = '0.0 4.20833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_405]
    type = PointValue
    point = '0.0 4.21875 0.0'
    variable = disp_x
  [../]
  [./disp_x_406]
    type = PointValue
    point = '0.0 4.22916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_407]
    type = PointValue
    point = '0.0 4.23958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_408]
    type = PointValue
    point = '0.0 4.25 0.0'
    variable = disp_x
  [../]
  [./disp_x_409]
    type = PointValue
    point = '0.0 4.26041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_410]
    type = PointValue
    point = '0.0 4.27083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_411]
    type = PointValue
    point = '0.0 4.28125 0.0'
    variable = disp_x
  [../]
  [./disp_x_412]
    type = PointValue
    point = '0.0 4.29166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_413]
    type = PointValue
    point = '0.0 4.30208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_414]
    type = PointValue
    point = '0.0 4.3125 0.0'
    variable = disp_x
  [../]
  [./disp_x_415]
    type = PointValue
    point = '0.0 4.32291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_416]
    type = PointValue
    point = '0.0 4.33333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_417]
    type = PointValue
    point = '0.0 4.34375 0.0'
    variable = disp_x
  [../]
  [./disp_x_418]
    type = PointValue
    point = '0.0 4.35416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_419]
    type = PointValue
    point = '0.0 4.36458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_420]
    type = PointValue
    point = '0.0 4.375 0.0'
    variable = disp_x
  [../]
  [./disp_x_421]
    type = PointValue
    point = '0.0 4.38541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_422]
    type = PointValue
    point = '0.0 4.39583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_423]
    type = PointValue
    point = '0.0 4.40625 0.0'
    variable = disp_x
  [../]
  [./disp_x_424]
    type = PointValue
    point = '0.0 4.41666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_425]
    type = PointValue
    point = '0.0 4.42708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_426]
    type = PointValue
    point = '0.0 4.4375 0.0'
    variable = disp_x
  [../]
  [./disp_x_427]
    type = PointValue
    point = '0.0 4.44791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_428]
    type = PointValue
    point = '0.0 4.45833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_429]
    type = PointValue
    point = '0.0 4.46875 0.0'
    variable = disp_x
  [../]
  [./disp_x_430]
    type = PointValue
    point = '0.0 4.47916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_431]
    type = PointValue
    point = '0.0 4.48958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_432]
    type = PointValue
    point = '0.0 4.5 0.0'
    variable = disp_x
  [../]
  [./disp_x_433]
    type = PointValue
    point = '0.0 4.51041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_434]
    type = PointValue
    point = '0.0 4.52083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_435]
    type = PointValue
    point = '0.0 4.53125 0.0'
    variable = disp_x
  [../]
  [./disp_x_436]
    type = PointValue
    point = '0.0 4.54166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_437]
    type = PointValue
    point = '0.0 4.55208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_438]
    type = PointValue
    point = '0.0 4.5625 0.0'
    variable = disp_x
  [../]
  [./disp_x_439]
    type = PointValue
    point = '0.0 4.57291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_440]
    type = PointValue
    point = '0.0 4.58333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_441]
    type = PointValue
    point = '0.0 4.59375 0.0'
    variable = disp_x
  [../]
  [./disp_x_442]
    type = PointValue
    point = '0.0 4.60416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_443]
    type = PointValue
    point = '0.0 4.61458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_444]
    type = PointValue
    point = '0.0 4.625 0.0'
    variable = disp_x
  [../]
  [./disp_x_445]
    type = PointValue
    point = '0.0 4.63541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_446]
    type = PointValue
    point = '0.0 4.64583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_447]
    type = PointValue
    point = '0.0 4.65625 0.0'
    variable = disp_x
  [../]
  [./disp_x_448]
    type = PointValue
    point = '0.0 4.66666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_449]
    type = PointValue
    point = '0.0 4.67708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_450]
    type = PointValue
    point = '0.0 4.6875 0.0'
    variable = disp_x
  [../]
  [./disp_x_451]
    type = PointValue
    point = '0.0 4.69791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_452]
    type = PointValue
    point = '0.0 4.70833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_453]
    type = PointValue
    point = '0.0 4.71875 0.0'
    variable = disp_x
  [../]
  [./disp_x_454]
    type = PointValue
    point = '0.0 4.72916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_455]
    type = PointValue
    point = '0.0 4.73958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_456]
    type = PointValue
    point = '0.0 4.75 0.0'
    variable = disp_x
  [../]
  [./disp_x_457]
    type = PointValue
    point = '0.0 4.76041666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_458]
    type = PointValue
    point = '0.0 4.77083333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_459]
    type = PointValue
    point = '0.0 4.78125 0.0'
    variable = disp_x
  [../]
  [./disp_x_460]
    type = PointValue
    point = '0.0 4.79166666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_461]
    type = PointValue
    point = '0.0 4.80208333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_462]
    type = PointValue
    point = '0.0 4.8125 0.0'
    variable = disp_x
  [../]
  [./disp_x_463]
    type = PointValue
    point = '0.0 4.82291666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_464]
    type = PointValue
    point = '0.0 4.83333333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_465]
    type = PointValue
    point = '0.0 4.84375 0.0'
    variable = disp_x
  [../]
  [./disp_x_466]
    type = PointValue
    point = '0.0 4.85416666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_467]
    type = PointValue
    point = '0.0 4.86458333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_468]
    type = PointValue
    point = '0.0 4.875 0.0'
    variable = disp_x
  [../]
  [./disp_x_469]
    type = PointValue
    point = '0.0 4.88541666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_470]
    type = PointValue
    point = '0.0 4.89583333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_471]
    type = PointValue
    point = '0.0 4.90625 0.0'
    variable = disp_x
  [../]
  [./disp_x_472]
    type = PointValue
    point = '0.0 4.91666666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_473]
    type = PointValue
    point = '0.0 4.92708333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_474]
    type = PointValue
    point = '0.0 4.9375 0.0'
    variable = disp_x
  [../]
  [./disp_x_475]
    type = PointValue
    point = '0.0 4.94791666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_476]
    type = PointValue
    point = '0.0 4.95833333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_477]
    type = PointValue
    point = '0.0 4.96875 0.0'
    variable = disp_x
  [../]
  [./disp_x_478]
    type = PointValue
    point = '0.0 4.97916666667 0.0'
    variable = disp_x
  [../]
  [./disp_x_479]
    type = PointValue
    point = '0.0 4.98958333333 0.0'
    variable = disp_x
  [../]
  [./disp_x_480]
    type = PointValue
    point = '0.0 5.0 0.0'
    variable = disp_x
  [../]
  [./lagrange_0]
    type = PointValue
    point = '0.0 0.00520833333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_1]
    type = PointValue
    point = '0.0 0.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_2]
    type = PointValue
    point = '0.0 0.0260416666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_3]
    type = PointValue
    point = '0.0 0.0364583333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_4]
    type = PointValue
    point = '0.0 0.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_5]
    type = PointValue
    point = '0.0 0.0572916666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_6]
    type = PointValue
    point = '0.0 0.0677083333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_7]
    type = PointValue
    point = '0.0 0.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_8]
    type = PointValue
    point = '0.0 0.0885416666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_9]
    type = PointValue
    point = '0.0 0.0989583333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_10]
    type = PointValue
    point = '0.0 0.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_11]
    type = PointValue
    point = '0.0 0.119791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_12]
    type = PointValue
    point = '0.0 0.130208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_13]
    type = PointValue
    point = '0.0 0.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_14]
    type = PointValue
    point = '0.0 0.151041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_15]
    type = PointValue
    point = '0.0 0.161458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_16]
    type = PointValue
    point = '0.0 0.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_17]
    type = PointValue
    point = '0.0 0.182291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_18]
    type = PointValue
    point = '0.0 0.192708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_19]
    type = PointValue
    point = '0.0 0.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_20]
    type = PointValue
    point = '0.0 0.213541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_21]
    type = PointValue
    point = '0.0 0.223958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_22]
    type = PointValue
    point = '0.0 0.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_23]
    type = PointValue
    point = '0.0 0.244791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_24]
    type = PointValue
    point = '0.0 0.255208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_25]
    type = PointValue
    point = '0.0 0.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_26]
    type = PointValue
    point = '0.0 0.276041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_27]
    type = PointValue
    point = '0.0 0.286458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_28]
    type = PointValue
    point = '0.0 0.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_29]
    type = PointValue
    point = '0.0 0.307291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_30]
    type = PointValue
    point = '0.0 0.317708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_31]
    type = PointValue
    point = '0.0 0.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_32]
    type = PointValue
    point = '0.0 0.338541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_33]
    type = PointValue
    point = '0.0 0.348958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_34]
    type = PointValue
    point = '0.0 0.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_35]
    type = PointValue
    point = '0.0 0.369791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_36]
    type = PointValue
    point = '0.0 0.380208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_37]
    type = PointValue
    point = '0.0 0.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_38]
    type = PointValue
    point = '0.0 0.401041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_39]
    type = PointValue
    point = '0.0 0.411458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_40]
    type = PointValue
    point = '0.0 0.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_41]
    type = PointValue
    point = '0.0 0.432291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_42]
    type = PointValue
    point = '0.0 0.442708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_43]
    type = PointValue
    point = '0.0 0.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_44]
    type = PointValue
    point = '0.0 0.463541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_45]
    type = PointValue
    point = '0.0 0.473958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_46]
    type = PointValue
    point = '0.0 0.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_47]
    type = PointValue
    point = '0.0 0.494791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_48]
    type = PointValue
    point = '0.0 0.505208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_49]
    type = PointValue
    point = '0.0 0.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_50]
    type = PointValue
    point = '0.0 0.526041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_51]
    type = PointValue
    point = '0.0 0.536458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_52]
    type = PointValue
    point = '0.0 0.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_53]
    type = PointValue
    point = '0.0 0.557291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_54]
    type = PointValue
    point = '0.0 0.567708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_55]
    type = PointValue
    point = '0.0 0.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_56]
    type = PointValue
    point = '0.0 0.588541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_57]
    type = PointValue
    point = '0.0 0.598958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_58]
    type = PointValue
    point = '0.0 0.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_59]
    type = PointValue
    point = '0.0 0.619791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_60]
    type = PointValue
    point = '0.0 0.630208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_61]
    type = PointValue
    point = '0.0 0.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_62]
    type = PointValue
    point = '0.0 0.651041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_63]
    type = PointValue
    point = '0.0 0.661458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_64]
    type = PointValue
    point = '0.0 0.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_65]
    type = PointValue
    point = '0.0 0.682291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_66]
    type = PointValue
    point = '0.0 0.692708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_67]
    type = PointValue
    point = '0.0 0.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_68]
    type = PointValue
    point = '0.0 0.713541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_69]
    type = PointValue
    point = '0.0 0.723958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_70]
    type = PointValue
    point = '0.0 0.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_71]
    type = PointValue
    point = '0.0 0.744791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_72]
    type = PointValue
    point = '0.0 0.755208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_73]
    type = PointValue
    point = '0.0 0.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_74]
    type = PointValue
    point = '0.0 0.776041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_75]
    type = PointValue
    point = '0.0 0.786458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_76]
    type = PointValue
    point = '0.0 0.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_77]
    type = PointValue
    point = '0.0 0.807291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_78]
    type = PointValue
    point = '0.0 0.817708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_79]
    type = PointValue
    point = '0.0 0.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_80]
    type = PointValue
    point = '0.0 0.838541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_81]
    type = PointValue
    point = '0.0 0.848958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_82]
    type = PointValue
    point = '0.0 0.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_83]
    type = PointValue
    point = '0.0 0.869791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_84]
    type = PointValue
    point = '0.0 0.880208333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_85]
    type = PointValue
    point = '0.0 0.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_86]
    type = PointValue
    point = '0.0 0.901041666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_87]
    type = PointValue
    point = '0.0 0.911458333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_88]
    type = PointValue
    point = '0.0 0.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_89]
    type = PointValue
    point = '0.0 0.932291666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_90]
    type = PointValue
    point = '0.0 0.942708333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_91]
    type = PointValue
    point = '0.0 0.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_92]
    type = PointValue
    point = '0.0 0.963541666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_93]
    type = PointValue
    point = '0.0 0.973958333333 0.0'
    variable = lagrange
  [../]
  [./lagrange_94]
    type = PointValue
    point = '0.0 0.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_95]
    type = PointValue
    point = '0.0 0.994791666667 0.0'
    variable = lagrange
  [../]
  [./lagrange_96]
    type = PointValue
    point = '0.0 1.00520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_97]
    type = PointValue
    point = '0.0 1.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_98]
    type = PointValue
    point = '0.0 1.02604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_99]
    type = PointValue
    point = '0.0 1.03645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_100]
    type = PointValue
    point = '0.0 1.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_101]
    type = PointValue
    point = '0.0 1.05729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_102]
    type = PointValue
    point = '0.0 1.06770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_103]
    type = PointValue
    point = '0.0 1.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_104]
    type = PointValue
    point = '0.0 1.08854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_105]
    type = PointValue
    point = '0.0 1.09895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_106]
    type = PointValue
    point = '0.0 1.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_107]
    type = PointValue
    point = '0.0 1.11979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_108]
    type = PointValue
    point = '0.0 1.13020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_109]
    type = PointValue
    point = '0.0 1.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_110]
    type = PointValue
    point = '0.0 1.15104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_111]
    type = PointValue
    point = '0.0 1.16145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_112]
    type = PointValue
    point = '0.0 1.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_113]
    type = PointValue
    point = '0.0 1.18229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_114]
    type = PointValue
    point = '0.0 1.19270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_115]
    type = PointValue
    point = '0.0 1.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_116]
    type = PointValue
    point = '0.0 1.21354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_117]
    type = PointValue
    point = '0.0 1.22395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_118]
    type = PointValue
    point = '0.0 1.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_119]
    type = PointValue
    point = '0.0 1.24479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_120]
    type = PointValue
    point = '0.0 1.25520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_121]
    type = PointValue
    point = '0.0 1.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_122]
    type = PointValue
    point = '0.0 1.27604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_123]
    type = PointValue
    point = '0.0 1.28645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_124]
    type = PointValue
    point = '0.0 1.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_125]
    type = PointValue
    point = '0.0 1.30729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_126]
    type = PointValue
    point = '0.0 1.31770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_127]
    type = PointValue
    point = '0.0 1.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_128]
    type = PointValue
    point = '0.0 1.33854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_129]
    type = PointValue
    point = '0.0 1.34895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_130]
    type = PointValue
    point = '0.0 1.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_131]
    type = PointValue
    point = '0.0 1.36979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_132]
    type = PointValue
    point = '0.0 1.38020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_133]
    type = PointValue
    point = '0.0 1.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_134]
    type = PointValue
    point = '0.0 1.40104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_135]
    type = PointValue
    point = '0.0 1.41145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_136]
    type = PointValue
    point = '0.0 1.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_137]
    type = PointValue
    point = '0.0 1.43229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_138]
    type = PointValue
    point = '0.0 1.44270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_139]
    type = PointValue
    point = '0.0 1.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_140]
    type = PointValue
    point = '0.0 1.46354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_141]
    type = PointValue
    point = '0.0 1.47395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_142]
    type = PointValue
    point = '0.0 1.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_143]
    type = PointValue
    point = '0.0 1.49479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_144]
    type = PointValue
    point = '0.0 1.50520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_145]
    type = PointValue
    point = '0.0 1.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_146]
    type = PointValue
    point = '0.0 1.52604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_147]
    type = PointValue
    point = '0.0 1.53645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_148]
    type = PointValue
    point = '0.0 1.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_149]
    type = PointValue
    point = '0.0 1.55729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_150]
    type = PointValue
    point = '0.0 1.56770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_151]
    type = PointValue
    point = '0.0 1.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_152]
    type = PointValue
    point = '0.0 1.58854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_153]
    type = PointValue
    point = '0.0 1.59895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_154]
    type = PointValue
    point = '0.0 1.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_155]
    type = PointValue
    point = '0.0 1.61979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_156]
    type = PointValue
    point = '0.0 1.63020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_157]
    type = PointValue
    point = '0.0 1.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_158]
    type = PointValue
    point = '0.0 1.65104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_159]
    type = PointValue
    point = '0.0 1.66145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_160]
    type = PointValue
    point = '0.0 1.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_161]
    type = PointValue
    point = '0.0 1.68229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_162]
    type = PointValue
    point = '0.0 1.69270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_163]
    type = PointValue
    point = '0.0 1.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_164]
    type = PointValue
    point = '0.0 1.71354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_165]
    type = PointValue
    point = '0.0 1.72395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_166]
    type = PointValue
    point = '0.0 1.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_167]
    type = PointValue
    point = '0.0 1.74479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_168]
    type = PointValue
    point = '0.0 1.75520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_169]
    type = PointValue
    point = '0.0 1.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_170]
    type = PointValue
    point = '0.0 1.77604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_171]
    type = PointValue
    point = '0.0 1.78645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_172]
    type = PointValue
    point = '0.0 1.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_173]
    type = PointValue
    point = '0.0 1.80729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_174]
    type = PointValue
    point = '0.0 1.81770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_175]
    type = PointValue
    point = '0.0 1.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_176]
    type = PointValue
    point = '0.0 1.83854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_177]
    type = PointValue
    point = '0.0 1.84895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_178]
    type = PointValue
    point = '0.0 1.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_179]
    type = PointValue
    point = '0.0 1.86979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_180]
    type = PointValue
    point = '0.0 1.88020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_181]
    type = PointValue
    point = '0.0 1.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_182]
    type = PointValue
    point = '0.0 1.90104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_183]
    type = PointValue
    point = '0.0 1.91145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_184]
    type = PointValue
    point = '0.0 1.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_185]
    type = PointValue
    point = '0.0 1.93229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_186]
    type = PointValue
    point = '0.0 1.94270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_187]
    type = PointValue
    point = '0.0 1.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_188]
    type = PointValue
    point = '0.0 1.96354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_189]
    type = PointValue
    point = '0.0 1.97395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_190]
    type = PointValue
    point = '0.0 1.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_191]
    type = PointValue
    point = '0.0 1.99479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_192]
    type = PointValue
    point = '0.0 2.00520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_193]
    type = PointValue
    point = '0.0 2.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_194]
    type = PointValue
    point = '0.0 2.02604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_195]
    type = PointValue
    point = '0.0 2.03645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_196]
    type = PointValue
    point = '0.0 2.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_197]
    type = PointValue
    point = '0.0 2.05729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_198]
    type = PointValue
    point = '0.0 2.06770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_199]
    type = PointValue
    point = '0.0 2.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_200]
    type = PointValue
    point = '0.0 2.08854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_201]
    type = PointValue
    point = '0.0 2.09895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_202]
    type = PointValue
    point = '0.0 2.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_203]
    type = PointValue
    point = '0.0 2.11979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_204]
    type = PointValue
    point = '0.0 2.13020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_205]
    type = PointValue
    point = '0.0 2.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_206]
    type = PointValue
    point = '0.0 2.15104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_207]
    type = PointValue
    point = '0.0 2.16145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_208]
    type = PointValue
    point = '0.0 2.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_209]
    type = PointValue
    point = '0.0 2.18229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_210]
    type = PointValue
    point = '0.0 2.19270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_211]
    type = PointValue
    point = '0.0 2.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_212]
    type = PointValue
    point = '0.0 2.21354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_213]
    type = PointValue
    point = '0.0 2.22395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_214]
    type = PointValue
    point = '0.0 2.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_215]
    type = PointValue
    point = '0.0 2.24479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_216]
    type = PointValue
    point = '0.0 2.25520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_217]
    type = PointValue
    point = '0.0 2.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_218]
    type = PointValue
    point = '0.0 2.27604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_219]
    type = PointValue
    point = '0.0 2.28645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_220]
    type = PointValue
    point = '0.0 2.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_221]
    type = PointValue
    point = '0.0 2.30729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_222]
    type = PointValue
    point = '0.0 2.31770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_223]
    type = PointValue
    point = '0.0 2.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_224]
    type = PointValue
    point = '0.0 2.33854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_225]
    type = PointValue
    point = '0.0 2.34895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_226]
    type = PointValue
    point = '0.0 2.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_227]
    type = PointValue
    point = '0.0 2.36979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_228]
    type = PointValue
    point = '0.0 2.38020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_229]
    type = PointValue
    point = '0.0 2.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_230]
    type = PointValue
    point = '0.0 2.40104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_231]
    type = PointValue
    point = '0.0 2.41145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_232]
    type = PointValue
    point = '0.0 2.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_233]
    type = PointValue
    point = '0.0 2.43229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_234]
    type = PointValue
    point = '0.0 2.44270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_235]
    type = PointValue
    point = '0.0 2.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_236]
    type = PointValue
    point = '0.0 2.46354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_237]
    type = PointValue
    point = '0.0 2.47395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_238]
    type = PointValue
    point = '0.0 2.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_239]
    type = PointValue
    point = '0.0 2.49479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_240]
    type = PointValue
    point = '0.0 2.50520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_241]
    type = PointValue
    point = '0.0 2.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_242]
    type = PointValue
    point = '0.0 2.52604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_243]
    type = PointValue
    point = '0.0 2.53645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_244]
    type = PointValue
    point = '0.0 2.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_245]
    type = PointValue
    point = '0.0 2.55729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_246]
    type = PointValue
    point = '0.0 2.56770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_247]
    type = PointValue
    point = '0.0 2.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_248]
    type = PointValue
    point = '0.0 2.58854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_249]
    type = PointValue
    point = '0.0 2.59895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_250]
    type = PointValue
    point = '0.0 2.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_251]
    type = PointValue
    point = '0.0 2.61979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_252]
    type = PointValue
    point = '0.0 2.63020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_253]
    type = PointValue
    point = '0.0 2.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_254]
    type = PointValue
    point = '0.0 2.65104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_255]
    type = PointValue
    point = '0.0 2.66145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_256]
    type = PointValue
    point = '0.0 2.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_257]
    type = PointValue
    point = '0.0 2.68229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_258]
    type = PointValue
    point = '0.0 2.69270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_259]
    type = PointValue
    point = '0.0 2.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_260]
    type = PointValue
    point = '0.0 2.71354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_261]
    type = PointValue
    point = '0.0 2.72395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_262]
    type = PointValue
    point = '0.0 2.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_263]
    type = PointValue
    point = '0.0 2.74479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_264]
    type = PointValue
    point = '0.0 2.75520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_265]
    type = PointValue
    point = '0.0 2.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_266]
    type = PointValue
    point = '0.0 2.77604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_267]
    type = PointValue
    point = '0.0 2.78645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_268]
    type = PointValue
    point = '0.0 2.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_269]
    type = PointValue
    point = '0.0 2.80729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_270]
    type = PointValue
    point = '0.0 2.81770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_271]
    type = PointValue
    point = '0.0 2.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_272]
    type = PointValue
    point = '0.0 2.83854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_273]
    type = PointValue
    point = '0.0 2.84895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_274]
    type = PointValue
    point = '0.0 2.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_275]
    type = PointValue
    point = '0.0 2.86979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_276]
    type = PointValue
    point = '0.0 2.88020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_277]
    type = PointValue
    point = '0.0 2.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_278]
    type = PointValue
    point = '0.0 2.90104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_279]
    type = PointValue
    point = '0.0 2.91145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_280]
    type = PointValue
    point = '0.0 2.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_281]
    type = PointValue
    point = '0.0 2.93229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_282]
    type = PointValue
    point = '0.0 2.94270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_283]
    type = PointValue
    point = '0.0 2.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_284]
    type = PointValue
    point = '0.0 2.96354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_285]
    type = PointValue
    point = '0.0 2.97395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_286]
    type = PointValue
    point = '0.0 2.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_287]
    type = PointValue
    point = '0.0 2.99479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_288]
    type = PointValue
    point = '0.0 3.00520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_289]
    type = PointValue
    point = '0.0 3.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_290]
    type = PointValue
    point = '0.0 3.02604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_291]
    type = PointValue
    point = '0.0 3.03645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_292]
    type = PointValue
    point = '0.0 3.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_293]
    type = PointValue
    point = '0.0 3.05729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_294]
    type = PointValue
    point = '0.0 3.06770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_295]
    type = PointValue
    point = '0.0 3.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_296]
    type = PointValue
    point = '0.0 3.08854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_297]
    type = PointValue
    point = '0.0 3.09895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_298]
    type = PointValue
    point = '0.0 3.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_299]
    type = PointValue
    point = '0.0 3.11979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_300]
    type = PointValue
    point = '0.0 3.13020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_301]
    type = PointValue
    point = '0.0 3.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_302]
    type = PointValue
    point = '0.0 3.15104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_303]
    type = PointValue
    point = '0.0 3.16145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_304]
    type = PointValue
    point = '0.0 3.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_305]
    type = PointValue
    point = '0.0 3.18229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_306]
    type = PointValue
    point = '0.0 3.19270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_307]
    type = PointValue
    point = '0.0 3.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_308]
    type = PointValue
    point = '0.0 3.21354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_309]
    type = PointValue
    point = '0.0 3.22395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_310]
    type = PointValue
    point = '0.0 3.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_311]
    type = PointValue
    point = '0.0 3.24479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_312]
    type = PointValue
    point = '0.0 3.25520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_313]
    type = PointValue
    point = '0.0 3.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_314]
    type = PointValue
    point = '0.0 3.27604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_315]
    type = PointValue
    point = '0.0 3.28645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_316]
    type = PointValue
    point = '0.0 3.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_317]
    type = PointValue
    point = '0.0 3.30729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_318]
    type = PointValue
    point = '0.0 3.31770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_319]
    type = PointValue
    point = '0.0 3.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_320]
    type = PointValue
    point = '0.0 3.33854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_321]
    type = PointValue
    point = '0.0 3.34895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_322]
    type = PointValue
    point = '0.0 3.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_323]
    type = PointValue
    point = '0.0 3.36979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_324]
    type = PointValue
    point = '0.0 3.38020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_325]
    type = PointValue
    point = '0.0 3.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_326]
    type = PointValue
    point = '0.0 3.40104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_327]
    type = PointValue
    point = '0.0 3.41145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_328]
    type = PointValue
    point = '0.0 3.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_329]
    type = PointValue
    point = '0.0 3.43229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_330]
    type = PointValue
    point = '0.0 3.44270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_331]
    type = PointValue
    point = '0.0 3.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_332]
    type = PointValue
    point = '0.0 3.46354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_333]
    type = PointValue
    point = '0.0 3.47395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_334]
    type = PointValue
    point = '0.0 3.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_335]
    type = PointValue
    point = '0.0 3.49479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_336]
    type = PointValue
    point = '0.0 3.50520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_337]
    type = PointValue
    point = '0.0 3.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_338]
    type = PointValue
    point = '0.0 3.52604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_339]
    type = PointValue
    point = '0.0 3.53645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_340]
    type = PointValue
    point = '0.0 3.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_341]
    type = PointValue
    point = '0.0 3.55729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_342]
    type = PointValue
    point = '0.0 3.56770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_343]
    type = PointValue
    point = '0.0 3.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_344]
    type = PointValue
    point = '0.0 3.58854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_345]
    type = PointValue
    point = '0.0 3.59895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_346]
    type = PointValue
    point = '0.0 3.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_347]
    type = PointValue
    point = '0.0 3.61979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_348]
    type = PointValue
    point = '0.0 3.63020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_349]
    type = PointValue
    point = '0.0 3.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_350]
    type = PointValue
    point = '0.0 3.65104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_351]
    type = PointValue
    point = '0.0 3.66145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_352]
    type = PointValue
    point = '0.0 3.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_353]
    type = PointValue
    point = '0.0 3.68229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_354]
    type = PointValue
    point = '0.0 3.69270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_355]
    type = PointValue
    point = '0.0 3.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_356]
    type = PointValue
    point = '0.0 3.71354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_357]
    type = PointValue
    point = '0.0 3.72395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_358]
    type = PointValue
    point = '0.0 3.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_359]
    type = PointValue
    point = '0.0 3.74479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_360]
    type = PointValue
    point = '0.0 3.75520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_361]
    type = PointValue
    point = '0.0 3.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_362]
    type = PointValue
    point = '0.0 3.77604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_363]
    type = PointValue
    point = '0.0 3.78645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_364]
    type = PointValue
    point = '0.0 3.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_365]
    type = PointValue
    point = '0.0 3.80729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_366]
    type = PointValue
    point = '0.0 3.81770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_367]
    type = PointValue
    point = '0.0 3.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_368]
    type = PointValue
    point = '0.0 3.83854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_369]
    type = PointValue
    point = '0.0 3.84895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_370]
    type = PointValue
    point = '0.0 3.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_371]
    type = PointValue
    point = '0.0 3.86979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_372]
    type = PointValue
    point = '0.0 3.88020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_373]
    type = PointValue
    point = '0.0 3.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_374]
    type = PointValue
    point = '0.0 3.90104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_375]
    type = PointValue
    point = '0.0 3.91145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_376]
    type = PointValue
    point = '0.0 3.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_377]
    type = PointValue
    point = '0.0 3.93229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_378]
    type = PointValue
    point = '0.0 3.94270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_379]
    type = PointValue
    point = '0.0 3.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_380]
    type = PointValue
    point = '0.0 3.96354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_381]
    type = PointValue
    point = '0.0 3.97395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_382]
    type = PointValue
    point = '0.0 3.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_383]
    type = PointValue
    point = '0.0 3.99479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_384]
    type = PointValue
    point = '0.0 4.00520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_385]
    type = PointValue
    point = '0.0 4.015625 0.0'
    variable = lagrange
  [../]
  [./lagrange_386]
    type = PointValue
    point = '0.0 4.02604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_387]
    type = PointValue
    point = '0.0 4.03645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_388]
    type = PointValue
    point = '0.0 4.046875 0.0'
    variable = lagrange
  [../]
  [./lagrange_389]
    type = PointValue
    point = '0.0 4.05729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_390]
    type = PointValue
    point = '0.0 4.06770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_391]
    type = PointValue
    point = '0.0 4.078125 0.0'
    variable = lagrange
  [../]
  [./lagrange_392]
    type = PointValue
    point = '0.0 4.08854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_393]
    type = PointValue
    point = '0.0 4.09895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_394]
    type = PointValue
    point = '0.0 4.109375 0.0'
    variable = lagrange
  [../]
  [./lagrange_395]
    type = PointValue
    point = '0.0 4.11979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_396]
    type = PointValue
    point = '0.0 4.13020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_397]
    type = PointValue
    point = '0.0 4.140625 0.0'
    variable = lagrange
  [../]
  [./lagrange_398]
    type = PointValue
    point = '0.0 4.15104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_399]
    type = PointValue
    point = '0.0 4.16145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_400]
    type = PointValue
    point = '0.0 4.171875 0.0'
    variable = lagrange
  [../]
  [./lagrange_401]
    type = PointValue
    point = '0.0 4.18229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_402]
    type = PointValue
    point = '0.0 4.19270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_403]
    type = PointValue
    point = '0.0 4.203125 0.0'
    variable = lagrange
  [../]
  [./lagrange_404]
    type = PointValue
    point = '0.0 4.21354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_405]
    type = PointValue
    point = '0.0 4.22395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_406]
    type = PointValue
    point = '0.0 4.234375 0.0'
    variable = lagrange
  [../]
  [./lagrange_407]
    type = PointValue
    point = '0.0 4.24479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_408]
    type = PointValue
    point = '0.0 4.25520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_409]
    type = PointValue
    point = '0.0 4.265625 0.0'
    variable = lagrange
  [../]
  [./lagrange_410]
    type = PointValue
    point = '0.0 4.27604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_411]
    type = PointValue
    point = '0.0 4.28645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_412]
    type = PointValue
    point = '0.0 4.296875 0.0'
    variable = lagrange
  [../]
  [./lagrange_413]
    type = PointValue
    point = '0.0 4.30729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_414]
    type = PointValue
    point = '0.0 4.31770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_415]
    type = PointValue
    point = '0.0 4.328125 0.0'
    variable = lagrange
  [../]
  [./lagrange_416]
    type = PointValue
    point = '0.0 4.33854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_417]
    type = PointValue
    point = '0.0 4.34895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_418]
    type = PointValue
    point = '0.0 4.359375 0.0'
    variable = lagrange
  [../]
  [./lagrange_419]
    type = PointValue
    point = '0.0 4.36979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_420]
    type = PointValue
    point = '0.0 4.38020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_421]
    type = PointValue
    point = '0.0 4.390625 0.0'
    variable = lagrange
  [../]
  [./lagrange_422]
    type = PointValue
    point = '0.0 4.40104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_423]
    type = PointValue
    point = '0.0 4.41145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_424]
    type = PointValue
    point = '0.0 4.421875 0.0'
    variable = lagrange
  [../]
  [./lagrange_425]
    type = PointValue
    point = '0.0 4.43229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_426]
    type = PointValue
    point = '0.0 4.44270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_427]
    type = PointValue
    point = '0.0 4.453125 0.0'
    variable = lagrange
  [../]
  [./lagrange_428]
    type = PointValue
    point = '0.0 4.46354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_429]
    type = PointValue
    point = '0.0 4.47395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_430]
    type = PointValue
    point = '0.0 4.484375 0.0'
    variable = lagrange
  [../]
  [./lagrange_431]
    type = PointValue
    point = '0.0 4.49479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_432]
    type = PointValue
    point = '0.0 4.50520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_433]
    type = PointValue
    point = '0.0 4.515625 0.0'
    variable = lagrange
  [../]
  [./lagrange_434]
    type = PointValue
    point = '0.0 4.52604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_435]
    type = PointValue
    point = '0.0 4.53645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_436]
    type = PointValue
    point = '0.0 4.546875 0.0'
    variable = lagrange
  [../]
  [./lagrange_437]
    type = PointValue
    point = '0.0 4.55729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_438]
    type = PointValue
    point = '0.0 4.56770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_439]
    type = PointValue
    point = '0.0 4.578125 0.0'
    variable = lagrange
  [../]
  [./lagrange_440]
    type = PointValue
    point = '0.0 4.58854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_441]
    type = PointValue
    point = '0.0 4.59895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_442]
    type = PointValue
    point = '0.0 4.609375 0.0'
    variable = lagrange
  [../]
  [./lagrange_443]
    type = PointValue
    point = '0.0 4.61979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_444]
    type = PointValue
    point = '0.0 4.63020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_445]
    type = PointValue
    point = '0.0 4.640625 0.0'
    variable = lagrange
  [../]
  [./lagrange_446]
    type = PointValue
    point = '0.0 4.65104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_447]
    type = PointValue
    point = '0.0 4.66145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_448]
    type = PointValue
    point = '0.0 4.671875 0.0'
    variable = lagrange
  [../]
  [./lagrange_449]
    type = PointValue
    point = '0.0 4.68229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_450]
    type = PointValue
    point = '0.0 4.69270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_451]
    type = PointValue
    point = '0.0 4.703125 0.0'
    variable = lagrange
  [../]
  [./lagrange_452]
    type = PointValue
    point = '0.0 4.71354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_453]
    type = PointValue
    point = '0.0 4.72395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_454]
    type = PointValue
    point = '0.0 4.734375 0.0'
    variable = lagrange
  [../]
  [./lagrange_455]
    type = PointValue
    point = '0.0 4.74479166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_456]
    type = PointValue
    point = '0.0 4.75520833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_457]
    type = PointValue
    point = '0.0 4.765625 0.0'
    variable = lagrange
  [../]
  [./lagrange_458]
    type = PointValue
    point = '0.0 4.77604166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_459]
    type = PointValue
    point = '0.0 4.78645833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_460]
    type = PointValue
    point = '0.0 4.796875 0.0'
    variable = lagrange
  [../]
  [./lagrange_461]
    type = PointValue
    point = '0.0 4.80729166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_462]
    type = PointValue
    point = '0.0 4.81770833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_463]
    type = PointValue
    point = '0.0 4.828125 0.0'
    variable = lagrange
  [../]
  [./lagrange_464]
    type = PointValue
    point = '0.0 4.83854166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_465]
    type = PointValue
    point = '0.0 4.84895833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_466]
    type = PointValue
    point = '0.0 4.859375 0.0'
    variable = lagrange
  [../]
  [./lagrange_467]
    type = PointValue
    point = '0.0 4.86979166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_468]
    type = PointValue
    point = '0.0 4.88020833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_469]
    type = PointValue
    point = '0.0 4.890625 0.0'
    variable = lagrange
  [../]
  [./lagrange_470]
    type = PointValue
    point = '0.0 4.90104166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_471]
    type = PointValue
    point = '0.0 4.91145833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_472]
    type = PointValue
    point = '0.0 4.921875 0.0'
    variable = lagrange
  [../]
  [./lagrange_473]
    type = PointValue
    point = '0.0 4.93229166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_474]
    type = PointValue
    point = '0.0 4.94270833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_475]
    type = PointValue
    point = '0.0 4.953125 0.0'
    variable = lagrange
  [../]
  [./lagrange_476]
    type = PointValue
    point = '0.0 4.96354166667 0.0'
    variable = lagrange
  [../]
  [./lagrange_477]
    type = PointValue
    point = '0.0 4.97395833333 0.0'
    variable = lagrange
  [../]
  [./lagrange_478]
    type = PointValue
    point = '0.0 4.984375 0.0'
    variable = lagrange
  [../]
  [./lagrange_479]
    type = PointValue
    point = '0.0 4.99479166667 0.0'
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
  file_base = plastic_shear_HM_h5_msh480
  print_linear_residuals = false
[]

