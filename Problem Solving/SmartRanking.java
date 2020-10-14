package com.Sum;

import java.util.Arrays;
import java.util.Scanner;

public class RankingElements {
    public static void main(String args[])
    {
        Scanner read=new Scanner(System.in);
        System.out.println("enter the size of the array");
        int n=read.nextInt();
        int[] elements=new int[n];
        int[] copy=new int[n];
        int[] pos=new int[n];
        System.out.println("enter the elements into the array");

        for(int i=0;i<n;i++)
        {
            elements[i]=read.nextInt();
            copy[i]=elements[i];
        }

        System.out.println("enter A if u want your ranking in Ascending(Least first) Or D for descending(Highest First");
        char key=read.next().charAt(0);
        if(key=='A')
        {
            Arrays.sort(copy);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(elements[i]==copy[j])
                    {
                        pos[i]=j+1;
                    }
                }
            }
            System.out.println(Arrays.toString(elements));
            System.out.println(Arrays.toString(pos));
        }
        else
        {
            Arrays.sort(copy);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(elements[i]==copy[j])
                    {
                        pos[i]=n-j;
                    }
                }
            }
            System.out.println(Arrays.toString(elements));
            System.out.println(Arrays.toString(pos));
        }

    }

}
