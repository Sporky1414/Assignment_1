## Identifying Information: 
a. AJ Keenan
b. Student ID: 2316808
c. akeenan@chapman.edu
d. CPSC 353-01
e. Assignment: PA01 Email 

## Application Purpose
The purpose of this application is to take in data from a file filled with DNA sequences with varying lengths. The file will either be passed through as a command line argument or by the user once the program has started, depending on the user's preference. After taking in the file, the code will determine the sum of all the sequence lengths, the mean of these lengths, the variance of these lengths, and the standard deviation of these lengths. The code will also determine the probabilty of getting any particular nucleotide in the entire file or any particular bigram of nucleotides in the file. For any sequences that contain illegal characters, such as an empty line or a non-nucleotide letter, the sequence will be skipped. If a sequence has an odd length, the first nucleotide of that sequence will be appended to the end of the sequence to get an even length before bigram probability calculations are done. In both sequences, the user will be alerted via the command line which sequences were ignored and which were adjusted for the bigram calculations. Once all the data is collected, the data will be outputted to a file called "AJ_Keenan.out." Following the data being written to the file, the program will then proceed to create 1000 new strings of DNA sequences with their lengths and nucleotides set based on Gaussian distribution applied to the data collected from the file passed through and the probabilities of the nucleotides from the file, respectively. These strings will then be appended to the same file the data was put in. Afterwards, the program will prompt the user if they wish to run through the process again with a new file. If the user wishes to, the program will repeat itself, with the new data being appended to AJ_Keenan.out. If the user does not wish to proceed, it will close out and end.

## Source Files 
a. main.cpp
b. File.h
c. File.cpp
d. DataHandler.h
e. DataHandler.cpp
f. StringMaker.h
g. StringMaker.cpp

## Known Errors: 
   Extra lines at the end of a file will be read by the program. While the program does not account for these lines when processing and collecting data, as it recognizes that the line is not a valid DNA sequence, the user is still alerted to the line's prescence.

## References
a. Class Notes
b. CPlusPlus.com API (IStream, Input/output with files, toupper, operator+ (string), Quick Q: How to square numbers??, to_string, Type conversions, string::substr, log, cos, RAND_MAX)
c. Geeksforgeeks.org (Switch Statement in C/C++)
d. Investopedia.com (Variance Definition)
e. Khan Academy (Standard Deviation)
f. Stack Overflow (How to put a new line inside a string in C++?, How to use the PI constant in C++, rand() between 0 and 1)
g. Linkedin Learning (Learning C++ by Erin Colvin)

## Compilation Instructions
Use the "make all" command, courtesy of the included MAKEFILE, to compile all source files. To run the program, run the assignment1.exe program from any linux terminal, such as in docker. When you run the program, you may pass through the file you wish to run the program on as an argument to save a step when running the program.


