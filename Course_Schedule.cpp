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
vll color, ans;
bool flag;
void dfs(int u)
{
    color[u] = 1;
    for (auto &v : g[u])
    {
        if (!color[v])
            dfs(v);
        else if (color[v] == 1)
            flag = true;
    }
    ans.pb(u);
    color[u] = 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1, 0);
    flag = false;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
            dfs(i);
    }
    if (flag)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        reverse(all(ans));
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
