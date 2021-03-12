import numpy as np

##########################################

A = np.array([2,5,10])
print(A.dtype)
B = np.array([2.4,10.6,5.2])
B.dtype

##########################################

A = np.array([(3,4,5),(12,6,1)])
Z = np.zeros((2,4))
O = np.ones((3,3))

##########################################

S = np.arange(10,30,5)
print(S)
np.arange(0,2,0.3)

##########################################

S1 = np.linspace(0,2,9)
print(S1)

#########################################

import random
print(random.choice([1,2,3,4,5]))
print(random.choice(['python']))
print(random.randrange(25,50))
print(random.randrange(25,50,2))
print(random.random())
print(random.uniform(5,10))
print(random.shuffle([1,2,3,4,5]))
print(random.seed(10))

##########################################

a = np.arange(15).reshape(3,5)
A = np.array([[0,1,2,3,4],[5,6,7,8,9],[10,11,12,13,14]])
# print(A.shape())
print(A.size())
print(A.T)

###########################################

c = np.arange(24).reshape(2,3,4)
print(c)
print(c.shape)
print(c[1,:,:])
print(c[:,:,2])

###########################################

a = np.array([20,30,40,50])
b = np.arange(4)
print(b)
c = a - b
print(c)
print(10*np.sin(a))
a<35

###########################################

A = np.array([[1,1],[0,1]])
B = np.array([[2,0],[3,4]])

print(A*B)
print(A.dot(B))
print(np.dot(A,B))
b = np.arange(12).reshape(3,4)
print(b)
print(b.sum(axis = 0))
print(b.sum(axis=1))

###########################################

a = np.arange(10)**3
print(a)

print(a[2:5])
print(a[0:6:2])

###########################################

b = np.array([[0,1,2,3],[10,11,12,13],[20,21,22,23],[30,31,32,33],[40,41,42,43]])
print(b[2,3])
print(b[0:5,1])
print(b[-1,:])
print(b[:,-1])

for row in b:
	print(row)
for elements in b.flat:
	print(elements)

####################################

b = np.array([[0,1,2,3],[10,11,12,13],[20,21,22,23],[30,31,32,33],[40,41,42,43]])
print(b.ravel())
B1 = b.reshape(4,5)
print(B1)

# #####################################

A1 = np.array([(3,4,5),(12,6,1)])
print(A1)
A2 = np.array([(1,2,6),(-4,3,8)])
print(A2)
D1 = np.vstack((A1,A2))
print(D1)
D2 = np.hstack((A1,A2))
print(D2)

###########################################

a = np.array([4.,2.])
b = np.array([3.,8.])
c = np.column_stack((a,b))
print(c)
d = np.hstack((a,b))
print(d)
e = np.hstack((a,[:,newaxis],b[:,newaxis]))
print(e)

########################################

a = np.arange(12^^2)
i = np.array([1,1,3,8,5])
print(a[i])
j = np.array([[3,4],[9,7]])
print(a[j])

###########################################

import numpy as np
a = np.array([(3,2,8),(1,6,7)])
s1 = 0
for row in a:
	for col in row:
		s1+=col
print(s1)

###########################################

import numpy as np
a = np.array([(3,2,9),(1,6,7)])
s = 0 
for i in range(a.shape[0]):
	for j in range(a.shape[1]):
		s+=a[i,j]
print(s)