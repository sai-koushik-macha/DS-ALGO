import java.util.*;

public class sumOfTwoNumbers{
/*
*	Given an array of numbers and a target number
*	check wether any two numbers of the array adds to the given target number
*	if many such pairs exist,print any one and if no such pair exist print
*	relevant message
*
*	constraints:
*	2 < i < 10^4;
*	0 < a[i] < 10^4;
* 	0 < target < 2*10^4; 
*/

	public static void main(String args[]) 
	{
	    //time complexity is O(n)
	    
		Scanner scanner = new Scanner(System.in);
		
		int arrayLength = scanner.nextInt();
		int[] array = new int[arrayLength];
		
		for(int i = 0 ; i < arrayLength ; i++)
			array[i] = scanner.nextInt();

        	int target = scanner.nextInt();
        
           //hashset to store the complement of the number wrt the target
		HashSet<Integer> encountered = new HashSet<>();
		
	   //boolean indicating if a pair has been found or not
		boolean pairFound = false;		

		for(int i = 0 ; i < arrayLength ; i++)
		{
			int temp = array[i];
			
			//if the number is found,it means the complement of it already 
			//exist and sum of these two is the target number.
		
			if(encountered.contains(temp))
			{
				System.out.println("The number " + temp + " and " + (target-temp) +" adds to " + target);
				pairFound = true;
				break;
			}
            
            		//add the complement of the number wrt target
			encountered.add(target-temp);
		}

		//print negative result if no such pair has been found
		if(!pairFound)
			System.out.println("No pair exist which adds to the given "+target);
	}

}