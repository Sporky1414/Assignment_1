/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

//Header file for the StringMaker class, which takes in data and, based on that data, returns 1000 DNA sequences.

#include <iostream>
#include <math.h>

using namespace std;

class StringMaker {
  public:
    //Constructor/Destructor
    StringMaker();
    ~StringMaker();

    //Methods to create a DNA sequence of a certain length based on data passed to it.
    int lengthOfStringMaker(float standardDev, float mean);
    string makeDNASequence(int length, float probA, float probC, float probT, float probG);

  private:
    //Methods used to aid in the DNA sequence calculation
    double randomNum();
    float boxMuller(double randomNumA, double randomNumB);
    float finalGaussian(float standardDev, float boxMuller, float mean);

    //Variable holding onto the sequence being worked on as it is being made.
    string sequenceToReturn;
};
