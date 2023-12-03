list = []
def shell_sort():
    gap = len(list) // 2
    while gap > 0:
        for i in range(gap,len(list)):
            temp = list[i]
            j = i
            while ((j>=gap) and (list[j-gap] > temp)):
                list[j] = list[j-gap]
                j -= gap 
            list[j] = temp
        gap = gap // 2
    return list
def get_list_from_user():
    total_element = int(input("Enter total number of the element in the list : "))
    for i in range(total_element):
        element = int(input("Enter element : "))
        list.append(element)
get_list_from_user()
print("Un-Sorted List : ",list)
print("Sorted List : ",shell_sort())