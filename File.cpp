/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

#include "File.h"

//Creates a File object should no path be passed as an argument.
File::File() {
  //Gets path from user, as one was not passed as an argument.
  filePath = getFilePathFromUser();

  //Loop to continue until a valid file path is found.
  while (true) {

    //Attempts to open the file.
    input.open(filePath);

    //Checks if file opened properly or not. If it opened properly, the loop ends. If not, the input will be reset and the user will be prompted to try another file name.
    if(!input.fail()) {
      break;
    } else {
      input.close();
      cout << "ERROR: Invalid file path. Please try again." << endl;
      filePath = getFilePathFromUser();
    }
  }

  //Preps the output file once the input is set up.
  output.open("AJ_Keenan.out");
}

//Creates a file object based on the path passed as an argument.
File::File(string path) {
  //Checks if file at string path is valid. The loop continues until the file path is determined to be valid.
  while(true) {

    //Attempts to open the file.
    input.open(path);

    //Checks if file opened properly or not. If it opened properly, the loop ends. If not, the input will be reset and the user will be prompted to try another file name.
    if(!input.fail()) {
      break;
    } else {
      input.close();
      cout << "ERROR: Invalid file path. Please try again." << endl;
      path = getFilePathFromUser();
    }
  }
  //Sets filePath global variable to the path just confirmed to be valid and preps the output file.
  filePath = path;
  output.open("AJ_Keenan.out");
}

//Closes out the input and output streams.
File::~File() {
  input.close();
  output.close();
}

//Reads the next line in the file
string File::readNextLine() {
  //Creates a temporary string to hold the next line from the file.
  string tempString;

  //Passes the next line in a file to tempString
  input >> tempString;

  //toReturn and tempChar variables created to aid in capitalizing the sequence.
  string toReturn = "";
  char tempChar = '\0';

  //Checks each char in tempString to ensure it is capitalized.
  for(int i = 0; i < tempString.length(); ++i) {
    tempChar = tempString[i];
    tempString[i] = toupper(tempChar);
  }
  //Returns the capitalized data.
  return tempString;
}

//Gets the file path from the user, but does not validate the file.
string File::getFilePathFromUser() {
  cout << "Enter File Name" << endl;
  string tempPath;
  cin >> tempPath;
  return tempPath;
}

//Checks if the file has data left. Needed because input is private and the main class needs to access input.eof().
bool File::hasDataLeft() {
  return !input.eof();
}

//Appends the argument string, data, to the end of the output file.
void File::writeData(string data) {
  output << data << endl;
}

//Resets the input stream to work with a new file.
void File::resetInput() {
  string path = "";
  //Closes out the input stream to prep it for being reset.
  if(input.is_open()) {
    input.close();
  }
  //Gets new path from user.
  path = getFilePathFromUser();
  while (true) {

    //Attempts to open the file.
    input.open(path);

    //Checks if file opened properly or not. If it opened properly, the loop ends. If not, the input will be reset and the user will be prompted to try another file name.
    if(!input.fail()) {
      break;
    } else {
      input.close();
      cout << "ERROR: Invalid file path. Please try again." << endl;
      path = getFilePathFromUser();
    }
  }
  //Sets global filePath variable to the now validated path string.
  filePath = path;
}
