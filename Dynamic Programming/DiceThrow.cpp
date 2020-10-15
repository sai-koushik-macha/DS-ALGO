//Given N dice each with M faces, numbered from 1 to M,
//find the number of ways to get sum X.
//X is the summation of values on each face when all the dice are thrown.
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
  int dp[51][51][51];
    // Recursive Solution with Memoization
    long long noOfWays(int M , int N , int X) {
        if(X==0 && N==0) return dp[M][N][X]=1;
        if(N<=0 || X<0) return dp[M][N][X]=0;
        if(dp[M][N][X]) return dp[M][N][X];

        int ways=0;
        for(int i=1;i<=M;i++)
        {
            ways+=noOfWays(M,N-1,X-i);
        }
        return dp[M][N][X]=ways;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;  //N dice with M faces need to have sum X

        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
