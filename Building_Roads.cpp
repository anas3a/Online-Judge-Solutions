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
vvi g;
vector<bool> vis;
void dfs(int i)
{
    vis[i] = true;
    for (auto &u : g[i])
    {
        if (!vis[u])
            dfs(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i), ans.pb(i);
    }
    cout << sz(ans) - 1 << endl;
    for (int i = 1; i < sz(ans); i++)
        cout << ans[i - 1] << " " << ans[i] << endl;
    return 0;
}
