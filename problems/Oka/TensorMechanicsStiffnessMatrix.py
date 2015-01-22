alpha = 2.827e5
beta = 1.21e5
gamma = 0.808e5

E = gamma*(3*alpha-4*gamma)/(alpha-gamma) # 210,000
nu = (alpha-2*gamma)/(2*(alpha-gamma)) # 0.3

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
    E = 10000
    nu = 0.2
    alpha, beta, gamma = printStiffnessTensor(E, nu)
    E2, nu2 = printElasticConstantsFromStiffness(alpha, beta, gamma)
