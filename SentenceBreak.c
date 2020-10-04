#include<stdio.h>

main()
{
    char ar[1000];
    int i,n,s=' ';
    gets(ar);
    for(i=0;ar[i]!='\0';i++)
    {
    printf("%c",ar[i]);    
    if(ar[i]==s)
    {
    printf("\n");
   }
   }
}
