''' Script to generate documentation images from tests '''

import os, sys, csv
import pylab as P
import matplotlib.pyplot as pp
import matplotlib
from os.path import expanduser
import numpy as np
from test.test_hotshot import shortfilename

redback_dir = os.path.join(expanduser('~'), 'projects', 'redback')
test_dir = os.path.join(redback_dir, 'tests', 'benchmark_3_M')
gold_dir = os.path.join(test_dir, 'gold')

def parseCsvFile(filename, column_keys=None):
    ''' Read S-curve data from csv file'''
    print 'Parsing "{}"...'.format(filename)
    column_index = {} # mapping, key=column_key, value=corresponding column index
    data = {} # dict of data, key=column_key, value=data list (floats)
    with open(filename, 'rb') as csvfile:
        csvreader = csv.reader(csvfile)
        line_i = 0 # line index
        for row in csvreader:
            if line_i == 0:
                # Headers. Find interesting columns
                headers = row
                # prepare structure for all columns we want
                if column_keys is None:
                    # grab all data in file
                    column_keys_we_want = [elt.lower() for elt in headers]
                else:
                    # grab only requested data from file
                    assert type(column_keys)==type([])
                    column_keys_we_want = column_keys
                for column_key in column_keys_we_want:
                    data[column_key] = []
                for column_i, elt in enumerate(headers):
                    elt_lower = elt.lower()
                    if elt_lower in column_keys_we_want:
                        column_index[elt_lower] = column_i
                column_indices = column_index.values()
                line_i += 1
                print 'Found columns {0}'.format(column_index)
                continue
            # Data line
            if len(row) < len(headers):
                break # finished reading all data
            for column_key in column_keys_we_want:
                data[column_key].append(float(row[column_index[column_key]]))
            line_i += 1
            continue # go to next data line
    print 'Finished parsing csv file'
    return data

def generateSingleComparison(benchmark_rootname, parameter, data_redback, data_abaqus, do_show=False):
    ''' Create figure comparing results from abaqus and redback '''
    key_x = 'time' # 'step'
    key_y = parameter
    redback_x = np.array(data_redback[key_x])
    redback_y = np.array(data_redback[key_y])
    abaqus_x = np.array(data_abaqus[key_x])
    abaqus_y = np.array(data_abaqus[key_y])
    if parameter.lower() == 's_pressure':
      abaqus_y = -abaqus_y
    fig = P.figure(figsize=(7, 4))
    ax = fig.add_subplot(111)
    pp.subplots_adjust(left=0.15, bottom=0.15, right=0.95, top=0.93,
                       wspace=None, hspace=None)
    P.grid(False)
    P.hold(True)
    line1, = P.plot(abaqus_x, abaqus_y, 'black', linewidth=1, linestyle='-', label='Abaqus', marker='x', markersize=10)
    line2, = P.plot(redback_x, redback_y, 'red', linewidth=1, linestyle='-', label='Redback', marker='o')
          #marker='o', markerfacecolor='grey', markeredgecolor='grey', markersize=5,
          #label='Experiment')
    P.xlabel('Time', fontsize=16)
    #r"$Time \hspace{1}(\times10^3 years)$")
    #r"$\dot{\epsilon}_M  \hspace{0.5} (s^{-1})$"
    P.ylabel(parameter, fontsize=16)
    # see https://docs.python.org/3.3/library/string.html#formatspec
    #P.figtext(0.5, 0.82, msg, horizontalalignment='center', color='black', fontsize=20)
    P.title(benchmark_rootname)
    P.tick_params(labelsize=14)
    #ax.xaxis.set_tick_params(labelsize=20)
    ax.legend(loc='best')
    #P.axis([x_min, x_max+margin_x, y_min-margin_y, y_max+margin_y])
    if do_show:
        P.show()
    else:
        shortfilename = '{0}_{1}.eps'.format(benchmark_rootname, parameter)
        fullfilename = os.path.join(redback_dir, 'doc', 'theory', 'figures', 'abaqus', shortfilename)
        P.savefig(fullfilename, format='eps', dpi=1000)
        print 'Figure saved as {0}'.format(fullfilename)
    P.clf()

def generateAllAbaqusTestImages(do_show=False):
  ''' Generate all images for all Abaqus benchmarks '''
  # Get list of all abaqus benchmarks
  benchmark_rootnames = []
  for shortname in os.listdir(gold_dir):
    if 'abaqus' in shortname.lower():
      benchmark_rootnames.append(os.path.splitext(shortname)[0])
  # Generate pictures for each benchmark
  for benchmark_rootname in benchmark_rootnames:
    generateComparisonImagesForBenchmark(benchmark_rootname, do_show=do_show)
  print 'Generated all images for all benchmarks'

def generateComparisonImagesForBenchmark(benchmark_rootname, do_show=False):
  ''' Generate all images (comparing redback and Abaqus results) for given benchmark '''
  # check if we have redback results
  redback_results_fullpath = os.path.join(test_dir, benchmark_rootname + '.csv')
  has_redback_results = os.path.isfile(redback_results_fullpath)
  data_redback = None
  if has_redback_results:
    data_redback = parseCsvFile(redback_results_fullpath)
  # check if we have abaqus results
  abaqus_results_fullpath = os.path.join(gold_dir, benchmark_rootname + '.csv')
  has_abaqus_results = os.path.isfile(abaqus_results_fullpath)
  data_abaqus = None
  if has_abaqus_results:
    data_abaqus = parseCsvFile(abaqus_results_fullpath)
  # generate images for each parameter
  all_parameters = data_redback.keys()
  all_parameters.remove('time')
  for parameter in all_parameters:
    generateSingleComparison(benchmark_rootname, parameter, data_redback, data_abaqus, do_show=do_show)
  print 'Finished images for benchmark {0}'.format(benchmark_rootname)

if __name__ == '__main__':
  generateAllAbaqusTestImages(do_show=False)
  print 'Finished'
