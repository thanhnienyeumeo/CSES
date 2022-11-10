#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define sz(x) x.length()
#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const int maxN= 1004;
const int maxPice = 1e5 + 5;
int n, k, price[maxN], value[maxN];
int dp[maxN][maxPice] = {};
void input()
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> price[i];
    }
    FOR(i,1,n) cin >> value[i];
}
void solve()
{
    FOR(i,1,n)
    FOR(weight, 0, k)
        {
            if(weight >= price[i])
            {
                dp[i][weight] = max(dp[i-1][weight - price[i]] + value[i], dp[i-1][weight]);
            }
            else dp[i][weight] = dp[i-1][weight];
        }
    cout << dp[n][k] << '\n';
}
int main()
{
   // freopen("1.in", "r", stdin);
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
