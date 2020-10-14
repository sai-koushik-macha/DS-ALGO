import java.util.*;
class Solution
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        int b[]=new int[n];
        int c[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
            b[i]=a[i];
        }
        Arrays.sort(b);
        int count=0,k=0,l=0,r=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                c[k]=a[i];
                k++;
                count++;
                if(count==1)
                {
                     l=i+1;
                }
                else if(count==2)
                {
                     r=i+1;
                }
                else
                {
                     t=i+1;
                }
                
            }

        }
        if(count==2)
        {
          System.out.println("yes");
          System.out.println("swap "+l+" "+r);
        }
        else
        {
            int count2=0;
            for(int i=k-1;i>0;i--)
            {
                 if(c[i]<c[i-1])
                 {
                     count2++;
                 }
            }
            if(count2==(k-1))
            {
                System.out.println("yes");
                System.out.println("reverse "+l+" "+t);
            }
            else
            {
                System.out.println("no");
            }
        }

    }
}
