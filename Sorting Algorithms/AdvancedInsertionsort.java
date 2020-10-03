import java.util.*;
class Solution
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        int count=0;
        for(int i=1;i<n;i++)
        {
            int in=i;
            int val=a[i];
            while(in>0 && a[in-1]>val)
            {
                a[in]=a[in-1];
                in--;
                count++;
            }
            a[in]=val;
        }
        System.out.println(count);
        }
    }
}
