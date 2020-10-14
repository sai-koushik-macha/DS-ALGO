def subset_array(lst,output=""):
    if len(lst)==0:
        print(output)
        return 
    subset_array(lst[1:],output)
    subset_array(lst[1:],output+str(lst[0])+" ")
n = int(input())
lst=[int(i) for i in input().split()]
subset_array(lst)