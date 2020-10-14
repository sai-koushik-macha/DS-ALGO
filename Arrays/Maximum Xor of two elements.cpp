#include <bits/stdc++.h> 
using namespace std; 
  

class node { 
public: 
    node* left; 
    node* right; 
}; 
  

void insert(int x, node* head) 
{ 
    
    node* curr = head; 
  
    for (int i = 30; i >= 0; i--) { 
  
        // Find the i-th bit 
        int val = (x >> i) & 1; 
  
        if (val == 0) { 
  
            // If curr->left is NULL 
            if (!curr->left) 
                curr->left = new node(); 
  
            // Update curr to curr->left 
            curr = curr->left; 
        } 
        else { 
  
            // If curr->right is NULL 
            if (!curr->right) 
                curr->right = new node(); 
  
            // Update curr to curr->right 
            curr = curr->right; 
        } 
    } 
} 
  
 
int findMaximumXOR(int arr[], int n) 
{ 
    // head Node of Trie 
    node* head = new node(); 
  
    // Insert each element in trie 
    for (int i = 0; i < n; i++) { 
        insert(arr[i], head); 
    } 
  
    // Stores the maximum XOR value 
    int ans = 0; 
  
    // Traverse the given array 
    for (int i = 0; i < n; i++) { 
  
        // Stores the XOR with current 
        // value arr[i] 
        int curr_xor = 0; 
  
        int M = pow(2, 30); 
  
        node* curr = head; 
  
        for (int j = 30; j >= 0; j--) { 
  
            
            int val = (arr[i] >> j) & 1; 
  
            // Check if the bit is 0 
            if (val == 0) { 
  
                // If right node exists 
                if (curr->right) { 
  
                    // Update the currentXOR 
                    curr_xor += M; 
                    curr = curr->right; 
                } 
  
                else { 
                    curr = curr->left; 
                } 
            } 
  
            else { 
  
                if (curr->left) { 
  
                    
                    curr_xor += M; 
                    curr = curr->left; 
                } 
                else { 
                    curr = curr->right; 
                } 
            } 
  
            
            M /= 2; 
        } 
  
       
        ans = max(ans, curr_xor); 
    } 
  
   
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    // Given array arr[] 
    int arr[] = { 1, 2, 3, 4 }; 
  
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    // Function Call 
    cout << findMaximumXOR(arr, N); 
  
    return 0; 
} 
