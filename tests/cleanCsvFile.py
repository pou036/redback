''' Script to clean CSV files with extra '\r' symbols (produced by Excel) '''

import os, sys, csv, re

input_file_name = 'bench_HM_elastic_no_porosity_PROBLEM.csv'
output_file_name = 'bench_HM_elastic_no_porosity.csv'

'''with open(output_file_name, 'wb') as f_out:
  writer = csv.writer(f_out)
  with open(input_file_name, 'rb') as f_in:
    reader = csv.reader(f_in)
    for row in reader:
      writer.writerow([elt.strip() for elt in row])
  writer.writerow([])
  '''

'''with open(input_file_name, 'rb') as f_in:
  reader = csv.reader(f_in)
  for row in reader:
    print row'''



# The MOOSE way (as done in CSVDiffer.py
with open(input_file_name) as f:
  text = f.read()
  text2 = re.sub( r'\n\s*\n', '\n', text).strip()
  text3 = re.sub( r'\r\n', '\n', text2).strip()
  lines = text3.split('\n')
  with open(output_file_name, 'wb') as f_out:
    for line in lines:
      f_out.write(line + '\n')

print 'Finished. Read "{0}" and wrote clean version in "{1}"'.format(input_file_name, output_file_name)
