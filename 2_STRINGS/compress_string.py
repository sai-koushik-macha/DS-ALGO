def comp(s):
    count=1
    st=s[0]
    if len(s)==0:
        return ""
    for i in range(1,len(s)):
        if st[-1]==s[i]:
            count+=1
        else:
            if count!=1:
                st = st+str(count)+s[i]
                count = 1
            else:
                st = st+s[i]
    if count!=1:
       st = st+str(count)
    return st
s = input()
st = comp(s)
print(st)