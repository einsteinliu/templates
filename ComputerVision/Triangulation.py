
# coding: utf-8

# In[ ]:




# In[32]:

import cv2
import math
import numpy as np 
import matplotlib.pyplot as plt

def reconstruct_X_DLT(P1,P2,x1,x2):
    A = np.eye(4)
    A[0,:] = x1[0,0]*P1[2,:]-P1[0,:];
    A[1,:] = x1[1,0]*P1[2,:]-P1[1,:];
    A[2,:] = x2[0,0]*P2[2,:]-P2[0,:];
    A[3,:] = x2[1,0]*P2[2,:]-P2[1,:];
    u,w,vt = np.linalg.svd(A)
    X = vt[3,:].transpose()
    return X/X[3]

def project(P,X):
    x = np.matmul(P,X)
    x = x/x[2]
    return x

X = np.zeros([4,1])
X[0,0] = 2
X[1,0] = 2
X[2,0] = 10
X[3,0] = 1

P1 = np.zeros([3,4])
P1[0,0] = 1
P1[1,1] = 1
P1[2,2] = 1

x1 = project(P1,X)

R = np.zeros([3,3])
R[0,0] = 1
R[1,1] = 1
R[2,2] = 1

t = np.zeros([3,1])
t[2,0] = 2.0

P2 = np.zeros([3,4])
P2[0:3,0:3] = R
P2[0:3,3:4] = t

X_t = np.zeros(X.shape)
X_t[2,0] = 40
X = X + X_t
print(X)
x2 = project(P2,X)

X_re = reconstruct_X_DLT(P1,P2,x1,x2)
print(X_re)


# In[ ]:



