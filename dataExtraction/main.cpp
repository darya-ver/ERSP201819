#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";
  
  ///cout << "here 1 \n";
  dataVector vect; 
  vect.readDirectory( dirName );

 // cout << "here 2 \n";
  ofstream outfile("outFile1.txt", ofstream::out );

 // cout << "here 3 \n";
  vect.writeToFile( outfile );

  outfile.close();

  return 0;
}
