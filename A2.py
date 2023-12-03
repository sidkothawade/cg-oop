mark_list = []
absent_student_list = []


def get_from_user():
    no_of_students = int(
        input(
            "Enter number of students who scored marks in 'Fundamental of Data Structure' in the class.\n"
        )
    )
    print("Enter mark of students.\nFor absent students enter '-1' ")
    for i in range(no_of_students):
        mark = int(input("Enter mark of student : "))
        if mark >= 0:
            mark_list.append(mark)
        else:
            absent_student_list.append(mark)


get_from_user()


def average_score_of_class():
    sum = 0
    no_of_present = len(mark_list)
    for mark in mark_list:
        sum = sum + mark
    average = sum / no_of_present
    print("The average score of class is : ", average)


def highest_and_lowest():
    print("Highest score of class is : ", max(mark_list))
    print("Lowest score of class is : ", min(mark_list))


def no_of_absent_student():
    print("Count of students who were absent for the test : ", len(absent_student_list))


def marks_with_highest_frequency():
    freq_dict = {}
    for mark in mark_list:
        if mark not in freq_dict:
            freq_dict[mark] = 1
        else:
            freq_dict[mark] += 1
    dict_values = list(freq_dict.values())
    print("Marks with the highest frequency : ", max(dict_values))


if _name_ == "_main_":
    while True:
        print(
            "MENU :: \n\t1 : The average score of class.\n\t2 : Highest and lowest score of class.\n\t3 : Count of absent students for test.\n\t4 : Marks with the highest frequency\n"
        )
        ch = int(input("Enter your choice among MENU section : "))
        if ch == 1:
            average_score_of_class()
        elif ch == 2:
            highest_and_lowest()
        elif ch == 3:
            no_of_absent_student()
        elif ch == 4:
            marks_with_highest_frequency()
        else:
            print("Enter correct choice !")

        print("MENU :: \n\tY : Do you want to continue ?\n\tN : Exit")
        ch1 = input("Enter your choice : ")
        if ch1 == "Y" or ch1 == "y":
            _name_ == "_main_"
        else:
            exit()