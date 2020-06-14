import math

def natLog(xValue, eps):
    n = 0
    sum = 0
    item = 1
    while math.fabs(item) >= eps:
        item = (pow(-1, n) * pow(xValue, n + 1)) / (n + 1)
        sum += item
        n += 1
    return sum

eps = float(input('Введите точностьв ряду Тейлора: '))
print('\n\nТаблица соответствующих значений')
print('-----------------------------------------------------------------------')
print('|  x  |           y         |      standart      |        error       |')
print('-----------------------------------------------------------------------')
mem = 0
summ = 0
for i in range(1, 5):
    try:
        x = 0.5 * i
        arg1 = x
        arg2 = x / 2
        value = natLog(arg1, eps) + natLog(arg2, eps)
        bestVal = math.log1p(x) + math.log1p(x / 2)
        print('| %3.1f |   %15.10f   |  %15.13f   |  %15.13f   |' % (
        x, value, bestVal, math.fabs(value - bestVal)))
    except:
        print('| %3.1f |      not define     |' % x)
        continue
for i in range(6, 7):
    x = 0.5 * i
    arg = x / 2 - 1
    value = natLog(arg, eps)
    bestVal = math.log1p(x / 2 - 1)
    print('| %3.1f |   %15.10f   |  %15.13f   |  %15.13f   |' % (x, value, bestVal, math.fabs(value - bestVal)))
input()
