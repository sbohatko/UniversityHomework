**Київський національний університет імені Тараса Шевченка**

**Кафедра програмних систем і технологій**

**Звіт про виконання третьої лабораторної роботи з дисципліни
"Основи програмування"**

**Виконав:** *Богатько Олександр Геннадійович, студент 1 курсу ФІТ ІПЗ-12*

**Викладач:** *Ковалюк Т.В.*

**Київ-2019**


##Перше завдання:

#### Написати програму, яка створює список, к-сть елементів якого задана користувачем, виводить його на екран, також виводить на екран мінімальний та максимальний елементи списку та суму елементів 
````
imported:
random

variables:
j = int(input('Please, enter the number of elements in your list:'))
l = []

code:
for i in range(j):
    l.append(randint(-10,10))

def printFunc():
    print(l)
    print(min(l))
    print(max(l))

printFunc()

def secondTask(l):
    theSum = 0
    for k in l:
        theSum = theSum + k
        k += 1
    return theSum



print(secondTask(l))



У програмі було використано базові функції input/output, цикл for, метод append.
````
####Тестові дані:
````
Please, enter the number of elements in your list:
>9
[2, -4, -7, 2, -2, -5, 1, 3, -4]
-7
3
-14

````
##Друге завдання:

#### Написати програму, яка генерує матрицю розміром n × m, будує транспоновану матрицю і виводить її на екран.
````
imported:
from random import randint

variables:
n = int(input('Please, enter number of rows:'))
m = int(input('Please, enter number of columns:'))

code:
def matCreat():
    matrix = [[random.randrange(0,10) for y in range(m)] for x in range(n)]
    for im in range(n):
        print(matrix[im])

    matrix1 = [list(p) for p in zip(*matrix)]
    print(matrix1)

matCreat()


У програмі було використано базові функції input/output, цикл for in range, бібліотеку random, модуль randint.
````
####Тестові дані:
````
Please, enter number of rows:
>4
Please, enter number of columns:
>3
Результат:
[9, 2, 4]
[9, 7, 2]
[3, 2, 0]
[4, 9, 8]
[[9, 9, 3, 4], [2, 7, 2, 9], [4, 2, 0, 8]]
