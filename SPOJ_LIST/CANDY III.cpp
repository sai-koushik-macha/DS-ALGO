#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int n,i,t;
	cin>>t;
	while(t--)
	{
		cout<<"\n";
		cin>>n;
		unsigned long long int  sum=0;
		unsigned long long int a[n];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			sum=(sum%n+a[i]%n);
		}
		if(sum%n==0)
		{
		cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}
