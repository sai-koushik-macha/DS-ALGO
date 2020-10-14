#include<iostream>
#include<cstring>
using namespace std;
typedef struct btnode * BTPTR;
struct btnode
{
	BTPTR lchild;
	char data;
	BTPTR rchild;
};
int find(char LDR[],char c,int n)
{
	int i=0;
	while(LDR[i]!=c)
	{
		i++;
	}
	//cout<<i<<endl;
	return i;
}
void create(BTPTR &T,char DLR[],char LDR[],int l,int n,int &i,int y)
{
	int t;
	t=find(LDR,DLR[i],n);
	if(n>=l)
	{		
		T=new btnode();
		T->data=DLR[i];
		T->lchild=NULL;
		T->rchild=NULL;
		i=i+1;
		create(T->lchild,DLR,LDR,l,t-1,i,y);
		create(T->rchild,DLR,LDR,t+1,n,i,y);	
	}
}
void sort(BTPTR &T)
{
	if(T!=NULL)
	{
		
		sort(T->lchild);
		cout<<T->data<<" ";	
		sort(T->rchild);
		
	
	}
	else
		return;
}

int main()
{
	BTPTR T=NULL;
	char LDR[20],DLR[20];
	cout<<"LDR then DLR"<<endl;
	cin.getline(LDR,20);
	cin.getline(DLR,20);
	int t=strlen(DLR);
	int n=0,y=t;
	//cout<<"A"<<endl;
	create(T,DLR,LDR,0,t-1,n,y);
	sort(T);
}
