/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
using namespace std;

#define ll int
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
const int maxN= 2e5 + 2;
int n, k, A[maxN];
int h[maxN], head[maxN], posInBase[maxN], chain[maxN], nChild[maxN], parent[maxN];
vector<int> adj[maxN] = {};
ll p[maxN][20] = {};
int pref[maxN] = {};
void DFS(int u)
{
   // cout << u << "\n";
    for (auto v : adj[u])
    if (h[v] == -1)
    {
        p[v][0] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
}

void Prepare()
{
    memset(h, -1, sizeof(h));
    memset(p, -1, sizeof(p));
//    FOR(i,1,n)
//    {
//        cout << h[i] << " ";
//    }
    h[1] = 0; DFS(1);

    for (int j = 1 ; (1 << j) <= n; j ++)
    for (int i = 1; i <= n; i++)
    if (p[i][j - 1] != -1)
        p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    for (int i = 19; i >= 0; i--)
    if (h[u] - (1 << i) >= h[v])
        u = p[u][i];

    if (u == v) return u;

    for (int i = 19; i >= 0; i--)
    if (p[u][i] != p[v][i])
        u = p[u][i], v = p[v][i];

    return p[u][0];
}
//3  3 5 8 9  5
//3  0 2 3 1 -4
//
void dfs2(int u, int par)
{
    for(int v: adj[u])
    {
        if(v == par) continue;
        dfs2(v, u);
        pref[u] += pref[v];
    }
}
void input()
{
    cin >> n>> k;
    FOR(i,1,n - 1)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Prepare();
    FOR(i,1,k)
    {
        int u,v;
        cin >> u >> v;
        int uv = LCA(u, v);
        pref[u]++;
        pref[v]++;
        pref[uv]--;
        pref[p[uv][0]]--;
    }
    dfs2(1, 0);
}
void solve()
{
    FOR(i,1,n) cout << pref[i] << " ";
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

