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

int vis[1002][1002];
vpl g;
ll n;
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[g[i].ff][g[i].ss] && (x == g[i].ff || y == g[i].ss))
            dfs(g[i].ff, g[i].ss);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(vis, 0, sizeof(vis));
    g.resize(n);
    for (auto &i : g)
        cin >> i.ff >> i.ss;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[g[i].ff][g[i].ss])
        {
            dfs(g[i].ff, g[i].ss);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}