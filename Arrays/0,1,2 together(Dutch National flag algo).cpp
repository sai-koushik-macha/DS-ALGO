#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cout<<"Enter size of array ";
	cin>>n;
	int ar[n];
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	int low=0,high=n-1,mid=0;
	while(mid<=high)
	{
		switch(ar[mid])
		{
			case 0:
				swap(ar[low],ar[mid]);
				low++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(ar[mid],ar[high]);
				high--;
				break;
		}
	}
	cout<<"your required array is\n";
	for(i=0;i<n;i++)
	{
		cout<<ar[i]<<"\t";
	}
}
