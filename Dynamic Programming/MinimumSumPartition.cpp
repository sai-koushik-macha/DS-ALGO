//Given an integer array arr of size N,
//the task is to divide it into two sets S1 and S2 such that
//the absolute difference between their sums is minimum and
//find the minimum difference
#include <bits/stdc++.h>
using namespace std;


#define f(n) for(int i=0;i<n;i++)
	//Recursive Approach using Memoization 
	int minDif(int a[],int i,int sum_cal,int sum,int dp[1001][1001])
	{
	    if(i==0) return dp[i][sum_cal]=abs(sum - 2*sum_cal);
	    if(dp[i][sum_cal]!=0) return dp[i][sum_cal];

	    return dp[i][sum_cal]=min(minDif(a,i-1,sum_cal+a[i-1],sum,dp),minDif(a,i-1,sum_cal,sum,dp));
	}

	int minDiffernce(int a[], int n)
	{
	    int i=n;
	    int sum_cal=0;
	    int sum=0;
	    f(n) sum+=a[i];
	    int dp[1001][1001];
	    memset(dp,0,sizeof(dp[0][0])*(n+1)*(sum+1));
	    return minDif(a,i,sum_cal,sum,dp);
	}


int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];



	    cout << minDiffernce(a, n) << "\n";

    }
    return 0;
}
