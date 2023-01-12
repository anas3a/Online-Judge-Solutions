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

ll n, w;
vpl v;
// ll dp[102][100005];
// ll f(ll i, ll w)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][w] != -1)
//         return dp[i][w];
//     ll a = 0, b = 0;
//     if (v[i].ff <= w)
//         a = v[i].ss + f(i + 1, w - v[i].ff);
//     b = f(i + 1, w);
//     return dp[i][w] = max(a, b);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    v.resize(n);
    for (auto &i : v)
        cin >> i.ff >> i.ss;
    // memset(dp, -1, sizeof(dp));
    // cout << f(0, w) << endl;

    vvl dp(n + 2, vll(w + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j - v[i - 1].ff >= 0)
                dp[i][j] = max(dp[i - 1][j - v[i - 1].ff] + v[i - 1].ss, dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
