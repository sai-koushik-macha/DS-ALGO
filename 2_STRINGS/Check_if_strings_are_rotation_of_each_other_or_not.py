def checkIfRotations(s1,s2):
    # logic:
    # if two strings are rotations of 
    # each other then if we concatenate one with itself
    # the other would be present in the new string.
    
    #creation of new nstring by 
    # repeating the first string
    s3 = s1+s1
    # check if second string present in nwew string
    if s2 in s3:
        return True
    else:
        return False
        
try:
    s1 = input()
    s2 = input()
    
    # call the function
    if checkIfRotations(s1,s2):
        print(s1+" "+s2+" are rotations of each other.")
    else:
        print(s1+" "+s2+" are not rotations of each other.")
except:
    pass
