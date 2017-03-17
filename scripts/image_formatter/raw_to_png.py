#!/usr/bin/env python

''' script to convert raw binary file to png
    Requirements: Python Imaging Library (PIL) or pillow (more recent)
    $ sudo easy_install pip
    $ sudo pip install pillow
'''

import os, sys, shutil, struct
from PIL import Image

def convertRawToPng(input_filename, output_base_dir):
  ''' Convert raw data to stack of png images
      @param[in] input_filename - string, name of raw input file
      @param[in] output_base_dir - string, name of base directory in which
        a subdirectory will be created with all png files
  '''
  # Check user input
  if not os.path.isfile(input_filename):
    raise Exception, 'Input file "{0}" not found!'.format(input_filename)
  if not os.path.isdir(output_base_dir):
    os.makedirs(output_base_dir)

  # Get base filename from input to create subdirectory
  root, last = os.path.split(input_filename)
  base, ext = os.path.splitext(last)
  assert ext.lower() == '.raw', "Converter needs .raw file as input!"
  output_dir = os.path.join(output_base_dir, base)
  if not os.path.isdir(output_dir):
    os.makedirs(output_dir)

  # Read raw data
  #import pdb;pdb.set_trace()
  with open(input_filename, "rb") as f:
    file_content = f.read()
    (n_bit, nz, ny, nx) = struct.unpack("<biii", file_content[:13])
    if n_bit == 0:
      length = 1 # data stored on 1 byte
      for k in range(nz):
        data = []
        for j in range(ny):
          for i in range(nx):
            index_start = 13 + (k*(nx*ny) + j*(nx) + i)*length
            index_end = index_start + length # data stored on 1 byte
            out, = struct.unpack("<b", file_content[index_start:index_end])
            data.append(out)
        # write image to file
        im = Image.new("1", (nx, ny))
        im.putdata(map(int, data))
        out_filename = os.path.join(output_dir, 'slice_{0:04d}.png'.format(k))
        im.save(out_filename)
    else:
      raise Exception, 'Case n_bit={0} not implemented yet!'.format(n_bit)


if __name__ == "__main__":
  input_filename = os.path.join('input_files', 'CP10_L40.raw')
  convertRawToPng(input_filename, 'output_files')
  print 'Finished'
