import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Queue<Integer> q  = new LinkedList<>();
        int t=sc.nextInt();
        while(t-->0)
        {
            int a=sc.nextInt();
            if(a==1)
            {
                int s=sc.nextInt();
               q.add(s);
            }
            else if(a==2)
            {
                 q.remove();
            }
            else if(a==3)
            {
               System.out.println(q.peek());
            }
        } 
    }
}
