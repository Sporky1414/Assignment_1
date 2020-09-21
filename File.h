/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

#include <iostream>
#include <fstream>

using namespace std;

class File{
  public:
    File();
    File(string path);
    ~File();

    string readNextLine();
    bool hasDataLeft();
    void writeData(string data);
    void resetInput();

  private:
    string getFilePathFromUser();

    string filePath;
    ifstream input;
    ofstream output;
};
