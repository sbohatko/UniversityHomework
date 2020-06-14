def mainFunc(string): 
    if string.count('(') > string.count(')'): 
        return 'NO' 
 
    for i in range(len(string)): 
        tempString = string[:i+1] 
        if tempString.count('(') < tempString.count(')'): 
            return i 
     
    return 'YES' 
 
 
 
 
stri = input()
print(mainFunc(stri))