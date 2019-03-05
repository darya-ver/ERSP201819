#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingDataOld";
  
  dataVector vect; 
  vect.readDirectory( dirName );

  // loop through all the nodes and calculate quartiles
  for( auto it2 = vect.allData.begin(); it2 != vect.allData.end(); it2 ++ ) {
    it2->second->calculateQuartiles();
  }

  ofstream outfile("quartilesOld.txt", ofstream::out );

  vect.writeToFile( outfile );

  outfile.close();

  return 0;
}
