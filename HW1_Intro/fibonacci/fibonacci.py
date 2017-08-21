# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n
    fib_list = [0, 1] #index: 0,1
    for x in range(2, n+1):
        fib_list.append(fib_list[x-2] + fib_list[x-1])
    return fib_list[-1]


flg = 0

while flg == 0:
    print('Please input a number')
    n = int(input())
    print(calc_fib(n))
    print('Continue?(Y=0/N=1)')
    flg = int(input())	
