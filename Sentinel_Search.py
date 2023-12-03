def sentinelSearch(arr, n, key):
	last = arr[n - 1]
	arr[n - 1] = key
	i = 0
	while (arr[i] != key):
		i += 1
	arr[n - 1] = last
	if ((i < n - 1) or (arr[n - 1] == key)):
		print(key, "is present at index", i)
	else:
		print("Element Not found")
arr = []
total_students = int(input("Enter total number of students : "))
for i in range(total_students):
    element = int(input("Enter your roll number : "))
    arr.append(element)
n = len(arr)
key = int(input("Enter roll number you want to search for : "))
sentinelSearch(arr, n, key)