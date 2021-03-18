def quicksort(lst):

if not lst:

return []

return (quicksort([x for x in lst[1:] if x < lst[0]])

+ [lst[0]] +

quicksort([x for x in lst[1:] if x >= lst[0]]))

def main():

arr = [str(x) for x in input("Enter the words in the array: ").split()]

arr1 = quicksort(arr)

print("Sorted lilt: "+str(arr1))

if __name__ == "__main__":

main()