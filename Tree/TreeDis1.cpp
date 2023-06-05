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
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long r) {
    return rd() % (r - l + 1) + l;
}

#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
const int maxN = 2e5 + 5;
int n;
vector<int> adj[maxN];
int child[maxN], par[maxN], h[maxN];
int dp[2][maxN] = {};
int res = 0;

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

int dfs2(int u, int par, int h, int i)
{
    int opt = -1;
    for(auto v: adj[u])
    {
        if(v == par) continue;
        dp[i][v] = h + 1;
        int g = dfs2(v, u, h + 1, i);
        //update dp[i][
        if(opt == -1 || dp[i][g] > dp[i][opt])
        {
            opt = g;
        }
    }
    if(opt != -1) return opt;
    return u;
}

void solve()
{
    int u = Rand(1, n);
   // debug(u);
    int b = dfs2(u, 0, 0, 0);
    int c = dfs2(b, 0, 0, 0);
    dfs2(c, 0, 0, 1);
    for(int  i = 1; i <= n; i++)
    {
        cout << max(dp[0][i], dp[1][i]) << " ";
    }
}

signed main()
{

    faster;
    int t = 1;
    //if( Multitests )
    //cin >> t;
    while(t--)
    {
        input();
        solve();
    }

}

