alpha = 8.889e+01
beta = 2.222e+01
gamma = 3.333e+01

E = gamma*(3*alpha-4*gamma)/(alpha-gamma) # 210,000
nu = (alpha-2*gamma)/(2*(alpha-gamma)) # 0.3
print E
print nu

''' In TensorMechanics, the stiffness matrix is entered as 
 [a b b a b a c c c] where
 C = [a b b . . .]
     [. a b . . .]
     [. . a . . .]
     [. . . c . .]
     [. . . . c .]
     [. . . . . c]
'''

def printElasticConstantsFromStiffness(alpha, beta, gamma):
    E = gamma*(3*alpha-4*gamma)/(alpha-gamma)
    nu = (alpha-2*gamma)/(2*(alpha-gamma))
    print 'E = {0}'.format(E)
    print 'nu = {0}\n'.format(nu)
    return E, nu

def printStiffnessTensor(E, nu):
    alpha =  E*(1-nu)/((1+nu)*(1-2*nu)) 
    beta = E*nu/((1+nu)*(1-2*nu)) 
    gamma = E/(2*(1+nu)) 
    print 'alpha = {0}'.format(alpha)
    print 'beta = {0}'.format(beta)
    print 'gamma = {0}\n'.format(gamma)
    print "C_ijkl = '{a:.3e} {b:.3e} {b:.3e} {a:.3e} {b:.3e} {a:.3e} {c:.3e} {c:.3e} {c:.3e}'\n".format(a=alpha, b=beta, c=gamma)
    return alpha, beta, gamma

if __name__ == '__main__':
    #printElasticConstantsFromStiffness(1.346e+03,5.769e+02,3.846e+2)
    E = 80
    nu = 0.2
    alpha2, beta2, gamma2 = printStiffnessTensor(E, nu)
    #alpha2 = 1.346e+03
    #beta2 = 5.769e+02
    #gamma2 = 3.846e+02
    #alpha2 = 1.346e+04
    #beta2 = 5.769e+03
    #gamma2 = 5.769e+03
    E2, nu2 = printElasticConstantsFromStiffness(alpha2, beta2, gamma2)
    print 'E2={0}, nu2={1}'.format(E2, nu2)
