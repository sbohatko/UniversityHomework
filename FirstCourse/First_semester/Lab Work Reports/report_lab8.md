
### Автор
__Богатько Олександр Геннадійович__

ІПЗ - 1. Варіант 2. Лабораторна номер 8

### Завдання

Скласти програму для обробки словнику та множини. Передбачити меню вибору задач.
Створити словник, який має декілька ключів та значень. Кожному ключу відповідає масив таких елементів: назва фірми, назва вакантної посади, кількість вакантних місць, заробітна платня. Надрукувати словник. Реалізувати запити: 1) визначити фірми з найбільшою кількістю вакансій на задану посаду; 2) вивести назву вакантної посади з найбільшою зарплатою; 3) доповнити словник даними про нову фірму з вакансіями.
Задано текст з цифр і літер латинського алфавіту. Скласти програму, яка визначає, яких літер – голосних {a, e, i, o, u, y} або приголосних більше в цьому тексті.

## Код

```python
# ================================ a ====================================


# ================================ a ====================================

# отримуємо словник з компаніями в яких найбільша кількість вакансій на посаду
def getHighestNumberOfVacancies(dictionary):
    i = 0
    # словник з результатами
    data = {
        "company":[],
        "vacant position": [],
        "number of vacantions": [],
        "salary": []
    } 
    # Цикл для перевірки чи є вакантна така ж вакантна позиція у словнику з результатами
    while i < len(dictionary["vacant position"]):
        # якщо немає, то записуємо словник дані вакантної позиції
        if dictionary["vacant position"][i] not in data["vacant position"]:
            data["company"].append(dictionary["company"][i])
            data["vacant position"].append(dictionary["vacant position"][i])
            data["number of vacantions"].append(dictionary["number of vacantions"][i])
            data["salary"].append(dictionary["salary"][i])
        
        # а якщо є, але кількість місць більша, то ми видаляємо дані старої вакантої позиції та записуємо дані вакантної позиції, де більша кількість місцт
        elif dictionary["vacant position"][i] in data["vacant position"] and dictionary["number of vacantions"][i] > data["number of vacantions"][data["vacant position"].index(dictionary["vacant position"][i])]:
            index = data["vacant position"].index(dictionary["vacant position"][i])
            data["company"].remove(data["company"][index])
            data["company"].append(dictionary["company"][i])
            data["vacant position"].remove(data["vacant position"][index])
            data["vacant position"].append(dictionary["vacant position"][i])
            data["number of vacantions"].remove(data["number of vacantions"][index])
            data["number of vacantions"].append(dictionary["number of vacantions"][i])
            data["salary"].remove(data["salary"][index])
            data["salary"].append(dictionary["salary"][i])
        i += 1
    return data

# вводимо і зберігаємо нову компанію
def inputNewCompany(dictionary):
    dictionary["company"].append(input("Input company name: "))
    dictionary["vacant position"].append(input("Input vacant position name: "))
    dictionary["number of vacantions"].append(int(input("Input number of vacantions: ")))
    dictionary["salary"].append(int(input("Input salary: ")))
    return dictionary

# отримуємо найвищу зарплату
def getHighestSalary(dictionary):
    return dictionary["vacant position"][dictionary["vacant position"].index(max(dictionary["vacant position"]))]

def a():
    # наш словник
    dictionary = {
        "company": ["Ivan corp", "Vasya inc", "yOlo"],
        "vacant position": ["programmer", "designer", "programmer"],
        "number of vacantions": [5, 2, 10],
        "salary": [150, 125, 100]
    }

    # нескінченний цикл для меню
    while True:
        # виводимо  вміст словника
        print(dictionary)
        option = input("The highest number of vacancies(1)\nThe highest salary(2)\nAdd new company(3)\nSelect option: ")
        if option == "1":
            print(getHighestNumberOfVacancies(dictionary))
        elif option == "2":
            print(getHighestSalary(dictionary))
        elif option == "3":
            print(inputNewCompany(dictionary))
        else:
            print("Try again!\n")
# ================================ a ====================================

# ================================ b ====================================
def b():
    # голосні звуки
    vowels = ["a", "e", "i", "o", "u", "y"]
    string = input("Input string: ")
    numOfVowels = 0
    numOfConsonants = 0
    for char in string:
        if char in vowels:
            numOfVowels += 1
        else:
            numOfConsonants += 1
    
    if numOfVowels > numOfConsonants:
        print("Vowels more than consonants: ")
    else:
        print("Consonants more than vowels: ")
    print("Vowels: " + str(numOfVowels))
    print("Consonants: " + str(numOfConsonants))
# ================================ b ====================================
def getAnswer():
    while True:
        # отримуємо відповідь а чи б
        answer = input("Dict app(a)\nString app(b)\nSelect: ")
        # якщо відповідь == а або б, то поветраємо значення відповіді, а якщо ні, то просимо ввести знову
        if answer == "a" or answer == "b":
            return answer
        else:
            print("Error, try again\n\n")

if __name__ == "__main__":
    answer = getAnswer()
    if answer == "a":
        a()
    else:
        b()


```

## Висновок
Висновок : ми ознайомитись з технологією обробки словників та множин в Python. Розробили програми з використанням операцій та методів обробки словників та множин у вигляді одновимірних масивів та матриць. 
