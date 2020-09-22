/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

/*
Main file to take in a file of DNA strings, calculate data from those strings, and create 1000 new strings based on that data.
*/

//Import all class headers
#include "File.h" //Class for reading and writing to files
#include "DataHandler.h" //Class to interpret DNA sequences
#include "StringMaker.h" //Class to create 1000 DNA sequences based on data passed to it.

using namespace std;

//Main program. File can be passed as an argument in the command line or can be inputted by the user after the application has started.
int main(int argc, char** argv) {
  //Create File and DataHandler objects for the processing of the DNA file and data colletion
  File *fileHandler;
  DataHandler *dataHandler = new DataHandler();

  //Create variables used to allow for multiple files per running of the program, count how many files are being analyzed, and keep track of what sequence is currently being searched in a file.
  bool continueProgram = true;
  int programCounter = 1;
  int sequenceCounter = 1;

  //Determine if a file path was passed as a command line argument or not. The fileHandler object is initialized based on that answer.
  if(argc < 2) {
    fileHandler = new File();
  } else {
    fileHandler = new File(argv[1]);
  }

  //Write header data to the file.
  fileHandler->writeData("Name: AJ Keenan");
  fileHandler->writeData("Student ID: 2316808");
  fileHandler->writeData("E-mail: akeenan@chapman.edu");
  fileHandler->writeData("Class Name: CPSC 350 - Data Structures");
  fileHandler->writeData("Class Section: 2");
  fileHandler->writeData("Assignment 1");
  fileHandler->writeData("\n\n");

  //Code to read file, calculate data, and write new strings to the file is in this loop.
  while(continueProgram) {
    //Writes section header in the file.
    fileHandler->writeData("Program Set " + to_string(programCounter));

    //Reads sequence from file and passes that, along with the sequence counter, to the dataHandler object for processing.
    while(fileHandler->hasDataLeft()) {
      dataHandler->calculateDataFromString(fileHandler->readNextLine(), sequenceCounter);
      sequenceCounter++;
    }

    //Resets sequence counter for the next file.
    sequenceCounter = 1;

    //Tells dataHandler to finalize the data, as some calculations required the data to be collected first beforehand.
    dataHandler->finalizeData();

    //Writes final data to the file.
    fileHandler->writeData(dataHandler->dataToString());

    //Starts a new section for the 1000 strings.
    fileHandler->writeData("\n1000 New DNA Sequences:\n");

    //Preps the stringMaker object, the lengthToUse variable, and a sequence to write variable for usage.
    StringMaker *stringMaker;
    int lengthToUse = 0;
    string sequenceToWrite;

    //Writes the 1000 strings to the file.
    for (int i = 0; i < 1000; ++i) {
      //Initalizes the StringMaker. A new one is used each time to clear out data.
      stringMaker = new StringMaker();

      //Determines the length of the DNA sequence to be created using the standard deviation and mean found from the original file.
      lengthToUse = stringMaker->lengthOfStringMaker(dataHandler->getStandardDevOfLengths(), dataHandler->getMeanOfLengths());

      //Gets the final DNA sequence using the data generated from the nucleotide probabilities in dataHandler and the length just calculated
      sequenceToWrite = stringMaker->makeDNASequence(lengthToUse, dataHandler->getRelProbA(), dataHandler->getRelProbC(), dataHandler->getRelProbT(), dataHandler->getRelProbG());

      //Writes the sequence to the output file.
      fileHandler->writeData(sequenceToWrite);

      //Deletes stringMaker so it can be reset.
      delete stringMaker;
    }

    //Seperates the 1000 strings from the next section, if one is to exist.
    fileHandler->writeData("\n\n");
    cout << endl;

    //Determines whether or not the program will repeat with another file.
    string choice = "";
    while(true) {
      cout << "Would you like to input another file? Type 'y' for yes and 'n' for no." << endl;
      cin >> choice;
      if (choice[0] == 'y' || choice[0] == 'Y') { //Program will loop again if the first character typed is a y. The fileHandler will be reset as a result and the program counter incremented.
        cout << "Great!" << endl;
        fileHandler->resetInput();
        programCounter++;
        break;
      } else if (choice[0] == 'n' || choice [0] == 'n') { //Program will terminate should the first character typed be an n, since the main while loop boolean will become false.
        cout << "Have a great day!" << endl;
        continueProgram = false;
        break;
      } else { //Repeats the loop, since an invalid answer was given by the user.
        cout << "Invalid Response. Please try again. " << endl;
      }
    }
  }
  //Clears objects from memory.
  delete fileHandler;
  delete dataHandler;
  return 0;
}
