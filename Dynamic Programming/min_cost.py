import sys
def minCost(cost,n,m):
    dp=[[sys.maxsize for i in range(m+1)]for i in range(n+1)]
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            if i==n-1 and j==m-1:
                dp[i][j]=cost[i][j]
            else:
                ans1=dp[i+1][j]
                ans2=dp[i][j+1]
                ans3=dp[i+1][j+1]
                dp[i][j]=cost[i][j]+min(ans1,ans2,ans3)
    return dp[0][0]
   
sys.setrecursionlimit(23787654) 
    
li=[int(ele) for ele in input().split()]
n=int(li[0])
m=int(li[1])

cost=[]
for i in range(n):
    p=[int(j)for j in input().split()]
    cost.append(p)


print(minCost(cost,n,m))