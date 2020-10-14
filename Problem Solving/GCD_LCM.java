
import java.util.*;

class GCD_LCM {
	public static void main (String[] args) {
	    Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t-->0){
		    int a=in.nextInt();
		    int b=in.nextInt();
		    System.out.println(lcm(a,b)+" "+gcd(a,b));
		}
	}
	static int gcd(int a, int b) 
	{ 
    	if (a == 0) 
    		return b; 
    	return gcd(b % a, a); 
	} 
	static int lcm(int a, int b) 
	{ 
		return (a*b)/gcd(a, b); 
	} 
}