/**
 * CREATED BYKARTHIK FROM NARSHIMA BOOK FOR LOGIC
 *
 * 3:43 AM  5/10/20
 */
*/
import java.util.*;
public class TwoSum{
    //This is not returning minimum index1;
    public static ArrayList<Integer> twoSumSolution(final List<Integer> a, int b) {
        
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        ArrayList<Integer> result = new ArrayList<Integer>();
        result.add(0);
        result.add(0);
        for(int i = 0; i < a.size(); i++){
            if(map.containsKey(a.get(i))){
                int index = map.get(a.get(i));
                result.set(0, index + 1);
                result.set(1, i + 1);
                break;
            }
            else{
                map.put(b - a.get(i), i);
            }
        }
        
        
        
//         System.out.println("Printing");
//        for(int i : map.values())
//            System.out.print(i + " ");
//        
//        System.out.println();
        return result;
    }
   static class Node implements Comparable<Node> {
        
        int left;
        int right;
        
        public Node(int left, int right) {
            this.left = left;
            this.right  = right;
        }
        
        public int compareTo(Node o) {
            if (this.right < o.right)
                return -1;
            if (this.right > o.right)
                return 1;
                
            return Integer.compare(this.left, o.left);
        }
        
    }
    
 public ArrayList<Integer> twoSum(final List<Integer> A, int B) {
     
     int sum = B;
     int diff;
     HashMap<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
     int size = A.size();
     int num;
     int index;
     ArrayList<Integer> res = new ArrayList<Integer>();
        ArrayList<Node> node = new ArrayList<>();
     
     for (int i = size - 1; i >= 0; i--) {
         num = A.get(i);
         diff = sum - num;
         
         if (hashMap.containsKey(diff)) {
             index = hashMap.get(diff);
             node.add(new Node(i + 1, index + 1));
         }
         
         hashMap.put(num, i);
         
     }
     
     if (node.size() > 0) {
         Collections.sort(node);
            res.add(node.get(0).left);
            res.add(node.get(0).right);
     }
     
     return res;
     
 }
    public static void main(String[] args){
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(2);
        a.add(7);
        a.add(11);
        a.add(15);
        ArrayList<Integer> result = twoSumSolution(a, 9);
        for(int i : result)
            System.out.print(i + " ");
    }
}
}
