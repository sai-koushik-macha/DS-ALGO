/*You are given an array of integers,there is a sliding 
window of size k which is moving from the very left of the
array to the very right Each time the sliding window moves 
right by one position.Return the max sliding window.
for example:- 
input: arr=[1,3,-1,-3,5,3,6,7] , k=3
output: [3,3,5,5,6,7]*/

import java.util.*;
public class Max_of_Sliding_Window { 
	static void printKMax(int arr[], int n, int k) 
	{ 
		int j, max; 

		for (int i = 0; i <= n - k; i++) { 

			max = arr[i]; 

			for (j = 1; j < k; j++) { 
				if (arr[i + j] > max) 
					max = arr[i + j]; 
			} 
			System.out.print(max + " "); 
		} 
	} 
	public static void main(String args[]) 
	{ 
                Scanner sc = new Scanner(System.in);
                int n= sc.nextInt();
		int arr[] = new int[n];
                for(int i=0;i<n;i++){
                arr[i]=sc.nextInt();                  
} 
		int k = sc.nextInt(); 
		printKMax(arr, n, k); 
	} 
} 

