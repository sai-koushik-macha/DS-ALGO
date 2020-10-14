import java.util.*;

public class Main {
    
    public static void main (String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int test_cases = sc.nextInt();
        for(int cs = 1; cs <= test_cases; cs++){
            int n = sc.nextInt();
             int a[] = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            leftright(a, n);
        }
   }
   
    public static void leftright(int [] a, int n){
        Arrays.sort(a);
        int mid = (n-1)/2;
        int temp = a[mid];
        a[mid] = a[n - 1];
        a[n - 1] = temp;
    
        int st = mid + 1;
        int ed = n - 2;
        while(st <= ed){
            temp = a[st];
            a[st] = a[ed];
            a[ed] = temp;
            st = st + 1;
            ed= ed - 1;
        }
        for(int i = 0; i < n; i++){
            if(i > 0) System.out.print(" ");
            System.out.print(a[i]);
        }
        System.out.println();
    }
}
