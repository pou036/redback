#import sys
#sys.path.append('~/projects/moose/python/TestHarness/testers')

from RunApp import RunApp
from util import runCommand
import os

class Txtdiff(RunApp):

  @staticmethod
  def validParams():
    params = RunApp.validParams()
    params.addRequiredParam('txtdiff',   [], "A list of files to txtdiff.")
    params.addParam('gold_dir',      'gold', "The directory where the \"golden standard\" files reside relative to the TEST_DIR: (default: ./gold/)")
    params.addParam('delete_output_before_running',  True, "Delete pre-existing output files before running test. Only set to False if you know what you're doing!")

    return params

  def __init__(self, name, params):
    RunApp.__init__(self, name, params)


  def prepare(self):
    if self.specs['delete_output_before_running'] == True:
      for file in self.specs['txtdiff']:
        try:
          os.remove(os.path.join(self.specs['test_dir'], file))
        except:
          pass


  def processResults(self, moose_dir, retcode, options, output):
    (reason, output) = RunApp.processResults(self, moose_dir, retcode, options, output)

    if reason != '' or self.specs['skip_checks']:
      return (reason, output)

    # Don't Run Exodiff on Scaled Tests
    if options.scaling and self.specs['scale_refine']:
      return (reason, output)

    # Make sure that all of the Exodiff files are actually available
    for file in self.specs['txtdiff']:
      if not os.path.exists(os.path.join(self.specs['test_dir'], self.specs['gold_dir'], file)):
        output += "File Not Found: " + os.path.join(self.specs['test_dir'], self.specs['gold_dir'], file)
        reason = 'MISSING GOLD FILE'
        break

    # Run the txtdiff
    if reason == '':
      output += 'Running txtdiff'
      with open(os.path.join(self.specs['test_dir'], file), 'r') as f:
        first_line = f.readline()
      with open(os.path.join(self.specs['test_dir'], self.specs['gold_dir'], file), 'r') as f:
        first_line_gold = f.readline()
      if first_line != first_line_gold:
        reason = 'TXTDIFF'

    return (reason, output)
