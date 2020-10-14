#You are on stair 0, in how many distinct ways you can climb to stair n
#You can either climb 1 step or 2 step at a time

s=int(input())
def ways(n):
    if(n<=3):
        return n
    dp=[0]*(n+1)
    dp[1]=1
    dp[2]=2
    for i in range(3,n+1):
        dp[i]=dp[i-1]+dp[i-2]
    return dp[n]
print(ways(s))
