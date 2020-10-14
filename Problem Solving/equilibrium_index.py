def equilibriumIndex(arr):
    # Please add your code here
    t_s = 0
    i = 0
    l = len(arr)
    while i<l:
        t_s = t_s + arr[i]
        i = i+1
    left_sum = 0
    index = 0
    while index <l:
        right_sum = t_s - left_sum-arr[index]
        if left_sum == right_sum:
            return index
        else:
            left_sum = left_sum+arr[index]
            index = index+1

# Main
n = int(input())
arr = [int(i) for i in input().strip().split()]
print(equilibriumIndex(arr))