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
