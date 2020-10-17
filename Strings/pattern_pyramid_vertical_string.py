# string converted in form of vertical pyramid
# For example if given input string is hello
# then it will print this 
# h
# h e
# h e l
# h e l l
# h e l l o
# h e l l
# h e l
# h e
# h
s=input("enter a string:")
l=len(s)   # take input string
for i in range(0,l+1):  #for uper triangle
    for j in range(0,i):
        print(s[j], end=" ")
    print(" ")
for i in range(l-1,0,-1):  #for lower triangle
    for k in range(0,i):
        print(s[k], end=" ")
    print(" ") 