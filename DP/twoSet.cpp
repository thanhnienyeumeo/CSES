/*by Colder
    nightCactus */
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
const int maxN = 2e5 + 5;
int n, k;
ll dp[maxN];
void input()
{
    cin >> n;
}
const ll Mod = 1e9 + 7;
ll calc( ll n)
{
    return n * (n + 1) / 2;
}
ll Pow(ll x, ll n)
{
    if(n == 0) return 1;
    if(n == 1) return x % Mod;
    ll mid = Pow(x, n / 2);
    mid = (mid * mid) % Mod;
    if(n % 2) return mid * x % Mod;
    return mid % Mod;
}
void solve()
{
    dp[0] = 1;
    if(calc(n) % 2 != 0)
    {
        cout << 0;
        return;
    }
  //  debug(calc(n) / 2);
    FOR(i, 1, n)
    {
        FORD(w, calc(n) / 2, i)
        {
            //(dp[w] += dp[w-i]) % Mod;
            dp[w] = (dp[w] + dp[w-i]) % Mod;
          //  debug(dp[w]);
        }
    }
    //debug(Pow(2, Mod - 2));
  //  debug(dp[calc(n) / 2]);
    cout << dp[calc(n) / 2] * Pow(2, Mod - 2) % Mod;
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
