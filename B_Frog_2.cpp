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

ll n, k;
vll v;
// ll dp[100005];
// ll f(int i)
// {
//     if (i == n - 1)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     ll a = LLONG_MAX;
//     for (int j = i + 1; j < n && j - i <= k; j++)
//     {
//         a = min(a, f(j) + abs(v[i] - v[j]));
//     }
//     return dp[i] = a;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    // memset(dp, -1, sizeof(dp));
    // cout << f(0) << endl;

    vll dp(n + 3, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        ll ans = INT_MAX;
        for (int j = i - 1; j >= 0 && i - j <= k; j--)
            ans = min(ans, abs(v[i] - v[j]) + dp[j]);
        dp[i] = ans;
    }
    cout << dp[n - 1] << endl;
    return 0;
}
