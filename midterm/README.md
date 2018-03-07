midterm_submission/                                                                                 0000775 0001773 0001773 00000000000 13247615774 013772  5                                                                                                    ustar   dobbs                           dobbs                                                                                                                                                                                                                  midterm_submission/README                                                                           0000664 0001773 0001773 00000001174 13247615774 014655  0                                                                                                    ustar   dobbs                           dobbs                                                                                                                                                                                                                  This directory contains the work for the BIEN 4290 Midterm
  @author Peter Dobbs
  @datecreated 6 March 2018

//#*FILES*#//

convertG42G4DCM.sh: bash script that converts a file of type ".g4" to a file of type ".g4dcm"
  parameters:
    input_filename  - pathname of the ".g4" file to convert
    output_filename - pathname of the file once it has been converted to ".g4dcm"

runConvertG42G4DCM.sh: bash script that runs convertG42G4DCM.sh on a directory of ".g4" files
  parameters: 
    input_directory  - name of the directory that holds the ".g4" files
    output_directory - name of the directory that will hold the ".g4dcm" files