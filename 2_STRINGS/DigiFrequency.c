#include<stdio.h>
main()
{
    char str[1000];
    int k=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,z=0;
   
    gets(str);
    while(str[k]!='\0')
    {
        if(str[k]=='0')
        {
         a++;
        }
        else if(str[k]=='1')
        {
         b++;
        }
        else if(str[k]=='2')
        {
         c++;
        }
        else if(str[k]=='3')
        {
         d++;
        }
        else if(str[k]=='4')
        {
         e++;
        }
        else if(str[k]=='5')
        {
         f++;
        }
        else if(str[k]=='6')
        {
         g++;
        }
        else if(str[k]=='7')
        {
         h++;
        }
        else if(str[k]=='8')
        {
         i++;
        }
        else if(str[k]=='9')
        {
         j++;
        }
         else
        {
         z++;
        }
        k++;
    }
    printf("%d %d %d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h,i,j);
}
