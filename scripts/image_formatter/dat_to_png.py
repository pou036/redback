#!/usr/bin/env python

''' script to convert raw binary file to png '''

import os, sys, shutil
from PIL import Image

input_filename = 'pack.dat' # 300x300x300
output_filename = 'image'

with open(input_filename, 'rb') as f:
    text = f.read().splitlines()

k=0
for i in range(300):
    k+= 1
    imtxt=''
    for j in range(300):
        imtxt=imtxt + ' ' + text[300*i+j].strip()
    im = Image.new("1", (300, 300))
    im.putdata(map(int, imtxt.split()))
    if i+1<10:
        im.save(output_filename+'00'+str(k)+'.png')
    elif i+1<100:
        im.save(output_filename+'0'+str(k)+'.png')
    else:
        im.save(output_filename+str(k)+'.png')
