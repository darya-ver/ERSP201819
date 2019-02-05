/*
 * Date: 1/28/19
 * Description: Header for the data structure used to store data
 * 		for each test.
 */


#include <string> 
#include <fstream>

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
		float minThru = 0;
		float maxThru = 0;
		float averageThru = 0;
		int elementsThru = 0;
		float totalThru = 0;
 
                //Values for bandwidth
                float minBand = 0;
                float maxBand = 0;
                float averageBand = 0;
                int elementsBand = 0;
                float totalBand = 0;

                /*
                 * Adds throughput to the node, updates all fields
                 */
                void addThroughput( float throughput ) {
                    
                    //Check min and max
                    if( throughput > maxThru ) {
                        maxThru = throughput;
                    }
                    else if ( throughput < minThru ) {
                        minThru = throughput;
                    }

                    //Recalculate average
                    elementsThru++;
                    totalThru += throughput;
                    averageThru = totalThru/elementsThru;
                }


                /*
                 * Adds bandwidth to the node, updates all fields
                 */
                void addBandwidth( float bandwidth ) {
                    
                    //Check min and max
                    if( bandwidth > maxBand ) {
                        maxBand = bandwidth;
                    }
                    else if ( bandwidth < minBand ) {
                        minBand = bandwidth;
                    }

                    //Recalculate average
                    elementsBand++;
                    totalBand += bandwidth;
                    averageBand = totalBand/elementsBand;
                }

                /*
                 * Writes data to outfile
                 */
                void writeNode( ofstream & outfile ) {
                        
                        //Strings to write
                        string testString = "Test Name: " + testName + "\n";
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

                }
}; 


