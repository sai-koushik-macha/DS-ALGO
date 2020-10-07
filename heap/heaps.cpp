#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void heap_sort(int h[],int &n)
{
	if(n>0)
	{
		cout<<h[0]<<" ";
		h[0]=h[n-1];
		n=n-1;
		int i=0;
		while((h[i]>h[2*i+1]||h[i]>h[2*i+2])&&(2*i+1)<n)
		{
			if(h[2*i+1]>h[2*i+2])
			{
				swap(h[i],h[2*i+2]);
				i=2*i+2;
			}			
			else if(h[2*i+1]<h[2*i+2])
			{
				swap(h[i],h[2*i+1]);
				i=2*i+1;
			}
			else 
				break;
		}
	//	n=n-1;
		heap_sort(h,n);
	}
}
void insert(int h[],int n,int k)
{
	h[n]=k;
	while(n>0)
	{
		if(h[n]<h[(n-1)/2])
		{
			swap(h[n],h[(n-1)/2]);
			n=(n-1)/2;
		}
		else 
			break;
	}
}
int main()
{
	//7 21 5 10 2 36 18
	int h[20]={0};
	int k;
	cout<<"enter the number \n";
	cin>>k;
	int i=0;
	while(k!=-1)
	{
		insert(h,i,k);
		cout<<"enter number or -1 to end \n";
		cin>>k;
		i++;
	}
	for(int i=0;i<20;i++)
		cout<<h[i]<<" ";
	cout<<endl;
	int n=7;
	heap_sort(h,n);	
}
