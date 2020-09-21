/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

//Import all class headers
#include "File.h" //Class for reading and writing to files
#include "DataHandler.h" //Class to interpret DNA sequences
#include "StringMaker.h" //Class to create 1000 DNA sequences based on data passed to it.

using namespace std;

//Main program. File can be passed as an argument in the command line or can be inputted by the user after the application has started.
int main(int argc, char** argv) {
  File *fileHandler;
  DataHandler *dataHandler = new DataHandler();
  bool continueProgram = true;
  int programCounter = 1;
  int sequenceCounter = 1;
  if(argc < 2) {
    fileHandler = new File();
  } else {
    fileHandler = new File(argv[1]);
  }
  fileHandler->writeData("Name: AJ Keenan");
  fileHandler->writeData("Student ID: 2316808");
  fileHandler->writeData("E-mail: akeenan@chapman.edu");
  fileHandler->writeData("Class Name: CPSC 350 - Data Structures");
  fileHandler->writeData("Class Section: 2");
  fileHandler->writeData("Assignment 1");
  fileHandler->writeData("\n\n");
  while(continueProgram) {
    fileHandler->writeData("Program Set " + to_string(programCounter));
    while(fileHandler->hasDataLeft()) {
      dataHandler->calculateDataFromString(fileHandler->readNextLine(), sequenceCounter);
      sequenceCounter++;
    }
    sequenceCounter = 1;
    dataHandler->finalizeData();
    fileHandler->writeData(dataHandler->dataToString());
    fileHandler->writeData("\n1000 New DNA Sequences:\n");
    StringMaker *stringMaker;
    int lengthToUse = 0;
    string sequenceToWrite;
    for (int i = 0; i < 1000; ++i) {
      stringMaker = new StringMaker();
      lengthToUse = stringMaker->lengthOfStringMaker(dataHandler->getStandardDevOfLengths(), dataHandler->getMeanOfLengths());
      sequenceToWrite = stringMaker->makeDNASequence(lengthToUse, dataHandler->getRelProbA(), dataHandler->getRelProbC(), dataHandler->getRelProbT(), dataHandler->getRelProbG());
      fileHandler->writeData(sequenceToWrite);
      delete stringMaker;
    }
    fileHandler->writeData("\n\n");
    cout << "Completed Task. ";
    string choice = "";
    while(true) {
      cout << "Would you like to input another file? Type 'y' for yes and 'n' for no." << endl;
      cin >> choice;
      if (choice[0] == 'y' || choice[0] == 'Y') {
        cout << "Great!" << endl;
        fileHandler->resetInput();
        programCounter++;
        break;
      } else if (choice[0] == 'n' || choice [0] == 'n') {
        cout << "Have a great day!" << endl;
        continueProgram = false;
        break;
      } else {
        cout << "Invalid Response. Please try again. " << endl;
      }
    }
  }
  delete fileHandler;
  delete dataHandler;
  return 0;
}
