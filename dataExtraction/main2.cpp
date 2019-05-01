#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirNameOld = "./testingDataOld";
  
  dataVector vectOld; 
  vectOld.readDirectory( dirNameOld );
  
  vector<string> names;

  ofstream outfileOld("pythonListsOldOMG.txt", ofstream::out );

  //unordered_map<string, vector<dataNode *> testsAndStuff;

  // loop through all the nodes and calculate quartiles
  for( auto it2 = vectOld.allData.begin(); it2 != vectOld.allData.end(); it2 ++ ) {
    names.push_back( it2->second->testName );
  }
  
  // writing all the lists to a file 
  for(int i = 0; i < names.size(); i++ ) {
    string num = names[i] + ",";
    outfileOld.write( num.c_str(), num.length() );
  }
  outfileOld.write( "\n", 1 );

  /*
   *  THROUGHPUT
   */
  outfileOld.write( "throughputs\n", 12 );

  for( auto it = vectOld.allData.begin(); it != vectOld.allData.end(); it++ ) {
    it->second->writeNodeT( outfileOld );
  }
  
  /*
   *  THROUGHPUT
   */
  outfileOld.write( "bandwidths\n", 11 );

  for( auto it = vectOld.allData.begin(); it != vectOld.allData.end(); it++ ) {
    it->second->writeNodeB( outfileOld );
  }

  outfileOld.close();


/*
  NEW STUFF





*/

  const string dirNameNew = "./testingData";
    
  dataVector vectNew; 
  vectNew.readDirectory( dirNameNew );

  ofstream outfileNew("pythonListsNewOMG.txt", ofstream::out );

  //unordered_map<string, vector<dataNode *> testsAndStuff;

  // // loop through all the nodes and calculate quartiles
  // for( auto it2 = vectNew.allData.begin(); it2 != vectNew.allData.end(); it2 ++ ) {
  //   names.push_back( it2->second->testName );
  // }
  
  // writing all the lists to a file 
  for(int i = 0; i < names.size(); i++ ) {
    string num = names[i] + ",";
    outfileNew.write( num.c_str(), num.length() );
  }
  outfileNew.write( "\n", 1 );

  /*
   *  THROUGHPUT
   */
  outfileNew.write( "throughputs\n", 12 );

  // for( auto it = vectNew.allData.begin(); it != vectNew.allData.end(); it++ ) {
  //   it->second->writeNodeT( outfileNew );
  // }
  for(unsigned int i = 0; i < names.size(); i++ ) {
    auto it = vectNew.allData.find( names[i] );
    it->second->writeNodeT( outfileNew );
  }
  
  /*
   *  THROUGHPUT
   */
  outfileNew.write( "bandwidths\n", 11 );

  // for( auto it = vectNew.allData.begin(); it != vectNew.allData.end(); it++ ) {
  //   it->second->writeNodeB( outfileNew );
  // }
  for(unsigned int i = 0; i < names.size(); i++ ) {
    auto it = vectNew.allData.find( names[i] );
    it->second->writeNodeB( outfileNew );
  }

  outfileNew.close();






  return 0;
  /*
  vector<float> minsT;
  vector<float> onesT;
  vector<float> twosT;
  vector<float> threesT;
  vector<float> maxsT;

  vector<float> minsB;
  vector<float> onesB;
  vector<float> twosB;
  vector<float> threesB;
  vector<float> maxsB;

  // loop through all the nodes and calculate quartiles
  for( auto it2 = vect.allData.begin(); it2 != vect.allData.end(); it2 ++ ) {
    it2->second->calculateQuartiles();

    names.push_back( it2->second->testName );
    // throughput variables
    minsT.push_back( it2->second->tQ[0] );
    onesT.push_back( it2->second->tQ[1] );
    twosT.push_back( it2->second->tQ[2] );
    threesT.push_back( it2->second->tQ[3] );
    maxsT.push_back( it2->second->tQ[4] );

    // bandwidth variables
    minsB.push_back( it2->second->bQ[0] );
    onesB.push_back( it2->second->bQ[1] );
    twosB.push_back( it2->second->bQ[2] );
    threesB.push_back( it2->second->bQ[3] );
    maxsB.push_back( it2->second->bQ[4] );

  }

  //for( auto it = 
  
  ofstream outfile("pythonLists.txt", ofstream::out );
  
  // writing all the lists to a file 
  for(int i = 0; i < names.size(); i++ ) {
    string num = names[i] + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );
  */

  /*
   * THROUGPUT
   */
   /*
  for(int i = 0; i < minsT.size(); i++ ) {
    string num = to_string(minsT[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < onesT.size(); i++ ) {
    string num = to_string(onesT[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < twosT.size(); i++ ) {
    string num = to_string(twosT[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < threesT.size(); i++ ) {
    string num = to_string(threesT[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < maxsT.size(); i++ ) {
    string num = to_string(maxsT[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );
  */

  /*
   * BANDWIDTHS
   */
   /*
  for(int i = 0; i < minsB.size(); i++ ) {
    string num = to_string(minsB[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < onesB.size(); i++ ) {
    string num = to_string(onesB[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < twosB.size(); i++ ) {
    string num = to_string(twosB[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < threesB.size(); i++ ) {
    string num = to_string(threesB[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );

  for(int i = 0; i < maxsB.size(); i++ ) {
    string num = to_string(maxsB[i]) + ",";
    outfile.write( num.c_str(), num.length() );
  }
  outfile.write( "\n", 1 );


  //vect.writeToFilePython( outfile );
  */

}

/*
PyObject* vectorToList_float(const vector<float> & data) {
  PyObject * listObj = PyList_New( data.size() );
  if (!listObj) throw logic_error("Unable to allocate memory for Python list");
  for( unsigned int i = 0; i < data.size(); i++ ) {
    PyObkect *num = PyFloat_FromDouble( (double)data[i] );
    if( !num ) {
      Py_DECREF( listObj );
      throw logic_error("Unable to allocate memory for Python list");
    }
    PyList_SET_ITEM(listObj, i, num);
  }

  return listObj;
}
*/
