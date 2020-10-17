#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

/**
@brief all_binary function create that string 
@param s is character array size length of all binary string p is adjacent value 0 or 1
@return 'void'
**/

void all_binary(char s[],int size,int p)
{
	if(p==size)
	{
	s[p]='\0';
	cout<<s<<endl;
	return ;
	}
	
	if(s[p-1]=='1')
	{
		s[p]='0';
		all_binary(s,size,p+1);
	}
	if(s[p-1]=='0')
	{
		s[p]='1';
		all_binary(s,size,p+1);
		s[p]='0';
		all_binary(s,size,p+1);
	}
}

int main()
{
	int i,j,n,k;
	cin>>n;
	char s[n];
	s[0]='0';
	all_binary(s,n,1);
	s[0]='1';
	all_binary(s,n,1);
	return 0;
}
