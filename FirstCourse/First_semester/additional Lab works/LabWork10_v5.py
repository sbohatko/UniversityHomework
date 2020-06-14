def start():
    global b
    a = input('Введите числа в строку:').split()
    b = []
    for elem in a:
        try:
            elem = int(elem)
            b.append(elem)
        except:
            print('Нужно ввести только целые числа')
            return start()
    return True
start()
newstr1 = []
newstr2 = []
for j in b:
    if j % 2 == 0 and j % 3 != 0:
        newstr1.append(j)
for k in b:
    if k % 2 == 0 and k % 3 == 0:
        newstr1.append(k)
for c in b:
    if c % 3 == 0 and c % 2 != 0:
        newstr1.append(c)
for t in b:
    if t % 2 != 0 and t % 3 !=0:
        newstr2.append(t)
print('Изначальный список:')
print(b)
print('Новый список:')
print(newstr1)
print('Числа которые не деляться на 2 и на 3:')
print(newstr2)