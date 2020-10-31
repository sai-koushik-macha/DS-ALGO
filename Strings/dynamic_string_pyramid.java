// this program will dym=namically takes string and 
// generates pattern of pyramid made of the given string
import java.util.Scanner;
class stringPyramid
{
    public static void main(String []p)
    {
        String pl;
        System.out.println("enter string herer::"); 
        Scanner sc = new Scanner(System.in);
        pl = sc.nextLine();// takes string
        int n;
        n = pl.length();
        
        for(int i=0;i<n;i++) // generate pyramind patten
        {
            for(int j=n;j>i;j--)
            {
                System.out.print(" ");
                
            }
            for(int k=0;k<=i;k++)
            {
                System.out.print(pl.charAt(k)+" ");//prints the character of the string
            }
            System.out.println(" ");
        }
    }
}