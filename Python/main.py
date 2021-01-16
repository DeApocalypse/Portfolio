# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import random as rd
from collections import defaultdict
import matplotlib.cm as cm

dataset=pd.read_csv('Mall_Customers.csv')   #Data!
X = dataset.iloc[:, [3, 4]].values  #(D, E)

K=5
m=200
Centroids=np.array([]).reshape(2,0)

#step 1
for i in range(K):
    rand=rd.randint(0,m-1)
    Centroids=np.c_[Centroids,X[rand]]
    

#step2
num_iter=20
Output=defaultdict()
Output={}
for n in range(num_iter):
    #step 2.a
    EuclidianDistance=np.array([]).reshape(m,0)
    for k in range(K):
        tempDist=np.sum((X-Centroids[:,k])**2,axis=1)
        EuclidianDistance=np.c_[EuclidianDistance,tempDist]
        
    C=np.argmin(EuclidianDistance,axis=1)+1
    #step 2.b
    Y={}
    for k in range(K):
        Y[k+1]=np.array([]).reshape(2,0)
    for i in range(m):
        Y[C[i]]=np.c_[Y[C[i]],X[i]]
     
    for k in range(K):
        Y[k+1]=Y[k+1].T
        
        
    for k in range(K):
        Centroids[:,k]=np.mean(Y[k+1],axis=0)
        
    Output=Y
    
plt.scatter(X[:,0],X[:,1],c='black',label='unclustered data')
plt.xlabel('Income')    #x축 항목
plt.ylabel('Number of transactions')    #y축 항목
plt.legend()    #?
plt.title('Plot of data points')    #타이틀
plt.show()  #1차로 보여주기 (클러스터링 되기 전 값 출력)

color=['red','blue','green','cyan','magenta'] #색 종류
labels=['cluster1','cluster2','cluster3','cluster4','cluster5'] #클러스터 이름
for k in range(K):  #K개의 클러스터로 표시, centroid
    plt.scatter(Output[k+1][:,0],Output[k+1][:,1],c=color[k],label=labels[k])
plt.scatter(Centroids[0,:],Centroids[1,:],s=300,c='yellow',label='Centroids')
plt.xlabel('Income')
plt.ylabel('Number of transactions')
plt.legend()
plt.title('Clusters of data points')
plt.show()
