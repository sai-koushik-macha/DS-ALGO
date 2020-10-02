"""
implemented Heap sort
"""

import java.util.Scanner;
public class HeapSort {
    static int heapsize=0;//class variable which keeps track of the heap size which will be useful wh
                          //when we are removing the first element from the stack
                          //then the stack size would reduce
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("enter the size of the array");
        int size = read.nextInt();
        int[] arr = new int[size];//array to hold heap elements
        System.out.println("enter the elements into the array");
        for (int i = 0; i < size; i++) {
            arr[i] = read.nextInt();
        }
        heapSort(arr);

    }
        /* heap sort algorithm*/
        public static void heapSort(int[] arr)
        {
            heapsize = arr.length;
            build_Heap(arr);//building heap
            //System.out.println(Arrays.toString(arr));
            for(int i=arr.length-1;i>0;i--)
           {
          /* basically we are swapping the first element and last element
          and heapifying and decreasing the heap size so that the last element is
          out of the heap*/
            int temp=arr[0];
            arr[0] =arr[i];
            arr[i]=temp;
            heapsize--;//removing the first element and decreasing the heap size so that the first
                       //element which is added to the last is'nt part of the heap
            max_heapify(arr,0);
            }
        //System.out.println(Arrays.toString(arr));
    }
    static void build_Heap(int[] arr)
    {
        for(int i=heapsize/2-1;i>=0;i--)
        {
            max_heapify(arr,i);
        }
    }
    static void max_heapify(int[] arr,int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest ;
        if (l < heapsize && arr[l] > arr[i])
        {
            largest = l;
        }
        else
            largest = i;
        if (r < heapsize && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            max_heapify(arr, largest);
        }
    }
}
