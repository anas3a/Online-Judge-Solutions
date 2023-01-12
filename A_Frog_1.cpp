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
vll v;
//ll dp[100005];
// ll f(int i)
// {
//     if (i == n - 1)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];
//     ll a, b;
//     a = b = LLONG_MAX;
//     if (i < n - 1)
//         a = f(i + 1) + abs(v[i] - v[i + 1]);
//     if (i < n - 2)
//         b = f(i + 2) + abs(v[i] - v[i + 2]);
//     return dp[i] = min(a, b);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    //memset(dp, -1, sizeof(dp));
    //cout << f(0) << endl;

    vll dp(n + 3, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 1; i < n; i++)
        dp[i] = min(abs(v[i] - v[i - 1]) + dp[i - 1], abs(v[i] - v[i - 2]) + dp[i - 2]);
    cout << dp[n - 1] << endl;
    return 0;
}
