/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define filein freopen("1.in", "r", stdin)
#define fileout freopen("1.out", "w", stdout)

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
const int maxN= 2e6 + 5;
int n, maxW, A[maxN];
pair<ll, ll> dp[maxN] = {};
void input()
{
    cin >> n>> maxW;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
void solve()
{
    dp[0] = {0, maxW + 1}; //max
    ll maxBit = (1 << n) - 1;
    FOR(mask, 1, maxBit)
    {
        dp[mask] = {25, 0}; //first is ans
        FOR(bit, 0, n-1)
        {
            if((mask >> bit) & 1)
            {
                ll oldMask = mask ^ (1 << bit);
                ll w = dp[oldMask].y;
                ll c = dp[oldMask].x;
                if(w + A[bit  +1] > maxW)
                {
                    c++;
                    w = 1LL*A[bit + 1];
                   // w = min(w, 1LL*A[bit + 1]);
                }
                else w = w + A[bit + 1];
                dp[mask] = min(dp[mask], {c, w});
            }
        }
      //  debug(dp[mask].x);
       // debug(dp[mask].y);
    }
    cout << dp[maxBit].x;
}
signed main()
{
   // filein;
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

