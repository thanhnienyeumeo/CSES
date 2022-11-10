#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const ll Mod = 1e9 + 7;
const int maxN= 1e6 + 5;
ll n, k, dp[maxN];
void prepare()
{
    dp[1] = 1;
    FOR(i, 2, maxN - 2)
    {
        if(i <= 6) dp[i] = 1;
        FOR(k, 1, 6)
        {
            if(i - k < 1) break;
            dp[i] = (dp[i] + dp[i-k]) % Mod;
        }
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
      // freopen("1.in", "r", stdin);
    faster;
    int t = 1;
    if( Multitests )
    cin >> t;
    prepare();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
