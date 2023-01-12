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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vvi g(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    bool found = false;
    vi lev(n + 1, -1);
    vi par(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (lev[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        lev[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : g[u])
            {
                if (lev[v] != -1)
                    continue;
                else
                {
                    q.push(v);
                    par[v] = u;
                    lev[v] = lev[u] + 1;
                }
            }
        }
    }
    vi ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < sz(g[i]); j++)
        {
            if (lev[g[i][j]] - lev[i] >= 2)
            {
                ans.pb(g[i][j]);
                ans.pb(i);
                i = n + 1;
                break;
            }
        }
    }
    if (sz(ans))
    {
        for (int i = par[ans[1]]; i != -1; i = par[i])
        {
            ans.pb(i);
            if (i == ans[0])
                break;
        }
        cout << sz(ans) << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
