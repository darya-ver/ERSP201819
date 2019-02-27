import matplotlib.pyplot as plt
import matplotlib.axes as ax
import numpy as np

def drawEbar(tests, mins, meds, maxs):
	# create errorbars
	plt.errorbar(np.arange(len(mins)), meds, [meds - mins, maxs - meds], 
			fmt = 'ko', lw = 1.5)
	plt.xlim(-0.5, len(mins))
	plt.ylim(-0.5, 5.5)
	# set x axis labels
	plt.xticks(range(len(tests)), tests, rotation = 45)
	plt.show()

def drawBoxPlot(tests, mins, q1, meds, q3, maxs):
	# create a dict of lists for creating boxplot later
	'''
	stats = {
		'med': meds,
		'q1': q1,
		'q3': q3,
		'whislo': mins,
		'whishi': maxs,
		'label': tests,
		'fliers': [],
	}
	bpstats = [stats]
	fig, axes = plt.subplots(1,1)
	axes.bxp(bpstats)
	plt.show()	
	'''
	bxp = plt.boxplot(mins)
	bxp['medians'] = meds
	bxp['whiskers'][0].set_ydata(q1)
	plt.show()
	
