''' Script to run 6 simulations (to compare with Oka's experiments)

for CONFINEMENT in 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8
do
    echo $CONFINEMENT
    mpiexec -n  1 $EXEC -i Oka.i --n-threads=2 Outputs/csv=true BCs/confinement_left/value=$CONFINEMENT BCs/confinement_right/value=-$CONFINEMENT BCs/confinement_front/value=-$CONFINEMENT BCs/confinement_back/value=$CONFINEMENT
    python create_postprocess_pics_from_csv.py
    mv Oka.csv oka_confinement_${CONFINEMENT}.csv
    mv Oka.e oka_confinement_${CONFINEMENT}.e
    mv pics_postprocess/P-Q/P-Q_00050.png pics_postprocess/P-Q/confinement_${CONFINEMENT}.png
done

'''
import os, sys, random, logging, subprocess, shutil

def getLogger(name, log_file='log.txt', level=logging.INFO):
    ''' Creates logger with given name and level.
        @param[in]   name     - string, logger name
        @param[in]   log_file - string, file name for log file
        @param[in]   level    - int, logging level
        @return[out] logger   - logger instance built
    '''
    logger_name = '{0}_{1}'.format(name, random.random())
    logger = logging.getLogger(logger_name)
    hdlr1 = logging.FileHandler(log_file)
    hdlr2 = logging.StreamHandler(sys.stdout)
    formatter = logging.Formatter('%(asctime)s %(levelname)-8s %(message)s')
    hdlr1.setFormatter(formatter)
    hdlr2.setFormatter(formatter)
    logger.addHandler(hdlr1)
    logger.addHandler(hdlr2)
    logger.setLevel(level)
    return logger

def runSimulations(output_subdir='batch_test', nb_procs=8):
    ''' Run 6 simulations (varying confining pressure) for given parameters '''
    input_file = 'Oka.i'
    normalising_stress = 2.26e6 # Pa
    output_root_dir = 'results'
    output_dir = os.path.join(output_root_dir, output_subdir)
    confining_pressures = {
        1:0.25e6/normalising_stress, # 0.11
        2:0.5e6/normalising_stress,  # 0.221
        3:0.75e6/normalising_stress, # 0.332
        4:1.0e6/normalising_stress,  # 0.442
        5:1.5e6/normalising_stress,  # 0.664
        6:2.0e6/normalising_stress,  # 0.885
    }
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)
    logger = getLogger('sim', os.path.join(output_dir, 'log.txt'), logging.INFO)
    logger.info('='*20)
    shutil.copy(input_file, os.path.join(output_dir, input_file))
    for i in sorted(confining_pressures.keys()):
        logger.info('Running simulation CD{0}...'.format(i))
        exec_loc = '~/projects/redback/redback-opt'
        command = 'mpiexec -n {nb_procs} {exec_loc} -i {input_i} Outputs/csv=true BCs/confinement_left/value={confinement__value} '\
        'BCs/confinement_right/value=-{confinement__value} BCs/confinement_front/value=-{confinement__value} '\
        'BCs/confinement_back/value={confinement__value} Executioner/num_steps=5'.\
        format(nb_procs=nb_procs, input_i=input_file, exec_loc=exec_loc, confinement__value=confining_pressures[i])
        logger.info(command)
        try:
            # copy input file (unaltered!)
            shutil.copy(input_file, os.path.join(output_dir, input_file))
            # Run simulation
            retcode = subprocess.call(command, shell=True)
            if retcode < 0:
                error_msg = 'Child process was terminated by signal {0}'.format(retcode)
                logger.error(error_msg)
            # Rename output file
            shutil.move('Oka.csv', os.path.join(output_dir, 'oka_CD{0}.csv'.format(i)))
            shutil.move('Oka.e',   os.path.join(output_dir, 'oka_CD{0}.e'.format(i)))
            logger.info('\tOutput files moved to {0}'.format(output_dir))
        except:
            logger.error('Execution failed!')
    logger.info('Finished')

if __name__ == '__main__':
    runSimulations(output_subdir='batch_dummy')