from random import randint

i=int(input("Введите количество згенерированных чисел с -30 до +30: "))
List=[]
neg=[]
pos=[]
List=[randint(-30,30) for i in range(i) ]
for i in List:
    if i > 0:
        pos.append(i)
    elif i < 0:
        neg.append(i)
print("Список с",i,"елементов")
List.sort()
print(List)
print("Список отрицательных чисел")
neg.sort()
print(neg)
print("Список положительных чисел")
pos.sort()
print(pos)
print("Максимальное число отрицательной последовательности")
print(neg[-1])
print("Минимальное число положительной последовательности")
print(pos[0])
print("Подготовил Богатько Александр Геннадиевич ИПЗ-12")