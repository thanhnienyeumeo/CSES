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
const int maxN= 5005;
ll n, k, A[maxN];
ll dp[maxN][maxN] = {};
bool isCalc[maxN][maxN] ={};
void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
ll calc(int i, int j, int player)
{
    if(isCalc[i][j]) return dp[i][j];
    if(i == j) {
        isCalc[i][j] = 1;
        if(player)
        return dp[i][j] = A[i];
        return dp[i][j] = 0;
    }
    isCalc[i][j] = 1;
    if(player == 1)
    return dp[i][j] = max(calc(i + 1, j, player ^ 1) + A[i], calc(i, j - 1, player ^ 1) + A[j]);
    return dp[i][j] = min(calc(i + 1, j, player ^ 1), calc(i, j - 1, player ^ 1));
}
void solve()
{
    cout << calc(1, n, 1) << '\n';
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
