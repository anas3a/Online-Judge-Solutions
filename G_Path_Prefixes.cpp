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

vvl g;
vll va, vb, ans, vx;
ll cnta = 0, cntb = 0;
void dfs(int u)
{
    cnta += va[u];
    cntb += vb[u];
    vx.pb(cntb);
    ans[u] = upper_bound(all(vx), cnta) - vx.begin() - 1;
    for (auto &i : g[u])
        dfs(i);
    vx.pop_back();
    cnta -= va[u];
    cntb -= vb[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        g.clear();
        g.resize(n + 1);
        va.clear();
        vb.clear();
        ans.clear();
        va.resize(n + 1, 0);
        vb.resize(n + 1, 0);
        ans.resize(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            ll p, a, b;
            cin >> p >> a >> b;
            g[p].pb(i);
            va[i] = a;
            vb[i] = b;
        }
        dfs(1);
        for (int i = 2; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}