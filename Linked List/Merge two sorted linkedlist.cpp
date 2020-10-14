// C program to merge two sorted linked lists 
// in-place. 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
//to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
}  
// Merges two given lists.
Node* merge(Node* node1, Node* node2) 
{ 
    if (!node1) 
        return node2; 
    if (!node2) 
        return node1; 
    if (node1->data < node2->data) { 
        node1->next = merge(node1->next, node2); 
        return node1; 
    } 
    else { 
        node2->next = merge(node1, node2->next); 
        return node2; 
    } 
} 
  
// Driver program 
int main() 
{ 
    Node* node1 = newNode(1); // 1->10->100
    node1->next = newNode(10); 
    node1->next->next = newNode(100); 
  
    Node* node2 = newNode(2); // 2->20->80
    node2->next = newNode(20); 
    node2->next->next = newNode(80); 
  
    Node* m_node = merge(node1, node2); 
  
  	//printing list
    while (m_node != NULL) { 
        cout<<m_node->data<<" "; 
        m_node = m_node->next; 
    } 
    return 0; 
} 
