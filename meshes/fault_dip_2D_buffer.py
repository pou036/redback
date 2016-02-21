# -*- coding: utf-8 -*-
''' Script to change the element physical tags in fault_dip_2D.msh
    in order to add a buffer around the Fault
      +——————————-—-—————————+
      |           +—+        |
      |          / /         |
      |        / /           |
      |      +—+             |
      +———————---————————————+
    Doing this with python script to modify .msh rather than with .geo (the proper way)
'''
from Canvas import Line

def createModifiedMesh(input_geo, input_msh, output_msh, n_layers=1):
    ''' Function to create new mesh by adding padding buffer
    (n elements on top and bottom)'''
    with open(input_geo) as fgeo_in:
        for line in fgeo_in:
            line2 = line.lower().strip()
            if line2.startswith('nb_points_x1'):
                nb_points_x1 = int(line2.split()[2][0:-1])
            elif line2.startswith('nb_points_x2'):
                nb_points_x2 = int(line2.split()[2][0:-1])
            elif line2.startswith('nb_points_x3'):
                nb_points_x3 = int(line2.split()[2][0:-1])
            elif line2.startswith('nb_points_y'):
                nb_points_y = int(line2.split()[2][0:-1])
    nb_bc_elts = 2*(nb_points_x1-1+nb_points_x2-1+nb_points_x3-1) + 2*(nb_points_y-1)
    elt_indices_to_change = []
    for i_col in range(nb_points_x2-1):
        n1 = nb_bc_elts + (nb_points_x1+i_col-1)*(nb_points_y-1) + 1
        #n2 = n1 + n_layers
        n4 = n1 + (nb_points_y-1)
        #n3 = n4 - n_layers
        elt_indices_to_change += range(n1, n1+n_layers) + range(n4-n_layers, n4)
    #import pdb;pdb.set_trace()
    with open(input_msh) as fmsh_in:
        with open(output_msh, 'wb') as f_out:
            in_element_block = False
            for line in fmsh_in:
                if not in_element_block and line.lower().startswith('$elements'):
                    in_element_block = True
                if not in_element_block:
                    f_out.write(line)
                    continue
                # Now reading an element line
                tmp = line.split()
                if len(tmp) == 9 and int(tmp[0]) in elt_indices_to_change:
                    tmp[3] = '0'
                    new_line = ' '.join(tmp) + '\n'
                    f_out.write(new_line)
                else:
                    f_out.write(line)
    return

if __name__ == '__main__':
    createModifiedMesh(input_geo='fault_dip_2D.geo',
                       input_msh='fault_dip_2D_thin.msh',
                       output_msh='fault_dip_2D_thin2.msh',
                       n_layers=3)
    print 'Finished'
