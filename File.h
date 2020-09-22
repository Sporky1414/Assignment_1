/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

//Header file for the File class, which is designed to take in DNA data from a file and write any data to a different output file.

//Libraries needed to take in data and spew out data from user and from a file.
#include <iostream>
#include <fstream>

using namespace std;

class File{
  public:
    //Conrstructors/Destructor
    File();
    File(string path);
    ~File();

    //Methods to take in data from a file, check if data is present, write new data to a file, and reset the file being read.
    string readNextLine();
    bool hasDataLeft();
    void writeData(string data);
    void resetInput();


  private:
    //Method to take in a new file path from the user. Private since the method does not check the validity of a file.
    string getFilePathFromUser();

    //filePath holds the path of the file, input is the file reader, and output is the file writer.
    string filePath;
    ifstream input;
    ofstream output;
};
