/*
 * Date: 1/31/19
 * Description: Function implemenations for the dataVector class
 */

#include "dataVector.hpp"
#include <string.h>

dataVector::dataVector() {
  
      const string testNames[VECSIZE] = { "fillseq", "fillsync",
        "fillrandom", "overwrite", "readrandom", "readrandom", "readseq",
        "readreverse", /*"compact",*/ "readrandom", "readseq", "readreverse",
        "fill100k", "crc32c", "snappycomp", "snappyuncomp", "acquireload"  };

			//Create node for each test
			for( int i = 0; i < VECSIZE; i++ ) {
                                dataNode * tempNode = new dataNode(testNames[i]);
				allData.push_back(tempNode);
			}
}




/*
 * Description: Gets data from file, and adds it into our vector
 *
 * Side effects: Vector is filled with data for each test
 *
 * Returns true upon success.
 */
bool dataVector::readFile( const string & directoryName, struct dirent * file) {

        //Line number we've reached in the file
        unsigned int lineNum = 0; 
        string fileName = directoryName;

        //Adds backslash if necessary
        if( directoryName.back() != '/' ) {
            fileName += '/';
        }

        //Appends file name
        fileName += file->d_name;
        ifstream inFile;

        //Open and check inFile
        inFile.open( fileName );
        if( !inFile ) {
            cerr << "INVALID FILE\n";
            return false;
        }

        //Debug message
        if ( debug ) {
            cerr << "\nIn File: " << fileName << endl;
        }

        int vecIndex = 0;

        //Read in lines from the file
        string line;
        while( getline( inFile, line ) ) {
            lineNum++;


            //We only want lines 7 on for data 
            if( lineNum >= 7 ) {

                //cout << line << endl;
                //Find index of first digit 
                int i = 0;
                while( !isdigit(line[i]) ) {
                    i++;
                }

                //Convert to substring
                string throughputSub = line.substr(i);
               // i += throughputSub.length();

                //Convert Float 
                float throughput = stof(throughputSub);
                //cout << throughput << endl;
                //cout << "__" << to_string(throughput) << "__" << endl;

                //Debugging
                if( debug ) {
                    cerr << "Throughput: " << throughput << endl;
                }

                //Find index of m
                while( line[i] != 'm' ) {
                    i++;
                }
                // cout << line.substr(i) << endl;
                
                int error = 0;
                //Find index of second digit
                while( !isdigit(line[i]) ) {
                    i++;
                    if( i > line.length()) {
                      error = 1;
                      break;
                    }
                }
                
                // if there are no more numbers in that line
                if( error ) {
                  continue;
                }

                //Convert to substring
                string bandwidthSub = line.substr(i);

                //Convert Float
                float bandwidth = stof(bandwidthSub);

                //Debugging
                if( debug ) {
                    cerr << "Bandwidth: " << bandwidth << endl;
                }

                //Add data into vector
                dataNode * currNode = allData[vecIndex];
                currNode->addThroughput(throughput);
                currNode->addBandwidth(bandwidth);

                vecIndex++;
            }
        }

        return true;
}                
       
/*
 * Reads in each file from a directory
 *
 * Returns true upon success, false if invalid directory
 */
bool dataVector::readDirectory( const string & directoryName ) {

    struct dirent * file = 0;

    //Open directory and check 
    DIR * dir = opendir( directoryName.c_str() );
    if( !dir ) {
        cerr << "DIRECTORY DOESN'T EXIST!\n";
        return false;
    }

    //Loop through every file
    while( (file = readdir( dir )) != NULL ) {
        
        //Skip . and .. directories
        if( strcmp( file->d_name, "." ) == 0 || 
            strcmp( file->d_name, ".." ) == 0 ) {
            continue;
        }

        readFile( directoryName, file );

    }

    closedir( dir );
    return true;

}
            
/*
 * Writes the vector to an outfile
 */
bool dataVector::writeToFile( ofstream & outfile ) {
    
    //Iterate through entire vector
    for( int i = 0; i < VECSIZE; i++ ) {
        dataNode * currNode = allData[i];
        currNode->writeNode( outfile );
    }

    return true;

}
        
        
