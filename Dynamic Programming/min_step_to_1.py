import sys
def countStepsTo1(n) :
     steps = [0 for i in range(n+1)]
     for i in range(2, n+1) :
         count1 = steps[i-1]
         count2 = sys.maxsize
         count3 = sys.maxsize
         if i % 3 == 0 :
             count2 = steps[i // 3]
         elif i % 2 == 0:
             count3 = steps[i // 2]
         
         steps[i] = 1 + min(count1, min(count2, count3))
     return steps[n]
    

# Main
n=int(input())
#dp = [-1 for i in range(n+1)]
print(countStepsTo1(n))

