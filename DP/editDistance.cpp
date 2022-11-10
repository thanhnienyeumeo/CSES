/*by Colder
    aCatCover712WithABlanket
        constellationOfCrab
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
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const int maxN= 5e3 + 5;
int n, k, A[maxN];
string s1, s2;
void input()
{
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    n = s1.length() - 1;
    k = s2.length() - 1;
}
int dp[maxN][maxN] = {};
void solve()
{
    FOR(i, 1, n) dp[i][0] = i;
    FOR(i, 1 ,k) dp[0][i] = i;
    FOR(i, 1, n)
    {
        FOR(j, 1, k)
        {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
        }
    }
    cout << dp[n][k];
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
