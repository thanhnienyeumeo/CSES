/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(x) x.length()
#define uni(x) x.erase(unique(begin(x), end(x)), end(x));
#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
//end_define
bool Multitests = 0;
const int maxN= 3e5 + 5;
int n, k, A[maxN], dp[maxN];
void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
const int oo = 1e9;
void solve()
{
    int res = 1;
    dp[1] = A[1];
    FOR(i, 2, n) dp[i] = oo;
    FOR(i,2,n)
    {
        int pv = lower_bound(dp + 1, dp + 1 + res, A[i]) - dp;
        dp[pv] = A[i];
        res = max(res, pv);
    }
    cout << res;
}
int main()
{
 //   freopen("1.in", "r", stdin);
    faster;
    int t = 1;
    if( Multitests )
    cin >> t;
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
