/*
 * Date: 1/28/19
 * Description: Header for the data structure used to store data
 * 		for each test.
 */

using namespace std;

#include <string>

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
                    averageThru = totalBand/elementsBand;
                }
}; 


