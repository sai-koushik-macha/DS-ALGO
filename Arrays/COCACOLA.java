import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of bottles :");
		int n=sc.nextInt();
		System.out.println("Enter the price of each bottle: ");
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		{
		    a[i]=sc.nextInt();
		}
		System.out.println("Enter the discount percentage : ");
		int d=sc.nextInt();
		for(int i=0;i<n;i++)
		{
		    a[i]=a[i]-(a[i]*d)/100;
		    System.out.println("Price of Bottle "+(i+1)+"  after discount  = "+a[i]);
		}
		
	}
}
