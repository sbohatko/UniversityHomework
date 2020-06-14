import os

def isadigital(var):
    try:
        float(var)
        bul = True
    except:
        bul = False

    return bul

def dictPrint(dict):
    print('{')
    for i in range(0, len(dict)):
        print(dict[i])
    print('}')

while True:
    print('Лабораторная робота №8\nБогатько Александр Геннадьевич ИПЗ-12')
    print('1.задание №1\n2.Задание №2\n0.Выход')
    choice = input()
    if isadigital(choice) == 1:
        choice = int(choice)
    if choice == 0:
          break

    elif choice == 1:
        os.system('cls')
#----------| 0 - city 0 - num, 1 - date, 2 - freePlaces, 3 - price |----------------------------------------------------
        flights = {0: ['Киев', 48701, '25.11.2019', 17, 180], 1: ['Вашингтон', 43776, '23.11.2019', 0, 200],
                    2: ['Москва', 41666, '03.12.2019', 13, 120], 3: ['Барселона', 40226, '23.11.2019', 0, 80]}

        while True:
            os.system('cls')
            print('Список рейсов:')
            dictPrint(flights)
            print('\n\n1.Список рейсов на которые есть свободные места')
            print('2.Минимальная стоимость')
            print('3.Отсортировать по цене')
            print('\n\n0.Выход')
            choiceTaskOne = input()
            if isadigital(choiceTaskOne) == 1:
                choiceTaskOne = int(choiceTaskOne)
            if choiceTaskOne == 1:
                os.system('cls')
                print('Cписок рейсів:')
                dictPrint(flights)
                print('\nСписок рейсов на которые есть свободные места:')
                for i in range(0, len(flights)):
                    if flights[i][3] != 0:
                        print(flights[i][0], end='')
                        print(' - ', end='')
                        print(flights[i][1], end='')
                        print(' - ', end='')
                        print(flights[i][3], end=' мест\n')
                input('\n\n\nЧтобы вернуться назад нажмите Enter')
            elif choiceTaskOne == 2:
                os.system('cls')
                print('Cписок рейсов:')
                dictPrint(flights)
                print('\nCписок рейсов с ценой до 100$:')
                for i in range(0, len(flights)):
                    if flights[i][4] <= 100:
                        print(flights[i][0], end='')
                        print(' - ', end='')
                        print(flights[i][1], end='')
                        print(' - ', end='')
                        print(flights[i][4], end='$')
                input('\n\n\nЧтобы вернуться назад нажмите Enter')
            elif choiceTaskOne == 3:
                os.system('cls')
                print('Отсортирований по цене список рейсов:')
                for j in range(len(flights)):
                    for i in range(len(flights) - 1):
                        if flights[i][4] > flights[i + 1][4]:
                            flights[i], flights[i + 1] = flights[i + 1], flights[i]
                dictPrint(flights)
                input('\n\n\nЧтобы вернуться назад нажмите Enter')

            elif choiceTaskOne == 0:
                break

        os.system('cls')
    elif choice == 2:
        text = str(input("Введите текст на англиском: "))
        vowels1 = []
        vowels = ("a", "e", "i", "o", "u", "y")
        for j in [char for char in text]:
            if j in vowels:
                vowels1.append(j)
        vowels2 = sorted(vowels1)
        repeat = []
        for el in vowels2:
            if not (el in repeat):
                repeat.append(el)
        print('Буквы в тексте в алфавитном порядке:')
        print(repeat)
        input('\nЧтобы вернуться назад нажмите Enter')
        os.system('cls')
    else:
        os.system('cls')

