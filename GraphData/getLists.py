from displayGraph import drawEbar, drawBoxPlot
import numpy as np

def main():
	# open file
	fp = open('../DataExtraction/pythonLists.txt')

	# create arrays to store results
	minsT = []
	onesT = []
	twosT = []
	threesT = []
	maxsT = []

	minsB = []
	onesB = []
	twosB = []
	threesB = []
	maxsB = []

	allData = []
	tests = []

	# iterate through all lines
	for i, line in enumerate(fp.readlines() ):

		# split by comma
		split = line.split( ',', -1)
		split = split[:-1]
			
		# cast each to a float except for test names
		if( i != 0 ):
			for j in range(0, len(split) ):
				split[j] = float(split[j])

		# store names of each benchmark
		if( i == 0 ):
			tests = split

		# store data
		if( i == 1 ):
			minsT = split
		elif( i == 2 ):
			onesT = split
		elif( i == 3 ):
			twosT = split
		elif( i == 4 ):
			threesT = split
		elif( i == 5 ):
			maxsT = split
		elif( i == 6 ):
			minsB = split
		elif( i == 7 ):
			onesB = split
		elif( i == 8 ):
			twosB = split
		elif( i == 9 ):
			threesB = split
		elif( i == 10 ):
			maxsB = split

	# convert all lists to arrays
	minsT = np.asarray(minsT)
	onesT = np.asarray(onesT)
	twosT = np.asarray(twosT)
	threesT = np.asarray(threesT)
	maxsT = np.asarray(maxsT)

	tests = np.asarray(tests)

	#drawEbar(tests, minsT, twosT, maxsT)
	drawBoxPlot(tests, minsT, onesT, twosT, threesT, maxsT)

if __name__ == '__main__':
	main()
