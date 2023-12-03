C = []  #  cricket
B = []  #  badminton
F = []  #  football

UNION = []


def get_from_user():
    c = int(input("Enter number of students who play cricket\n"))
    print("Enter roll numbers of student :")
    for i in range(c):
        nc = int(input("Enter roll number of student "))
        C.append(nc)
    print(C)

    b = int(input("Enter number of students who play badminton\n"))
    print("Enter roll numbers of student :")
    for i in range(b):
        nb = int(input("Enter roll number of student "))
        B.append(nb)
    print(B)

    f = int(input("Enter number of students who play football\n"))
    print("Enter roll numbers of student :")
    for i in range(f):
        nf = int(input("Enter roll number of student "))
        F.append(nf)
    print(F)


get_from_user()


def both_cricket_badminton():
    both = []
    for i in C:
        for j in B:
            if i == j:
                both.append(i)
    print("The roll number of students who play both cricket and badminton are", both)





def either_cricket_or_badminton_but_not_both():
    cricket_or_badminton = []
    for i in C:
        if i not in B:
            cricket_or_badminton.append(i)
    for j in B:
        if j not in C:
            cricket_or_badminton.append(j)
    print(
        "The roll number of students who play either cricket or badminton but not both are",
        cricket_or_badminton,
    )



def neither_cricket_nor_badminton():
    cric_nor_bad = []
    C.extend(B)
    for i in F:
        if i not in C:
            cric_nor_bad.append(i)
    print(
        "The roll number of students who neither play cricket nor badminton are",
        cric_nor_bad,
    )




def cricket_football_but_not_badminton():
    cric_foot_not_bad = []
    for i in C:
        if i not in B:
            cric_foot_not_bad.append(i)
    for j in F:
        if j not in B:
            cric_foot_not_bad.append(j)
    print(
        "The roll number of students who play cricket and football but not badminton are",
        cric_foot_not_bad,
    )


if _name_ == '_main_':
    while(True):
        print("MENU\n\t1 : Both Cricket and Badminton \n\t2 : Either Cricket or Badminton but not both \n\t3 : Neither Cricket nor Badminton \n\t4 : Cricket and Football but not Badminton\n")
        ch = int(input("Enter desired choice\n"))
        if ch == 1:
            both_cricket_badminton()
        elif ch == 2:
            either_cricket_or_badminton_but_not_both()
        elif ch == 3:
            neither_cricket_nor_badminton()
        elif ch == 4:
            cricket_football_but_not_badminton()
        else:
            print("Enter among MENU section")

        print("MENU\n\tY : Do you want to continue ?\n\tN : Exit")
        a = input("Enter choice\n")
        if a=='Y' or a=='y':
            _name_ == '_main_'
        else:
            exit()