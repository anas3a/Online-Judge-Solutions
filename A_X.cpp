#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

ll n, r, y, b;
ll dp[1005];

ll f(ll w, ll cr, ll cy, ll cb)
{
    if (w == 0)
        return 0;
    ll aa = 0, bb = 0, cc = 0;
    if (dp[w] != -1)
        return dp[w];
    if (r <= w && cr - cy <= 0 && cr - cb <= 0)
    {
        aa = 1 + f(w - r, cr + 1, cy, cb);
    }
    if (y <= w && cy - cr <= 0 && cy - cb <= 0)
    {
        bb = 1 + f(w - y, cr, cy + 1, cb);
    }
    if (b <= w && cb - cr <= 0 && cb - cy <= 0)
    {
        cc = 1 + f(w - b, cr, cy, cb + 1);
    }
    return dp[w] = max(aa, max(bb, cc));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n >> r >> y >> b;
    cout << f(n, 0, 0, 0) << endl;
    return 0;
}
