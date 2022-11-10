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
const int maxN= 1e8 + 2;
int n, k, A[1005];
ll dp[maxN] = {};
void input()
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
void solve()
{
    FOR(i, 1, k) dp[i] = 1e9;
    dp[0] = 0;
    FOR(sum, 1, k)
    {
        FOR(i, 1, n)
        {
            if(A[i] <= sum)
            {
                dp[sum] = min(dp[sum], dp[sum - A[i]] + 1);
            }
        }
    }
    if(dp[k] == 1e9) cout << -1;
    else
    cout << dp[k];
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
