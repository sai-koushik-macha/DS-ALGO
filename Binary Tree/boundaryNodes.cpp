#include<iostream>
using namespace std;
typedef struct btnode * BTPTR;
struct btnode
{
	BTPTR lchild;
	char data;
	BTPTR rchild;
};
void create(BTPTR &T,char a[],int& n)
{
	if(a[n]!='.')
	{
		T=new btnode();
		T->data=a[n];
		T->lchild=NULL;
		T->rchild=NULL;
		cout<<T->data<<endl;
		n++;
		create(T->lchild,a,n);
		n++;
		create(T->rchild,a,n);
	}
	else
	{
		return;
	}
}
void left(BTPTR T)
{
	if(T!=NULL)
	{
		if(T->lchild!=NULL)
		{
			cout<<T->data<<" ";
			left(T->lchild);
		}
		else if(T->rchild!=NULL)
		{
			cout<<T->data<<" ";
			left(T->rchild);
		}
	}
}
void right(BTPTR T)
{
	if(T!=NULL)
	{
		if(T->lchild!=NULL)
		{
			cout<<T->data<<" ";
			right(T->lchild);
		}
		else if(T->rchild!=NULL)
		{
			cout<<T->data<<" ";
			right(T->rchild);
		}
	}
}
void leaf(BTPTR T)
{
	if(T!=NULL)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
			cout<<T->data<<" ";
		leaf(T->lchild);
		leaf(T->rchild);	
	}
}
int main()
{
	BTPTR T=NULL;
	char c[30];
	cin.getline(c,30);
	int n=0;
	create(T,c,n);
	cout<<"boundary elements are "<<endl;
	left(T);
	leaf(T);
	right(T->rchild);
	
}
