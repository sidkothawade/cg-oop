list = []
def insertion_sort():
    i = 1
    for i in range(len(list)):
        temp = list[i]
        j = i-1
        while ((j>=0) and (list[j]>temp)):
            list[j+1] = list[j]
            j = j - 1
            list[j+1] = temp
    return list
def get_list_from_user():
    total_element = int(input("Enter total number of the element in the list : "))
    for i in range(total_element):
        element = int(input("Enter element : "))
        list.append(element)
get_list_from_user()
print("Un-sorted List : ",list)
print("Sorted List : ",insertion_sort())