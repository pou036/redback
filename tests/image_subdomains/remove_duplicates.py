#!/usr/bin/env python

''' script to remove duplicates from file '''

import os, sys, shutil

input_filename = 'gold/idfile.txt'
output_filename = 'idfile_unique.txt'
nb_qp = 8 # number of quadrature points used for that kind of elements (e.g 10 for TET10)

with open(input_filename, 'rb') as f_in:
    lines = f_in.readlines()

assert len(lines) == 1

dictionary = {}
for elt in lines[0].split():
    if elt not in dictionary:
        dictionary[elt] = 1
    else:
        dictionary[elt] += 1

kept_indices = []
for elt_id_str in dictionary.keys():
    if float(dictionary[elt_id_str]) > float(nb_qp)/2.0:
        kept_indices.append(elt_id_str)

new_txt = ' '.join(sorted(kept_indices, key=int))

'''# Remove duplicates
assert len(lines) == 1
tmp = lines[0].split()
tmp2 = list(set(tmp))

new_txt = ' '.join(sorted(tmp2, key=float))
'''
with open(output_filename, 'wb') as f_out:
    f_out.write(new_txt)

print 'End of third step, created file "{0}" with unique indices'.format(output_filename)
