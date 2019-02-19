//#include <Python.h>
//#include <vector>
//#include <stdexcept>
//#include "PyUtils.h"
#include "dataVector.cpp"

using namespace std;

int main() {
  
  const string dirName = "./testingData";
  
  dataVector vect; 
  vect.readDirectory( dirName );

  // loop through all the nodes and calculate quartiles
  for( auto it2 = vect.allData.begin(); it2 != vect.allData.end(); it2 ++ ) {
    it2->second->calculateQuartiles();
  }

  ofstream outfile("pythonLists.txt", ofstream::out );

  vect.writeToFilePython( outfile );

  outfile.close();



  return 0;
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
