#!/usr/bin/env python

''' script to remove duplicates from file '''

import os, sys, shutil

input_filename = 'gold/idfile.txt'
output_filename = 'idfile_unique.txt'

with open(input_filename, 'rb') as f_in:
    lines = f_in.readlines()

# Remove duplicates
assert len(lines) == 1
tmp = lines[0].split()
tmp2 = list(set(tmp))

new_txt = ' '.join(sorted(tmp2, key=float))

with open(output_filename, 'wb') as f_out:
    f_out.write(new_txt)

print 'End of third step, created file "{0}" with unique indices'.format(output_filename)
