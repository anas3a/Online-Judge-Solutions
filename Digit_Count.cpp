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

ll n, m;
vll v;
ll dp[20][20];
ll f(ll x, ll j)
{
    if (j == n)
        return 1;
    if (dp[x][j] != -1)
        return dp[x][j];
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (abs(x - v[i]) <= 2 || j == 0)
            ans += f(v[i], j + 1);
    }
    return dp[x][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        v.clear();
        v.resize(m);
        memset(dp, -1, sizeof(dp));
        for (auto &i : v)
            cin >> i;
        cout << "Case " << ++cs << ": " << f(0, 0) << endl;
    }
    return 0;
}