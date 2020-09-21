#include "StringMaker.h"

StringMaker::StringMaker() {
  sequenceToReturn = "";
}

StringMaker::~StringMaker() {

}

int StringMaker::lengthOfStringMaker(float standardDev, float mean) {
  float boxMullerNum = boxMuller(randomNum(), randomNum());
  return (int) finalGaussian(standardDev, boxMullerNum, mean);
}

string StringMaker::makeDNASequence(int length, float probA, float probC, float probT, float probG) {
  int nucleotideSelection = 0;
  int numForA = (int)(probA * 100); //25
  int numForC = (int)(probC * 100); //25
  int numForT = (int)(probT * 100); //25
  int quadAStop = numForA - 1;
  int quadCStop = quadAStop + numForC;
  int quadTStop = quadCStop + numForT;
  int quadGStop = 99;
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
  return sequenceToReturn;
}

double StringMaker::randomNum() {
  double temp = ((double) rand() / RAND_MAX);
  return temp;
}

float StringMaker::boxMuller(double randomNumA, double randomNumB) {
  return sqrt(-2 * log(randomNumA)) * cos(2 * M_PI * randomNumB);
}

float StringMaker::finalGaussian(float standardDev, float boxMuller, float mean) {
  return (standardDev * boxMuller) + mean;
}

void StringMaker::resetStringMaker() {
  sequenceToReturn = "";
}
