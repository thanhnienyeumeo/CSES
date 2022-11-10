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
bool Multitests = 0;
const int maxN= 1e5 + 5;
int n, k, A[maxN];
const int Mod = 1e9 + 7;
void input()
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
ll dp[maxN][105] = {};
void solve()
{
    if(A[1] == 0)
    {
        FOR(sum, 1, k) dp[1][sum] = 1;
    }
    else dp[1][A[1]] = 1;
    FOR(i,2,n)
    {
        if(A[i] == 0)
        FOR(sum,1,k)
        {
            dp[i][sum] = (dp[i-1][sum] + dp[i-1][sum + 1]) % Mod;
            if(sum > 0) dp[i][sum] = (dp[i][sum] + dp[i-1][sum - 1]) % Mod;
        }
        else
        {
            dp[i][A[i]] = (dp[i-1][A[i]-1] + dp[i-1][A[i]+1] + dp[i-1][A[i]]) % Mod;
        }
    }
    ll res = 0;
//    FOR(id,1,n){
//    FOR(i,1,k) debug(dp[id][i]); //res = (res + dp[n][i]) % Mod;
//    cout << '\n';
//    }
    FOR(i,1,k) res = (res + dp[n][i]) % Mod;
    cout << res;
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
