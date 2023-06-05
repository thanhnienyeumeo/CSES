#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,m,n) for(int i = m; i <= n; i++)
const int maxN = 2e5 + 5;
int n,u,v;
ll bit[maxN], A[maxN];
vector<int> adj[maxN] = {};
int timeDfs = 0;
int st[maxN], en[maxN] = {};
void update(int i, ll x)
{
    while(i < maxN)
    {
        bit[i] += x;
        i += (i & (-i));
    }
}
ll get(int i)
{
    ll res = 0;
    while(i >= 1)
    {
        res += bit[i];
        i -= (i & (-i));
    }
    return res;
}
void dfs(int u,int par)
{
    st[u] = ++timeDfs;
    update(timeDfs, A[u]);
    for(int v: adj[u])
    {
        if( v == par) continue;
        dfs(v, u);
        //timeDfs++;
    }
    en[u] = timeDfs;
}
int main()
{
    int q;
    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
    FOR(i,1,n-1)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    FOR(i,1,q)
    {
        int type;
        cin >> type;
        if(type == 2)
        {
            cin >> u;
            cout << get(st[u]) << '\n';
            continue;
        }
        cin >> u >> v;
        update(st[u], -A[u]);
        update(st[u], v);
        A[u] = v;
    }

}
