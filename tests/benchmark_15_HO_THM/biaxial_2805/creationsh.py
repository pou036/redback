import os
strings2 = list()
for element in os.listdir('/Users/pou036/projects/redback/tests/benchmark_15_HO_THM/biaxial_2805_plast'):
    if element.endswith('.i'):
        (shortname, extension) = os.path.splitext(element)
        #print("'%s' est un fichier" % shortname)
        strings2.append(shortname)
#print " ,".join([str(x) for x in strings2] )
del strings2[0]
fichier = open("script.txt", "w")
for i in strings2:
    fichier.write("/Users/pou036/projects/redback/redback-opt -i "+i+".i --n-threads=16 --no-color Outputs/csv=true "+'\n')

fichier.close()
