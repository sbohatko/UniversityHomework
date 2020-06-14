from collections import Counter

def unique_list(l):
    ulist = []
    [ulist.append(x) for x in l if x not in ulist]
    return ulist
a = input("Введите текст: ")
a=' '.join(unique_list(a.split()))

d = dict.fromkeys(a, 0)
for c in a: d[c] += 1 
print("Отформатированный текст: ",a)
print("Колличество повторяющихся символов:",d)
input("Нажмите ENTER ,чтобы выйти")

