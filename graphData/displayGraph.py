import matplotlib.pyplot as plt
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

def drawBoxPlot(tests, data, info):
	# draw boxplot with no outliers and allows color
	bplot = plt.boxplot(data, 0, '', patch_artist = True )
	
	# different color and width settings
	color = ['red', 'blue']
	bgColor = 'white'
	lwidth = 0.7

	# set outline color for box and median
	for item in ['boxes', 'medians']:
		i = 0
		# change color for every other one
		for box in bplot[item]:
			if i % 2 == 0:
				box.set(color = color[0], lw = lwidth)
			else:
				box.set(color = color[1], lw = lwidth)
			i += 1
	
	# set outline color for whisker and cap
	for item in ['whiskers', 'caps']:
		j = 2
		k = 1
		# change color every 2 whiskers/caps
		for box in bplot[item]:
			if j / k == 2:
				useColor = color[(k-1) % 2]
				k += 1
			box.set(color = useColor, lw = lwidth)
			j += 1

	# set background color for box
	for box in bplot['boxes']:
		box.set(facecolor = bgColor)

	# set position of the xaxis labels
	pos = range(1, len(data)+1, 2)
	plt.xticks(pos, tests, rotation=45, ha = 'right')
	
	# set titles, axis labels, legends
	plt.title(info[0], fontsize = 15)
	#plt.title(info[0])
	plt.xlabel(info[1])
	plt.ylabel(info[2])
	plt.legend([bplot['boxes'][0], bplot['boxes'][1]], 
			['old version','new version'], loc = 'best')
	#saves graph without cutting off labels
	plt.savefig(info[0], bbox_inches="tight", dpi=320)
	plt.show()
