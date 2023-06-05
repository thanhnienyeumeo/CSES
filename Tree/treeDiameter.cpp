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
const int maxN = 1e6 + 5;
int n;
vector<int> adj[maxN];
int h[maxN];

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

void dfs(int u, int par)
{
    for(auto v: adj[u])
    {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
    }
}
void solve4();
void solve3()
{
    //count the cnt of same best diameter
    dfs(1,0);
    int res = -1, cnt = 1, pv = -1;
    FOR(i,1,n)
    {
        if(res == -1 || h[i] > h[res])
        {
            res = i;
            cnt = 1;
        }
        else if(h[i] == h[res]) cnt++;
    }

    ll old = h[res];
    memset(h, 0, sizeof(h));
    //debug(old);
    //do it again with res

    dfs(res, 0);
    ll ans = cnt;
    res = -1, cnt = 1;
    FOR(i,1,n)
    {
        if(res == -1 || h[i] > h[res])
        {
            res = i;
            cnt = 1;
        }
        else if(h[i] == h[res]) cnt++;
    }
    ans *= cnt;
    if(h[res] == old * 2) //special
    {
        solve4();
        return;
    }
    cout << h[res] << " " << ans;
}
void solve4()
{
    memset(h, 0, sizeof(h));
    dfs(2,0);
    int res = -1, cnt = 1, pv = -1;
    FOR(i,1,n)
    {
        if(res == -1 || h[i] > h[res])
        {
            res = i;
            cnt = 1;

        }
        else if(h[i] == h[res]) cnt++;
    }
    memset(h, 0, sizeof(h));
    ll old = h[res];
    //do it again with res

    dfs(res, 0);
    ll ans = cnt;
    res = -1, cnt = 1;
    FOR(i,1,n)
    {
        if(res == -1 || h[i] > h[res])
        {
            res = i;
            cnt = 1;
        }
        else if(h[i] == h[res]) cnt++;
    }
    ans *= cnt;
    cout << h[res] << " " << ans;
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
        solve3();
    }

}

