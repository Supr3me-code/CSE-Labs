# num=int(input("Enter a number-"))
# count=0
# for i in range(1,(num+1)):
#     if num%i == 0:
#         count += 1
#         print(str(i)+" is a factor of "+str(num))
# print("Total factors of "+str(num)+" are "+str(count))

# ########################################

# import numpy as np
# M=np.arange(16).reshape(4,4)
# print("Matrix is\n",M)
# print("Column wise sum-",M.sum(axis=0))
# print("Row wise sum-",M.sum(axis=1))

# ###########################################

# import numpy as np
# print("-----OPERATIONS ON ARRAYS-----")
# n=int(input("Enter number of elements in list-"))
# list=[]
# for i in range(1,n+1):
#     list.append(float(input("Enter element "+str(i)+" - ")))
# print("Given List has elements-",list)
# arr1=np.array(list)
# print("Array created from List is-",arr1)
# print("\n")

# tuple=(24,12,18,30,72)
# print("Given Tuple has elements-",tuple)
# arr2=np.array(tuple)
# print("Array created from Tuple is-",arr2)
# print("\n")

# arr3=np.zeros([3,4],dtype=int)
# print("3*4 array with all zeros is-\n",arr3)
# print("\n")

# arr4=np.arange(0,20,5)
# print("Integers from 0(included) to 20(excluded) in steps of 5 is-\n",arr4)
# print("\n")

# arr5=np.arange(12).reshape(3,4)
# print("Original 3*4 array is-\n",arr5)
# arr5=arr5.reshape(2,2,3)
# print("Modified 2*2*3 array is-\n",arr5)
# print("\n")

# arr6=np.arange(16).reshape(4,4)
# max_elem_array=np.amax(arr6)
# min_elem_array=np.amin(arr6)
# max_elem_columnwise=np.amax(arr6,0)
# min_elem_columnwise=np.amin(arr6,0)
# max_elem_rowwise=np.amax(arr6,1)
# min_elem_rowwise=np.amin(arr6,1)
# total=np.sum(arr6)
# total_columnwise=np.sum(arr6,0)
# total_rowwise=np.sum(arr6,1)
# print("4*4 array is-\n",arr6)
# print("The maximum element in array is- ",max_elem_array)
# print("The minimum element in array is- ",min_elem_array)
# print("Row wise maximum in array is- ",max_elem_rowwise)
# print("Row wise minimum in array is- ",min_elem_rowwise)
# print("Column wise maximum in array is- ",max_elem_columnwise)
# print("Column wise minimum in array is- ",min_elem_columnwise)
# print("Sum of elements in array is- ",total)
# print("Row wise sum of elements in array is- ",total_rowwise)
# print("Column wise sum of elements in array is- ",total_columnwise)

# ##########################################

# import numpy as np
# mat=np.arange(16).reshape(4,4)
# mat1=mat.T
# print("Original Matrix is-\n",mat)
# print("\n")
# print("Transpose of Matrix is-\n",mat1)

# #########################################

# import numpy as np
# mat1=np.array([[12,7,3],[4,5,6],[7,8,9]])
# mat2=np.arange(9).reshape(3,3)
# print("1st Matrix is-\n",mat1)
# print("2nd Matrix is-\n",mat2)
# res_mat=np.add(mat1,mat2)
# print("Addition of Matrix 1 and 2 results in following Matrix-\n",res_mat)

# ########################################


import numpy as np
mat1=np.arange(12).reshape(3,4)
mat2=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12]])
print("1st Matrix is-\n",mat1)
print("2nd Matrix is-\n",mat2)
res_mat=np.multiply(mat1,mat2)
print("Element Wise Product of Matrix 1 and 2 results in following Matrix-\n",res_mat)
