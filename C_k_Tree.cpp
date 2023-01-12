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

ll md = 1e9 + 7;

ll n, k, d;
ll dp[200][2];
ll f(ll sum, ll flag)
{
    if (sum > n)
        return 0;
    if (sum == n)
        return flag;
    if (dp[sum][flag] != -1)
        return dp[sum][flag];
    ll ans = 0;
    for (ll i = 1; i <= k; i++)
    {
        if (i >= d)
            ans += f(sum + i, 1) % md;
        else
            ans += f(sum + i, flag) % md;
    }
    return dp[sum][flag] = ans % md;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << endl;
    return 0;
}
