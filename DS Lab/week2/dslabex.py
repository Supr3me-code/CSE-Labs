x=int(input("Enter the length of rectangle-"))
y=int(input("Enter the breadth of rectangle-"))
print("The area of given rectangle is "+str(x*y))

###########################################################

x=int(input("Enter first number-"))
y=int(input("Enter second number-"))
print("The numbers before swapping are "+str(x)+" and "+str(y))
x=x-y
y=x+y
x=y-x
print("The numbers after swapping are "+str(x)+" and "+str(y))

############################################################

num=int(input("Enter the number-"))
if num%2 == 0:
    print(str(num)+" is even")
else:
    print(str(num)+" is odd")

#############################################################

num1=int(input("Enter first number-"))
num2=int(input("Enter second number-"))
num3=int(input("Enter third number-"))
if num1>num2 and num1>num3:
    print(str(num1)+" is largest among three numbers")
elif num2>num1 and num2>num3:
    print(str(num2)+" is largest among three numbers")
else:
    print(str(num3)+" is largest among three numbers")

###############################################################

a=10
while a>0:
    if a>5:
        a=a-1
        print(a)
    else:
        a=a-2
        print(a)

################################################################

m=int(input("Enter start of range-"))
n=int(input("Enter end of range-"))
for i in range(m,n+1):
    flag=False
    if i > 1:
        for j in range(2,(i//2)+1):
            if i%j == 0:
                flag=True
                break
        if flag == False:
            print(i)

##################################################################

list1=['Red','Green']
list2=[10,20,30]

print(list2*2)#Multiplication

list1=list1+['Blue']#Concatenation
print(list1)

print(len(list1))#Length

print(list2[-1])#Indexing

print(list2[0:2])#Slicing(start:end:inc)
print(list2[0:3:2])

print(min(list2))#min,max and sum functions
print(max(list2))
print(sum(list2))
print(40 in list2)#membership operator in

#append function(insert object at end of list)
a=[10,20,30,40]
a.append(50)
print(a)

#extend function(inserting sequence of objects at end of list)
a=[10,20,30]
a.extend([50,60,70])
print(a)

#count(returns count of object passed as argument)
a=[10,20,30,10,50,20,60,20,30,20,30]
print(a.count(20))

#pop(removes element with given index)
a=[10,20,30,40,50,60]
a.pop(3)
print(a)

#remove(removes first occurence of value passed as argument from list)
a=[10,20,30,20,40,50]
a.remove(20)
print(a)

#reverse(reverse elements of list)
a=[10,20,30,40,50]
a.reverse()
print(a)

#sort(sort given elements of list)
a=[45,24,64,15,8]
a.sort()
print(a)

#copy(copy contents of one list into another)
a=[10,20,30,40]
b=[]
b=a.copy()
print(b)

#clear(clears all the elements in list)
a=[10,20,30]
print(a.clear())

###############################################################################

tp=(1,3,5,7,9,2,4,6,8,10)
print(tp[:len(tp)//2])
print(tp[len(tp)//2:])

######################################################################


tp = (12,7,38,56,78)
li =[]
for ele in tp:
	if ele % 2 == 0:
		li.append(ele)
tp2 = tuple(li)
print(tp2)

#########################################################################

n=int(input("Enter number of elements-"))
list=[]
i=0
while i < n:
    list.append(int(input()))
    i=i+1
    
print("The negative numbers in list are-")
for num in list:
    if num < 0:
        print(num)

##################################################################

n=int(input("Enter number of elements-"))
list=[]
i=0
while i < n:
    list.append(int(input()))
    i=i+1
    
print("The negative numbers in list are-")
j=0
while j < len(list):
    if list[j] < 0:
        print(list[j])
    j=j+1

#####################################################################

n=int(input("Enter number of elements-"))
list=[]
i=0
while i < n:
    list.append(int(input()))
    i=i+1

positiveCount=0
negativeCount=0
for num in list:
    if num > 0:
        positiveCount += 1
    elif num < 0:
        negativeCount += 1
print("There are "+str(positiveCount)+" positive and "+str(negativeCount)+" negative numbers in the list")

#####################################################################3

n=int(input("Enter number of elements-"))
list=[]
i=0
while i < n:
    list.append(int(input()))
    i=i+1
print("List before removing even numbers is-")
print(list)
for ele in list:
    if ele % 2 == 0:
        list.remove(ele)
print("List after removing even numbers is-")
print(list)

# ###################################################################3


import pandas as pd
dict1={'Name':['A','B','C','D','E'],'Height':[170,192,185,195,176],'Qualification':['V','W','X','Y','Z']}
df=pd.DataFrame.from_dict(dict1)

add=['Delhi','Mumbai','Chennai','Bengaluru','Manipal']
df['Address']=add
print(df)

# ######################################################################


import pandas as pd
dict1={'Name':['A','B','C','D','E'],'Height':[170,192,185,195,176],'Qualification':['V','W','X','Y','Z']}
df=pd.DataFrame.from_dict(dict1)

df.insert(1,'Salary',[10000,20000,30000,40000,50000],False)
print(df)