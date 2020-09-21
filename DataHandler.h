#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class DataHandler {
  public:
    DataHandler();
    ~DataHandler();

    void calculateDataFromString(string sequence, int sequenceCounter);
    void finalizeData();
    string dataToString();

    //data points
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

  private:
    string ensureEvenLength(string sequence, int sequenceCounter);
    bool checkIfValidString(string sequence);
};
