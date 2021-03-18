def binary_search_rec(l,start,end,ele):

if(end >= start):

mid = (start + end) // 2

if(l[mid] == ele):

return mid

elif(l[mid] > ele):

return binary_search_rec(l,start,mid - 1,ele)

else:

return binary_search_rec(l,mid + 1,end,ele)

else:

return -1

def main():

l = [int(x) for x in input("Enter the numbers in the array: ").split()]

ele = int(input("Enter the element to be searched: "))

new_l = l.copy()

new_l.sort()

result = binary_search_rec(new_l,0,len(new_l) - 1,ele)

if(result == -1):

print(str(ele) + " is not found")

else:

print(str(ele) + " is found at index " +str(l.index(new_l[result])))

if __name__ == "__main__":

main()