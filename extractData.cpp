#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <dirent.h>
#include <vector>

using namespace std;

/**
 * gets data from each file 
 */
void getDataFromFile( const string & directoryName, struct dirent * file, 
                      ifstream & infile ) {

    string fileName = directoryName;

    // keeps track of what line number we reached
    unsigned int lineNum = 0;

    // checks if the last element is a backslash
    if( directoryName.back() != '/' ) {
      fileName += '/';
    }

    fileName += file->d_name;

    infile.open( fileName );

    cout << "\nIn file: " << fileName << endl;
    // read in every line
    string line;

    while( getline( infile, line ) ) {
      lineNum ++;

      // only extract the line numbers from 7 on (this is where data is)
      if( lineNum >= 7)  
        cout << "line " << lineNum << "\t" << line << endl;

    }
    infile.close();
}

/**
 * loop through all the files in a directory
 */
void loopThroughDir( const string & directoryName ) {

  struct dirent * file = 0; 
  DIR * dir = opendir( directoryName.c_str() );
  ifstream infile;
  vector<string> words;
  
  while( (file = readdir( dir )) != NULL ) {
    if( strcmp( file->d_name, ".") == 0 || strcmp( file->d_name, ".." ) == 0 ) {
      continue;
    }

    getDataFromFile( directoryName, file, infile );
  }

  closedir( dir );
}

int main() {

  /**
   * LOOPING THROUGH EACH FILE IN THE DATA DIRECTORY"
   */
  const string directoryName = "./testingData";
  loopThroughDir( directoryName );
  
  return 0;
}

