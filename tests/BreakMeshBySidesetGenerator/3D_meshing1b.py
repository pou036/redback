''' oval and rectangle faults, intersecting bounding box '''

import sys,  math
from PIL.GimpGradientFile import linear
sys.path.append('/Applications/gmsh-4.4.1-MacOSX-sdk')
import gmsh # Install Gmsh SDK: see https://pypi.org/project/gmsh-sdk/

def generate3DMesh(mesh_filename='out.msh', params={}, do_show=False):
  ''' Generate 2D faulted mesh (without interfaces) using gmsh
      @param mesh_filename: string, filename of mesh to generate.
      @param params: dictionary of mesh parameters, with potentially:
        ['lc']: float, characteristic length at mesh points
        ["Mesh.CharacteristicLengthMin"]
        ["Mesh.CharacteristicLengthMax"]
      @param do_show: boolean, show resulting mesh in gmsh or not
  '''
  # check inputs
  defaults = {
    "lc":0.1,
    "Mesh.CharacteristicLengthMin":1e-2,
    "Mesh.CharacteristicLengthMax":1,
    "Mesh.ElementOrder":1,
  }
  # Initialise gmsh and set option
  gmsh.initialize()
  gmsh.option.setNumber("General.Terminal", 1) # to print messages on terminal
  model = gmsh.model
  factory = model.occ
  mesh = model.mesh
  #gmsh.option.setNumber("Mesh.Algorithm", 6);
  for key in ["Mesh.CharacteristicLengthMin", "Mesh.CharacteristicLengthMax",
              "Mesh.ElementOrder"]:
    if key in params:
      value = params[key]
      print  'Taking "{0}" from params'.format(key)
    else:
      value = defaults[key]
      print  'Taking "{0}" from default'.format(key)
    gmsh.option.setNumber(key, value)

  model.add("my_model") # otherwise, a new unnamed model will be created on the fly

  # user parameters
  lc = defaults['lc']
  if 'lc' in params:
    lc = params['lc']

  # construct bounding box
  factory.synchronize() # needed before meshing
  tag_box = factory.addBox(0,0,0, 1,1,1, tag=-1) # (xmin,ymin,zmin, Lx,Ly,Lz, tag)
  factory.synchronize() # needed before meshing

  # add rectangle fault
  tag_rect = factory.addRectangle(0.1, 0.1, 0.1, 1.5, 0.6, -1, 0) # x, y, z, dx, dy, tag=-1, roundedRadius=0.
  factory.rotate([(2, tag_rect)], 0.1,0.1,0.1, 0,1,0, -math.pi/3.) # (dimTags, x, y, z, ax, ay, az, angle)

  # add disk fault
  tag_disk = factory.addDisk(0.35, 0.6, 0.7, 0.5, 0.3) # (xc,yc,zc, rx,ry, tag=-1)
  factory.rotate([(2, tag_disk)], 0.5,0.5,0.5, 1,1,0, math.pi/7.) # (dimTags, x, y, z, ax, ay, az, angle)

  # fuse all 2D features together
  outDimTags, outDimTagsMap = factory.fragment([(2,tag_rect),(2,tag_disk)], [])

  # intersect them with box
  outDimTags, outDimTagsMap = factory.intersect(
    [(3, tag_box)], [(2, tag_rect),(2, tag_disk)], -1, removeObject=False, removeTool=True) # intersect(objectDimTags, toolDimTags, tag=-1, removeObject=True, removeTool=True)
  factory.synchronize() # needed to refresh all elements

  # embed intersecting lines in outer box first
  mesh.embed(1, [22], 2, 6) # (dim, tags, inDim, inTag)
  factory.synchronize() # needed to refresh all elements
  mesh.embed(1, [26], 2, 1) # (dim, tags, inDim, inTag)
  factory.synchronize() # needed to refresh all elements
  # embed 2D features in 3D box
  mesh.embed(2, [tag_disk, tag_rect], 3, tag_box) # (dim, tags, inDim, inTag)
  bnd = model.getBoundary([(3, tag_box)], combined=False, oriented=False, recursive=False)

  # Add physical tags
  model.addPhysicalGroup(2, [bnd[0][1]], 1) # (dim, tags, tag)
  model.setPhysicalName(2, 1, 'left') # (dim, tag, name)
  model.addPhysicalGroup(2, [bnd[1][1]], 2)
  model.setPhysicalName(2, 2, 'right')
  model.addPhysicalGroup(2, [bnd[2][1]], 3)
  model.setPhysicalName(2, 3, 'front')
  model.addPhysicalGroup(2, [bnd[3][1]], 4)
  model.setPhysicalName(2, 4, 'back')
  model.addPhysicalGroup(2, [bnd[4][1]], 5)
  model.setPhysicalName(2, 5, 'bottom')
  model.addPhysicalGroup(2, [bnd[5][1]], 6)
  model.setPhysicalName(2, 6, 'top')
  model.addPhysicalGroup(2, [tag_rect], 7)
  model.setPhysicalName(2, 7, 'square_fault')
  model.addPhysicalGroup(2, [tag_disk], 8)
  model.setPhysicalName(2, 8, 'oval_fault')

  model.addPhysicalGroup(3, [tag_box], 9)
  model.setPhysicalName(3, 9, 'matrix')

  #model.mesh.setSize(model.getEntities(0), 0.1);

  '''
  p() = PointsOf{ Volume{1}; };
  Characteristic Length { PointsOf{ Volume{1}; } } = mylc;
  '''

  factory.synchronize() # needed before meshing
  mesh.generate(3) # (dim)

  gmsh.write(mesh_filename)
  print 'Generated mesh "{0}"'.format(mesh_filename)

  if do_show:
    gmsh.fltk.run()  # start gmsh
  gmsh.finalize() #  needed at the end
  # dim=1; print 'Entities of dim {0}: {1}'.format(dim, model.getEntities(dim))

########################################################################
if __name__ == "__main__":
  params={
    "lc":0.3,
    "Mesh.CharacteristicLengthMin":1,#0.3,
    "Mesh.CharacteristicLengthMax":1,
  }
  generate3DMesh(mesh_filename='3Dcase1b.msh', params=params, do_show=True)
  print 'Finished'
