/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define filein freopen("1.in", "r", stdin)
#define fileout freopen("1.out", "w", stdout)
#define int ll
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define uni(x) x.erase(unique(begin(x), end(x)), end(x));

#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const int maxN= 3e5 + 5;
int n, k, A[maxN];
ll dp[20] =  {};
ll f[20][10][2][2][2] = {}; //isPos,
ll calc(ll x)
{
    if(x == -1) return -1;
    if(x == 0) return 0;
    string s = to_string(x);
    int n = s.length();
  //  debug(n);
    memset(f, 0, sizeof(f));
    f[0][0][0][0][0] = 1;
    FOR(i, 0, n - 1)
    {
        FOR(digit, 0, 9)
        {
            FOR(isPos, 0, 1) FOR(isLower, 0, 1) FOR(isSame, 0, 1)
            {
                FOR(newDigit, 0, 9)
                {
                    if(!isLower && newDigit > s[i] - '0') continue;
                    ll cur = f[i][digit][isPos][isLower][isSame];
                    if(!cur) continue;

                    int newIsPos = isPos || newDigit > 0;
                    int newIsSame = isSame || newDigit == digit;
                    int newIsLower = isLower || newDigit < s[i] - '0';
                    f[i+1][newDigit][newIsPos][newIsLower][newIsSame] += cur;
                }
            }
        }
    }
    ll res = 0;
    FOR(i,0,9) res += f[n][i][1][1][0] + f[n][i][1][0][0];
    res += dp[n-1];
   // debug(res);
    return res;
}
void input()
{
    cin >> n >> k;
    swap(n,k);
    dp[1] = 9;
    ll pre = 9;
    FOR(i, 2, 18)
    {
        pre = pre * 9;
        dp[i] = dp[i-1] + pre;
    }
}
void solve()
{
    cout << calc(n) - calc(k - 1);
}
signed main()
{

    faster;
    int t = 1;
    if( Multitests )
    cin >> t;
    while(t--)
    {
        input();
        solve();
    }

}


