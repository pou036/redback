import re, os, sys
from Tester import Tester
from RunParallel import RunParallel # For TIMEOUT value

class RunPy(Tester):

  @staticmethod
  def validParams():
    params = Tester.validParams()
    params.addRequiredParam('input',              "The input file to use for this test.")
    params.addRequiredParam('txtdiff',   [], "A list of files to txtdiff.")
    params.addParam('gold_dir',      'gold', "The directory where the \"golden standard\" files reside relative to the TEST_DIR: (default: ./gold/)")
    params.addParam('test_name',          "The name of the test - populated automatically")

    params.addParam('skip_test_harness_cli_args', False, "Skip adding global TestHarness CLI Args for this test")
    params.addParam('input_switch', '-i', "The default switch used for indicating an input to the executable")
    params.addParam('errors',             ['ERROR', 'command not found', 'erminate called after throwing an instance of'], "The error messages to detect a failed run")
    params.addParam('expect_out',         "A regular expression that must occur in the input in order for the test to be considered passing.")
    params.addParam('match_literal', False, "Treat expect_out as a string not a regular expression.")
    params.addParam('absent_out',         "A regular expression that must be *absent* from the output for the test to pass.")
    params.addParam('should_crash', False, "Inidicates that the test is expected to crash or otherwise terminate early")
    params.addParam('executable_pattern', "A test that only runs if the exectuable name matches the given pattern")

    params.addParam('walltime',           "The max time as pbs understands it")
    params.addParam('job_name',           "The test name as pbs understands it")
    params.addParam('no_copy',            "The tests file as pbs understands it")

    # Parallel/Thread testing
    params.addParam('max_parallel', 1000, "Maximum number of MPI processes this test can be run with      (Default: 1000)")
    params.addParam('min_parallel',    1, "Minimum number of MPI processes that this test can be run with (Default: 1)")
    params.addParam('max_threads',    16, "Max number of threads (Default: 16)")
    params.addParam('min_threads',     1, "Min number of threads (Default: 1)")
    params.addParam('allow_warnings',   False, "If the test harness is run --error warnings become errors, setting this to true will disable this an run the test without --error");

    # Valgrind
    params.addParam('valgrind', 'NORMAL', "Set to (NONE, NORMAL, HEAVY) to determine which configurations where valgrind will run.")

    params.addParam('post_command',       "Command to be run after the MOOSE job is run")

    return params

  def __init__(self, name, params):
    Tester.__init__(self, name, params)
    if os.environ.has_key("MOOSE_MPI_COMMAND"):
      self.mpi_command = os.environ['MOOSE_MPI_COMMAND']
      self.force_mpi = True
    else:
      self.mpi_command = 'mpiexec -host localhost'
      self.force_mpi = False

  def getCommand(self, options):
    specs = self.specs
    # Create the command line string to run
    command = 'python '+ specs['input']

    return command


  def processResults(self, moose_dir, retcode, options, output):
    reason = ''
    specs = self.specs
    if specs.isValid('expect_out'):
      if specs['match_literal']:
        out_ok = self.checkOutputForLiteral(output, specs['expect_out'])
      else:
        out_ok = self.checkOutputForPattern(output, specs['expect_out'])
      # Process out_ok
      if (out_ok and retcode != 0):
        reason = 'OUT FOUND BUT CRASH'
      elif (not out_ok):
        reason = 'NO EXPECTED OUT'

    elif specs.isValid('absent_out'):
      out_ok = self.checkOutputForPattern(output, specs['absent_out'])
      # Process out_ok
      if (not out_ok and retcode != 0):
        reason = 'OUTPUT ABSENT BUT CRASH'
      elif (out_ok):
        reason = 'OUTPUT NOT ABSENT'

    if reason == '':
      # We won't pay attention to the ERROR strings if EXPECT_ERR is set (from the derived class)
      # since a message to standard error might actually be a real error.  This case should be handled
      # in the derived class.
      if options.valgrind_mode == '' and not specs.isValid('expect_err') and len( filter( lambda x: x in output, specs['errors'] ) ) > 0:
        reason = 'ERRMSG'
      elif retcode == RunParallel.TIMEOUT:
        reason = 'TIMEOUT'
      elif retcode == 0 and specs['should_crash'] == True:
        reason = 'NO CRASH'
      elif retcode != 0 and specs['should_crash'] == False:
        reason = 'CRASH'
      # Valgrind runs
      elif retcode == 0 and options.valgrind_mode != '' and 'ERROR SUMMARY: 0 errors' not in output:
        reason = 'MEMORY ERROR'
      # PBS runs
      elif retcode == 0 and options.pbs and 'command not found' in output:
        reason = 'QSUB NOT FOUND'

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
