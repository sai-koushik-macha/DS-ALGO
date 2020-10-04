"""
You are given two positive integers a and b.

In one move, you can change a in the following way:

Choose any positive odd integer x (x>0) and replace a with a+x;
choose any positive even integer y (y>0) and replace a with a−y.
You can perform as many such operations as you want. You can choose the same numbers x and y in different moves.

Your task is to find the minimum number of moves required to obtain b from a. It is guaranteed that you can always obtain b from a.

You have to answer t independent test cases.
"""
t=int(input())# input the number of test cases
for i in range(t):
    a,b=map(int,input().split()) # getting te=he values of a and b
    diff=a-b  # finding the difference 
    if diff<0:
        diff*=-1
        if diff%2==0:
            print('2')
            continue
        else:
            print('1')
            continue
    elif diff>0:
        if diff%2==0:
            print('1')
            continue
        else:
            print('2')
            continue
    else:
        print('0')
        continue
