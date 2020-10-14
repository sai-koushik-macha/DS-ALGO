"""
**********Problem Statement*********
You are responsible for collecting signatures from all tenants of a certain building.
For each tenant, you know a period of time when he or she is at home.
You would like to collect all signatures by visiting the building as few times as
possible.
The mathematical model for this problem is the following. You are given a set
of segments on a line and your goal is to mark as few points on a line as possible
so that each segment contains at least one marked point.

The first line of the input contains the number 𝑛 of segments. Each of the following 𝑛 lines
contains two integers 𝑎𝑖 and 𝑏𝑖 (separated by a space) defining the coordinates of endpoints of the 𝑖-th
segment.
eg:
Input:
3
1 3
2 5
3 6
Output:
1
3
"""
n=int(input())#number of items of the list
if n==0:
    print("0")
    exit()
start=list()
end=list()
for i in range(n):
    t=input().split()
    start.append(int(t[0]))
    lst=list()
    lst.append(int(t[1]))
    lst.append(i)
    end.append(lst)
print(end)
end.sort()
print(end)
print(start)
index=0
answerCount=0
ans=list()
while index<n:
    if end[index][0]!=-1:
        key=end[index][0]
        for i in range(n):
            if start[i]<=key:
                for j in range(n):
                    if end[j][1]==i:
                        end[j][0]=-1
            i+=1
        answerCount+=1
        ans.append(key)
    index+=1
print(answerCount)
for points in ans:
    print(points,end=" ")
