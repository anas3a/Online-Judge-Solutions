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
    vi color(n + 1, -1);
    bool bipar = true;
    for (int i = 1; i <= n; i++)
    {
        if (!bipar)
            break;
        if (color[i] != -1)
            continue;
        color[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty() && bipar)
        {
            int u = q.front();
            q.pop();
            for (auto &v : g[u])
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    bipar = false;
                    break;
                }
            }
        }
    }
    if (!bipar)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << color[i] + 1 << " ";
        cout << endl;
    }
    return 0;
}
