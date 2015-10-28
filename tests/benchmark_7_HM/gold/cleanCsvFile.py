import os, sys, csv

input_file_name = 'tests/benchmark_7_HM/gold/bench_HM_elastic.csv'
output_file_name = 'tests/benchmark_7_HM/gold/bench_HM_elastic_clean.csv'

with open(output_file_name, 'wb') as f_out:
  writer = csv.writer(f_out)
  with open(input_file_name, 'rb') as f_in:
    reader = csv.reader(f_in)
    for row in reader:
      import pdb;pdb.set_trace()
      writer.writerow([elt.strip() for elt in row])

print 'Finished'