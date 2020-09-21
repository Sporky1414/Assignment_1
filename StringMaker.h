#include <iostream>
#include <math.h>

using namespace std;

class StringMaker {
  public:
    StringMaker();
    ~StringMaker();
    int lengthOfStringMaker(float standardDev, float mean);
    string makeDNASequence(int length, float probA, float probC, float probT, float probG);
    void resetStringMaker();

  private:
    double randomNum();
    float boxMuller(double randomNumA, double randomNumB);
    float finalGaussian(float standardDev, float boxMuller, float mean);
    string sequenceToReturn;
};