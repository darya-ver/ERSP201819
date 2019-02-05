/*
 * Date: 1/31/19
 * Description: Function implemenations for the dataVector class
 */


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
        while( getLine( inFile, line ) ) {
            lineNum++;

            int vecIndex = 0;

            //We only want lines 7 on for data 
            if( lineNum >= 7 ) {

                //Find index of first digit 
                int i = 0;
                while( !isdigit(line[i]) ) {
                    i++;
                }

                //Convert to substring
                string throughputSub = line.substr(i);
                i++;

                //Convert Float 
                float throughput = stof(throughputSub);

                //Debugging
                if( debug ) {
                    cerr << "Throughput: " << throughput << endl;
                }

                //Find index of second digit
                while( !isDigit(line[i]) ) {
                    i++;
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

            }
            vecIndex++;
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
bool dataVector::writeToFile( const ofstream & outfile ) {
    
    //Iterate through entire vector
    for( int i = 0; i < VECSIZE; i++ ) {
        dataNode * currNode = allData[i];
        currNode->writeNode( outfile );
    }

    return true;

}
        
        
