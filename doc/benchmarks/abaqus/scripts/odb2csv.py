''' Script to extract all elemental data from Abaqus odb for a given element/integration point
    and write it in csv file. 
    
    All data from the odb file is extract, so the output csv name get 'full'.
    To select your interest data from the full csv use the fullcsv2goldcsv.py file
    
    To run this script, do ;
    open abaqus/CAE 
    open your .cae file 
    in file clic Select Work Directory to select your good place to generate outputs files
    in file clic Run Script
    
    Assumptions:
        * there must be only a single element type in the whole mesh
'''
import odbAccess
from abaqusConstants import * 
import csv, os, numpy
print 'Current (Abaqus) directory = ',os.getcwd()
import odbcsv2goldcsv
try:
    import odbcsv2goldcsv
except:
    error_msg = 'You need to set the Abaqus Work Directory to the location containing the file "odbcsv2goldcsv.py"'
    raise Exception, error_msg

odb_name = 'C:\\Users\\OlivierSimonnot\\Dropbox\\UNSW\\Abaqus\\benchmarks\\benchmark_3_M\\bench_elastic_1\\Job-1.odb'
output_csv_filename = 'bench_abaqus_elastic_01.csv' 
'''output_csv_folderway = C:\\Users\\OlivierSimonnot\\Dropbox\\UNSW\\Abaqus\\folder for redback tests\\bench_3M\\gold'''
supported_types = ['C3D20R', 'CPS4R',
'AC1D2','AC1D3','AC2D3','AC2D4','AC2D6','AC2D8','AC3D4','AC3D6','AC3D8','AC3D10','AC3D15',
'AC3D20','ACAX3','ACAX4','ACAX6','ACAX8','ACIN2D2','ACIN2D3','ACIN3D3',
'ACIN3D4','ACIN3D6','ACIN3D8','ACINAX2','ACINAX3','ASI1','ASI2','ASI2A',
'ASI2D2','ASI2D2','ASI2D2','ASI3A','ASI3A','ASI3A','ASI3A','ASI3A','ASI3A',
'ASI3A','ASI3A','ASI3A','ASI3A','B21','B21','B22','B22H','B23','B23H','B31','B31H','B31OS','B31OSH','B32','B32H',
'B32OS','B32OSH','B33','B33H','C3D4','C3D4E','C3D4H','C3D4P','C3D4T','C3D6','C3D6E','C3D6H','C3D6P','C3D6T','C3D8','C3D8E','C3D8H','C3D8HT',
'C3D8I','C3D8IH','C3D8P','C3D8PH','C3D8PHT','C3D8PT','C3D8R','C3D8RH','C3D8RHT','C3D8RP','C3D8RPH','C3D8RPHT','C3D8RPT','C3D8RT','C3D8T',
'CAX3','CAXE','CAX3H','CAX3H','CAX4','CAX4E','CAX4H','CAX4HT','CAX4I','CAX4IH','CAX4P','CAX4PH','CAX4PT','CAX4R','CAX4RH','CAX4RHT','CAX4RP','CAX4RPH','CAX4RPHT',
'CAX4RPT','CAX4RT','CAX4RT','CGAX3','CGAX3H','CGAX3HT','CGAX3T'] 
step_name = 'test'
part_name = 'PART-1'
selected_element_index = 1
selected_integration_point_index = 1
INVARIANTS = [PRESS, MISES] # which stress invariants to export

##########################################
def getValidVtkName(field_keyword):
    ''' convert keyword in string acceptable for VTK (no spaces) '''
    return field_keyword.replace(' ' ,'_')

# Extract data from odb file. 
odb = odbAccess.openOdb(path=odb_name)

# get access to the nodal displacement data
step_names = odb.steps.keys()
print 'Steps in this simulation: %s' %(step_names)
print 'Working on step %s' %(step_name)
nb_frames = len(odb.steps[step_name].frames)
frame = odb.steps[step_name].frames[-1]
disp = frame.fieldOutputs['U'] # displacement (at nodes) 

# get access to the part instance -- through which you can access the undeformed nodal position coordinates
try:
    part_instance = odb.rootAssembly.instances[part_name]
except:
    error_msg = 'Inexistant part. Existing parts: ', odb.rootAssembly.instances.keys()
    raise Exception, error_msg
nb_elements = len(part_instance.elements)
nb_nodes = len(part_instance.nodes)

# find element type. This script only supports one single element type!
# list (set) of all element types used in the  model
elt_types = set(elt.type for elt in part_instance.elements)
print 'This model contains the following elements: %s' %(elt_types)
if len(elt_types)!=1:
    msg = "Can't deal with more than 1 element type for now..."
    raise Exception, msg
for elt_type in elt_types:
    if elt_type not in supported_types:
        msg = 'Type %s not supported yet!' %(elt_type)
        raise Exception, msg
elt_type = elt_types.pop() # single element type in this model

# find dimensionality of our problem
dim = None
if part_instance.embeddedSpace == odbAccess.TWO_D_PLANAR:
    dim = 2
elif part_instance.embeddedSpace == odbAccess.THREE_D:
    dim = 3
if dim is None:
    raise Exception, "Can't handle dimensionality %s!?!" \
        %(part_instance.embeddedSpace)

# find out if double precision is used
use_double = None # flag, using double precision or not?
try:
    disp.values[0].data
    use_double = False
except:
    pass
try:
    disp.values[0].dataDouble
    use_double = True
except:
    pass
if use_double is None:
    raise Exception, 'Could not figure out if single or double precision was used'

dir_path = os.path.split(os.path.realpath(odb_name))[0]
full_out_filename = os.path.join(dir_path, output_csv_filename)
has_printed_nb_ips = False
with open(full_out_filename , 'wb') as out_file:
    csv_writer = csv.writer(out_file)
    
    # Identify size of data by reading one timestep
    data_sizes = {}
    frame = odb.steps[step_name].frames[0]
    for f in frame.fieldOutputs.values():
        #print '\tFound data "%s" (%s) -- %s, %s' \
        #    %(f.name, f.description, f.type, f.locations[0].position)
        data_f = f.values
        if f.locations[0].position == odbAccess.INTEGRATION_POINT:
            data_name = f.name
            sample_data = None
            for data in data_f:
                ip_id = data.integrationPoint
                index = data.elementLabel
                if use_double:
                    sample_data = data.dataDouble
                else:
                    sample_data = data.data
                break
            assert sample_data is not None
            data_length = 1
            if type(sample_data) in [list, numpy.ndarray]:
                data_length = len(sample_data)
            data_sizes[data_name] = data_length
            # Stress is a special case, it has invariants
            if data_name == 'S':
                for invariant in INVARIANTS:
                    ff = f.getScalarField(invariant)
                    subdata_name = ff.name
                    data_ff = ff.values
                    sample_data = None
                    for data in data_ff:
                        ip_id = data.integrationPoint
                        index = data.elementLabel
                        if use_double:
                            sample_data = data.dataDouble
                        else:
                            sample_data = data.data
                        break
                    assert sample_data is not None
                    data_length = 1
                    if type(sample_data) in [list, numpy.ndarray]:
                        data_length = len(sample_data)
                    data_sizes[subdata_name] = data_length
    
    # write header
    data_names = sorted(data_sizes.keys())
    header = ['timestep', 'time']
    for data_name in data_names:
        data_size = data_sizes[data_name]
        if data_size > 1:
            for i in range(data_size):
                header.append('{0}[{1}]'.format(data_name,i+1))
        else:
            header.append(data_name)
    csv_writer.writerow(['dimensionality',dim,'Element index:',selected_element_index, 'Integration point:',selected_integration_point_index])
    csv_writer.writerow(header)

    # Loop on all timesteps
    for frame_i in range(nb_frames):
        frame = odb.steps[step_name].frames[frame_i]
        frame_time = frame.frameId
        #disp = frame.fieldOutputs['U'] # displacement (at nodes) 

        # read data at nodes and elements
        data_nodes = {} # key=node_index, value=dict{field_keyword:value}
        data_elts = {} # key=elt_index, value=dict{field_keyword:value}
        nodal_keywords = {} # key=keywords of fields defined at nodes, value=type of data 
        elt_keywords = {} # key=keywords of fields defined at elements, value=type of data 
        #   (SCALAR, VECTOR, TENSOR_2D_PLANAR, TENSOR_3D_FULL...)
        
        # TODO: optimise script to read only required data
        
        # Thomas playing
        if 0:
            print 'Thomas playing'
            stress = frame.fieldOutputs['S'].values
            for elt_i in range(nb_elements):
                print '%s --> S=%s'%(elt_i, stress[elt_i].data)

        # from now on we know there's only 1 element type. Get number of integration points
        nb_ips = None # number of integration points. Will be set when reading first data at elements.
        for f in frame.fieldOutputs.values():
            #print '\tFound data "%s" (%s) -- %s, %s' \
            #   %(f.name, f.description, f.type, f.locations[0].position)
            data_f = f.values
            if f.locations[0].position == odbAccess.INTEGRATION_POINT:
                elt_keywords[f.name] = f.type
                '''for elt_i in range(nb_elements):
                    if elt_i not in data_elts:
                        data_elts[elt_i] = {}
                    if use_double:
                        data_elts[elt_i][f.name] = data_f[elt_i].dataDouble
                    else:
                        data_elts[elt_i][f.name] = data_f[elt_i].data'''
                # find number of integration points once and for all 
                if nb_ips is None:
                    nb_ips = len(data_f)/nb_elements # 4 integration points this element type
                    if not has_printed_nb_ips:
                        print '(Element %s has %s integration points)'%(elt_type, nb_ips)
                        has_printed_nb_ips = True
                # get values
                for data in data_f:
                    ip_id = data.integrationPoint
                    index = data.elementLabel
                    if index not in data_elts:
                        data_elts[index] = {}
                    if ip_id not in data_elts[index]:
                        data_elts[index][ip_id] = {}
                    if use_double:
                        data_elts[index][ip_id][f.name] = data.dataDouble
                    else:
                        data_elts[index][ip_id][f.name] = data.data
                    #if f.name == 'S':
                    #    print 'index=%s, IP=%s, S=%s'%(index, ip_id, data_elts[index][ip_id][f.name])
                # Get stress invariants
                if f.name == 'S':
                    for invariant in INVARIANTS:
                        ff = f.getScalarField(invariant)
                        data_ff = ff.values
                        for data in data_ff:
                            ip_id = data.integrationPoint
                            index = data.elementLabel
                            if index not in data_elts:
                                data_elts[index] = {}
                            if ip_id not in data_elts[index]:
                                data_elts[index][ip_id] = {}
                            if use_double:
                                data_elts[index][ip_id][ff.name] = data.dataDouble
                            else:
                                data_elts[index][ip_id][ff.name] = data.data
            elif f.locations[0].position == odbAccess.NODAL:
                pass
                '''nodal_keywords[f.name] = f.type
                for index in range(nb_nodes):
                    node_i = data_f[index].nodeLabel
                    if node_i not in data_nodes:
                        data_nodes[node_i] = {}
                    if use_double:
                        data_nodes[node_i][f.name] = data_f[index].dataDouble
                    else:
                        data_nodes[node_i][f.name] = data_f[index].data'''
                        
        requested_values = [frame_i, frame_time]
        for data_name in data_names:
            try:
                tmp = data_elts[selected_element_index][selected_integration_point_index][data_name]
                data_size = data_sizes[data_name]
                if data_size > 1:
                    for i in range(data_size):
                        requested_values.append(tmp[i])
                else:
                    requested_values.append(tmp)
            except:
                raise Exception, 'Invalid requested field "{0}". Available options: {1}'.format(export_field, data_elts[selected_element_index][selected_integration_point_index].keys())
    
        # write info to csv
        csv_writer.writerow(requested_values)

print 'Wrote "%s"'%(full_out_filename)

# Excecute other python script to generate all gold csv files
odbcsv2goldcsv.odbcsv2goldcsv(full_out_filename, 
                              os.path.join(dir_path, os.path.splitext(output_csv_filename)[0]),
                              properties=['S.Mises', 'S.Pressure'])
odb.close()
print 'Finished'