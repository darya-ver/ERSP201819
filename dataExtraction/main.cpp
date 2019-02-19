#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";
  
  ///cout << "here 1 \n";
  dataVector vect; 
  vect.readDirectory( dirName );

  // loop through all the nodes and calculate quartiles
  for( auto it2 = vect.allData.begin(); it2 != vect.allData.end(); it2 ++ ) {
    //cerr << "doing test... " << it2->first << endl;
    it2->second->calculateQuartiles();
  }

 // cout << "here 2 \n";
  ofstream outfile("outFile1.txt", ofstream::out );

 // cout << "here 3 \n";
  vect.writeToFile( outfile );

  outfile.close();

  return 0;
}
