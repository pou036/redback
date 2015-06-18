''' Script to generate redback parameters from Falcon parameters 

TODO: some properties depend on T,P (EOS):
 * lambda, beta (for water)
 * c_th
'''
import os, sys

# Falcon parameters
T_top = 293 # K
T_bottom = 350 # K
P_top = 1e5 # Pa
height = 500 # m, height of the model
length = 1000 # m, length of the model
thermal_cond = 2.5 # W.m^{-1}.K^{-1}, thermal conductivity of the mixture
g = 9.8 # m.s^{-2}
lambda_w = 70e-6 # K^{-1}, thermal expansion coefficient (fluid)
lambda_s = 1e-6 # K^{-1}, thermal expansion coefficient (solid)
beta_w = 4e-10 # Pa^{-1}, compressibility (fluid)
beta_s = 2e-10 # Pa^{-1}, compressibility (solid)
phi = 0.3 # -, porosity
perm = 1e-13 # m^2, permeability
mu_f0 = 1.2e-4 # Pa.s, fluid viscosity
rho_s = 2500 # kg.m^{-3}
c_w = 4186 # J.kg^{-1}.K^{-1} specific heat (fluid)
c_s = 920 # J.kg^{-1}.K^{-1}, specific heat (solid)
rho_w0 = 1000 # kg.m^{-3}

# Redback normalisation parameters
x_0 = length # m
T_0 = T_top # K
P_bottom = P_top + rho_w0*g*height
P_0 = P_bottom # Pa

# Redback formulas to computer parameters needed
delta = (T_bottom - T_top) / float(T_top)
rho_c_p_mixture = phi*rho_w0*c_w + (1-phi)*rho_s*c_s
c_th = thermal_cond / float(rho_c_p_mixture)
v_ref = c_th / float(x_0)
Pe = x_0* v_ref / float(c_th) # Peclet number = 1
lambda_m = phi*lambda_w + (1-phi)*lambda_s
beta_m = phi*beta_w + (1-phi)*beta_s
capital_lambda = (lambda_m/float(beta_m))*delta*T_0/P_0
Le = mu_f0*c_th*beta_m/float(perm) # Lewis number
T_star_top = (T_top - T_0)/float(delta*T_0)
T_star_bottom = (T_bottom - T_0)/float(delta*T_0)
P_star_top = P_top/float(P_0)
P_star_bottom = P_bottom/float(P_0)
normalized_gravity = rho_w0*g*(x_0/float(P_0))

def generateInputFile(input_file_name):
  ''' Generate Redback input file based on required parameters '''
  input_file_content = '''
[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 20
  ny = 10
  xmin = 0
  xmax = 1
  ymin = -{ymin}
  ymax = 0
[]

[Variables]
  [./temp]
  [../]
  [./pore_pressure]
  [../]
[]

[Materials]
  [./redback_nomech]
    type = RedbackMaterial
    Aphi = 1
    are_convective_terms_on = true
    block = 0
    temperature = temp
    pore_pres = pore_pressure
    ar = 10
    ar_F = 1
    ar_R = 1
    eta1 = 1e3
    fluid_density = {fluid_density}
    fluid_thermal_expansion = {fluid_themal_expansion}
    gr = 1
    gravity = '0 -{normalized_gravity} 0'
    mu = 0
    phi0 = {porosity}
    ref_lewis_nb = {Lewis_number}
    pressurization_coefficient = {pressurization_coefficient}
    solid_compressibility = {solid_compressibility}
    solid_density = {solid_density}
    total_porosity = total_porosity
    Peclet_number = {Peclet_number}
    solid_thermal_expansion = {solid_thermal_expansion}
    delta = {delta}
    fluid_compressibility = {fluid_compressibility}
    # output_properties = mixture_density
    outputs = all
  [../]
[]

[Functions]
  [./init_gradient_T]
    type = ParsedFunction
    value = {T_star_top}-y*({T_star_bottom}-{T_star_top})*{x_0}/{height}
  [../]
  [./init_gradient_P]
    # P_top-rho*g*y
    type = ParsedFunction
    value = {P_star_top}-{normalized_gravity}*y
  [../]
[]

[ICs]
  [./temp_IC]
    variable = temp
    type = FunctionIC
    function = init_gradient_T
  [../]
  [./press_IC]
    variable = pore_pressure
    type = FunctionIC
    function = init_gradient_P
  [../]
[]

[BCs]
  [./temperature_top]
    type = DirichletBC
    variable = temp
    boundary = top
    value = {T_star_top}
  [../]
  [./temperature_bottom]
    type = DirichletBC
    variable = temp
    boundary = bottom
    value = {T_star_bottom}
  [../]
  [./pore_pressure_top]
    type = DirichletBC
    variable = pore_pressure
    boundary = top
    value = {P_star_top}
  [../]
[]

[AuxVariables]
  [./Mod_Gruntfest_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
  [./total_porosity]
    family = MONOMIAL
  [../]
  [./Lewis_number]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Kernels]
  active = 'press_td temp_diff press_thermPress temp_td press_diff'
  [./temp_td]
    type = TimeDerivative
    variable = temp
  [../]
  [./temp_diff]
    type = Diffusion
    variable = temp
  [../]
  [./temp_conv]
    type = RedbackThermalConvection
    variable = temp
  [../]
  [./press_td]
    type = TimeDerivative
    variable = pore_pressure
  [../]
  [./press_diff]
    type = RedbackMassDiffusion
    variable = pore_pressure
  [../]
  [./pres_conv]
    type = RedbackMassConvection
    variable = pore_pressure
    temperature = temp
  [../]
  [./press_thermPress]
    type = RedbackThermalPressurization
    variable = pore_pressure
    temperature = temp
  [../]
[]

[AuxKernels]
  [./Gruntfest_Number]
    type = MaterialRealAux
    variable = Mod_Gruntfest_number
    property = mod_gruntfest_number
  [../]
  [./total_porosity]
    type = RedbackTotalPorosityAux
    variable = total_porosity
    mechanical_porosity = 0
    execute_on = linear
  [../]
  [./Lewis_number]
    type = MaterialRealAux
    variable = Lewis_number
    property = lewis_number
  [../]
[]

[Preconditioning]
  # active = ''
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Postprocessors]
  [./middle_temp]
    type = PointValue
    variable = temp
    point = '{x_middle} {y_middle} 0'
  [../]
  [./middle_press]
    type = PointValue
    variable = pore_pressure
    point = '{x_middle} {y_middle} 0'
  [../]
  [./middle_porosity]
    type = PointValue
    variable = total_porosity
    point = '{x_middle} {y_middle} 0'
  [../]
  [./dt]
    type = TimestepSize
  [../]
  [./num_li]
    type = NumLinearIterations
  [../]
  [./num_nli]
    type = NumNonlinearIterations
  [../]
[]

[Executioner]
  # [./TimeStepper]
  # type = ConstantDT
  # dt = 1e-1
  # [../]
  # [./TimeStepper]
  # type = PostprocessorDT
  # dt = 0.123
  # postprocessor = new_timestep
  # [../]
  start_time = 0.0
  end_time = 1e-3
  dtmax = 1
  dtmin = 1e-15
  type = Transient
  num_steps = 100000
  dt = 0.1
  l_max_its = 200
  nl_max_its = 10
  solve_type = PJFNK
  #petsc_options_iname = '-pc_type -pc_hypre_type -snes_linesearch_type -ksp_gmres_restart -snes_converged_reason'
  #petsc_options_value = 'hypre boomeramg cp 201 1'
  petsc_options_iname = '-ksp_type -pc_type -sub_pc_type -ksp_gmres_restart '
  petsc_options_value = 'gmres asm lu 201'
  nl_abs_tol = 1e-8 # 1e-10 to begin with
  reset_dt = true
  line_search = basic
  [./TimeStepper]
    # adapt_log = true
    type = SolutionTimeAdaptiveDT
    dt = 1e-7
  [../]
[]

[Outputs]
  file_base = convection2D
  output_initial = true
  exodus = true
  [./console]
    type = Console
    perf_log = true
    linear_residuals = true
  [../]
[]
'''\
  .format(fluid_density=1, fluid_themal_expansion=lambda_w,
          gravity=g, porosity=phi, Lewis_number=Le,
          pressurization_coefficient=capital_lambda,
          solid_compressibility=beta_s, solid_density=rho_s/float(rho_w0),
          Peclet_number=Pe, solid_thermal_expansion=lambda_s,
          delta=delta, fluid_compressibility=beta_w,
          ymin=height/float(length), height=height, 
          full_gravity=g,
          normalized_gravity=normalized_gravity, P0=P_0, x_0=x_0,
          T_star_top=T_star_top, T_star_bottom=T_star_bottom,
          P_star_top=P_star_top, x_middle=0.5, y_middle=-height/float(2.0*length))
  with open(input_file_name, 'w') as f_out:
    f_out.write(input_file_content)
    print 'File "{0}" created'.format(os.path.realpath(input_file_name))
    print input_file_content
  return

if __name__ == '__main__':
  generateInputFile(input_file_name='convection2D.i')
