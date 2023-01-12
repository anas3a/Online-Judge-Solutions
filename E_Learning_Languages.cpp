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
vvl g;
vector<bool> vis;
void dfs(int u)
{
    vis[u] = true;
    for (auto &v : g[u])
    {
        if (!vis[v])
            dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(m + 1);
    vis.resize(m + 1, false);
    vll cnt(m + 1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        ll cx = 0;
        if (!k)
            ans++;
        for (int j = 0; j < k; j++)
        {
            ll c;
            cin >> c;
            cnt[c] = 1;
            if (cx == 0)
            {
                cx = c;
                continue;
            }
            g[c].pb(cx);
            g[cx].pb(c);
        }
    }
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i] && cnt[i])
        {
            flag = true;
            ans++;
            dfs(i);
        }
    }
    if (flag)
        ans--;
    cout << ans << endl;
    return 0;
}