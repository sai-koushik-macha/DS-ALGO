// Java program for convert Selection Sort 
// as, it is unstable to make it stable
class Convert 
{ 
	static void SelectionSort(int[] a, int n) 
	{ 
		
		for (int i = 0; i < n - 1; i++) 
		{ 
			int min = i; 
			for (int j = i + 1; j < n; j++) 
				if (a[min] > a[j]) 
					min = j; 

			// Move minimum element at current i. 
			int key = a[min]; 
			while (min > i) 
			{ 
				a[min] = a[min - 1]; 
				min--; 
			} 
			
			a[i] = key; 
		} 
	} 

	static void printArray(int[] a, int n) 
	{ 
		for (int i = 0; i < n; i++) 
		System.out.print(a[i]+ " "); 
		
		System.out.println(); 
	} 

	
	public static void main (String[] args) 
	{ 
		int[] a = { 4, 5, 3, 2, 4, 1 }; 
		int n = a.length; 
		SelectionSort(a, n); 
		printArray(a, n); 
	} 
} 


