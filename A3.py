row1 = int(input("Enter rows of matrix\n"))
column1 = int(input("Enter columns of matrix\n"))
A = []
print("Enter the entries row wise :: \n")
for i in range(row1):
    a = []
    for j in range(column1):
        a.append(int(input("Enter elements : ")))
    A.append(a)

for i in range(row1):
    for j in range(column1):
        print(A[i][j],end=" ")
    print()

row2 = int(input("Enter rows of matrix\n"))
column2 = int(input("Enter columns of matrix\n"))
B = []
print("Enter the entries row wise :: \n")
for i in range(row2):
    a = []
    for j in range(column2):
        a.append(int(input("Enter elements : ")))
    B.append(a)

for i in range(row2):
    for j in range(column2):
        print(B[i][j],end=" ")
    print()

print("The addition of matrices : ")
for i in range(row1):
    for j in range(column1):
        print(A[i][j] + B[i][j],end=' ')
    print()

print("The subtraction of matrices : ")
for i in range(row1):
    for j in range(column1):
        print(A[i][j] - B[i][j],end=' ')
    print()

print("The transpose of 1st matrix : ")
for i in range(row1):
    for j in range(column1):
        print(A[j][i],end=' ')
    print()

print("The transpose of 2nd matrix : ")
for i in range(row2):
    for j in range(column2):
        print(B[j][i],end=' ')
    print()

print("The Multiplication of matrices : ")
result = []
for i in range(len(A)):
    row = [] 
    for j in range(len(B[0])):
        product = 0 
        for v in range(len(A[i])):
            product += A[i][v] * B[v][j]
        row.append(product) 
    result.append(row) 
for i in result:
    for j in i:
        print(j ,end=' ')
    print()