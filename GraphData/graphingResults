import matplotlib.pyplot as plt
import numpy as np

# construct data arrays
mins = np.array([2.604167, 0.262674, 1.303781, 0.178635, 0.031250, 0.01, 2.786615, 4.201681, 0.174917, 0.206271, 0.000108, 0.3777643])
maxes = np.array([2.610966, 0.277008, 1.379310, 0.186463, 0.031250, 0.01, 3.436426, 5.076142, 0.296296, 0.234137, 0.00011, 0.401445])
means = np.array([2.608586, 0.269571, 1.337125, 0.181504, 0.03125, 0.01, 3.111901, 4.648650, 0.230262, 0.222179, 0.000109, 0.3941])

# create stacked errorbars
# plt.errorbar(np.arange(len(mins)), means, fmt = 'ro', lw = 2)
plt.errorbar(np.arange(len(mins)), means, [means - mins, maxes - means], fmt = 'ko', lw = 1.5)
plt.xlim(-1, 12)
plt.show()
