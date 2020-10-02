#include <stdio.h>

int main()
{
  int a[5];
  int i,j,rem,res;
   for(i=0;i<5;i++)
  {
    printf("Enter The no ");
    scanf("%d", &a[i]);
  }
  for(i=0;i<5;i++)
  {
      j= a[i];
      res = 0;
      while(j != 0)
      {
          rem=j%10;
          res = res*10 + rem;
          j = j/10;
      }
      if(res == a[i])
        printf("\n %d is a Plindrome", a[i]);
      else
        printf("\n %d isn't a Palinrome ", a[i]);
  }
}
