list = []
def selection_sort():
    for i in range(len(list)):
        min_index = i
        for j in range(i,len(list)):
            if list[j] < list[min_index]:
                min_index = j
        list[i], list[min_index] = list[min_index], list[i]
    return list
def get_list_from_user():
    total_element = int(input("Enter total number of the element in the list : "))
    for i in range(total_element):
        element = int(input("Enter element : "))
        list.append(element)
get_list_from_user()
print("Un-Sorted List : ",list)
print("Sorted List : ",selection_sort())
    
   
   
   