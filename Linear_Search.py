array = []
def linearSearch(array, n, x):
    for i in range(0, n):
        if (array[i] == x):
            return i
    return -1
total_students = int(input("Enter total number of students : "))
for i in range(total_students):
    element = int(input("Enter your roll number : "))
    array.append(element)
x = int(input("Enter roll number you want to search for : "))
n = len(array)
result = linearSearch(array, n, x)
if(result == -1):
    print("Element not found")
else:
    print("Element found at index: ", result)