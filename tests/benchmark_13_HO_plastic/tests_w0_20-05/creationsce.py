import os
strings2 = list()
for element in os.listdir('/Users/pou036/projects/redback/tests/benchmark_13_HO_plastic/tests_m_20-05'):
    if element.endswith('.e'):
        (shortname, extension) = os.path.splitext(element)
        #print("'%s' est un fichier" % shortname)
        strings2.append(shortname)
#print " ,".join([str(x) for x in strings2] )
del strings2[0]
fichier = open("moment.txt", "w")
for i in strings2:
    fichier.write(i+"=csvRead('"+i+".csv',[],[],[],[],[],[],1);"+'\n')
fichier.write('\n')
for i in strings2:
    fichier.write("plot("+i+"(:,2),-"+i+"(:,8))"+'\n')
fichier.write('\n')
fichier.write("legend(")
for i in strings2:
    fichier.write("'"+i+"',")
fichier.write(")")


fichier.close()
