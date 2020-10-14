#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){ a%=m;LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
int u[100001];
int v[100001];
int val[100001];
int n, m, k;
vector<int> graph[100001];
stack<int> scc_stack;
bool visit[100001];
int components_sz[100001];
int components_count = 0;
void dfs(int node) {
    visit[node] = 1;
    for(int i: graph[node]) {
        if(visit[i] == 0) {
            visit[i] = 1;
            dfs(i);
        }
    }
    scc_stack.push(node);
}
void dfs2(int node) {
    components_sz[components_count]++;
    visit[node] = 1;
    for(int i: graph[node]) {
        if(visit[i] == 1)
            continue;
        visit[i] = 1;
        dfs2(i);
    }
}
bool check(int limit) {
    components_count = 0;
    memset(visit, 0, sizeof(visit));
    while(!scc_stack.empty()) {
        scc_stack.pop();
    }
    for(int i = 1; i <= n; i++) {
        graph[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        int a = u[i], b = v[i];
        if(val[a] >= limit && val[b] >= limit) {
            graph[a].push_back(b);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(visit[i] == 0) {
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++) 
        graph[i].clear();
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= m; i++) {
        int a = u[i], b = v[i];
        if(val[a] >= limit && val[b] >= limit) {
            graph[b].push_back(a);
        }
    }
    while(scc_stack.size()) {
        int cur = scc_stack.top();
        scc_stack.pop();
        if(visit[cur] == 1)
            continue;
        ++components_count;
        dfs2(cur);
    }
    int ans = 0;
    for(int i = 1; i <= components_count; i++) {
        ans = max(ans , components_sz[i]);
        components_sz[i] = 0;
    }
    components_count = 0;
    if(ans >= k)
        return 1;
    else
        return 0;
}
int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    assert(cin >> n >> m >> k);
    for(int i = 1; i <= n; i++)
        assert(cin >> val[i]);
    for(int i = 1; i <= m; i++) {
        assert(cin >> u[i] >> v[i]);
    }
    int l = 1, r = 1000000000;
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid) == 1) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    assert(ans != -1);
    cout << ans << endl;
}