# number systems calculator 2-10 c.c. --> 2-31 c.c.
import time
def func_10_31(x,y,z): # 10c.c. --> 2-31c.c.
    print('The resulting number: ', end ='')
    size = 0
    i = 0
    A = [0] * 100 # "пустой" массив забитый "0"
    div = (int(x))
    while div != 0:
        x = div % z
        div = div // z
        A[size] = x
        #print(A[size])
        size += 1
    b = 0
    u = 0
    K = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'] # это питон сынок, нахер твой аски3 александрию
    while i < size:
        i += 1
        if A[size - i] > 9:
            b = A[size - i]
            u = b - 9
            A[size - i] = K[u - 1]

        print(A[size - i], end='')
    else:

        quit()

def func_2_10_31(digit,step,out):  # перевод в 10 с.с.
    dlina=len(digit)
    #print (dlina)
    chislo_dec=0
    for i in range(0, dlina):
        chislo_dec=chislo_dec+int(digit[i])*(step**(dlina-i-1))
    if output_pow == 10:
        print('The resulting number:',chislo_dec) # 10 c.c. итоговое число
    else:
        print(func_10_31(chislo_dec, total_pow, output_pow))
    quit()

# main()
total_num = (input("Please enter an integer: ")) # ебучий инт пришлось убрать т.к. он нахуй ломает прогу, но в функциях он снова станет 'интовым'
total_pow = int(input("Please enter the degree of the number: "))
output_pow = int(input("Specify the degree of the new number: "))
if (total_pow == 10 and 32 > output_pow > 1):
    print(func_10_31(total_num, total_pow, output_pow))
elif (total_pow < 10 and 32 > output_pow > 1):
    print(func_2_10_31(total_num, total_pow, output_pow))
else:
    print('Are you sure you entered everything correctly? Try again..')
