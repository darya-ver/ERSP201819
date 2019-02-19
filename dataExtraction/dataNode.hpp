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

		//Values for throughput
		/*
    float minThru = INT8_MAX;
		float maxThru = 0;
		float averageThru = 0;
		int elementsThru = 0;
		float totalThru = 0;
 
    //Values for bandwidth
    float minBand = INT8_MAX;
    float maxBand = 0;
    float averageBand = 0;
    int elementsBand = 0;
    float totalBand = 0;
    */
    vector<float> throughputs;
    vector<float> bandwidths;
    vector<float> bQ;
    vector<float> tQ;

    /*
     * Adds throughput to the node, updates all fields
     */
    void addThroughput( float throughput ) {
        
        throughputs.push_back( throughput );
        /*
        //Check min and max
        if( throughput > maxThru ) {
            maxThru = throughput;
        }

        if ( throughput < minThru ) {
            minThru = throughput;
        }

        //Recalculate average
        elementsThru++;
        totalThru += throughput;
        averageThru = totalThru/elementsThru;
        */
    }


    /*
     * Adds bandwidth to the node, updates all fields
     */
    void addBandwidth( float bandwidth ) {
        
        bandwidths.push_back( bandwidth );
        /*
        //Check min and max
        if( bandwidth > maxBand ) {
            maxBand = bandwidth;
        }
        
        if ( bandwidth < minBand ) {
            minBand = bandwidth;
        }

        //Recalculate average
        elementsBand++;
        totalBand += bandwidth;
        averageBand = totalBand/elementsBand;
        */
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

                //cout << "before \n";

      // set the array depending on param
      if( c == 'b' ) {
        quantile = bandwidths;
      } else {
        quantile = throughputs;
      }
      
      /*
      auto const Q1 = quantile.size() / 4;
      auto const Q2 = quantile.size() / 2;
      auto const Q3 = Q1 + Q2;

      nth_element( quantile.begin(),   
                   quantile.begin() + Q1, quantile.end());

      nth_element( quantile.begin() + Q1 + 1,   
                   quantile.begin() + Q2, quantile.end());

      nth_element( quantile.begin() + Q2 + 1,   
                   quantile.begin() + Q3, quantile.end());
      
                cout << "after \n";
      float q1 = quantile[Q1];
      float q2 = quantile[Q2];
      float q3 = quantile[Q3];

      float max = INT8_MAX;

      for( auto it = quantile.begin(); it != quantile.end(); it++ ) {
        if( *it > max ) max = *it;
      }
      */

      sort( quantile.begin(), quantile.end() );
      cout << "name: " << testName << ", " << c << endl;

      for( unsigned int i = 0; i < quantile.size(); i++ ) {
        cout << "\t" << quantile[i] << endl;
      }
      float q0 = quantile[0];
      float q1 = quantile[ quantile.size() / 4];
      float q2 = quantile[ quantile.size() / 2 ];
      float q3 = quantile[ quantile.size() / 2
                         + quantile.size() / 4 ];
      float max = quantile[ quantile.size() - 1];

      cout << "min: " << q0 << endl;
      cout << "Q1: " << q1 << endl;
      cout << "Q2: " << q2 << endl;
      cout << "Q3: " << q3 << endl;
      cout << "max: " << max << endl;
      
      // put values into array
      if( c == 'b' ) {
        bQ.push_back( q0 );
        bQ.push_back( q1 );
        bQ.push_back( q2 );
        bQ.push_back( q3 );
        bQ.push_back( max );
      } else {
        bQ.push_back( q0 );
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
            
      //Strings to write
      /*string testString = "Test Name: " + testName + "\n";
      string maxThruStr = "   Max Throughput: " + to_string(maxThru) + "\n";
      string minThruStr = "   Min Throughput: " + to_string(minThru) + "\n";
      string avgThruStr = "   Avg Throughput: " + to_string(averageThru) + "\n";
      string maxBandStr = "   Max BandWidth:  " + to_string(maxBand) + "\n";
      string minBandStr = "   Min BandWidth:  " + to_string(minBand) + "\n";
      string avgBandStr = "   Avg BandWidth:  " + to_string(averageBand) + "\n";

      outfile.write( testString.c_str(), testString.length() );
      outfile.write( maxThruStr.c_str(), maxThruStr.length() );
      outfile.write( minThruStr.c_str(), minThruStr.length() );
      outfile.write( avgThruStr.c_str(), avgThruStr.length() );
      outfile.write( maxBandStr.c_str(), maxBandStr.length() );
      outfile.write( minBandStr.c_str(), minBandStr.length() );
      outfile.write( avgBandStr.c_str(), avgBandStr.length() );
      outfile.write( "\n", 1 );
      */

      //cout << "here 5" << endl;

      string testString = "Test Name: " + testName + "\n";
      string bQ0 = to_string(bQ[0]) + "\n";
      string bQ1 = to_string(bQ[1]) + "\n";
      string bQ2 = to_string(bQ[2]) + "\n";
      string bQ3 = to_string(bQ[3]) + "\n";
      string bQmax = to_string(bQ[4]) + "\n";

      outfile.write( testString.c_str(), testString.length() );
      outfile.write( bQ0.c_str(), bQ0.length() );
      outfile.write( bQ1.c_str(), bQ1.length() );
      outfile.write( bQ2.c_str(), bQ2.length() );
      outfile.write( bQ3.c_str(), bQ3.length() );
      outfile.write( bQmax.c_str(), bQmax.length() );

    }
}; 


