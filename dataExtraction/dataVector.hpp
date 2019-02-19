/*
 * Date: 1/28/19
 * Description: Vector of dataNodes
 */


#include <vector>
#include <iterator>
#include <array>
#include <ctype.h>
#include "dataNode.hpp"
#include <iostream>
#include <dirent.h>
#include <string>
#include <unordered_map>

#define VECSIZE 16

using namespace std;

class dataVector {

	public:
		//Vector of tests 
		unordered_map<string, dataNode *> allData;

    bool debug = false;

		//Constructor
		dataVector();
    
		//Destructor, calls delete on every node
		~dataVector() {
			for( auto it = allData.begin(); it != allData.end(); it++ ) {
				delete it->second;
			}
		}


    //Gets data from each file
    bool readFile( const string & directoryName, 
               struct dirent * file);

    //Loop through all files in a directory
    bool readDirectory( const string & directoryName );

    //Write the data to an output file
    bool writeToFile( ofstream & outfile);

    //Write the data to an output file python
    bool writeToFilePython( ofstream & outfile);

};
