/*by Colder
    aCatCover712WithABlanket
        constellationOfCrab
            nightCactus
                WHO*/
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
const int maxN= 1e3 + 5;
int n, k, A[maxN];
int dp[maxN][maxN] = {};
void input()
{
    cin >> n >> k;
    if(n > k) swap(n, k);
}
void solve()
{
    FOR(i,1,max(n,k)) dp[i][i] = 1;
    dp[1][2] = 2;
    dp[2][1] = 2;
    FOR(i, 1, n)
    {
        FOR(j,1,k)
        {
            if(dp[i][j]) continue;
            if(dp[j][i])
            {
                dp[i][j] = dp[j][i];
                continue;
            }
            FOR(cutI, 1, i - 1)
            {
                if(dp[i][j] == 0) dp[i][j] = dp[cutI][j] + dp[i - cutI][j];
                else dp[i][j] = min(dp[i][j], dp[cutI][j] + dp[i-cutI][j]);
            }
            FOR(cutJ, 1, j - 1)
            {
                if(dp[i][j] == 0) dp[i][j] = dp[i][cutJ] + dp[i][j - cutJ] ;
                else
                dp[i][j] = min(dp[i][j], dp[i][cutJ] + dp[i][j - cutJ]);
            }
          //  debug(dp[i][j]);
        }
        //cout << '\n';
    }
    cout << dp[n][k] - 1;
    //n^3
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
