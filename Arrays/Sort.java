public class Sort{
    int[][] A = { { 17, 7, 21, 41, 45, 131, 14, 101, 198, 139 }, { 89, 15, 2, 59, 40, 26, 115, 60, 151, 18 } };
    public boolean checkPrime(int k){
        if(k == 2 || k == 3){
            return true;
        }
        for(int i = 2;i < k / 2;i++){
            if(k % i == 0){
                return false;
            }
        }
        return true;
    }
    public void primeAndNonPrime(){
        int i,j;
        i = 0;
        j = 0;
        while(i < 10 && j < 10){
            if(checkPrime(A[0][i])){
                while(checkPrime(A[1][j])){
                    j++;
                }
                int temp = A[0][i];
                A[0][i] = A[1][j];
                A[1][j] = temp;
                j++;
            }
            i++;
        }
        while(j < 10){

        }
    }
    public void sort(){
        for(int i = 0;i < 10;i++){
            for(int j = (i+1);j< 10;j++){
                if(A[0][i] > A[0][j]){
                    int temp = A[0][i];
                    A[0][i] = A[0][j];
                    A[0][j] = temp;
                }
                if (A[1][i] < A[1][j]) {
                    int temp = A[1][i];
                    A[1][i] = A[1][j];
                    A[1][j] = temp;
                }
            }
        }
    }
    public void print(){
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 10;j++){
                System.out.print(A[i][j]+ " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
      Sort s = new Sort();
      System.out.println("Given Array that::");
      s.print();
      System.out.println();
      System.out.println("After Seperating Prime and Non prime");
      s.primeAndNonPrime();
      s.print();
      System.out.println();
      System.out.println("After Sort");
      s.sort();
      s.print();
    }
}
