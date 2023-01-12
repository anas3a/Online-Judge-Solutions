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
vector<vll> v;
ll dp[100005][4];
// ll f(ll i, ll x)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][x] != -1)
//         return dp[i][x];
//     ll m, n, o;
//     m = n = o = 0;
//     if (x != 1)
//         m = v[i][0] + f(i + 1, 1);
//     if (x != 2)
//         n = v[i][1] + f(i + 1, 2);
//     if (x != 3)
//         o = v[i][2] + f(i + 1, 3);
//     return dp[i][x] = max({m, n, o});
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n, vll(3));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    // memset(dp, -1, sizeof(dp));
    // cout << f(0, 0) << endl;
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
    return 0;
}
