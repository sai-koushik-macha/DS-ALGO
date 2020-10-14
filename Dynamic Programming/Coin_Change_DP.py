#You are given coins of different denominations and a total amount of money.
#Find the number of combinations that make up that amount.
#You may assume that you have infinite number of each kind of coin.
#Example: If amount=5 and coins=[1,2,5], answer is 4, that are (1+1+1+1+1),(1+1+1+2),(1+2+2),(5) 

amt=int(input())
c=list(map(int,input().split()))
def number_of_combinations(amount,coins):
    dp=[0]*(amount+1)
    dp[0]=1
    for c in coins:
        for i in range(c,amount+1):
            dp[i]+=dp[i-c]
    return dp[amount]

print(number_of_combinations(amt,c))
