/*by Colder
    nightCactus... */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(x) x.length()
#define uni(x) x.erase(unique(x.begin(), x.end()), x.end());
#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
//end_define
bool Multitests = 0;
const int maxN= 4e5 + 5;
int n, k;
struct project
{
    int st,en,money;
} A[maxN];
ll dp[maxN] = {};
vector<int> x;
int Find(vector<int> x, int value)
{
    return lower_bound(x.begin(), x.end(), value) - x.begin();
}
void input()
{
    cin >> n;
    FOR(i,1,n)
    {
        cin >> A[i].st >> A[i].en >> A[i].money;
      // x.push_back(A[i].st);
      //  x.push_back(A[i].en);
    }
    sort(A + 1, A + 1 + n, [&](project a, project b){
         if(a.en == b.en) return a.money < b.money;
         return a.en < b.en;
         });

}
int binary(int l, int r, int value)
{
    int res = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(A[mid].en < value)
        {
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    return res;
}
void solve()
{
    dp[1] = A[1].money;
    ll res = A[1].money;
    FOR(i,2,n)
    {
        auto t = binary(1, i - 1, A[i].st);
        if(t == - 1) //first time?
        {
            dp[i] = max(1LL*A[i].money, dp[i-1]);
        }
        else{
            dp[i] = max(A[i].money + dp[t], dp[i-1]);
        }
        res = max(res, dp[i]);
      //  debug(A[i].en);
       // debug(dp[A[i].en]);
    }
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
