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
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> vis(n + 1, false);
    vi p(n + 1, -1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
                p[v] = u;
            }
        }
    }
    if (!vis[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vi ans;
        for (int u = n; u != -1; u = p[u])
            ans.pb(u);
        reverse(all(ans));
        cout << sz(ans) << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
