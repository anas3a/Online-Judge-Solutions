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
vvi v;
ll dp[100005];
ll f(int u)
{
    if (dp[u] != -1)
        return dp[u];
    ll ans = 0;
    for (auto &i : v[u])
    {
        ans = max(ans, f(i));
    }
    return dp[u] = ans + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n + 1);
    memset(dp, -1, sizeof(dp));
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f(i));
    cout << ans - 1 << endl;
    return 0;
}
