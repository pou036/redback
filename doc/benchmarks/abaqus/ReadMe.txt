###################################################
#                                                 #
#   tuto to compare abaqus to redback benchmarks  #
#                                                 #
####################################################

They have input files .inp in abaqus folder,
you can run it on abaqus : file import Model

before that

be careful that in abaqus software the Set Work Directory is for ;
doc/benchmarks/abaqus/ (were they have Pythons files)

if you want abaqus for benchmarks :
https://academy.3ds.com/en/software/abaqus-student-edition
The Abaqus Student Edition is available free of charge to students,
educators, and researchers for personal and educational use.
The Abaqus SE is available on Windows platform only and supports
structural models up to 1000 nodes and CFD models to 10,000 nodes.
The full documentation collection in HTML format makes this the perfect
Abaqus learning tool both on campus or on the move.

after that

you can generate a folder in output_csv_folder with .csv files with results of
one physical dimension for one element on one integration point.
To do that use the script : odb2csv.py and read informations to exctract the
relevent data

In tmp folder (doc/benchmarks/abaqus/tmp) they have all results for one
test in just only csv file with the name of the test
