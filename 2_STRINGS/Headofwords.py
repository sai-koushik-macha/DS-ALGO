sen=input("Enter the sentence :").split()
for i in sen:
    p=""
    count=0
    for j in i:
        count=count+1
    for j in range(0,count):
        if j==0 or j==count-1:
            p=p+chr(ord(i[j])-32)
        else:
            p=p+i[j]
    print(p," ",end=" ")
    
   # i had taken a sentence and splited the sentence into list of words and capitalized each word and then made it into sentence
