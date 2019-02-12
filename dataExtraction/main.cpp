#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";

  dataVector vect = dataVector();
  vect.readDirectory( dirName );

  ofstream outfile("outFile.txt", ofstream::out );

  vect.writeToFile( outfile );

  outfile.close();

  return 0;
}
