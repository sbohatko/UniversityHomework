from collections import Counter

def func (n):
    if n==0:
        return 0
    else:
        return 1+(n*
                  (n-1))
print("(LabWork5)Богатько Александр В2 ИПЗ-12")   
num = int(input("Enter number: "))
print("Recursion depth = ",func (num))
print("Number of ones = ",bin(num)[2:].count('1'))
input('Press ENTER to exit')
