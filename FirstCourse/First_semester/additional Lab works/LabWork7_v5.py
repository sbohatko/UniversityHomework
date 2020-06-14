from random import randint
import time
import os
import math
print('Богатько Александр Геннадьевич\nГруппа: ИПЗ-12\nПредмет: Основы програмирования')
time.sleep(1.5)

def isadigital(var):
    try:
        float(var)
        bul = True
    except:
        bul = False

    return bul

def makeMatrix(n, m):
    table = []
    fillWith = ' '
    for i in range(0, n):
        table.append([])
        for j in range(0, m):
            table[i].append(fillWith)
    return table

def tablePrint(tl):
    for wall in range(0, 4 * len(tl[0]) + 1):
        print('-', end = '')
    print()
    for i in range (0, len(tl)):
        print('|', end = '')
        for j in range(0, len(tl[0])):
            print(' %c |' %tl[i][j] , end = '')
        print()
        for wall in range(0, 4 * len(tl[0]) + 1):
            print('-', end='')
        print()

def tableWalker(tl):
    waker = 'W'
    tl[0][0] = waker
    iNow = 0
    jNow = 0
    step = 1
    while step != '0':
        tablePrint(tl)
        print('\n\nw - up      s - down')
        print('a - left    d - right')
        print('\n0 - Exit')
        step = input()
        tl[iNow][jNow] = ' '
        if step == 's' and iNow == len(tl) - 1:
            iNow = 0
            tl[iNow][jNow] = waker
        elif step == 'w' and iNow == 0:
            iNow = len(tl) - 1
            tl[iNow][jNow] = waker
        elif step == 'd' and jNow == len(tl[0]) - 1:
            jNow = 0
            tl[iNow][jNow] = waker
        elif step == 'a' and jNow == 0:
            jNow = len(tl[0]) - 1
            tl[iNow][jNow] = waker
        elif step == 's':
            iNow += 1
            tl[iNow][jNow] = waker
        elif step == 'w':
            iNow -= 1
            tl[iNow][jNow] = waker
        elif step == 'd':
            jNow += 1
            tl[iNow][jNow] = waker
        elif step == 'a':
            jNow -= 1
            tl[iNow][jNow] = waker
        else:
            tl[iNow][jNow] = waker
        os.system('cls')


def menu():
    print("Какую функцию желаете выполнить?")
    print("1 = действия со списками          2 = шахматная доска")
    choosing = int(input())
    if choosing == 1:
        a()
    elif choosing == 2:
        b()
    else:
        print("Есть только два варианта, попробуй ещё раз")
        return menu()

def a():
    b = int(input("Введіть к-ть чисел: "))
    a = [randint(1, 100) for i in range(b)]
    newstr1 = []
    for j in a:
        if j % 2 == 0 and j % 3 != 0:
            newstr1.append(j)
    for k in a:
        if k % 2 == 0 and k % 3 == 0:
            newstr1.append(k)
    for c in a:
        if c % 3 == 0 and c % 2 != 0:
            newstr1.append(c)
    print(a)
    print(newstr1)
    returning()

def b():
    n = int(input('Введите количество строк '))
    m = int(input('Введите количество столбцов '))
    table = makeMatrix(n, m)
    tableWalker(table)
    os.system('cls')

def returning():
    print("Хотите попробовать ещё раз? (Y / N)")
    returning1 = str(input())
    if returning1 == "Y" or returning1 == "y":
        menu()
    elif returning1 == "N" or returning1 == "n":
        print("Конец выполнения программы.")
        exit()
    else:
        print("Некоректный ответ")
        returning()

menu()