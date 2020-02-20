from math import *
import numpy as np

input_data = [-0.918, -0.624, -1.223, 0.984, -0.521,
-1.155, -1.065, -0.752, 1.680, 0.246, -0.334, -0.407, -0.683, 1.591,
1.729, 0.071, -1.412, 0.860, -1.088, -0.156, 0.920, 0.108, -0.721,
0.146, 0.944, 0.116, -1.348, -0.767, -0.952, -0.798, -0.904, -1.061,
-0.723, -0.897, -0.807, 0.503, -1.046, 0.404, -0.678, -0.437, -1.728,
-1.077, -0.375, -0.628, -2.360, 1.393, -1.968, -0.022, -0.719, -1.389]

# intial parameters
n_iter = len(input_data)
sz = (n_iter,) # size of array
x = -0.37727 # truth value (typo in example at top of p. 13 calls this z)
# z = np.random.normal(x,0.1,size=sz) # observations (normal about x, sigma=0.1)
z = input_data

Q = 1e-5 # process variance

# allocate space for arrays
xhat=np.zeros(sz)      # a posteri estimate of x
P=np.zeros(sz)         # a posteri error estimate
xhatminus=np.zeros(sz) # a priori estimate of x
Pminus=np.zeros(sz)    # a priori error estimate
K=np.zeros(sz)         # gain or blending factor

R = 0.1**2 # estimate of measurement variance, change to see effect

# intial guesses
xhat[0] = 0.0
P[0] = 1.0

for k in range(1,n_iter):
    # time update
    xhatminus[k] = xhat[k-1]
    Pminus[k] = P[k-1]+Q

    # measurement update
    K[k] = Pminus[k]/( Pminus[k]+R )
    xhat[k] = xhatminus[k]+K[k]*(z[k]-xhatminus[k])
    P[k] = (1-K[k])*Pminus[k]

    print('input: {:.2f}\tK: {:.2f}\tx_hat: {:.2f}\tP: {:.2f}'.format(
        z[k], K[k], xhat[k], P[k]
    ))