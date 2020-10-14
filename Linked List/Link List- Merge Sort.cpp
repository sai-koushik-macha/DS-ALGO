#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(int dat){
		data=dat;
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



void printNode(Node *head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	
	return;
}


Node* findmid(Node *head){
	//Running Algorithm
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

Node* merge(Node* a, Node* b){
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	
	Node* c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
		
	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
Node* mergeSort(Node* &s){
	if(s==NULL || s->next==NULL){
		return s;
	}
	
	Node* mid=findmid(s);
	Node* a=s;
	Node* b=mid->next;
	mid->next=NULL;
	a=mergeSort(a);
	b=mergeSort(b);
	Node* c=merge(a,b);
	return c;
	
	
}

int main(){
	Node*head=inputList();
	
	printNode(head);
	head=mergeSort(head);
	cout<<"\nMerged: ";
	printNode(head);
	//cout<<"\nMid: "<<mid->data;
}


