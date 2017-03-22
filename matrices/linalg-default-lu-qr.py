#!/bin/env python 

import sys   # for reading argc and argv 
import numpy as np
import scipy as sp
from scipy import linalg
import time






# Read command line arguments
#N = int(sys.argv[1]) # repetitions
#M = int(sys.argv[2]) # Problem size

# seed 
sp.random.seed(0)

# WARNING: Active only one solver at a time
N=512
ii = 1
while ii < N:
    start = time.time() #time
    # Array Declaracion
    A = sp.random.random((ii, ii)) 
    b = sp.random.random(ii)
    
    # Default solve
    #x = sp.linalg.solve(A, b)
    
    # lu solve
    x = sp.linalg.lu_solve(sp.linalg.lu_factor(A), b)
    
    # qr solve
    #Q, R = sp.linalg.qr(A)
    #y = np.dot(Q.T, b)
    #x = sp.linalg.solve(R, y)

    # increment counter
    ii = ii + 1


    # Printing
    #print x
    end = time.time()
    print" %-9s %s "%(end - start , ii-1)
    #print x

