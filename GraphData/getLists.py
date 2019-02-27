#from displayGraph import drawEbar, drawBoxPlot
#import numpy as np

def main():

  # create arrays to store results
  allDataTCurr = [] # throughputs for curr kernel
  allDataBCurr = [] # bandwidths  for curr kernel

  allDataTOld = []  # throughputs for old  kernel
  allDataBOld = []  # bandwidths  for old  kernel

  tests = []        # array of names

  ########################
  ###   CURR KERNEL
  ########################

  # open file
  fp = open('../DataExtraction/pythonListsCurr.txt')
  # iterate through all lines
  for i, line in enumerate(fp.readlines() ):

    # split by comma
    split = line.split( ',', -1)
    split = split[:-1] # gets rid of extra char at the end
      
    # cast each to a float except for test names
    if( i != 0 and i != 1 and i != 17 ):
      for j in range(0, len(split) ):
        split[j] = float(split[j])

    # store names of each benchmark
    if i == 0 :
      tests = split
      continue

    # skip over throughput and bandwidth string in file
    if i == 1 or i == 17:
      continue

    # extract for throughputs
    if( i < 17 ):
      allDataTCurr.append( split )

    # extract for bandwidths 
    if( i > 17 ):
      allDataBCurr.append( split )

  ########################
  ###   OLD KERNEL
  ########################

  # open file
  fp = open('../DataExtraction/pythonListsOld.txt')

  # iterate through all lines
  for i, line in enumerate(fp.readlines() ):

    # split by comma
    split = line.split( ',', -1)
    split = split[:-1] # gets rid of extra char at the end
      
    # cast each to a float except for test names
    if( i != 0 and i != 1 and i != 17 ):
      for j in range(0, len(split) ):
        split[j] = float(split[j])

    # skip over throughput and bandwidth string in file
    if i == 0 or i == 1 or i == 17:
      continue

    # extract for throughputs
    if( i < 17 ):
      allDataTOld.append( split )

    # extract for bandwidths 
    if( i > 17 ):
      allDataBOld.append( split )

  ########################
  ###  GRAPH STUFF 
  ########################

  print( tests )

  print( allDataTCurr )
  print( allDataBCurr )

  print( allDataTOld )
  print( allDataBOld )

  # convert all lists to arrays
  #tests = np.asarray(tests)

  #allDataTCurr = np.asarray(allDataTCurr)
  #allDataBCurr = np.asarray(allDataBCurr)
  #allDataTOld = np.asarray(allDataTOld)
  #allDataBOld = np.asarray(allDataBOld)

  #drawEbar(tests, minsT, twosT, maxsT)
  #drawBoxPlot(tests, minsT, onesT, twosT, threesT, maxsT)

if __name__ == '__main__':
  main()