See https://github.com/pou036/redback/wiki/MOOSE%20on%20Raijin@NCI

Contents of this folder:

.profile

    This is a startup script.  Copy into your home directory and restart the shell.  If all you want is a working Petsc installation, this is all you need to do.

install.pbs

    This downloads petsc, installs petsc, downloads Moose, configures Libmesh, compiles Moose.  First, change the paths with <username> in them to where you want the files to go, then submit to job system with:

    qsub install.pbs

    Note that a single install of Petsc/Moose uses up more than half of the group's current number-of-files quota.  If you edit the files in Windows, remember to run dos2unix before submission.
