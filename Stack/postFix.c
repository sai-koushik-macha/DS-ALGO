#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int main(int argc, char *argv[]){
    int n;
    char str1[] = "A+(B*C-(D/E^F)*G)*H";
    n=strlen(str1);
    char str[n+2];
    str[0]='(';
    str[n+1]=')';
    str[n+2]='\0';
    for(int i=0;i<n;i++){
        str[i+1]=str1[i];
    }
    n=strlen(str);
    int j=0;
    struct Stack *stack3 = createStack(n);
    for(int i=0;i<n;i++){
        int a = str[i];
        char c;
        if (str[i] == '('){
            push(stack3, str[i]);
       }
       else if(str[i]==')'){
           c=pop(stack3);
           while(c!='('){
               str1[j]=c;
               j++;
               c=pop(stack3);
           }
       }
       else if(a>=65 && a<=90){
           str1[j]=str[i];
           j++;
       }
       else{
           if(str[i]=='-' || str[i]=='+'){
               c=pop(stack3);
               if(c=='*' || c=='/' || c=='^'){
                   push(stack3,str[i]);
                   str1[j]=c;
                   j++;
               }
               else{
                   push(stack3,c);
                   push(stack3,str[i]);
               }
           }
           if (str[i] == '*' || str[i] == '/')
           {
               c = pop(stack3);
               if (c == '^')
               {
                   push(stack3, str[i]);
                   str1[j] = c;
                   j++;
               }
               else
               {
                   push(stack3, c);
                   push(stack3, str[i]);
               }
           }
           if(str[i]=='^'){
               push(stack3,str[i]);
           }
       }
    }
    for(int i=0;i<j;i++){
        printf("%c",str1[i]);
    }
    printf("\n");
}
