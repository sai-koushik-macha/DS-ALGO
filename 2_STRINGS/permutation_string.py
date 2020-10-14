def printPermutations(s,string):
    #Implement Your Code Here
    if len(string)==0:
        print(s)
    else:
        for i in range(len(string)):
            printPermutations(s+string[i],string[0:i]+string[i+1:])

string = input()
s=""
printPermutations(s,string)
