//Given two strings s and t. Find the minimum number of operations that need to be
//performed on str1 to convert it to str2. The possible operations are:

//Insert
//Remove
//Replace

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:

	    int Edit(string s,string t,int i,int j,int dp[200][200])
	    {
	        if(i==s.length()) return t.length()-j;
	        else if(j==t.length()) return s.length()-i;
	        if(dp[s.length()-i][t.length()-j]!=-1) return dp[s.length()-i][t.length()-j];

	        if(s[i]==t[j]) return dp[s.length()-i][t.length()-j]=Edit(s,t,i+1,j+1,dp);
	        else return dp[s.length()-i][t.length()-j]=1 + min(Edit(s,t,i+1,j,dp),min(Edit(s,t,i,j+1,dp),Edit(s,t,i+1,j+1,dp)));

	    }

		int editDistance(string s, string t)
		{
		    int dp[200][200];
		    memset(dp,-1,sizeof(dp[0][0])*200*200);
		    int i=0,j=0;
		    return Edit(s,t,i,j,dp);
		}
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
