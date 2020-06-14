import math
##########_Main_Function_##########
def cycle():
    sum = 0.0
    member=0.0
    #member=float(member)
    for x in range(1, 6):
        k=0
        while True:
            try:
                
                chis = (math.pow(-1, k)*math.pow((x/2), 2*k+1))
                znam = (k+1)*(math.factorial(k))
                k += 1
                if znam != 0.0:
                    member = chis/znam
                    sum +=  member
                print(x,' ', k,' ', member,' ', sum)
            except OverflowError:
                print("OverFlow – break cycle with k")            
                break  
    return sum


print(60*'=')
print('x',' ','k',' ','member',' ','sum')
print(60*'=')
print(cycle())
print(60*'=')