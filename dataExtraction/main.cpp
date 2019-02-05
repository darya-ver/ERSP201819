#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";

  dataVector vect = dataVector();
  vect.readDirectory( dirName );

  return 0;
}
