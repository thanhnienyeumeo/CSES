#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
vector<int> adj[maxN];
int child[maxN], par[maxN];
int dp[maxN] = {}; //no match with u
int dp1[maxN] = {}; //one match with u
void dfs(int u, int pre)
{

    int Max = -1;
    dp[u] = 0;
    dp1[u] = 0;
    for(auto v: adj[u]) //no match with u
    {
        if(v == pre) continue;
        dfs(v, u);
        child[u] += child[v] + 1;
        dp1[u] += max(dp1[v], dp[v]);
    }
    int res = 0;
    for(auto v: adj[u])
    {
        if(v == pre) continue;
        res = res + dp[v];
    }
    for(auto v: adj[u]) //match
    {
        if(v != pre)
        dp[u] = max(dp[u], res - dp[v] + dp1[v] + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp[1]);
}
