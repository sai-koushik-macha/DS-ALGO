//Take a tour from the city 0 (0 based index) to all other cities
//such that you visit each city atmost once and
//then at the end come back to city 0 in min cost.

#include<bits/stdc++.h>
using namespace std;
#define f(n) for(int i=0;i<n;i++)
// Start travelling from source vertex and consider rest of the vertices
int CostOfTravel(int graph[20][20],int n,int source,bool visited[])
{

    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && graph[source][i])
        {
            visited[i]=1;
            mn=min(mn,graph[source][i]+CostOfTravel(graph,n,i,visited)); // main formula
            visited[i]=0; // backtrack
        }
    }

    return (mn==INT_MAX)?graph[source][0]:mn; // If all the vertices visited go back to source!!
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n; // Number of vertices to visit
	    cin>>n;
	    int graph[20][20];
	    bool visited[n];
	    int dp[20][20];
	    f(n)
	        for(int j=0;j<n;j++) cin>>graph[i][j]; // Cost of city i to city j

        memset(visited,0,sizeof(visited[0])*n);
        memset(dp,-1,sizeof(dp[0][0])*n*n);

        int ans=INT_MAX,cnt=1,cost=0;
        visited[0]=1;
	    cout<<CostOfTravel(graph,n,0,visited)<<endl;
	}
}
