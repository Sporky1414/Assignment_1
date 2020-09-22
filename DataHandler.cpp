/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 1
*/

#include "DataHandler.h"

//Creates the DataHandler object and initalizes all variables to 0. It will also initialze the "fullMergedSequences" variable to null.
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

//Destructor for Class.
DataHandler::~DataHandler() {

}

//Takes in Data from the string and calculates data that can be calculated without knowing the rest of the sequences.
void DataHandler::calculateDataFromString(string sequence, int sequenceCounter) {
  //Checks if the sequence passed through is a valid sequence of DNA Nucleotides. If it is not, the method will terminate and skip the invalid sequence.
  if(!checkIfValidString(sequence)) {
    cout << "ERROR: Line " << sequenceCounter << " in the file has bad data or is blank. Skipping this line." << endl;
    return;
  }
  //Adds to the number of DNA sequences that have been counted. Used for the mean calcuation.
  numOfStrings++;
  //Seperates sequences in the "fullMergedSequences" variable by an underscore. The sequences must be searched twice in order to get data that was impossible to get without the mean.
  fullMergedSequences += sequence + "_";
  //Increments sumOfLength by the current sequence's length.
  sumOfLength += sequence.length();
  //Iterates through sequence to determine which nucleotides and bigrams are present and count them as such.
  for(int i = 0; i < sequence.length(); ++i) {
    //Counts the nucleotides
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
    //Ensures the sequence being passed through is even before checking for bigrams.
    sequence = ensureEvenLength(sequence, sequenceCounter);
    //Counts the bigrams present.
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

//Calculates data that could not be calculated until are DNA sequences have been accounted for.
void DataHandler::finalizeData() {
  //Mean is calculated
  meanOfLength = float(sumOfLength)/numOfStrings;
  //Preps for second iteration of DNA sequences by initalizing needed intermediary variables for the calculations.
  int tempLength = 0;
  int totalNucleotides = 0;
  float varianceNum = 0;
  float lengthMeanDistance = 0;
  //Iterates through all DNA sequences, now that the mean has been calculated, to determine the variance and the total number of nucleotides.
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
  //Calculates the total number of bigrams for the probability calculations.
  int numOfBigrams = numOfAA + numOfAC + numOfAG + numOfAT + numOfCA + numOfCC + numOfCG + numOfCT + numOfGA + numOfGC + numOfGG + numOfGT + numOfTA + numOfTC + numOfTG + numOfTT;
  //Calculates the variance
  varianceOfLength = varianceNum/numOfStrings;
  //Calculates standard deviation using the variance, since the standard deviation is the square root of the variance.
  standardDevOfLength = sqrt(varianceOfLength);
  //Calculates the propability of each nucleotide appearing in the entire file.
  relProbA = float(numOfA)/totalNucleotides;
  relProbC = float(numOfC)/totalNucleotides;
  relProbG = float(numOfG)/totalNucleotides;
  relProbT = float(numOfT)/totalNucleotides;
  //Calculates the probability of each bigram appearing in the entire file.
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

//Adjusts a DNA sequence if needed to be even in order to properly count bigrams.
string DataHandler::ensureEvenLength(string sequence, int sequenceCounter) {
  //Even-length sequences are ignored and are not touched.
  if(sequence.length() % 2 == 0) {
    return sequence;
  //User is alerted that an odd-length sequence has been found, then adjusts the sequence to be even by appending the first character of the sequence to the end.
  } else {
    cout << "Sequence " << sequenceCounter << " has an odd length. Adding an extra " << sequence[0] << " nucleotide to sequence for bigram probability calculations." << endl;
    string temp = sequence + sequence[0];
    return temp;
  }
}

//Checks if the DNA sequence does not have any illegal characters
bool DataHandler::checkIfValidString(string sequence) {
  //If the sequence is empty, the sequence is not valid.
  if(sequence.length() < 1) {
    return false;
  }
  //Iterates through sequence to check for invalid characters. If an invalid character is found, the method returns false.
  for(int i = 0; i < sequence.length(); ++i) {
    if(sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'T' && sequence[i] != 'G') {
      return false;
    }
  }
  //Since the sequence would have passed both tests to be valid if the function makes it to this point, the sequence is valid and "true" is returned.
  return true;
}

//Compacts all data from the DataHandler calculations into one string and returns it.
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

//Getter for sumOfLength.
int DataHandler::getSumOfLengths() {
  return sumOfLength;
}

//Getter for meanOfLength.
float DataHandler::getMeanOfLengths() {
  return meanOfLength;
}

//Getter for standardDevOfLength.
float DataHandler::getStandardDevOfLengths() {
  return standardDevOfLength;
}

//Getter for relProbA.
float DataHandler::getRelProbA() {
  return relProbA;
}

//Getter for relProbC.
float DataHandler::getRelProbC() {
  return relProbC;
}

//Getter for relProbG.
float DataHandler::getRelProbG() {
  return relProbG;
}

//Getter for relProbT.
float DataHandler::getRelProbT() {
  return relProbT;
}
