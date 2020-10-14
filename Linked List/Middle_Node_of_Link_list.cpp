#include<bits/stdc++.h>
using namespace std;


class Node{
	public:
		int data;
		Node* next;
		Node(int d){
			data=d;
			next=NULL;
		}
};


void insertatEnd(Node* &head,Node*&last,int data){
	if(head==NULL){
		head=new Node(data);
		last=head;
		return;
	}
	else{
		Node* newNode=new Node(data);
		last->next=newNode;
		last=newNode;
	}
	return;
}



Node* inputList(){
	Node* head=NULL;
	Node*last= head;
	int d;
	cin>>d;
	while(d!=-1){  //Takes input till input is -1
		insertatEnd(head,last,d);
		cin>>d;
	}
	return head;
}





Node* findMid(Node*head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	else{
		Node *fast=head->next;
		Node *slow=head;
		
		while(fast!=NULL && fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
			
		}
		return slow;
	}
	
}


void printNode(Node *head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	
	return;
}

int main(){
	Node*head=inputList();
	printNode(head);
	Node* mid=findMid(head);
	cout<<"\nMid: "<<mid->data;
}
