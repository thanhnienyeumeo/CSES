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
const int maxN= 1e3 + 5;
ll n, k, dp[maxN][maxN];
string s[maxN] = {};
void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
}
const ll Mod = 1e9 + 7;
void solve()
{
    dp[1][1] = (s[1][1] == '.');
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            if(i == 1 && j == 1) continue;
            if(s[i][j] == '*') continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= Mod;
        }
    }
    cout << dp[n][n];
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



