

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
#define TPTR struct Node*
Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int inSearch(int in[],int l,int h,int x)
{
    for(int i=l;i<=h;i++)
    {
        if(in[i]==x) return i;
    }
    return 0;
}

void treeCreate(TPTR &T,int in[],int pre[],int &i,int n,int x,int y)
{
    if(i>=n) return ;
    int p=inSearch(in,x,y,pre[i]);
    if(p>=x && p<=y)
    {
        T=new Node(pre[i]);
        T->data=pre[i];

        i++;
        treeCreate(T->left,in,pre,i,n,x,p-1);
        treeCreate(T->right,in,pre,i,n,p+1,y);
    }
    return;

}

Node* buildTree(int in[],int pre[], int n)
{
    TPTR T=new Node(pre[0]);
    int i=0;
    treeCreate(T,in,pre,i,n,0,n-1);
    return T;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
