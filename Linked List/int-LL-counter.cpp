// Program to count the number of times a certain integer occurs
// in the Linked List.


#include <bits/stdc++.h>
using namespace std;


class Node {

   public:
      int data;
      Node* next;

};


void push(Node** head_ptr, int new_data) {

   Node* new_node = new Node();

   new_node->data = new_data;

   new_node->next = (*head_ptr);

   (*head_ptr) = new_node;


}


int count(Node* head, int find) {

   Node* curr = head;
   int count = 0;
   while (curr != nullptr) {
      if (curr->data == find)
         count++;
      curr = curr->next;

   }

   return count;
}


int main() {

   //empty list created here
   Node* head = nullptr;



   push(&head, 7);
   push(&head, 3);
   push(&head, 2);
   push(&head, 7);
   push(&head, 7);

   cout << "The count of 7 is: " << count(head, 7);

   return 0;
}