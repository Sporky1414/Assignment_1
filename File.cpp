#include "File.h"

File::File() {
  File(getFilePathFromUser());
}

File::File(string path) {
  while(true) {
    input.open(path);
    if(!input.fail()) {
      break;
    } else {
      input.close();
      cout << "ERROR: Invalid file path. Please try again." << endl;
      path = getFilePathFromUser();
    }
  }
  filePath = path;
  output.open("AJ_Keenan.out");
}

File::~File() {
  input.close();
  output.close();
}

string File::readNextLine() {
  string tempString;
  input >> tempString;
  string toReturn = "";
  char tempChar = '\0';
  for(int i = 0; i < tempString.length(); ++i) {
    tempChar = tempString[i];
    tempString[i] = toupper(tempChar);
  }
  return tempString;
}

string File::getFilePathFromUser() {
  cout << "Enter File Name" << endl;
  string tempPath;
  cin >> tempPath;
  return tempPath;
}

bool File::hasDataLeft() {
  return !input.eof();
}

void File::writeData(string data) {
  output << data << endl;
}

void File::resetInput() {
  string path = "";
  if(input.is_open()) {
    input.close();
  }
  path = getFilePathFromUser();
  while(true) {
    input.open(path);
    if(!input.fail()) {
      break;
    } else {
      input.close();
      cout << "ERROR: Invalid file path. Please try again." << endl;
      path = getFilePathFromUser();
    }
  }
  filePath = path;
}
