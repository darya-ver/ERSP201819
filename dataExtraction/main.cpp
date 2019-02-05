#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";

  dataVector::readDirectory( dirName );

  return 0;
}
