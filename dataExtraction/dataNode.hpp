/*
 * Date: 1/28/19
 * Description: Header for the data structure used to store data
 * 		for each test.
 */


#include <string> 
#include <fstream>
#include <iostream>

using namespace std;

class dataNode {

	public:

		//Constructor to init name
		dataNode(string name) {
			testName = name;
		}

		//Name of the test
		string testName;

    vector<float> throughputs;
    vector<float> bandwidths;
    vector<float> bQ;
    vector<float> tQ;

    /*
     * Adds throughput to the node vector
     */
    void addThroughput( float throughput ) {
        
        throughputs.push_back( throughput );
    }


    /*
     * Adds bandwidth to the node vector
     */
    void addBandwidth( float bandwidth ) {
        
        bandwidths.push_back( bandwidth );
    }
    
    /**
     * calculates the quartiles of throughput and bandwidth
     */
    void calculateQuartiles() {

      doQuart( 'b' ); // bandwidth
      doQuart( 't' ); // throughput
    }

    /**
     * caculates per array
     */
    void doQuart( char c ) {
      vector<float> quantile; 

      // set the array depending on param
      if( c == 'b' ) {
        quantile = bandwidths;
      } else {
        quantile = throughputs;
      }
     
      sort( quantile.begin(), quantile.end() );
      
      float q0 = quantile[0];
      float q1 = quantile[ quantile.size() / 4];
      float q2 = quantile[ quantile.size() / 2 ];
      float q3 = quantile[ quantile.size() / 2
                         + quantile.size() / 4 ];
      float max = quantile[ quantile.size() - 1];

      // put values into array
      if( c == 'b' ) {
        bQ.push_back( q0 );
        bQ.push_back( q1 );
        bQ.push_back( q2 );
        bQ.push_back( q3 );
        bQ.push_back( max );
      } else {
        tQ.push_back( q0 );
        tQ.push_back( q1 );
        tQ.push_back( q2 );
        tQ.push_back( q3 );
        tQ.push_back( max );
      }

    }

    /*
     * Writes data to outfile
     */
    void writeNode( ofstream & outfile ) {

      string testString = "\n---------\nTest Name: " + testName + "\n";
      string bandwidthS = "\tBandwidths: \n\t\t"
                               + to_string(bQ[0]) + ", "
                               + to_string(bQ[1]) + ", "
                               + to_string(bQ[2]) + ", "
                               + to_string(bQ[3]) + ", "
                               + to_string(bQ[4]) + "\n";

      string throughputS = "\tThroughputs: \n\t\t"
                               + to_string(tQ[0]) + ", "
                               + to_string(tQ[1]) + ", "
                               + to_string(tQ[2]) + ", "
                               + to_string(tQ[3]) + ", "
                               + to_string(tQ[4]) + "\n";

      outfile.write( testString.c_str(), testString.length() );
      outfile.write( bandwidthS.c_str(), bandwidthS.length() );
      outfile.write( throughputS.c_str(), throughputS.length() );

    }

    /*
     * Writes data to outfile
     */
    void writeNodePython( ofstream & outfile ) {

      string testString = testName + "\n";
      string bandwidthS = "\tBandwidths: \n"
                               + to_string(bQ[0]) + ", "
                               + to_string(bQ[1]) + ", "
                               + to_string(bQ[2]) + ", "
                               + to_string(bQ[3]) + ", "
                               + to_string(bQ[4]) + "\n";

      string throughputS = "\tThroughputs: \n"
                               + to_string(tQ[0]) + ", "
                               + to_string(tQ[1]) + ", "
                               + to_string(tQ[2]) + ", "
                               + to_string(tQ[3]) + ", "
                               + to_string(tQ[4]) + "\n";

      outfile.write( testString.c_str(), testString.length() );
      outfile.write( bandwidthS.c_str(), bandwidthS.length() );
      outfile.write( throughputS.c_str(), throughputS.length() );

    }
}; 


