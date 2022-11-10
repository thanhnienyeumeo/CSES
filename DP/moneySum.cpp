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
const int maxN= 3e5  +5;
int n, k, A[105];
bitset<maxN> dp;
void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
void solve()
{
    dp[0] = 1;
    FOR(i, 1, n)
        {
            dp = dp | (dp << A[i]);
        }
    cout << dp.count() - 1 << '\n';
    FOR(i,1,1e5) if(dp[i]) cout << i << " ";
}
int main()
{
 //   freopen("1.in", "r", stdin);
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
