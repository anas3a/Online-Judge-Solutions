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
ll allmask, n;
ll cnt = 0;
ll dp[20000];
ll f(ll mask)
{
    if (mask == allmask)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;
        ll sumx = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
                sumx += v[i][j];
        }
        ans = min(ans, f(mask | (1 << i)) + v[i][i] + sumx);
    }
    return dp[mask] =  ans;
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
        memset(dp, -1, sizeof(dp));
        v.clear();
        v.resize(n, vll(n));
        for (auto &i : v)
            for (auto &j : i)
                cin >> j;
        allmask = (1 << n) - 1;
        cout << "Case " << ++cs << ": " << f(0) << endl;
    }
    return 0;
}