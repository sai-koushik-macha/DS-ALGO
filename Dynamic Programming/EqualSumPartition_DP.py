"""
given a list of numbers we have to find out if that list can be partitioned into two parts such that each part has equal sum
example 1:
enter a list of elements(integers) 1 2 2 5
yes we can partition the list into two parts of equal sum

example 2:
enter a list of elements(integers) 1 2 3 4 5
we cannot partition the list into two parts of equal sum

"""
def canPartition(List):
    n=len(List)
    S=sum(List)
    if S%2!=0:
        return False
    S=S//2
    rows, cols = (n+1,S+1)
    t = [[False for i in range(cols)] for j in range(rows)]
    for i in range(n+1):
        t[i][0]=True

    for i in range(1,n+1):
        for j in range(1,S+1):
            if List[i-1]<=j:
                t[i][j]=t[i-1][j] or t[i-1][j-List[i-1]]
            else:
                t[i][j]=t[i-1][j]
    return t[n][S]

ll=list(map(int,input('enter a list of elements(integers) ').split()))
if (canPartition(ll)):
    print("yes we can partition the list into two parts of equal sum")
    
else:
    print("we cannot partition the list into two parts of equal sum")
