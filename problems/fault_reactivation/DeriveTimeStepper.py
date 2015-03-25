''' Script to plot post-processor values of interest from old simulation
    in order to try and figure out a better time-stepper...
'''

import os, sys, math, csv, copy
import numpy as np
import matplotlib.pyplot as plt
from twisted.test.test_amp import tempSelfSigned

csv_file = '3D_periodic_ts.csv'

time_col_index = 0
temp_col_index = 5
pp_col_index = 4
strainrate_col_index = 9
timestep_col_index = 10

times = [] # times
temps = [] # temperatures
pps = [] # pore pressures
epsdots = [] # strain rates
tss = [] # timesteps
with open(csv_file, 'r') as csvfile:
    reader = csv.reader(csvfile)
    i = 0 # line index
    for row in reader:
        i += 1
        if i == 1:
            # read headers
            headers = row
            # visual check
            print 'Time column header is "{0}"'.format(headers[time_col_index])
            print 'Temperature column header is "{0}"'.format(headers[temp_col_index])
            print 'Pore pressure column header is "{0}"'.format(headers[pp_col_index])
            print 'Strain rate column header is "{0}"\n'.format(headers[strainrate_col_index])
            continue
        # data row
        if not row:
            # handle empty lines (last line for example)
            continue
        times.append(float(row[time_col_index]))
        temps.append(float(row[temp_col_index]))
        pps.append(float(row[pp_col_index]))
        epsdots.append(float(row[strainrate_col_index]))
        tss.append(float(row[timestep_col_index]))
times = np.array(times)
temps = np.array(temps)
pps = np.array(pps)
epsdots = np.array(epsdots)
tss = np.array(tss)

# Pretend to run time-stepping algorithm

def getValue(time_array, value_array, t, previous_i=0):
    ''' Helper function to get new value at given new time
        by interpolation of already computed values 
        at already computed times
    '''
    i = previous_i # index in time_array being checked
    while i < len(time_array) and t > time_array[i]:
        i += 1
    if i == len(time_array):
        # we reached the end
        return value_array[-1], i-1
    else:
        # time_array[i-1] <= t <= time_array[i], let's interpolate
        return value_array[i-1] \
            + (t - time_array[i-1])*(value_array[i] - value_array[i-1])\
            /(time_array[i] - time_array[i-1]), i-1

def computeTimeStepForArray(time_array, value_arrays, coeff=1.05):
    ''' Time stepping algorithm '''
    # Parameters set by user
    percent_change = 0.1 # value between 0 and 1
    direction = 1
    initial_dt = 0.1
    max_dt = 1.0
    # Start algorithm
    for value_array in value_arrays:
        assert len(time_array) == len(value_array)
    nb_arrays = len(value_arrays)
    new_times = []
    dts = [] # array of timesteps to return
    old_value = [None for k in range(nb_arrays)]
    new_value = [None for k in range(nb_arrays)]
    observables = [[] for k in range(nb_arrays)]
    current_t = 0
    i = 0
    while current_t < time_array[-1]:
        if i == 0:
            for k in range(nb_arrays):
                new_value[k], time_index = getValue(time_array, value_arrays[k], current_t)
                observables[k].append(0)
                old_value = copy.deepcopy(new_value)
            dt = initial_dt
            dts.append(dt)
            new_times.append(current_t)
            current_t += dt
            i += 1
            continue
        elif i == 1:
            for k in range(nb_arrays):
                new_value[k], time_index = getValue(time_array, value_arrays[k], current_t)
                observables[k].append(math.fabs((new_value[k]-old_value[k])/dts[-1]))
            old_value = copy.deepcopy(new_value)
            dt = min(max_dt, max(0, dt + dt * percent_change*direction))
            dts.append(dt)
            new_times.append(current_t)
            current_t += dt
            i += 1
            continue
        # we now have access to the last 2 values
        # compute numerical gradient
        for k in range(nb_arrays):
            new_value[k], time_index = getValue(time_array, value_arrays[k], current_t)
            observables[k].append(math.fabs((new_value[k]-old_value[k])/dts[-1]))
        old_value = copy.deepcopy(new_value)
        direction = 1
        for k in range(nb_arrays):
            if (observables[k][-1] > coeff*observables[k][-2]) \
            and (observables[k][-1] > coeff*observables[k][-3]):
                # increasing change, reduce timestep
                direction = -1
                break
        dt = min(max_dt, max(0, dt + dt * percent_change*direction))
        dts.append(dt)
        new_times.append(current_t)
        current_t += dt
        i += 1
    return dts, new_times, [np.array(observables[k]) for k in range(nb_arrays)]

arrays = [temps, pps, epsdots]
nb_arrays = len(arrays)
new_timesteps, new_times, observables \
    = computeTimeStepForArray(times, arrays, coeff=1.03)
#dts_pp, dummy = computeTimeStepForArray(pps)
#dts_epsdot, dummy = computeTimeStepForArray(epsdots)

# plot data
fig, (ax0, ax1, ax2, ax3, ax4) = plt.subplots(nrows=5)
plt.subplots_adjust(hspace=0.7)
ax0.set_title('Temperature')
ax1.set_title('Pore pressure')
ax2.set_title('Strain rate')
ax3.set_title('Time step')
ax4.set_title('Observable')

ax0.plot(times, temps, '-', linewidth=1)
ax1.plot(times, pps, '-', linewidth=1)
ax2.plot(times, epsdots, '-', linewidth=1)
ax3.plot(new_times, new_timesteps, '-', linewidth=1)
ax3.hold(True)
ax3.plot(times, tss, '-', linewidth=1)
ax4.plot(new_times, observables[0], '-', linewidth=1)

print 'Nb of timesteps in original simulation: {0}'.format(len(times))
print 'Nb of timesteps in new simulation: {0}'.format(len(new_times))
plt.show()
print 'Finished'
