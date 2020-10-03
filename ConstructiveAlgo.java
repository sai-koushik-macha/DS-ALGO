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
            int b[]=new int[n];
            
            for(int i=0;i<n;i++)
            {
                a[i]=sc.nextInt();
                b[i]=a[i];
            }
            Arrays.sort(b);
            int k=n-1,p=0;
            int ans=10000000,count=0;
            while(true)
            {
                 for(int i=0;i<n;i++)
                 {
                    if(b[k]==a[i])
                    {
                        if(i<ans)
                        {
                        ans=i;
                        count++;
                        }
                        break;
                    }
                 }
               
               k--;
              if(ans==0)
              {
                  break;
              }
               
            }
            if(count%2==0)
            {
                System.out.println("ANDY");
            }
            else
            {
                System.out.println("BOB");
            }
        }
    }
}
