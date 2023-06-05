/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define filein freopen("1.in", "r", stdin)
#define fileout freopen("1.out", "w", stdout)

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define uni(x) x.erase(unique(begin(x), end(x)), end(x));

#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const int maxN = 2e5 + 5;
int n;
vector<int> adj[maxN];
int child[maxN], par[maxN], h[maxN];
ll dp[2][maxN] = {};
int res = 0;
void dfs(int u, int pre)
{
    ll sum = 0;
  //  dp[2][u] = dp[2][pre] + dp[1][pre] - (dp[1])
    for(auto v: adj[u])
    {
        if(v==pre) continue;
        dfs(v, u);
        child[u] += child[v] + 1;
        dp[1][u] += dp[1][v] + child[v] + 1;
        //sum += dp[1][v];
    }
//    for(auto v: adj[u])
//    {
//        if(v==pre) continue;
//        //dp[2][v] = dp[2][u] + sum - dp[1][v] + (n - child[v] - 1);
//        dp[2][v] = dp[2][u] + dp[1][u] - (dp[1][v] + child[v] + 1) + (n - child[v] - 1);
//        debug(v);
//        debug(dp[2][v]);
//    }
}
void dfs2(int u, int pre)
{
    if(pre != 0)
    dp[2][u] = dp[2][pre] + dp[1][pre] - (dp[1][u] + child[u] + 1) + (n - child[u] - 1);
    for(auto v: adj[u])
    {
        if(v==pre) continue;
        dfs2(v,u);
    }
}
void input()
{
    cin >> n;
    FOR(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve()
{
    dfs(1, 0);
    dfs2(1,0);
    for(int i = 1; i <= n; i++){
           // debug(dp[1][i]);
          //  debug(dp[2][i]);
            cout << dp[1][i] + dp[2][i] << " ";
    }
}
signed main()
{

    faster;
    int t = 1;
    if( Multitests )
    cin >> t;
    while(t--)
    {
        input();
        solve();
    }

}
