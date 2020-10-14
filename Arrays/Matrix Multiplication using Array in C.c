#include <stdio.h>
#define MAX 50

int main()
{
    int i,j,k,arow,brow,acolumn,bcolumn,sum;
    int a[MAX][MAX],b[MAX][MAX],product[MAX][MAX];
    printf("Enter the number of rows and Column: ");
    scanf("%d %d", &arow, &acolumn);
    printf("Enter the no of elements of a: \n");
    for(i=0;i < arow;i++)
    {
        for(j=0;j < acolumn;j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }
    printf("Enter the number of rows and Column: ");
    scanf("%d %d", &brow, &bcolumn);

    if(brow != acolumn)
    {
        printf("The Multiplication cannot be done");
    }
    else
    printf("Enter the no of elements of b: \n");
    for(i=0;i<brow;i++)
    {
        for(j=0;j<bcolumn;j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<arow;i++)
    {
        for(j=0;j<bcolumn;j++)
        {
            for(k=0;k<brow;k++)
            {
              sum += a[i][k]*b[k][j];
            }
            product[i][j]= sum;
            sum = 0;
        }
    }
    printf("The Resultant Matrix is: \n");
    for(i=0;i<arow;i++)
    {
        for(j=0;j<bcolumn;j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}
