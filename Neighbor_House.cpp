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

vvl v;
ll n;
ll dp[3][25];
ll f(ll i, ll c)
{
    if (i == n)
        return 0;
    if (dp[c][i] != -1)
        return dp[c][i];
    ll ans = LLONG_MAX;
    for (int j = 0; j < 3; j++)
    {
        if (j == c && i != 0)
            continue;
        ans = min(ans, f(i + 1, j) + v[i][j]);
    }
    return dp[c][i] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        memset(dp, -1, sizeof(dp));
        v.resize(n, vll(3));
        for (auto &i : v)
            cin >> i[0] >> i[1] >> i[2];
        cout << "Case " << ++cs << ": " << f(0, 0) << endl;
    }
    return 0;
}