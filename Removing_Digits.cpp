#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

ll n;
ll dp[1000006];
ll f(ll x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    if (dp[x] != -1)
        return dp[x];

    int y = x;
    ll ans = INT_MAX;
    while (y != 0)
    {
        ll z = y % 10;
        y /= 10;
        if (!z)
            continue;
        ans = min(ans, 1 + f(x - z));
    }
    return dp[x] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) << endl;
    return 0;
}
