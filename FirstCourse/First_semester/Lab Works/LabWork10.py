import random

# =================================== a ===================================
def getEvenNumbers(List: list):
    evenNumbers = []
    for i in range(len(List)):
        if List[i] % 2 == 0:
            evenNumbers.append(List[i])
    return evenNumbers

# сортуємо список і отримуємо тільки непарні елементи
def getOddNumbers(List):
    oddNums = []
    for i in range(len(List)):
        if List[i] % 2 != 0:
            oddNums.append(List[i])
    return oddNums

def getNumberOfElements():
    while True:
        # отримуємо кількість елементів
        numberOfElements = int(input("Input number of elements: "))

        # якщо кількість елементів є число та більше рівне 0, то повертаємо значення, інакше просимо ввести значення знову
        if numberOfElements >= 0:
            return numberOfElements
        else:
            print("Error, try again\n\n")

def a():
    # отримуємо кількість елементів
    numberOfElements = getNumberOfElements()
    
    # Заповнюємо список рандомними значеннями від 0 до 100 
    List = [random.randint(0, 100) for n in range(numberOfElements)]

    # сортуємо список і записуємо всі непарні елементи
    oddNumbers = getOddNumbers(List)

    # отримуємо максимальне значення і мінімальне значення непарних елементів
    print("Max odd number: ", max(oddNumbers))
    print("Min odd number: ", min(oddNumbers))

    # сортуємо список і отримуємо всі парні елементи парних елементів
    evenNumbers = getEvenNumbers(List)

    # отримуємо максимальне і мінімальне значення
    print("Max even number: ", max(evenNumbers))
    print("Min even number: ", min(evenNumbers))

# =================================== a ===================================
# =================================== b ===================================

# Вводимо значення елементів матриці
def entryMatr(n, matrix):
    for i in range(n):
        matrix.append([])
        for j in range(n):
            matrix[i].append(int(input("Enter item: ")))
    return matrix

# отримуємо розмір матриці від юзера
def getN():
    while True:
        n = int(input("Input size of square matrix: "))
        if n > 0:
            return n
        else:
            print("Error, try again\n")

# транспонування матриці
def transpose(mat, tr, N): 
    for i in range(N): 
        for j in range(N): 
            tr[i][j] = mat[j][i] 
   
# якщо матриця симетрична, то True
def isSymmetric(mat, N): 
      
    tr = [ [0 for j in range(len(mat[0])) ] for i in range(len(mat)) ] 
    transpose(mat, tr, N) 
    for i in range(N): 
        for j in range(N): 
            if (mat[i][j] != tr[i][j]): 
                return False
    return True

def b():
    matrix = []

    # задаємо розмірність та вводимо елементи матриці
    n = getN()

    # вводимо елементи матриці
    matrix = entryMatr(n, matrix)

    if (isSymmetric(matrix, n)): 
        print("YES")
    else: 
        print ("No")

# =================================== b ===================================

def getAnswer():
    while True:
        # отримуємо відповідь а чи б
        answer = input("List app(a)\nMatrix app(b)\nSelect: ")
        # якщо відповідь == а або б, то поветраємо значення відповіді, а якщо ні, то просимо ввести знову
        if answer == "a" or answer == "b":
            return answer
        else:
            print("Error, try again\n\n")


if __name__ == "__main__":
    # отримуємо відповідь користувача (а або б)
    answer = getAnswer()

    if answer == "a":
        a()

    # так як ми виключаємо  можливість отримання іншої відповіді окрім як а або б, то можемо тупо через else
    else:
        b()
