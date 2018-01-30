''' Script to format source files according to MOOSE standards '''

import sys, os

def clean_file(input_filename, overwrite):
  ''' Function to clean given file according to MOOSE standards
      @param[in] input_filename - string, input file name
  '''
  # Check that file exists
  if not os.path.isfile(input_filename):
    error_msg = 'File "{0}" not found!'.format(input_filename)
    raise Exception, error_msg
  # Open file and save content in buffer
  lines = None
  with open(input_filename) as f_in:
    lines = f_in.readlines()
  # Write tmp file with nicer format
  tmp_filename = input_filename + '_tmp_formatting'
  try:
    os.remove(tmp_filename)
  except OSError:
    pass
  nb_lines = len(lines)
  with open(tmp_filename, 'w') as f_out:
    for i_line, line in enumerate(lines):
      # Apply formatting rules
      # things that clang_format doesn't do

      #constructor formatting
      if i_line + 1 < len(lines):
        if lines[i_line + 1].startswith('  : '):
          line= line[:len(line) - 1] + ' :\n'
        elif line.startswith('  : '):
          line = '    ' + (line[4:])

      new_line = line.replace('\t','  ')

      #break after type declaration for classes, but only if base
      if line.startswith(('void ','Real ','MooseEnum ','RankTwoTensor ','bool ')) and line.find('(') > -1 and line.find(';') == -1 and line.find('=') == -1:
        new_line =line[0:line.find(' ')] + '\n' + line[line.find(' ')+1:len(line)]

      f_out.write(new_line)

  print '(tmp) file "{0}" created'.format(tmp_filename)
  # Overwrite initial file
  os.rename(input_filename, input_filename+'_backup')
  os.rename(tmp_filename, input_filename)
  print 'File "{0}" cleaned (overwritten)'.format(input_filename)

def cleanAllFiles():
  ''' Function to clean all files '''
  overwrite = False
  home_dir = os.path.expanduser('~')
  redback_dir = os.path.join(home_dir, 'projects', 'redback')

  for dirpath, dirnames, files in os.walk(redback_dir):
    for name in files:
      if name.endswith('.h') | name.endswith('.C'):
        clean_file(os.path.join(dirpath, name), overwrite=overwrite)
  return

if __name__ == "__main__":
  if 0:
    home_dir = os.path.expanduser('~')
    test_input_filename = os.path.join(home_dir, 'projects', 'redback', 'src',
      'actions', 'RedbackAction.C')
    clean_file(test_input_filename, overwrite=False)
  if 1:
    cleanAllFiles()
