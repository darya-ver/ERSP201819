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

#define VECSIZE 16

using namespace std;

class dataVector {

	private:
		//Array with all test names
    //enum {arrsize = 17};
		//static const string testNames[arrsize] = { "fillseq", "fillsync",
    //"fillrandom", "overwrite", "readrandom", "readrandom", "readseq",
    //"readreverse", "compact", "readrandom", "readseq", "readreverse",
    //"fill100k", "crc32c", "snappycomp", "snappyuncomp", "acquireload"  };

	public:
		//Vector of tests 
		vector<dataNode *> allData;

    bool debug = false;

		//Constructor
		dataVector(); // {
      /*
      const string testNames[arrsize] = { "fillseq", "fillsync",
        "fillrandom", "overwrite", "readrandom", "readrandom", "readseq",
        "readreverse", "compact", "readrandom", "readseq", "readreverse",
        "fill100k", "crc32c", "snappycomp", "snappyuncomp", "acquireload"  };

			//Create node for each test
			for( int i = 0; i < VECSIZE; i++ ) {
                                dataNode * tempNode = new dataNode(testnames[i]);
				allData.push_back(tempNode);
			}
		}
      */


		//Destructor, calls delete on every node
		~dataVector() {
			for( auto it = allData.begin(); it != allData.end(); it++ ) {
				delete *it;
			}
		}


                //Gets data from each file
                bool readFile( const string & directoryName, 
                               struct dirent * file);

                //Loop through all files in a directory
                bool readDirectory( const string & directoryName );

                //Write the data to an output file
                bool writeToFile( ofstream & outfile);
};
