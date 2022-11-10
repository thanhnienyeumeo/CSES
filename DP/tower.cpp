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
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 1;
const int maxN= 1e6 + 5;
int n, k;
ll dp[maxN] = {};
ll pref[maxN] = {};
void prepare()
{
    dp[0] = 1;
    dp[1] = 2;
    //
    FOR(i, 2, 1e6)
    {
        dp[i] =
    }
}
void input()
{
    cin >> n;
}
void solve()
{
    cout << dp[n] << '\n';
}
int main()
{
     //  freopen("1.in", "r", stdin);
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
