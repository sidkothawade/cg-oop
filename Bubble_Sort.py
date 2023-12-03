list = []
def bubble_sort():
    for i in range(len(list)):
        for j in range(0,len(list)-i-1):
            if list[j] > list[j+1]:
                list[j],list[j+1] = list[j+1],list[j]
    return list
def get_list_from_user():
    total_element = int(input("Enter total number of the element in the list : "))
    for i in range(total_element):
        element = int(input("Enter element : "))
        list.append(element)
get_list_from_user()
print("Un-Sorted List : ",list)
print("Sorted List : ",bubble_sort())
