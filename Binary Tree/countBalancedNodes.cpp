// C++ program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a
// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to get the sum of left
// subtree and right subtree
int Sum(Node *root, int &res)
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }

    // Store the sum of
    // left subtree
    int leftSubSum = Sum(root->left, res);

    // Store the sum of
    // right subtree
    int rightSubSum = Sum(root->right, res);

    // Check if node is balanced or not
    if (root->left and root->right && leftSubSum == rightSubSum)

        // Increase count of
        // balanced nodes
        res += 1;

    // Return subtree sum
    return root->data + leftSubSum + rightSubSum;
}

// Driver Code
int main()
{

    // Insert nodes in tree
    Node *root = new Node(9);
    root->left = new Node(2);
    root->left->left = new Node(-1);
    root->left->right = new Node(3);
    root->right = new Node(4);
    root->right->right = new Node(0);

    // Store the count of balanced nodes
    int res = 0;
    Sum(root, res);
    cout << res;
}
