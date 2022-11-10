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
const int maxN= 1e6 + 5;
ll n, k, dp[maxN];
void input()
{
    cin >> n;
}
void solve()
{
    dp[n] = 0;
    FOR(i, 0, n-1) dp[i] = 1e9;
    FORD(i, n, 0)
    {
        ll m = i;
        if(dp[i] == 1e9) continue;
        while(m > 0)
        {
            dp[i - m % 10] = min(dp[i - m % 10], dp[i] + 1);
            //cout << (i - m % 10) << " ";
            m /= 10;
        }
    }
    cout << dp[0];
}
int main()
{
    //freopen("1.in", "r", stdin);
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
