/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

#include "StringMaker.h"

//Constructor for StringMaker initalizes the sequenceToReturn variable.
StringMaker::StringMaker() {
  sequenceToReturn = "";
}

//Destructor
StringMaker::~StringMaker() {

}

//Determines how long a given string will be using Gaussian distribution from the standard deviation/mean passed as arguments.
int StringMaker::lengthOfStringMaker(float standardDev, float mean) {
  //Takes two random numbers to find the Box Muller Transformation number.
  float boxMullerNum = boxMuller(randomNum(), randomNum());
  //Calculates the Gaussian Distribution using the standard deviation, Box Muller Transformation number, and the mean.
  return (int) finalGaussian(standardDev, boxMullerNum, mean);
}

//Creates the DNA sequence based on the desired length and the probabilty to get each nucleotide.
string StringMaker::makeDNASequence(int length, float probA, float probC, float probT, float probG) {
  //Variable that holds the nucleotide selection to be used.
  int nucleotideSelection = 0;
  //Determines what stop points between a number from 0 to 99 will there be a switch between nucleotides. The stop points are determined by the probabilities passed as arguments.
  int numForA = (int)(probA * 100);
  int numForC = (int)(probC * 100);
  int numForT = (int)(probT * 100);
  int quadAStop = numForA - 1;
  int quadCStop = quadAStop + numForC;
  int quadTStop = quadCStop + numForT;
  int quadGStop = 99;
  //Selects each nucleotide by generating a random number, then comparing it to the stop points. For example, if the stop points are 24 for A, 49 for C, 74 for T, and 99 for G,
  //a nucleotide selection less than 24 will give an 'A' nucleotide, less than 49 will give a 'C' nucleotide, less than 74 a 'T' nucleotide, and less than 99 a 'G' nucleotide.
  for(int i = 0; i < length; ++i) {
    nucleotideSelection = (randomNum() * 100);
    if(nucleotideSelection <= quadAStop) {
      sequenceToReturn += 'A';
    } else if (nucleotideSelection <= quadCStop) {
      sequenceToReturn += 'C';
    } else if (nucleotideSelection <= quadTStop) {
      sequenceToReturn += 'T';
    } else {
      sequenceToReturn += 'G';
    }
  }
  //Once the sequence is built, it is returned.
  return sequenceToReturn;
}

//Returns a random number from 0 to 1 exclusive.
double StringMaker::randomNum() {
  double temp = ((double) rand() / RAND_MAX);
  return temp;
}

//Returns the calculation of the Box Muller transformation using the two random numbers passed as arguments.
float StringMaker::boxMuller(double randomNumA, double randomNumB) {
  return sqrt(-2 * log(randomNumA)) * cos(2 * M_PI * randomNumB);
}

//Returns the final Gaussian Distribution calculation.
float StringMaker::finalGaussian(float standardDev, float boxMuller, float mean) {
  return (standardDev * boxMuller) + mean;
}
