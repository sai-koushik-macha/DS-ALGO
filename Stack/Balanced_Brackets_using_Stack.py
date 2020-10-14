s=input()
def check_valid(s):
    stack=[]
    for i in s:
        if(stack==[]):
            stack.append(i)
        elif(i=='(' or i=='{' or i=='['):
            stack.append(i)
        else:
            if(i==')' and stack[-1]=='('):
                stack.pop()
            elif(i=='}' and stack[-1]=='{'):
                stack.pop()
            elif(i==']' and stack[-1]=='['):
                stack.pop()
            else:
                return False
    if(stack==[]):
        return True
    return False
print(check_valid(s))
