from displayGraph import drawEbar, drawBoxPlot
import numpy as np

def main():

  # create arrays to store results
  allDataTCurr = [] # throughputs for curr kernel
  allDataBCurr = [] # bandwidths  for curr kernel

  allDataTOld = []  # throughputs for old  kernel
  allDataBOld = []  # bandwidths  for old  kernel

  tests = []        # array of names

  allDataT = []     # array of all data
  allDataB = []
    
  ########################
  ###   CURR KERNEL
  ########################

  # open file
  fp = open('../DataExtraction/pythonLists/pythonListsCurr.txt')
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
  fp = open('../DataExtraction/pythonLists/pythonListsOld.txt')

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

  for i in range(len(allDataTOld)):
    allDataT.append(allDataTOld[i])
    allDataT.append(allDataTCurr[i])

  for i in range(len(allDataBOld)):
    allDataB.append(allDataBOld[i])
    allDataB.append(allDataBCurr[i])

  #allDataTCurr = np.asarray(allDataTCurr)
  #allDataBCurr = np.asarray(allDataBCurr)
  #allDataTOld = np.asarray(allDataTOld)
  #allDataBOld = np.asarray(allDataBOld)
  #drawEbar(tests, minsT, twosT, maxsT)
  
  # array of info to pass into boxplot
  tInfo = ["Figure 1: Throughput LevelDB", "Benchmarks", "op/s"]
  bInfo = ["Figure 2: Bandwidth LevelDB", "Benchmarks", "MB/s"]

  drawBoxPlot(tests, allDataT, tInfo)
  drawBoxPlot(tests, allDataB, bInfo)

if __name__ == '__main__':
  main()
