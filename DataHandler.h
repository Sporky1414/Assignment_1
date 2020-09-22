/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

//Header file for the DataHandler class, which takes in the DNA sequences from the file and calculates data points based off the sequences.

//Includes libraries for user input, math, and the string methods.
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class DataHandler {
  public:
    //Constructor/Destructor
    DataHandler();
    ~DataHandler();

    //Methods to calculate data
    void calculateDataFromString(string sequence, int sequenceCounter);
    void finalizeData();

    //Method to output the data as a string
    string dataToString();

    //Getter methods for variables that are needed outside of DataHandler
    int getSumOfLengths();
    float getMeanOfLengths();
    float getStandardDevOfLengths();
    float getRelProbA();
    float getRelProbC();
    float getRelProbT();
    float getRelProbG();

  private:
    //Private data points needed for all calcuations
    int sumOfLength;
    float meanOfLength;
    float varianceOfLength;
    float standardDevOfLength;
    int numOfStrings;
    int numOfA;
    int numOfC;
    int numOfT;
    int numOfG;
    int numOfAA;
    int numOfAC;
    int numOfAT;
    int numOfAG;
    int numOfCA;
    int numOfCC;
    int numOfCT;
    int numOfCG;
    int numOfTA;
    int numOfTC;
    int numOfTT;
    int numOfTG;
    int numOfGA;
    int numOfGC;
    int numOfGT;
    int numOfGG;
    float relProbA;
    float relProbC;
    float relProbT;
    float relProbG;
    float relProbAA;
    float relProbAC;
    float relProbAT;
    float relProbAG;
    float relProbCA;
    float relProbCC;
    float relProbCT;
    float relProbCG;
    float relProbTA;
    float relProbTC;
    float relProbTT;
    float relProbTG;
    float relProbGA;
    float relProbGC;
    float relProbGT;
    float relProbGG;
    string fullMergedSequences;

    //Methods to check for issues with a DNA sequence
    string ensureEvenLength(string sequence, int sequenceCounter);
    bool checkIfValidString(string sequence);
};
