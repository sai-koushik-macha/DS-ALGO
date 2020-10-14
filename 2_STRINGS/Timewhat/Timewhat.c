#include<stdio.h>
main()
{
    char s[10],A;
    int i;
    gets(s);
    if(s[8]=='P' && s[9]=='M')
    {
        for(i=0;i<2;i++)
        {
            if(s[i]=='0' && s[i+1]=='1')
            printf("13");
            else if(s[i]=='0' && s[i+1]=='2')
            printf("14");
            else if(s[i]=='0' && s[i+1]=='3')
            printf("15");
            else if(s[i]=='0' && s[i+1]=='4')
            printf("16");
            else if(s[i]=='0' && s[i+1]=='5')
            printf("17");
            else if(s[i]=='0' && s[i+1]=='6')
            printf("18");
            else if(s[i]=='0' && s[i+1]=='7')
            printf("19");
            else if(s[i]=='0' && s[i+1]=='8')
            printf("20");
            else if(s[i]=='0' && s[i+1]=='9')
            printf("21");
            else if(s[i]=='1' && s[i+1]=='0')
            printf("22");
            else if(s[i]=='1' && s[i+1]=='1')
            printf("23");
              else if(s[i]=='1' && s[i+1]=='2')
              printf("12");

            

        }
    
        for(i=2;i<8;i++)
        printf("%c",s[i]);
    }
    else if(s[8]=='A'&&s[9]=='M')
    {
            for(i=0;i<2;i++)
            {
                if(s[i]=='1' && s[i+1]=='2')
                {
                  printf("00");  
                  break;
                }
                else
                {
                    printf("%c",s[i]);
                }
            }

    for(i=2;i<8;i++)
    {
        printf("%c",s[i]);
    }
    }
}
