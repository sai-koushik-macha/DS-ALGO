#include<stdio.h>
#include<math.h>
#define f(x) (sin(x)/(1+pow(x,3)))
void main()
{
    int i;
    float a,b,n,h,sum=0;
    printf("enter values of a,b and n\n");
    scanf("%f%f%f",&a,&b,&n);
    h=(b-a)/n;
    sum=f(a)+f(b);
    for(i=1;i<n;i++)
    {
        if(i%2==0)
           sum=sum+(2*f(a+(i*h)));
        else
            sum=sum+(4*f(a+(i*h)));

    }
    sum=(sum*h)/3;
    printf("value of integration is %f",sum);
}
