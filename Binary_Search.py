def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1
arr = []
total_element = int(input("Enter total number of the elements in the array : "))
for i in range(total_element):
    a = int(input("Enter element : "))
    arr.append(a) 
x = int(input("Enter a nummber you want to search : "))
arr.sort()
result = binary_search(arr, 0, len(arr)-1, x)
if result != -1:
    print("Element is present at index", result)
else:
    print("Element is not present in array")