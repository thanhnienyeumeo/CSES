/*by Colder
    nightCactus... */
#include <iostream>
#include <vector>
#include <climits>
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
int height[maxN], head[maxN], posInBase[maxN], chain[maxN], nChild[maxN], parent[maxN];
vector<int> adj[maxN] = {};
ll ST[4 * maxN] = {};
ll lazy[4 * maxN] = {};

void down(int id, int startL, int endL, int startR, int endR)
{
    ll value = lazy[id];
    ST[id * 2 + 1] += value * (endR - startR + 1 );
    lazy[id * 2 + 1] +=value;
    ST[id * 2] += value* (endL - startL + 1);
    lazy[id * 2] += value ;
    lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v,  ll value)
{
    if( v < l | r < u)
    {
        return;
    }
    if( u <= l && r <=v )
    {
        ST[id] += value * (r - l + 1);
        lazy[id] += value;
        return;
    }
    int mid = (l + r) >> 1;
    if(lazy[id])
    down(id, l, mid, mid+1, r);

    update(id * 2, l, mid, u, v, value);
    update(id * 2 + 1, mid + 1, r, u, v, value);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}
ll get(int id, int l, int r, int u, int v)
{
    if( v  < l || r < u)
    {
        return 0;
    }
    if( u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) >> 1;
    //day xuong
    if(lazy[id])
    down(id, l, mid, mid+1, r);

    ll f = get(id * 2, l, mid, u, v);
    ll s = get(id * 2 + 1, mid + 1, r, u, v);
    return f + s;
}

//hld time
int nChain = 0;
int nBase = 0;
void hld(int u, int par_u)
{
    if(head[nChain] == 0){
        head[nChain] = u;
        height[nChain] = height[chain[par_u]] + 1;
    }
    chain[u] = nChain;
    int maxV = -1;
    posInBase[u] = ++nBase;
    for(auto e: adj[u])
    {
        int v=e;
        if(v != par_u && (maxV == -1 | nChild[v] > nChild[maxV]) )
        {
            maxV = v;
        }
    }
    if(maxV == -1) return;
    hld(maxV, u);
    for(auto e: adj[u])
    {
        int v = e;
        if(v == par_u || v == maxV) continue;
        nChain++;
        hld(v, u);
    }
}

void dfs(int u, int par_u)
{
    parent[u] = par_u;
    for(auto e: adj[u])
    {
        int v = e;
        if(v == par_u) continue;
        dfs(v, u);
        nChild[u] += nChild[v] + 1;
    }
}

void update(int u, int v)
{
    if(height[chain[u]] > height[chain[v]]) swap(u,v);
    //chainv is higher
    while(height[chain[v]] > height[chain[u]])
    {
        int x = head[chain[v]];
        update(1, 1, n, posInBase[x], posInBase[v], 1);
        v = parent[x];
    }
    while(chain[u] != chain[v])
    {
        int x = head[chain[u]];
        int y = head[chain[v]];
        update(1, 1, n, posInBase[x], posInBase[u], 1);
        update(1, 1, n, posInBase[y], posInBase[v], 1);
        u = parent[x];
        v = parent[y];
    }
    if(posInBase[u] > posInBase[v]) swap(u,v);
    //u is lower -> lca
    update(1, 1, n, posInBase[u], posInBase[v], 1);
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
    dfs(1,0);
    hld(1, 0);
    FOR(i,1,k)
    {
        int u,v;
        cin >> u >> v;
        update(u, v);
    }
}
void solve()
{
    FOR(i,1,n) cout << get(1, 1, n, posInBase[i], posInBase[i]) << " ";
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

