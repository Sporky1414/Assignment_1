/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

#include "DataHandler.h"

DataHandler::DataHandler() {
  int sumOfLength = 0;
  float meanOfLength = 0;
  float varianceOfLength = 0;
  float standardDevOfLength = 0;
  int numOfStrings = 0;
  int numOfA = 0;
  int numOfC = 0;
  int numOfT = 0;
  int numOfG = 0;
  int numOfAA = 0;
  int numOfAC = 0;
  int numOfAT = 0;
  int numOfAG = 0;
  int numOfCA = 0;
  int numOfCC = 0;
  int numOfCT = 0;
  int numOfCG = 0;
  int numOfTA = 0;
  int numOfTC = 0;
  int numOfTT = 0;
  int numOfTG = 0;
  int numOfGA = 0;
  int numOfGC = 0;
  int numOfGT = 0;
  int numOfGG = 0;
  float relProbA = 0;
  float relProbC = 0;
  float relProbT = 0;
  float relProbG = 0;
  float relProbAA = 0;
  float relProbAC = 0;
  float relProbAT = 0;
  float relProbAG = 0;
  float relProbCA = 0;
  float relProbCC = 0;
  float relProbCT = 0;
  float relProbCG = 0;
  float relProbTA = 0;
  float relProbTC = 0;
  float relProbTT = 0;
  float relProbTG = 0;
  float relProbGA = 0;
  float relProbGC = 0;
  float relProbGT = 0;
  float relProbGG = 0;
  string fullMergedSequences = "";
}

DataHandler::~DataHandler() {

}

void DataHandler::calculateDataFromString(string sequence, int sequenceCounter) {
  if(!checkIfValidString(sequence)) {
    cout << "ERROR: Line " << sequenceCounter << " in the file has bad data or is blank. Skipping this line." <<  "\n" << endl;
    return;
  }
  numOfStrings++;
  fullMergedSequences += sequence + "_";
  sumOfLength += sequence.length();
  for(int i = 0; i < sequence.length(); ++i) {
    switch (sequence[i]) {
      case 'A':
        numOfA++;
        break;
      case 'C':
        numOfC++;
        break;
      case 'T':
        numOfT++;
        break;
      default:
        numOfG++;
        break;
    }
    sequence = ensureEvenLength(sequence, sequenceCounter);
    if(i != 0 && i % 2 == 1) {
      string bigram = sequence.substr(i - 1, 2);
      if(bigram == "AA") {
        numOfAA++;
      } else if (bigram == "AC") {
        numOfAC++;
      } else if (bigram == "AT") {
        numOfAT++;
      } else if (bigram == "AG") {
        numOfAG++;
      } else if (bigram == "CA") {
        numOfCA++;
      } else if (bigram == "CC") {
        numOfCC++;
      } else if (bigram == "CT") {
        numOfCT++;
      } else if (bigram == "CG") {
        numOfCG++;
      } else if (bigram == "TA") {
        numOfTA++;
      } else if (bigram == "TC") {
        numOfTC++;
      } else if (bigram == "TT") {
        numOfTT++;
      } else if (bigram == "TG") {
        numOfTG++;
      } else if (bigram == "GA") {
        numOfGA++;
      } else if (bigram == "GT") {
        numOfGT++;
      } else if (bigram == "GC") {
        numOfGC++;
      } else {
        numOfGG++;
      }
    }
  }
}

void DataHandler::finalizeData() {
  meanOfLength = float(sumOfLength)/numOfStrings;
  //Variance, Standard Deviation, and Setup for Probabilities
  int tempLength = 0;
  int totalNucleotides = 0;
  float varianceNum = 0;
  float lengthMeanDistance = 0;
  for(int i = 0; i < fullMergedSequences.length(); ++i) {
    if(fullMergedSequences[i] != '_') {
      tempLength++;
      totalNucleotides++;
    } else {
      lengthMeanDistance = abs(tempLength - meanOfLength);
      varianceNum += pow(lengthMeanDistance, 2);\
      tempLength = 0;
    }
  }
  int numOfBigrams = numOfAA + numOfAC + numOfAG + numOfAT + numOfCA + numOfCC + numOfCG + numOfCT + numOfGA + numOfGC + numOfGG + numOfGT + numOfTA + numOfTC + numOfTG + numOfTT;
  varianceOfLength = varianceNum/numOfStrings;
  standardDevOfLength = sqrt(varianceOfLength);
  relProbA = float(numOfA)/totalNucleotides;
  relProbC = float(numOfC)/totalNucleotides;
  relProbG = float(numOfG)/totalNucleotides;
  relProbT = float(numOfT)/totalNucleotides;
  relProbAA = float(numOfAA)/numOfBigrams;
  relProbAC = float(numOfAC)/numOfBigrams;
  relProbAG = float(numOfAG)/numOfBigrams;
  relProbAT = float(numOfAT)/numOfBigrams;
  relProbCA = float(numOfCA)/numOfBigrams;
  relProbCC = float(numOfCC)/numOfBigrams;
  relProbCG = float(numOfCG)/numOfBigrams;
  relProbCT = float(numOfCT)/numOfBigrams;
  relProbGA = float(numOfGA)/numOfBigrams;
  relProbGC = float(numOfGC)/numOfBigrams;
  relProbGG = float(numOfGG)/numOfBigrams;
  relProbGT = float(numOfGT)/numOfBigrams;
  relProbTA = float(numOfTA)/numOfBigrams;
  relProbTC = float(numOfTC)/numOfBigrams;
  relProbTG = float(numOfTG)/numOfBigrams;
  relProbTT = float(numOfTT)/numOfBigrams;
}

string DataHandler::ensureEvenLength(string sequence, int sequenceCounter) {
  if(sequence.length() % 2 == 0) {
    return sequence;
  } else {
    cout << "Sequence " << sequenceCounter << " has an odd length. Adding an extra " << sequence[0] << " nucleotide to sequence for bigram probability calculations." << endl;
    cout << "Old Sequence: " << sequence << endl;
    string temp = sequence + sequence[0];
    cout << "New Sequence: " << temp <<  "\n" << endl;
    return temp;
  }
}

bool DataHandler::checkIfValidString(string sequence) {
  if(sequence.length() < 1) {
    return false;
  }
  for(int i = 0; i < sequence.length(); ++i) {
    if(sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'T' && sequence[i] != 'G') {
      return false;
    }
  }
  return true;
}

string DataHandler::dataToString() {
  string temp = "\nSum of DNA Sequence Lengths in File: " + to_string(sumOfLength) +'\n';
  temp +=  "Mean of DNA Sequence Lengths in File: " + to_string(meanOfLength) + '\n';
  temp += "Variance of DNA Sequence Lengths in File: " + to_string(varianceOfLength) + '\n';
  temp += "Standard Deviation of DNA Sequence Lengths in File: " + to_string(standardDevOfLength) + '\n';
  temp += "Probability of A in DNA Sequences: " + to_string(relProbA) + '\n';
  temp += "Probability of C in DNA Sequences: " + to_string(relProbC) + '\n';
  temp += "Probability of G in DNA Sequences: " + to_string(relProbG) + '\n';
  temp += "Probability of T in DNA Sequences: " + to_string(relProbT) + '\n';
  temp += "Probability of AA in DNA Sequences: " + to_string(relProbAA) + '\n';
  temp += "Probability of AC in DNA Sequences: " + to_string(relProbAC) + '\n';
  temp += "Probability of AG in DNA Sequences: " + to_string(relProbAG) + '\n';
  temp += "Probability of AT in DNA Sequences: " + to_string(relProbAT) + '\n';
  temp += "Probability of CA in DNA Sequences: " + to_string(relProbCA) + '\n';
  temp += "Probability of CC in DNA Sequences: " + to_string(relProbCC) + '\n';
  temp += "Probability of CG in DNA Sequences: " + to_string(relProbCG) + '\n';
  temp += "Probability of CT in DNA Sequences: " + to_string(relProbCT) + '\n';
  temp += "Probability of GA in DNA Sequences: " + to_string(relProbGA) + '\n';
  temp += "Probability of GC in DNA Sequences: " + to_string(relProbGC) + '\n';
  temp += "Probability of GG in DNA Sequences: " + to_string(relProbGG) + '\n';
  temp += "Probability of GT in DNA Sequences: " + to_string(relProbGT) + '\n';
  temp += "Probability of TA in DNA Sequences: " + to_string(relProbTA) + '\n';
  temp += "Probability of TC in DNA Sequences: " + to_string(relProbTC) + '\n';
  temp += "Probability of TG in DNA Sequences: " + to_string(relProbTG) + '\n';
  temp += "Probability of TT in DNA Sequences: " + to_string(relProbTT) + '\n';
  return temp;
}

int DataHandler::getSumOfLengths() {
  return sumOfLength;
}

float DataHandler::getMeanOfLengths() {
  return meanOfLength;
}

float DataHandler::getStandardDevOfLengths() {
  return standardDevOfLength;
}

float DataHandler::getRelProbA() {
  return relProbA;
}

float DataHandler::getRelProbC() {
  return relProbC;
}

float DataHandler::getRelProbG() {
  return relProbG;
}

float DataHandler::getRelProbT() {
  return relProbT;
}
