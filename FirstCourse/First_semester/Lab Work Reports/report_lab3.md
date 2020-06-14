**Київський національний університет імені Тараса Шевченка**

**Кафедра програмних систем і технологій**

**Звіт про виконання третьої лабораторної роботи з дисципліни
"Основи програмування"**

**Виконав:** *Богатько Олександр Геннадійові, студент 1 курсу ФІТ ІПЗ-12*

**Викладач:** *Ковалюк Т.В.*

**Київ-2019**


##Перше завдання:

#### Написати програму для обчислення суми ряду, елементи якого розраховуються з використанням операцій піднесення у степінь, розрахунку факторіалу числа, операцій множення та ділення.
```
imported:
math

variables:
accuracy = float(input("Введіть точність: "))
res = 0
memberToSave = 0

code:
for x in range(1, 6):
    k = 0
    currentRes = 0
    while True:
        currentRes = (((-1) ** k) * ((x / 2) ** (2 * k + 1))) / ((k + 1) * math.factorial(k))
        res += currentRes

        # Configuring table
        space1String = (20 - len(str(round(currentRes, 4)))) * "  "

        if currentRes < 0:
            space1String += " "

        space2String = (15 - len(str(round(res, 4)))) * "  "

        if res < 0:
            space2String += " "

        space3String = (9 - len(str(k))) * "  "

        print("        ", x, space3String, k, space1String, round(currentRes, 4), space2String, round(res, 4))
        if abs(currentRes - memberToSave) <= accuracy:
            print("overflow - break cycle with k")
            break
        k += 1
        memberToSave = currentRes

print("===========================================")
print("sum=", res)

У програмі було використано базові функції input/output, цикл for, конструкцію if з операторами break/continue, модуль math.
```
####Тестові дані:
```
Введіть точність: 50
===========================================
        x                  k                          member                          sum        
===========================================
         1                  0                                    0.5                          0.5
overflow - break cycle with k
         2                  0                                    1.0                          1.5
overflow - break cycle with k
         3                  0                                    1.5                          3.0
overflow - break cycle with k
         4                  0                                    2.0                          5.0
overflow - break cycle with k
         5                  0                                    2.5                          7.5
overflow - break cycle with k
===========================================
sum= 7.5
