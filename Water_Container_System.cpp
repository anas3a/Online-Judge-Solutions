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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n, qt;
        cin >> n >> qt;
        vvl g(n + 1), lv(2e4);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        queue<int> q;
        vector<bool> vis(n + 1, false);
        vector<int> lev(n + 1, 0);

        q.push(1);
        vis[1] = true;
        lev[1] = 1;
        lv[1].pb(1);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : g[v])
            {
                if (!vis[u])
                {
                    vis[u] = true;
                    q.push(u);
                    lev[u] = lev[v] + 1;
                    lv[lev[u]].pb(u);
                }
            }
        }
        ll ans = 0, ind = 1;
        vll indx(2e4, 0);
        while (qt--)
        {
            ll x;
            cin >> x;
            if (ind == n + 1)
                continue;
            indx[ind]++;
            if (indx[ind] == sz(lv[ind]))
            {
                ans += sz(lv[ind]);
                ind++;
            }
        }
        cout << "Case #" << ++cs << ": " << ans << nl;
    }
    return 0;
}