/*
 * Date: 1/31/19
 * Description: Function implemenations for the dataVector class
 */

#include "dataVector.hpp"
#include <string.h>

dataVector::dataVector() {}

/**
 * removes extra space at the end of a string
 */
string removeSpace( string OG ) {
  int count = 0;
  while( count < OG.length() && (isalpha(OG[count]) || isdigit( OG[count] )) ) {
    count ++;
  }

  return OG.substr(0, count);
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
        bool seenComp = false; // to check to see if we've compact method

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

        //Read in lines from the file
        string line;
        int count = 0;
        while( getline( inFile, line ) ) {
            lineNum++;

            //We only want lines 7+ on for data 
            if( lineNum >= 7 ) {

                // get the string name
                string::size_type pos = line.find(':');
                string testName = removeSpace(line.substr(0, pos));

                // compressed versions of the tests
                if( seenComp && count < 3) {
                    testName += "_wComp";
                    count ++;
                }

                //Find index of first digit 
                int i = 0;
                while( !isdigit(line[i]) ) {
                    i++;
                }

                //Convert to substring
                string throughputSub = line.substr(i);

                //Convert Float 
                float throughput = stof(throughputSub);
                throughput = 1 / throughput;

                //Debugging
                if( debug ) {
                    cerr << "Throughput: " << throughput << endl;
                }

                //Find index of m
                while( line[i] != 'm' ) {
                    i++;
                }
                
                int error = 0;
                //Find index of second digit
                while( !isdigit(line[i]) ) {
                    i++;
                    if( i > line.length()) {
                      error = 1;
                      break;
                    }
                }
                
                // if there are no more numbers in that line - REACHED
                //    COMPACT
                if( error ) {
                  seenComp = true;
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

                // get the node with specified test name
                auto nodeIt = allData.find( testName );

                // if node doesn't exist make new one
                if( nodeIt == allData.end() ) {
                    dataNode * newNode = new dataNode( testName );
                    //newNode->addBandwidth( bandwidth );
                    newNode->addThroughput( throughput );
                    if( bandwidth > 99999.0 ) {
                        newNode->addBandwidth( 0 );
                        //cerr << "omg \n";
                    } else {
                        newNode->addBandwidth( bandwidth );
                    }
                    /*if( throughput > 99999.0 ) {
                        newNode->addThroughput( 0 );
                        cerr << "omg \n";
                    } else {
                        newNode->addThroughput( throughput );
                    }*/
                    allData.insert( make_pair( testName, newNode ) );
                }

                // if it does exist, add to it
                else {
                    nodeIt->second->addThroughput( throughput );
                    if( bandwidth > 99999.0 ) {
                        nodeIt->second->addBandwidth( 0 );
                        //cerr << "omg \n";
                    } else {
                        nodeIt->second->addBandwidth( bandwidth );
                    }
                }
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
    

    auto it = allData.begin();
    while( it != allData.end() ) {
        dataNode * currNode = it->second;
        currNode->writeNode( outfile );
        it ++;
    }

    return true;
}
        
        
/*
 * Writes the vector to an outfile
 */
bool dataVector::writeToFilePython( ofstream & outfile ) {
    

    auto it = allData.begin();
    while( it != allData.end() ) {
        dataNode * currNode = it->second;
        currNode->writeNodePython( outfile );
        it ++;
    }

    return true;
}
