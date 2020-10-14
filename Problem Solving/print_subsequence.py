
def printSubsequences(string,output=""):
    #Implement Your Code Here
    if len(string)==0:
        print(output)
        return
    printSubsequences(string[1:],output+string[0])
    printSubsequences(string[1:],output)

string = input()
printSubsequences(string)